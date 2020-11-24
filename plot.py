## script to generate singularities images. requires chaste_codegen, it's cellml files, matplotlib and numpy

# todo:
# We probably want to limit the search to -150 to +100mV ish
# try finding without vardefs --> works fine but can't draw diagram

import os
from sympy import *
import sympy.core.numbers
from sympy.codegen.rewriting import ReplaceOptim, expm1_opt, optimize
import matplotlib.pyplot as plt
import numpy as np
from chaste_codegen import (add_conversions, ChastePrinter, load_model_with_conversions, DATA_DIR)
from chaste_codegen._math_functions import MATH_FUNC_SYMPY_MAPPING
from chaste_codegen._partial_eval import partial_eval
from chaste_codegen.model_with_conversions import (get_equations_for, _get_modifiable_parameters)
from cellmlmanip.model import Variable


import sys
sys.setrecursionlimit(sys.getrecursionlimit() * 2)

U_offset = 1e-7

printer = ChastePrinter(lambda var: str(var).lstrip('_').replace('$', '__'),
                        lambda deriv: str(deriv).lstrip('_').replace('$', '__'))


def match_pattern(equation, patterns, functions):
    """Check if list of patterns are found and if so applied the function f from the corresponding list.

    :param equation: The equation to be checked.
    :param patterns: List of pattrns to look for.
    :param functions: List of functions to apply to match if found. 
        Please note: patterns and conditions should be of equal length.
    :return: A tuple of (match found, function(match)) 
        if there was a match and function(match) is not False/None, otherwise (None, None)
    """

    check_match = None
    for pattern, func in zip(patterns, functions):
        match = equation.match(pattern)
        check_match = func(match)
        if not check_match:
            match = simplify(equation).match(pattern)
            check_match = func(match)
#        if not check_match:
#            match = equation.factor().match(pattern)
#            check_match = func(match)
        if check_match:
            return match, check_match
    return None, None

def get_initial_value(var, model):
    """Returns the initial value of a variable if it has one, 0 otherwise"""
    # state vars have an initial value parameter defined
    initial_value = 0
    if var in model.state_vars:
        initial_value = getattr(var, 'initial_value', 0)
    else:
        eqs = get_equations_for(model, (var,), filter_modifiable_parameters_lhs=False, optimise=False)
        # If there is a defining equation, there should be just 1 equation and it should be of the form var = value
        if len(eqs) == 1 and isinstance(eqs[0].rhs, Float):
            initial_value = eqs[0].rhs
    return initial_value

def get_singularity_points(rhs, V):
    def handle_singularity_points(sp):
        if isinstance(sp, FiniteSet):
            return handle_FinisteSet(sp)
        elif isinstance(sp, Complement):
            return handle_Complement(sp)
        elif isinstance(sp, Union):
            return handle_Union(sp)
        else:
            return EmptySet
        
    def handle_FinisteSet(sp):
        return FiniteSet(*filter(lambda s: s.is_real, sp))

    def handle_Complement(sp):
        return handle_FinisteSet(sp.args[1]) if isinstance(sp.args[1], FiniteSet) else EmptySet

    def handle_Union(sp):
        singularity_points = EmptySet
        for s in sp.args:
            singularity_points = singularity_points.union(handle_singularity_points(s))
        return singularity_points

    try:
        rhs = rhs.subs(MATH_FUNC_SYMPY_MAPPING)
        singularity_points = singularities(rhs, V, domain=Reals)
    except (RecursionError, NotImplementedError):
        print("Singularities cannot be found")
        print(rhs)
        print()
        return set()
    
    return set(handle_singularity_points(singularity_points))

def _process_singularities(model):
    unprocessed_eqs = {eq.lhs: eq.rhs for eq in model.derivative_equations} | MATH_FUNC_SYMPY_MAPPING
    subs_dict = {eq.lhs: eq.rhs for eq in model.derivative_equations} | MATH_FUNC_SYMPY_MAPPING
    paramdefs = {e: get_initial_value(e, model) for e in _get_modifiable_parameters(model)}
    vardefs = {e: get_initial_value(e, model) for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))}
    vardefs_offset = {e: get_initial_value(e, model) + 1e-7 for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))}

    def process_singularities_eq(expr, expr_part, singularity_points, sing_no=0, singularity_points_processed=set(), singularity_piecewise_parts=[], params=False):
        def f(Vx):
            return expr.subs({model.membrane_voltage_var:Vx})
        if singularity_points and singularity_points != singularity_points_processed:
            if expr_part == 0.0:
                print('#### Eq == 0!')
            elif isinstance(expr_part, Piecewise):
                print('####Piecewise!')
            else:
                (vs,ve, U) = get_U(expr_part, model.membrane_voltage_var)
                if vs is not None and ve is not None:
                    print("*V for " + str(U_offset) + " range* ")
                    print("`" +printer.doprint(vs) + " - "+ printer.doprint(ve) +"`")
                    singularities_parts = []
                    for sp in singularity_points - singularity_points_processed:
                        sing_no += 1
                        singularity_points_processed.add(sp)
