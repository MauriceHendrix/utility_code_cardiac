## script to generate singularities images. requires chaste_codegen, it's cellml files, matplotlib and numpy

# todo:
# table, piecewises, number of fixes for each model new vs old
# printer pow(1/x,(-1.0))
# We probably want to limit the search to -150 to +100mV ish

import os
import time

import math
import matplotlib.pyplot as plt
import numpy as np
import sympy.core.numbers
from sympy import *

from chaste_codegen import (DATA_DIR, ChastePrinter,
                            load_model_with_conversions)
from chaste_codegen._math_functions import exp_, subs_math_func_placeholders, MATH_FUNC_SYMPY_MAPPING
from chaste_codegen.model_with_conversions import (_get_modifiable_parameters,
                                                   get_equations_for)
from cellmlmanip.model import Variable

from sympy.codegen.rewriting import ReplaceOptim, optimize

# Optimisations to be applied to equations
_V, _W = Wild('V'), Wild('W')
# For P^n make sure n is passed as int if it is actually a whole number
_POW_OPT = ReplaceOptim(lambda p: p.is_Pow and (isinstance(p.exp, Float) or isinstance(p.exp, float))
                        and float(p.exp).is_integer(),
                        lambda p: Pow(p.base, int(float(p.exp))))

U_offset = 1e-7
Sing_no = 0#

printer = ChastePrinter(lambda var: str(var).lstrip('_').replace('$', '__'),
                        lambda deriv: str(deriv).lstrip('_').replace('$', '__'))

def draw_graph(rhs, point, model, vs, ve, U, vardefs, vardefs_offset, deriv_eqs_dict, draw_points=2000):
    prev_rhs = None
    while prev_rhs != rhs:
        prev_rhs = rhs
        newrhs = rhs.xreplace(deriv_eqs_dict | vardefs)
        if newrhs == 0:
            rhs = rhs.xreplace(deriv_eqs_dict | vardefs_offset)
        else:
            rhs = newrhs

    prev_ve = None
    while prev_ve != ve:
        prev_ve = ve
        ve = ve.xreplace(deriv_eqs_dict | vardefs)
    prev_vs = None
    while prev_vs != vs:
        prev_vs = vs
        vs = vs.xreplace(deriv_eqs_dict | vardefs)

    if ve < vs:  # Swap to adjust the range from smaller to larger
        ve, vs = vs, ve

    V = model.membrane_voltage_var
    fig = plt.figure()
    ax1 = fig.add_subplot(111)
    x, y, y2 = [], [], []

    A = (ve, rhs.xreplace({V:ve}))
    B = (vs, rhs.xreplace({V:vs}))
   
    slope = (A[1]-B[1])/(ve - vs)
    
    #slope-pont
    f = slope*(V - A[0]) + A[1]
    ymin = min(A[1], B[1])
    ymax = max(A[1], B[1])

    ydiff = ymax-ymin if ymax-ymin != 0 else ve - vs
    plt.xlim(float(vs - (ve - vs)), float(ve + (ve - vs)))
    plt.axvspan(vs, ve, color='gold', alpha=0.125)

    current_point = point - (1.5 * (ve - vs))

    for _ in range(draw_points):
        try:
            val = rhs.subs({V: current_point})
            if val.is_real:
                x.append(current_point)
                y.append(val)
                y2.append(f.subs({V: current_point}))
        except TypeError:
            pass
        current_point+=(3 * (ve - vs))/draw_points
        
    plt.plot(x,y, color="silver")
    plt.plot(x,y2, color="red")
    image_dir = 'diagrams/' + model.name
    os.makedirs(image_dir, exist_ok=True)
    global Sing_no
    image_name = image_dir + '/' + str(Sing_no) + '.png'
    Sing_no += 1
    plt.savefig(image_name)
    print("\n*Singularity point: " + str(point) +"*")
    print("\n![point](" + image_name + ")")
    
    #plt.show()
    #assert False
    plt.close('all')
    
