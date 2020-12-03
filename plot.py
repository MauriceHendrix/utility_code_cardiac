## script to generate singularities images. requires chaste_codegen, it's cellml files, matplotlib and numpy

# todo:
# check top of eqs?
#printer


# We probably want to limit the search to -150 to +100mV ish

import os
from sympy import *
import sympy.core.numbers
from sympy.codegen.rewriting import ReplaceOptim, expm1_opt, optimize
import matplotlib.pyplot as plt
import numpy as np
from chaste_codegen import (add_conversions, ChastePrinter, load_model_with_conversions, DATA_DIR)
from chaste_codegen._math_functions import substitute_math_func, exp_
from chaste_codegen._partial_eval import partial_eval
from chaste_codegen.model_with_conversions import (get_equations_for, _get_modifiable_parameters)
from cellmlmanip.model import Variable
from func_timeout import func_set_timeout, FunctionTimedOut
import time
from cellmlmanip import load_model


U_offset = 1e-7

printer = ChastePrinter(lambda var: str(var).lstrip('_').replace('$', '__'),
                        lambda deriv: str(deriv).lstrip('_').replace('$', '__'))

            
@func_set_timeout(4)
def simple(expr):
    try:
        return simplify(expr)
    except Exception as e:
        print("simplify error: " + str(e))
    #return expr.factor()

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
    if not isinstance(equation, Float):
        for pattern, func in zip(patterns, functions):
            match = equation.match(pattern)
            check_match = func(match)
#           if not check_match:
#               match = equation.factor().match(pattern)
#               try:
#                   simplified_eq = simple(equation)
#                   match = simplified_eq.match(pattern)
#               except FunctionTimedOut:
#                   pass # took to long
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
            return set()
        
    def handle_FinisteSet(sp):
        #return FiniteSet(*filter(lambda s: s.is_real, sp))
        return set(filter(lambda s: s.is_real, sp))

    def handle_Complement(sp):
        return handle_FinisteSet(sp.args[1]) if isinstance(sp.args[1], FiniteSet) else set()

    def handle_Union(sp):
        singularity_points = set()
        for s in sp.args:
            singularity_points = singularity_points.union(handle_singularity_points(s))
        return singularity_points

    # Don't waste time with expressions without exp
    if len(rhs.atoms(exp)) == 0:
        return set()
    try:
        singularity_points = singularities(rhs, V, domain=Reals)
    except (RecursionError, NotImplementedError):
        print("Singularities cannot be found error")
        return EmptySet  #Finding singularities failes, further substitutes are unlikley to work.
    except Exception as e:
        if not isinstance(e, RecursionError) and not isinstance(e, NotImplementedError):
            print("singularity error: " + str(e))
        return EmptySet  #Finding singularities failes, further substitutes are unlikley to work.
    
    return set(handle_singularity_points(singularity_points))

