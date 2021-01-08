## script to generate singularities images. requires chaste_codegen, it's cellml files, matplotlib and numpy

# todo:
# table, piecewises, number of fixes for each model new vs old
# printer pow(1/x,(-1.0))
# We probably want to limit the search to -150 to +100mV ish

import os
import time

from math import isclose
import matplotlib.pyplot as plt
import numpy as np
from sympy import (
    Abs,
    Add,
    Float,
    I,
    log,
    Mul,
    Piecewise,
    Pow,
    solveset,
    Wild
)
from sympy.codegen.rewriting import ReplaceOptim, optimize

# Optimisations to be applied to equations
_V, _W = Wild('V'), Wild('W')
# For P^n make sure n is passed as int if it is actually a whole number
_POW_OPT = ReplaceOptim(lambda p: p.is_Pow and (isinstance(p.exp, Float) or isinstance(p.exp, float))
                        and float(p.exp).is_integer(),
                        lambda p: Pow(p.base, int(float(p.exp))))
                        

from chaste_codegen import (DATA_DIR, ChastePrinter,
                            load_model_with_conversions)
from chaste_codegen._math_functions import exp_, subs_math_func_placeholders
from chaste_codegen.model_with_conversions import (_get_modifiable_parameters,
                                                   get_equations_for)
printer = ChastePrinter(lambda var: str(var).lstrip('_').replace('$', '__'),
                        lambda deriv: str(deriv).lstrip('_').replace('$', '__'))

U_offset = 1e-7
exp_function = exp_
script_type = 'no_singularity_fixes'

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

def _get_U(expr, V, U_offset, exp_function):
    Z=Wild('Z', real=True)
    X=Wild('X', real=True, include=[V])
    Y=Wild('Y', real=True)
    
    print(expr)
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
                        try:
                            sp = tuple(filter(lambda s: not s.has(I), solveset(u, V)))
                            print(sp)
                            if sp:
                                find_v_low = solveset(u + U_offset, V)
                                find_v_up = solveset(u - U_offset, V)
                                find_v_low = tuple(find_v_low)
                                find_v_up = tuple(find_v_up)
                                if find_v_low and find_v_up:
                                    (vs, ve, U, sp) = (find_v_low[-1], find_v_up[-1], u, sp[-1])
                        except TypeError as e:
                            print(e)
                            pass # Result could be 'ConditionSet' which is not iterable

                    if vs is not None: #check top
                        for n in num:
                            match = n.match(Z * V - Z * Y)
                            found_on_top = match is not None and Z in match and Z != 0 and (sp == match[Y] or (isinstance(sp, Float) and isinstance(match[Y], Float) and isclose(match[Y], sp)))
                            if not found_on_top:
                                match = n.match(exp_function(Z * V - Z * Y))
                                found_on_top = match is not None and Z in match and Z != 0 and (sp == match[Y] or (isinstance(sp, Float) and isinstance(match[Y], Float) and isclose(match[Y], sp)))
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

def _generate_piecewise(vs, ve, sp, ex, V):
    """Generates a piecewsie for expression ex based on the singularity point sp and vmin (vs) and vmax (ve) """
    def f(Vx, e):
        return e.xreplace({V: Vx})

    if vs is None:
        return ex

    return Piecewise(*[(f(vs, ex) + ((V - vs) / (ve - vs)) * (f(ve, ex) - f(vs, ex)),
                        Abs(V - sp) < Abs((ve - vs) / 2)), (ex, True)])