def get_U(expr, V):
    Z=Wild('Z', real=True)
    X=Wild('X', real=True, include=[V])
    Y=Wild('Y', real=True)
    
    def check_bottom_match(m):
        return m is not None and X in m and Z in m and Z != 0

    (vs, ve, U, sp) = None, None, None, None
    # the denominator is all args where a **-1

    numerator = set(a for a in expr.args if not isinstance(a, Pow) or a.args[1] != -1.0)
    denominator = set(a.args[0] for a in expr.args if isinstance(a, Pow) and a.args[1] == -1.0)
    
    if len(denominator) > 0 and len(numerator) > 0:
        # U might be on top, try numerator / denominator and denominator / numerator
        for denom, num in ((denominator, numerator), (numerator, denominator)):
            found_on_top = False
            for d in denom:
                if d.has(exp):
                    find_U = d.match(exp(X) * -Z + 1.0)
                    if not check_bottom_match(find_U):
                        find_U = d.match(exp(X) * Z - 1.0)
                    if check_bottom_match(find_U):
                        u = (find_U[X] + log(find_U[Z]))
                        sp = tuple(filter(lambda s: not s.has(I), solveset(u, V)))
                        if sp:
                            find_v_low = solveset(u + U_offset, V)
                            find_v_up = solveset(u - U_offset, V)
                            find_v_low = tuple(find_v_low)
                            find_v_up = tuple(find_v_up)
                            if find_v_low and find_v_up:
                                (vs, ve, U, sp) = (find_v_low[-1], find_v_up[-1], u, sp[-1])
                    if vs is not None: #check top
                        for n in num:
                            match = n.match(Z * V - Z * Y)
                            found_on_top = match is not None and Z in match and Z != 0 and (sp == match[Y] or (isinstance(sp, Float) and isinstance(match[Y], Float) and math.isclose(match[Y], sp)))
                            if not found_on_top:
                                match = n.match(exp(Z * V - Z * Y))
                                found_on_top = match is not None and Z in match and Z != 0 and (sp == match[Y] or (isinstance(sp, Float) and isinstance(match[Y], Float) and math.isclose(match[Y], sp)))
                                if not found_on_top:
                                    match = n.match(Z * V - Z * sp)
                                    found_on_top = match is not None and Z in match and Z != 0
                                    if not found_on_top:
                                        match = n.match(exp(Z * V - Z * sp))
                                        found_on_top = match is not None and Z in match and Z != 0
                            if found_on_top:
                                break
                        break
            if vs is not None and found_on_top: #found U, no need to try further
                break
            else:
                (vs, ve, U, sp) = None, None, None, None
    return (vs, ve, U, sp)

# def get_new_expr_parts(expr, expr_part_eval, V):
    # def f(Vx):
# #        return expr_part_eval.xreplace({V:Vx})
        # return expr.xreplace({V:Vx})

    # singularity_piecewise_parts = []
    # if expr_part_eval.has(exp):
        # if isinstance(expr_part_eval, Add): # A+B
            # for a in expr_part_eval.args:
                # if a.has(exp):
                    # singularity_piecewise_parts.extend(get_new_expr_parts(expr, a, V))
        # elif isinstance(expr_part_eval, Pow) and expr_part_eval.args[1] == -1.0 and len(expr_part_eval.args) == 2:  # 1/A
            # singularity_piecewise_parts = get_new_expr_parts(expr, expr_part_eval.args[0], V)
        # elif isinstance(expr_part_eval, Mul): #and len(expr_part_eval.atoms(exp)) > 0:
            # (vs, ve, U, sp) = get_U(expr_part_eval, V)
            # if vs is not None:
               # print('*U2*: ' + printer.doprint(U))
               # print("*V for " + str(U_offset) + " range* ")
               # print("`" +printer.doprint(vs) + " - "+ printer.doprint(ve) +"`")
               # print('singularity point: ' + str(sp))
               # #(rhs, model, vardefs, vardefs_offset, deriv_eqs_dict) = draw_graph_params
               # #draw_graph(rhs, sp, model, vs, ve, U, vardefs, vardefs_offset, deriv_eqs_dict)
               # singularity_piecewise_parts = [(f(vs) + ((V - vs) / (ve - vs)) * (f(ve) - f(vs)), Abs(V-sp) < Abs((ve-vs)/2))]
            # else:
                # for a in expr_part_eval.args:
                    # if a.has(exp):
                        # singularity_piecewise_parts.extend(get_new_expr_parts(expr, a, V))
    # return singularity_piecewise_parts

