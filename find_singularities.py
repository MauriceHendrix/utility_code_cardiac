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
from chaste_codegen._math_functions import exp_
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

exp_function = exp_

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
                if d.has(exp_function):
                    find_U = d.match(exp_function(X) * -Z + 1.0)
                    if not check_bottom_match(find_U):
                        find_U = d.match(exp_function(X) * Z - 1.0)
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
                                match = n.match(exp_function(Z * V - Z * Y))
                                found_on_top = match is not None and Z in match and Z != 0 and (sp == match[Y] or (isinstance(sp, Float) and isinstance(match[Y], Float) and math.isclose(match[Y], sp)))
                                if not found_on_top:
                                    match = n.match(Z * V - Z * sp)
                                    found_on_top = match is not None and Z in match and Z != 0
                                    if not found_on_top:
                                        match = n.match(exp_function(Z * V - Z * sp))
                                        found_on_top = match is not None and Z in match and Z != 0
                            if found_on_top:
                                break
                        break
            if vs is not None and found_on_top: #found U, no need to try further
                break
            else:
                (vs, ve, U, sp) = None, None, None, None
    return (vs, ve, U, sp)

def get_new_expr_parts(expr, V):
    def f(Vx, e):
        return e.xreplace({V:Vx})

    if not expr.has(exp_function):
        return [(None, None, None, expr, False)]
    singularity_points = []##name singularity points?
    
    if isinstance(expr, Mul): # 1 * A --> A
        expr = Mul(*[a for a in expr.args if not a==1.0])

    if isinstance(expr, Add): # A+B
        for a in expr.args:
            singularity_points.extend(get_new_expr_parts(a, V))

        range = [item for (vs, ve, _, _, _) in singularity_points for item in (vs, ve)]
        if len(singularity_points) > 1 and len(set([sp for (_, _, sp, _, _) in singularity_points])) == 1 and all(isinstance(b, Float) for b in range): # if thre are multiple parts and they have the same singularity points
            sp = singularity_points[0][2]
            vs, ve = min(range), max(range)
            singularity_points = [(vs, ve, sp, expr, True)]

        expr_parts = []
        is_piecewise = False
        for vs, ve, sp, ex, has_piecewise in singularity_points:
            if vs is None:
                is_piecewise = is_piecewise or has_piecewise
                expr_parts.append(ex)
            else: # generate piecewise
                is_piecewise = True
                piecewise = Piecewise(*[(f(vs, ex) + ((V - vs) / (ve - vs)) * (f(ve, ex) - f(vs, ex)), Abs(V-sp) < Abs((ve-vs)/2)), (ex, True)])
                expr_parts.append(piecewise)
        singularity_points = [(None, None, None, Add(*expr_parts), is_piecewise)]

    elif isinstance(expr, Pow) and expr.args[1] == -1.0 and len(expr.args) == 2:  # 1/A
        #print('1/A')
        singularity_points = get_new_expr_parts(expr.args[0], V)
        assert len(singularity_points) == 1
        vs, ve, sp, ex, has_piecewise = singularity_points[0]
        assert vs is None
        singularity_points = [(None, None, None, 1.0/ex, has_piecewise)]

                
    elif isinstance(expr, Mul):
        (vs, ve, U, sp) = get_U(expr, V)
        if vs is not None:
            singularity_points = [(vs, ve, sp, expr, True)]
        else:
            expr_parts = []
            is_piecewise = False
            for sub_ex in expr.args:
                for vs, ve, sp, ex, has_piecewise in get_new_expr_parts(sub_ex, V):
                    if vs is None:
                        is_piecewise = is_piecewise or has_piecewise
                        expr_parts.append(ex)
                    else: # generate piecewise
                        is_piecewise = True
                        piecewise = Piecewise(*[(f(vs, ex) + ((V - vs) / (ve - vs)) * (f(ve, ex) - f(vs, ex)), Abs(V-sp) < Abs((ve-vs)/2)), (ex, True)])
                        expr_parts.append(piecewise)
            singularity_points = [(None, None, None, Mul(*expr_parts), is_piecewise)]
    else:
        return [(None, None, None, expr, False)]


    return singularity_points

def get_new_expr(expr, V):
    def f(Vx, ex):
        return ex.xreplace({V:Vx})

    if not expr.has(exp_function):
        return False, expr
    expr_parts = []
    singularity_points = get_new_expr_parts(expr, V)
    assert len(singularity_points) == 1
    (vs, ve, sp, ex, has_piecewise) = singularity_points[0]
    if vs is not None: # create piecewise
        has_piecewise = True
        ex = Piecewise(*[(f(vs, ex) + ((V - vs) / (ve - vs)) * (f(ve, ex) - f(vs, ex)), Abs(V-sp) < Abs((ve-vs)/2)), (ex, True)])
    return has_piecewise, ex

