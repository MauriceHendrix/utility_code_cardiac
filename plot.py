## script to generate singularities images. requires chaste_codegen, it's cellml files, matplotlib and numpy

import os
from sympy import *
from sympy.codegen.rewriting import ReplaceOptim, expm1_opt, optimize
import matplotlib.pyplot as plt
import numpy as np
from chaste_codegen import (add_conversions, ChastePrinter, load_model_with_conversions, DATA_DIR)
from chaste_codegen._math_functions import MATH_FUNC_SYMPY_MAPPING
from chaste_codegen._partial_eval import partial_eval
from chaste_codegen.model_with_conversions import (get_equations_for, _get_modifiable_parameters)

offset = 1e-7

printer = ChastePrinter(lambda var: str(var).lstrip('_').replace('$', '__'),
                        lambda deriv: str(deriv).lstrip('_').replace('$', '__'))

                       
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

    def get_singularity_points(singularity_points):
        if singularity_points is EmptySet or isinstance(singularity_points, Intersection) or isinstance(singularity_points, ConditionSet) or isinstance(singularity_points, Complement):
            return None
        if isinstance(singularity_points, Union):
            # Pick out all fite sets in the argument as 1 finite set
            singularity_points = FiniteSet().union(*(filter(lambda s: isinstance(s, FiniteSet), singularity_points.args)))
        assert isinstance(singularity_points, FiniteSet), "Expecting singularity points to be contained in a  FiniteSet:\n" + str(singularity_points)
        # Pick out just the real answers
        return set(filter(lambda s: s.is_real, singularity_points))

    vardefs = [Eq(e, _get_initial_value(e)) for e in ((_get_modifiable_parameters(model) | model.state_vars ) - set([model.membrane_voltage_var]))]
    eq_no = 0
    for eq in model.derivative_equations:
        rhs = eq.rhs.subs(MATH_FUNC_SYMPY_MAPPING)
        singularity_points = singularities(rhs, model.membrane_voltage_var)
        singularity_points = get_singularity_points(singularity_points)
        if singularity_points:
            eq_no += 1
            print("## Equation "+ str(eq_no) + ":")
            print("```")
            print(printer.doprint(eq.lhs) + " = " + printer.doprint(rhs))
            print("```")
            print("### Partially evaluated to: ")
            partial_eval_eq = partial_eval(vardefs + model.derivative_equations + [eq], list(model.y_derivatives) + [eq.lhs], keep_multiple_usages=False)[-1]
            partial_eval_rhs = partial_eval_eq.rhs.subs(MATH_FUNC_SYMPY_MAPPING)
            print("```")
            print(printer.doprint(partial_eval_eq.lhs) + " = " + printer.doprint(partial_eval_rhs))
            print("```")
            (vs,ve, U) = get_U(partial_eval_rhs, model.membrane_voltage_var)
            print("### Singulariy points detected:")
            print(singularity_points)
            if vs is not None and ve is not None:
                for sing_no, point in enumerate(singularity_points):
                    draw_graph(partial_eval_rhs, point, model, eq_no, sing_no + 1, vs, ve, U)
            print()

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
    try:
        left_lim = limit(rhs, V, point, '-')
    except NotImplementedError:
        left_lim = "NotImplemented"
    try:
        right_lim = limit(rhs, V, point, '-')
    except NotImplementedError:
        right_lim = "NotImplemented "
    print("\n*Left limit:* " + str(left_lim) + (" == " if left_lim == right_lim else " != ") + "Right limit:* " + str(right_lim))
    print("\n*Has piecewise: * " + str(len(rhs.atoms(Piecewise)) > 0))
    print("\n![point](" + image_name + ")")
    
    #plt.show()
    #assert False
    plt.close('all')


def get_U(rhs, V):
    A=Wild('A', real=True)
    U=Wild('U', real=True)
    P=Wild('P', real=True)
    Q=Wild('Q', real=True)
    R=Wild('R', real=True)
    S=Wild('S', real=True)
    match = rhs.match(A / U)
    if match and U in match and A in match:
        find_U = match[U].match(P * exp(Q) - 1.0)
        if not find_U:
            find_U = match[U].expand().match(P * exp(Q) - 1.0)
        if find_U and P in find_U and Q in find_U:
            u = find_U[Q] + log(find_U[P])
            print("*U*")
            print("`" +printer.doprint(u)+"`")
            print()
            find_v_low = solveset(u + offset, V, domain=Reals)
            find_v_up = solveset(u - offset, V, domain=Reals)
            assert len(find_v_low) < 2
            assert len(find_v_up) < 2
            find_v_low = list(find_v_low)
            find_v_up = list(find_v_up)
            if find_v_low and find_v_up:
                top_match = match[A].match(R * u + S)
                if not top_match:
                    top_match = match[A].expand().match(R * u + S)
                if top_match:
                    print("*V for " + str(offset) + " range* ")
                    print("`" +printer.doprint(find_v_low[-1]) + " - "+ printer.doprint(find_v_up[-1]) +"`")
                else:
                    print("*V only found at bottom*")
                    print("`" +printer.doprint(find_v_low[-1]) + " - "+ printer.doprint(find_v_up[-1]) +"`")
                return (find_v_low[-1], find_v_up[-1], u)
    return get_U_plus(rhs, V)
    
def get_U_plus(rhs, V):
    A=Wild('A', real=True)
    U=Wild('U', real=True)
    P=Wild('P', real=True)
    Q=Wild('Q', real=True)
    R=Wild('R', real=True)
    S=Wild('S', real=True)
    match = rhs.match(A / U)
    if match and U in match and A in match:
        find_U = match[U].match(-P * exp(Q) + 1.0)
        if not find_U:
            find_U = match[U].expand().match(P * exp(Q) - 1.0)
        if find_U and P in find_U and Q in find_U:
            u = find_U[Q] + log(find_U[P])
            print("*U for -exp(U)+1* ")
            print("`" +printer.doprint(u)+"`")
            print()
            find_v_low = solveset(u + offset, V, domain=Reals)
            find_v_up = solveset(u - offset, V, domain=Reals)
            find_v_low = list(find_v_low)
            find_v_up = list(find_v_up)
            assert len(find_v_low) < 2
            assert len(find_v_up) < 2
            if find_v_low and find_v_up:
                top_match = match[A].match(R * u + S)
                if not top_match:
                    top_match = match[A].expand().match(R * u + S)
                if top_match:
                    print("*V for " + str(offset) + " range* ")
                    print("`" +printer.doprint(find_v_low[-1]) + " - "+ printer.doprint(find_v_up[-1]) +"`")
                else:
                    print("*V only found at bottom*")
                    print("`" +printer.doprint(find_v_low[-1]) + " - "+ printer.doprint(find_v_up[-1]) +"`")
                return (find_v_low[-1], find_v_up[-1], u)
    return (None, None, None)

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

