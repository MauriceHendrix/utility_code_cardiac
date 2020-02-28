#simple test to see performance of different substitution methods for sympy

from sympy import Symbol, Function, Eq, log, exp
import time

def partial_eval(equations, required_lhs, callable):
    evaluated_eqs = []
    # subs in all constants and expressions only used once
    subs_dict = {}
    for eq in equations:
        new_eq = callable(eq, subs_dict)
        if new_eq.lhs not in required_lhs:
            subs_dict[new_eq.lhs] = new_eq.rhs
        else:
            evaluated_eqs.append(new_eq)
    return evaluated_eqs

var_chaste_interface__environment__time = Symbol('var_chaste_interface__environment__time', real=True)
HeartConfig__Instance__GetCapacitance = Symbol('HeartConfig__Instance__GetCapacitance', real=True)
var_chaste_interface__membrane__V = Symbol('var_chaste_interface__membrane__V', real=True)
var_chaste_interface__calcium_concentration__Cai = Symbol('var_chaste_interface__calcium_concentration__Cai', real=True)
var_chaste_interface__calcium_concentration__Cass = Symbol('var_chaste_interface__calcium_concentration__Cass', real=True)
var_chaste_interface__calcium_concentration__CaJSR = Symbol('var_chaste_interface__calcium_concentration__CaJSR', real=True)
var_chaste_interface__calcium_concentration__CaNSR = Symbol('var_chaste_interface__calcium_concentration__CaNSR', real=True)
var_chaste_interface__calcium_fluxes__P_RyR = Symbol('var_chaste_interface__calcium_fluxes__P_RyR', real=True)
var_chaste_interface__calcium_buffering__LTRPN_Ca = Symbol('var_chaste_interface__calcium_buffering__LTRPN_Ca', real=True)
var_chaste_interface__calcium_buffering__HTRPN_Ca = Symbol('var_chaste_interface__calcium_buffering__HTRPN_Ca', real=True)
var_chaste_interface__ryanodine_receptors__P_O1 = Symbol('var_chaste_interface__ryanodine_receptors__P_O1', real=True)
var_chaste_interface__ryanodine_receptors__P_O2 = Symbol('var_chaste_interface__ryanodine_receptors__P_O2', real=True)
var_chaste_interface__ryanodine_receptors__P_C2 = Symbol('var_chaste_interface__ryanodine_receptors__P_C2', real=True)
var_chaste_interface__L_type_calcium_current__O = Symbol('var_chaste_interface__L_type_calcium_current__O', real=True)
var_chaste_interface__L_type_calcium_current__C2 = Symbol('var_chaste_interface__L_type_calcium_current__C2', real=True)
var_chaste_interface__L_type_calcium_current__C3 = Symbol('var_chaste_interface__L_type_calcium_current__C3', real=True)
var_chaste_interface__L_type_calcium_current__C4 = Symbol('var_chaste_interface__L_type_calcium_current__C4', real=True)
var_chaste_interface__L_type_calcium_current__I1 = Symbol('var_chaste_interface__L_type_calcium_current__I1', real=True)
var_chaste_interface__L_type_calcium_current__I2 = Symbol('var_chaste_interface__L_type_calcium_current__I2', real=True)
var_chaste_interface__L_type_calcium_current__I3 = Symbol('var_chaste_interface__L_type_calcium_current__I3', real=True)
var_chaste_interface__sodium_concentration__Nai = Symbol('var_chaste_interface__sodium_concentration__Nai', real=True)
var_chaste_interface__fast_sodium_current__O_Na = Symbol('var_chaste_interface__fast_sodium_current__O_Na', real=True)
var_chaste_interface__fast_sodium_current__C_Na1 = Symbol('var_chaste_interface__fast_sodium_current__C_Na1', real=True)
var_chaste_interface__fast_sodium_current__C_Na2 = Symbol('var_chaste_interface__fast_sodium_current__C_Na2', real=True)
var_chaste_interface__fast_sodium_current__I1_Na = Symbol('var_chaste_interface__fast_sodium_current__I1_Na', real=True)
var_chaste_interface__fast_sodium_current__I2_Na = Symbol('var_chaste_interface__fast_sodium_current__I2_Na', real=True)
var_chaste_interface__fast_sodium_current__IF_Na = Symbol('var_chaste_interface__fast_sodium_current__IF_Na', real=True)
var_chaste_interface__fast_sodium_current__IC_Na2 = Symbol('var_chaste_interface__fast_sodium_current__IC_Na2', real=True)
var_chaste_interface__fast_sodium_current__IC_Na3 = Symbol('var_chaste_interface__fast_sodium_current__IC_Na3', real=True)
var_chaste_interface__potassium_concentration__Ki = Symbol('var_chaste_interface__potassium_concentration__Ki', real=True)
var_chaste_interface__fast_transient_outward_potassium_current__ato_f = Symbol('var_chaste_interface__fast_transient_outward_potassium_current__ato_f', real=True)
var_chaste_interface__fast_transient_outward_potassium_current__ito_f = Symbol('var_chaste_interface__fast_transient_outward_potassium_current__ito_f', real=True)
var_chaste_interface__slow_transient_outward_potassium_current__ato_s = Symbol('var_chaste_interface__slow_transient_outward_potassium_current__ato_s', real=True)
var_chaste_interface__slow_transient_outward_potassium_current__ito_s = Symbol('var_chaste_interface__slow_transient_outward_potassium_current__ito_s', real=True)
var_chaste_interface__slow_delayed_rectifier_potassium_current__nKs = Symbol('var_chaste_interface__slow_delayed_rectifier_potassium_current__nKs', real=True)
var_chaste_interface__ultra_rapidly_activating_delayed_rectifier_potassium_current__aur = Symbol('var_chaste_interface__ultra_rapidly_activating_delayed_rectifier_potassium_current__aur', real=True)
var_chaste_interface__ultra_rapidly_activating_delayed_rectifier_potassium_current__iur = Symbol('var_chaste_interface__ultra_rapidly_activating_delayed_rectifier_potassium_current__iur', real=True)
var_chaste_interface__non_inactivating_steady_state_potassium_current__aKss = Symbol('var_chaste_interface__non_inactivating_steady_state_potassium_current__aKss', real=True)
var_chaste_interface__non_inactivating_steady_state_potassium_current__iKss = Symbol('var_chaste_interface__non_inactivating_steady_state_potassium_current__iKss', real=True)
var_chaste_interface__rapid_delayed_rectifier_potassium_current__O_K = Symbol('var_chaste_interface__rapid_delayed_rectifier_potassium_current__O_K', real=True)
var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K1 = Symbol('var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K1', real=True)
var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K2 = Symbol('var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K2', real=True)
var_chaste_interface__rapid_delayed_rectifier_potassium_current__I_K = Symbol('var_chaste_interface__rapid_delayed_rectifier_potassium_current__I_K', real=True)