def get_new_expr_parts_sp(expr, expr_part_eval, V):
    def f(Vx):
        return expr.xreplace({V:Vx})

    singularity_piecewise_parts = []
    singularity_points = []
    if expr_part_eval.has(exp):
        if isinstance(expr_part_eval, Add): # A+B
            for a in expr_part_eval.args:
                if a.has(exp):
                    point, part = get_new_expr_parts_sp(expr, a, V)
                    singularity_points.extend(point)
                    singularity_piecewise_parts.extend(part)

            range = [item for (vs, ve, _) in singularity_points for item in (vs, ve, _, _)]
            if len(singularity_points) > 1 and len(set([sp for (_, _, sp) in singularity_points])) == 1 and all(isinstance(b, Float) for b in range): # if thre are multiple parts and they have the same singularity points
                sp = singularity_points[0][2]
                vs, ve = min(range), max(range)
                singularity_piecewise_parts = [(f(vs) + ((V - vs) / (ve - vs)) * (f(ve) - f(vs)), Abs(V-sp) < Abs((ve-vs)/2))]
                singularity_points = [(vs, ve, sp)]
                print()
                print('`Two part eq with same singularity. range used: '+ printer.doprint(vs) +' - ' + printer.doprint(ve)  +'`')

        elif isinstance(expr_part_eval, Pow) and expr_part_eval.args[1] == -1.0 and len(expr_part_eval.args) == 2:  # 1/A
            point, part = get_new_expr_parts_sp(expr, expr_part_eval.args[0], V)
            singularity_points.extend(point)
            singularity_piecewise_parts.extend(part)

        elif isinstance(expr_part_eval, Mul): #and len(expr_part_eval.atoms(exp)) > 0:
            (vs, ve, U, sp) = get_U(expr_part_eval, V)
            if vs is not None:
                print('*U2*: ' + printer.doprint(U))
                print("*V for " + str(U_offset) + " range* ")
                print("`" +printer.doprint(vs) + " - "+ printer.doprint(ve) +"`")
                print('singularity point: ' + str(sp))
                singularity_piecewise_parts = [(f(vs) + ((V - vs) / (ve - vs)) * (f(ve) - f(vs)), Abs(V-sp) < Abs((ve-vs)/2))]
                singularity_points = [(vs, ve, sp)]
            else:
                for a in expr_part_eval.args:
                    if a.has(exp):
                        point, part = get_new_expr_parts_sp(expr, a, V)
                        singularity_points.extend(point)
                        singularity_piecewise_parts.extend(part)
    return singularity_points, singularity_piecewise_parts

proc_times = []
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
    model = load_model_with_conversions(os.path.join(DATA_DIR, '..', '..', '..', 'cellml', 'cellml', file_name), quiet=True)
    
    print("# Model: " + model.name + '('+file_name+')')
    print("No of piecewises: " + str(sum([len(eq.rhs.atoms(Piecewise)) for eq in model.equations])) )
    #print("Piecewises: " + str([printer.doprint(eq.lhs) for eq in model.derivative_equations if isinstance(eq.rhs, Piecewise)]) )
    toc = time.perf_counter()

    unprocessed_eqs = {}

    eq_no = 0
    num_sing = 0

    tic2 = time.perf_counter()
    for eq in model.derivative_equations:
        if not isinstance(eq.rhs, Piecewise):
            rhs = subs_math_func_placeholders(eq.rhs)
            unprocessed_eqs[eq.lhs] = optimize(rhs.xreplace(unprocessed_eqs), (_POW_OPT,) )

#            singularity_piecewise_parts = get_new_expr_parts(unprocessed_eqs[eq.lhs], unprocessed_eqs[eq.lhs], model.membrane_voltage_var)
            points, singularity_piecewise_parts = get_new_expr_parts_sp(unprocessed_eqs[eq.lhs], unprocessed_eqs[eq.lhs], model.membrane_voltage_var)

            if len(singularity_piecewise_parts) > 0:
                eq_no+=1
                print("## Equation "+ str(eq_no) + ":")
                print("```")
                print(printer.doprint(eq.lhs) + " = " + printer.doprint(eq.rhs))
                print("```")
                print("### Partially evaluated to: ")
                print("```")
                print(printer.doprint(eq.lhs) + " = " + printer.doprint(unprocessed_eqs[eq.lhs]))
                print("```")
                num_sing += len(singularity_piecewise_parts)
                singularity_piecewise_parts.append((eq.rhs, True))
                new_expr = Piecewise(*singularity_piecewise_parts)
                unprocessed_eqs.pop(eq.lhs)
                print("## New Eq:")
                print("```")
                print(printer.doprint(eq.lhs) + " = " + printer.doprint(new_expr))
                print("```")
                print()

    toc2 = time.perf_counter()
    proc_times.append(toc2-tic2)
    print('# of singularities: ', num_sing)
    print("singularity processing time: "+str(toc2-tic2))
print('average processing time:' + str(sum(proc_times) / len(proc_times)))
