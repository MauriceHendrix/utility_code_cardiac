## script to generate singularities images. requires chaste_codegen, it's cellml files, matplotlib and numpy

# todo:
# We probably want to limit the search to -150 to +100mV ish
# try finding without vardefs
# 1/x warning

import os
from sympy import *
from sympy.codegen.rewriting import ReplaceOptim, expm1_opt, optimize
import matplotlib.pyplot as plt
import numpy as np
from chaste_codegen import (add_conversions, ChastePrinter, load_model_with_conversions, DATA_DIR)
from chaste_codegen._math_functions import MATH_FUNC_SYMPY_MAPPING
from chaste_codegen._partial_eval import partial_eval
from chaste_codegen.model_with_conversions import (get_equations_for, _get_modifiable_parameters)

U_offset = 1e-7

printer = ChastePrinter(lambda var: str(var).lstrip('_').replace('$', '__'),
                        lambda deriv: str(deriv).lstrip('_').replace('$', '__'))


def match_pattern(eq, patterns, conditions):
    check_match = None
    for pattern, condition in zip(patterns, conditions):
        match = eq.match(pattern)
        check_match = condition(match)
        if not check_match:
            match = eq.factor().match(pattern)
            check_match = condition(match)
#        if not check_match:
#            match = eq.expand().match(pattern)
#            check_match = condition(match)
        if check_match:
            return match, check_match
    return None, None

def _process_singularities(model):
    def _get_initial_value(var):
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
#            print('handle_singularity_points')
#            print(sp)
            if isinstance(sp, FiniteSet):
                return handle_FinisteSet(sp)
            elif isinstance(sp, Complement):
                return handle_Complement(sp)
            elif isinstance(sp, Union):
                return handle_Union(sp)
            else:
                return EmptySet
        
        def handle_FinisteSet(sp):
#            print('handle_FinisteSet')
#            print(sp)
#            print(type(sp))
            return FiniteSet(*filter(lambda s: s.is_real, sp))

        def handle_Complement(sp):
#            print('handle_Complement')
#            print(sp)
            return handle_FinisteSet(sp.args[1]) if isinstance(sp.args[1], FiniteSet) else EmptySet

        def handle_Union(sp):
#            print('handle_Union')
#            print(sp)
            singularity_points = EmptySet
            for s in sp.args:
                singularity_points = singularity_points.union(handle_singularity_points(s))
            return singularity_points

        singularity_points = singularities(rhs, V, domain=Reals)
        return set(handle_singularity_points(singularity_points))