#                        singularity_piecewise_parts.append((f(vs) + ((model.membrane_voltage_var - vs) / (ve - vs)) * (f(ve) - f(vs)), Abs(model.membrane_voltage_var-sp) < ve-sp))
                        singularity_piecewise_parts.append((f(vs) + ((model.membrane_voltage_var - vs) / (ve - vs)) * (f(ve) - f(vs)), Abs(model.membrane_voltage_var-sp) < Abs((ve-vs)/2)))

                        draw_graph(expr, sp, model, eq_no, sing_no, vs, ve, U)
                else:
                    A=Wild('A', real=True)
                    B=Wild('B', real=True)
                    match, _ = match_pattern(expr_part, [A + B], [lambda m: m is not None and A in m and B in m and m[A] != 0.0 and m[B] != 0.0])  # Eq is A + B: handle and and B analysis seperately
                    if match: # Eq is A + B: handle and and B analysis seperately
                        print('####A + B:\n')
                        print('`'+printer.doprint(match[A])+'`')
                        print('`'+printer.doprint(match[B])+'`')
                        print()
                        (sing_no, singularity_points_processed, singularity_piecewise_parts) = process_singularities_eq(expr, match[A], get_singularity_points(match[A], model.membrane_voltage_var), sing_no, singularity_points_processed, singularity_piecewise_parts, params)
                        (sing_no, singularity_points_processed, singularity_piecewise_parts) = process_singularities_eq(expr, match[B], get_singularity_points(match[B], model.membrane_voltage_var), sing_no, singularity_points_processed, singularity_piecewise_parts, params)
                    elif isinstance(expr_part, Mul) and (isinstance(expr_part.args[0], Float) or isinstance(expr_part.args[0], float)):  # Eq is number * expr: handle expr seperately
                        print('#### float * A\n')
                        part = Mul(*expr_part.args[1:])
                        (sing_no, singularity_points_processed, singularity_piecewise_parts) = process_singularities_eq(expr, part, get_singularity_points(part, model.membrane_voltage_var), sing_no, singularity_points_processed, singularity_piecewise_parts, params)  # Eq is 1 / expr: handle expr seperately
                    elif isinstance(expr_part, Pow) and expr_part.args[1] == -1 and len(expr_part.args) == 2:  # 1/A
                        print('####1 / A\n')
                        print()
                        (sing_no, singularity_points_processed, singularity_piecewise_parts) = process_singularities_eq(expr, expr_part.args[0], get_singularity_points(expr_part.args[0], model.membrane_voltage_var), sing_no, singularity_points_processed, singularity_piecewise_parts, params)
                    else:
                        # 1/x warning
                        print('####Failed to find U symbolically!')
                        print()
                        print(type(expr_part))
                        print(expr_part)
                        if not params:
                            print("\n*try substituting parameters*\n")
                            #vardefs = [Eq(e, get_initial_value(e, model)) for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))]
                            #vardefs = [Eq(e, get_initial_value(e, model)) for e in _get_modifiable_parameters(model)]

                            #subs_dict = {eq.lhs: eq.rhs for eq in model.derivative_equations} | MATH_FUNC_SYMPY_MAPPING
                            #vardefs = {e: get_initial_value(e, model) for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))}
                            #vardefs_offset = {e: get_initial_value(e, model) + 1e-7 for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))}

                            #rhs_eq = Eq(Variable('rhs', 'dimensionless'), rhs)
                            #partial_eval_eq = partial_eval(vardefs + model.derivative_equations + [rhs_eq], list(model.y_derivatives) + [rhs_eq.lhs], keep_multiple_usages=False)[-1]
                            prev_expr = None
                            while expr_part != prev_expr:
                                prev_expr = expr_part
                                expr_part = expr_part.subs(subs_dict | paramdefs)
                            
                            #return process_singularities_eq(expr, partial_eval_eq.rhs, singularity_points, sing_no, singularity_points_processed, singularity_piecewise_parts, params=True)
                            return process_singularities_eq(expr, expr_part, singularity_points, sing_no, singularity_points_processed, singularity_piecewise_parts, params=True)
        return (sing_no, singularity_points_processed, singularity_piecewise_parts)

    #subs_dict = {eq.lhs: eq.rhs for eq in model.derivative_equations}

    eq_no = 0
    for eq in model.derivative_equations:
        if len(eq.rhs.atoms(Piecewise)) > 0:
            print(printer.doprint(eq.lhs) + " = " + printer.doprint(eq.rhs))
            print('\n####Piecewise!!')
            print()
            continue

        prev_rhs = None
        rhs = eq.rhs
        partial_eval_rhs = eq.rhs.subs(MATH_FUNC_SYMPY_MAPPING)
        
        # Get singularities
        singularity_points = get_singularity_points(partial_eval_rhs, model.membrane_voltage_var)
        # recurse till we find singularities or nothing changes
        while len(singularity_points) == 0 and rhs != partial_eval_rhs:
            prev_rhs = partial_eval_rhs
            rhs = rhs.subs(unprocessed_eqs)
            partial_eval_rhs = partial_eval_rhs.subs(unprocessed_eqs | MATH_FUNC_SYMPY_MAPPING)
            singularity_points = get_singularity_points(partial_eval_rhs, model.membrane_voltage_var)

        if singularity_points:
            eq_no += 1
            print("## Equation "+ str(eq_no) + ":")
            print("```")
            print(printer.doprint(eq.lhs) + " = " + printer.doprint(eq.rhs))
            print("```")
            print("### Partially evaluated to: ")