def _get_new_expr_parts(expr, V, U_offset, exp_function):
    """Removes suitable singularities and replaces it with a piecewise, returning (vs, ve, sp, has_singularity)"""
    if not expr.has(exp_function):
        return (None, None, None, expr, False)

    if isinstance(expr, Mul):  # 1 * A --> A
        expr = Mul(*[a for a in expr.args if not a == 1.0])

    if isinstance(expr, Add):  # A+B
        new_expr_parts = []
        for a in expr.args:
            new_expr_parts.append(_get_new_expr_parts(a, V, U_offset, exp_function))

        # For multiple parts with the same singularity point pick the widest range
        range = [item for (vs, ve, _, _, _) in new_expr_parts for item in (vs, ve)]
        if len(new_expr_parts) > 1 and len(set([sp for (_, _, sp, _, _) in new_expr_parts])) == 1 \
                and all(isinstance(b, Float) for b in range):
            sp = new_expr_parts[0][2]
            vs, ve = min(range), max(range)
            new_expr = (vs, ve, sp, expr, True)
        else:
            expr_parts = []
            is_piecewise = False
            for vs, ve, sp, ex, has_piecewise in new_expr_parts:
                is_piecewise = is_piecewise or has_piecewise or vs is not None
                expr_parts.append(_generate_piecewise(vs, ve, sp, ex, V))
            new_expr = (None, None, None, Add(*expr_parts), is_piecewise)

    elif isinstance(expr, Pow) and expr.args[1] == -1.0 and len(expr.args) == 2:  # 1/A
        new_expr = _get_new_expr_parts(expr.args[0], V, U_offset, exp_function)
        vs, ve, sp, ex, has_piecewise = new_expr
        has_piecewise = has_piecewise or vs is not None
        new_expr = (None, None, None, 1.0 / _generate_piecewise(vs, ve, sp, ex, V), has_piecewise)

    elif isinstance(expr, Mul):
        (vs, ve, U, sp) = _get_U(expr, V, U_offset, exp_function)
        if vs is not None:
            new_expr = (vs, ve, sp, expr, True)
        else:
            expr_parts = []
            is_piecewise = False
            for sub_ex in expr.args:
                vs, ve, sp, ex, has_piecewise = _get_new_expr_parts(sub_ex, V, U_offset, exp_function)
                has_piecewise = is_piecewise = is_piecewise or has_piecewise or vs is not None
                expr_parts.append(_generate_piecewise(vs, ve, sp, ex, V))
            new_expr = (None, None, None, Mul(*expr_parts), is_piecewise)

    else:  # Different type of equation e.g a number
        return (None, None, None, expr, False)

    return new_expr

def get_new_expr(expr, V, U_offset=1e-7, exp_function=exp_):
    """Removes suitable singularities and replaces it with a piecewise.
    :param: expr the expression to analyse ().
    :param: V the volatge variable
    :param: U_offset determins the offset either side of U for which the fix is used (defaulr 1e-7)
    :return: expr with singularities fixes if appropriate
    """
    if not expr.has(exp_function):
        return False, expr
    (vs, ve, sp, ex, has_piecewise) = _get_new_expr_parts(expr, V, U_offset, exp_function)
    ex = _generate_piecewise(vs, ve, sp, ex, V)
    return has_piecewise or vs is not None, optimize(ex, (_POW_OPT,) )