proc_times = []
for file_name in (#'aslanidi_atrial_model_2009.cellml',
                  'aslanidi_Purkinje_model_2009.cellml',
                  # 'beeler_reuter_model_1977.cellml',
                  # 'benson_epicardial_2008.cellml',
                  # 'bernus_wilders_zemlin_verschelde_panfilov_2002.cellml',
                  # 'bondarenko_szigeti_bett_kim_rasmusson_2004_apical.cellml',
                  # 'bondarenko_szigeti_bett_kim_rasmusson_2004_septal.cellml',
                  # 'bueno_2007_endo.cellml',
                  # 'bueno_2007_epi.cellml',
                  # 'carro_2011_endo.cellml',
                  # 'carro_2011_epi.cellml',
                  # 'clancy_rudy_2002.cellml',
                  # 'corrias_purkinje_2011.cellml',
                  # 'courtemanche_ramirez_nattel_1998.cellml',
                  # 'davies_isap_2012.cellml',
                  # 'decker_2009.cellml',
                  # 'demir_model_1994.cellml',
                  # 'difrancesco_noble_model_1985.cellml',
                  # 'dokos_model_1996.cellml',
                  # 'earm_noble_model_1990.cellml',
                  # 'espinosa_model_1998_normal.cellml',
                  # 'faber_rudy_2000.cellml',
                  # 'fink_noble_giles_model_2008.cellml',
                  # 'fox_mcharg_gilmour_2002.cellml',
                  # 'grandi_pasqualini_bers_2010_ss.cellml',
                  # 'grandi_pasqualini_bers_2010_ss_endo.cellml',
                  # 'hilgemann_noble_model_1987.cellml',
                  # 'hodgkin_huxley_squid_axon_model_1952_modified.cellml',
                  # 'hund_rudy_2004.cellml',
                  # 'iribe_model_2006.cellml',
                  # 'iyer_2004.cellml',
                  # 'iyer_model_2007.cellml',
                  # 'jafri_rice_winslow_model_1998.cellml',
                  # 'kurata_model_2002.cellml',
                  # 'lindblad_model_1996.cellml',
                  # 'livshitz_rudy_2007.cellml',
                  # 'li_mouse_2010.cellml',
                  # 'luo_rudy_1991.cellml',
                  # 'luo_rudy_1994.cellml',
                  # 'mahajan_shiferaw_2008.cellml',
                  # 'maleckar_model_2009.cellml',
                  # 'maltsev_2009.cellml',
                  # 'matsuoka_model_2003.cellml',
                  # 'mcallister_noble_tsien_1975_b.cellml',
                  # 'noble_model_1962.cellml',
                  # 'noble_model_1991.cellml',
                  # 'noble_model_1998.cellml',
                  # 'noble_model_2001.cellml',
                  # 'noble_noble_SAN_model_1984.cellml',
                  # 'noble_SAN_model_1989.cellml',
                  # 'nygren_atrial_model_1998.cellml',
                  # 'ohara_rudy_2011_endo.cellml',
                  # 'ohara_rudy_2011_epi.cellml',
                  # 'ohara_rudy_cipa_v1_2017.cellml',
                  # 'paci_hyttinen_aaltosetala_severi_atrialVersion.cellml',
                  # 'paci_hyttinen_aaltosetala_severi_ventricularVersion.cellml',
                  # 'pandit_clark_giles_demir_2001_endocardial_cell.cellml',
                  # 'pandit_clark_giles_demir_2001_epicardial_cell.cellml',
                  # 'pasek_simurda_christe_2006.cellml',
                  # 'pasek_simurda_orchard_christe_2008.cellml',
                  # 'priebe_beuckelmann_1998.cellml',
                  # 'ramirez_nattel_courtemanche_2000.cellml',
                  # 'sachse_moreno_abildskov_2008_b.cellml',
                  # 'sakmann_model_2000_epi.cellml',
                  # 'shannon_wang_puglisi_weber_bers_2004.cellml',
                  # 'stewart_zhang_model_2008_ss.cellml',
                  # 'ten_tusscher_model_2004_endo.cellml',
                  # 'ten_tusscher_model_2004_epi.cellml',
                  # 'ten_tusscher_model_2004_M.cellml',
                  # 'ten_tusscher_model_2006_endo.cellml',
                  # 'ten_tusscher_model_2006_epi.cellml',
                  # 'ten_tusscher_model_2006_M.cellml',
                  # 'ToRORd_fkatp_endo.cellml',
                  # 'ToRORd_fkatp_epi.cellml',
                  # 'Trovato2020.cellml',
                  # 'viswanathan_model_1999_epi.cellml',
                  # 'wang_sobie_2008.cellml',
                  # 'winslow_model_1999.cellml',
                  # 'zhang_SAN_model_2000_0D_capable.cellml'
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
            unprocessed_eqs[eq.lhs] = optimize(eq.rhs.xreplace(unprocessed_eqs), (_POW_OPT,) )
            changed, alt_new = get_new_expr(unprocessed_eqs[eq.lhs], model.membrane_voltage_var)
            if changed:
                eq_no+=1
                print("## Equation "+ str(eq_no) + ":")
                print("```")
                print(printer.doprint(eq.lhs) + " = " + printer.doprint(unprocessed_eqs[eq.lhs]))
                print("```")
                num_sing += len(alt_new.atoms(Piecewise))
                unprocessed_eqs.pop(eq.lhs)
                print("## New Eq:")
                print("```")
                print(printer.doprint(eq.lhs) + " = " + printer.doprint(alt_new))
                print("```")
                print()
    toc2 = time.perf_counter()
    proc_times.append(toc2-tic2)
    print('# of singularities: ', num_sing)
    print("singularity processing time: "+str(toc2-tic2))
print('average processing time:' + str(sum(proc_times) / len(proc_times)))