#            partial_eval_eq = partial_eval(model.derivative_equations + [eq], list(model.y_derivatives) + [eq.lhs], keep_multiple_usages=False)[-1]
#            partial_eval_rhs = partial_eval_eq.rhs.subs(MATH_FUNC_SYMPY_MAPPING)
            print("```")
#            print(printer.doprint(partial_eval_eq.lhs) + " = " + printer.doprint(partial_eval_rhs))
            print(printer.doprint(eq.lhs) + " = " + printer.doprint(rhs))
            print("```")
            print("### Singulariy points detected:\n")
            print(singularity_points)
#            (sing_no, singularity_points_processed, singularity_piecewise_parts) = process_singularities_eq(partial_eval_eq.rhs, partial_eval_rhs, singularity_points, sing_no=0, singularity_points_processed=set(), singularity_piecewise_parts=[])
            (sing_no, singularity_points_processed, singularity_piecewise_parts) = process_singularities_eq(rhs, partial_eval_rhs, singularity_points, sing_no=0, singularity_points_processed=set(), singularity_piecewise_parts=[])
            if len(singularity_piecewise_parts) > 0:
                print("## New Eq:")
                singularity_piecewise_parts.append((eq.rhs, True))
                new_expr = Piecewise(*singularity_piecewise_parts)
                print(printer.doprint(new_expr))
                unprocessed_eqs.pop(eq.lhs)
                print()
#new eq for overall eq!

def get_U(rhs, V):
    def match_U(match):
        def check_match(m):
            return m is not None and P in m and Q in m and m[P] != 0.0
        #return match_pattern(match[U], [P * exp(Q) - 1.0, -P * exp(Q) + 1.0, P * exp(Q) + 1.0], [check_match, check_match, check_match])[0]
        if match is None or U not in match or A not in match:
            return None
        return match_pattern(match[U], [P * exp(Q) - 1.0, -P * exp(Q) + 1.0], [check_match, check_match])[0]
    (vs,ve, U) = (None, None, None)
    A=Wild('A', real=True)
    U=Wild('U', real=True, exclude=[Rational])
    P=Wild('P', real=True)
    Q=Wild('Q', real=True)
    R=Wild('R', real=True)
    S=Wild('S', real=True)
  
    match, find_U = match_pattern(rhs, [A / U, U / A], [match_U, match_U])
    if match and find_U:
        u = (find_U[Q] + log(find_U[P]))
        print("*U*")
        print("`" +printer.doprint(u)+"`")
        print()
        #find_v_low = solveset(u + U_offset, V, domain=Reals)
        #find_v_up = solveset(u - U_offset, V, domain=Reals)
        find_v_low = solveset(u + U_offset, V)
        find_v_up = solveset(u - U_offset, V)
        assert len(find_v_low) < 2
        assert len(find_v_up) < 2
        find_v_low = list(find_v_low)
        find_v_up = list(find_v_up)
        if find_v_low and find_v_up:
            (vs, ve, U) = (find_v_low[-1], find_v_up[-1], u)