d_dt_chaste_interface_var_non_inactivating_steady_state_potassium_current__iKss = Symbol('d_dt_chaste_interface_var_non_inactivating_steady_state_potassium_current__iKss', real=True)
var_L_type_calcium_current__E_CaL = Symbol('var_L_type_calcium_current__E_CaL', real=True)
var_L_type_calcium_current__Kpc_half = Symbol('var_L_type_calcium_current__Kpc_half', real=True)
var_L_type_calcium_current__Kpc_max = Symbol('var_L_type_calcium_current__Kpc_max', real=True)
var_L_type_calcium_current__Kpcb = Symbol('var_L_type_calcium_current__Kpcb', real=True)
var_L_type_calcium_current__C1 = Symbol('var_L_type_calcium_current__C1', real=True)
var_L_type_calcium_current__g_CaL = Symbol('var_L_type_calcium_current__g_CaL', real=True)
var_L_type_calcium_current__i_CaL_max = Symbol('var_L_type_calcium_current__i_CaL_max', real=True)
var_calcium_background_current__g_Cab = Symbol('var_calcium_background_current__g_Cab', real=True)
var_calcium_buffering__HTRPN_tot = Symbol('var_calcium_buffering__HTRPN_tot', real=True)
var_calcium_buffering__LTRPN_tot = Symbol('var_calcium_buffering__LTRPN_tot', real=True)
var_calcium_concentration__CMDN_tot = Symbol('var_calcium_concentration__CMDN_tot', real=True)
var_calcium_concentration__CSQN_tot = Symbol('var_calcium_concentration__CSQN_tot', real=True)
var_L_type_calcium_current__gamma = Symbol('var_L_type_calcium_current__gamma', real=True)
var_calcium_concentration__Km_CMDN = Symbol('var_calcium_concentration__Km_CMDN', real=True)
var_calcium_concentration__Bi = Symbol('var_calcium_concentration__Bi', real=True)
var_calcium_concentration__Bss = Symbol('var_calcium_concentration__Bss', real=True)
var_calcium_concentration__Km_CSQN = Symbol('var_calcium_concentration__Km_CSQN', real=True)
var_calcium_concentration__BJSR = Symbol('var_calcium_concentration__BJSR', real=True)
var_calcium_fluxes__Km_up = Symbol('var_calcium_fluxes__Km_up', real=True)
var_calcium_fluxes__k_minus_htrpn = Symbol('var_calcium_fluxes__k_minus_htrpn', real=True)
var_calcium_fluxes__k_minus_ltrpn = Symbol('var_calcium_fluxes__k_minus_ltrpn', real=True)
var_calcium_fluxes__k_plus_htrpn = Symbol('var_calcium_fluxes__k_plus_htrpn', real=True)
d_dt_chaste_interface_var_calcium_buffering__HTRPN_Ca = Symbol('d_dt_chaste_interface_var_calcium_buffering__HTRPN_Ca', real=True)
var_calcium_fluxes__k_plus_ltrpn = Symbol('var_calcium_fluxes__k_plus_ltrpn', real=True)
d_dt_chaste_interface_var_calcium_buffering__LTRPN_Ca = Symbol('d_dt_chaste_interface_var_calcium_buffering__LTRPN_Ca', real=True)
var_calcium_fluxes__J_trpn = Symbol('var_calcium_fluxes__J_trpn', real=True)
var_calcium_fluxes__tau_tr = Symbol('var_calcium_fluxes__tau_tr', real=True)
var_calcium_fluxes__J_tr = Symbol('var_calcium_fluxes__J_tr', real=True)
var_calcium_fluxes__tau_xfer = Symbol('var_calcium_fluxes__tau_xfer', real=True)
var_calcium_fluxes__J_xfer = Symbol('var_calcium_fluxes__J_xfer', real=True)
var_calcium_fluxes__v1 = Symbol('var_calcium_fluxes__v1', real=True)
var_calcium_fluxes__v2 = Symbol('var_calcium_fluxes__v2', real=True)
var_calcium_fluxes__J_leak = Symbol('var_calcium_fluxes__J_leak', real=True)
var_calcium_fluxes__v3 = Symbol('var_calcium_fluxes__v3', real=True)
var_calcium_fluxes__J_up = Symbol('var_calcium_fluxes__J_up', real=True)
var_calcium_pump_current__Km_pCa = Symbol('var_calcium_pump_current__Km_pCa', real=True)
var_calcium_pump_current__i_pCa_max = Symbol('var_calcium_pump_current__i_pCa_max', real=True)
var_calcium_pump_current__i_pCa = Symbol('var_calcium_pump_current__i_pCa', real=True)
var_fast_sodium_current__C_Na3 = Symbol('var_fast_sodium_current__C_Na3', real=True)
var_fast_sodium_current__g_Na = Symbol('var_fast_sodium_current__g_Na', real=True)
var_fast_transient_outward_potassium_current__g_Kto_f = Symbol('var_fast_transient_outward_potassium_current__g_Kto_f', real=True)
var_membrane__Acap = Symbol('var_membrane__Acap', real=True)
var_membrane__Cao = Symbol('var_membrane__Cao', real=True)
var_membrane__Cm = Symbol('var_membrane__Cm', real=True)
var_membrane__F = Symbol('var_membrane__F', real=True)
var_membrane__Ko = Symbol('var_membrane__Ko', real=True)
var_membrane__Nao = Symbol('var_membrane__Nao', real=True)
var_membrane__R = Symbol('var_membrane__R', real=True)
var_membrane__T = Symbol('var_membrane__T', real=True)
var_calcium_background_current__E_CaN= Symbol('var_calcium_background_current__E_CaN', real=True)
var_L_type_calcium_current__Kpcf = Symbol('var_L_type_calcium_current__Kpcf', real=True)
var_L_type_calcium_current__alpha = Symbol('var_L_type_calcium_current__alpha', real=True)
var_L_type_calcium_current__beta = Symbol('var_L_type_calcium_current__beta', real=True)
d_dt_chaste_interface_var_L_type_calcium_current__C2 = Symbol('d_dt_chaste_interface_var_L_type_calcium_current__C2', real=True)
d_dt_chaste_interface_var_L_type_calcium_current__C3 = Symbol('d_dt_chaste_interface_var_L_type_calcium_current__C3', real=True)
d_dt_chaste_interface_var_L_type_calcium_current__C4 = Symbol('d_dt_chaste_interface_var_L_type_calcium_current__C4', real=True)
d_dt_chaste_interface_var_L_type_calcium_current__I1 = Symbol('d_dt_chaste_interface_var_L_type_calcium_current__I1', real=True)
d_dt_chaste_interface_var_L_type_calcium_current__I2 = Symbol('d_dt_chaste_interface_var_L_type_calcium_current__I2', real=True)
d_dt_chaste_interface_var_L_type_calcium_current__I3 = Symbol('d_dt_chaste_interface_var_L_type_calcium_current__I3', real=True)
d_dt_chaste_interface_var_L_type_calcium_current__O = Symbol('d_dt_chaste_interface_var_L_type_calcium_current__O', real=True)
var_L_type_calcium_current__i_CaL = Symbol('var_L_type_calcium_current__i_CaL', real=True)
d_dt_chaste_interface_var_calcium_fluxes__P_RyR = Symbol('d_dt_chaste_interface_var_calcium_fluxes__P_RyR', real=True)
var_calcium_background_current__i_Cab = Symbol('var_calcium_background_current__i_Cab', real=True)
var_fast_sodium_current__alpha_Na11 = Symbol('var_fast_sodium_current__alpha_Na11', real=True)
var_fast_sodium_current__alpha_Na12 = Symbol('var_fast_sodium_current__alpha_Na12', real=True)
var_fast_sodium_current__alpha_Na13= Symbol('var_fast_sodium_current__alpha_Na13', real=True)
var_fast_sodium_current__alpha_Na2 = Symbol('var_fast_sodium_current__alpha_Na2', real=True)
var_fast_sodium_current__alpha_Na3 = Symbol('var_fast_sodium_current__alpha_Na3', real=True)
var_fast_sodium_current__alpha_Na4 = Symbol('var_fast_sodium_current__alpha_Na4', real=True)
var_fast_sodium_current__alpha_Na5 = Symbol('var_fast_sodium_current__alpha_Na5', real=True)
var_fast_sodium_current__beta_Na11 = Symbol('var_fast_sodium_current__beta_Na11', real=True)
var_fast_sodium_current__beta_Na12 = Symbol('var_fast_sodium_current__beta_Na12', real=True)
var_fast_sodium_current__beta_Na13 = Symbol('var_fast_sodium_current__beta_Na13', real=True)
var_fast_sodium_current__beta_Na3 = Symbol('var_fast_sodium_current__beta_Na3', real=True)
d_dt_chaste_interface_var_fast_sodium_current__C_Na1 = Symbol('d_dt_chaste_interface_var_fast_sodium_current__C_Na1', real=True)
d_dt_chaste_interface_var_fast_sodium_current__C_Na2 = Symbol('d_dt_chaste_interface_var_fast_sodium_current__C_Na2', real=True)
d_dt_chaste_interface_var_fast_sodium_current__IC_Na2 = Symbol('d_dt_chaste_interface_var_fast_sodium_current__IC_Na2', real=True)
d_dt_chaste_interface_var_fast_sodium_current__IC_Na3 = Symbol('d_dt_chaste_interface_var_fast_sodium_current__IC_Na3', real=True)
var_fast_sodium_current__beta_Na2 = Symbol('var_fast_sodium_current__beta_Na2', real=True)
d_dt_chaste_interface_var_fast_sodium_current__O_Na = Symbol('d_dt_chaste_interface_var_fast_sodium_current__O_Na', real=True)
var_fast_sodium_current__beta_Na4 = Symbol('var_fast_sodium_current__beta_Na4', real=True)
d_dt_chaste_interface_var_fast_sodium_current__IF_Na = Symbol('d_dt_chaste_interface_var_fast_sodium_current__IF_Na', real=True)
var_fast_sodium_current__beta_Na5 = Symbol('var_fast_sodium_current__beta_Na5', real=True)
d_dt_chaste_interface_var_fast_sodium_current__I1_Na = Symbol('d_dt_chaste_interface_var_fast_sodium_current__I1_Na', real=True)
d_dt_chaste_interface_var_fast_sodium_current__I2_Na = Symbol('d_dt_chaste_interface_var_fast_sodium_current__I2_Na', real=True)
var_fast_transient_outward_potassium_current__alpha_a = Symbol('var_fast_transient_outward_potassium_current__alpha_a', real=True)
var_fast_transient_outward_potassium_current__alpha_i = Symbol('var_fast_transient_outward_potassium_current__alpha_i', real=True)
var_fast_transient_outward_potassium_current__beta_a = Symbol('var_fast_transient_outward_potassium_current__beta_a', real=True)
d_dt_chaste_interface_var_fast_transient_outward_potassium_current__ato_f = Symbol('d_dt_chaste_interface_var_fast_transient_outward_potassium_current__ato_f', real=True)
var_fast_transient_outward_potassium_current__beta_i = Symbol('var_fast_transient_outward_potassium_current__beta_i', real=True)
d_dt_chaste_interface_var_fast_transient_outward_potassium_current__ito_f = Symbol('d_dt_chaste_interface_var_fast_transient_outward_potassium_current__ito_f', real=True)
var_membrane__VJSR = Symbol('var_membrane__VJSR', real=True)
var_membrane__VNSR = Symbol('var_membrane__VNSR', real=True)
var_membrane__Vmyo = Symbol('var_membrane__Vmyo', real=True)
d_dt_chaste_interface_var_calcium_concentration__CaNSR = Symbol('d_dt_chaste_interface_var_calcium_concentration__CaNSR', real=True)
var_membrane__Vss = Symbol('var_membrane__Vss', real=True)
var_non_inactivating_steady_state_potassium_current__g_Kss = Symbol('var_non_inactivating_steady_state_potassium_current__g_Kss', real=True)
var_non_inactivating_steady_state_potassium_current__tau_Kss = Symbol('var_non_inactivating_steady_state_potassium_current__tau_Kss', real=True)
var_fast_transient_outward_potassium_current__E_K = Symbol('var_fast_transient_outward_potassium_current__E_K', real=True)
var_fast_transient_outward_potassium_current__i_Kto_f = Symbol('var_fast_transient_outward_potassium_current__i_Kto_f', real=True)
var_non_inactivating_steady_state_potassium_current__i_Kss = Symbol('var_non_inactivating_steady_state_potassium_current__i_Kss', real=True)
var_rapid_delayed_rectifier_potassium_current__C_K0 = Symbol('var_rapid_delayed_rectifier_potassium_current__C_K0', real=True)
var_rapid_delayed_rectifier_potassium_current__alpha_a0 = Symbol('var_rapid_delayed_rectifier_potassium_current__alpha_a0', real=True)
var_rapid_delayed_rectifier_potassium_current__alpha_a1 = Symbol('var_rapid_delayed_rectifier_potassium_current__alpha_a1', real=True)
var_rapid_delayed_rectifier_potassium_current__alpha_i = Symbol('var_rapid_delayed_rectifier_potassium_current__alpha_i', real=True)
var_rapid_delayed_rectifier_potassium_current__beta_a0 = Symbol('var_rapid_delayed_rectifier_potassium_current__beta_a0', real=True)
var_rapid_delayed_rectifier_potassium_current__beta_a1 = Symbol('var_rapid_delayed_rectifier_potassium_current__beta_a1', real=True)
var_rapid_delayed_rectifier_potassium_current__beta_i = Symbol('var_rapid_delayed_rectifier_potassium_current__beta_i', real=True)
d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__I_K = Symbol('d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__I_K', real=True)
d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__O_K = Symbol('d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__O_K', real=True)
var_rapid_delayed_rectifier_potassium_current__g_Kr = Symbol('var_rapid_delayed_rectifier_potassium_current__g_Kr', real=True)
var_rapid_delayed_rectifier_potassium_current__kb = Symbol('var_rapid_delayed_rectifier_potassium_current__kb', real=True)
var_rapid_delayed_rectifier_potassium_current__kf = Symbol('var_rapid_delayed_rectifier_potassium_current__kf', real=True)
d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__C_K1 = Symbol('d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__C_K1', real=True)
d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__C_K2 = Symbol('d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__C_K2', real=True)
var_calcium_fluxes__J_rel = Symbol('var_calcium_fluxes__J_rel', real=True)
d_dt_chaste_interface_var_calcium_concentration__CaJSR = Symbol('d_dt_chaste_interface_var_calcium_concentration__CaJSR', real=True)
d_dt_chaste_interface_var_calcium_concentration__Cass = Symbol('d_dt_chaste_interface_var_calcium_concentration__Cass', real=True)
var_ryanodine_receptors__P_C1 = Symbol('var_ryanodine_receptors__P_C1', real=True)
var_ryanodine_receptors__k_minus_a = Symbol('var_ryanodine_receptors__k_minus_a', real=True)
var_ryanodine_receptors__k_minus_b = Symbol('var_ryanodine_receptors__k_minus_b', real=True)
var_ryanodine_receptors__k_minus_c = Symbol('var_ryanodine_receptors__k_minus_c', real=True)
var_ryanodine_receptors__k_plus_a = Symbol('var_ryanodine_receptors__k_plus_a', real=True)
var_ryanodine_receptors__k_plus_b = Symbol('var_ryanodine_receptors__k_plus_b', real=True)
var_ryanodine_receptors__k_plus_c = Symbol('var_ryanodine_receptors__k_plus_c', real=True)
d_dt_chaste_interface_var_ryanodine_receptors__P_C2 = Symbol('d_dt_chaste_interface_var_ryanodine_receptors__P_C2', real=True)
var_ryanodine_receptors__m = Symbol('var_ryanodine_receptors__m', real=True)
d_dt_chaste_interface_var_ryanodine_receptors__P_O2 = Symbol('d_dt_chaste_interface_var_ryanodine_receptors__P_O2', real=True)
var_ryanodine_receptors__n = Symbol('var_ryanodine_receptors__n', real=True)
d_dt_chaste_interface_var_ryanodine_receptors__P_O1 = Symbol('d_dt_chaste_interface_var_ryanodine_receptors__P_O1', real=True)
var_slow_delayed_rectifier_potassium_current__alpha_n = Symbol('var_slow_delayed_rectifier_potassium_current__alpha_n', real=True)
var_slow_delayed_rectifier_potassium_current__beta_n = Symbol('var_slow_delayed_rectifier_potassium_current__beta_n', real=True)
var_slow_delayed_rectifier_potassium_current__g_Ks = Symbol('var_slow_delayed_rectifier_potassium_current__g_Ks', real=True)
d_dt_chaste_interface_var_slow_delayed_rectifier_potassium_current__nKs = Symbol('d_dt_chaste_interface_var_slow_delayed_rectifier_potassium_current__nKs', real=True)
var_slow_delayed_rectifier_potassium_current__i_Ks = Symbol('var_slow_delayed_rectifier_potassium_current__i_Ks', real=True)
var_slow_transient_outward_potassium_current__ass = Symbol('var_slow_transient_outward_potassium_current__ass', real=True)
d_dt_chaste_interface_var_non_inactivating_steady_state_potassium_current__aKss = Symbol('d_dt_chaste_interface_var_non_inactivating_steady_state_potassium_current__aKss', real=True)
var_slow_transient_outward_potassium_current__g_Kto_s = Symbol('var_slow_transient_outward_potassium_current__g_Kto_s', real=True)
var_slow_transient_outward_potassium_current__iss = Symbol('var_slow_transient_outward_potassium_current__iss', real=True)
var_slow_transient_outward_potassium_current__i_Kto_s = Symbol('var_slow_transient_outward_potassium_current__i_Kto_s', real=True)
var_slow_transient_outward_potassium_current__tau_ta_s = Symbol('var_slow_transient_outward_potassium_current__tau_ta_s', real=True)
d_dt_chaste_interface_var_slow_transient_outward_potassium_current__ato_s = Symbol('d_dt_chaste_interface_var_slow_transient_outward_potassium_current__ato_s', real=True)
var_slow_transient_outward_potassium_current__tau_ti_s = Symbol('var_slow_transient_outward_potassium_current__tau_ti_s', real=True)
d_dt_chaste_interface_var_slow_transient_outward_potassium_current__ito_s = Symbol('d_dt_chaste_interface_var_slow_transient_outward_potassium_current__ito_s', real=True)
var_sodium_background_current__g_Nab = Symbol('var_sodium_background_current__g_Nab', real=True)
var_sodium_calcium_exchange_current__K_mCa = Symbol('var_sodium_calcium_exchange_current__K_mCa', real=True)
var_sodium_calcium_exchange_current__K_mNa = Symbol('var_sodium_calcium_exchange_current__K_mNa', real=True)
var_sodium_calcium_exchange_current__eta = Symbol('var_sodium_calcium_exchange_current__eta', real=True)
var_sodium_calcium_exchange_current__k_NaCa = Symbol('var_sodium_calcium_exchange_current__k_NaCa', real=True)
var_sodium_calcium_exchange_current__k_sat = Symbol('var_sodium_calcium_exchange_current__k_sat', real=True)
var_fast_sodium_current__E_Na = Symbol('var_fast_sodium_current__E_Na', real=True)
var_fast_sodium_current__i_Na = Symbol('var_fast_sodium_current__i_Na', real=True)
var_rapid_delayed_rectifier_potassium_current__i_Kr = Symbol('var_rapid_delayed_rectifier_potassium_current__i_Kr', real=True)
var_sodium_background_current__i_Nab = Symbol('var_sodium_background_current__i_Nab', real=True)
var_sodium_calcium_exchange_current__i_NaCa = Symbol('var_sodium_calcium_exchange_current__i_NaCa', real=True)
d_dt_chaste_interface_var_calcium_concentration__Cai = Symbol('d_dt_chaste_interface_var_calcium_concentration__Cai', real=True)
var_sodium_potassium_pump_current__Km_Ko = Symbol('var_sodium_potassium_pump_current__Km_Ko', real=True)
var_sodium_potassium_pump_current__Km_Nai = Symbol('var_sodium_potassium_pump_current__Km_Nai', real=True)
var_sodium_potassium_pump_current__i_NaK_max = Symbol('var_sodium_potassium_pump_current__i_NaK_max', real=True)
var_sodium_potassium_pump_current__sigma = Symbol('var_sodium_potassium_pump_current__sigma', real=True)
var_sodium_potassium_pump_current__f_NaK = Symbol('var_sodium_potassium_pump_current__f_NaK', real=True)
var_sodium_potassium_pump_current__i_NaK= Symbol('var_sodium_potassium_pump_current__i_NaK', real=True)
d_dt_chaste_interface_var_sodium_concentration__Nai = Symbol('d_dt_chaste_interface_var_sodium_concentration__Nai', real=True)
var_time_independent_potassium_current__i_K1 = Symbol('var_time_independent_potassium_current__i_K1', real=True)
var_ultra_rapidly_activating_delayed_rectifier_potassium_current__g_Kur = Symbol('var_ultra_rapidly_activating_delayed_rectifier_potassium_current__g_Kur', real=True)
var_ultra_rapidly_activating_delayed_rectifier_potassium_current__i_Kur = Symbol('var_ultra_rapidly_activating_delayed_rectifier_potassium_current__i_Kur', real=True)
d_dt_chaste_interface_var_potassium_concentration__Ki = Symbol('d_dt_chaste_interface_var_potassium_concentration__Ki', real=True)
var_ultra_rapidly_activating_delayed_rectifier_potassium_current__tau_aur = Symbol('var_ultra_rapidly_activating_delayed_rectifier_potassium_current__tau_aur', real=True)
d_dt_chaste_interface_var_ultra_rapidly_activating_delayed_rectifier_potassium_current__aur = Symbol('d_dt_chaste_interface_var_ultra_rapidly_activating_delayed_rectifier_potassium_current__aur', real=True)
var_ultra_rapidly_activating_delayed_rectifier_potassium_current__tau_iur = Symbol('var_ultra_rapidly_activating_delayed_rectifier_potassium_current__tau_iur', real=True)
d_dt_chaste_interface_var_ultra_rapidly_activating_delayed_rectifier_potassium_current__iur = Symbol('d_dt_chaste_interface_var_ultra_rapidly_activating_delayed_rectifier_potassium_current__iur', real=True)
d_dt_chaste_interface_var_membrane__V = Symbol('d_dt_chaste_interface_var_membrane__V', real=True)
var_calcium_activated_chloride_current__E_Cl = Symbol('var_calcium_activated_chloride_current__E_Cl', real=True)
var_calcium_activated_chloride_current__Km_Cl = Symbol('var_calcium_activated_chloride_current__Km_Cl', real=True)
var_calcium_activated_chloride_current__g_ClCa = Symbol('var_calcium_activated_chloride_current__g_ClCa', real=True)
var_calcium_activated_chloride_current__O_ClCa = Symbol('var_calcium_activated_chloride_current__O_ClCa', real=True)
var_calcium_activated_chloride_current__i_ClCa = Symbol('var_calcium_activated_chloride_current__i_ClCa', real=True)
var_membrane__i_stim_converter = Symbol('var_membrane__i_stim_converter', real=True)
var_membrane__i_stim = Symbol('var_membrane__i_stim', real=True)
d_dt_chaste_interface_var_membrane__V = Symbol('d_dt_chaste_interface_var_membrane__V', real=True)