def draw_graphs(eq_no, file_name, new_ex, original_eq, V, vardefs, vardefs_offset):
    draw_points=2000
    SP = Wild('SP', real=True)
    R = Wild('R', real=True)
    file_name = file_name.replace('.cellml', '')
    
    # subsitute in parameters in both euqations so we can draw them
    prev_ex = None
    while prev_ex != new_ex:
        prev_ex = new_ex
        newrex = new_ex.xreplace(vardefs)
        if newrex == 0:
            newrex = new_ex.xreplace(vardefs_offset)
        new_ex = newrex
    
    prev_ex = None
    while prev_ex != original_eq:
        prev_ex = original_eq
        newrex = original_eq.xreplace(vardefs)
        if newrex == 0:
            newrex = original_eq.xreplace(vardefs_offset)
        original_eq = newrex

    # subsitute in math functions (exp etc) for drawing
    new_ex=subs_math_func_placeholders(new_ex)
    original_eq=subs_math_func_placeholders(original_eq)
    
    Piecewises = new_ex.atoms(Piecewise)
    for pw_index, pw in enumerate(Piecewises):
        match = pw.args[0][1].match(Abs(V - SP) < R)
        if match and SP in match and R in match:
            sp = match[SP]
            vs = sp - match[R]
            ve = sp + match[R]
            print("## Singularity point: " +str(sp))
            fig = plt.figure()
            ax1 = fig.add_subplot(111)
            x, y, x2, y2 = [], [], [], []

            A = original_eq.xreplace({V:ve})
            B = original_eq.xreplace({V:vs})

            ymin = min(A, B)
            ymax = max(A, B)

            ydiff = ymax-ymin if ymax-ymin != 0 else ve - vs
            plt.xlim(float(vs - (ve - vs)), float(ve + (ve - vs)))
            plt.axvspan(vs, ve, color='gold', alpha=0.125)
            
            current_point = sp - (1.1 * (ve - vs))

            for _ in range(draw_points):
                try:
                    val = original_eq.subs({V: current_point})
                    if val.is_real:
                        x.append(current_point)
                        y.append(val)
                        if vs <= current_point <= ve:
                            x2.append(current_point)
                            y2.append(new_ex.subs({V: current_point}))
                except TypeError:
                    pass
                current_point+=(3 * (ve - vs))/draw_points
                
            plt.plot(x,y, color="silver")
            plt.plot(x2,y2, color="red")

            image_dir = 'diagrams/' + script_type + '/' + file_name
            os.makedirs(image_dir, exist_ok=True)
            image_name = image_dir + '/' + str(eq_no) + '_' + str(pw_index)+ '.png'
            print("![Singularity](%s)" % (image_name))
            print()

            plt.savefig(image_name)
            #plt.show()
            plt.close('all')

proc_times = []
for file_name in (#'aslanidi_atrial_model_2009.cellml',
                  # 'aslanidi_Purkinje_model_2009.cellml',
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
                  'paci_hyttinen_aaltosetala_severi_atrialVersion.cellml',
#                  'paci_hyttinen_aaltosetala_severi_ventricularVersion.cellml',
                  # 'pandit_clark_giles_demir_2001_endocardial_cell.cellml',
                  # 'pandit_clark_giles_demir_2001_epicardial_cell.cellml',
                  # 'pasek_simurda_christe_2006.cellml',
                  # 'pasek_simurda_orchard_christe_2008.cellml',
                  # 'priebe_beuckelmann_1998.cellml',
                  # 'ramirez_nattel_courtemanche_2000.cellml',
#                  'sachse_moreno_abildskov_2008_b.cellml',
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
    vardefs = {e: get_initial_value(e, model) for e in _get_modifiable_parameters(model) | (model.state_vars - set([model.membrane_voltage_var]))}
    vardefs_offset = {e: val + 1e-7  for e, val in vardefs.items()}
    
    toc = time.perf_counter()

    unprocessed_eqs = {}

    eq_no = 0
    num_sing = 0

    tic2 = time.perf_counter()
    for eq in model.derivative_equations:
        vardefs[eq.lhs] = eq.rhs
        vardefs_offset[eq.lhs] = eq.rhs
        if not isinstance(eq.rhs, Piecewise):
            unprocessed_eqs[eq.lhs] = eq.rhs.xreplace(unprocessed_eqs)
            
            changed, new_ex = get_new_expr(unprocessed_eqs[eq.lhs], model.membrane_voltage_var)
            if changed:
                eq_no+=1
                print("## Equation "+ str(eq_no) + ":")
                print("```")
                print(printer.doprint(eq.lhs) + " = " + printer.doprint(unprocessed_eqs[eq.lhs]))
                print("```")
                num_sing += len(new_ex.atoms(Piecewise))
                print("## New Eq:")
                print("```")
                print(printer.doprint(eq.lhs) + " = " + printer.doprint(new_ex))
                print("```")
#               draw_graphs(eq_no, file_name, new_ex, unprocessed_eqs[eq.lhs], model.membrane_voltage_var, vardefs, vardefs_offset)
                print()
                unprocessed_eqs.pop(eq.lhs)
    toc2 = time.perf_counter()
    proc_times.append(toc2-tic2)
    print('# of singularities: ', num_sing)
    print("singularity processing time: "+str(toc2-tic2))
print('average processing time:' + str(sum(proc_times) / len(proc_times)))