#    if ve and vs and ve < vs:  # adjust the range from smaller to larger
#        return (ve, vs, U)
#    else:
    return (vs, ve, U)



def draw_graph(rhs, point, model, eq_no, sing_no, vs, ve, U, draw_points=2000):
    subs_dict = {eq.lhs: eq.rhs for eq in model.derivative_equations} | MATH_FUNC_SYMPY_MAPPING
    vardefs = {e: get_initial_value(e, model) for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))}
    vardefs_offset = {e: get_initial_value(e, model) + 1e-7 for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))}
    prev_rhs = None
    while prev_rhs != rhs:
        prev_rhs = rhs
        newrhs = rhs.subs(subs_dict | vardefs)
        if newrhs == 0:
            rhs = rhs.subs(subs_dict | vardefs_offset)
        else:
            rhs = newrhs

    prev_ve = None
    while prev_ve != ve:
        prev_ve = ve
        ve = ve.subs(subs_dict | vardefs)

    prev_vs = None
    while prev_vs != vs:
        prev_vs = vs
        vs = vs.subs(subs_dict | vardefs)

    if ve < vs:  # Swap to adjust the range from smaller to larger
        ve, vs = vs, ve
        
    # vardefs = [Eq(e, get_initial_value(e, model)) for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))]
    # vardefs_offset = [Eq(e, get_initial_value(e, model) + 1e-7) for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))]
    # rhs_eq = Eq(Variable('rhs', 'dimensionless'), rhs)


    # partial_eval_eq = partial_eval(vardefs + model.derivative_equations + [rhs_eq], list(model.y_derivatives) + [rhs_eq.lhs], keep_multiple_usages=False)[-1]
    # if partial_eval_eq.rhs == 0:  #add small number
        # partial_eval_eq = partial_eval(vardefs_offset + model.derivative_equations + [rhs_eq], list(model.y_derivatives) + [rhs_eq.lhs], keep_multiple_usages=False)[-1]
    # rhs=partial_eval_eq.rhs.subs(MATH_FUNC_SYMPY_MAPPING)
    
#    if not isinstance(point,Float):
#        sp_eq = Eq(Variable('sp', 'dimensionless'), point)
#        point = partial_eval(vardefs_offset + model.derivative_equations + [sp_eq], list(model.y_derivatives) + [sp_eq.lhs], keep_multiple_usages=False)[-1]
#        point = point.rhs

    V = model.membrane_voltage_var
    fig = plt.figure()
    ax1 = fig.add_subplot(111)
    x, y, y2 = [], [], []

    A = (ve, rhs.subs({V:ve}))
    B = (vs, rhs.subs({V:vs}))
    
    slope = (A[1]-B[1])/(ve - vs)
    
    #slope-pont
    f = slope*(V - A[0]) + A[1]
    ymin = min(A[1], B[1])
    ymax = max(A[1], B[1])

    ydiff = ymax-ymin if ymax-ymin != 0 else ve - vs
    #plt.ylim(float(ymin - ydiff), float(ymax + ydiff))
    #plt.ylim(float(ymin - 10*ydiff), float(ymax + 10*ydiff))
    #plt.ylim(float(ymin - 100*ydiff), float(ymax + 100*ydiff))
    plt.xlim(float(vs - (ve - vs)), float(ve + (ve - vs)))
    plt.axvspan(vs, ve, color='gold', alpha=0.125)

    current_point = point - (1.5 * (ve - vs))
    for _ in range(draw_points):
        val = rhs.subs({V: current_point})
        if val.is_real:
            x.append(current_point)
            y.append(val)
            y2.append(f.subs({V: current_point}))
        current_point+=(3 * (ve - vs))/draw_points

    plt.plot(x,y, color="silver")
    plt.plot(x,y2, color="red")
    image_dir = 'diagrams/stepwise_recursion/' + model.name
    os.makedirs(image_dir, exist_ok=True)
    image_name = image_dir + '/eq' + str(eq_no) + '-sing' + str(sing_no) + '.png'
    plt.savefig(image_name)
    print("\n*Singularity point: " + str(point) +"*")
    print("\n![point](" + image_name + ")")
    
    #plt.show()
    #assert False
    plt.close('all')
    