def get_U(rhs, V):
    def find_u_pattern():
        for outer_pattern in (A / U1, U1 / A, A / U2, U2 / A):
        #for outer_pattern in (A / U, U / A):
            match = rhs.match(outer_pattern)
            #if match is not None:
            #    print(match.get(U1, match.get(U2, None)))
            #    print(match)
            #    print()
            #if match is not None and U in match:
            if match is not None:
                match_found = match.get(U1, match.get(U2, None))
                if  match_found is not None:
                    for inner_pattern in (P * exp(Q) - 1.0, -P * exp(Q) + 1.0):
                        #find_U = match[U].match(inner_pattern)
                        find_U = match_found.match(inner_pattern)
                        if find_U is not None and P in find_U and Q in find_U and find_U[P] != 0.0:
                            # find U on top
                            top = match.get(A, None)
                            #assert top is not None and top.match()
                            #print('top')
                            top_match = top.match((find_U[Q] + log(find_U[P])) * Wild('x') + Wild('y'))
                            if not top_match:
                                top_match = top.match(exp(find_U[Q] + log(find_U[P])) * Wild('x') + Wild('y'))
                            #print(top.match((find_U[Q] + log(find_U[P])) * Wild('x') + Wild('y')))
                            #print(top.match(exp(find_U[Q] + log(find_U[P])) * Wild('x') + Wild('y')))
                            #print('--')
                            assert top_match is not None, str(top_match)
                            return find_U
        return None

    (vs, ve, U, sp) = (None, None, None, None)
    A=Wild('A', real=True)
    U1=Wild('U1', real=True, exclude=[Rational])
    U2=Wild('U2', real=True, exclude=[Rational and not sympy.core.numbers.NegativeOne])
    P=Wild('P', real=True)
    Q=Wild('Q', real=True)

    find_U = find_u_pattern()
    if find_U:
        u = (find_U[Q] + log(find_U[P]))
        sp = tuple(filter(lambda s: not s.has(I), solveset(u, V)))
            
        if len(sp) == 1:
            find_v_low = solveset(u + U_offset, V)
            find_v_up = solveset(u - U_offset, V)
            #assert len(find_v_low) < 2
            #assert len(find_v_up) < 2
            find_v_low = tuple(find_v_low)
            find_v_up = tuple(find_v_up)
            if find_v_low and find_v_up:
                (vs, ve, U, sp) = (find_v_low[-1], find_v_up[-1], u, sp[-1])

    #return (vs, ve, U)
    return (vs, ve, U, sp)



# def draw_graph(rhs, point, model, eq_no, sing_no, vs, ve, U, vardefs, vardefs_offset, deriv_eqs_dict, draw_points=2000):
    # prev_rhs = None
    # while prev_rhs != rhs:
        # prev_rhs = rhs
        # newrhs = rhs.subs(deriv_eqs_dict | vardefs | MATH_FUNC_SYMPY_MAPPING)
        # if newrhs == 0:
            # rhs = rhs.subs(deriv_eqs_dict | vardefs_offset | MATH_FUNC_SYMPY_MAPPING)
        # else:
            # rhs = newrhs

    # prev_ve = None
    # while prev_ve != ve:
        # prev_ve = ve
        # ve = ve.subs(deriv_eqs_dict | vardefs | MATH_FUNC_SYMPY_MAPPING)

    # prev_vs = None
    # while prev_vs != vs:
        # prev_vs = vs
        # vs = vs.subs(deriv_eqs_dict | vardefs | MATH_FUNC_SYMPY_MAPPING)

    # if ve < vs:  # Swap to adjust the range from smaller to larger
        # ve, vs = vs, ve
        

    # V = model.membrane_voltage_var
    # fig = plt.figure()
    # ax1 = fig.add_subplot(111)
    # x, y, y2 = [], [], []

    # A = (ve, rhs.subs({V:ve}))
    # B = (vs, rhs.subs({V:vs}))
    
    # slope = (A[1]-B[1])/(ve - vs)
    
    # #slope-pont
    # f = slope*(V - A[0]) + A[1]
    # ymin = min(A[1], B[1])
    # ymax = max(A[1], B[1])

    # ydiff = ymax-ymin if ymax-ymin != 0 else ve - vs
    # plt.xlim(float(vs - (ve - vs)), float(ve + (ve - vs)))
    # plt.axvspan(vs, ve, color='gold', alpha=0.125)

    # current_point = point - (1.5 * (ve - vs))
    # for _ in range(draw_points):
        # val = rhs.subs({V: current_point})
        # if val.is_real:
            # x.append(current_point)
            # y.append(val)
            # y2.append(f.subs({V: current_point}))
        # current_point+=(3 * (ve - vs))/draw_points

    # plt.plot(x,y, color="silver")
    # plt.plot(x,y2, color="red")
    # image_dir = 'diagrams/stepwise_recursion/' + model.name
    # os.makedirs(image_dir, exist_ok=True)
    # image_name = image_dir + '/eq' + str(eq_no) + '-sing' + str(sing_no) + '.png'
    # plt.savefig(image_name)
    # print("\n*Singularity point: " + str(point) +"*")
    # print("\n![point](" + image_name + ")")
    
    # #plt.show()
    # #assert False
    # plt.close('all')
    