#        if singularity_points is EmptySet or isinstance(singularity_points, Intersection) or isinstance(singularity_points, ConditionSet) or isinstance(singularity_points, Complement):
#            return None
#        if isinstance(singularity_points, Union):
#            # Pick out all fite sets in the argument as 1 finite set
#            finite_sets = [c.args[1] for c in singularity_points.args if isinstance(c, Complement) and isinstance(c.args[1], FiniteSet)]
#            finite_sets += [s for s in singularity_points.args if isinstance(s, FiniteSet)]
#            singularity_points = Union()
#            for s in finite_sets:
#                singularity_points = singularity_points.union(s)
#        assert isinstance(singularity_points, FiniteSet), "Expecting singularity points to be contained in a  FiniteSet:\n" + str(singularity_points)
#        # Pick out just the real answers
#        print(singularity_points)
#        return set(filter(lambda s: s.is_real, singularity_points))

    def process_singularities_eq(expr, expr_part, singularity_points, sing_no=0, singularity_points_processed=set()):
        if singularity_points and singularity_points != singularity_points_processed:
        
        
            if expr_part == 0.0:
                print('#### Eq == 0!')
            elif isinstance(expr_part, Piecewise):
                print('####Piecewise!')
            else:
                (vs,ve, U) = get_U(expr_part, model.membrane_voltage_var)
                if vs is not None and ve is not None:
                    for sp in singularity_points - singularity_points_processed:
                        sing_no += 1
                        singularity_points_processed.add(sp)
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
                        (sing_no, singularity_points_processed) = process_singularities_eq(expr, match[A], get_singularity_points(match[A], model.membrane_voltage_var), sing_no, singularity_points_processed)
                        (sing_no, singularity_points_processed) = process_singularities_eq(expr, match[B], get_singularity_points(match[B], model.membrane_voltage_var), sing_no, singularity_points_processed)
                    elif isinstance(expr_part, Mul) and (isinstance(expr_part.args[0], Float) or isinstance(expr_part.args[0], float)):  # Eq is number * expr: handle expr seperately
                        print('#### float * A\n')
                        part = Mul(*expr_part.args[1:])
                        (sing_no, singularity_points_processed) = process_singularities_eq(expr, part, get_singularity_points(part, model.membrane_voltage_var), sing_no, singularity_points_processed)  # Eq is 1 / expr: handle expr seperately
                    elif isinstance(expr_part, Pow) and expr_part.args[1] == -1 and len(expr_part.args) == 2:  # 1/A
                        print('####1 / A\n')
                        print()
                        (sing_no, singularity_points_processed) = process_singularities_eq(expr, expr_part.args[0], get_singularity_points(expr_part.args[0], model.membrane_voltage_var), sing_no, singularity_points_processed)
                    else:
                        # 1/x warning
                        print('####Failed!')
                        print(type(expr_part))
                        print(expr_part)
                        print(expr_part.args)
        return (sing_no, singularity_points_processed)

    vardefs = [Eq(e, _get_initial_value(e)) for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))]
    #add small number
    vardefs_offset = [Eq(e, _get_initial_value(e) + 1e-7) for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))]
    eq_no = 0
    for eq in model.derivative_equations:
        rhs = eq.rhs.subs(MATH_FUNC_SYMPY_MAPPING)
        #todo: rhs == 0?
        singularity_points = get_singularity_points(rhs, model.membrane_voltage_var)
        if singularity_points:
            eq_no += 1
            print("## Equation "+ str(eq_no) + ":")
            print("```")
            print(printer.doprint(eq.lhs) + " = " + printer.doprint(rhs))
            print("```")
            print("### Partially evaluated to: ")
            partial_eval_eq = partial_eval(vardefs + model.derivative_equations + [eq], list(model.y_derivatives) + [eq.lhs], keep_multiple_usages=False)[-1]
            if partial_eval_eq.rhs == 0:  #add small number
                partial_eval_eq = partial_eval(vardefs_offset + model.derivative_equations + [eq], list(model.y_derivatives) + [eq.lhs], keep_multiple_usages=False)[-1]
            partial_eval_rhs = partial_eval_eq.rhs.subs(MATH_FUNC_SYMPY_MAPPING)
            print("```")
            print(printer.doprint(partial_eval_eq.lhs) + " = " + printer.doprint(partial_eval_rhs))
            print("```")
            print("### Singulariy points detected:\n")
            print(singularity_points)
            process_singularities_eq(partial_eval_rhs, partial_eval_rhs, singularity_points, sing_no=0, singularity_points_processed=set() )

def get_U(rhs, V):
    def match_U(match):
        def check_match(m):
            return m is not None and P in m and Q in m
        return match_pattern(match[U], [P * exp(Q) - 1.0, -P * exp(Q) + 1.0, P * exp(Q) + 1.0], [check_match, check_match, check_match])[0]
    
    (vs,ve, U) = (None, None, None)
    A=Wild('A', real=True)
    U=Wild('U', real=True, exclude=[Rational])
    P=Wild('P', real=True)
    Q=Wild('Q', real=True)
    R=Wild('R', real=True)
    S=Wild('S', real=True)
    
    match, find_U = match_pattern(rhs, [A / U], [lambda m: m is not None and U in m and A in m and match_U(m) ])
    if match and find_U:
        u = find_U[Q] + log(find_U[P])
        print("*U*")
        print("`" +printer.doprint(u)+"`")
        print()
        find_v_low = solveset(u + U_offset, V, domain=Reals)
        find_v_up = solveset(u - U_offset, V, domain=Reals)
        assert len(find_v_low) < 2
        assert len(find_v_up) < 2
        find_v_low = list(find_v_low)
        find_v_up = list(find_v_up)
        if find_v_low and find_v_up:
            top_match, _ = match_pattern(match[A], [R * u + S], [lambda m: m is not None and R in m and R != 0.0])
            if top_match:
                print("*V for " + str(U_offset) + " range* ")
                print("`" +printer.doprint(find_v_low[-1]) + " - "+ printer.doprint(find_v_up[-1]) +"`")
                (vs, ve, U) = (find_v_low[-1], find_v_up[-1], u)
            else:
                print("*Not found on top* ")

    if ve and vs and ve < vs:  # adjust the range from smaller to larger
        return (ve, vs, U)
    else:
        return (vs, ve, U)