equations = [
Eq(d_dt_chaste_interface_var_non_inactivating_steady_state_potassium_current__iKss, 0.0),
Eq(var_L_type_calcium_current__E_CaL, 63.0),
Eq(var_L_type_calcium_current__Kpc_half, 20.0),
Eq(var_L_type_calcium_current__Kpc_max, 0.23324),
Eq(var_L_type_calcium_current__Kpcb, 0.00050000000000000001),
Eq(var_L_type_calcium_current__C1, 1.0 - var_chaste_interface__L_type_calcium_current__C3 - var_chaste_interface__L_type_calcium_current__C4 - var_chaste_interface__L_type_calcium_current__I1 - var_chaste_interface__L_type_calcium_current__I2 - var_chaste_interface__L_type_calcium_current__I3 - var_chaste_interface__L_type_calcium_current__O - 2 * var_chaste_interface__L_type_calcium_current__C2),
Eq(var_L_type_calcium_current__g_CaL, 0.1729),
Eq(var_L_type_calcium_current__i_CaL_max, 7.0),
Eq(var_calcium_background_current__g_Cab, 0.00036699999999999998),
Eq(var_calcium_buffering__HTRPN_tot, 140.0),
Eq(var_calcium_buffering__LTRPN_tot, 70.0),
Eq(var_calcium_concentration__CMDN_tot, 50.0),
Eq(var_calcium_concentration__CSQN_tot, 15000.0),
Eq(var_L_type_calcium_current__gamma, var_L_type_calcium_current__Kpc_max * var_chaste_interface__calcium_concentration__Cass / (var_L_type_calcium_current__Kpc_half + var_chaste_interface__calcium_concentration__Cass)),
Eq(var_calcium_concentration__Km_CMDN, 0.23799999999999999),
Eq(var_calcium_concentration__Bi, pow((1.0 + pow((var_chaste_interface__calcium_concentration__Cai + var_calcium_concentration__Km_CMDN), (-2.0)) * var_calcium_concentration__CMDN_tot * var_calcium_concentration__Km_CMDN), (-1.0))),
Eq(var_calcium_concentration__Bss, pow((1.0 + pow((var_chaste_interface__calcium_concentration__Cass + var_calcium_concentration__Km_CMDN), (-2.0)) * var_calcium_concentration__CMDN_tot * var_calcium_concentration__Km_CMDN), (-1.0))),
Eq(var_calcium_concentration__Km_CSQN, 800.0),
Eq(var_calcium_concentration__BJSR, pow((1.0 + pow((var_chaste_interface__calcium_concentration__CaJSR + var_calcium_concentration__Km_CSQN), (-2.0)) * var_calcium_concentration__CSQN_tot * var_calcium_concentration__Km_CSQN), (-1.0))),
Eq(var_calcium_fluxes__Km_up, 0.5),
Eq(var_calcium_fluxes__k_minus_htrpn, 3.1999999999999999e-5),
Eq(var_calcium_fluxes__k_minus_ltrpn, 0.019599999999999999),
Eq(var_calcium_fluxes__k_plus_htrpn, 0.0023700000000000001),
Eq(d_dt_chaste_interface_var_calcium_buffering__HTRPN_Ca, -var_chaste_interface__calcium_buffering__HTRPN_Ca * var_calcium_fluxes__k_minus_htrpn + (-var_chaste_interface__calcium_buffering__HTRPN_Ca + var_calcium_buffering__HTRPN_tot) * var_chaste_interface__calcium_concentration__Cai * var_calcium_fluxes__k_plus_htrpn),
Eq(var_calcium_fluxes__k_plus_ltrpn, 0.0327),
Eq(d_dt_chaste_interface_var_calcium_buffering__LTRPN_Ca, -var_chaste_interface__calcium_buffering__LTRPN_Ca * var_calcium_fluxes__k_minus_ltrpn + (-var_chaste_interface__calcium_buffering__LTRPN_Ca + var_calcium_buffering__LTRPN_tot) * var_chaste_interface__calcium_concentration__Cai * var_calcium_fluxes__k_plus_ltrpn),
Eq(var_calcium_fluxes__J_trpn, -var_chaste_interface__calcium_buffering__HTRPN_Ca * var_calcium_fluxes__k_minus_htrpn - var_chaste_interface__calcium_buffering__LTRPN_Ca * var_calcium_fluxes__k_minus_ltrpn + (-var_chaste_interface__calcium_buffering__HTRPN_Ca + var_calcium_buffering__HTRPN_tot) * var_chaste_interface__calcium_concentration__Cai * var_calcium_fluxes__k_plus_htrpn + (-var_chaste_interface__calcium_buffering__LTRPN_Ca + var_calcium_buffering__LTRPN_tot) * var_chaste_interface__calcium_concentration__Cai * var_calcium_fluxes__k_plus_ltrpn),
Eq(var_calcium_fluxes__tau_tr, 20.0),
Eq(var_calcium_fluxes__J_tr, (-var_chaste_interface__calcium_concentration__CaJSR + var_chaste_interface__calcium_concentration__CaNSR) / var_calcium_fluxes__tau_tr),
Eq(var_calcium_fluxes__tau_xfer, 8.0),
Eq(var_calcium_fluxes__J_xfer, (-var_chaste_interface__calcium_concentration__Cai + var_chaste_interface__calcium_concentration__Cass) / var_calcium_fluxes__tau_xfer),
Eq(var_calcium_fluxes__v1, 4.5),
Eq(var_calcium_fluxes__v2, 1.7399999999999999e-5),
Eq(var_calcium_fluxes__J_leak, (-var_chaste_interface__calcium_concentration__Cai + var_chaste_interface__calcium_concentration__CaNSR) * var_calcium_fluxes__v2),
Eq(var_calcium_fluxes__v3, 0.45000000000000001),
Eq(var_calcium_fluxes__J_up, pow(var_chaste_interface__calcium_concentration__Cai, 2.0) * var_calcium_fluxes__v3 / (pow(var_chaste_interface__calcium_concentration__Cai, 2.0) + pow(var_calcium_fluxes__Km_up, 2.0))),
Eq(var_calcium_pump_current__Km_pCa, 0.5),
Eq(var_calcium_pump_current__i_pCa_max, 1.0),
Eq(var_calcium_pump_current__i_pCa, pow(var_chaste_interface__calcium_concentration__Cai, 2.0) * var_calcium_pump_current__i_pCa_max / (pow(var_chaste_interface__calcium_concentration__Cai, 2.0) + pow(var_calcium_pump_current__Km_pCa, 2.0))),
Eq(var_fast_sodium_current__C_Na3, 1.0 - var_chaste_interface__fast_sodium_current__C_Na1 - var_chaste_interface__fast_sodium_current__C_Na2 - var_chaste_interface__fast_sodium_current__I1_Na - var_chaste_interface__fast_sodium_current__I2_Na - var_chaste_interface__fast_sodium_current__IC_Na2 - var_chaste_interface__fast_sodium_current__IC_Na3 - var_chaste_interface__fast_sodium_current__IF_Na - var_chaste_interface__fast_sodium_current__O_Na),
Eq(var_fast_sodium_current__g_Na, 13.0),
Eq(var_fast_transient_outward_potassium_current__g_Kto_f, 0.40670000000000001),
Eq(var_membrane__Acap, 0.00015339999999999999),
Eq(var_membrane__Cao, 1800.0),
Eq(var_membrane__Cm, 1.0),
Eq(var_membrane__F, 96.5),
Eq(var_membrane__Ko, 5400.0),
Eq(var_membrane__Nao, 140000.0),
Eq(var_membrane__R, 8.3140000000000001),
Eq(var_membrane__T, 298.0),
Eq(var_calcium_background_current__E_CaN, 0.5 * var_membrane__R * var_membrane__T * log(var_membrane__Cao / var_chaste_interface__calcium_concentration__Cai) / var_membrane__F),
Eq(var_L_type_calcium_current__Kpcf, 13.0 - 13.0 * exp(-2.1025 * pow((1 + 0.068965517241379309 * var_chaste_interface__membrane__V), 2.0))),
Eq(var_L_type_calcium_current__alpha, 0.40000000000000002 * (1.0 + 0.69999999999999996 * exp(-160.0 * pow((1 + 0.025000000000000001 * var_chaste_interface__membrane__V), 2.0)) - 0.75 * exp(-1.0 * pow((1 + 0.050000000000000003 * var_chaste_interface__membrane__V), 2.0))) * exp(1.2 + 0.10000000000000001 * var_chaste_interface__membrane__V) / (1.0 + 0.12 * exp(1.2 + 0.10000000000000001 * var_chaste_interface__membrane__V))),
Eq(var_L_type_calcium_current__beta, 0.050000000000000003 * exp(-0.92307692307692313 - 0.076923076923076927 * var_chaste_interface__membrane__V)),
Eq(d_dt_chaste_interface_var_L_type_calcium_current__C2, -var_chaste_interface__L_type_calcium_current__C2 * var_L_type_calcium_current__beta + 2.0 * var_chaste_interface__L_type_calcium_current__C3 * var_L_type_calcium_current__beta + 4.0 * var_L_type_calcium_current__C1 * var_L_type_calcium_current__alpha - 3.0 * var_chaste_interface__L_type_calcium_current__C2 * var_L_type_calcium_current__alpha),
Eq(d_dt_chaste_interface_var_L_type_calcium_current__C3, 3.0 * var_chaste_interface__L_type_calcium_current__C2 * var_L_type_calcium_current__alpha + 3.0 * var_chaste_interface__L_type_calcium_current__C4 * var_L_type_calcium_current__beta - 2.0 * var_chaste_interface__L_type_calcium_current__C3 * var_L_type_calcium_current__alpha - 2.0 * var_chaste_interface__L_type_calcium_current__C3 * var_L_type_calcium_current__beta),
Eq(d_dt_chaste_interface_var_L_type_calcium_current__C4, -var_chaste_interface__L_type_calcium_current__C4 * var_L_type_calcium_current__alpha + 2.0 * var_chaste_interface__L_type_calcium_current__C3 * var_L_type_calcium_current__alpha + 4.0 * var_chaste_interface__L_type_calcium_current__O * var_L_type_calcium_current__beta + 0.0080000000000000002 * var_chaste_interface__L_type_calcium_current__I2 * var_L_type_calcium_current__beta - 3.0 * var_chaste_interface__L_type_calcium_current__C4 * var_L_type_calcium_current__beta - 0.002 * var_chaste_interface__L_type_calcium_current__C4 * var_L_type_calcium_current__Kpcf + 4.0 * var_chaste_interface__L_type_calcium_current__I3 * var_L_type_calcium_current__Kpcb * var_L_type_calcium_current__beta + 0.040000000000000001 * var_chaste_interface__L_type_calcium_current__I1 * var_L_type_calcium_current__Kpcb * var_L_type_calcium_current__beta - 1.0 * var_chaste_interface__L_type_calcium_current__C4 * var_L_type_calcium_current__Kpcf * var_L_type_calcium_current__gamma - 0.01 * var_chaste_interface__L_type_calcium_current__C4 * var_L_type_calcium_current__alpha * var_L_type_calcium_current__gamma),
Eq(d_dt_chaste_interface_var_L_type_calcium_current__I1, var_chaste_interface__L_type_calcium_current__O * var_L_type_calcium_current__gamma - var_chaste_interface__L_type_calcium_current__I1 * var_L_type_calcium_current__Kpcb + 0.001 * var_chaste_interface__L_type_calcium_current__I3 * var_L_type_calcium_current__alpha - 0.001 * var_chaste_interface__L_type_calcium_current__I1 * var_L_type_calcium_current__Kpcf + 0.01 * var_chaste_interface__L_type_calcium_current__C4 * var_L_type_calcium_current__alpha * var_L_type_calcium_current__gamma - 0.040000000000000001 * var_chaste_interface__L_type_calcium_current__I1 * var_L_type_calcium_current__Kpcf * var_L_type_calcium_current__beta),
Eq(d_dt_chaste_interface_var_L_type_calcium_current__I2, var_chaste_interface__L_type_calcium_current__I3 * var_L_type_calcium_current__Kpcb - var_chaste_interface__L_type_calcium_current__I2 * var_L_type_calcium_current__gamma + 0.001 * var_L_type_calcium_current__Kpcf * var_chaste_interface__L_type_calcium_current__O + 0.002 * var_chaste_interface__L_type_calcium_current__C4 * var_L_type_calcium_current__Kpcf - 0.001 * var_chaste_interface__L_type_calcium_current__I2 * var_L_type_calcium_current__alpha - 0.0080000000000000002 * var_chaste_interface__L_type_calcium_current__I2 * var_L_type_calcium_current__beta),
Eq(d_dt_chaste_interface_var_L_type_calcium_current__I3, var_chaste_interface__L_type_calcium_current__I2 * var_L_type_calcium_current__gamma - var_chaste_interface__L_type_calcium_current__I3 * var_L_type_calcium_current__Kpcb + 0.001 * var_chaste_interface__L_type_calcium_current__I1 * var_L_type_calcium_current__Kpcf - 0.001 * var_chaste_interface__L_type_calcium_current__I3 * var_L_type_calcium_current__alpha + 1.0 * var_chaste_interface__L_type_calcium_current__C4 * var_L_type_calcium_current__Kpcf * var_L_type_calcium_current__gamma - 4.0 * var_chaste_interface__L_type_calcium_current__I3 * var_L_type_calcium_current__Kpcb * var_L_type_calcium_current__beta),
Eq(d_dt_chaste_interface_var_L_type_calcium_current__O, var_chaste_interface__L_type_calcium_current__C4 * var_L_type_calcium_current__alpha + var_chaste_interface__L_type_calcium_current__I1 * var_L_type_calcium_current__Kpcb - var_chaste_interface__L_type_calcium_current__O * var_L_type_calcium_current__gamma + 0.001 * var_chaste_interface__L_type_calcium_current__I2 * var_L_type_calcium_current__alpha - 4.0 * var_chaste_interface__L_type_calcium_current__O * var_L_type_calcium_current__beta - 0.001 * var_L_type_calcium_current__Kpcf * var_chaste_interface__L_type_calcium_current__O),
Eq(var_L_type_calcium_current__i_CaL, (-var_L_type_calcium_current__E_CaL + var_chaste_interface__membrane__V) * var_chaste_interface__L_type_calcium_current__O * var_L_type_calcium_current__g_CaL),
Eq(d_dt_chaste_interface_var_calcium_fluxes__P_RyR, -0.040000000000000001 * var_chaste_interface__calcium_fluxes__P_RyR - 0.10000000000000001 * var_L_type_calcium_current__i_CaL * exp(-0.038580246913580245 * pow((-1 + 0.20000000000000001 * var_chaste_interface__membrane__V), 2.0)) / var_L_type_calcium_current__i_CaL_max),
Eq(var_calcium_background_current__i_Cab, (-var_calcium_background_current__E_CaN + var_chaste_interface__membrane__V) * var_calcium_background_current__g_Cab),
Eq(var_fast_sodium_current__alpha_Na11, 3.802 / (0.20000000000000001 * exp(-0.016666666666666666 - 0.0066666666666666671 * var_chaste_interface__membrane__V) + 0.1027 * exp(-0.14705882352941177 - 0.058823529411764705 * var_chaste_interface__membrane__V))),
Eq(var_fast_sodium_current__alpha_Na12, 3.802 / (0.1027 * exp(-0.16666666666666666 - 0.066666666666666666 * var_chaste_interface__membrane__V) + 0.23000000000000001 * exp(-0.016666666666666666 - 0.0066666666666666671 * var_chaste_interface__membrane__V))),
Eq(var_fast_sodium_current__alpha_Na13, 3.802 / (0.25 * exp(-0.016666666666666666 - 0.0066666666666666671 * var_chaste_interface__membrane__V) + 0.1027 * exp(-0.20833333333333334 - 0.083333333333333329 * var_chaste_interface__membrane__V))),
Eq(var_fast_sodium_current__alpha_Na2, 1.0 / (0.39395599999999997 + 0.188495 * exp(-0.42168674698795178 - 0.060240963855421679 * var_chaste_interface__membrane__V))),
Eq(var_fast_sodium_current__alpha_Na3, 6.9999999999999997e-7 * exp(-0.90909090909090906 - 0.12987012987012986 * var_chaste_interface__membrane__V)),
Eq(var_fast_sodium_current__alpha_Na4, 0.001 * var_fast_sodium_current__alpha_Na2),
Eq(var_fast_sodium_current__alpha_Na5, 1.0526315789473684e-5 * var_fast_sodium_current__alpha_Na2),
Eq(var_fast_sodium_current__beta_Na11, 0.19170000000000001 * exp(-0.12315270935960591 - 0.04926108374384236 * var_chaste_interface__membrane__V)),
Eq(var_fast_sodium_current__beta_Na12, 0.20000000000000001 * exp(0.12315270935960591 - 0.04926108374384236 * var_chaste_interface__membrane__V)),
Eq(var_fast_sodium_current__beta_Na13, 0.22 * exp(0.36945812807881773 - 0.04926108374384236 * var_chaste_interface__membrane__V)),
Eq(var_fast_sodium_current__beta_Na3, 0.008539999999999999 + 2.0000000000000002e-5 * var_chaste_interface__membrane__V),
Eq(d_dt_chaste_interface_var_fast_sodium_current__C_Na1, var_chaste_interface__fast_sodium_current__C_Na2 * var_fast_sodium_current__alpha_Na12 + var_chaste_interface__fast_sodium_current__IF_Na * var_fast_sodium_current__alpha_Na3 + var_chaste_interface__fast_sodium_current__O_Na * var_fast_sodium_current__beta_Na13 - var_chaste_interface__fast_sodium_current__C_Na1 * var_fast_sodium_current__alpha_Na13 - var_chaste_interface__fast_sodium_current__C_Na1 * var_fast_sodium_current__beta_Na12 - var_chaste_interface__fast_sodium_current__C_Na1 * var_fast_sodium_current__beta_Na3),
Eq(d_dt_chaste_interface_var_fast_sodium_current__C_Na2, var_chaste_interface__fast_sodium_current__C_Na1 * var_fast_sodium_current__beta_Na12 + var_fast_sodium_current__C_Na3 * var_fast_sodium_current__alpha_Na11 + var_chaste_interface__fast_sodium_current__IC_Na2 * var_fast_sodium_current__alpha_Na3 - var_chaste_interface__fast_sodium_current__C_Na2 * var_fast_sodium_current__alpha_Na12 - var_chaste_interface__fast_sodium_current__C_Na2 * var_fast_sodium_current__beta_Na11 - var_chaste_interface__fast_sodium_current__C_Na2 * var_fast_sodium_current__beta_Na3),
Eq(d_dt_chaste_interface_var_fast_sodium_current__IC_Na2, var_chaste_interface__fast_sodium_current__C_Na2 * var_fast_sodium_current__beta_Na3 + var_chaste_interface__fast_sodium_current__IC_Na3 * var_fast_sodium_current__alpha_Na11 + var_chaste_interface__fast_sodium_current__IF_Na * var_fast_sodium_current__beta_Na12 - var_chaste_interface__fast_sodium_current__IC_Na2 * var_fast_sodium_current__alpha_Na12 - var_chaste_interface__fast_sodium_current__IC_Na2 * var_fast_sodium_current__alpha_Na3 - var_chaste_interface__fast_sodium_current__IC_Na2 * var_fast_sodium_current__beta_Na11),
Eq(d_dt_chaste_interface_var_fast_sodium_current__IC_Na3, var_fast_sodium_current__C_Na3 * var_fast_sodium_current__beta_Na3 + var_chaste_interface__fast_sodium_current__IC_Na2 * var_fast_sodium_current__beta_Na11 - var_chaste_interface__fast_sodium_current__IC_Na3 * var_fast_sodium_current__alpha_Na11 - var_chaste_interface__fast_sodium_current__IC_Na3 * var_fast_sodium_current__alpha_Na3),
Eq(var_fast_sodium_current__beta_Na2, var_fast_sodium_current__alpha_Na13 * var_fast_sodium_current__alpha_Na2 * var_fast_sodium_current__alpha_Na3 / (var_fast_sodium_current__beta_Na13 * var_fast_sodium_current__beta_Na3)),
Eq(d_dt_chaste_interface_var_fast_sodium_current__O_Na, var_chaste_interface__fast_sodium_current__C_Na1 * var_fast_sodium_current__alpha_Na13 + var_chaste_interface__fast_sodium_current__IF_Na * var_fast_sodium_current__beta_Na2 - var_chaste_interface__fast_sodium_current__O_Na * var_fast_sodium_current__alpha_Na2 - var_chaste_interface__fast_sodium_current__O_Na * var_fast_sodium_current__beta_Na13),
Eq(var_fast_sodium_current__beta_Na4, var_fast_sodium_current__alpha_Na3),
Eq(d_dt_chaste_interface_var_fast_sodium_current__IF_Na, var_chaste_interface__fast_sodium_current__C_Na1 * var_fast_sodium_current__beta_Na3 + var_chaste_interface__fast_sodium_current__I1_Na * var_fast_sodium_current__beta_Na4 + var_chaste_interface__fast_sodium_current__IC_Na2 * var_fast_sodium_current__alpha_Na12 + var_chaste_interface__fast_sodium_current__O_Na * var_fast_sodium_current__alpha_Na2 - var_chaste_interface__fast_sodium_current__IF_Na * var_fast_sodium_current__alpha_Na3 - var_chaste_interface__fast_sodium_current__IF_Na * var_fast_sodium_current__alpha_Na4 - var_chaste_interface__fast_sodium_current__IF_Na * var_fast_sodium_current__beta_Na12 - var_chaste_interface__fast_sodium_current__IF_Na * var_fast_sodium_current__beta_Na2),
Eq(var_fast_sodium_current__beta_Na5, 0.02 * var_fast_sodium_current__alpha_Na3),
Eq(d_dt_chaste_interface_var_fast_sodium_current__I1_Na, var_chaste_interface__fast_sodium_current__I2_Na * var_fast_sodium_current__beta_Na5 + var_chaste_interface__fast_sodium_current__IF_Na * var_fast_sodium_current__alpha_Na4 - var_chaste_interface__fast_sodium_current__I1_Na * var_fast_sodium_current__alpha_Na5 - var_chaste_interface__fast_sodium_current__I1_Na * var_fast_sodium_current__beta_Na4),
Eq(d_dt_chaste_interface_var_fast_sodium_current__I2_Na, var_chaste_interface__fast_sodium_current__I1_Na * var_fast_sodium_current__alpha_Na5 - var_chaste_interface__fast_sodium_current__I2_Na * var_fast_sodium_current__beta_Na5),
Eq(var_fast_transient_outward_potassium_current__alpha_a, 0.18064 * exp(1.0731000000000002 + 0.035770000000000003 * var_chaste_interface__membrane__V)),
Eq(var_fast_transient_outward_potassium_current__alpha_i, 0.00015200000000000001 * exp(-1.9285714285714286 - 0.14285714285714285 * var_chaste_interface__membrane__V) / (1.0 + 0.0067083000000000004 * exp(-4.7857142857142856 - 0.14285714285714285 * var_chaste_interface__membrane__V))),
Eq(var_fast_transient_outward_potassium_current__beta_a, 0.39560000000000001 * exp(-1.8711 - 0.062370000000000002 * var_chaste_interface__membrane__V)),
Eq(d_dt_chaste_interface_var_fast_transient_outward_potassium_current__ato_f, (1.0 - var_chaste_interface__fast_transient_outward_potassium_current__ato_f) * var_fast_transient_outward_potassium_current__alpha_a - var_chaste_interface__fast_transient_outward_potassium_current__ato_f * var_fast_transient_outward_potassium_current__beta_a),
Eq(var_fast_transient_outward_potassium_current__beta_i, 0.00095 * exp(4.7857142857142856 + 0.14285714285714285 * var_chaste_interface__membrane__V) / (1.0 + 0.051334999999999999 * exp(4.7857142857142856 + 0.14285714285714285 * var_chaste_interface__membrane__V))),
Eq(d_dt_chaste_interface_var_fast_transient_outward_potassium_current__ito_f, (1.0 - var_chaste_interface__fast_transient_outward_potassium_current__ito_f) * var_fast_transient_outward_potassium_current__alpha_i - var_fast_transient_outward_potassium_current__beta_i * var_chaste_interface__fast_transient_outward_potassium_current__ito_f),
Eq(var_membrane__VJSR, 1.1999999999999999e-7),
Eq(var_membrane__VNSR, 2.0980000000000001e-6),
Eq(var_membrane__Vmyo, 2.584e-5),
Eq(d_dt_chaste_interface_var_calcium_concentration__CaNSR, (-var_calcium_fluxes__J_leak + var_calcium_fluxes__J_up) * var_membrane__Vmyo / var_membrane__VNSR - var_calcium_fluxes__J_tr * var_membrane__VJSR / var_membrane__VNSR),
Eq(var_membrane__Vss, 1.4849999999999999e-9),
Eq(var_non_inactivating_steady_state_potassium_current__g_Kss, 0.050000000000000003),
Eq(var_non_inactivating_steady_state_potassium_current__tau_Kss, 13.17 + 39.299999999999997 * exp(-0.086199999999999999 * var_chaste_interface__membrane__V)),
Eq(var_fast_transient_outward_potassium_current__E_K, var_membrane__R * var_membrane__T * log(var_membrane__Ko / var_chaste_interface__potassium_concentration__Ki) / var_membrane__F),
Eq(var_fast_transient_outward_potassium_current__i_Kto_f, pow(var_chaste_interface__fast_transient_outward_potassium_current__ato_f, 3.0) * (-var_fast_transient_outward_potassium_current__E_K + var_chaste_interface__membrane__V) * var_fast_transient_outward_potassium_current__g_Kto_f * var_chaste_interface__fast_transient_outward_potassium_current__ito_f),
Eq(var_non_inactivating_steady_state_potassium_current__i_Kss, (-var_fast_transient_outward_potassium_current__E_K + var_chaste_interface__membrane__V) * var_chaste_interface__non_inactivating_steady_state_potassium_current__aKss * var_non_inactivating_steady_state_potassium_current__g_Kss * var_chaste_interface__non_inactivating_steady_state_potassium_current__iKss),
Eq(var_rapid_delayed_rectifier_potassium_current__C_K0, 1.0 - var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K1 - var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K2 - var_chaste_interface__rapid_delayed_rectifier_potassium_current__I_K - var_chaste_interface__rapid_delayed_rectifier_potassium_current__O_K),
Eq(var_rapid_delayed_rectifier_potassium_current__alpha_a0, 0.022348 * exp(0.01176 * var_chaste_interface__membrane__V)),
Eq(var_rapid_delayed_rectifier_potassium_current__alpha_a1, 0.013733 * exp(0.038198000000000003 * var_chaste_interface__membrane__V)),
Eq(var_rapid_delayed_rectifier_potassium_current__alpha_i, 0.090820999999999999 * exp(0.11695499999999999 + 0.023390999999999999 * var_chaste_interface__membrane__V)),
Eq(var_rapid_delayed_rectifier_potassium_current__beta_a0, 0.047002000000000002 * exp(-0.063100000000000003 * var_chaste_interface__membrane__V)),
Eq(var_rapid_delayed_rectifier_potassium_current__beta_a1, 6.8899999999999994e-5 * exp(-0.041779999999999998 * var_chaste_interface__membrane__V)),
Eq(var_rapid_delayed_rectifier_potassium_current__beta_i, 0.0064970000000000002 * exp(-0.16339999999999999 - 0.032680000000000001 * var_chaste_interface__membrane__V)),
Eq(d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__I_K, var_chaste_interface__rapid_delayed_rectifier_potassium_current__O_K * var_rapid_delayed_rectifier_potassium_current__alpha_i - var_chaste_interface__rapid_delayed_rectifier_potassium_current__I_K * var_rapid_delayed_rectifier_potassium_current__beta_i),
Eq(d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__O_K, var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K2 * var_rapid_delayed_rectifier_potassium_current__alpha_a1 + var_chaste_interface__rapid_delayed_rectifier_potassium_current__I_K * var_rapid_delayed_rectifier_potassium_current__beta_i - var_chaste_interface__rapid_delayed_rectifier_potassium_current__O_K * var_rapid_delayed_rectifier_potassium_current__alpha_i - var_chaste_interface__rapid_delayed_rectifier_potassium_current__O_K * var_rapid_delayed_rectifier_potassium_current__beta_a1),
Eq(var_rapid_delayed_rectifier_potassium_current__g_Kr, 0.078),
Eq(var_rapid_delayed_rectifier_potassium_current__kb, 0.036777999999999998),
Eq(var_rapid_delayed_rectifier_potassium_current__kf, 0.023761000000000001),
Eq(d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__C_K1, var_rapid_delayed_rectifier_potassium_current__C_K0 * var_rapid_delayed_rectifier_potassium_current__alpha_a0 + var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K2 * var_rapid_delayed_rectifier_potassium_current__kb - var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K1 * var_rapid_delayed_rectifier_potassium_current__beta_a0 - var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K1 * var_rapid_delayed_rectifier_potassium_current__kf),
Eq(d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__C_K2, var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K1 * var_rapid_delayed_rectifier_potassium_current__kf + var_chaste_interface__rapid_delayed_rectifier_potassium_current__O_K * var_rapid_delayed_rectifier_potassium_current__beta_a1 - var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K2 * var_rapid_delayed_rectifier_potassium_current__alpha_a1 - var_chaste_interface__rapid_delayed_rectifier_potassium_current__C_K2 * var_rapid_delayed_rectifier_potassium_current__kb),
Eq(var_calcium_fluxes__J_rel, (-var_chaste_interface__calcium_concentration__Cass + var_chaste_interface__calcium_concentration__CaJSR) * (var_chaste_interface__ryanodine_receptors__P_O1 + var_chaste_interface__ryanodine_receptors__P_O2) * var_chaste_interface__calcium_fluxes__P_RyR * var_calcium_fluxes__v1),
Eq(d_dt_chaste_interface_var_calcium_concentration__CaJSR, (-var_calcium_fluxes__J_rel + var_calcium_fluxes__J_tr) * var_calcium_concentration__BJSR),
Eq(d_dt_chaste_interface_var_calcium_concentration__Cass, (var_calcium_fluxes__J_rel * var_membrane__VJSR / var_membrane__Vss - var_calcium_fluxes__J_xfer * var_membrane__Vmyo / var_membrane__Vss - 0.5 * var_L_type_calcium_current__i_CaL * var_membrane__Acap * var_membrane__Cm / (var_membrane__F * var_membrane__Vss)) * var_calcium_concentration__Bss),
Eq(var_ryanodine_receptors__P_C1, 1.0 - var_chaste_interface__ryanodine_receptors__P_C2 - var_chaste_interface__ryanodine_receptors__P_O1 - var_chaste_interface__ryanodine_receptors__P_O2),
Eq(var_ryanodine_receptors__k_minus_a, 0.071249999999999994),
Eq(var_ryanodine_receptors__k_minus_b, 0.96499999999999997),
Eq(var_ryanodine_receptors__k_minus_c, 0.00080000000000000004),
Eq(var_ryanodine_receptors__k_plus_a, 0.00607499999999999974),
Eq(var_ryanodine_receptors__k_plus_b, 0.00404999999999999983),
Eq(var_ryanodine_receptors__k_plus_c, 0.0089999999999999993),
Eq(d_dt_chaste_interface_var_ryanodine_receptors__P_C2, var_chaste_interface__ryanodine_receptors__P_O1 * var_ryanodine_receptors__k_plus_c - var_chaste_interface__ryanodine_receptors__P_C2 * var_ryanodine_receptors__k_minus_c),
Eq(var_ryanodine_receptors__m, 3.0),
Eq(d_dt_chaste_interface_var_ryanodine_receptors__P_O2, -var_chaste_interface__ryanodine_receptors__P_O2 * var_ryanodine_receptors__k_minus_b + pow(var_chaste_interface__calcium_concentration__Cass, var_ryanodine_receptors__m) * var_chaste_interface__ryanodine_receptors__P_O1 * var_ryanodine_receptors__k_plus_b),
Eq(var_ryanodine_receptors__n, 4.0),
Eq(d_dt_chaste_interface_var_ryanodine_receptors__P_O1, var_chaste_interface__ryanodine_receptors__P_C2 * var_ryanodine_receptors__k_minus_c + var_chaste_interface__ryanodine_receptors__P_O2 * var_ryanodine_receptors__k_minus_b - var_chaste_interface__ryanodine_receptors__P_O1 * var_ryanodine_receptors__k_minus_a - var_chaste_interface__ryanodine_receptors__P_O1 * var_ryanodine_receptors__k_plus_c + pow(var_chaste_interface__calcium_concentration__Cass, var_ryanodine_receptors__n) * var_ryanodine_receptors__P_C1 * var_ryanodine_receptors__k_plus_a - pow(var_chaste_interface__calcium_concentration__Cass, var_ryanodine_receptors__m) * var_chaste_interface__ryanodine_receptors__P_O1 * var_ryanodine_receptors__k_plus_b),
Eq(var_slow_delayed_rectifier_potassium_current__alpha_n, 4.8133299999999997e-6 * (26.5 + var_chaste_interface__membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * var_chaste_interface__membrane__V))),
Eq(var_slow_delayed_rectifier_potassium_current__beta_n, 9.5333299999999997e-5 * exp(-1.0069999999999999 - 0.037999999999999999 * var_chaste_interface__membrane__V)),
Eq(var_slow_delayed_rectifier_potassium_current__g_Ks, 0.0057499999999999999),
Eq(d_dt_chaste_interface_var_slow_delayed_rectifier_potassium_current__nKs, (1.0 - var_chaste_interface__slow_delayed_rectifier_potassium_current__nKs) * var_slow_delayed_rectifier_potassium_current__alpha_n - var_slow_delayed_rectifier_potassium_current__beta_n * var_chaste_interface__slow_delayed_rectifier_potassium_current__nKs),
Eq(var_slow_delayed_rectifier_potassium_current__i_Ks, pow(var_chaste_interface__slow_delayed_rectifier_potassium_current__nKs, 2.0) * (-var_fast_transient_outward_potassium_current__E_K + var_chaste_interface__membrane__V) * var_slow_delayed_rectifier_potassium_current__g_Ks),
Eq(var_slow_transient_outward_potassium_current__ass, 1.0 / (1.0 + exp(-2.9220779220779218 - 0.12987012987012986 * var_chaste_interface__membrane__V))),
Eq(d_dt_chaste_interface_var_non_inactivating_steady_state_potassium_current__aKss, (-var_chaste_interface__non_inactivating_steady_state_potassium_current__aKss + var_slow_transient_outward_potassium_current__ass) / var_non_inactivating_steady_state_potassium_current__tau_Kss),
Eq(var_slow_transient_outward_potassium_current__g_Kto_s, 0.0),
Eq(var_slow_transient_outward_potassium_current__iss, 1.0 / (1.0 + exp(7.9298245614035094 + 0.17543859649122806 * var_chaste_interface__membrane__V))),
Eq(var_slow_transient_outward_potassium_current__i_Kto_s, (-var_fast_transient_outward_potassium_current__E_K + var_chaste_interface__membrane__V) * var_chaste_interface__slow_transient_outward_potassium_current__ato_s * var_slow_transient_outward_potassium_current__g_Kto_s * var_chaste_interface__slow_transient_outward_potassium_current__ito_s),
Eq(var_slow_transient_outward_potassium_current__tau_ta_s, 2.0579999999999998 + 0.49299999999999999 * exp(-0.062899999999999998 * var_chaste_interface__membrane__V)),
Eq(d_dt_chaste_interface_var_slow_transient_outward_potassium_current__ato_s, (-var_chaste_interface__slow_transient_outward_potassium_current__ato_s + var_slow_transient_outward_potassium_current__ass) / var_slow_transient_outward_potassium_current__tau_ta_s),
Eq(var_slow_transient_outward_potassium_current__tau_ti_s, 270.0 + 1050.0 / (1.0 + exp(7.9298245614035094 + 0.17543859649122806 * var_chaste_interface__membrane__V))),
Eq(d_dt_chaste_interface_var_slow_transient_outward_potassium_current__ito_s, (-var_chaste_interface__slow_transient_outward_potassium_current__ito_s + var_slow_transient_outward_potassium_current__iss) / var_slow_transient_outward_potassium_current__tau_ti_s),
Eq(var_sodium_background_current__g_Nab, 0.0025999999999999999),
Eq(var_sodium_calcium_exchange_current__K_mCa, 1380.0),
Eq(var_sodium_calcium_exchange_current__K_mNa, 87500.0),
Eq(var_sodium_calcium_exchange_current__eta, 0.34999999999999998),
Eq(var_sodium_calcium_exchange_current__k_NaCa, 292.80000000000001),
Eq(var_sodium_calcium_exchange_current__k_sat, 0.10000000000000001),
Eq(var_fast_sodium_current__E_Na, var_membrane__R * var_membrane__T * log((1.0 * var_membrane__Nao + 0.1111111111111111 * var_membrane__Ko) / (1.0 * var_chaste_interface__sodium_concentration__Nai + 0.1111111111111111 * var_chaste_interface__potassium_concentration__Ki)) / var_membrane__F),
Eq(var_fast_sodium_current__i_Na, (-var_fast_sodium_current__E_Na + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current__O_Na * var_fast_sodium_current__g_Na),
Eq(var_rapid_delayed_rectifier_potassium_current__i_Kr, (-var_membrane__R * var_membrane__T * log((1.0 * var_membrane__Ko + 0.020408163265306124 * var_membrane__Nao) / (1.0 * var_chaste_interface__potassium_concentration__Ki + 0.020408163265306124 * var_chaste_interface__sodium_concentration__Nai)) / var_membrane__F + var_chaste_interface__membrane__V) * var_chaste_interface__rapid_delayed_rectifier_potassium_current__O_K * var_rapid_delayed_rectifier_potassium_current__g_Kr),
Eq(var_sodium_background_current__i_Nab, (-var_fast_sodium_current__E_Na + var_chaste_interface__membrane__V) * var_sodium_background_current__g_Nab),
Eq(var_sodium_calcium_exchange_current__i_NaCa, 1.0 * (pow(var_chaste_interface__sodium_concentration__Nai, 3.0) * var_membrane__Cao * exp(var_membrane__F * var_chaste_interface__membrane__V * var_sodium_calcium_exchange_current__eta / (var_membrane__R * var_membrane__T)) - pow(var_membrane__Nao, 3.0) * var_chaste_interface__calcium_concentration__Cai * exp((-1.0 + var_sodium_calcium_exchange_current__eta) * var_membrane__F * var_chaste_interface__membrane__V / (var_membrane__R * var_membrane__T))) * var_sodium_calcium_exchange_current__k_NaCa / ((1.0 + var_sodium_calcium_exchange_current__k_sat * exp((-1.0 + var_sodium_calcium_exchange_current__eta) * var_membrane__F * var_chaste_interface__membrane__V / (var_membrane__R * var_membrane__T))) * (pow(var_membrane__Nao, 3.0) + pow(var_sodium_calcium_exchange_current__K_mNa, 3.0)) * (var_membrane__Cao + var_sodium_calcium_exchange_current__K_mCa))),
Eq(d_dt_chaste_interface_var_calcium_concentration__Cai, (-var_calcium_fluxes__J_trpn - var_calcium_fluxes__J_up - 0.5 * (-2.0 * var_sodium_calcium_exchange_current__i_NaCa + var_calcium_background_current__i_Cab + var_calcium_pump_current__i_pCa) * var_membrane__Acap * var_membrane__Cm / (var_membrane__F * var_membrane__Vmyo) + var_calcium_fluxes__J_leak + var_calcium_fluxes__J_xfer) * var_calcium_concentration__Bi),
Eq(var_sodium_potassium_pump_current__Km_Ko, 1500.0),
Eq(var_sodium_potassium_pump_current__Km_Nai, 21000.0),
Eq(var_sodium_potassium_pump_current__i_NaK_max, 0.88),
Eq(var_sodium_potassium_pump_current__sigma, -0.14285714285714285 + 0.14285714285714285 * exp(1.4858841010401188e-5 * var_membrane__Nao)),
Eq(var_sodium_potassium_pump_current__f_NaK, 1.0 / (1.0 + 0.1245 * exp(-0.10000000000000001 * var_membrane__F * var_chaste_interface__membrane__V / (var_membrane__R * var_membrane__T)) + 0.036499999999999998 * var_sodium_potassium_pump_current__sigma * exp(-var_membrane__F * var_chaste_interface__membrane__V / (var_membrane__R * var_membrane__T)))),
Eq(var_sodium_potassium_pump_current__i_NaK, 1.0 * var_membrane__Ko * var_sodium_potassium_pump_current__f_NaK * var_sodium_potassium_pump_current__i_NaK_max / ((1.0 + pow((var_sodium_potassium_pump_current__Km_Nai / var_chaste_interface__sodium_concentration__Nai), 1.5)) * (var_membrane__Ko + var_sodium_potassium_pump_current__Km_Ko))),
Eq(d_dt_chaste_interface_var_sodium_concentration__Nai, (-var_fast_sodium_current__i_Na - var_sodium_background_current__i_Nab - 3.0 * var_sodium_calcium_exchange_current__i_NaCa - 3.0 * var_sodium_potassium_pump_current__i_NaK) * var_membrane__Acap * var_membrane__Cm / (var_membrane__F * var_membrane__Vmyo)),
Eq(var_time_independent_potassium_current__i_K1, 0.29380000000000001 * (-var_fast_transient_outward_potassium_current__E_K + var_chaste_interface__membrane__V) * var_membrane__Ko / ((1.0 + exp(0.089599999999999999 * var_chaste_interface__membrane__V - 0.089599999999999999 * var_fast_transient_outward_potassium_current__E_K)) * (210.0 + var_membrane__Ko))),
Eq(var_ultra_rapidly_activating_delayed_rectifier_potassium_current__g_Kur, 0.16),
Eq(var_ultra_rapidly_activating_delayed_rectifier_potassium_current__i_Kur, (-var_fast_transient_outward_potassium_current__E_K + var_chaste_interface__membrane__V) * var_chaste_interface__ultra_rapidly_activating_delayed_rectifier_potassium_current__aur * var_ultra_rapidly_activating_delayed_rectifier_potassium_current__g_Kur * var_chaste_interface__ultra_rapidly_activating_delayed_rectifier_potassium_current__iur),
Eq(d_dt_chaste_interface_var_potassium_concentration__Ki, (-var_fast_transient_outward_potassium_current__i_Kto_f - var_non_inactivating_steady_state_potassium_current__i_Kss - var_rapid_delayed_rectifier_potassium_current__i_Kr - var_slow_delayed_rectifier_potassium_current__i_Ks - var_slow_transient_outward_potassium_current__i_Kto_s - var_time_independent_potassium_current__i_K1 - var_ultra_rapidly_activating_delayed_rectifier_potassium_current__i_Kur + 2.0 * var_sodium_potassium_pump_current__i_NaK) * var_membrane__Acap * var_membrane__Cm / (var_membrane__F * var_membrane__Vmyo)),
Eq(var_ultra_rapidly_activating_delayed_rectifier_potassium_current__tau_aur, 2.0579999999999998 + 0.49299999999999999 * exp(-0.062899999999999998 * var_chaste_interface__membrane__V)),
Eq(d_dt_chaste_interface_var_ultra_rapidly_activating_delayed_rectifier_potassium_current__aur, (-var_chaste_interface__ultra_rapidly_activating_delayed_rectifier_potassium_current__aur + var_slow_transient_outward_potassium_current__ass) / var_ultra_rapidly_activating_delayed_rectifier_potassium_current__tau_aur),
Eq(var_ultra_rapidly_activating_delayed_rectifier_potassium_current__tau_iur, 1200.0 - 170.0 / (1.0 + exp(7.9298245614035094 + 0.17543859649122806 * var_chaste_interface__membrane__V))),
Eq(d_dt_chaste_interface_var_ultra_rapidly_activating_delayed_rectifier_potassium_current__iur, (-var_chaste_interface__ultra_rapidly_activating_delayed_rectifier_potassium_current__iur + var_slow_transient_outward_potassium_current__iss) / var_ultra_rapidly_activating_delayed_rectifier_potassium_current__tau_iur),
Eq(d_dt_chaste_interface_var_membrane__V, 0.0),
Eq(var_calcium_activated_chloride_current__E_Cl, -40.0),
Eq(var_calcium_activated_chloride_current__Km_Cl, 10.0),
Eq(var_calcium_activated_chloride_current__g_ClCa, 10.0),
Eq(var_calcium_activated_chloride_current__O_ClCa, 0.20000000000000001 / (1.0 + exp(5.9871794871794881 - 0.12820512820512822 * var_chaste_interface__membrane__V))),
Eq(var_calcium_activated_chloride_current__i_ClCa, (-var_calcium_activated_chloride_current__E_Cl + var_chaste_interface__membrane__V) * var_calcium_activated_chloride_current__O_ClCa * var_calcium_activated_chloride_current__g_ClCa * var_chaste_interface__calcium_concentration__Cai / (var_calcium_activated_chloride_current__Km_Cl + var_chaste_interface__calcium_concentration__Cai)),
Eq(var_membrane__i_stim_converter, Function('GetIntracellularAreaStimulus', real=True)(var_chaste_interface__environment__time)),
Eq(var_membrane__i_stim, var_membrane__i_stim_converter / HeartConfig__Instance__GetCapacitance),
Eq(d_dt_chaste_interface_var_membrane__V, -var_L_type_calcium_current__i_CaL - var_calcium_activated_chloride_current__i_ClCa - var_calcium_background_current__i_Cab - var_calcium_pump_current__i_pCa - var_fast_sodium_current__i_Na - var_fast_transient_outward_potassium_current__i_Kto_f - var_membrane__i_stim - var_non_inactivating_steady_state_potassium_current__i_Kss - var_rapid_delayed_rectifier_potassium_current__i_Kr - var_slow_delayed_rectifier_potassium_current__i_Ks - var_slow_transient_outward_potassium_current__i_Kto_s - var_sodium_background_current__i_Nab - var_sodium_calcium_exchange_current__i_NaCa - var_sodium_potassium_pump_current__i_NaK - var_time_independent_potassium_current__i_K1 - var_ultra_rapidly_activating_delayed_rectifier_potassium_current__i_Kur),
]
required_equations = [
d_dt_chaste_interface_var_non_inactivating_steady_state_potassium_current__iKss,
d_dt_chaste_interface_var_calcium_buffering__HTRPN_Ca,
d_dt_chaste_interface_var_calcium_buffering__LTRPN_Ca,
d_dt_chaste_interface_var_L_type_calcium_current__C2,
d_dt_chaste_interface_var_L_type_calcium_current__C3,
d_dt_chaste_interface_var_L_type_calcium_current__C4,
d_dt_chaste_interface_var_L_type_calcium_current__I1,
d_dt_chaste_interface_var_L_type_calcium_current__I2,
d_dt_chaste_interface_var_L_type_calcium_current__I3,
d_dt_chaste_interface_var_L_type_calcium_current__O,
d_dt_chaste_interface_var_calcium_fluxes__P_RyR,
d_dt_chaste_interface_var_fast_sodium_current__C_Na1,
d_dt_chaste_interface_var_fast_sodium_current__C_Na2,
d_dt_chaste_interface_var_fast_sodium_current__IC_Na2,
d_dt_chaste_interface_var_fast_sodium_current__IC_Na3,
d_dt_chaste_interface_var_fast_sodium_current__O_Na,
d_dt_chaste_interface_var_fast_sodium_current__IF_Na,
d_dt_chaste_interface_var_fast_sodium_current__I1_Na,
d_dt_chaste_interface_var_fast_sodium_current__I2_Na,
d_dt_chaste_interface_var_fast_transient_outward_potassium_current__ato_f,
d_dt_chaste_interface_var_fast_transient_outward_potassium_current__ito_f,
d_dt_chaste_interface_var_calcium_concentration__CaNSR,
d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__I_K,
d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__O_K,
d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__C_K1,
d_dt_chaste_interface_var_rapid_delayed_rectifier_potassium_current__C_K2,
d_dt_chaste_interface_var_calcium_concentration__CaJSR,
d_dt_chaste_interface_var_calcium_concentration__Cass,
d_dt_chaste_interface_var_ryanodine_receptors__P_C2,
d_dt_chaste_interface_var_ryanodine_receptors__P_O2,
d_dt_chaste_interface_var_ryanodine_receptors__P_O1,
d_dt_chaste_interface_var_slow_delayed_rectifier_potassium_current__nKs,
d_dt_chaste_interface_var_non_inactivating_steady_state_potassium_current__aKss,
d_dt_chaste_interface_var_slow_transient_outward_potassium_current__ato_s,
d_dt_chaste_interface_var_slow_transient_outward_potassium_current__ito_s,
d_dt_chaste_interface_var_calcium_concentration__Cai,
d_dt_chaste_interface_var_sodium_concentration__Nai,
d_dt_chaste_interface_var_potassium_concentration__Ki,
d_dt_chaste_interface_var_ultra_rapidly_activating_delayed_rectifier_potassium_current__aur,
d_dt_chaste_interface_var_ultra_rapidly_activating_delayed_rectifier_potassium_current__iur,
d_dt_chaste_interface_var_membrane__V,
d_dt_chaste_interface_var_membrane__V,
]