def get_new_expr_parts(expr, expr_eval, expr_part_eval, V, singularity_piecewise_parts=[], params=True):
    def f(Vx):
        return expr_eval.xreplace({V:Vx})

    if not isinstance(expr_part_eval, Float) and not isinstance(expr_part_eval, int) and not isinstance(expr_part_eval, Piecewise): # eq=0 or piecewise
        (vs,ve, U, sp) = get_U(expr_part_eval, V)
        if vs is not None and ve is not None:
            print('*U*: '+printer.doprint(U))
            print("*V for " + str(U_offset) + " range* ")
            print("`" +printer.doprint(vs) + " - "+ printer.doprint(ve) +"`")
            #singularities_to_do = get_singularity_points(expr_part_eval, V) - singularity_points_processed
            # process unprocessed singularities
            #for sp in singularities_to_do:
            #for sp in set(singularity_point):
            #singularity_points_processed.add(sp)
            #store singularity parts for new equation
            print(f(vs) + ((model.membrane_voltage_var - vs) / (ve - vs)) * (f(ve) - f(vs)))
            singularity_piecewise_parts.append((f(vs) + ((model.membrane_voltage_var - vs) / (ve - vs)) * (f(ve) - f(vs)), Abs(model.membrane_voltage_var-sp) < Abs((ve-vs)/2)))
        else:
            A=Wild('A', real=True)
            B=Wild('B', real=True)
            match = expr_part_eval.match(A + B)
            if match and A in match and B in match and match[A] != 0.0 and match[B] != 0.0: # Eq is A + B: handle and and B analysis seperately
                #print('#### A+B')
                (singularity_piecewise_parts) = get_new_expr_parts(expr, expr_eval, match[A], V, singularity_piecewise_parts=singularity_piecewise_parts, params=params)
                return get_new_expr_parts(expr, expr_eval, match[B], V, singularity_piecewise_parts=singularity_piecewise_parts, params=params)
            elif isinstance(expr_part_eval, Mul) and (isinstance(expr_part_eval.args[0], Float) or isinstance(expr_part_eval.args[0], float)):  # Eq is number * expr: handle expr seperately
                #print('#### float * A\n')
                part = Mul(*expr_part_eval.args[1:])
                return get_new_expr_parts(expr, expr_eval, part, V, singularity_piecewise_parts=singularity_piecewise_parts, params=params)
            elif isinstance(expr_part_eval, Pow) and expr_part_eval.args[1] == -1 and len(expr_part_eval.args) == 2:  # 1/A
                #print('####1 / A\n')
                return get_new_expr_parts(expr, expr_eval, expr_part_eval.args[0], V, singularity_piecewise_parts=singularity_piecewise_parts, params=params)
            else:
                # 1/x warning
                #print('####Failed to find U symbolically!')
                if params:
                    #print("\n*try substituting parameters*\n")
                    prev_expr = None
                    expr_part_eval = expr_part_eval.xreplace(paramdefs)
                    old_singularity_piecewise_parts = str(singularity_piecewise_parts)
                    (singularity_piecewise_parts) = get_new_expr_parts(expr, expr_eval, expr_part_eval, V, singularity_piecewise_parts=singularity_piecewise_parts, params=False)
                    if old_singularity_piecewise_parts != str(singularity_piecewise_parts):
                        print("found! ")

    return singularity_piecewise_parts
    


