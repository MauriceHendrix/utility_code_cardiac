## script to generate singularities images. requires chaste_codegen, it's cellml files, matplotlib and numpy

import os
from sympy import *
import matplotlib.pyplot as plt
import numpy as np
from chaste_codegen import (add_conversions, ChastePrinter, load_model_with_conversions, DATA_DIR)
from chaste_codegen._math_functions import MATH_FUNC_SYMPY_MAPPING
from chaste_codegen._partial_eval import partial_eval
from chaste_codegen.model_with_conversions import (get_equations_for, _get_modifiable_parameters)

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
        #if singularity_points is not EmptySet and not isinstance(singularity_points, FiniteSet) and not isinstance(singularity_points, ConditionSet) and not isinstance(singularity_points, Union) and not isinstance(singularity_points, Intersection):
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
            print("### Singulariy points detected:")
            print(singularity_points)
            for sing_no, point in enumerate(singularity_points):
                draw_graph(partial_eval_rhs, point, model, eq_no, sing_no + 1)
            print()

def draw_graph(rhs, point, model, eq_no, sing_no, area_width=1e-7, draw_points=20000):
    V = model.membrane_voltage_var
    
    fig = plt.figure()
    ax1 = fig.add_subplot(111)
    #ax1.margins(x=0, y=0)
    x,y, x2, y2 = [], [], [], []

    vs = point - area_width
    ve = point + area_width
    A = (ve, rhs.subs({V:ve}))
    B = (vs, rhs.subs({V:vs}))
    slope = (A[1]-B[1])/(2 * area_width)
    
    #slope-pont
    f = slope*(V - A[0]) + A[1]
    ymin = min(A[1], B[1])
    ymax = max(A[1], B[1])
    diff = ymax-ymin if ymax-ymin != 0 else 1e-7
    plt.ylim(float(ymin - diff), float(ymax + diff))

    current_point = point - (1.5 * area_width)
    for _ in range(draw_points):
        val = rhs.subs({V: current_point})
        if val.is_real:
            x.append(current_point)
            x2.append(current_point)
            y.append(val)
            y2.append(f.subs({V: current_point}))
        current_point+=(3 * area_width)/draw_points

    plt.plot(x,y, color="silver")
    plt.plot(x2,y2, color="red")
    plt.axvspan(vs, ve, color='gold', alpha=0.125)
    image_dir = 'diagrams/' + model.name
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
        right_lim = "NotImplemented"
    print("\n*Left limit:* " + str(left_lim) + " == " if left_lim == right_lim else " != " + "Right limit:* " + str(right_lim))
    print("\n![point](" + image_name + ")")
    plt.close('all')
    #plt.show()


for file_name in (#'aslanidi_model_2009.cellml',
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
                  'mahajan_2008.cellml',
                  'matsuoka_model_2003.cellml',
                  'new_luo_rudy_1991_with_range.cellml',
                  'noble_model_1991.cellml',
                  'noble_model_1998.cellml',
                  'noble_noble_SAN_model_1984.cellml',
                  'noble_SAN_model_1989.cellml',
                  'nygren_atrial_model_1998.cellml',
                  ##'old_davies_isap_2012.cellml',
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