for file_name in (#'old_davies_isap_2012.cellml',
                  #'aslanidi_model_2009.cellml',
                  #'beeler_reuter_model_1977.cellml',
                  #'bondarenko_model_2004_apex.cellml',
                  #'bondarenko_szigeti_bett_kim_rasmusson_2004_apical.cellml',
                  #'courtemanche_ramirez_nattel_model_1998.cellml',
                  #'decker_2009.cellml',
                  #'demir_model_1994.cellml',
                  #'difrancesco_noble_model_1985.cellml',
                  #'dokos_model_1996.cellml',
                  #'earm_noble_model_1990.cellml',
                  #'espinosa_model_1998_normal.cellml',
                  #'FaberRudy2000.cellml',
                  #'fink_noble_giles_model_2008.cellml',
                  #'grandi2010ss.cellml',
                  #'hilgemann_noble_model_1987.cellml',
                  #'hodgkin_huxley_squid_axon_model_1952_modified.cellml',
                  #'hund_rudy_2004_a.cellml',
                  #'iribe_model_2006_without_otherwise_section.cellml',
                  #'iyer_model_2004.cellml',
                  #'iyer_model_2007.cellml',
                  #'jafri_rice_winslow_model_1998.cellml',
                  #'kurata_model_2002.cellml',
                  #'livshitz_rudy_2007.cellml',
                  #'li_mouse_2010.cellml',
                  #'luo_rudy_1994.cellml',
                  #'mahajan_2008.cellml',
                  #'matsuoka_model_2003.cellml',
                  #'new_luo_rudy_1991_with_range.cellml',
                  #'noble_model_1991.cellml',
                  #'noble_model_1998.cellml',
                  #'noble_noble_SAN_model_1984.cellml',
                  #'noble_SAN_model_1989.cellml',
                  #'nygren_atrial_model_1998.cellml',
                  #'paci_hyttinen_aaltosetala_severi_ventricularVersion.cellml',
                  #'pandit_model_2001_epi.cellml',
                  #'priebe_beuckelmann_model_1998.cellml',
                  #'sachse_moreno_abildskov_2008_b.cellml',
                  #'sakmann_model_2000_epi.cellml',
                  #'Shannon2004.cellml',
                  #'stewart_zhang_model_2008_ss.cellml',
                  #'ten_tusscher_model_2004_endo.cellml',
                  #'ten_tusscher_model_2004_epi.cellml',
                  #'ten_tusscher_model_2006_epi.cellml',
                  #'viswanathan_model_1999_epi.cellml',
                  #'winslow_model_1999.cellml',
                  #'zhang_SAN_model_2000_0D_capable.cellml',
                  #'zhang_SAN_model_2000_all.cellml',

                  'aslanidi_atrial_model_2009.cellml',
                  'aslanidi_Purkinje_model_2009.cellml',
                  'beeler_reuter_model_1977.cellml',
                  'benson_epicardial_2008.cellml',
                  'bernus_wilders_zemlin_verschelde_panfilov_2002.cellml',
                  'bondarenko_szigeti_bett_kim_rasmusson_2004_apical.cellml',
                  'bondarenko_szigeti_bett_kim_rasmusson_2004_septal.cellml',
                  'bueno_2007_endo.cellml',
                  'bueno_2007_epi.cellml',
                  'carro_2011_endo.cellml',
                  'carro_2011_epi.cellml',
                  'clancy_rudy_2002.cellml',
                  'corrias_purkinje_2011.cellml',
                  'courtemanche_ramirez_nattel_1998.cellml',
                  'davies_isap_2012.cellml',
                  'decker_2009.cellml',
                  'demir_model_1994.cellml',
                  'difrancesco_noble_model_1985.cellml',
                  'dokos_model_1996.cellml',
                  'earm_noble_model_1990.cellml',
                  'espinosa_model_1998_normal.cellml',
                  'faber_rudy_2000.cellml',
                  'fink_noble_giles_model_2008.cellml',
                  'fox_mcharg_gilmour_2002.cellml',
                  'grandi_pasqualini_bers_2010_ss.cellml',
                  'grandi_pasqualini_bers_2010_ss_endo.cellml',
                  'hilgemann_noble_model_1987.cellml',
                  'hodgkin_huxley_squid_axon_model_1952_modified.cellml',
                  'hund_rudy_2004.cellml',
                  'iribe_model_2006.cellml',
                  'iyer_2004.cellml',
                  'iyer_model_2007.cellml',
                  'jafri_rice_winslow_model_1998.cellml',
                  'kurata_model_2002.cellml',
                  'lindblad_model_1996.cellml',
                  'livshitz_rudy_2007.cellml',
                  'li_mouse_2010.cellml',
                  'luo_rudy_1991.cellml',
                  'luo_rudy_1994.cellml',
                  'mahajan_shiferaw_2008.cellml',
                  'maleckar_model_2009.cellml',
                  'maltsev_2009.cellml',
                  'matsuoka_model_2003.cellml',
                  'mcallister_noble_tsien_1975_b.cellml',
                  'noble_model_1962.cellml',
                  'noble_model_1991.cellml',
                  'noble_model_1998.cellml',
                  'noble_model_2001.cellml',
                  'noble_noble_SAN_model_1984.cellml',
                  'noble_SAN_model_1989.cellml',
                  'nygren_atrial_model_1998.cellml',
                  'ohara_rudy_2011_endo.cellml',
                  'ohara_rudy_2011_epi.cellml',
                  'ohara_rudy_cipa_v1_2017.cellml',
                  'paci_hyttinen_aaltosetala_severi_atrialVersion.cellml',
                  'paci_hyttinen_aaltosetala_severi_ventricularVersion.cellml',
                  'pandit_clark_giles_demir_2001_endocardial_cell.cellml',
                  'pandit_clark_giles_demir_2001_epicardial_cell.cellml',
                  'pasek_simurda_christe_2006.cellml',
                  'pasek_simurda_orchard_christe_2008.cellml',
                  'priebe_beuckelmann_1998.cellml',
                  'ramirez_nattel_courtemanche_2000.cellml',
                  'sachse_moreno_abildskov_2008_b.cellml',
                  'sakmann_model_2000_epi.cellml',
                  'shannon_wang_puglisi_weber_bers_2004.cellml',
                  'stewart_zhang_model_2008_ss.cellml',
                  'ten_tusscher_model_2004_endo.cellml',
                  'ten_tusscher_model_2004_epi.cellml',
                  'ten_tusscher_model_2004_M.cellml',
                  'ten_tusscher_model_2006_endo.cellml',
                  'ten_tusscher_model_2006_epi.cellml',
                  'ten_tusscher_model_2006_M.cellml',
                  'ToRORd_fkatp_endo.cellml',
                  'ToRORd_fkatp_epi.cellml',
                  'Trovato2020.cellml',
                  'viswanathan_model_1999_epi.cellml',
                  'wang_sobie_2008.cellml',
                  'winslow_model_1999.cellml',
                  'zhang_SAN_model_2000_0D_capable.cellml'
                  ):
    model = load_model_with_conversions(os.path.join(DATA_DIR, '..', '..', '..', 'cellml', file_name), quiet=True)
    print("# Model: " + model.name + '('+file_name+')')
    _process_singularities(model)
    
    # #deqs = partial_eval(model.derivative_equations, model.y_derivatives, keep_multiple_usages=False)
    # vardefs_symbols = (_get_modifiable_parameters(model) | model.state_vars )
    # subs_dict = {eq.lhs: eq.rhs for eq in model.derivative_equations}

    # for eq in model.derivative_equations:
# #        print(eq)
        # prev_rhs = None
        # rhs = eq.rhs.subs(MATH_FUNC_SYMPY_MAPPING)
# #        try:
        # singularity_points = get_singularity_points(rhs, model.membrane_voltage_var)
        # while len(singularity_points) == 0 and rhs != prev_rhs:
            # prev_rhs = rhs
            # rhs = rhs.subs(subs_dict)
            # singularity_points = get_singularity_points(rhs, model.membrane_voltage_var)
# #            print(singularity_points)
# #        except Exception as e:
# #            print(e)
# #            print(type(rhs))
# #            print(rhs)
            # # print(model.name)
            # # print(eq)
            # # print(e)
            # # print()
    # print("done")
    # print()

#model.derivative_equations = [model.derivative_equations[36]]

#print(printer.doprint(model.derivative_equations[-1].rhs) + '=' + printer.doprint(model.derivative_equations[-1].rhs))

#model.derivative_equations = [Eq(model.derivative_equations[-1].lhs, model.derivative_equations[-1].rhs.args[1].args[0].subs(MATH_FUNC_SYMPY_MAPPING))]
#_process_singularities(model)