for file_name in ('aslanidi_atrial_model_2009.cellml',
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
    tic = time.perf_counter()
    model = load_model_with_conversions(os.path.join(DATA_DIR, '..', '..', '..', 'cellml', file_name), quiet=True)
    print("# Model: " + model.name + '('+file_name+')')

    toc = time.perf_counter()
    print('load time: ' + str(toc-tic))
    print()

    tic2 = time.perf_counter()
    paramdefs = {e: get_initial_value(e, model) for e in _get_modifiable_parameters(model)}
    unprocessed_eqs = {}
    eq_defs = {}

    eq_no=0
    for eq in model.derivative_equations:
        rhs = substitute_math_func(eq.rhs)
        #pe_expr = rhs.xreplace(unprocessed_eqs)
#        if not isinstance(pe_expr, Piecewise): # piecewise
        if not isinstance(rhs, Piecewise): # piecewise
            #unprocessed_eqs[eq.lhs] = pe_expr
            eq_defs[eq.lhs] = rhs
            old_pe=None
            
            singularity_piecewise_parts = get_new_expr_parts(eq.rhs, eq_defs[eq.lhs], eq_defs[eq.lhs], model.membrane_voltage_var, singularity_piecewise_parts=[], params=True)
            
            while eq_defs[eq.lhs] != old_pe and len(singularity_piecewise_parts) == 0:
                old_pe = eq_defs[eq.lhs]
                eq_defs[eq.lhs] = eq_defs[eq.lhs].xreplace(eq_defs)
                singularity_piecewise_parts = get_new_expr_parts(eq.rhs, eq_defs[eq.lhs], eq_defs[eq.lhs], model.membrane_voltage_var, singularity_piecewise_parts=[], params=True)
            

            #singularity_piecewise_parts = get_new_expr_parts(eq.rhs, unprocessed_eqs[eq.lhs], unprocessed_eqs[eq.lhs], model.membrane_voltage_var, singularity_piecewise_parts=[], params=True)

            if len(singularity_piecewise_parts) > 0:
                eq_no+=1
                print("## Equation "+ str(eq_no) + ":")
                print("```")
                print(printer.doprint(eq.lhs) + " = " + printer.doprint(eq.rhs))
                print("```")
                print("### Partially evaluated to: ")
                print("```")
                #print(printer.doprint(eq.lhs) + " = " + printer.doprint(unprocessed_eqs[eq.lhs]))
                print(printer.doprint(eq.lhs) + " = " + printer.doprint(eq_defs[eq.lhs]))
                print("```")
                singularity_piecewise_parts.append((eq.rhs, True))
                new_expr = Piecewise(*singularity_piecewise_parts)
                #unprocessed_eqs.pop(eq.lhs)
                eq_defs.pop(eq.lhs)
                print("## New Eq:")
                print("```")
                print(printer.doprint(eq.lhs) + " = " + printer.doprint(new_expr))
                print()
                print("```")
                print()

    toc2 = time.perf_counter()
    print("singularity processing time: "+str(toc2-tic2))

    # tic3 = time.perf_counter()

    # toc3 = time.perf_counter()
    # p2+=toc3-tic3
    # print("proc2: "+str(toc3-tic3))

    # vardefs = {e: get_initial_value(e, model) for e in _get_modifiable_parameters(model) | (model.state_vars - set([model.membrane_voltage_var]))}

    # for k in unprocessed_eqs:
        # if (printer.doprint(unprocessed_eqs[k]) != printer.doprint(unprocessed_eqs2[k]) and simplify(unprocessed_eqs[k]-unprocessed_eqs2[k])!=0):
            # for i in range (-200, 200, 15):
                # e1 = unprocessed_eqs[k].subs({model.membrane_voltage_var: i} |vardefs)
                # e2 = unprocessed_eqs2[k].subs({model.membrane_voltage_var: i}|vardefs)
                # assert e1.evalf() == e2.evalf(), '\n'+str(e1)+'\n'+str(e2)+'\n'+str(unprocessed_eqs[k])+'\n'+str(unprocessed_eqs2[k])