def draw_graph(rhs, point, model, eq_no, sing_no, vs, ve, U, draw_points=2000):
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
    plt.ylim(float(ymin - ydiff), float(ymax + ydiff))
    plt.xlim(float(vs - (ve - vs)), float(ve + (ve - vs)))
    
    #Ross function
    g = 1 - (1/2)*U

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
    plt.axvspan(vs, ve, color='gold', alpha=0.125)
    image_dir = 'diagrams/u/' + model.name
    os.makedirs(image_dir, exist_ok=True)
    image_name = image_dir + '/eq' + str(eq_no) + '-sing' + str(sing_no) + '.png'
    plt.savefig(image_name)
    print("\n*Singularity point: " + str(point) +"*")
    print("\n![point](" + image_name + ")")
    
    #plt.show()
    #assert False
    plt.close('all')
    
for file_name in ('old_davies_isap_2012.cellml',
                  'aslanidi_model_2009.cellml',
                  'beeler_reuter_model_1977.cellml',
                  'bondarenko_model_2004_apex.cellml',
                  'bondarenko_szigeti_bett_kim_rasmusson_2004_apical.cellml',
                  'courtemanche_ramirez_nattel_model_1998.cellml',
                  'decker_2009.cellml',
                  'demir_model_1994.cellml',
                  'difrancesco_noble_model_1985.cellml',
                  'dokos_model_1996.cellml',
                  'earm_noble_model_1990.cellml',
                  'espinosa_model_1998_normal.cellml',
                  'FaberRudy2000.cellml',
                  'fink_noble_giles_model_2008.cellml',
                  'grandi2010ss.cellml',
                  'hilgemann_noble_model_1987.cellml',
                  'hodgkin_huxley_squid_axon_model_1952_modified.cellml',
                  'hund_rudy_2004_a.cellml',
                  'iribe_model_2006_without_otherwise_section.cellml',
                  'iyer_model_2004.cellml',
                  'iyer_model_2007.cellml',
                  'jafri_rice_winslow_model_1998.cellml',
                  'kurata_model_2002.cellml',
                  'livshitz_rudy_2007.cellml',
                  'li_mouse_2010.cellml',
                  'luo_rudy_1994.cellml',
                  'mahajan_2008.cellml',
                  'matsuoka_model_2003.cellml',
                  'new_luo_rudy_1991_with_range.cellml',
                  'noble_model_1991.cellml',
                  'noble_model_1998.cellml',
                  'noble_noble_SAN_model_1984.cellml',
                  'noble_SAN_model_1989.cellml',
                  'nygren_atrial_model_1998.cellml',
                  'paci_hyttinen_aaltosetala_severi_ventricularVersion.cellml',
                  'pandit_model_2001_epi.cellml',
                  'priebe_beuckelmann_model_1998.cellml',
                  'sachse_moreno_abildskov_2008_b.cellml',
                  'sakmann_model_2000_epi.cellml',
                  'Shannon2004.cellml',
                  'stewart_zhang_model_2008_ss.cellml',
                  'ten_tusscher_model_2004_endo.cellml',
                  'ten_tusscher_model_2004_epi.cellml',
                  'ten_tusscher_model_2006_epi.cellml',
                  'viswanathan_model_1999_epi.cellml',
                  'winslow_model_1999.cellml',
                  'zhang_SAN_model_2000_0D_capable.cellml',
                  'zhang_SAN_model_2000_all.cellml',
                  ):
    model = load_model_with_conversions(os.path.join(DATA_DIR, 'tests', 'cellml', file_name), quiet=True)
    print("# Model: " + model.name)
    _process_singularities(model)
    
model = load_model_with_conversions(os.path.join(DATA_DIR, 'tests', 'cellml', 'courtemanche_ramirez_nattel_model_1998.cellml'), quiet=True)
model.derivative_equations = [model.derivative_equations[36]]
# _process_singularities(model)
# print(type(model.derivative_equations[-1].rhs))
# print(1)

model.derivative_equations = [Eq(model.derivative_equations[-1].lhs, model.derivative_equations[-1].rhs.args[1].args[0])]
# print(2)
_process_singularities(model)