def replace_func(eq, dict):
    new_rhs = eq.rhs
    for lhs, rhs in dict.items():
        new_rhs = new_rhs.replace(lhs, rhs)
    return Eq(eq.lhs, new_rhs)

def xreplace_func(eq, dict):
    new_rhs = eq.rhs
    for lhs, rhs in dict.items():
        new_rhs = new_rhs.xreplace({lhs: rhs})
    return Eq(eq.lhs, new_rhs)


t1 = time.process_time()

for i in range(10):
    x1 = partial_eval(equations, required_equations, lambda eq, dict: Eq(eq.lhs, eq.rhs.xreplace(dict)))

print('xreplace took:' + str(time.process_time() - t1 ))
t2 = time.process_time()

for i in range(10):
    x2 = partial_eval(equations, required_equations, lambda eq, dict: Eq(eq.lhs, eq.rhs.subs(dict)))

print('subs took:' + str(time.process_time() - t2 ))
t3 = time.process_time()

for i in range(10):
    x3 = partial_eval(equations, required_equations, replace_func)

print('replace took:' + str(time.process_time() - t3 ))

t4 = time.process_time()

for i in range(10):
    x4 = partial_eval(equations, required_equations, replace_func)

print('xreplace func took:' + str(time.process_time() - t4 ))


assert len(x1) == len(x2) == len(x3) == len(x4)
assert x1[1] == x2[1] == x3[1] == x4[1]
assert x1[2] == x2[2] == x3[2] == x4[2]
assert x1[3] == x2[3] == x3[3] == x4[3]
