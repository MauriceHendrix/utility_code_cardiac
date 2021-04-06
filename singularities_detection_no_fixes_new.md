# Model: aslanidi_atrial_model_2009(aslanidi_atrial_model_2009.cellml)
Number of piecewises: 6
## Equation 1:
```
L_type_Ca_channel_d_L_gate__alpha_d_L = -50.0 * L_type_Ca_channel_d_L_gate__E10 / (-1.0 + exp(-0.20798668885191349 * L_type_Ca_channel_d_L_gate__E10)) - 16.719999999999999 * L_type_Ca_channel_d_L_gate__E0_alpha_d_L / (-1.0 + exp(-0.40000000000000002 * L_type_Ca_channel_d_L_gate__E0_alpha_d_L))
```
## New Eq:
```
L_type_Ca_channel_d_L_gate__alpha_d_L = -16.719999999999999 * (45.0 + membrane__V) / (-1.0 + exp(-18.0 - 0.40000000000000002 * membrane__V)) + ((fabs(10.0 + membrane__V) < 4.8079999981354149e-7) ? (2.4040000035085995e-5 / (-1.0 + exp(1.000000001459484e-7)) + 1039933.4446628628 * (10.000000480800001 + membrane__V) * (-2.4040000035085995e-5 / (-1.0 + exp(1.000000001459484e-7)) - 2.4039999946268154e-5 / (-1.0 + exp(-9.9999999776489825e-8)))) : (-50.0 * (10.0 + membrane__V) / (-1.0 + exp(-2.0798668885191347 - 0.20798668885191349 * membrane__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_atrial_model_2009/1_0.png)

## Equation 2:
```
L_type_Ca_channel_d_L_gate__beta_d_L = 4.4800000000000004 * L_type_Ca_channel_d_L_gate__E0_beta_d_L / (-1.0 + exp(0.40000000000000002 * L_type_Ca_channel_d_L_gate__E0_beta_d_L))
```
## New Eq:
```
L_type_Ca_channel_d_L_gate__beta_d_L = ((fabs(5.0 + membrane__V) < 2.500000002569891e-7) ? (1.1200000011513112e-6 / (-1.0 + exp(1.0000000010279564e-7)) - 1999999.9979440873 * (4.9999997499999997 + membrane__V) * (-1.1200000011513112e-6 / (-1.0 + exp(1.0000000010279564e-7)) - 1.1200000011513112e-6 / (-1.0 + exp(-1.0000000010279564e-7)))) : (4.4800000000000004 * (5.0 + membrane__V) / (-1.0 + exp(2.0 + 0.40000000000000002 * membrane__V))))
```
## Singularity point: -5.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_atrial_model_2009/2_0.png)

## Equation 3:
```
L_type_Ca_channel_f_L_gate__alpha_f_L = 8.4900000000000002 * L_type_Ca_channel_f_L_gate__E0_f_L / (-1.0 + exp(0.25 * L_type_Ca_channel_f_L_gate__E0_f_L))
```
## New Eq:
```
L_type_Ca_channel_f_L_gate__alpha_f_L = ((fabs(18.0 + membrane__V) < 4.0000000112172529e-7) ? (3.3960000095234478e-6 / (-1.0 + exp(1.0000000028043132e-7)) - 1249999.9964946085 * (17.999999599999999 + membrane__V) * (-3.3960000095234478e-6 / (-1.0 + exp(1.0000000028043132e-7)) - 3.3960000095234478e-6 / (-1.0 + exp(-1.0000000028043132e-7)))) : (8.4900000000000002 * (18.0 + membrane__V) / (-1.0 + exp(4.5 + 0.25 * membrane__V))))
```
## Singularity point: -18.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_atrial_model_2009/3_0.png)

## Equation 4:
```
sodium_current_m_gate__alpha_m = -460.0 * sodium_current_m_gate__E0_m / (-1.0 + exp(-0.078907914463820727 * sodium_current_m_gate__E0_m))
```
## New Eq:
```
sodium_current_m_gate__alpha_m = ((fabs(44.399999999999999 + membrane__V) < 1.2673000000518186e-6) ? (0.00058295800002383658 / (-1.0 + exp(1.000000000040889e-7)) + 394539.57230297127 * (44.400001267299999 + membrane__V) * (-0.00058295800002383658 / (-1.0 + exp(1.000000000040889e-7)) - 0.00058295800002383658 / (-1.0 + exp(-1.000000000040889e-7)))) : (-460.0 * (44.399999999999999 + membrane__V) / (-1.0 + exp(-3.5035114021936398 - 0.078907914463820727 * membrane__V))))
```
## Singularity point: -44.399999999999999
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_atrial_model_2009/4_0.png)

## Equation 5:
```
sodium_current__i_Na = pow(membrane__F, 2) * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp((-sodium_current__E_Na + membrane__V) * membrane__F / (membrane__R * membrane__T))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
sodium_current__i_Na = ((fabs(membrane__V) < 2.6539450910485349e-6) ? (-188398.77346612973 * (-2.6539450910485349e-6 + membrane__V) * (-0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(9.9999999999999995e-8)) - 0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-9.9999999999999995e-8))) + 0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(9.9999999999999995e-8))) : (3635.606491085292 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(0.037679754693225945 * membrane__V - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / (-1.0 + exp(0.037679754693225945 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_atrial_model_2009/5_0.png)

Number of singularities:  5
# Model: aslanidi_2009(aslanidi_Purkinje_model_2009.cellml)
Number of piecewises: 4
## Equation 1:
```
i_Ks_xs1_gate__tau_xs1 = 1 / (7.6100000000000007e-5 * (44.600000000000001 + membrane__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * membrane__V)) + 0.00036000000000000002 * (-0.55000000000000004 + membrane__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * membrane__V)))
```
## New Eq:
```
i_Ks_xs1_gate__tau_xs1 = 1 / (((fabs(-0.55000000000000004 + membrane__V) < 7.8125000002593481e-7) ? (2.8125000000933653e-10 / (-1.0 + exp(1.0000000000331966e-7)) - 639999.9999787542 * (-0.55000078125000007 + membrane__V) * (-2.8125000000933653e-10 / (-1.0 + exp(1.0000000000331966e-7)) - 2.8125000000933653e-10 / (-1.0 + exp(-1.0000000000331966e-7)))) : (0.00036000000000000002 * (-0.55000000000000004 + membrane__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * membrane__V)))) + ((fabs(44.600000000000001 + membrane__V) < 1.0030088759549471e-8) ? (-7.6329002496322579e-13 / (1.0 - exp(1.0000002035326362e-7)) + 49850007.511046082 * (44.600000010030094 + membrane__V) * (7.6329002496322579e-13 / (1.0 - exp(1.0000002035326362e-7)) + 7.6328948424020387e-13 / (1.0 - exp(-9.9999949512152856e-8)))) : (7.6100000000000007e-5 * (44.600000000000001 + membrane__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * membrane__V)))))
```
## Singularity point: 0.55000000000000004
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_Purkinje_model_2009/1_0.png)
## Singularity point: -44.600000000000001
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_Purkinje_model_2009/1_1.png)

## Equation 2:
```
i_Ks_xs2_gate__tau_xs2 = 2.0 / (7.6100000000000007e-5 * (44.600000000000001 + membrane__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * membrane__V)) + 0.00036000000000000002 * (-0.55000000000000004 + membrane__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * membrane__V)))
```
## New Eq:
```
i_Ks_xs2_gate__tau_xs2 = 2.0 / (((fabs(-0.55000000000000004 + membrane__V) < 7.8125000002593481e-7) ? (2.8125000000933653e-10 / (-1.0 + exp(1.0000000000331966e-7)) - 639999.9999787542 * (-0.55000078125000007 + membrane__V) * (-2.8125000000933653e-10 / (-1.0 + exp(1.0000000000331966e-7)) - 2.8125000000933653e-10 / (-1.0 + exp(-1.0000000000331966e-7)))) : (0.00036000000000000002 * (-0.55000000000000004 + membrane__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * membrane__V)))) + ((fabs(44.600000000000001 + membrane__V) < 1.0030088759549471e-8) ? (-7.6329002496322579e-13 / (1.0 - exp(1.0000002035326362e-7)) + 49850007.511046082 * (44.600000010030094 + membrane__V) * (7.6329002496322579e-13 / (1.0 - exp(1.0000002035326362e-7)) + 7.6328948424020387e-13 / (1.0 - exp(-9.9999949512152856e-8)))) : (7.6100000000000007e-5 * (44.600000000000001 + membrane__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * membrane__V)))))
```
## Singularity point: 0.55000000000000004
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_Purkinje_model_2009/2_0.png)
## Singularity point: -44.600000000000001
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_Purkinje_model_2009/2_1.png)

## Equation 3:
```
i_Na_L_m_L_gate__alpha_m_L = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
i_Na_L_m_L_gate__alpha_m_L = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_Purkinje_model_2009/3_0.png)

## Equation 4:
```
i_Na_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
i_Na_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_Purkinje_model_2009/4_0.png)

## Equation 5:
```
i_to_2__i_to_2_max = pow(i_to_2__z_Cl, 2) * pow(model_parameters__F, 2) * (-model_parameters__Cl_o * exp(-i_to_2__z_Cl * membrane__V * model_parameters__F / (model_parameters__R * model_parameters__T)) + intracellular_ion_concentrations__Cl_i) * i_to_2__p_Cl * membrane__V / ((1.0 - exp(-i_to_2__z_Cl * membrane__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__Cm * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_to_2__i_to_2_max = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (3.8593999999999993e-9 * (-100.0 * exp(9.9999999999999995e-8) + intracellular_ion_concentrations__Cl_i) / (1.0 - exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-3.8593999999999993e-9 * (-100.0 * exp(9.9999999999999995e-8) + intracellular_ion_concentrations__Cl_i) / (1.0 - exp(9.9999999999999995e-8)) - 3.8593999999999993e-9 * (-100.0 * exp(-9.9999999999999995e-8) + intracellular_ion_concentrations__Cl_i) / (1.0 - exp(-9.9999999999999995e-8)))) : (0.0014448004881001341 * (-100.0 * exp(0.037435883507802616 * membrane__V) + intracellular_ion_concentrations__Cl_i) * membrane__V / (1.0 - exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_Purkinje_model_2009/5_0.png)

## Equation 6:
```
background_currents__i_Ca_b = pow(model_parameters__F, 2) * pow(model_parameters__z_Ca, 2) * (-model_parameters__Ca_o * model_parameters__gamma_Cao + Ca_i__Ca_i * model_parameters__gamma_Cai * exp(membrane__V * model_parameters__F * model_parameters__z_Ca / (model_parameters__R * model_parameters__T))) * background_currents__p_Ca_b * membrane__V / ((-1.0 + exp(membrane__V * model_parameters__F * model_parameters__z_Ca / (model_parameters__R * model_parameters__T))) * model_parameters__Cm * model_parameters__R * model_parameters__T)
```
## New Eq:
```
background_currents__i_Ca_b = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (3.8499135947999997e-9 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_i__Ca_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 374358.83507802623 * (-1.3356169352749131e-6 + membrane__V) * (-3.8499135947999997e-9 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_i__Ca_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 3.8499135947999997e-9 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_i__Ca_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.0028824983370007683 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_i__Ca_i * exp(0.074871767015605231 * membrane__V)) * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_Purkinje_model_2009/6_0.png)

## Equation 7:
```
i_Ca_L__i_Ca_L_max = pow(model_parameters__F, 2) * pow(model_parameters__z_Ca, 2) * (-15.0 + membrane__V) * (-model_parameters__Ca_o * model_parameters__gamma_Cao + Ca_r__Ca_r * model_parameters__gamma_Cai * exp((-15.0 + membrane__V) * model_parameters__F * model_parameters__z_Ca / (model_parameters__R * model_parameters__T))) * i_Ca_L__p_Ca / ((-1.0 + exp((-15.0 + membrane__V) * model_parameters__F * model_parameters__z_Ca / (model_parameters__R * model_parameters__T))) * model_parameters__Cm * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_Ca_L__i_Ca_L_max = ((fabs(-15.0 + membrane__V) < 1.3356169352718439e-6) ? (4.6891709968709491e-6 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_r__Ca_r * exp(9.9999999933270713e-8)) / (-1.0 + exp(9.9999999933270713e-8)) - 374358.83507888648 * (-15.000001335616934 + membrane__V) * (-4.6891709968709491e-6 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_r__Ca_r * exp(9.9999999933270713e-8)) / (-1.0 + exp(9.9999999933270713e-8)) - 4.6891710031074985e-6 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_r__Ca_r * exp(-1.0000000006626968e-7)) / (-1.0 + exp(-1.0000000006626968e-7)))) : (3.510865186083326 * (-15.0 + membrane__V) * (-0.34100000000000003 * model_parameters__Ca_o + Ca_r__Ca_r * exp(-1.1230765052340785 + 0.074871767015605231 * membrane__V)) / (-1.0 + exp(-1.1230765052340785 + 0.074871767015605231 * membrane__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/aslanidi_Purkinje_model_2009/7_0.png)

Number of singularities:  9
# Model: beeler_reuter_model_1977(beeler_reuter_model_1977.cellml)
Number of piecewises: 0
## Equation 1:
```
sodium_current_m_gate__alpha_m = -(47.0 + membrane__V) / (-1.0 + exp(-4.7000000000000002 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
sodium_current_m_gate__alpha_m = ((fabs(47.0 + membrane__V) < 1.0000000010279564e-6) ? (1.0000000045806701e-6 / (-1.0 + exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.000001000000005 + membrane__V) * (-9.9999999747524271e-7 / (-1.0 + exp(-9.9999999747524276e-8)) - 1.0000000045806701e-6 / (-1.0 + exp(1.0000000045806701e-7)))) : (-(47.0 + membrane__V) / (-1.0 + exp(-4.7000000000000002 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/beeler_reuter_model_1977/1_0.png)

## Equation 2:
```
time_independent_outward_current__i_K1 = (4.0 * (-1.0 + exp(3.3999999999999999 + 0.040000000000000001 * membrane__V)) / (exp(2.1200000000000001 + 0.040000000000000001 * membrane__V) + exp(4.2400000000000002 + 0.080000000000000002 * membrane__V)) + 0.20000000000000001 * (23.0 + membrane__V) / (1.0 - exp(-0.92000000000000004 - 0.040000000000000001 * membrane__V))) * time_independent_outward_current__G_K1
```
## New Eq:
```
time_independent_outward_current__i_K1 = (4.0 * (-1.0 + exp(3.3999999999999999 + 0.040000000000000001 * membrane__V)) / (exp(2.1200000000000001 + 0.040000000000000001 * membrane__V) + exp(4.2400000000000002 + 0.080000000000000002 * membrane__V)) + ((fabs(23.0 + membrane__V) < 2.5000000007935341e-6) ? (-5.0000000015870685e-7 / (1.0 - exp(1.0000000003174136e-7)) + 199999.99993651727 * (23.000002500000001 + membrane__V) * (5.0000000015870685e-7 / (1.0 - exp(1.0000000003174136e-7)) + 5.0000000015870685e-7 / (1.0 - exp(-1.0000000003174136e-7)))) : (0.20000000000000001 * (23.0 + membrane__V) / (1.0 - exp(-0.92000000000000004 - 0.040000000000000001 * membrane__V))))) * time_independent_outward_current__G_K1
```
## Singularity point: -23.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/beeler_reuter_model_1977/2_0.png)

Number of singularities:  2
# Model: benson_epicardial_2008(benson_epicardial_2008.cellml)
Number of piecewises: 7
## Equation 1:
```
ICaL__ibarca = 4.0 * (-15.0 + cell__V) * (-Environment__Ca_o * ICaL__gacao + Ca__Ca_ss * ICaL__gacai * exp(2.0 * (-15.0 + cell__V) * Environment__FonRT)) * Environment__F * Environment__FonRT * ICaL__pca / (-1.0 + exp(2.0 * (-15.0 + cell__V) * Environment__FonRT))
```
## New Eq:
```
ICaL__ibarca = ((fabs(-15.0 + cell__V) < 1.3356169352718439e-6) ? (-374358.83507888648 * (-15.000001335616936 + cell__V) * (-0.0192969999871219 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-9.9999999933263712e-8)) * ICaL__pca / (-1.0 + exp(-9.9999999933263712e-8)) - 0.019297000012786711 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(1.0000000006626268e-7)) * ICaL__pca / (-1.0 + exp(1.0000000006626268e-7))) + 0.019297000012786711 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(1.0000000006626268e-7)) * ICaL__pca / (-1.0 + exp(1.0000000006626268e-7))) : (14448.004881000332 * (-15.0 + cell__V) * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-1.1230765052339999 + 0.074871767015599999 * cell__V)) * ICaL__pca / (-1.0 + exp(-1.1230765052339999 + 0.074871767015599999 * cell__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/benson_epicardial_2008/1_0.png)

## Equation 2:
```
ICab__ICab = 7.9803360000000004e-7 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(2.0 * Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * cell__V / (-1.0 + exp(2.0 * Environment__FonRT * cell__V))
```
## New Eq:
```
ICab__ICab = ((fabs(cell__V) < 1.3356169352750067e-6) ? (3.8499135948000005e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(1.0000000000000001e-7)) / (-1.0 + exp(1.0000000000000001e-7)) - 374358.83507799997 * (-1.3356169352750067e-6 + cell__V) * (-3.8499135948000005e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(1.0000000000000001e-7)) / (-1.0 + exp(1.0000000000000001e-7)) - 3.8499135948000005e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(-1.0000000000000001e-7)) / (-1.0 + exp(-1.0000000000000001e-7)))) : (0.0028824983370005666 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(0.074871767015599999 * cell__V)) * cell__V / (-1.0 + exp(0.074871767015599999 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/benson_epicardial_2008/2_0.png)

## Equation 3:
```
IKr__tauxr = 1 / (0.00029999999999999997 * (38.360799999999998 + cell__V) / (-1.0 + exp(5.8385137599999997 + 0.1522 * cell__V)) + 0.00059999999999999995 * (-1.7383999999999999 + cell__V) / (1.0 - exp(0.2364224 - 0.13600000000000001 * cell__V)))
```
## New Eq:
```
IKr__tauxr = 1 / (((fabs(38.360799999999998 + cell__V) < 6.5703022045227044e-7) ? (1.9710906613568111e-10 / (-1.0 + exp(9.9999999552835566e-8)) - 761000.00340292137 * (38.360799342969777 + cell__V) * (-1.9710906613568111e-10 / (-1.0 + exp(9.9999999552835566e-8)) - 1.9710906613568111e-10 / (-1.0 + exp(-9.9999999552835566e-8)))) : (0.00029999999999999997 * (38.360799999999998 + cell__V) / (-1.0 + exp(5.8385137599999997 + 0.1522 * cell__V)))) + ((fabs(-1.7384000000000002 + cell__V) < 7.3529411770412167e-7) ? (-4.4117647055585959e-10 / (1.0 - exp(9.9999999992661527e-8)) + 679999.99994722824 * (-1.7383992647058824 + cell__V) * (4.4117647055585959e-10 / (1.0 - exp(9.9999999992661527e-8)) + 4.4117647068908634e-10 / (1.0 - exp(-1.0000000002285959e-7)))) : (0.00059999999999999995 * (-1.7383999999999999 + cell__V) / (1.0 - exp(0.2364224 - 0.13600000000000001 * cell__V)))))
```
## Singularity point: -38.360799999999998
![Singularity](diagrams/new/no_singularity_fixes/benson_epicardial_2008/3_0.png)
## Singularity point: 1.7384000000000002
![Singularity](diagrams/new/no_singularity_fixes/benson_epicardial_2008/3_1.png)

## Equation 4:
```
IKs__tauxs = 1 / (7.6100000000000007e-5 * (44.600000000000001 + cell__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * cell__V)) + 0.00036000000000000002 * (-0.55000000000000004 + cell__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * cell__V)))
```
## New Eq:
```
IKs__tauxs = 1 / (((fabs(-0.55000000000000004 + cell__V) < 7.8125000002593481e-7) ? (2.8125000000933653e-10 / (-1.0 + exp(1.0000000000331966e-7)) - 639999.9999787542 * (-0.55000078125000007 + cell__V) * (-2.8125000000933653e-10 / (-1.0 + exp(1.0000000000331966e-7)) - 2.8125000000933653e-10 / (-1.0 + exp(-1.0000000000331966e-7)))) : (0.00036000000000000002 * (-0.55000000000000004 + cell__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * cell__V)))) + ((fabs(44.600000000000001 + cell__V) < 1.0030088759549471e-8) ? (-7.6329002496322579e-13 / (1.0 - exp(1.0000002035326362e-7)) + 49850007.511046082 * (44.600000010030094 + cell__V) * (7.6329002496322579e-13 / (1.0 - exp(1.0000002035326362e-7)) + 7.6328948424020387e-13 / (1.0 - exp(-9.9999949512152856e-8)))) : (7.6100000000000007e-5 * (44.600000000000001 + cell__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * cell__V)))))
```
## Singularity point: 0.55000000000000004
![Singularity](diagrams/new/no_singularity_fixes/benson_epicardial_2008/4_0.png)
## Singularity point: -44.600000000000001
![Singularity](diagrams/new/no_singularity_fixes/benson_epicardial_2008/4_1.png)

## Equation 5:
```
INa__am = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa__am = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/benson_epicardial_2008/5_0.png)

## Equation 6:
```
INal__amL = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INal__amL = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/benson_epicardial_2008/6_0.png)

## Equation 7:
```
Ito2__Ito2_max = (-Environment__Cl_o * exp(Environment__FonRT * cell__V) + Cl__Cl_i) * Environment__F * Environment__FonRT * Ito2__PCl * cell__V / (1.0 - exp(Environment__FonRT * cell__V))
```
## New Eq:
```
Ito2__Ito2_max = ((fabs(cell__V) < 2.6712338705500134e-6) ? (3.8594000000000001e-9 * (-100.0 * exp(1.0000000000000001e-7) + Cl__Cl_i) / (1.0 - exp(1.0000000000000001e-7)) - 187179.41753899999 * (-2.6712338705500134e-6 + cell__V) * (-3.8594000000000001e-9 * (-100.0 * exp(1.0000000000000001e-7) + Cl__Cl_i) / (1.0 - exp(1.0000000000000001e-7)) - 3.8594000000000001e-9 * (-100.0 * exp(-1.0000000000000001e-7) + Cl__Cl_i) / (1.0 - exp(-1.0000000000000001e-7)))) : (0.001444800488100033 * (-100.0 * exp(0.0374358835078 * cell__V) + Cl__Cl_i) * cell__V / (1.0 - exp(0.0374358835078 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/benson_epicardial_2008/7_0.png)

Number of singularities:  9
# Model: bernus_wilders_zemlin_verschelde_panfilov_2002_version01(bernus_wilders_zemlin_verschelde_panfilov_2002.cellml)
Number of piecewises: 0
## Equation 1:
```
sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/bernus_wilders_zemlin_verschelde_panfilov_2002/1_0.png)

Number of singularities:  1
# Model: bondarenko_2004_apical(bondarenko_szigeti_bett_kim_rasmusson_2004_apical.cellml)
Number of piecewises: 0
## Equation 1:
```
slow_delayed_rectifier_potassium_current__alpha_n = 4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current__alpha_n = ((fabs(26.5 + membrane__V) < 7.812499998038902e-7) ? (-3.7604140701062501e-12 / (1.0 - exp(1.0000000020227162e-7)) + 640000.00016065314 * (26.500000781250002 + membrane__V) * (3.760414053005867e-12 / (1.0 - exp(-9.9999999747524276e-8)) + 3.7604140701062501e-12 / (1.0 - exp(1.0000000020227162e-7)))) : (4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))))
```
## Singularity point: -26.500000000000000
![Singularity](diagrams/new/no_singularity_fixes/bondarenko_szigeti_bett_kim_rasmusson_2004_apical/1_0.png)

Number of singularities:  1
# Model: bondarenko_2004_septum(bondarenko_szigeti_bett_kim_rasmusson_2004_septal.cellml)
Number of piecewises: 0
## Equation 1:
```
slow_delayed_rectifier_potassium_current__alpha_n = 4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current__alpha_n = ((fabs(26.5 + membrane__V) < 7.812499998038902e-7) ? (-3.7604140701062501e-12 / (1.0 - exp(1.0000000020227162e-7)) + 640000.00016065314 * (26.500000781250002 + membrane__V) * (3.760414053005867e-12 / (1.0 - exp(-9.9999999747524276e-8)) + 3.7604140701062501e-12 / (1.0 - exp(1.0000000020227162e-7)))) : (4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))))
```
## Singularity point: -26.500000000000000
![Singularity](diagrams/new/no_singularity_fixes/bondarenko_szigeti_bett_kim_rasmusson_2004_septal/1_0.png)

Number of singularities:  1
# Model: bueno_2007(bueno_2007_endo.cellml)
Number of piecewises: 5
Number of singularities:  0
# Model: bueno_2007(bueno_2007_epi.cellml)
Number of piecewises: 5
Number of singularities:  0
# Model: Carro_Rodriguez_Laguna_Pueyo_CinC2010_EPI(carro_2011_endo.cellml)
Number of piecewises: 4
## Equation 1:
```
L_Type_Calcium_Current__Ibar_Ca_j = (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(2.0 * membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Ca * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(2.0 * membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Ca_j = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + membrane__V) * (-9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (0.71831868267118426 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(0.074871767015605231 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/carro_2011_endo/1_0.png)

## Equation 2:
```
L_Type_Calcium_Current__Ibar_Ca_sl = (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(2.0 * membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Ca * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(2.0 * membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Ca_sl = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + membrane__V) * (-9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (0.71831868267118426 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(0.074871767015605231 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/carro_2011_endo/2_0.png)

## Equation 3:
```
L_Type_Calcium_Current__Ibar_K = (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_K * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_K = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (0.00019748616671718709 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/carro_2011_endo/3_0.png)

## Equation 4:
```
L_Type_Calcium_Current__Ibar_Na_j = (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Na * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Na_j = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (1.0971453706510394e-5 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/carro_2011_endo/4_0.png)

## Equation 5:
```
L_Type_Calcium_Current__Ibar_Na_sl = (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Na * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Na_sl = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (1.0971453706510394e-5 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/carro_2011_endo/5_0.png)

Number of singularities:  5
# Model: Carro_Rodriguez_Laguna_Pueyo_CinC2010_EPI(carro_2011_epi.cellml)
Number of piecewises: 4
## Equation 1:
```
L_Type_Calcium_Current__Ibar_Ca_j = (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(2.0 * membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Ca * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(2.0 * membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Ca_j = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + membrane__V) * (-9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (0.71831868267118426 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(0.074871767015605231 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/carro_2011_epi/1_0.png)

## Equation 2:
```
L_Type_Calcium_Current__Ibar_Ca_sl = (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(2.0 * membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Ca * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(2.0 * membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Ca_sl = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + membrane__V) * (-9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (0.71831868267118426 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(0.074871767015605231 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/carro_2011_epi/2_0.png)

## Equation 3:
```
L_Type_Calcium_Current__Ibar_K = (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_K * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_K = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (0.00019748616671718709 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/carro_2011_epi/3_0.png)

## Equation 4:
```
L_Type_Calcium_Current__Ibar_Na_j = (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Na * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Na_j = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (1.0971453706510394e-5 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/carro_2011_epi/4_0.png)

## Equation 5:
```
L_Type_Calcium_Current__Ibar_Na_sl = (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Na * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Na_sl = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (1.0971453706510394e-5 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/carro_2011_epi/5_0.png)

Number of singularities:  5
# Model: clancy_rudy_2002(clancy_rudy_2002.cellml)
Number of piecewises: 9
## Equation 1:
```
L_type_Ca_channel__I_CaCa = 4.0 * pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Cao * calcium_dynamics__Cao + L_type_Ca_channel__gamma_Cai * calcium_dynamics__Cai * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Ca * L_type_Ca_channel__P_scale * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaCa = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + membrane__V) * (-1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (7.8019226357407252 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(0.074871767015605231 * membrane__V)) * L_type_Ca_channel__P_scale * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/clancy_rudy_2002/1_0.png)

## Equation 2:
```
L_type_Ca_channel__I_CaK = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_K * L_type_Ca_channel__P_scale * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaK = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (0.00069711623550831479 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037435883507802616 * membrane__V)) * L_type_Ca_channel__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/clancy_rudy_2002/2_0.png)

## Equation 3:
```
L_type_Ca_channel__I_CaNa = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Na * L_type_Ca_channel__P_scale * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaNa = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-6.5127374999999992e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(9.9999999999999995e-8)) - 6.5127374999999992e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) + 6.5127374999999992e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(9.9999999999999995e-8))) : (0.0024381008236689767 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037435883507802616 * membrane__V)) * L_type_Ca_channel__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/clancy_rudy_2002/3_0.png)

## Equation 4:
```
L_type_Ca_channel_d_gate__tau_d = 0.028571428571428571 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * L_type_Ca_channel_d_gate__d_infinity / (10.0 + membrane__V)
```
## New Eq:
```
L_type_Ca_channel_d_gate__tau_d = ((fabs(10.0 + membrane__V) < 6.2400000011564316e-7) ? (801282.05113355326 * (10.000000624 + membrane__V) * (45787.545779060179 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7)) + 45787.545779060179 * (1.0 - exp(-1.0000000001853256e-7)) / (1.0 + exp(-1.0000000001853256e-7))) - 45787.545779060179 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7))) : (0.028571428571428571 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * (10.0 + membrane__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/clancy_rudy_2002/4_0.png)

## Equation 5:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = 0.001 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = 0.001 * ((fabs(30.0 + membrane__V) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + membrane__V) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/clancy_rudy_2002/5_0.png)

## Equation 6:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 0.0040000000000000001 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 0.0040000000000000001 * ((fabs(30.0 + membrane__V) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + membrane__V) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/clancy_rudy_2002/6_0.png)

Number of singularities:  6
# Model: Corrias_rabbit_purkinje_model(corrias_purkinje_2011.cellml)
Number of piecewises: 0
## Equation 1:
```
x_ks__tau_x_ks = 1 / (0.00013100000000000001 * (30.0 + membrane__Vm) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__Vm)) + 7.1899999999999999e-5 * (30.0 + membrane__Vm) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__Vm)))
```
## New Eq:
```
x_ks__tau_x_ks = ((fabs(30.0 + membrane__Vm) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + membrane__Vm) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__Vm) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__Vm)) + 7.1899999999999999e-5 * (30.0 + membrane__Vm) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__Vm)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/corrias_purkinje_2011/1_0.png)

## Equation 2:
```
y_kr__ykrv1 = 0.0013799999999999999 * (7.0 + membrane__Vm) / (1.0 - exp(-0.86099999999999999 - 0.123 * membrane__Vm))
```
## New Eq:
```
y_kr__ykrv1 = ((fabs(7.0 + membrane__Vm) < 8.1300813015161566e-7) ? (-1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 614999.99994681031 * (7.0000008130081302 + membrane__Vm) * (1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 1.1219512196092296e-9 / (1.0 - exp(-1.0000000000864873e-7)))) : (0.0013799999999999999 * (7.0 + membrane__Vm) / (1.0 - exp(-0.86099999999999999 - 0.123 * membrane__Vm))))
```
## Singularity point: -7.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/corrias_purkinje_2011/2_0.png)

## Equation 3:
```
y_kr__ykrv2 = 6.0999999999999999e-5 * (10.0 + membrane__Vm) / (-1.0 + exp(1.45 + 0.14499999999999999 * membrane__Vm))
```
## New Eq:
```
y_kr__ykrv2 = ((fabs(10.0 + membrane__Vm) < 6.8965517296959433e-7) ? (4.2068965605324136e-11 / (-1.0 + exp(1.0000000020937704e-7)) - 724999.99941571394 * (9.9999993103448261 + membrane__Vm) * (-4.206896549696637e-11 / (-1.0 + exp(-9.9999999951805303e-8)) - 4.2068965605324136e-11 / (-1.0 + exp(1.0000000020937704e-7)))) : (6.0999999999999999e-5 * (10.0 + membrane__Vm) / (-1.0 + exp(1.45 + 0.14499999999999999 * membrane__Vm))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/corrias_purkinje_2011/3_0.png)

Number of singularities:  3
# Model: courtemanche_1998(courtemanche_ramirez_nattel_1998.cellml)
Number of piecewises: 4
## Equation 1:
```
Ca_release_current_from_JSR_w_gate__tau_w = 6.0 * (1.0 - exp(1.5800000000000001 - 0.20000000000000001 * membrane__V)) / ((1.0 + 0.29999999999999999 * exp(1.5800000000000001 - 0.20000000000000001 * membrane__V)) * (-7.9000000000000004 + membrane__V))
```
## New Eq:
```
Ca_release_current_from_JSR_w_gate__tau_w = ((fabs(-7.9000000000000004 + membrane__V) < 5.0000000006988898e-7) ? (999999.99986022199 * (-7.8999995000000007 + membrane__V) * (11999999.987664523 * (1.0 - exp(-1.0000000010279564e-7)) / (1.0 + 0.29999999999999999 * exp(-1.0000000010279564e-7)) + 12000000.008980805 * (1.0 - exp(9.9999999925159949e-8)) / (1.0 + 0.29999999999999999 * exp(9.9999999925159949e-8))) - 12000000.008980805 * (1.0 - exp(9.9999999925159949e-8)) / (1.0 + 0.29999999999999999 * exp(9.9999999925159949e-8))) : (6.0 * (1.0 - exp(1.5800000000000001 - 0.20000000000000001 * membrane__V)) / ((1.0 + 0.29999999999999999 * exp(1.5800000000000001 - 0.20000000000000001 * membrane__V)) * (-7.9000000000000004 + membrane__V))))
```
## Singularity point: 7.9000000000000004
![Singularity](diagrams/new/no_singularity_fixes/courtemanche_ramirez_nattel_1998/1_0.png)

## Equation 2:
```
L_type_Ca_channel_d_gate__tau_d = 28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * (10.0 + membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__tau_d = ((fabs(10.0 + membrane__V) < 6.2400000011564316e-7) ? (801282.05113355326 * (10.000000624 + membrane__V) * (45787545.779060178 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7)) + 45787545.779060178 * (1.0 - exp(-1.0000000001853256e-7)) / (1.0 + exp(-1.0000000001853256e-7))) - 45787545.779060178 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7))) : (28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * (10.0 + membrane__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/courtemanche_ramirez_nattel_1998/2_0.png)

## Equation 3:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/courtemanche_ramirez_nattel_1998/3_0.png)

## Equation 4:
```
rapid_delayed_rectifier_K_current_xr_gate__alpha_xr = 0.00029999999999999997 * (14.1 + membrane__V) / (1.0 - exp(-2.8199999999999998 - 0.20000000000000001 * membrane__V))
```
## New Eq:
```
rapid_delayed_rectifier_K_current_xr_gate__alpha_xr = ((fabs(14.1 + membrane__V) < 5.0000000051397819e-7) ? (-1.5000000015419344e-10 / (1.0 - exp(1.0000000010279564e-7)) + 999999.99897204363 * (14.1000005 + membrane__V) * (1.5000000015419344e-10 / (1.0 - exp(1.0000000010279564e-7)) + 1.5000000015419344e-10 / (1.0 - exp(-1.0000000010279564e-7)))) : (0.00029999999999999997 * (14.1 + membrane__V) / (1.0 - exp(-2.8199999999999998 - 0.20000000000000001 * membrane__V))))
```
## Singularity point: -14.100000000000000
![Singularity](diagrams/new/no_singularity_fixes/courtemanche_ramirez_nattel_1998/4_0.png)

## Equation 5:
```
rapid_delayed_rectifier_K_current_xr_gate__beta_xr = 7.3898000000000003e-5 * (-3.3328000000000002 + membrane__V) / (-1.0 + exp(-0.65046743564221166 + 0.19517145812596365 * membrane__V))
```
## New Eq:
```
rapid_delayed_rectifier_K_current_xr_gate__beta_xr = ((fabs(-3.3328000000000002 + membrane__V) < 5.1236999998316435e-7) ? (3.786311824234723e-11 / (-1.0 + exp(9.9999999953377383e-8)) - 975857.29066188342 * (-3.33280051237 + membrane__V) * (-3.7863118275164535e-11 / (-1.0 + exp(-1.0000000004005093e-7)) - 3.786311824234723e-11 / (-1.0 + exp(9.9999999953377383e-8)))) : (7.3898000000000003e-5 * (-3.3328000000000002 + membrane__V) / (-1.0 + exp(-0.65046743564221166 + 0.19517145812596365 * membrane__V))))
```
## Singularity point: 3.3328000000000002
![Singularity](diagrams/new/no_singularity_fixes/courtemanche_ramirez_nattel_1998/5_0.png)

## Equation 6:
```
slow_delayed_rectifier_K_current_xs_gate__alpha_xs = 4.0000000000000003e-5 * (-19.899999999999999 + membrane__V) / (1.0 - exp(1.1705882352941175 - 0.058823529411764705 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_K_current_xs_gate__alpha_xs = ((fabs(-19.899999999999999 + membrane__V) < 1.7000000003264404e-6) ? (-6.7999999942003354e-11 / (1.0 - exp(9.9999999914710792e-8)) + 294117.64700234594 * (-19.8999983 + membrane__V) * (6.8000000084111897e-11 / (1.0 - exp(-1.0000000012369395e-7)) + 6.7999999942003354e-11 / (1.0 - exp(9.9999999914710792e-8)))) : (4.0000000000000003e-5 * (-19.899999999999999 + membrane__V) / (1.0 - exp(1.1705882352941175 - 0.058823529411764705 * membrane__V))))
```
## Singularity point: 19.899999999999999
![Singularity](diagrams/new/no_singularity_fixes/courtemanche_ramirez_nattel_1998/6_0.png)

## Equation 7:
```
slow_delayed_rectifier_K_current_xs_gate__beta_xs = 3.4999999999999997e-5 * (-19.899999999999999 + membrane__V) / (-1.0 + exp(-2.2111111111111108 + 0.1111111111111111 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_K_current_xs_gate__beta_xs = ((fabs(-19.899999999999999 + membrane__V) < 8.9999999985934664e-7) ? (3.1499999995077133e-11 / (-1.0 + exp(9.9999999984371854e-8)) - 555555.55564237863 * (-19.900000899999998 + membrane__V) * (-3.1499999995077133e-11 / (-1.0 + exp(9.9999999984371854e-8)) - 3.1499999995077133e-11 / (-1.0 + exp(-9.9999999984371854e-8)))) : (3.4999999999999997e-5 * (-19.899999999999999 + membrane__V) / (-1.0 + exp(-2.2111111111111108 + 0.1111111111111111 * membrane__V))))
```
## Singularity point: 19.899999999999999
![Singularity](diagrams/new/no_singularity_fixes/courtemanche_ramirez_nattel_1998/7_0.png)

Number of singularities:  7
# Model: davies_isap_2012(davies_isap_2012.cellml)
Number of piecewises: 5
## Equation 1:
```
ICaL__ibarca = 4.0 * (-15.0 + cell__V) * (-Environment__Ca_o * ICaL__gacao + Ca__Ca_ss * ICaL__gacai * exp(2.0 * (-15.0 + cell__V) * Environment__FonRT)) * Environment__F * Environment__FonRT * ICaL__pca / (-1.0 + exp(2.0 * (-15.0 + cell__V) * Environment__FonRT))
```
## New Eq:
```
ICaL__ibarca = ((fabs(-15.0 + cell__V) < 1.3356169352718439e-6) ? (-374358.83507888648 * (-15.000001335616936 + cell__V) * (-0.0192969999871219 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-9.9999999933263712e-8)) * ICaL__pca / (-1.0 + exp(-9.9999999933263712e-8)) - 0.019297000012786711 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(1.0000000006626268e-7)) * ICaL__pca / (-1.0 + exp(1.0000000006626268e-7))) + 0.019297000012786711 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(1.0000000006626268e-7)) * ICaL__pca / (-1.0 + exp(1.0000000006626268e-7))) : (14448.004881000332 * (-15.0 + cell__V) * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-1.1230765052339999 + 0.074871767015599999 * cell__V)) * ICaL__pca / (-1.0 + exp(-1.1230765052339999 + 0.074871767015599999 * cell__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/davies_isap_2012/1_0.png)

## Equation 2:
```
ICab__ICab = (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(2.0 * Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * ICab__GCab * cell__V / (-1.0 + exp(2.0 * Environment__FonRT * cell__V))
```
## New Eq:
```
ICab__ICab = ((fabs(cell__V) < 1.3356169352750067e-6) ? (-374358.83507799997 * (-1.3356169352750067e-6 + cell__V) * (-0.0048242500000000004 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(1.0000000000000001e-7)) * ICab__GCab / (-1.0 + exp(1.0000000000000001e-7)) - 0.0048242500000000004 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(-1.0000000000000001e-7)) * ICab__GCab / (-1.0 + exp(-1.0000000000000001e-7))) + 0.0048242500000000004 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(1.0000000000000001e-7)) * ICab__GCab / (-1.0 + exp(1.0000000000000001e-7))) : (3612.001220250083 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(0.074871767015599999 * cell__V)) * ICab__GCab * cell__V / (-1.0 + exp(0.074871767015599999 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/davies_isap_2012/2_0.png)

## Equation 3:
```
IKs__tauxs = 1 / (7.6100000000000007e-5 * (44.600000000000001 + cell__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * cell__V)) + 0.00036000000000000002 * (-0.55000000000000004 + cell__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * cell__V)))
```
## New Eq:
```
IKs__tauxs = 1 / (((fabs(-0.55000000000000004 + cell__V) < 7.8125000002593481e-7) ? (2.8125000000933653e-10 / (-1.0 + exp(1.0000000000331966e-7)) - 639999.9999787542 * (-0.55000078125000007 + cell__V) * (-2.8125000000933653e-10 / (-1.0 + exp(1.0000000000331966e-7)) - 2.8125000000933653e-10 / (-1.0 + exp(-1.0000000000331966e-7)))) : (0.00036000000000000002 * (-0.55000000000000004 + cell__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * cell__V)))) + ((fabs(44.600000000000001 + cell__V) < 1.0030088759549471e-8) ? (-7.6329002496322579e-13 / (1.0 - exp(1.0000002035326362e-7)) + 49850007.511046082 * (44.600000010030094 + cell__V) * (7.6329002496322579e-13 / (1.0 - exp(1.0000002035326362e-7)) + 7.6328948424020387e-13 / (1.0 - exp(-9.9999949512152856e-8)))) : (7.6100000000000007e-5 * (44.600000000000001 + cell__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * cell__V)))))
```
## Singularity point: 0.55000000000000004
![Singularity](diagrams/new/no_singularity_fixes/davies_isap_2012/3_0.png)
## Singularity point: -44.600000000000001
![Singularity](diagrams/new/no_singularity_fixes/davies_isap_2012/3_1.png)

## Equation 4:
```
INa__am = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa__am = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/davies_isap_2012/4_0.png)

## Equation 5:
```
INal__amL = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INal__amL = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/davies_isap_2012/5_0.png)

## Equation 6:
```
Ito2__Ito2_max = (-Environment__Cl_o * exp(Environment__FonRT * cell__V) + Cl__Cl_i) * Environment__F * Environment__FonRT * Ito2__PCl * cell__V / (1.0 - exp(Environment__FonRT * cell__V))
```
## New Eq:
```
Ito2__Ito2_max = ((fabs(cell__V) < 2.6712338705500134e-6) ? (-187179.41753899999 * (-2.6712338705500134e-6 + cell__V) * (-0.0096485000000000008 * (-Environment__Cl_o * exp(1.0000000000000001e-7) + Cl__Cl_i) * Ito2__PCl / (1.0 - exp(1.0000000000000001e-7)) - 0.0096485000000000008 * (-Environment__Cl_o * exp(-1.0000000000000001e-7) + Cl__Cl_i) * Ito2__PCl / (1.0 - exp(-1.0000000000000001e-7))) + 0.0096485000000000008 * (-Environment__Cl_o * exp(1.0000000000000001e-7) + Cl__Cl_i) * Ito2__PCl / (1.0 - exp(1.0000000000000001e-7))) : (3612.001220250083 * (-Environment__Cl_o * exp(0.0374358835078 * cell__V) + Cl__Cl_i) * Ito2__PCl * cell__V / (1.0 - exp(0.0374358835078 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/davies_isap_2012/6_0.png)

Number of singularities:  7
# Model: decker_2009(decker_2009.cellml)
Number of piecewises: 4
## Equation 1:
```
IKr_xr_gate__tau_xr = 1 / (0.00029999999999999997 * (38.360799999999998 + membrane__Vm) / (-1.0 + exp(5.8385137599999997 + 0.1522 * membrane__Vm)) + 0.00059999999999999995 * (-1.7383999999999999 + membrane__Vm) / (1.0 - exp(0.2364224 - 0.13600000000000001 * membrane__Vm)))
```
## New Eq:
```
IKr_xr_gate__tau_xr = 1 / (((fabs(38.360799999999998 + membrane__Vm) < 6.5703022045227044e-7) ? (1.9710906613568111e-10 / (-1.0 + exp(9.9999999552835566e-8)) - 761000.00340292137 * (38.360799342969777 + membrane__Vm) * (-1.9710906613568111e-10 / (-1.0 + exp(9.9999999552835566e-8)) - 1.9710906613568111e-10 / (-1.0 + exp(-9.9999999552835566e-8)))) : (0.00029999999999999997 * (38.360799999999998 + membrane__Vm) / (-1.0 + exp(5.8385137599999997 + 0.1522 * membrane__Vm)))) + ((fabs(-1.7384000000000002 + membrane__Vm) < 7.3529411770412167e-7) ? (-4.4117647055585959e-10 / (1.0 - exp(9.9999999992661527e-8)) + 679999.99994722824 * (-1.7383992647058824 + membrane__Vm) * (4.4117647055585959e-10 / (1.0 - exp(9.9999999992661527e-8)) + 4.4117647068908634e-10 / (1.0 - exp(-1.0000000002285959e-7)))) : (0.00059999999999999995 * (-1.7383999999999999 + membrane__Vm) / (1.0 - exp(0.2364224 - 0.13600000000000001 * membrane__Vm)))))
```
## Singularity point: -38.360799999999998
![Singularity](diagrams/new/no_singularity_fixes/decker_2009/1_0.png)
## Singularity point: 1.7384000000000002
![Singularity](diagrams/new/no_singularity_fixes/decker_2009/1_1.png)

## Equation 2:
```
INaL_mL_gate__amL = 0.32000000000000001 * (47.130000000000003 + membrane__Vm) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__Vm))
```
## New Eq:
```
INaL_mL_gate__amL = ((fabs(47.130000000000003 + membrane__Vm) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__Vm) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__Vm) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__Vm))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/decker_2009/2_0.png)

## Equation 3:
```
INa_m_gate__am = 0.32000000000000001 * (47.130000000000003 + membrane__Vm) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__Vm))
```
## New Eq:
```
INa_m_gate__am = ((fabs(47.130000000000003 + membrane__Vm) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__Vm) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__Vm) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__Vm))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/decker_2009/3_0.png)

## Equation 4:
```
ICaL__ICaL_max = 4.0 * pow(model_parameters__F, 2) * (-ICaL__gamma_Cao * model_parameters__Ca_o + Ca__Ca_ss_CaL * ICaL__gamma_Cai * exp(2.0 * membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__PCa * membrane__Vm / ((-1.0 + exp(2.0 * membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
ICaL__ICaL_max = ((fabs(membrane__Vm) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + membrane__Vm) * (-0.019296999999999998 * (-0.34100000000000003 * model_parameters__Ca_o + Ca__Ca_ss_CaL * exp(9.9999999999999995e-8)) * ICaL__PCa / (-1.0 + exp(9.9999999999999995e-8)) - 0.019296999999999998 * (-0.34100000000000003 * model_parameters__Ca_o + Ca__Ca_ss_CaL * exp(-9.9999999999999995e-8)) * ICaL__PCa / (-1.0 + exp(-9.9999999999999995e-8))) + 0.019296999999999998 * (-0.34100000000000003 * model_parameters__Ca_o + Ca__Ca_ss_CaL * exp(9.9999999999999995e-8)) * ICaL__PCa / (-1.0 + exp(9.9999999999999995e-8))) : (14448.004881001343 * (-0.34100000000000003 * model_parameters__Ca_o + Ca__Ca_ss_CaL * exp(0.074871767015605231 * membrane__Vm)) * ICaL__PCa * membrane__Vm / (-1.0 + exp(0.074871767015605231 * membrane__Vm))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/decker_2009/4_0.png)

## Equation 5:
```
ICab__ICab = 4.0 * pow(model_parameters__F, 2) * (-ICab__gamma_Ca_o * model_parameters__Ca_o + Ca__Ca_i * ICab__gamma_Ca_i * exp(2.0 * membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICab__PCab * membrane__Vm / ((-1.0 + exp(2.0 * membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__Vm) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + membrane__Vm) * (-0.019296999999999998 * (-0.34100000000000003 * model_parameters__Ca_o + Ca__Ca_i * exp(9.9999999999999995e-8)) * ICab__PCab / (-1.0 + exp(9.9999999999999995e-8)) - 0.019296999999999998 * (-0.34100000000000003 * model_parameters__Ca_o + Ca__Ca_i * exp(-9.9999999999999995e-8)) * ICab__PCab / (-1.0 + exp(-9.9999999999999995e-8))) + 0.019296999999999998 * (-0.34100000000000003 * model_parameters__Ca_o + Ca__Ca_i * exp(9.9999999999999995e-8)) * ICab__PCab / (-1.0 + exp(9.9999999999999995e-8))) : (14448.004881001343 * (-0.34100000000000003 * model_parameters__Ca_o + Ca__Ca_i * exp(0.074871767015605231 * membrane__Vm)) * ICab__PCab * membrane__Vm / (-1.0 + exp(0.074871767015605231 * membrane__Vm))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/decker_2009/5_0.png)

## Equation 6:
```
INab__INab = (-model_parameters__Na_o + Na__Na_i * exp(INab__phi)) * INab__PNab * INab__phi * model_parameters__F / (-1.0 + exp(INab__phi))
```
## New Eq:
```
INab__INab = ((fabs(membrane__Vm) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__Vm) * (-0.0096484999999999991 * (-model_parameters__Na_o + Na__Na_i * exp(9.9999999999999995e-8)) * INab__PNab / (-1.0 + exp(9.9999999999999995e-8)) - 0.0096484999999999991 * (-model_parameters__Na_o + Na__Na_i * exp(-9.9999999999999995e-8)) * INab__PNab / (-1.0 + exp(-9.9999999999999995e-8))) + 0.0096484999999999991 * (-model_parameters__Na_o + Na__Na_i * exp(9.9999999999999995e-8)) * INab__PNab / (-1.0 + exp(9.9999999999999995e-8))) : (3612.0012202503358 * (-model_parameters__Na_o + Na__Na_i * exp(0.037435883507802616 * membrane__Vm)) * INab__PNab * membrane__Vm / (-1.0 + exp(0.037435883507802616 * membrane__Vm))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/decker_2009/6_0.png)

## Equation 7:
```
Ito2__Ito2_max = pow(Ito2__zCl, 2) * pow(model_parameters__F, 2) * (-model_parameters__Cl_o * exp(membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T)) + Cl__Cl_i) * Ito2__PCl * membrane__Vm / ((1.0 - exp(membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
Ito2__Ito2_max = ((fabs(membrane__Vm) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__Vm) * (-0.0096484999999999991 * (-100.0 * exp(9.9999999999999995e-8) + Cl__Cl_i) * Ito2__PCl / (1.0 - exp(9.9999999999999995e-8)) - 0.0096484999999999991 * (-100.0 * exp(-9.9999999999999995e-8) + Cl__Cl_i) * Ito2__PCl / (1.0 - exp(-9.9999999999999995e-8))) + 0.0096484999999999991 * (-100.0 * exp(9.9999999999999995e-8) + Cl__Cl_i) * Ito2__PCl / (1.0 - exp(9.9999999999999995e-8))) : (3612.0012202503358 * (-100.0 * exp(0.037435883507802616 * membrane__Vm) + Cl__Cl_i) * Ito2__PCl * membrane__Vm / (1.0 - exp(0.037435883507802616 * membrane__Vm))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/decker_2009/7_0.png)

Number of singularities:  8
# Model: demir_model_1994(demir_model_1994.cellml)
Number of piecewises: 0
## Equation 1:
```
L_type_Ca_channel_d_gate__alpha_d_L = -28.390000000000001 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)) - 84.900000000000006 * membrane__V / (-1.0 + exp(-0.20799999999999999 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__alpha_d_L = -28.390000000000001 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)) + ((fabs(membrane__V) < 4.8076923076923074e-7) ? (4.0817307692307694e-5 / (-1.0 + exp(9.9999999999999995e-8)) + 1040000.0 * (4.8076923076923074e-7 + membrane__V) * (-4.0817307692307694e-5 / (-1.0 + exp(9.9999999999999995e-8)) - 4.0817307692307694e-5 / (-1.0 + exp(-9.9999999999999995e-8)))) : (-84.900000000000006 * membrane__V / (-1.0 + exp(-0.20799999999999999 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/demir_model_1994/1_0.png)

## Equation 2:
```
L_type_Ca_channel_d_gate__beta_d_L = 11.43 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__beta_d_L = ((fabs(-5.0 + membrane__V) < 2.4999999981289989e-7) ? (2.8575000029373855e-6 / (-1.0 + exp(1.0000000010279565e-7)) - 2000000.0014968009 * (-5.0000002500000003 + membrane__V) * (-2.8574999927855059e-6 / (-1.0 + exp(-9.9999999747524276e-8)) - 2.8575000029373855e-6 / (-1.0 + exp(1.0000000010279565e-7)))) : (11.43 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))))
```
## Singularity point: 5.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/demir_model_1994/2_0.png)

## Equation 3:
```
sodium_current_m_gate__alpha_m = -824.0 * (51.899999999999999 + membrane__V) / (-1.0 + exp(-5.8314606741573032 - 0.11235955056179775 * membrane__V))
```
## New Eq:
```
sodium_current_m_gate__alpha_m = ((fabs(51.899999999999999 + membrane__V) < 8.8999999903194293e-7) ? (0.00073335999627488491 / (-1.0 + exp(9.999999949204822e-8)) + 561797.75342005875 * (51.900000889999994 + membrane__V) * (-0.00073335999627488491 / (-1.0 + exp(9.999999949204822e-8)) - 0.00073336000212975705 / (-1.0 + exp(-1.0000000029041085e-7)))) : (-824.0 * (51.899999999999999 + membrane__V) / (-1.0 + exp(-5.8314606741573032 - 0.11235955056179775 * membrane__V))))
```
## Singularity point: -51.899999999999999
![Singularity](diagrams/new/no_singularity_fixes/demir_model_1994/3_0.png)

## Equation 4:
```
sodium_current__i_Na = pow(membrane__F, 2) * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp((-reversal_potentials__E_Na + membrane__V) * membrane__F / (membrane__R * membrane__T))) * cleft_space_equations__Na_c * membrane__V * sodium_current__P_Na * sodium_current_h_gate__h1 * sodium_current_h_gate__h2 / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
sodium_current__i_Na = ((fabs(membrane__V) < 2.671376065969565e-6) ? (-187169.45411372735 * (-2.671376065969565e-6 + membrane__V) * (-0.0096485341499999988 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(9.9999999999999995e-8 - 1.0 * log(cleft_space_equations__Na_c / intracellular_concentrations_and_buffer_equations__Na_i))) * cleft_space_equations__Na_c * sodium_current__P_Na * sodium_current_h_gate__h1 * sodium_current_h_gate__h2 / (-1.0 + exp(9.9999999999999995e-8)) - 0.0096485341499999988 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - 1.0 * log(cleft_space_equations__Na_c / intracellular_concentrations_and_buffer_equations__Na_i))) * cleft_space_equations__Na_c * sodium_current__P_Na * sodium_current_h_gate__h1 * sodium_current_h_gate__h2 / (-1.0 + exp(-9.9999999999999995e-8))) + 0.0096485341499999988 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(9.9999999999999995e-8 - 1.0 * log(cleft_space_equations__Na_c / intracellular_concentrations_and_buffer_equations__Na_i))) * cleft_space_equations__Na_c * sodium_current__P_Na * sodium_current_h_gate__h1 * sodium_current_h_gate__h2 / (-1.0 + exp(9.9999999999999995e-8))) : (3611.8217397063127 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(0.037433890822745473 * membrane__V - 1.0 * log(cleft_space_equations__Na_c / intracellular_concentrations_and_buffer_equations__Na_i))) * cleft_space_equations__Na_c * membrane__V * sodium_current__P_Na * sodium_current_h_gate__h1 * sodium_current_h_gate__h2 / (-1.0 + exp(0.037433890822745473 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/demir_model_1994/4_0.png)

Number of singularities:  4
# Model: difrancesco_noble_model_1985(difrancesco_noble_model_1985.cellml)
Number of piecewises: 0
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + membrane__V) < 1.0000000010279564e-6) ? (-0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (41.000001000000005 + membrane__V) * (0.00019999999949504854 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)))) : (200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -41.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/difrancesco_noble_model_1985/1_0.png)

## Equation 2:
```
hyperpolarising_activated_current_y_gate__beta_y = (42.0 + membrane__V) / (1.0 - exp(-8.4000000000000004 - 0.20000000000000001 * membrane__V))
```
## New Eq:
```
hyperpolarising_activated_current_y_gate__beta_y = ((fabs(42.0 + membrane__V) < 5.0000000229033503e-7) ? (-5.0000000584304871e-7 / (1.0 - exp(1.0000000116860974e-7)) + 999999.99541932996 * (42.000000500000006 + membrane__V) * (4.9999999873762135e-7 / (1.0 - exp(-9.9999999747524276e-8)) + 5.0000000584304871e-7 / (1.0 - exp(1.0000000116860974e-7)))) : ((42.0 + membrane__V) / (1.0 - exp(-8.4000000000000004 - 0.20000000000000001 * membrane__V))))
```
## Singularity point: -42.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/difrancesco_noble_model_1985/2_0.png)

## Equation 3:
```
second_inward_current_d_gate__alpha_d = 30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))
```
## New Eq:
```
second_inward_current_d_gate__alpha_d = ((fabs(19.0 + membrane__V) < 4.0000000112172529e-7) ? (-1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1249999.9964946085 * (19.000000400000001 + membrane__V) * (1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1.2000000033651759e-5 / (1.0 - exp(-1.0000000028043132e-7)))) : (30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/difrancesco_noble_model_1985/3_0.png)

## Equation 4:
```
second_inward_current_d_gate__beta_d = 12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))
```
## New Eq:
```
second_inward_current_d_gate__beta_d = ((fabs(19.0 + membrane__V) < 1.0000000010279564e-6) ? (1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 499999.99948602181 * (18.999998999999999 + membrane__V) * (-1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 1.2000000012335477e-5 / (-1.0 + exp(-1.0000000010279564e-7)))) : (12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/difrancesco_noble_model_1985/4_0.png)

## Equation 5:
```
second_inward_current__i_siCa = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(100.0 / membrane__RTONF) - extracellular_calcium_concentration__Cao * exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siCa = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (2.0000000001218549e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(-1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/difrancesco_noble_model_1985/5_0.png)

## Equation 6:
```
second_inward_current__i_siK = 0.01 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(50.0 / membrane__RTONF) - extracellular_potassium_concentration__Kc * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siK = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(-1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/difrancesco_noble_model_1985/6_0.png)

## Equation 7:
```
second_inward_current__i_siNa = 0.01 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(50.0 / membrane__RTONF) - extracellular_sodium_concentration__Nao * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siNa = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(-1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/difrancesco_noble_model_1985/7_0.png)

## Equation 8:
```
transient_outward_current__i_to = (10.0 + membrane__V) * (0.20000000000000001 + extracellular_potassium_concentration__Kc / (extracellular_potassium_concentration__Kc + transient_outward_current__Km_to)) * (intracellular_potassium_concentration__Ki * exp(0.5 * membrane__V / membrane__RTONF) - extracellular_potassium_concentration__Kc * exp(-0.5 * membrane__V / membrane__RTONF)) * intracellular_calcium_concentration__Cai * transient_outward_current__g_to * transient_outward_current_s_gate__s / ((1.0 - exp(-2.0 - 0.20000000000000001 * membrane__V)) * (intracellular_calcium_concentration__Cai + transient_outward_current__Km_Ca))
```
## New Eq:
```
transient_outward_current__i_to = ((fabs(10.0 + membrane__V) < 4.9999999962579977e-7) ? (1000000.0007484005 * (10.000000500000001 + membrane__V) * (4.9999999873762135e-7 * (0.20000000000000001 + extracellular_potassium_concentration__Kc / (10.0 + extracellular_potassium_concentration__Kc)) * (intracellular_potassium_concentration__Ki * exp(-0.18716944475525468) - extracellular_potassium_concentration__Kc * exp(0.18716944475525468)) * intracellular_calcium_concentration__Cai * transient_outward_current__g_to * transient_outward_current_s_gate__s / ((1.0 - exp(-9.9999999747524276e-8)) * (0.00050000000000000001 + intracellular_calcium_concentration__Cai)) + 5.0000000051397819e-7 * (0.20000000000000001 + extracellular_potassium_concentration__Kc / (10.0 + extracellular_potassium_concentration__Kc)) * (intracellular_potassium_concentration__Ki * exp(-0.18716946347220006) - extracellular_potassium_concentration__Kc * exp(0.18716946347220006)) * intracellular_calcium_concentration__Cai * transient_outward_current__g_to * transient_outward_current_s_gate__s / ((1.0 - exp(1.0000000010279565e-7)) * (0.00050000000000000001 + intracellular_calcium_concentration__Cai))) - 5.0000000051397819e-7 * (0.20000000000000001 + extracellular_potassium_concentration__Kc / (10.0 + extracellular_potassium_concentration__Kc)) * (intracellular_potassium_concentration__Ki * exp(-0.18716946347220006) - extracellular_potassium_concentration__Kc * exp(0.18716946347220006)) * intracellular_calcium_concentration__Cai * transient_outward_current__g_to * transient_outward_current_s_gate__s / ((1.0 - exp(1.0000000010279565e-7)) * (0.00050000000000000001 + intracellular_calcium_concentration__Cai))) : ((10.0 + membrane__V) * (0.20000000000000001 + extracellular_potassium_concentration__Kc / (10.0 + extracellular_potassium_concentration__Kc)) * (intracellular_potassium_concentration__Ki * exp(0.018716945411372737 * membrane__V) - extracellular_potassium_concentration__Kc * exp(-0.018716945411372737 * membrane__V)) * intracellular_calcium_concentration__Cai * transient_outward_current__g_to * transient_outward_current_s_gate__s / ((1.0 - exp(-2.0 - 0.20000000000000001 * membrane__V)) * (0.00050000000000000001 + intracellular_calcium_concentration__Cai))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/difrancesco_noble_model_1985/8_0.png)

Number of singularities:  8
# Model: dokos_model_1996(dokos_model_1996.cellml)
Number of piecewises: 0
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (34.299999999999997 + membrane__E) / (1.0 - exp(-3.0869999999999997 - 0.089999999999999997 * membrane__E))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(34.299999999999997 + membrane__E) < 1.111111110674301e-6) ? (-0.0002222222221348602 / (1.0 - exp(9.9999999960687092e-8)) + 450000.0001769081 * (34.300001111111108 + membrane__E) * (0.0002222222221348602 / (1.0 - exp(9.9999999960687092e-8)) + 0.0002222222221348602 / (1.0 - exp(-9.9999999960687092e-8)))) : (200.0 * (34.299999999999997 + membrane__E) / (1.0 - exp(-3.0869999999999997 - 0.089999999999999997 * membrane__E))))
```
## Singularity point: -34.299999999999997
![Singularity](diagrams/new/no_singularity_fixes/dokos_model_1996/1_0.png)

## Equation 2:
```
hyperpolarising_activated_current_y_gate__alpha_y = 0.35999999999999999 * (137.80000000000001 + membrane__E) / (-1.0 + exp(9.0948000000000011 + 0.066000000000000003 * membrane__E))
```
## New Eq:
```
hyperpolarising_activated_current_y_gate__alpha_y = ((fabs(137.80000000000001 + membrane__E) < 1.5151515100342294e-6) ? (5.4545453849641483e-7 / (-1.0 + exp(9.9999998724342741e-8)) - 330000.00111454481 * (137.79999848484852 + membrane__E) * (-5.4545453849641483e-7 / (-1.0 + exp(9.9999998724342741e-8)) - 5.4545454872823031e-7 / (-1.0 + exp(-1.0000000060017555e-7)))) : (0.35999999999999999 * (137.80000000000001 + membrane__E) / (-1.0 + exp(9.0948000000000011 + 0.066000000000000003 * membrane__E))))
```
## Singularity point: -137.80000000000001
![Singularity](diagrams/new/no_singularity_fixes/dokos_model_1996/2_0.png)

## Equation 3:
```
hyperpolarising_activated_current_y_gate__beta_y = 0.10000000000000001 * (76.299999999999997 + membrane__E) / (1.0 - exp(-16.023 - 0.20999999999999999 * membrane__E))
```
## New Eq:
```
hyperpolarising_activated_current_y_gate__beta_y = ((fabs(76.299999999999997 + membrane__E) < 4.7619047904845502e-7) ? (-4.7619047904845503e-8 / (1.0 - exp(1.0000000060017555e-7)) + 1049999.9936981567 * (76.300000476190476 + membrane__E) * (4.7619047904845503e-8 / (1.0 - exp(1.0000000060017555e-7)) + 4.7619047904845503e-8 / (1.0 - exp(-1.0000000060017555e-7)))) : (0.10000000000000001 * (76.299999999999997 + membrane__E) / (1.0 - exp(-16.023 - 0.20999999999999999 * membrane__E))))
```
## Singularity point: -76.299999999999997
![Singularity](diagrams/new/no_singularity_fixes/dokos_model_1996/3_0.png)

Number of singularities:  3
# Model: earm_noble_model_1990(earm_noble_model_1990.cellml)
Number of piecewises: 4
## Equation 1:
```
L_type_calcium_current__i_Ca_L_Ca = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 / membrane__RTONF) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) / membrane__RTONF)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d * L_type_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp(2.0 * (50.0 - membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
L_type_calcium_current__i_Ca_L_Ca = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (2.0000000001218549e-7 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-7 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-1.0000000000609274e-7)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-7 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (0.14973556329098189 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/earm_noble_model_1990/1_0.png)

## Equation 2:
```
L_type_calcium_current__i_Ca_L_K = 0.002 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 / membrane__RTONF) - extracellular_potassium_concentration__K_c * exp((50.0 - membrane__V) / membrane__RTONF)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d * L_type_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp((50.0 - membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
L_type_calcium_current__i_Ca_L_K = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (2.0000000001218549e-10 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(1.0000000000609274e-7)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-10 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(-1.0000000000609274e-7)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-10 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(1.0000000000609274e-7)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (7.4867781645490941e-5 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/earm_noble_model_1990/2_0.png)

## Equation 3:
```
L_type_calcium_current__i_Ca_L_Na = 0.01 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 / membrane__RTONF) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) / membrane__RTONF)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d * L_type_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp((50.0 - membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
L_type_calcium_current__i_Ca_L_Na = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-1.0000000000609274e-7)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/earm_noble_model_1990/3_0.png)

Number of singularities:  3
# Model: espinosa_model_1998(espinosa_model_1998_normal.cellml)
Number of piecewises: 1
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/espinosa_model_1998_normal/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K_ds = (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K_ds = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (3.0000000001827821e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 3.0000000001827821e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 3.0000000001827821e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00011230167246823642 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/espinosa_model_1998_normal/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_Na_ds = (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na_ds = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/espinosa_model_1998_normal/3_0.png)

## Equation 4:
```
L_type_Ca_channel_d_gate__alpha_d = 30.0 * (4.0 + membrane__V) / (1.0 - exp(-1.3333333333333333 - 0.33333333333333331 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__alpha_d = ((fabs(4.0 + membrane__V) < 2.9999999995311555e-7) ? (-8.9999999985934664e-6 / (1.0 - exp(9.9999999984371854e-8)) + 1666666.6669271358 * (4.0000003 + membrane__V) * (8.9999999985934664e-6 / (1.0 - exp(9.9999999984371854e-8)) + 8.9999999985934664e-6 / (1.0 - exp(-9.9999999984371854e-8)))) : (30.0 * (4.0 + membrane__V) / (1.0 - exp(-1.3333333333333333 - 0.33333333333333331 * membrane__V))))
```
## Singularity point: -4.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/espinosa_model_1998_normal/4_0.png)

## Equation 5:
```
L_type_Ca_channel_d_gate__beta_d = 12.0 * (4.0 + membrane__V) / (-1.0 + exp(0.53333333333333333 + 0.13333333333333333 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__beta_d = ((fabs(4.0 + membrane__V) < 7.4999999988278887e-7) ? (8.9999999985934664e-6 / (-1.0 + exp(9.9999999984371854e-8)) - 666666.66677085438 * (3.9999992500000001 + membrane__V) * (-8.9999999985934664e-6 / (-1.0 + exp(9.9999999984371854e-8)) - 8.9999999985934664e-6 / (-1.0 + exp(-9.9999999984371854e-8)))) : (12.0 * (4.0 + membrane__V) / (-1.0 + exp(0.53333333333333333 + 0.13333333333333333 * membrane__V))))
```
## Singularity point: -4.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/espinosa_model_1998_normal/5_0.png)

## Equation 6:
```
L_type_Ca_channel_f_gate__alpha_f = 6.25 * (24.0 + membrane__V) / (-1.0 + exp(4.3636363636363633 + 0.18181818181818182 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_f_gate__alpha_f = ((fabs(24.0 + membrane__V) < 5.4999999932192623e-7) ? (3.4374999957620389e-6 / (-1.0 + exp(9.999999987671386e-8)) - 909090.91021169221 * (23.999999450000001 + membrane__V) * (-3.4374999957620389e-6 / (-1.0 + exp(9.999999987671386e-8)) - 3.4374999957620389e-6 / (-1.0 + exp(-9.999999987671386e-8)))) : (6.25 * (24.0 + membrane__V) / (-1.0 + exp(4.3636363636363633 + 0.18181818181818182 * membrane__V))))
```
## Singularity point: -24.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/espinosa_model_1998_normal/6_0.png)

## Equation 7:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + membrane__V) < 1.0000000010279564e-6) ? (-0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (41.000001000000005 + membrane__V) * (0.00019999999949504854 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)))) : (200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -41.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/espinosa_model_1998_normal/7_0.png)

## Equation 8:
```
time_dependent_potassium_current_x_gate__alpha_x = 1.5 * (-18.0 + membrane__V) / (1.0 - exp(3.6000000000000001 - 0.20000000000000001 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_x_gate__alpha_x = ((fabs(-18.0 + membrane__V) < 4.9999999873762135e-7) ? (-7.4999999810643203e-7 / (1.0 - exp(9.9999999747524276e-8)) + 1000000.0025247573 * (-17.999999500000001 + membrane__V) * (7.4999999810643203e-7 / (1.0 - exp(9.9999999747524276e-8)) + 7.4999999810643203e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (1.5 * (-18.0 + membrane__V) / (1.0 - exp(3.6000000000000001 - 0.20000000000000001 * membrane__V))))
```
## Singularity point: 18.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/espinosa_model_1998_normal/8_0.png)

## Equation 9:
```
time_dependent_potassium_current_x_gate__beta_x = 0.53400000000000003 * (-18.0 + membrane__V) / (-1.0 + exp(-1.2 + 0.066666666666666666 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_x_gate__beta_x = ((fabs(-18.0 + membrane__V) < 1.4999999997655777e-6) ? (8.0099999987481852e-7 / (-1.0 + exp(9.9999999984371854e-8)) - 333333.33338542719 * (-18.0000015 + membrane__V) * (-8.0099999987481852e-7 / (-1.0 + exp(9.9999999984371854e-8)) - 8.0099999987481852e-7 / (-1.0 + exp(-9.9999999984371854e-8)))) : (0.53400000000000003 * (-18.0 + membrane__V) / (-1.0 + exp(-1.2 + 0.066666666666666666 * membrane__V))))
```
## Singularity point: 18.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/espinosa_model_1998_normal/9_0.png)

Number of singularities:  9
# Model: faber_rudy_2000(faber_rudy_2000.cellml)
Number of piecewises: 13
## Equation 1:
```
L_type_Ca_channel__I_CaCa = 4.0 * pow(cell__F, 2) * (-L_type_Ca_channel__gamma_Cao * calcium_dynamics__Cao + L_type_Ca_channel__gamma_Cai * calcium_dynamics__Cai * exp(2.0 * cell__F * cell__V / (cell__R * cell__T))) * L_type_Ca_channel__P_Ca * cell__V / ((-1.0 + exp(2.0 * cell__F * cell__V / (cell__R * cell__T))) * cell__R * cell__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaCa = ((fabs(cell__V) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + cell__V) * (-0.019296999999999998 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_Ca / (-1.0 + exp(9.9999999999999995e-8)) - 0.019296999999999998 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_Ca / (-1.0 + exp(-9.9999999999999995e-8))) + 0.019296999999999998 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_Ca / (-1.0 + exp(9.9999999999999995e-8))) : (14448.004881001343 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(0.074871767015605231 * cell__V)) * L_type_Ca_channel__P_Ca * cell__V / (-1.0 + exp(0.074871767015605231 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/1_0.png)

## Equation 2:
```
L_type_Ca_channel_d_gate__tau_d = 28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * cell__V)) * L_type_Ca_channel_d_gate__d_infinity / (10.0 + cell__V)
```
## New Eq:
```
L_type_Ca_channel_d_gate__tau_d = ((fabs(10.0 + cell__V) < 6.2400000011564316e-7) ? (801282.05113355326 * (10.000000624 + cell__V) * (45787545.779060178 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7)) + 45787545.779060178 * (1.0 - exp(-1.0000000001853256e-7)) / (1.0 + exp(-1.0000000001853256e-7))) - 45787545.779060178 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7))) : (28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * cell__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * cell__V)) * (10.0 + cell__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/2_0.png)

## Equation 3:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/3_0.png)

## Equation 4:
```
L_type_Ca_channel__I_CaK = pow(cell__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(cell__F * cell__V / (cell__R * cell__T))) * L_type_Ca_channel__P_K * cell__V / ((-1.0 + exp(cell__F * cell__V / (cell__R * cell__T))) * cell__R * cell__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaK = ((fabs(cell__V) < 2.6712338705498262e-6) ? (1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + cell__V) * (-1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.00069711623550831479 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/4_0.png)

## Equation 5:
```
L_type_Ca_channel__I_CaNa = pow(cell__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(cell__F * cell__V / (cell__R * cell__T))) * L_type_Ca_channel__P_Na * cell__V / ((-1.0 + exp(cell__F * cell__V / (cell__R * cell__T))) * cell__R * cell__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaNa = ((fabs(cell__V) < 2.6712338705498262e-6) ? (6.5127374999999992e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + cell__V) * (-6.5127374999999992e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 6.5127374999999992e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.0024381008236689767 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/5_0.png)

## Equation 6:
```
non_specific_calcium_activated_current__I_ns_K = pow(cell__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(cell__F * cell__V / (cell__R * cell__T))) * cell__V * non_specific_calcium_activated_current__P_ns_Ca / ((-1.0 + exp(cell__F * cell__V / (cell__R * cell__T))) * cell__R * cell__T)
```
## New Eq:
```
non_specific_calcium_activated_current__I_ns_K = ((fabs(cell__V) < 2.6712338705498262e-6) ? (1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + cell__V) * (-1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.00063210021354380874 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/6_0.png)

## Equation 7:
```
non_specific_calcium_activated_current__I_ns_Na = pow(cell__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(cell__F * cell__V / (cell__R * cell__T))) * cell__V * non_specific_calcium_activated_current__P_ns_Ca / ((-1.0 + exp(cell__F * cell__V / (cell__R * cell__T))) * cell__R * cell__T)
```
## New Eq:
```
non_specific_calcium_activated_current__I_ns_Na = ((fabs(cell__V) < 2.6712338705498262e-6) ? (1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + cell__V) * (-1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.00063210021354380874 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/7_0.png)

## Equation 8:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 1 / (0.00060999999999999997 * (38.899999999999999 + cell__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * cell__V)) + 0.0013799999999999999 * (14.199999999999999 + cell__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * cell__V)))
```
## New Eq:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 1 / (((fabs(38.899999999999999 + cell__V) < 6.8965517030505907e-7) ? (4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)) - 725000.00221680664 * (38.899999310344825 + cell__V) * (-4.2068965171893065e-10 / (-1.0 + exp(-9.9999999179090074e-8)) - 4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)))) : (0.00060999999999999997 * (38.899999999999999 + cell__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * cell__V)))) + ((fabs(14.199999999999999 + cell__V) < 8.1300813015161566e-7) ? (-1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 614999.99994681031 * (14.200000813008129 + cell__V) * (1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 1.1219512196092296e-9 / (1.0 - exp(-1.0000000000864873e-7)))) : (0.0013799999999999999 * (14.199999999999999 + cell__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * cell__V)))))
```
## Singularity point: -14.199999999999999
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/8_0.png)
## Singularity point: -38.899999999999999
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/8_1.png)

## Equation 9:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = 1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = ((fabs(30.0 + cell__V) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + cell__V) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/9_0.png)

## Equation 10:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 4.0 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 4.0 * ((fabs(30.0 + cell__V) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + cell__V) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/faber_rudy_2000/10_0.png)

Number of singularities:  11
# Model: fink_noble_giles_model_2008(fink_noble_giles_model_2008.cellml)
Number of piecewises: 4
## Equation 1:
```
ICaL__i_CaL = pow(Environment__F, 2) * pow(ICaL__z, 2) * (-15.0 + cell__V) * (-Environment__Ca_o + 0.25 * Ca__Ca_ss * exp(2.0 * (-15.0 + cell__V) * Environment__F / (Environment__R * Environment__T))) * ICaL__g_CaL * iCaL_d_gate__d * iCaL_f2_gate__f2 * iCaL_fCass_gate__fCass * iCaL_f_gate__f / ((-1.0 + exp(2.0 * (-15.0 + cell__V) * Environment__F / (Environment__R * Environment__T))) * Environment__R * Environment__T)
```
## New Eq:
```
ICaL__i_CaL = ((fabs(-15.0 + cell__V) < 1.3356880330661625e-6) ? (-374338.90820464725 * (-15.000001335688033 + cell__V) * (-0.01929706830117572 * (-Environment__Ca_o + 0.25 * Ca__Ca_ss * exp(1.0000000000609274e-7)) * ICaL__g_CaL * iCaL_d_gate__d * iCaL_f2_gate__f2 * iCaL_fCass_gate__fCass * iCaL_f_gate__f / (-1.0 + exp(1.0000000000609274e-7)) - 0.01929706830117572 * (-Environment__Ca_o + 0.25 * Ca__Ca_ss * exp(-1.0000000000609274e-7)) * ICaL__g_CaL * iCaL_d_gate__d * iCaL_f2_gate__f2 * iCaL_fCass_gate__fCass * iCaL_f_gate__f / (-1.0 + exp(-1.0000000000609274e-7))) + 0.01929706830117572 * (-Environment__Ca_o + 0.25 * Ca__Ca_ss * exp(1.0000000000609274e-7)) * ICaL__g_CaL * iCaL_d_gate__d * iCaL_f2_gate__f2 * iCaL_fCass_gate__fCass * iCaL_f_gate__f / (-1.0 + exp(1.0000000000609274e-7))) : (14447.286958825251 * (-15.0 + cell__V) * (-Environment__Ca_o + 0.25 * Ca__Ca_ss * exp(-1.1230167246823641 + 0.074867781645490947 * cell__V)) * ICaL__g_CaL * iCaL_d_gate__d * iCaL_f2_gate__f2 * iCaL_fCass_gate__fCass * iCaL_f_gate__f / (-1.0 + exp(-1.1230167246823641 + 0.074867781645490947 * cell__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/fink_noble_giles_model_2008/1_0.png)

Number of singularities:  1
# Model: fox_model_2001(fox_mcharg_gilmour_2002.cellml)
Number of piecewises: 0
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * fast_sodium_current_m_gate__E0_m / (1.0 - exp(-0.10000000000000001 * fast_sodium_current_m_gate__E0_m))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/fox_mcharg_gilmour_2002/1_0.png)

## Equation 2:
```
slow_activating_delayed_rectifiyer_K_current_X_ks_gate__tau_X_ks = 1 / (0.00013100000000000001 * (-10.0 + membrane__V) / (-1.0 + exp(-0.68699999999999994 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (-10.0 + membrane__V) / (1.0 - exp(1.48 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_activating_delayed_rectifiyer_K_current_X_ks_gate__tau_X_ks = ((fabs(-10.0 + membrane__V) < 1.4556040763835654e-6) ? (1 / (-1.0465793309197835e-10 / (1.0 - exp(2.1542940330476766e-7)) - 1.9068413400624708e-10 / (-1.0 + exp(-1.0000000004755094e-7)) + 343499.99983666249 * (-9.9999985443959236 + membrane__V) * (1.0465793309197835e-10 / (1.0 - exp(2.1542940330476766e-7)) + 1.0465793309197835e-10 / (1.0 - exp(-2.1542940330476766e-7)) + 1.9068413400624708e-10 / (-1.0 + exp(1.0000000004755094e-7)) + 1.9068413400624708e-10 / (-1.0 + exp(-1.0000000004755094e-7))))) : (1 / (0.00013100000000000001 * (-10.0 + membrane__V) / (-1.0 + exp(-0.68699999999999994 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (-10.0 + membrane__V) / (1.0 - exp(1.48 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: 10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/fox_mcharg_gilmour_2002/2_0.png)

## Equation 3:
```
L_type_Ca_current__i_Ca_max = 4.0 * pow(membrane__F, 2) * (-0.34100000000000003 * standard_ionic_concentrations__Ca_o + calcium_dynamics__Ca_i * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__P_Ca * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__C_sc * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_Ca_max = ((fabs(membrane__V) < 1.3354093264248706e-6) ? (-374417.03461708582 * (-1.3354093264248706e-6 + membrane__V) * (-1.9300000000000002e-5 * (-0.34100000000000003 * standard_ionic_concentrations__Ca_o + calcium_dynamics__Ca_i * exp(1.0000000000000001e-7)) * L_type_Ca_current__P_Ca / (-1.0 + exp(1.0000000000000001e-7)) - 1.9300000000000002e-5 * (-0.34100000000000003 * standard_ionic_concentrations__Ca_o + calcium_dynamics__Ca_i * exp(-1.0000000000000001e-7)) * L_type_Ca_current__P_Ca / (-1.0 + exp(-1.0000000000000001e-7))) + 1.9300000000000002e-5 * (-0.34100000000000003 * standard_ionic_concentrations__Ca_o + calcium_dynamics__Ca_i * exp(1.0000000000000001e-7)) * L_type_Ca_current__P_Ca / (-1.0 + exp(1.0000000000000001e-7))) : (14.452497536219512 * (-0.34100000000000003 * standard_ionic_concentrations__Ca_o + calcium_dynamics__Ca_i * exp(0.074883406923417162 * membrane__V)) * L_type_Ca_current__P_Ca * membrane__V / (-1.0 + exp(0.074883406923417162 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/fox_mcharg_gilmour_2002/3_0.png)

## Equation 4:
```
L_type_Ca_current__i_CaK = 1000.0 * pow(membrane__F, 2) * (-standard_ionic_concentrations__K_o + standard_ionic_concentrations__K_i * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__P_CaK * L_type_Ca_current_d_gate__d * L_type_Ca_current_f_Ca_gate__f_Ca * L_type_Ca_current_f_gate__f * membrane__V / ((1.0 + L_type_Ca_current__i_Ca_max / L_type_Ca_current__i_Ca_half) * (-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__C_sc * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_CaK = ((fabs(membrane__V) < 2.6708186528497411e-6) ? (-187208.51730854291 * (-2.6708186528497411e-6 + membrane__V) * (-5.5873500000000006e-9 * (-standard_ionic_concentrations__K_o + standard_ionic_concentrations__K_i * exp(1.0000000000000001e-7)) * L_type_Ca_current_d_gate__d * L_type_Ca_current_f_Ca_gate__f_Ca * L_type_Ca_current_f_gate__f / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(1.0000000000000001e-7))) - 5.5873500000000006e-9 * (-standard_ionic_concentrations__K_o + standard_ionic_concentrations__K_i * exp(-1.0000000000000001e-7)) * L_type_Ca_current_d_gate__d * L_type_Ca_current_f_Ca_gate__f_Ca * L_type_Ca_current_f_gate__f / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(-1.0000000000000001e-7)))) + 5.5873500000000006e-9 * (-standard_ionic_concentrations__K_o + standard_ionic_concentrations__K_i * exp(1.0000000000000001e-7)) * L_type_Ca_current_d_gate__d * L_type_Ca_current_f_Ca_gate__f_Ca * L_type_Ca_current_f_gate__f / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(1.0000000000000001e-7)))) : (0.0020919990183677745 * (-standard_ionic_concentrations__K_o + standard_ionic_concentrations__K_i * exp(0.037441703461708581 * membrane__V)) * L_type_Ca_current_d_gate__d * L_type_Ca_current_f_Ca_gate__f_Ca * L_type_Ca_current_f_gate__f * membrane__V / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(0.037441703461708581 * membrane__V)))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/fox_mcharg_gilmour_2002/4_0.png)
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/fox_mcharg_gilmour_2002/4_1.png)

Number of singularities:  4
# Model: grandi_pasqualini_bers_2010(grandi_pasqualini_bers_2010_ss.cellml)
Number of piecewises: 6
## Equation 1:
```
I_Ca__taud = 28.571428571428569 * (1.0 - exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) * I_Ca__dss / (5.0 + membrane_potential__V_m)
```
## New Eq:
```
I_Ca__taud = ((fabs(5.0 + membrane_potential__V_m) < 5.999999999062311e-7) ? (833333.33346356789 * (5.0000005999999999 + membrane_potential__V_m) * (47619047.626489595 * (1.0 - exp(9.9999999984371854e-8)) / (1.0 + exp(9.9999999984371854e-8)) + 47619047.626489595 * (1.0 - exp(-9.9999999984371854e-8)) / (1.0 + exp(-9.9999999984371854e-8))) - 47619047.626489595 * (1.0 - exp(9.9999999984371854e-8)) / (1.0 + exp(9.9999999984371854e-8))) : (28.571428571428569 * (1.0 - exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) / ((1.0 + exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) * (5.0 + membrane_potential__V_m))))
```
## Singularity point: -5.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss/1_0.png)

## Equation 2:
```
I_Ca__ibarca_j = 4.0 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(2.0 * membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pCa / (-1.0 + exp(2.0 * membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarca_j = ((fabs(membrane_potential__V_m) < 4.9999999999999998e-8 * fabs(parameters__R * parameters__Temp / parameters__Frdy)) ? (1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * parameters__R * parameters__Temp / parameters__Frdy + membrane_potential__V_m) * (-1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8)) - 1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8))) * parameters__Frdy / (parameters__R * parameters__Temp)) : (0.00216 * pow(parameters__Frdy, 2) * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(2.0 * membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * membrane_potential__V_m * parameters__pCa_max / ((-1.0 + exp(2.0 * membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * parameters__R * parameters__Temp)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss/2_0.png)

## Equation 3:
```
I_Ca__ibarca_sl = 4.0 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(2.0 * membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pCa / (-1.0 + exp(2.0 * membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarca_sl = ((fabs(membrane_potential__V_m) < 4.9999999999999998e-8 * fabs(parameters__R * parameters__Temp / parameters__Frdy)) ? (1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * parameters__R * parameters__Temp / parameters__Frdy + membrane_potential__V_m) * (-1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8)) - 1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8))) * parameters__Frdy / (parameters__R * parameters__Temp)) : (0.00216 * pow(parameters__Frdy, 2) * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(2.0 * membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * membrane_potential__V_m * parameters__pCa_max / ((-1.0 + exp(2.0 * membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * parameters__R * parameters__Temp)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss/3_0.png)

## Equation 4:
```
I_Ca__ibark = (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pK / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibark = ((fabs(membrane_potential__V_m) < 9.9999999999999995e-8 * fabs(parameters__R * parameters__Temp / parameters__Frdy)) ? (1.3499999999999999e-14 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * parameters__R * parameters__Temp / parameters__Frdy + membrane_potential__V_m) * (-1.3499999999999999e-14 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(9.9999999999999995e-8)) - 1.3499999999999999e-14 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(-9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(-9.9999999999999995e-8))) * parameters__Frdy / (parameters__R * parameters__Temp)) : (1.35e-7 * pow(parameters__Frdy, 2) * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * membrane_potential__V_m / ((-1.0 + exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * parameters__R * parameters__Temp)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss/4_0.png)

## Equation 5:
```
I_Ca__ibarna_j = (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pNa / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarna_j = ((fabs(membrane_potential__V_m) < 9.9999999999999995e-8 * fabs(parameters__R * parameters__Temp / parameters__Frdy)) ? (7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * parameters__R * parameters__Temp / parameters__Frdy + membrane_potential__V_m) * (-7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(9.9999999999999995e-8)) - 7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(-9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(-9.9999999999999995e-8))) * parameters__Frdy / (parameters__R * parameters__Temp)) : (7.4999999999999993e-9 * pow(parameters__Frdy, 2) * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * membrane_potential__V_m / ((-1.0 + exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * parameters__R * parameters__Temp)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss/5_0.png)

## Equation 6:
```
I_Ca__ibarna_sl = (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pNa / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarna_sl = ((fabs(membrane_potential__V_m) < 9.9999999999999995e-8 * fabs(parameters__R * parameters__Temp / parameters__Frdy)) ? (7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * parameters__R * parameters__Temp / parameters__Frdy + membrane_potential__V_m) * (-7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(9.9999999999999995e-8)) - 7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(-9.9999999999999995e-8))) * parameters__Frdy / (parameters__R * parameters__Temp)) : (7.4999999999999993e-9 * pow(parameters__Frdy, 2) * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * membrane_potential__V_m / ((-1.0 + exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * parameters__R * parameters__Temp)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss/6_0.png)

Number of singularities:  6
# Model: grandi_pasqualini_bers_2010(grandi_pasqualini_bers_2010_ss_endo.cellml)
Number of piecewises: 6
## Equation 1:
```
I_Ca__taud = 28.571428571428569 * (1.0 - exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) * I_Ca__dss / (5.0 + membrane_potential__V_m)
```
## New Eq:
```
I_Ca__taud = ((fabs(5.0 + membrane_potential__V_m) < 5.999999999062311e-7) ? (833333.33346356789 * (5.0000005999999999 + membrane_potential__V_m) * (47619047.626489595 * (1.0 - exp(9.9999999984371854e-8)) / (1.0 + exp(9.9999999984371854e-8)) + 47619047.626489595 * (1.0 - exp(-9.9999999984371854e-8)) / (1.0 + exp(-9.9999999984371854e-8))) - 47619047.626489595 * (1.0 - exp(9.9999999984371854e-8)) / (1.0 + exp(9.9999999984371854e-8))) : (28.571428571428569 * (1.0 - exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) / ((1.0 + exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) * (5.0 + membrane_potential__V_m))))
```
## Singularity point: -5.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss_endo/1_0.png)

## Equation 2:
```
I_Ca__ibarca_j = 4.0 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(2.0 * membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pCa / (-1.0 + exp(2.0 * membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarca_j = ((fabs(membrane_potential__V_m) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + membrane_potential__V_m) * (-1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8)) - 1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8))) + 1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8))) : (7.8019226357407252 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(0.074871767015605231 * membrane_potential__V_m)) * membrane_potential__V_m * parameters__pCa_max / (-1.0 + exp(0.074871767015605231 * membrane_potential__V_m))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss_endo/2_0.png)

## Equation 3:
```
I_Ca__ibarca_sl = 4.0 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(2.0 * membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pCa / (-1.0 + exp(2.0 * membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarca_sl = ((fabs(membrane_potential__V_m) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + membrane_potential__V_m) * (-1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8)) - 1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8))) + 1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8))) : (7.8019226357407252 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(0.074871767015605231 * membrane_potential__V_m)) * membrane_potential__V_m * parameters__pCa_max / (-1.0 + exp(0.074871767015605231 * membrane_potential__V_m))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss_endo/3_0.png)

## Equation 4:
```
I_Ca__ibark = (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pK / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibark = ((fabs(membrane_potential__V_m) < 2.6712338705498262e-6) ? (1.3025475e-9 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + membrane_potential__V_m) * (-1.3025475e-9 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 1.3025475e-9 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.00048762016473379531 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(0.037435883507802616 * membrane_potential__V_m)) * membrane_potential__V_m / (-1.0 + exp(0.037435883507802616 * membrane_potential__V_m))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss_endo/4_0.png)

## Equation 5:
```
I_Ca__ibarna_j = (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pNa / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarna_j = ((fabs(membrane_potential__V_m) < 2.6712338705498262e-6) ? (7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + membrane_potential__V_m) * (-7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (2.7090009151877515e-5 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(0.037435883507802616 * membrane_potential__V_m)) * membrane_potential__V_m / (-1.0 + exp(0.037435883507802616 * membrane_potential__V_m))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss_endo/5_0.png)

## Equation 6:
```
I_Ca__ibarna_sl = (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pNa / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarna_sl = ((fabs(membrane_potential__V_m) < 2.6712338705498262e-6) ? (7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + membrane_potential__V_m) * (-7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (2.7090009151877515e-5 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(0.037435883507802616 * membrane_potential__V_m)) * membrane_potential__V_m / (-1.0 + exp(0.037435883507802616 * membrane_potential__V_m))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/grandi_pasqualini_bers_2010_ss_endo/6_0.png)

Number of singularities:  6
# Model: hilgemann_noble_model_1987(hilgemann_noble_model_1987.cellml)
Number of piecewises: 0
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + membrane__V) < 1.0000000010279564e-6) ? (-0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (41.000001000000005 + membrane__V) * (0.00019999999949504854 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)))) : (200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -41.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/hilgemann_noble_model_1987/1_0.png)

## Equation 2:
```
second_inward_calcium_current_d_gate__alpha_d = 30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))
```
## New Eq:
```
second_inward_calcium_current_d_gate__alpha_d = ((fabs(19.0 + membrane__V) < 4.0000000112172529e-7) ? (-1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1249999.9964946085 * (19.000000400000001 + membrane__V) * (1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1.2000000033651759e-5 / (1.0 - exp(-1.0000000028043132e-7)))) : (30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/hilgemann_noble_model_1987/2_0.png)

## Equation 3:
```
second_inward_calcium_current_d_gate__beta_d = 12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))
```
## New Eq:
```
second_inward_calcium_current_d_gate__beta_d = ((fabs(19.0 + membrane__V) < 1.0000000010279564e-6) ? (1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 499999.99948602181 * (18.999998999999999 + membrane__V) * (-1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 1.2000000012335477e-5 / (-1.0 + exp(-1.0000000010279564e-7)))) : (12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/hilgemann_noble_model_1987/3_0.png)

## Equation 4:
```
second_inward_calcium_current__i_siCa = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 / membrane__RTONF) - extracellular_calcium_concentration__Ca_o * exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d * second_inward_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_calcium_current__i_siCa = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (2.0000000001218549e-7 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-7 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-1.0000000000609274e-7)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-7 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (0.14973556329098189 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/hilgemann_noble_model_1987/4_0.png)

## Equation 5:
```
second_inward_calcium_current__i_siK = 0.002 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 / membrane__RTONF) - extracellular_potassium_concentration__K_c * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d * second_inward_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_calcium_current__i_siK = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (2.0000000001218549e-10 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(1.0000000000609274e-7)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-10 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(-1.0000000000609274e-7)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-10 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(1.0000000000609274e-7)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (7.4867781645490941e-5 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/hilgemann_noble_model_1987/5_0.png)

## Equation 6:
```
second_inward_calcium_current__i_siNa = 0.01 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 / membrane__RTONF) - extracellular_sodium_concentration__Na_o * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d * second_inward_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_calcium_current__i_siNa = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-1.0000000000609274e-7)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/hilgemann_noble_model_1987/6_0.png)

Number of singularities:  6
# Model: hodgkin_huxley_squid_axon_model_1952_modified(hodgkin_huxley_squid_axon_model_1952_modified.cellml)
Number of piecewises: 0
Number of singularities:  0
# Model: HundRudy2004_units(hund_rudy_2004.cellml)
Number of piecewises: 7
## Equation 1:
```
ICaL__ibarca = 4.0 * (-15.0 + cell__V) * (-Environment__Ca_o * ICaL__gacao + Ca__Ca_ss * ICaL__gacai * exp(2.0 * (-15.0 + cell__V) * Environment__FonRT)) * Environment__F * Environment__FonRT * ICaL__pca / (-1.0 + exp(2.0 * (-15.0 + cell__V) * Environment__FonRT))
```
## New Eq:
```
ICaL__ibarca = ((fabs(-15.0 + cell__V) < 1.3356169352718439e-6) ? (-374358.83507888648 * (-15.000001335616936 + cell__V) * (-0.0192969999871219 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-9.9999999933263712e-8)) * ICaL__pca / (-1.0 + exp(-9.9999999933263712e-8)) - 0.019297000012786711 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(1.0000000006626268e-7)) * ICaL__pca / (-1.0 + exp(1.0000000006626268e-7))) + 0.019297000012786711 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(1.0000000006626268e-7)) * ICaL__pca / (-1.0 + exp(1.0000000006626268e-7))) : (14448.004881000332 * (-15.0 + cell__V) * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-1.1230765052339999 + 0.074871767015599999 * cell__V)) * ICaL__pca / (-1.0 + exp(-1.1230765052339999 + 0.074871767015599999 * cell__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/hund_rudy_2004/1_0.png)

## Equation 2:
```
ICab__ICab = 7.9803360000000004e-7 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(2.0 * Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * cell__V / (-1.0 + exp(2.0 * Environment__FonRT * cell__V))
```
## New Eq:
```
ICab__ICab = ((fabs(cell__V) < 1.3356169352750067e-6) ? (3.8499135948000005e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(1.0000000000000001e-7)) / (-1.0 + exp(1.0000000000000001e-7)) - 374358.83507799997 * (-1.3356169352750067e-6 + cell__V) * (-3.8499135948000005e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(1.0000000000000001e-7)) / (-1.0 + exp(1.0000000000000001e-7)) - 3.8499135948000005e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(-1.0000000000000001e-7)) / (-1.0 + exp(-1.0000000000000001e-7)))) : (0.0028824983370005666 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(0.074871767015599999 * cell__V)) * cell__V / (-1.0 + exp(0.074871767015599999 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/hund_rudy_2004/2_0.png)

## Equation 3:
```
IKr__tauxr = 1 / (0.00029999999999999997 * (38.360799999999998 + cell__V) / (-1.0 + exp(5.8385137599999997 + 0.1522 * cell__V)) + 0.00059999999999999995 * (-1.7383999999999999 + cell__V) / (1.0 - exp(0.2364224 - 0.13600000000000001 * cell__V)))
```
## New Eq:
```
IKr__tauxr = 1 / (((fabs(38.360799999999998 + cell__V) < 6.5703022045227044e-7) ? (1.9710906613568111e-10 / (-1.0 + exp(9.9999999552835566e-8)) - 761000.00340292137 * (38.360799342969777 + cell__V) * (-1.9710906613568111e-10 / (-1.0 + exp(9.9999999552835566e-8)) - 1.9710906613568111e-10 / (-1.0 + exp(-9.9999999552835566e-8)))) : (0.00029999999999999997 * (38.360799999999998 + cell__V) / (-1.0 + exp(5.8385137599999997 + 0.1522 * cell__V)))) + ((fabs(-1.7384000000000002 + cell__V) < 7.3529411770412167e-7) ? (-4.4117647055585959e-10 / (1.0 - exp(9.9999999992661527e-8)) + 679999.99994722824 * (-1.7383992647058824 + cell__V) * (4.4117647055585959e-10 / (1.0 - exp(9.9999999992661527e-8)) + 4.4117647068908634e-10 / (1.0 - exp(-1.0000000002285959e-7)))) : (0.00059999999999999995 * (-1.7383999999999999 + cell__V) / (1.0 - exp(0.2364224 - 0.13600000000000001 * cell__V)))))
```
## Singularity point: -38.360799999999998
![Singularity](diagrams/new/no_singularity_fixes/hund_rudy_2004/3_0.png)
## Singularity point: 1.7384000000000002
![Singularity](diagrams/new/no_singularity_fixes/hund_rudy_2004/3_1.png)

## Equation 4:
```
IKs__tauxs = 1 / (7.6100000000000007e-5 * (44.600000000000001 + cell__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * cell__V)) + 0.00036000000000000002 * (-0.55000000000000004 + cell__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * cell__V)))
```
## New Eq:
```
IKs__tauxs = 1 / (((fabs(-0.55000000000000004 + cell__V) < 7.8125000002593481e-7) ? (2.8125000000933653e-10 / (-1.0 + exp(1.0000000000331966e-7)) - 639999.9999787542 * (-0.55000078125000007 + cell__V) * (-2.8125000000933653e-10 / (-1.0 + exp(1.0000000000331966e-7)) - 2.8125000000933653e-10 / (-1.0 + exp(-1.0000000000331966e-7)))) : (0.00036000000000000002 * (-0.55000000000000004 + cell__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * cell__V)))) + ((fabs(44.600000000000001 + cell__V) < 1.0030088759549471e-8) ? (-7.6329002496322579e-13 / (1.0 - exp(1.0000002035326362e-7)) + 49850007.511046082 * (44.600000010030094 + cell__V) * (7.6329002496322579e-13 / (1.0 - exp(1.0000002035326362e-7)) + 7.6328948424020387e-13 / (1.0 - exp(-9.9999949512152856e-8)))) : (7.6100000000000007e-5 * (44.600000000000001 + cell__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * cell__V)))))
```
## Singularity point: 0.55000000000000004
![Singularity](diagrams/new/no_singularity_fixes/hund_rudy_2004/4_0.png)
## Singularity point: -44.600000000000001
![Singularity](diagrams/new/no_singularity_fixes/hund_rudy_2004/4_1.png)

## Equation 5:
```
INa__am = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa__am = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/hund_rudy_2004/5_0.png)

## Equation 6:
```
INal__amL = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INal__amL = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/hund_rudy_2004/6_0.png)

## Equation 7:
```
Ito2__Ito2_max = (-Environment__Cl_o * exp(Environment__FonRT * cell__V) + Cl__Cl_i) * Environment__F * Environment__FonRT * Ito2__PCl * cell__V / (1.0 - exp(Environment__FonRT * cell__V))
```
## New Eq:
```
Ito2__Ito2_max = ((fabs(cell__V) < 2.6712338705500134e-6) ? (3.8594000000000001e-9 * (-Environment__Cl_o * exp(1.0000000000000001e-7) + Cl__Cl_i) / (1.0 - exp(1.0000000000000001e-7)) - 187179.41753899999 * (-2.6712338705500134e-6 + cell__V) * (-3.8594000000000001e-9 * (-Environment__Cl_o * exp(1.0000000000000001e-7) + Cl__Cl_i) / (1.0 - exp(1.0000000000000001e-7)) - 3.8594000000000001e-9 * (-Environment__Cl_o * exp(-1.0000000000000001e-7) + Cl__Cl_i) / (1.0 - exp(-1.0000000000000001e-7)))) : (0.001444800488100033 * (-Environment__Cl_o * exp(0.0374358835078 * cell__V) + Cl__Cl_i) * cell__V / (1.0 - exp(0.0374358835078 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/hund_rudy_2004/7_0.png)

Number of singularities:  9
# Model: iribe_model_2006(iribe_model_2006.cellml)
Number of piecewises: 1
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca = 4.0 * (-50.0 + membrane_potential__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * cell_parameters__F / (cell_parameters__R * cell_parameters__T)) - cell_parameters__Ca_o * exp(-2.0 * (-50.0 + membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * cell_parameters__F / ((1.0 - exp(-2.0 * (-50.0 + membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * cell_parameters__R * cell_parameters__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca = ((fabs(-50.0 + membrane_potential__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane_potential__V) * (2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - cell_parameters__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - cell_parameters__Ca_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - cell_parameters__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.14973556329098189 * (-50.0 + membrane_potential__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - cell_parameters__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane_potential__V)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane_potential__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/iribe_model_2006/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K = 0.002 * (-50.0 + membrane_potential__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * cell_parameters__F / (cell_parameters__R * cell_parameters__T)) - cell_parameters__K_o * exp((50.0 - membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * cell_parameters__F / ((1.0 - exp((50.0 - membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * cell_parameters__R * cell_parameters__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K = ((fabs(-50.0 + membrane_potential__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane_potential__V) * (2.0000000001218549e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - cell_parameters__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - cell_parameters__K_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - cell_parameters__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (7.4867781645490941e-5 * (-50.0 + membrane_potential__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - cell_parameters__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane_potential__V)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane_potential__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/iribe_model_2006/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_Na = 0.01 * (-50.0 + membrane_potential__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * cell_parameters__F / (cell_parameters__R * cell_parameters__T)) - cell_parameters__Na_o * exp((50.0 - membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * cell_parameters__F / ((1.0 - exp((50.0 - membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * cell_parameters__R * cell_parameters__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na = ((fabs(-50.0 + membrane_potential__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane_potential__V) * (1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - cell_parameters__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - cell_parameters__Na_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - cell_parameters__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (-50.0 + membrane_potential__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - cell_parameters__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane_potential__V)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane_potential__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/iribe_model_2006/3_0.png)

## Equation 4:
```
L_type_Ca_channel_d_gate__alpha_d = 30.0 * (19.0 + membrane_potential__V) * L_type_Ca_channel_d_gate__speed_d / (1.0 - exp(-4.75 - 0.25 * membrane_potential__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__alpha_d = ((fabs(19.0 + membrane_potential__V) < 4.0000000112172529e-7) ? (-3.6000000100955276e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1249999.9964946085 * (19.000000400000001 + membrane_potential__V) * (3.6000000100955276e-5 / (1.0 - exp(1.0000000028043132e-7)) + 3.6000000100955276e-5 / (1.0 - exp(-1.0000000028043132e-7)))) : (90.0 * (19.0 + membrane_potential__V) / (1.0 - exp(-4.75 - 0.25 * membrane_potential__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/iribe_model_2006/4_0.png)

## Equation 5:
```
L_type_Ca_channel_d_gate__beta_d = -12.0 * (19.0 + membrane_potential__V) * L_type_Ca_channel_d_gate__speed_d / (1.0 - exp(1.8999999999999999 + 0.10000000000000001 * membrane_potential__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__beta_d = ((fabs(19.0 + membrane_potential__V) < 1.0000000010279564e-6) ? (-3.600000003700643e-5 / (1.0 - exp(1.0000000010279564e-7)) - 499999.99948602181 * (18.999998999999999 + membrane_potential__V) * (3.600000003700643e-5 / (1.0 - exp(1.0000000010279564e-7)) + 3.600000003700643e-5 / (1.0 - exp(-1.0000000010279564e-7)))) : (-36.0 * (19.0 + membrane_potential__V) / (1.0 - exp(1.8999999999999999 + 0.10000000000000001 * membrane_potential__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/iribe_model_2006/5_0.png)

## Equation 6:
```
L_type_Ca_channel_f_gate__alpha_f = 6.25 * (34.0 + membrane_potential__V) * L_type_Ca_channel_f_gate__speed_f / (-1.0 + exp(8.5 + 0.25 * membrane_potential__V))
```
## New Eq:
```
L_type_Ca_channel_f_gate__alpha_f = 3.125 * (34.0 + membrane_potential__V) / (-1.0 + exp(8.5 + 0.25 * membrane_potential__V))
```

## Equation 7:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (41.0 + membrane_potential__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane_potential__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + membrane_potential__V) < 1.0000000010279564e-6) ? (-0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (41.000001000000005 + membrane_potential__V) * (0.00019999999949504854 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)))) : (200.0 * (41.0 + membrane_potential__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane_potential__V))))
```
## Singularity point: -41.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/iribe_model_2006/7_0.png)

Number of singularities:  6
# Model: IyerMazhariWinslow2004(iyer_2004.cellml)
Number of piecewises: 1
## Equation 1:
```
COMPUTE_ICa_ICaK__ICamax = 4.0 * COMPUTE_ICa_ICaK__PCa * COMPUTE_ICa_ICaK__VFsq_over_RT * COMPUTE_ICa_ICaK__a1_Ca / COMPUTE_ICa_ICaK__a2_Ca
```
## New Eq:
```
COMPUTE_ICa_ICaK__ICamax = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 1.3355699481865285e-6) ? (-374372.00550889375 * (-1.3355699481865285e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (-0.1351 * (0.001 * exp(1.0000000000000001e-7) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa_max / (-1.0 + exp(1.0000000000000001e-7)) - 0.1351 * (0.001 * exp(-1.0000000000000001e-7) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa_max / (-1.0 + exp(-1.0000000000000001e-7))) + 0.1351 * (0.001 * exp(1.0000000000000001e-7) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa_max / (-1.0 + exp(1.0000000000000001e-7))) : (101155.3158885031 * (0.001 * exp(0.074874401101778759 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_ICa_ICaK__PCa_max / (-1.0 + exp(0.074874401101778759 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/iyer_2004/1_0.png)

## Equation 2:
```
COMPUTE_ICa_ICaK__ICaK = COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa * COMPUTE_ICa_ICaK__PKprime * COMPUTE_ICa_ICaK__VFsq_over_RT * COMPUTE_ICa_ICaK__a1_K / COMPUTE_ICa_ICaK__a2_K
```
## New Eq:
```
COMPUTE_ICa_ICaK__ICaK = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.671139896373057e-6) ? (-187186.00275444688 * (-2.671139896373057e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (-3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(1.0000000000000001e-7))) - 3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(-1.0000000000000001e-7)))) + 3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(1.0000000000000001e-7)))) : (0.01156711037185033 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/iyer_2004/2_1.png)
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/iyer_2004/2_2.png)

## Equation 3:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_K = COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__VFsq_over_RT * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a1_K / COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a2
```
## New Eq:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_K = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.671139896373057e-6) ? (-187186.00275444688 * (-2.671139896373057e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (-0.0010711499999999999 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(1.0000000000000001e-7)) - 0.0010711499999999999 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(-1.0000000000000001e-7))) + 0.0010711499999999999 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(1.0000000000000001e-7))) : (401.00857370085151 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/iyer_2004/3_0.png)

## Equation 4:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_Na = 0.02 * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__VFsq_over_RT * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a1_Na / COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a2
```
## New Eq:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_Na = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.671139896373057e-6) ? (-187186.00275444688 * (-2.671139896373057e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (-2.1423000000000001e-5 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(1.0000000000000001e-7)) - 2.1423000000000001e-5 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(-1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(-1.0000000000000001e-7))) + 2.1423000000000001e-5 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(1.0000000000000001e-7))) : (8.0201714740170313 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/iyer_2004/4_0.png)

Number of singularities:  4
# Model: iyer_model_2007(iyer_model_2007.cellml)
Number of piecewises: 7
## Equation 1:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_K = COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__VFsq_over_RT * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a1_K / COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a2
```
## New Eq:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_K = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.671139896373057e-6) ? (-187186.00275444688 * (-2.671139896373057e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (-4.0150763800800001e-10 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(1.0000000000000001e-7)) - 4.0150763800800001e-10 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(-1.0000000000000001e-7))) + 4.0150763800800001e-10 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(1.0000000000000001e-7))) : (0.00015031321966819388 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/iyer_model_2007/1_0.png)

## Equation 2:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_Na = 0.02 * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__VFsq_over_RT * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a1_Na / COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a2
```
## New Eq:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_Na = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.671139896373057e-6) ? (-187186.00275444688 * (-2.671139896373057e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (-8.0301527601600006e-12 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(1.0000000000000001e-7)) - 8.0301527601600006e-12 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(-1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(-1.0000000000000001e-7))) + 8.0301527601600006e-12 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(1.0000000000000001e-7))) : (3.006264393363878e-6 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/iyer_model_2007/2_0.png)

## Equation 3:
```
COMPUTE_ICa_ICaK__ICamax = 4.0 * COMPUTE_ICa_ICaK__PCa * COMPUTE_ICa_ICaK__VFsq_over_RT * COMPUTE_ICa_ICaK__a1_Ca / COMPUTE_ICa_ICaK__a2_Ca
```
## New Eq:
```
COMPUTE_ICa_ICaK__ICamax = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 1.3355699481865285e-6) ? (-374372.00550889375 * (-1.3355699481865285e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (-0.019300000000000001 * (0.001 * exp(1.0000000000000001e-7) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa / (-1.0 + exp(1.0000000000000001e-7)) - 0.019300000000000001 * (0.001 * exp(-1.0000000000000001e-7) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa / (-1.0 + exp(-1.0000000000000001e-7))) + 0.019300000000000001 * (0.001 * exp(1.0000000000000001e-7) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa / (-1.0 + exp(1.0000000000000001e-7))) : (14450.7594126433 * (0.001 * exp(0.074874401101778759 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_ICa_ICaK__PCa / (-1.0 + exp(0.074874401101778759 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/iyer_model_2007/3_0.png)

## Equation 4:
```
COMPUTE_ICa_ICaK__ICaK = COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa * COMPUTE_ICa_ICaK__PKprime * COMPUTE_ICa_ICaK__VFsq_over_RT * COMPUTE_ICa_ICaK__a1_K / COMPUTE_ICa_ICaK__a2_K
```
## New Eq:
```
COMPUTE_ICa_ICaK__ICaK = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.671139896373057e-6) ? (-187186.00275444688 * (-2.671139896373057e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (-3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(1.0000000000000001e-7))) - 3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(-1.0000000000000001e-7)))) + 3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(1.0000000000000001e-7)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(1.0000000000000001e-7)))) : (0.01156711037185033 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/iyer_model_2007/4_0.png)
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/iyer_model_2007/4_2.png)

Number of singularities:  4
# Model: jafri_rice_winslow_1998(jafri_rice_winslow_model_1998.cellml)
Number of piecewises: 4
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca_max = 4.0 * pow(membrane__F, 2) * (0.001 * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T)) - 0.34100000000000003 * ionic_concentrations__Cao) * L_type_Ca_channel__P_Ca * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_max = ((fabs(membrane__V) < 1.3307320976818627e-6) ? (-375733.02761014085 * (-1.3307320976818627e-6 + membrane__V) * (-0.019368999999999997 * (0.001 * exp(9.9999999999999995e-8) - 0.34100000000000003 * ionic_concentrations__Cao) * L_type_Ca_channel__P_Ca / (-1.0 + exp(9.9999999999999995e-8)) - 0.019368999999999997 * (0.001 * exp(-9.9999999999999995e-8) - 0.34100000000000003 * ionic_concentrations__Cao) * L_type_Ca_channel__P_Ca / (-1.0 + exp(-9.9999999999999995e-8))) + 0.019368999999999997 * (0.001 * exp(9.9999999999999995e-8) - 0.34100000000000003 * ionic_concentrations__Cao) * L_type_Ca_channel__P_Ca / (-1.0 + exp(9.9999999999999995e-8))) : (14555.146023561636 * (0.001 * exp(0.075146605522028176 * membrane__V) - 0.34100000000000003 * ionic_concentrations__Cao) * L_type_Ca_channel__P_Ca * membrane__V / (-1.0 + exp(0.075146605522028176 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/jafri_rice_winslow_model_1998/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K = pow(membrane__F, 2) * (-ionic_concentrations__Ko + ionic_concentrations__Ki * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * (L_type_Ca_channel__O + L_type_Ca_channel__O_Ca) * L_type_Ca_channel__p_k * L_type_Ca_channel_y_gate__y * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K = ((fabs(membrane__V) < 2.6614641953637258e-6) ? (-187866.5138050704 * (-2.6614641953637258e-6 + membrane__V) * (-9.6845000000000022e-12 * (-ionic_concentrations__Ko + ionic_concentrations__Ki * exp(1.0000000000000001e-7)) * (L_type_Ca_channel__O + L_type_Ca_channel__O_Ca) * L_type_Ca_channel_y_gate__y / ((1.0 - 218.34061135371181 * L_type_Ca_channel__i_Ca_L_Ca_max) * (-1.0 + exp(1.0000000000000001e-7))) - 9.6845000000000022e-12 * (-ionic_concentrations__Ko + ionic_concentrations__Ki * exp(-1.0000000000000001e-7)) * (L_type_Ca_channel__O + L_type_Ca_channel__O_Ca) * L_type_Ca_channel_y_gate__y / ((1.0 - 218.34061135371181 * L_type_Ca_channel__i_Ca_L_Ca_max) * (-1.0 + exp(-1.0000000000000001e-7)))) + 9.6845000000000022e-12 * (-ionic_concentrations__Ko + ionic_concentrations__Ki * exp(1.0000000000000001e-7)) * (L_type_Ca_channel__O + L_type_Ca_channel__O_Ca) * L_type_Ca_channel_y_gate__y / ((1.0 - 218.34061135371181 * L_type_Ca_channel__i_Ca_L_Ca_max) * (-1.0 + exp(1.0000000000000001e-7)))) : (3.6387865058904094e-6 * (-ionic_concentrations__Ko + ionic_concentrations__Ki * exp(0.037573302761014088 * membrane__V)) * (L_type_Ca_channel__O + L_type_Ca_channel__O_Ca) * L_type_Ca_channel_y_gate__y * membrane__V / ((1.0 - 218.34061135371181 * L_type_Ca_channel__i_Ca_L_Ca_max) * (-1.0 + exp(0.037573302761014088 * membrane__V)))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/jafri_rice_winslow_model_1998/2_0.png)
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/jafri_rice_winslow_model_1998/2_1.png)

## Equation 3:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/jafri_rice_winslow_model_1998/3_0.png)

## Equation 4:
```
time_dependent_potassium_current_X_gate__alpha_X = 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_X_gate__alpha_X = ((fabs(30.0 + membrane__V) < 6.7567567541004792e-7) ? (-4.8581081061982445e-11 / (1.0 - exp(9.9999999960687092e-8)) + 740000.00029091549 * (30.000000675675675 + membrane__V) * (4.8581081061982445e-11 / (1.0 - exp(9.9999999960687092e-8)) + 4.8581081061982445e-11 / (1.0 - exp(-9.9999999960687092e-8)))) : (7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/jafri_rice_winslow_model_1998/4_0.png)

## Equation 5:
```
time_dependent_potassium_current_X_gate__beta_X = 0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_X_gate__beta_X = ((fabs(30.0 + membrane__V) < 1.4556040746072085e-6) ? (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) - 343500.00025585521 * (29.999998544395925 + membrane__V) * (-1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) - 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)))) : (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/jafri_rice_winslow_model_1998/5_0.png)

Number of singularities:  5
# Model: kurata_model_2002(kurata_model_2002.cellml)
Number of piecewises: 0
## Equation 1:
```
L_type_calcium_channel_current_d_gate__alpha_d = -0.028389999999999999 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)) - 0.084900000000000003 * membrane__V / (-1.0 + exp(-0.20798668885191349 * membrane__V))
```
## New Eq:
```
L_type_calcium_channel_current_d_gate__alpha_d = -0.028389999999999999 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)) + ((fabs(membrane__V) < 4.8080000000000002e-7) ? (4.0819920000000005e-8 / (-1.0 + exp(1.0000000000000001e-7)) + 1039933.4442595673 * (4.8080000000000002e-7 + membrane__V) * (-4.0819920000000005e-8 / (-1.0 + exp(1.0000000000000001e-7)) - 4.0819920000000005e-8 / (-1.0 + exp(-1.0000000000000001e-7)))) : (-0.084900000000000003 * membrane__V / (-1.0 + exp(-0.20798668885191349 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/kurata_model_2002/1_0.png)

## Equation 2:
```
L_type_calcium_channel_current_d_gate__beta_d = 0.011429999999999999 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))
```
## New Eq:
```
L_type_calcium_channel_current_d_gate__beta_d = ((fabs(-5.0 + membrane__V) < 2.500000002569891e-7) ? (2.8575000029373851e-9 / (-1.0 + exp(1.0000000010279564e-7)) - 1999999.9979440873 * (-5.0000002500000003 + membrane__V) * (-2.8575000029373851e-9 / (-1.0 + exp(1.0000000010279564e-7)) - 2.8575000029373851e-9 / (-1.0 + exp(-1.0000000010279564e-7)))) : (0.011429999999999999 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))))
```
## Singularity point: 5.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/kurata_model_2002/2_0.png)

Number of singularities:  2
# Model: lindblad_atrial_model_1996(lindblad_model_1996.cellml)
Number of piecewises: 0
## Equation 1:
```
L_type_Ca_channel_d_L_gate__alpha_d_L = -50.0 * membrane__V / (-1.0 + exp(-0.20798668885191349 * membrane__V)) - 16.719999999999999 * L_type_Ca_channel_d_L_gate__E0_alpha_d_L / (-1.0 + exp(-0.40000000000000002 * L_type_Ca_channel_d_L_gate__E0_alpha_d_L))
```
## New Eq:
```
L_type_Ca_channel_d_L_gate__alpha_d_L = -16.719999999999999 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)) + ((fabs(membrane__V) < 4.8080000000000002e-7) ? (2.404e-5 / (-1.0 + exp(1.0000000000000001e-7)) + 1039933.4442595673 * (4.8080000000000002e-7 + membrane__V) * (-2.404e-5 / (-1.0 + exp(1.0000000000000001e-7)) - 2.404e-5 / (-1.0 + exp(-1.0000000000000001e-7)))) : (-50.0 * membrane__V / (-1.0 + exp(-0.20798668885191349 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/lindblad_model_1996/1_0.png)

## Equation 2:
```
L_type_Ca_channel_d_L_gate__beta_d_L = 4.4800000000000004 * L_type_Ca_channel_d_L_gate__E0_beta_d_L / (-1.0 + exp(0.40000000000000002 * L_type_Ca_channel_d_L_gate__E0_beta_d_L))
```
## New Eq:
```
L_type_Ca_channel_d_L_gate__beta_d_L = ((fabs(-5.0 + membrane__V) < 2.500000002569891e-7) ? (1.1200000011513112e-6 / (-1.0 + exp(1.0000000010279564e-7)) - 1999999.9979440873 * (-5.0000002500000003 + membrane__V) * (-1.1200000011513112e-6 / (-1.0 + exp(1.0000000010279564e-7)) - 1.1200000011513112e-6 / (-1.0 + exp(-1.0000000010279564e-7)))) : (4.4800000000000004 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))))
```
## Singularity point: 5.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/lindblad_model_1996/2_0.png)

## Equation 3:
```
L_type_Ca_channel_f_L_gate__alpha_f_L = 8.4900000000000002 * L_type_Ca_channel_f_L_gate__E0_f_L / (-1.0 + exp(0.25 * L_type_Ca_channel_f_L_gate__E0_f_L))
```
## New Eq:
```
L_type_Ca_channel_f_L_gate__alpha_f_L = 8.4900000000000002 * (28.0 + membrane__V) / (-1.0 + exp(7.0 + 0.25 * membrane__V))
```

## Equation 4:
```
sodium_current_m_gate__alpha_m = -460.0 * sodium_current_m_gate__E0_m / (-1.0 + exp(-0.078907914463820727 * sodium_current_m_gate__E0_m))
```
## New Eq:
```
sodium_current_m_gate__alpha_m = ((fabs(44.399999999999999 + membrane__V) < 1.2673000000518186e-6) ? (0.00058295800002383658 / (-1.0 + exp(1.000000000040889e-7)) + 394539.57230297127 * (44.400001267299999 + membrane__V) * (-0.00058295800002383658 / (-1.0 + exp(1.000000000040889e-7)) - 0.00058295800002383658 / (-1.0 + exp(-1.000000000040889e-7)))) : (-460.0 * (44.399999999999999 + membrane__V) / (-1.0 + exp(-3.5035114021936398 - 0.078907914463820727 * membrane__V))))
```
## Singularity point: -44.399999999999999
![Singularity](diagrams/new/no_singularity_fixes/lindblad_model_1996/4_0.png)

## Equation 5:
```
sodium_current__i_Na = pow(membrane__F, 2) * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp((-sodium_current__E_Na + membrane__V) * membrane__F / (membrane__R * membrane__T))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
sodium_current__i_Na = ((fabs(membrane__V) < 2.6541413816729874e-6) ? (-188384.8401794009 * (-2.6541413816729874e-6 + membrane__V) * (-0.0096485341500000005 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(1.0000000000000001e-7 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(1.0000000000000001e-7)) - 0.0096485341500000005 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-1.0000000000000001e-7 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-1.0000000000000001e-7))) + 0.0096485341500000005 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(1.0000000000000001e-7 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(1.0000000000000001e-7))) : (3635.2751276264835 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(0.037676968035880179 * membrane__V - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / (-1.0 + exp(0.037676968035880179 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/lindblad_model_1996/5_0.png)

Number of singularities:  4
# Model: LivshitzRudy2007(livshitz_rudy_2007.cellml)
Number of piecewises: 0
## Equation 1:
```
ICaL__ibarca = 4.0 * (-Environment__Ca_o * ICaL__gacao + Ca__Ca_i * ICaL__gacai * exp(2.0 * Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * ICaL__pca * cell__V / (-1.0 + exp(2.0 * Environment__FonRT * cell__V))
```
## New Eq:
```
ICaL__ibarca = ((fabs(cell__V) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + cell__V) * (-0.019296999999999998 * (-0.34100000000000003 * Environment__Ca_o + (-0.040960000000000003 + 0.33333333333333331 * Ca__Ca_T + 0.66666666666666663 * sqrt(-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T) * cos(0.33333333333333331 * acos(0.5 * pow((-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T), (-1.5)) * (3.2130000000000006e-5 * Ca__Ca_T - 2.0 * pow((0.12288 - Ca__Ca_T), 3) + 9.0 * (0.12288 - Ca__Ca_T) * (0.00019279000000000003 - 0.0028800000000000002 * Ca__Ca_T))))) * exp(9.9999999999999995e-8)) * ICaL__pca / (-1.0 + exp(9.9999999999999995e-8)) - 0.019296999999999998 * (-0.34100000000000003 * Environment__Ca_o + (-0.040960000000000003 + 0.33333333333333331 * Ca__Ca_T + 0.66666666666666663 * sqrt(-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T) * cos(0.33333333333333331 * acos(0.5 * pow((-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T), (-1.5)) * (3.2130000000000006e-5 * Ca__Ca_T - 2.0 * pow((0.12288 - Ca__Ca_T), 3) + 9.0 * (0.12288 - Ca__Ca_T) * (0.00019279000000000003 - 0.0028800000000000002 * Ca__Ca_T))))) * exp(-9.9999999999999995e-8)) * ICaL__pca / (-1.0 + exp(-9.9999999999999995e-8))) + 0.019296999999999998 * (-0.34100000000000003 * Environment__Ca_o + (-0.040960000000000003 + 0.33333333333333331 * Ca__Ca_T + 0.66666666666666663 * sqrt(-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T) * cos(0.33333333333333331 * acos(0.5 * pow((-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T), (-1.5)) * (3.2130000000000006e-5 * Ca__Ca_T - 2.0 * pow((0.12288 - Ca__Ca_T), 3) + 9.0 * (0.12288 - Ca__Ca_T) * (0.00019279000000000003 - 0.0028800000000000002 * Ca__Ca_T))))) * exp(9.9999999999999995e-8)) * ICaL__pca / (-1.0 + exp(9.9999999999999995e-8))) : (14448.004881001343 * (-0.34100000000000003 * Environment__Ca_o + (-0.040960000000000003 + 0.33333333333333331 * Ca__Ca_T + 0.66666666666666663 * sqrt(-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T) * cos(0.33333333333333331 * acos(0.5 * pow((-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T), (-1.5)) * (3.2130000000000006e-5 * Ca__Ca_T - 2.0 * pow((0.12288 - Ca__Ca_T), 3) + 9.0 * (0.12288 - Ca__Ca_T) * (0.00019279000000000003 - 0.0028800000000000002 * Ca__Ca_T))))) * exp(0.074871767015605231 * cell__V)) * ICaL__pca * cell__V / (-1.0 + exp(0.074871767015605231 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/livshitz_rudy_2007/1_0.png)

## Equation 2:
```
ICaL__ibark = (-Environment__K_o * ICaL__gako + ICaL__gaki * K__K_i * exp(Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * ICaL__pk * cell__V / (-1.0 + exp(Environment__FonRT * cell__V))
```
## New Eq:
```
ICaL__ibark = ((fabs(cell__V) < 2.6712338705498262e-6) ? (1.8621604999999999e-9 * (-0.75 * Environment__K_o + 0.75 * K__K_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + cell__V) * (-1.8621604999999999e-9 * (-0.75 * Environment__K_o + 0.75 * K__K_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 1.8621604999999999e-9 * (-0.75 * Environment__K_o + 0.75 * K__K_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.00069711623550831479 * (-0.75 * Environment__K_o + 0.75 * K__K_i * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/livshitz_rudy_2007/2_0.png)

## Equation 3:
```
ICaL__ibarna = (-Environment__Na_o * ICaL__ganao + ICaL__ganai * Na__Na_i * exp(Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * ICaL__pna * cell__V / (-1.0 + exp(Environment__FonRT * cell__V))
```
## New Eq:
```
ICaL__ibarna = ((fabs(cell__V) < 2.6712338705498262e-6) ? (6.5127374999999992e-9 * (-0.75 * Environment__Na_o + 0.75 * Na__Na_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + cell__V) * (-6.5127374999999992e-9 * (-0.75 * Environment__Na_o + 0.75 * Na__Na_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 6.5127374999999992e-9 * (-0.75 * Environment__Na_o + 0.75 * Na__Na_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.0024381008236689767 * (-0.75 * Environment__Na_o + 0.75 * Na__Na_i * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/livshitz_rudy_2007/3_0.png)

## Equation 4:
```
ICaL__taud = 28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * cell__V)) * ICaL__dss0 / (10.0 + cell__V)
```
## New Eq:
```
ICaL__taud = ((fabs(10.0 + cell__V) < 6.2400000011564316e-7) ? (801282.05113355326 * (10.000000624 + cell__V) * (45787545.779060178 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7)) + 45787545.779060178 * (1.0 - exp(-1.0000000001853256e-7)) / (1.0 + exp(-1.0000000001853256e-7))) - 45787545.779060178 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7))) : (28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * cell__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * cell__V)) * (10.0 + cell__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/livshitz_rudy_2007/4_0.png)

## Equation 5:
```
IKr__tauxr = 1 / (0.00060999999999999997 * (38.899999999999999 + cell__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * cell__V)) + 0.0013799999999999999 * (14.199999999999999 + cell__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * cell__V)))
```
## New Eq:
```
IKr__tauxr = 1 / (((fabs(38.899999999999999 + cell__V) < 6.8965517030505907e-7) ? (4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)) - 725000.00221680664 * (38.899999310344825 + cell__V) * (-4.2068965171893065e-10 / (-1.0 + exp(-9.9999999179090074e-8)) - 4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)))) : (0.00060999999999999997 * (38.899999999999999 + cell__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * cell__V)))) + ((fabs(14.199999999999999 + cell__V) < 8.1300813015161566e-7) ? (-1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 614999.99994681031 * (14.200000813008129 + cell__V) * (1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 1.1219512196092296e-9 / (1.0 - exp(-1.0000000000864873e-7)))) : (0.0013799999999999999 * (14.199999999999999 + cell__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * cell__V)))))
```
## Singularity point: -38.899999999999999
![Singularity](diagrams/new/no_singularity_fixes/livshitz_rudy_2007/5_0.png)
## Singularity point: -14.199999999999999
![Singularity](diagrams/new/no_singularity_fixes/livshitz_rudy_2007/5_1.png)

## Equation 6:
```
IKs__tauxs = 1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))
```
## New Eq:
```
IKs__tauxs = ((fabs(30.0 + cell__V) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + cell__V) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/livshitz_rudy_2007/6_0.png)

## Equation 7:
```
INa__am = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa__am = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/livshitz_rudy_2007/7_0.png)

Number of singularities:  8
# Model: Li_Mouse_2010(li_mouse_2010.cellml)
Number of piecewises: 2
## Equation 1:
```
L_type_calcium_current__i_CaL = -2.0 * (-calcium_concentration__Cass + cell__Cao * exp(-L_type_calcium_current__FVRT_Ca)) * L_type_calcium_current__FVRT_Ca * L_type_calcium_current__O * L_type_calcium_current__P_CaL * L_type_calcium_current__y_gate * cell__F * cell__Vss / ((1.0 - exp(-L_type_calcium_current__FVRT_Ca)) * cell__Acap * cell__Cm)
```
## New Eq:
```
L_type_calcium_current__i_CaL = ((fabs(cell__V) < 1.3267937823834197e-6) ? (376848.3140626513 * (1.3267937823834197e-6 + cell__V) * (-3.0621664503101105e-9 * (-calcium_concentration__Cass + cell__Cao * exp(9.9999999999999995e-8)) * L_type_calcium_current__O * L_type_calcium_current__P_CaL * L_type_calcium_current__y_gate / ((1.0 - exp(9.9999999999999995e-8)) * cell__Cm) - 3.0621664503101105e-9 * (-calcium_concentration__Cass + cell__Cao * exp(-9.9999999999999995e-8)) * L_type_calcium_current__O * L_type_calcium_current__P_CaL * L_type_calcium_current__y_gate / ((1.0 - exp(-9.9999999999999995e-8)) * cell__Cm)) + 3.0621664503101105e-9 * (-calcium_concentration__Cass + cell__Cao * exp(9.9999999999999995e-8)) * L_type_calcium_current__O * L_type_calcium_current__P_CaL * L_type_calcium_current__y_gate / ((1.0 - exp(9.9999999999999995e-8)) * cell__Cm)) : (-0.0023079445283571576 * (-calcium_concentration__Cass + cell__Cao * exp(-0.075369662812530269 * cell__V)) * L_type_calcium_current__O * L_type_calcium_current__P_CaL * L_type_calcium_current__y_gate * cell__V / ((1.0 - exp(-0.075369662812530269 * cell__V)) * cell__Cm)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/li_mouse_2010/1_0.png)

## Equation 2:
```
slow_delayed_rectifier_K_I__alpha_n = 4.8133299999999997e-6 * (26.5 + cell__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * cell__V))
```
## New Eq:
```
slow_delayed_rectifier_K_I__alpha_n = ((fabs(26.5 + cell__V) < 7.812499998038902e-7) ? (-3.7604140701062501e-12 / (1.0 - exp(1.0000000020227162e-7)) + 640000.00016065314 * (26.500000781250002 + cell__V) * (3.760414053005867e-12 / (1.0 - exp(-9.9999999747524276e-8)) + 3.7604140701062501e-12 / (1.0 - exp(1.0000000020227162e-7)))) : (4.8133299999999997e-6 * (26.5 + cell__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * cell__V))))
```
## Singularity point: -26.500000000000000
![Singularity](diagrams/new/no_singularity_fixes/li_mouse_2010/2_0.png)

Number of singularities:  2
# Model: luo_rudy_1991(luo_rudy_1991.cellml)
Number of piecewises: 5
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/luo_rudy_1991/1_0.png)

## Equation 2:
```
time_dependent_potassium_current_Xi_gate__temp_Xi = 2.8370000000000002 * (-1.0 + exp(3.0800000000000001 + 0.040000000000000001 * membrane__V)) / (77.0 + membrane__V)
```
## New Eq:
```
time_dependent_potassium_current_Xi_gate__temp_Xi = ((fabs(77.0 + membrane__V) < 2.5000000007935341e-6) ? (-1134800.0028650947 + 1134800.0028650947 * exp(9.9999999747524276e-8) - 199999.99993651727 * (76.999997500000006 + membrane__V) * (2269599.9992795982 - 1134799.9964145035 * exp(-1.0000000031595847e-7) - 1134800.0028650947 * exp(9.9999999747524276e-8))) : (2.8370000000000002 * (-1.0 + exp(3.0800000000000001 + 0.040000000000000001 * membrane__V)) / (77.0 + membrane__V)))
```
## Singularity point: -77.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/luo_rudy_1991/2_0.png)

Number of singularities:  2
# Model: luo_rudy_1994(luo_rudy_1994.cellml)
Number of piecewises: 5
## Equation 1:
```
L_type_Ca_channel__I_CaCa = 4.0 * pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Cao * ionic_concentrations__Cao + L_type_Ca_channel__gamma_Cai * ionic_concentrations__Cai * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Ca * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaCa = ((fabs(membrane__V) < 1.3307320976818627e-6) ? (1.0459259999999999e-7 * (-0.34000000000000002 * ionic_concentrations__Cao + ionic_concentrations__Cai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 375733.02761014085 * (-1.3307320976818627e-6 + membrane__V) * (-1.0459259999999999e-7 * (-0.34000000000000002 * ionic_concentrations__Cao + ionic_concentrations__Cai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 1.0459259999999999e-7 * (-0.34000000000000002 * ionic_concentrations__Cao + ionic_concentrations__Cai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.078597788527232842 * (-0.34000000000000002 * ionic_concentrations__Cao + ionic_concentrations__Cai * exp(0.075146605522028176 * membrane__V)) * membrane__V / (-1.0 + exp(0.075146605522028176 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/luo_rudy_1994/1_0.png)

## Equation 2:
```
L_type_Ca_channel__I_CaK = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_K * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaK = ((fabs(membrane__V) < 2.6614641953637258e-6) ? (1.8691085000000002e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(1.0000000000000001e-7)) / (-1.0 + exp(1.0000000000000001e-7)) - 187866.5138050704 * (-2.6614641953637258e-6 + membrane__V) * (-1.8691085000000002e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(1.0000000000000001e-7)) / (-1.0 + exp(1.0000000000000001e-7)) - 1.8691085000000002e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-1.0000000000000001e-7)) / (-1.0 + exp(-1.0000000000000001e-7)))) : (7.0228579563684903e-6 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037573302761014088 * membrane__V)) * membrane__V / (-1.0 + exp(0.037573302761014088 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/luo_rudy_1994/2_0.png)

## Equation 3:
```
L_type_Ca_channel__I_CaNa = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Na * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaNa = ((fabs(membrane__V) < 2.6614641953637258e-6) ? (6.5370375000000006e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(1.0000000000000001e-7)) / (-1.0 + exp(1.0000000000000001e-7)) - 187866.5138050704 * (-2.6614641953637258e-6 + membrane__V) * (-6.5370375000000006e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(1.0000000000000001e-7)) / (-1.0 + exp(1.0000000000000001e-7)) - 6.5370375000000006e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-1.0000000000000001e-7)) / (-1.0 + exp(-1.0000000000000001e-7)))) : (2.4561808914760263e-5 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037573302761014088 * membrane__V)) * membrane__V / (-1.0 + exp(0.037573302761014088 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/luo_rudy_1994/3_0.png)

## Equation 4:
```
L_type_Ca_channel_d_gate__tau_d = 28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * L_type_Ca_channel_d_gate__d_infinity / (10.0 + membrane__V)
```
## New Eq:
```
L_type_Ca_channel_d_gate__tau_d = ((fabs(10.0 + membrane__V) < 6.2400000011564316e-7) ? (801282.05113355326 * (10.000000624 + membrane__V) * (45787545.779060178 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7)) + 45787545.779060178 * (1.0 - exp(-1.0000000001853256e-7)) / (1.0 + exp(-1.0000000001853256e-7))) - 45787545.779060178 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7))) : (28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * (10.0 + membrane__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/luo_rudy_1994/4_0.png)

## Equation 5:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/luo_rudy_1994/5_0.png)

## Equation 6:
```
time_dependent_potassium_current_X_gate__alpha_X = 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_X_gate__alpha_X = ((fabs(30.0 + membrane__V) < 6.7567567541004792e-7) ? (-4.8581081061982445e-11 / (1.0 - exp(9.9999999960687092e-8)) + 740000.00029091549 * (30.000000675675675 + membrane__V) * (4.8581081061982445e-11 / (1.0 - exp(9.9999999960687092e-8)) + 4.8581081061982445e-11 / (1.0 - exp(-9.9999999960687092e-8)))) : (7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/luo_rudy_1994/6_0.png)

## Equation 7:
```
time_dependent_potassium_current_X_gate__beta_X = 0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_X_gate__beta_X = ((fabs(30.0 + membrane__V) < 1.4556040746072085e-6) ? (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) - 343500.00025585521 * (29.999998544395925 + membrane__V) * (-1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) - 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)))) : (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/luo_rudy_1994/7_0.png)

Number of singularities:  7
# Model: MahajanShiferaw2008_units(mahajan_shiferaw_2008.cellml)
Number of piecewises: 5
## Equation 1:
```
ICaL__rxa = 4.0 * (-0.34100000000000003 * Environment__Ca_o + Ca__csm * exp(2.0 * Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * ICaL__pca * cell__V / (-1.0 + exp(2.0 * Environment__FonRT * cell__V))
```
## New Eq:
```
ICaL__rxa = ((fabs(cell__V) < 4.9999999999999998e-8 * fabs(Environment__R * Environment__T / Environment__F)) ? (1.9999999999999999e-7 * (-0.34100000000000003 * Environment__Ca_o + 0.001 * Ca__Ca_submem * exp(9.9999999999999995e-8)) * Environment__F * ICaL__pca / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * Environment__R * Environment__T / Environment__F + cell__V) * (-1.9999999999999999e-7 * (-0.34100000000000003 * Environment__Ca_o + 0.001 * Ca__Ca_submem * exp(9.9999999999999995e-8)) * Environment__F * ICaL__pca / (-1.0 + exp(9.9999999999999995e-8)) - 1.9999999999999999e-7 * (-0.34100000000000003 * Environment__Ca_o + 0.001 * Ca__Ca_submem * exp(-9.9999999999999995e-8)) * Environment__F * ICaL__pca / (-1.0 + exp(-9.9999999999999995e-8))) * Environment__F / (Environment__R * Environment__T)) : (4.0 * pow(Environment__F, 2) * (-0.34100000000000003 * Environment__Ca_o + 0.001 * Ca__Ca_submem * exp(2.0 * Environment__F * cell__V / (Environment__R * Environment__T))) * ICaL__pca * cell__V / ((-1.0 + exp(2.0 * Environment__F * cell__V / (Environment__R * Environment__T))) * Environment__R * Environment__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/mahajan_shiferaw_2008/1_0.png)

## Equation 2:
```
IKr__xkrv1 = 0.0013799999999999999 * (7.0 + cell__V) / (1.0 - exp(-0.86099999999999999 - 0.123 * cell__V))
```
## New Eq:
```
IKr__xkrv1 = ((fabs(7.0 + cell__V) < 8.1300813015161566e-7) ? (-1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 614999.99994681031 * (7.0000008130081302 + cell__V) * (1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 1.1219512196092296e-9 / (1.0 - exp(-1.0000000000864873e-7)))) : (0.0013799999999999999 * (7.0 + cell__V) / (1.0 - exp(-0.86099999999999999 - 0.123 * cell__V))))
```
## Singularity point: -7.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/mahajan_shiferaw_2008/2_0.png)

## Equation 3:
```
IKr__xkrv2 = 0.00060999999999999997 * (10.0 + cell__V) / (-1.0 + exp(1.45 + 0.14499999999999999 * cell__V))
```
## New Eq:
```
IKr__xkrv2 = ((fabs(10.0 + cell__V) < 6.8965517296959433e-7) ? (4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)) - 724999.99941571394 * (9.9999993103448261 + cell__V) * (-4.206896549696637e-10 / (-1.0 + exp(-9.9999999951805303e-8)) - 4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)))) : (0.00060999999999999997 * (10.0 + cell__V) / (-1.0 + exp(1.45 + 0.14499999999999999 * cell__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/mahajan_shiferaw_2008/3_0.png)

## Equation 4:
```
IKs__tauxs1 = 1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))
```
## New Eq:
```
IKs__tauxs1 = ((fabs(30.0 + cell__V) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + cell__V) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/mahajan_shiferaw_2008/4_0.png)

## Equation 5:
```
INa__am = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa__am = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/mahajan_shiferaw_2008/5_0.png)

Number of singularities:  5
# Model: Maleckar(maleckar_model_2009.cellml)
Number of piecewises: 0
## Equation 1:
```
sodium_current__i_Na = pow(membrane__F, 2) * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp((-sodium_current__E_Na + membrane__V) * membrane__F / (membrane__R * membrane__T))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
sodium_current__i_Na = ((fabs(membrane__V) < 2.6380041870925617e-6) ? (-189537.22759290531 * (-2.6380041870925617e-6 + membrane__V) * (-0.0096487000000000014 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(1.0000000000000001e-7 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(1.0000000000000001e-7)) - 0.0096487000000000014 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-1.0000000000000001e-7 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-1.0000000000000001e-7))) + 0.0096487000000000014 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(1.0000000000000001e-7 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(1.0000000000000001e-7))) : (3657.5756957513308 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(0.037907445518581065 * membrane__V - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / (-1.0 + exp(0.037907445518581065 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/maleckar_model_2009/1_0.png)

Number of singularities:  1
# Model: maltsev_2009(maltsev_2009.cellml)
Number of piecewises: 0
## Equation 1:
```
i_CaL_dL_gate__alpha_dL = -0.028389999999999999 * (35.0 + Vm__Vm) / (-1.0 + exp(-14.0 - 0.40000000000000002 * Vm__Vm)) - 0.084900000000000003 * Vm__Vm / (-1.0 + exp(-0.20833333333333334 * Vm__Vm))
```
## New Eq:
```
i_CaL_dL_gate__alpha_dL = -0.028389999999999999 * (35.0 + Vm__Vm) / (-1.0 + exp(-14.0 - 0.40000000000000002 * Vm__Vm)) + ((fabs(Vm__Vm) < 4.7999999999999996e-7) ? (4.0752e-8 / (-1.0 + exp(9.9999999999999995e-8)) + 1041666.6666666667 * (4.7999999999999996e-7 + Vm__Vm) * (-4.0752e-8 / (-1.0 + exp(9.9999999999999995e-8)) - 4.0752e-8 / (-1.0 + exp(-9.9999999999999995e-8)))) : (-0.084900000000000003 * Vm__Vm / (-1.0 + exp(-0.20833333333333334 * Vm__Vm))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/maltsev_2009/1_0.png)

## Equation 2:
```
i_CaL_dL_gate__beta_dL = 0.011429999999999999 * (-5.0 + Vm__Vm) / (-1.0 + exp(-2.0 + 0.40000000000000002 * Vm__Vm))
```
## New Eq:
```
i_CaL_dL_gate__beta_dL = ((fabs(-5.0 + Vm__Vm) < 2.500000002569891e-7) ? (2.8575000029373851e-9 / (-1.0 + exp(1.0000000010279564e-7)) - 1999999.9979440873 * (-5.0000002500000003 + Vm__Vm) * (-2.8575000029373851e-9 / (-1.0 + exp(1.0000000010279564e-7)) - 2.8575000029373851e-9 / (-1.0 + exp(-1.0000000010279564e-7)))) : (0.011429999999999999 * (-5.0 + Vm__Vm) / (-1.0 + exp(-2.0 + 0.40000000000000002 * Vm__Vm))))
```
## Singularity point: 5.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/maltsev_2009/2_0.png)

Number of singularities:  2
# Model: matsuoka_model_2003(matsuoka_model_2003.cellml)
Number of piecewises: 0
## Equation 1:
```
constant_field_equations__CF_Ca = 2.0 * (-external_ion_concentrations__Cao * exp(-2.0 * membrane__F * membrane__Vm / (membrane__R * membrane__T)) + internal_ion_concentrations__Cai) * membrane__F * membrane__Vm / ((1.0 - exp(-2.0 * membrane__F * membrane__Vm / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
constant_field_equations__CF_Ca = ((fabs(membrane__Vm) < 1.3356415961992688e-6) ? (374351.92301797954 * (1.3356415961992688e-6 + membrane__Vm) * (9.9999999999999995e-8 * (-0.026190000000000001 + 0.5 * sqrt(pow((0.052380000000000003 - internal_ion_concentrations__Ca_Total), 2) + 0.0095200000000000007 * internal_ion_concentrations__Ca_Total) + 0.5 * internal_ion_concentrations__Ca_Total - external_ion_concentrations__Cao * exp(9.9999999999999995e-8)) / (1.0 - exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-0.026190000000000001 + 0.5 * sqrt(pow((0.052380000000000003 - internal_ion_concentrations__Ca_Total), 2) + 0.0095200000000000007 * internal_ion_concentrations__Ca_Total) + 0.5 * internal_ion_concentrations__Ca_Total - external_ion_concentrations__Cao * exp(-9.9999999999999995e-8)) / (1.0 - exp(-9.9999999999999995e-8))) - 9.9999999999999995e-8 * (-0.026190000000000001 + 0.5 * sqrt(pow((0.052380000000000003 - internal_ion_concentrations__Ca_Total), 2) + 0.0095200000000000007 * internal_ion_concentrations__Ca_Total) + 0.5 * internal_ion_concentrations__Ca_Total - external_ion_concentrations__Cao * exp(9.9999999999999995e-8)) / (1.0 - exp(9.9999999999999995e-8))) : (0.074870384603595908 * (-0.026190000000000001 + 0.5 * sqrt(pow((0.052380000000000003 - internal_ion_concentrations__Ca_Total), 2) + 0.0095200000000000007 * internal_ion_concentrations__Ca_Total) + 0.5 * internal_ion_concentrations__Ca_Total - external_ion_concentrations__Cao * exp(-0.074870384603595908 * membrane__Vm)) * membrane__Vm / (1.0 - exp(-0.074870384603595908 * membrane__Vm))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/matsuoka_model_2003/1_0.png)

## Equation 2:
```
constant_field_equations__CF_K = (-external_ion_concentrations__Ko * exp(-membrane__F * membrane__Vm / (membrane__R * membrane__T)) + internal_ion_concentrations__Ki) * membrane__F * membrane__Vm / ((1.0 - exp(-membrane__F * membrane__Vm / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
constant_field_equations__CF_K = ((fabs(membrane__Vm) < 2.6712831923985376e-6) ? (187175.96150898977 * (2.6712831923985376e-6 + membrane__Vm) * (9.9999999999999995e-8 * (-external_ion_concentrations__Ko * exp(9.9999999999999995e-8) + internal_ion_concentrations__Ki) / (1.0 - exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-external_ion_concentrations__Ko * exp(-9.9999999999999995e-8) + internal_ion_concentrations__Ki) / (1.0 - exp(-9.9999999999999995e-8))) - 9.9999999999999995e-8 * (-external_ion_concentrations__Ko * exp(9.9999999999999995e-8) + internal_ion_concentrations__Ki) / (1.0 - exp(9.9999999999999995e-8))) : (0.037435192301797954 * (-external_ion_concentrations__Ko * exp(-0.037435192301797954 * membrane__Vm) + internal_ion_concentrations__Ki) * membrane__Vm / (1.0 - exp(-0.037435192301797954 * membrane__Vm))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/matsuoka_model_2003/2_0.png)

## Equation 3:
```
background_Kpl_current__i_Kpl = (3.0 + membrane__Vm) * background_Kpl_current__P_Kpl * constant_field_equations__CF_K / (1.0 - exp(-0.23076923076923078 - 0.076923076923076927 * membrane__Vm))
```
## New Eq:
```
background_Kpl_current__i_Kpl = ((fabs(3.0 + membrane__Vm) < 1.3000000000928935e-6) ? (384615.38458790135 * (3.0000013000000001 + membrane__Vm) * (1.0918250040419466e-10 * pow(external_ion_concentrations__Ko, 0.16) * constant_field_equations__CF_K / (1.0 - exp(1.0000000000714566e-7)) + 1.0918250040419466e-10 * pow(external_ion_concentrations__Ko, 0.16) * constant_field_equations__CF_K / (1.0 - exp(-1.0000000000714566e-7))) - 1.0918250040419466e-10 * pow(external_ion_concentrations__Ko, 0.16) * constant_field_equations__CF_K / (1.0 - exp(1.0000000000714566e-7))) : (8.3986538766456042e-5 * pow(external_ion_concentrations__Ko, 0.16) * (3.0 + membrane__Vm) * constant_field_equations__CF_K / (1.0 - exp(-0.23076923076923078 - 0.076923076923076927 * membrane__Vm))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/matsuoka_model_2003/3_0.png)
## Singularity point: -3.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/matsuoka_model_2003/3_1.png)

## Equation 4:
```
constant_field_equations__CF_Na = (-external_ion_concentrations__Nao * exp(-membrane__F * membrane__Vm / (membrane__R * membrane__T)) + internal_ion_concentrations__Nai) * membrane__F * membrane__Vm / ((1.0 - exp(-membrane__F * membrane__Vm / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
constant_field_equations__CF_Na = ((fabs(membrane__Vm) < 2.6712831923985376e-6) ? (187175.96150898977 * (2.6712831923985376e-6 + membrane__Vm) * (9.9999999999999995e-8 * (-external_ion_concentrations__Nao * exp(9.9999999999999995e-8) + internal_ion_concentrations__Nai) / (1.0 - exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-external_ion_concentrations__Nao * exp(-9.9999999999999995e-8) + internal_ion_concentrations__Nai) / (1.0 - exp(-9.9999999999999995e-8))) - 9.9999999999999995e-8 * (-external_ion_concentrations__Nao * exp(9.9999999999999995e-8) + internal_ion_concentrations__Nai) / (1.0 - exp(9.9999999999999995e-8))) : (0.037435192301797954 * (-external_ion_concentrations__Nao * exp(-0.037435192301797954 * membrane__Vm) + internal_ion_concentrations__Nai) * membrane__Vm / (1.0 - exp(-0.037435192301797954 * membrane__Vm))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/matsuoka_model_2003/4_0.png)

Number of singularities:  4
# Model: mcallister_noble_tsien_1975_modelB(mcallister_noble_tsien_1975_b.cellml)
Number of piecewises: 0
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = (47.0 + membrane__V) / (1.0 - exp(-4.7000000000000002 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.0 + membrane__V) < 9.9999999747524271e-7) ? (-9.9999999747524271e-7 / (1.0 - exp(9.9999999747524276e-8)) + 500000.00126237865 * (47.000000999999997 + membrane__V) * (9.9999999747524271e-7 / (1.0 - exp(9.9999999747524276e-8)) + 9.9999999747524271e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : ((47.0 + membrane__V) / (1.0 - exp(-4.7000000000000002 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/mcallister_noble_tsien_1975_b/1_0.png)

## Equation 2:
```
pacemaker_potassium_current_s_gate__alpha_s = 0.001 * (-pacemaker_potassium_current_s_gate__E_s + membrane__V) / (1.0 - exp(0.20000000000000001 * pacemaker_potassium_current_s_gate__E_s - 0.20000000000000001 * membrane__V))
```
## New Eq:
```
pacemaker_potassium_current_s_gate__alpha_s = ((fabs(52.0 + membrane__V) < 4.9999999873762135e-7) ? (-5.0000000584304868e-10 / (1.0 - exp(1.0000000116860974e-7)) + 1000000.0025247573 * (52.000000500000006 + membrane__V) * (5.0000000584304868e-10 / (1.0 - exp(1.0000000116860974e-7)) + 4.9999999163219401e-10 / (1.0 - exp(-9.999999832643881e-8)))) : (0.001 * (52.0 + membrane__V) / (1.0 - exp(-10.4 - 0.20000000000000001 * membrane__V))))
```
## Singularity point: -52.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/mcallister_noble_tsien_1975_b/2_0.png)

## Equation 3:
```
time_independent_outward_current__i_K1 = 0.35714285714285715 * pacemaker_potassium_current__I_K2 + 0.20000000000000001 * (-time_independent_outward_current__E_K1 + membrane__V) / (1.0 - exp(0.040000000000000001 * time_independent_outward_current__E_K1 - 0.040000000000000001 * membrane__V))
```
## New Eq:
```
time_independent_outward_current__i_K1 = (-1.0 + exp(4.4000000000000004 + 0.040000000000000001 * membrane__V)) / (exp(2.3999999999999999 + 0.040000000000000001 * membrane__V) + exp(4.7999999999999998 + 0.080000000000000002 * membrane__V)) + ((fabs(30.0 + membrane__V) < 2.5000000007935341e-6) ? (-5.0000000015870685e-7 / (1.0 - exp(1.0000000003174136e-7)) + 199999.99993651727 * (30.000002500000001 + membrane__V) * (5.0000000015870685e-7 / (1.0 - exp(1.0000000003174136e-7)) + 5.0000000015870685e-7 / (1.0 - exp(-1.0000000003174136e-7)))) : (0.20000000000000001 * (30.0 + membrane__V) / (1.0 - exp(-1.2 - 0.040000000000000001 * membrane__V))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/mcallister_noble_tsien_1975_b/3_0.png)

## Equation 4:
```
transient_chloride_current_q_gate__alpha_q = 0.0080000000000000002 * membrane__V / (1.0 - exp(-0.10000000000000001 * membrane__V))
```
## New Eq:
```
transient_chloride_current_q_gate__alpha_q = ((fabs(membrane__V) < 9.9999999999999995e-7) ? (-8.0000000000000005e-9 / (1.0 - exp(9.9999999999999995e-8)) + 500000.0 * (9.9999999999999995e-7 + membrane__V) * (8.0000000000000005e-9 / (1.0 - exp(9.9999999999999995e-8)) + 8.0000000000000005e-9 / (1.0 - exp(-9.9999999999999995e-8)))) : (0.0080000000000000002 * membrane__V / (1.0 - exp(-0.10000000000000001 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/mcallister_noble_tsien_1975_b/4_0.png)

Number of singularities:  4
# Model: noble_model_1962(noble_model_1962.cellml)
Number of piecewises: 0
## Equation 1:
```
sodium_channel_m_gate__alpha_m = 0.10000000000000001 * (-48.0 - membrane__V) / (-1.0 + exp(-3.2000000000000002 - 0.066666666666666666 * membrane__V))
```
## New Eq:
```
sodium_channel_m_gate__alpha_m = ((fabs(48.0 + membrane__V) < 1.5000000033182914e-6) ? (1.5000000033182915e-7 / (-1.0 + exp(1.0000000022121943e-7)) + 333333.33259593527 * (48.000001500000003 + membrane__V) * (-1.5000000033182915e-7 / (-1.0 + exp(1.0000000022121943e-7)) - 1.5000000033182915e-7 / (-1.0 + exp(-1.0000000022121943e-7)))) : (0.10000000000000001 * (-48.0 - membrane__V) / (-1.0 + exp(-3.2000000000000002 - 0.066666666666666666 * membrane__V))))
```
## Singularity point: -48.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1962/1_0.png)

## Equation 2:
```
sodium_channel_m_gate__beta_m = 0.12 * (8.0 + membrane__V) / (-1.0 + exp(1.6000000000000001 + 0.20000000000000001 * membrane__V))
```
## New Eq:
```
sodium_channel_m_gate__beta_m = ((fabs(8.0 + membrane__V) < 5.0000000006988898e-7) ? (5.9999999955095972e-8 / (-1.0 + exp(9.9999999925159949e-8)) - 999999.99986022199 * (7.9999995000000004 + membrane__V) * (-5.9999999955095972e-8 / (-1.0 + exp(9.9999999925159949e-8)) - 6.0000000061677387e-8 / (-1.0 + exp(-1.0000000010279564e-7)))) : (0.12 * (8.0 + membrane__V) / (-1.0 + exp(1.6000000000000001 + 0.20000000000000001 * membrane__V))))
```
## Singularity point: -8.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1962/2_0.png)

Number of singularities:  2
# Model: noble_model_1991(noble_model_1991.cellml)
Number of piecewises: 0
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1991/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K = (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (2.0000000001218549e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (7.4867781645490941e-5 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1991/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_Na = (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1991/3_0.png)

## Equation 4:
```
L_type_Ca_channel_d_gate__alpha_d = 30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__alpha_d = ((fabs(19.0 + membrane__V) < 4.0000000112172529e-7) ? (-1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1249999.9964946085 * (19.000000400000001 + membrane__V) * (1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1.2000000033651759e-5 / (1.0 - exp(-1.0000000028043132e-7)))) : (30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1991/4_0.png)

## Equation 5:
```
L_type_Ca_channel_d_gate__beta_d = 12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__beta_d = ((fabs(19.0 + membrane__V) < 1.0000000010279564e-6) ? (1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 499999.99948602181 * (18.999998999999999 + membrane__V) * (-1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 1.2000000012335477e-5 / (-1.0 + exp(-1.0000000010279564e-7)))) : (12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1991/5_0.png)

## Equation 6:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + membrane__V) < 1.0000000010279564e-6) ? (-0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (41.000001000000005 + membrane__V) * (0.00019999999949504854 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)))) : (200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -41.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1991/6_0.png)

Number of singularities:  6
# Model: noble_model_1998(noble_model_1998.cellml)
Number of piecewises: 1
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1998/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K_ds = (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K_ds = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (2.0000000001218549e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (7.4867781645490941e-5 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1998/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_Na_ds = (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na_ds = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1998/3_0.png)

## Equation 4:
```
L_type_Ca_channel_d_gate__alpha_d = 30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__alpha_d = ((fabs(19.0 + membrane__V) < 4.0000000112172529e-7) ? (-1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1249999.9964946085 * (19.000000400000001 + membrane__V) * (1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1.2000000033651759e-5 / (1.0 - exp(-1.0000000028043132e-7)))) : (30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1998/4_0.png)

## Equation 5:
```
L_type_Ca_channel_d_gate__beta_d = 12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__beta_d = ((fabs(19.0 + membrane__V) < 1.0000000010279564e-6) ? (1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 499999.99948602181 * (18.999998999999999 + membrane__V) * (-1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 1.2000000012335477e-5 / (-1.0 + exp(-1.0000000010279564e-7)))) : (12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1998/5_0.png)

## Equation 6:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + membrane__V) < 1.0000000010279564e-6) ? (-0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (41.000001000000005 + membrane__V) * (0.00019999999949504854 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)))) : (200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -41.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_1998/6_0.png)

Number of singularities:  6
# Model: noble_model_2001(noble_model_2001.cellml)
Number of piecewises: 1
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca_cyt = 4.0 * (1.0 - L_type_Ca_channel__FrICa) * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChoncyt * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_cyt = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (6.0000000003655656e-8 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 6.0000000003655656e-8 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 6.0000000003655656e-8 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (0.044920668987294569 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_2001/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChonds * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (1.4000000000852982e-7 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 1.4000000000852982e-7 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 1.4000000000852982e-7 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (0.10481489430368732 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_2001/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_K_cyt = (1.0 - L_type_Ca_channel__FrICa) * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChoncyt * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K_cyt = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (6.0000000003655647e-11 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 6.0000000003655647e-11 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 6.0000000003655647e-11 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (2.2460334493647287e-5 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_2001/3_0.png)

## Equation 4:
```
L_type_Ca_channel__i_Ca_L_K_ds = (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChonds * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K_ds = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.4000000000852982e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 1.4000000000852982e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 1.4000000000852982e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (5.2407447151843657e-5 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_2001/4_0.png)

## Equation 5:
```
L_type_Ca_channel__i_Ca_L_Na_cyt = (1.0 - L_type_Ca_channel__FrICa) * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChoncyt * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na_cyt = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (3.0000000001827826e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 3.0000000001827826e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 3.0000000001827826e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (0.00011230167246823643 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_2001/5_0.png)

## Equation 6:
```
L_type_Ca_channel__i_Ca_L_Na_ds = (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChonds * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na_ds = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (7.0000000004264919e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7)) + 7.0000000004264919e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-1.0000000000609274e-7))) - 7.0000000004264919e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.0000000000609274e-7))) : (0.00026203723575921831 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_2001/6_0.png)

## Equation 7:
```
L_type_Ca_channel_d_gate__alpha_d = 30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__alpha_d = ((fabs(19.0 + membrane__V) < 4.0000000112172529e-7) ? (-1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1249999.9964946085 * (19.000000400000001 + membrane__V) * (1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1.2000000033651759e-5 / (1.0 - exp(-1.0000000028043132e-7)))) : (30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_2001/7_0.png)

## Equation 8:
```
L_type_Ca_channel_d_gate__beta_d = 12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__beta_d = ((fabs(19.0 + membrane__V) < 1.0000000010279564e-6) ? (1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 499999.99948602181 * (18.999998999999999 + membrane__V) * (-1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 1.2000000012335477e-5 / (-1.0 + exp(-1.0000000010279564e-7)))) : (12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_2001/8_0.png)

## Equation 9:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + membrane__V) < 1.0000000010279564e-6) ? (-0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (41.000001000000005 + membrane__V) * (0.00019999999949504854 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)))) : (200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -41.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_model_2001/9_0.png)

Number of singularities:  9
# Model: NN_SAN_model_1984(noble_noble_SAN_model_1984.cellml)
Number of piecewises: 0
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + membrane__V) < 1.0000000010279564e-6) ? (-0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (41.000001000000005 + membrane__V) * (0.00019999999949504854 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)))) : (200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -41.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_noble_SAN_model_1984/1_0.png)

## Equation 2:
```
hyperpolarising_activated_current_y_gate__beta_y = (52.0 + membrane__V) / (1.0 - exp(-10.4 - 0.20000000000000001 * membrane__V))
```
## New Eq:
```
hyperpolarising_activated_current_y_gate__beta_y = ((fabs(52.0 + membrane__V) < 4.9999999873762135e-7) ? (-5.0000000584304871e-7 / (1.0 - exp(1.0000000116860974e-7)) + 1000000.0025247573 * (52.000000500000006 + membrane__V) * (4.99999991632194e-7 / (1.0 - exp(-9.999999832643881e-8)) + 5.0000000584304871e-7 / (1.0 - exp(1.0000000116860974e-7)))) : ((52.0 + membrane__V) / (1.0 - exp(-10.4 - 0.20000000000000001 * membrane__V))))
```
## Singularity point: -52.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_noble_SAN_model_1984/2_0.png)

## Equation 3:
```
intracellular_calcium_concentration__alpha_p = 0.625 * intracellular_calcium_concentration__E0_p / (-1.0 + exp(0.25 * intracellular_calcium_concentration__E0_p))
```
## New Eq:
```
intracellular_calcium_concentration__alpha_p = 0.625 * (64.0 + membrane__V) / (-1.0 + exp(16.0 + 0.25 * membrane__V))
```

## Equation 4:
```
second_inward_current_d_gate__alpha_d = 30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))
```
## New Eq:
```
second_inward_current_d_gate__alpha_d = ((fabs(19.0 + membrane__V) < 4.0000000112172529e-7) ? (-1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1249999.9964946085 * (19.000000400000001 + membrane__V) * (1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1.2000000033651759e-5 / (1.0 - exp(-1.0000000028043132e-7)))) : (30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_noble_SAN_model_1984/4_0.png)

## Equation 5:
```
second_inward_current_d_gate__beta_d = 12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))
```
## New Eq:
```
second_inward_current_d_gate__beta_d = ((fabs(19.0 + membrane__V) < 1.0000000010279564e-6) ? (1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 499999.99948602181 * (18.999998999999999 + membrane__V) * (-1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 1.2000000012335477e-5 / (-1.0 + exp(-1.0000000010279564e-7)))) : (12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_noble_SAN_model_1984/5_0.png)

## Equation 6:
```
second_inward_current__i_siCa = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(100.0 / membrane__RTONF) - extracellular_calcium_concentration__Cao * exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siCa = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (2.0000000001218549e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(-1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_noble_SAN_model_1984/6_0.png)

## Equation 7:
```
second_inward_current__i_siK = 0.01 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(50.0 / membrane__RTONF) - extracellular_potassium_concentration__Kc * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siK = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(-1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_noble_SAN_model_1984/7_0.png)

## Equation 8:
```
second_inward_current__i_siNa = 0.01 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(50.0 / membrane__RTONF) - extracellular_sodium_concentration__Nao * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siNa = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(-1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_noble_SAN_model_1984/8_0.png)

## Equation 9:
```
time_dependent_potassium_current_x_gate__alpha_x = 0.5 * (22.0 + membrane__V) / (1.0 - exp(-4.4000000000000004 - 0.20000000000000001 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_x_gate__alpha_x = ((fabs(22.0 + membrane__V) < 4.9999999873762135e-7) ? (-2.4999999936881068e-7 / (1.0 - exp(9.9999999747524276e-8)) + 1000000.0025247573 * (22.000000499999999 + membrane__V) * (2.4999999936881068e-7 / (1.0 - exp(9.9999999747524276e-8)) + 2.4999999936881068e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.5 * (22.0 + membrane__V) / (1.0 - exp(-4.4000000000000004 - 0.20000000000000001 * membrane__V))))
```
## Singularity point: -22.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_noble_SAN_model_1984/9_0.png)

## Equation 10:
```
time_dependent_potassium_current_x_gate__beta_x = 0.17799999999999999 * (22.0 + membrane__V) / (-1.0 + exp(1.4666666666666666 + 0.066666666666666666 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_x_gate__beta_x = ((fabs(22.0 + membrane__V) < 1.4999999997655777e-6) ? (2.6699999995827282e-7 / (-1.0 + exp(9.9999999984371854e-8)) - 333333.33338542719 * (21.9999985 + membrane__V) * (-2.6699999995827282e-7 / (-1.0 + exp(9.9999999984371854e-8)) - 2.6699999995827282e-7 / (-1.0 + exp(-9.9999999984371854e-8)))) : (0.17799999999999999 * (22.0 + membrane__V) / (-1.0 + exp(1.4666666666666666 + 0.066666666666666666 * membrane__V))))
```
## Singularity point: -22.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_noble_SAN_model_1984/10_0.png)

Number of singularities:  9
# Model: Noble_SAN_model_1989(noble_SAN_model_1989.cellml)
Number of piecewises: 0
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + membrane__V) < 1.0000000010279564e-6) ? (-0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (41.000001000000005 + membrane__V) * (0.00019999999949504854 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)))) : (200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -41.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_SAN_model_1989/1_0.png)

## Equation 2:
```
intracellular_calcium_concentration__alpha_p = 0.625 * intracellular_calcium_concentration__E0_p / (-1.0 + exp(0.25 * intracellular_calcium_concentration__E0_p))
```
## New Eq:
```
intracellular_calcium_concentration__alpha_p = 0.625 * (64.0 + membrane__V) / (-1.0 + exp(16.0 + 0.25 * membrane__V))
```

## Equation 3:
```
second_inward_current_d_gate__alpha_d = 30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))
```
## New Eq:
```
second_inward_current_d_gate__alpha_d = ((fabs(19.0 + membrane__V) < 4.0000000112172529e-7) ? (-1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1249999.9964946085 * (19.000000400000001 + membrane__V) * (1.2000000033651759e-5 / (1.0 - exp(1.0000000028043132e-7)) + 1.2000000033651759e-5 / (1.0 - exp(-1.0000000028043132e-7)))) : (30.0 * (19.0 + membrane__V) / (1.0 - exp(-4.75 - 0.25 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_SAN_model_1989/3_0.png)

## Equation 4:
```
second_inward_current_d_gate__beta_d = 12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))
```
## New Eq:
```
second_inward_current_d_gate__beta_d = ((fabs(19.0 + membrane__V) < 1.0000000010279564e-6) ? (1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 499999.99948602181 * (18.999998999999999 + membrane__V) * (-1.2000000012335477e-5 / (-1.0 + exp(1.0000000010279564e-7)) - 1.2000000012335477e-5 / (-1.0 + exp(-1.0000000010279564e-7)))) : (12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_SAN_model_1989/4_0.png)

## Equation 5:
```
second_inward_current__i_siCa = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(100.0 / membrane__RTONF) - extracellular_calcium_concentration__Cao * exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siCa = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (2.0000000001218549e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.0000000001218549e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(-1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.0000000001218549e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_SAN_model_1989/5_0.png)

## Equation 6:
```
second_inward_current__i_siK = 0.01 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(50.0 / membrane__RTONF) - extracellular_potassium_concentration__Kc * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siK = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(-1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_SAN_model_1989/6_0.png)

## Equation 7:
```
second_inward_current__i_siNa = 0.01 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(50.0 / membrane__RTONF) - extracellular_sodium_concentration__Nao * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siNa = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.0000000000609275e-9 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.0000000000609275e-9 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(-1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.0000000000609275e-9 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.0000000000609274e-7)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/noble_SAN_model_1989/7_0.png)

Number of singularities:  6
# Model: nygren_atrial_model_1998(nygren_atrial_model_1998.cellml)
Number of piecewises: 0
## Equation 1:
```
sodium_current__i_Na = pow(membrane__F, 2) * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp((-sodium_current__E_Na + membrane__V) * membrane__F / (membrane__R * membrane__T))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
sodium_current__i_Na = ((fabs(membrane__V) < 2.6380041870925617e-6) ? (-189537.22759290531 * (-2.6380041870925617e-6 + membrane__V) * (-0.0096487000000000014 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(1.0000000000000001e-7 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(1.0000000000000001e-7)) - 0.0096487000000000014 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-1.0000000000000001e-7 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-1.0000000000000001e-7))) + 0.0096487000000000014 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(1.0000000000000001e-7 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(1.0000000000000001e-7))) : (3657.5756957513308 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(0.037907445518581065 * membrane__V - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / (-1.0 + exp(0.037907445518581065 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/nygren_atrial_model_1998/1_0.png)

Number of singularities:  1
# Model: ohara_rudy_2011_endo(ohara_rudy_2011_endo.cellml)
Number of piecewises: 16
## Equation 1:
```
ICaL__PhiCaK = (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_2011_endo/1_0.png)

## Equation 2:
```
ICaL__PhiCaL = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_2011_endo/2_0.png)

## Equation 3:
```
ICaL__PhiCaNa = (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_2011_endo/3_0.png)

## Equation 4:
```
ICab__ICab = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(-9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * ICab__PCab * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_2011_endo/4_0.png)

## Equation 5:
```
INab__INab = (-extracellular__nao + intracellular_ions__nai * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (3.75e-10 * pow(physical_constants__F, 2) * (-extracellular__nao + intracellular_ions__nai * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_2011_endo/5_0.png)

Number of singularities:  5
# Model: ohara_rudy_2011_epi(ohara_rudy_2011_epi.cellml)
Number of piecewises: 16
## Equation 1:
```
ICaL__PhiCaK = (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_2011_epi/1_0.png)

## Equation 2:
```
ICaL__PhiCaL = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_2011_epi/2_0.png)

## Equation 3:
```
ICaL__PhiCaNa = (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_2011_epi/3_0.png)

## Equation 4:
```
ICab__ICab = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(-9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * ICab__PCab * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_2011_epi/4_0.png)

## Equation 5:
```
INab__INab = (-extracellular__nao + intracellular_ions__nai * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (3.75e-10 * pow(physical_constants__F, 2) * (-extracellular__nao + intracellular_ions__nai * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_2011_epi/5_0.png)

Number of singularities:  5
# Model: ohara_rudy_cipa_v1_2017(ohara_rudy_cipa_v1_2017.cellml)
Number of piecewises: 16
## Equation 1:
```
ICaL__PhiCaK = (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK = ((fabs(membrane__v) < 2.6712338705498262e-6) ? (2.671233870549826e-13 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + membrane__v) * (2.671233870549826e-13 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)) - 2.671233870549826e-13 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)))) : (0.037435883507802616 * pow(membrane__v, 2) * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(0.037435883507802616 * membrane__v)) / (-1.0 + exp(0.037435883507802616 * membrane__v))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_cipa_v1_2017/1_0.png)

## Equation 2:
```
ICaL__PhiCaL = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL = ((fabs(membrane__v) < 1.3356169352749131e-6) ? (2.671233870549826e-13 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 374358.83507802623 * (-1.3356169352749131e-6 + membrane__v) * (2.671233870549826e-13 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)) - 2.671233870549826e-13 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)))) : (0.14974353403121046 * pow(membrane__v, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(0.074871767015605231 * membrane__v)) / (-1.0 + exp(0.074871767015605231 * membrane__v))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_cipa_v1_2017/2_0.png)

## Equation 3:
```
ICaL__PhiCaNa = (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa = ((fabs(membrane__v) < 2.6712338705498262e-6) ? (2.671233870549826e-13 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + membrane__v) * (2.671233870549826e-13 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)) - 2.671233870549826e-13 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)))) : (0.037435883507802616 * pow(membrane__v, 2) * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(0.037435883507802616 * membrane__v)) / (-1.0 + exp(0.037435883507802616 * membrane__v))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_cipa_v1_2017/3_0.png)

## Equation 4:
```
ICab__ICab = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 1.3356169352749131e-6) ? (-374358.83507802623 * (-1.3356169352749131e-6 + membrane__v) * (2.671233870549826e-13 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(-9.9999999999999995e-8)) * ICab__PCab / (-1.0 + exp(-9.9999999999999995e-8)) - 2.671233870549826e-13 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(9.9999999999999995e-8)) * ICab__PCab / (-1.0 + exp(9.9999999999999995e-8))) + 2.671233870549826e-13 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(9.9999999999999995e-8)) * ICab__PCab / (-1.0 + exp(9.9999999999999995e-8))) : (0.14974353403121046 * pow(membrane__v, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(0.074871767015605231 * membrane__v)) * ICab__PCab / (-1.0 + exp(0.074871767015605231 * membrane__v))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_cipa_v1_2017/4_0.png)

## Equation 5:
```
INab__INab = (-extracellular__nao + intracellular_ions__nai * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 2.6712338705498262e-6) ? (-187179.41753901311 * (-2.6712338705498262e-6 + membrane__v) * (2.671233870549826e-13 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * INab__PNab / (-1.0 + exp(-9.9999999999999995e-8)) - 2.671233870549826e-13 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * INab__PNab / (-1.0 + exp(9.9999999999999995e-8))) + 2.671233870549826e-13 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * INab__PNab / (-1.0 + exp(9.9999999999999995e-8))) : (0.037435883507802616 * pow(membrane__v, 2) * (-extracellular__nao + intracellular_ions__nai * exp(0.037435883507802616 * membrane__v)) * INab__PNab / (-1.0 + exp(0.037435883507802616 * membrane__v))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ohara_rudy_cipa_v1_2017/5_0.png)

Number of singularities:  5
# Model: paci_hyttinen_aaltosetala_severi_atrialVersion(paci_hyttinen_aaltosetala_severi_atrialVersion.cellml)
Number of piecewises: 9
## Equation 1:
```
i_CaL__i_CaL = 4.0 * pow(model_parameters__F, 2) * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(2.0 * Membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * Membrane__Vm * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / ((-1.0 + exp(2.0 * Membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_CaL__i_CaL = ((fabs(Membrane__Vm) < 4.3086710741444596e-12 * fabs(model_parameters__T)) ? (-116045061550.51096 * (-4.3086710741444596e-12 * model_parameters__T + Membrane__Vm) * (-0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(9.9999999999999995e-8)) - 0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(-9.9999999999999995e-8))) / model_parameters__T + 0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(9.9999999999999995e-8))) : (4478658957.2358274 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(23209.012310102189 * Membrane__Vm / model_parameters__T)) * Membrane__Vm * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / ((-1.0 + exp(23209.012310102189 * Membrane__Vm / model_parameters__T)) * model_parameters__T)))
```

Number of singularities:  1
# Model: paci_hyttinen_aaltosetala_severi_ventricularVersion(paci_hyttinen_aaltosetala_severi_ventricularVersion.cellml)
Number of piecewises: 13
## Equation 1:
```
i_CaL__i_CaL = 4.0 * pow(model_parameters__F, 2) * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(2.0 * Membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * Membrane__Vm * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / ((-1.0 + exp(2.0 * Membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_CaL__i_CaL = ((fabs(Membrane__Vm) < 4.3086710741444596e-12 * fabs(model_parameters__T)) ? (-116045061550.51096 * (-4.3086710741444596e-12 * model_parameters__T + Membrane__Vm) * (-0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(9.9999999999999995e-8)) - 0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(-9.9999999999999995e-8))) / model_parameters__T + 0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(9.9999999999999995e-8))) : (4478658957.2358274 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(23209.012310102189 * Membrane__Vm / model_parameters__T)) * Membrane__Vm * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / ((-1.0 + exp(23209.012310102189 * Membrane__Vm / model_parameters__T)) * model_parameters__T)))
```

Number of singularities:  1
# Model: pandit_clark_giles_demir_2001_version06_variant01(pandit_clark_giles_demir_2001_endocardial_cell.cellml)
Number of piecewises: 2
## Equation 1:
```
sodium_current_m_gate__tau_m = 0.0013600000000000001 / (0.080000000000000002 * exp(-0.090909090909090912 * membrane__V) + 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V)))
```
## New Eq:
```
sodium_current_m_gate__tau_m = 0.0013600000000000001 / (0.080000000000000002 * exp(-0.090909090909090912 * membrane__V) + ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V)))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/pandit_clark_giles_demir_2001_endocardial_cell/1_0.png)

Number of singularities:  1
# Model: pandit_clark_giles_demir_2001(pandit_clark_giles_demir_2001_epicardial_cell.cellml)
Number of piecewises: 2
## Equation 1:
```
sodium_current_m_gate__tau_m = 0.0013600000000000001 / (0.080000000000000002 * exp(-0.090909090909090912 * membrane__V) + 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V)))
```
## New Eq:
```
sodium_current_m_gate__tau_m = 0.0013600000000000001 / (0.080000000000000002 * exp(-0.090909090909090912 * membrane__V) + ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V)))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/pandit_clark_giles_demir_2001_epicardial_cell/1_0.png)

Number of singularities:  1
# Model: pasek_simurda_christe_2006(pasek_simurda_christe_2006.cellml)
Number of piecewises: 0
## Equation 1:
```
i_Nas_h_gate__beta_h = 18.77 * (64.400000000000006 + Vms__Vms) / (1.0 - exp(-14.168000000000001 - 0.22 * Vms__Vms))
```
## New Eq:
```
i_Nas_h_gate__beta_h = ((fabs(64.400000000000006 + Vms__Vms) < 4.5454545727352524e-7) ? (-8.531818233024069e-6 / (1.0 - exp(1.0000000060017555e-7)) + 1099999.9933980689 * (64.400000454545463 + Vms__Vms) * (8.531818233024069e-6 / (1.0 - exp(1.0000000060017555e-7)) + 8.531818233024069e-6 / (1.0 - exp(-1.0000000060017555e-7)))) : (18.77 * (64.400000000000006 + Vms__Vms) / (1.0 - exp(-14.168000000000001 - 0.22 * Vms__Vms))))
```
## Singularity point: -64.400000000000006
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_christe_2006/1_0.png)

## Equation 2:
```
i_Nas_m_gate__alpha_m = 117.26000000000001 * (59.299999999999997 + Vms__Vms) / (1.0 - exp(-32.615000000000002 - 0.55000000000000004 * Vms__Vms))
```
## New Eq:
```
i_Nas_m_gate__alpha_m = ((fabs(59.300000000000004 + Vms__Vms) < 1.8181818361995283e-7) ? (-2.1320000627866875e-5 / (1.0 - exp(1.0000000294496659e-7)) + 2749999.9727482134 * (59.300000181818184 + Vms__Vms) * (2.1319999794684464e-5 / (1.0 - exp(-9.9999999036981543e-8)) + 2.1320000627866875e-5 / (1.0 - exp(1.0000000294496659e-7)))) : (117.26000000000001 * (59.299999999999997 + Vms__Vms) / (1.0 - exp(-32.615000000000002 - 0.55000000000000004 * Vms__Vms))))
```
## Singularity point: -59.300000000000004
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_christe_2006/2_0.png)

## Equation 3:
```
i_Cas__i_Cas = 4.0 * pow(model_parameters__F, 2) * (-0.34100000000000003 * model_parameters__Cae + ion_concentrations__Cass * exp(2.0 * Vms__Vms * model_parameters__F / (model_parameters__R * model_parameters__T))) * ((0.10000000000000001 - 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C2 + (0.90000000000000002 + 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C1) * Vms__Vms * i_Cas__Co * membrane_permeabilities__gCas / ((-1.0 + exp(2.0 * Vms__Vms * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_Cas__i_Cas = ((fabs(Vms__Vms) < 1.2701813471502591e-6) ? (-393644.57769891288 * (-1.2701813471502591e-6 + Vms__Vms) * (-5.2689000000000005e-11 * (-0.40920000000000001 + ion_concentrations__Cass * exp(1.0000000000000001e-7)) * ((0.10000000000000001 - 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C2 + (0.90000000000000002 + 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C1) * i_Cas__Co / (-1.0 + exp(1.0000000000000001e-7)) - 5.2689000000000005e-11 * (-0.40920000000000001 + ion_concentrations__Cass * exp(-1.0000000000000001e-7)) * ((0.10000000000000001 - 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C2 + (0.90000000000000002 + 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C1) * i_Cas__Co / (-1.0 + exp(-1.0000000000000001e-7))) + 5.2689000000000005e-11 * (-0.40920000000000001 + ion_concentrations__Cass * exp(1.0000000000000001e-7)) * ((0.10000000000000001 - 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C2 + (0.90000000000000002 + 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C1) * i_Cas__Co / (-1.0 + exp(1.0000000000000001e-7))) : (4.1481478308756044e-5 * (-0.40920000000000001 + ion_concentrations__Cass * exp(0.078728915539782576 * Vms__Vms)) * ((0.10000000000000001 - 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C2 + (0.90000000000000002 + 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C1) * Vms__Vms * i_Cas__Co / (-1.0 + exp(0.078728915539782576 * Vms__Vms))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_christe_2006/3_0.png)

Number of singularities:  3
# Model: pasek_model_2008(pasek_simurda_orchard_christe_2008.cellml)
Number of piecewises: 0
## Equation 1:
```
i_Kr_s_xr_gate__tau_xr = 0.001 / (0.00060999999999999997 * (38.899999999999999 + Vm_s__Vm_s) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * Vm_s__Vm_s)) + 0.0013799999999999999 * (14.199999999999999 + Vm_s__Vm_s) / (1.0 - exp(-1.7465999999999999 - 0.123 * Vm_s__Vm_s)))
```
## New Eq:
```
i_Kr_s_xr_gate__tau_xr = 0.001 / (((fabs(38.899999999999999 + Vm_s__Vm_s) < 6.8965517030505907e-7) ? (4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)) - 725000.00221680664 * (38.899999310344825 + Vm_s__Vm_s) * (-4.2068965171893065e-10 / (-1.0 + exp(-9.9999999179090074e-8)) - 4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)))) : (0.00060999999999999997 * (38.899999999999999 + Vm_s__Vm_s) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * Vm_s__Vm_s)))) + ((fabs(14.199999999999999 + Vm_s__Vm_s) < 8.1300813015161566e-7) ? (-1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 614999.99994681031 * (14.200000813008129 + Vm_s__Vm_s) * (1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 1.1219512196092296e-9 / (1.0 - exp(-1.0000000000864873e-7)))) : (0.0013799999999999999 * (14.199999999999999 + Vm_s__Vm_s) / (1.0 - exp(-1.7465999999999999 - 0.123 * Vm_s__Vm_s)))))
```
## Singularity point: -14.199999999999999
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_orchard_christe_2008/1_0.png)
## Singularity point: -38.899999999999999
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_orchard_christe_2008/1_1.png)

## Equation 2:
```
i_Ks_s_xs_gate__tau_xs = 0.001 / (0.00013100000000000001 * (30.0 + Vm_s__Vm_s) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * Vm_s__Vm_s)) + 7.1899999999999999e-5 * (30.0 + Vm_s__Vm_s) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * Vm_s__Vm_s)))
```
## New Eq:
```
i_Ks_s_xs_gate__tau_xs = 0.001 * ((fabs(30.0 + Vm_s__Vm_s) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + Vm_s__Vm_s) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + Vm_s__Vm_s) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * Vm_s__Vm_s)) + 7.1899999999999999e-5 * (30.0 + Vm_s__Vm_s) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * Vm_s__Vm_s)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_orchard_christe_2008/2_0.png)

## Equation 3:
```
i_CaL_s__i_CaL_s = 4.0 * pow(model_parameters__F, 2) * (0.001 * exp(2.0 * Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T)) - 0.34100000000000003 * model_parameters__Ca_e) * (i_CaL_s__Ccao + i_CaL_s__Co) * Vm_s__Vm_s * i_CaL_s_y_gate__y * membrane_permeabilities__P_CaL_s / ((-1.0 + exp(2.0 * Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_CaL_s__i_CaL_s = ((fabs(Vm_s__Vm_s) < 1.3347668393782383e-6) ? (-374597.25942315906 * (-1.3347668393782383e-6 + Vm_s__Vm_s) * (-7.425432175987399e-7 * (-0.61380000000000001 + 0.001 * exp(9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(9.9999999999999995e-8)) - 7.425432175987399e-7 * (-0.61380000000000001 + 0.001 * exp(-9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(-9.9999999999999995e-8))) + 7.425432175987399e-7 * (-0.61380000000000001 + 0.001 * exp(9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(9.9999999999999995e-8))) : (0.55630930863148487 * (-0.61380000000000001 + 0.001 * exp(0.07491945188463181 * Vm_s__Vm_s)) * (i_CaL_s__Ccao + i_CaL_s__Co) * Vm_s__Vm_s * i_CaL_s_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(0.07491945188463181 * Vm_s__Vm_s))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_orchard_christe_2008/3_0.png)

## Equation 4:
```
i_CaL_s__i_KL_s = pow(model_parameters__F, 2) * (-model_parameters__K_e + ion_concentrations__K_i * exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * (i_CaL_s__Ccao + i_CaL_s__Co) * Vm_s__Vm_s * i_CaL_s_y_gate__y * membrane_permeabilities__P_KL_s / ((1.0 - 2.1834061135371177 * (i_CaL_s__i_CaL_s + i_CaL_t__i_CaL_t) / (model_parameters__Sms + model_parameters__Smt)) * (-1.0 + exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_CaL_s__i_KL_s = ((fabs(Vm_s__Vm_s) < 2.6695336787564767e-6) ? (-187298.62971157953 * (-2.6695336787564767e-6 + Vm_s__Vm_s) * (-1.7821037222369758e-12 * (-5.4000000000000004 + ion_concentrations__K_i * exp(9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y / ((-1.0 + exp(9.9999999999999995e-8)) * (1.0 - 20430.198966619231 * i_CaL_s__i_CaL_s - 20205.350866353103 * (0.001 * exp(0.07491945188463181 * Vm_t__Vm_t) - 0.34100000000000003 * ion_concentrations__Ca_t) * (i_CaL_t__TCcao + i_CaL_t__TCo) * Vm_t__Vm_t * i_CaL_t_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(0.07491945188463181 * Vm_t__Vm_t)))) - 1.7821037222369758e-12 * (-5.4000000000000004 + ion_concentrations__K_i * exp(-9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y / ((-1.0 + exp(-9.9999999999999995e-8)) * (1.0 - 20430.198966619231 * i_CaL_s__i_CaL_s - 20205.350866353103 * (0.001 * exp(0.07491945188463181 * Vm_t__Vm_t) - 0.34100000000000003 * ion_concentrations__Ca_t) * (i_CaL_t__TCcao + i_CaL_t__TCo) * Vm_t__Vm_t * i_CaL_t_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(0.07491945188463181 * Vm_t__Vm_t))))) + 1.7821037222369758e-12 * (-5.4000000000000004 + ion_concentrations__K_i * exp(9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y / ((-1.0 + exp(9.9999999999999995e-8)) * (1.0 - 20430.198966619231 * i_CaL_s__i_CaL_s - 20205.350866353103 * (0.001 * exp(0.07491945188463181 * Vm_t__Vm_t) - 0.34100000000000003 * ion_concentrations__Ca_t) * (i_CaL_t__TCcao + i_CaL_t__TCo) * Vm_t__Vm_t * i_CaL_t_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(0.07491945188463181 * Vm_t__Vm_t))))) : (6.6757117035778174e-7 * (-5.4000000000000004 + ion_concentrations__K_i * exp(0.037459725942315905 * Vm_s__Vm_s)) * (i_CaL_s__Ccao + i_CaL_s__Co) * Vm_s__Vm_s * i_CaL_s_y_gate__y / ((-1.0 + exp(0.037459725942315905 * Vm_s__Vm_s)) * (1.0 - 20430.198966619231 * i_CaL_s__i_CaL_s - 20205.350866353103 * (0.001 * exp(0.07491945188463181 * Vm_t__Vm_t) - 0.34100000000000003 * ion_concentrations__Ca_t) * (i_CaL_t__TCcao + i_CaL_t__TCo) * Vm_t__Vm_t * i_CaL_t_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(0.07491945188463181 * Vm_t__Vm_t))))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_orchard_christe_2008/4_0.png)
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_orchard_christe_2008/4_1.png)

## Equation 5:
```
i_nsK_s__i_nsK_s = pow(model_parameters__F, 2) * (-0.75 * model_parameters__K_e + 0.75 * ion_concentrations__K_i * exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * Vm_s__Vm_s * membrane_permeabilities__P_nsK_s / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_nsK_s__i_nsK_s = ((fabs(Vm_s__Vm_s) < 2.6695336787564767e-6) ? (-187298.62971157953 * (-2.6695336787564767e-6 + Vm_s__Vm_s) * (-8.554716652752149e-14 * (-4.0500000000000007 + 0.75 * ion_concentrations__K_i * exp(9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(9.9999999999999995e-8))) - 8.554716652752149e-14 * (-4.0500000000000007 + 0.75 * ion_concentrations__K_i * exp(-9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(-9.9999999999999995e-8)))) + 8.554716652752149e-14 * (-4.0500000000000007 + 0.75 * ion_concentrations__K_i * exp(9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(9.9999999999999995e-8)))) : (3.2045734132626158e-8 * (-4.0500000000000007 + 0.75 * ion_concentrations__K_i * exp(0.037459725942315905 * Vm_s__Vm_s)) * Vm_s__Vm_s / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(0.037459725942315905 * Vm_s__Vm_s)))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_orchard_christe_2008/5_0.png)

## Equation 6:
```
i_nsNa_s__i_nsNa_s = pow(model_parameters__F, 2) * (-0.75 * model_parameters__Na_e + 0.75 * ion_concentrations__Na_i * exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * Vm_s__Vm_s * membrane_permeabilities__P_nsNa_s / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_nsNa_s__i_nsNa_s = ((fabs(Vm_s__Vm_s) < 2.6695336787564767e-6) ? (-187298.62971157953 * (-2.6695336787564767e-6 + Vm_s__Vm_s) * (-8.554716652752149e-14 * (-105.0 + 0.75 * ion_concentrations__Na_i * exp(9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(9.9999999999999995e-8))) - 8.554716652752149e-14 * (-105.0 + 0.75 * ion_concentrations__Na_i * exp(-9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(-9.9999999999999995e-8)))) + 8.554716652752149e-14 * (-105.0 + 0.75 * ion_concentrations__Na_i * exp(9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(9.9999999999999995e-8)))) : (3.2045734132626158e-8 * (-105.0 + 0.75 * ion_concentrations__Na_i * exp(0.037459725942315905 * Vm_s__Vm_s)) * Vm_s__Vm_s / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(0.037459725942315905 * Vm_s__Vm_s)))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/pasek_simurda_orchard_christe_2008/6_0.png)

Number of singularities:  7
# Model: priebe_beuckelmann_1998(priebe_beuckelmann_1998.cellml)
Number of piecewises: 20
## Equation 1:
```
INa_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa_m_gate__alpha_m = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/priebe_beuckelmann_1998/1_0.png)

Number of singularities:  1
# Model: ramirez_2000(ramirez_nattel_courtemanche_2000.cellml)
Number of piecewises: 4
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/ramirez_nattel_courtemanche_2000/1_0.png)

## Equation 2:
```
rapid_delayed_rectifier_K_current_xr_gate__alpha_xr = 0.040000000000000001 * (-248.0 + membrane__V) / (1.0 - exp(8.8571428571428577 - 0.035714285714285712 * membrane__V))
```
## New Eq:
```
rapid_delayed_rectifier_K_current_xr_gate__alpha_xr = ((fabs(-248.0 + membrane__V) < 2.8000000042993634e-6) ? (-1.1200000017197454e-7 / (1.0 - exp(1.0000000015354869e-7)) + 178571.42829723447 * (-247.9999972 + membrane__V) * (1.1200000017197454e-7 / (1.0 - exp(1.0000000015354869e-7)) + 1.1200000017197454e-7 / (1.0 - exp(-1.0000000015354869e-7)))) : (0.040000000000000001 * (-248.0 + membrane__V) / (1.0 - exp(8.8571428571428577 - 0.035714285714285712 * membrane__V))))
```
## Singularity point: 248.00000000000000
![Singularity](diagrams/new/no_singularity_fixes/ramirez_nattel_courtemanche_2000/2_0.png)

## Equation 3:
```
rapid_delayed_rectifier_K_current_xr_gate__beta_xr = 0.028000000000000001 * (163.0 + membrane__V) / (-1.0 + exp(7.7619047619047619 + 0.047619047619047616 * membrane__V))
```
## New Eq:
```
rapid_delayed_rectifier_K_current_xr_gate__beta_xr = ((fabs(163.0 + membrane__V) < 2.0999999890136678e-6) ? (5.8799999692382698e-8 / (-1.0 + exp(9.9999999476841319e-8)) - 238095.23934085399 * (162.99999790000001 + membrane__V) * (-5.8799999692382698e-8 / (-1.0 + exp(9.9999999476841319e-8)) - 5.8799999692382698e-8 / (-1.0 + exp(-9.9999999476841319e-8)))) : (0.028000000000000001 * (163.0 + membrane__V) / (-1.0 + exp(7.7619047619047619 + 0.047619047619047616 * membrane__V))))
```
## Singularity point: -163.00000000000000
![Singularity](diagrams/new/no_singularity_fixes/ramirez_nattel_courtemanche_2000/3_0.png)

## Equation 4:
```
sarcolemmal_Ca_current_d_gate__tau_d = 28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * (10.0 + membrane__V))
```
## New Eq:
```
sarcolemmal_Ca_current_d_gate__tau_d = ((fabs(10.0 + membrane__V) < 6.2400000011564316e-7) ? (801282.05113355326 * (10.000000624 + membrane__V) * (45787545.779060178 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7)) + 45787545.779060178 * (1.0 - exp(-1.0000000001853256e-7)) / (1.0 + exp(-1.0000000001853256e-7))) - 45787545.779060178 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7))) : (28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * (10.0 + membrane__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/ramirez_nattel_courtemanche_2000/4_0.png)

## Equation 5:
```
slow_delayed_rectifier_K_current_xs_gate__alpha_xs = 1.0000000000000001e-5 * (28.5 + membrane__V) / (1.0 - exp(-0.24782608695652175 - 0.0086956521739130436 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_K_current_xs_gate__alpha_xs = ((fabs(28.5 + membrane__V) < 1.1499999999387001e-5) ? (-1.1499999999387001e-10 / (1.0 - exp(9.9999999994669564e-8)) + 43478.260871882798 * (28.500011499999999 + membrane__V) * (1.1499999999387001e-10 / (1.0 - exp(9.9999999994669564e-8)) + 1.1499999999387001e-10 / (1.0 - exp(-9.9999999994669564e-8)))) : (1.0000000000000001e-5 * (28.5 + membrane__V) / (1.0 - exp(-0.24782608695652175 - 0.0086956521739130436 * membrane__V))))
```
## Singularity point: -28.500000000000000
![Singularity](diagrams/new/no_singularity_fixes/ramirez_nattel_courtemanche_2000/5_0.png)

## Equation 6:
```
slow_delayed_rectifier_K_current_xs_gate__beta_xs = 0.00023000000000000001 * (28.5 + membrane__V) / (-1.0 + exp(8.6363636363636367 + 0.30303030303030304 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_K_current_xs_gate__beta_xs = ((fabs(28.5 + membrane__V) < 3.3000000065896984e-7) ? (7.5899999743000998e-11 / (-1.0 + exp(9.9999999661397887e-8)) - 1515151.5121259419 * (28.499999670000001 + membrane__V) * (-7.5899999743000998e-11 / (-1.0 + exp(9.9999999661397887e-8)) - 7.5900000560125136e-11 / (-1.0 + exp(-1.0000000073797778e-7)))) : (0.00023000000000000001 * (28.5 + membrane__V) / (-1.0 + exp(8.6363636363636367 + 0.30303030303030304 * membrane__V))))
```
## Singularity point: -28.500000000000000
![Singularity](diagrams/new/no_singularity_fixes/ramirez_nattel_courtemanche_2000/6_0.png)

Number of singularities:  6
# Model: sachse_model_2007(sachse_moreno_abildskov_2008_b.cellml)
Number of piecewises: 0
## Equation 1:
```
I_Shkr__I_Shkr = pow(model_parameters__F, 2) * (-model_parameters__Ko * exp(-membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T)) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr * membrane__Vm / ((1.0 - exp(-membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
I_Shkr__I_Shkr = ((fabs(membrane__Vm) < 8.6113989637305703e-9 * fabs(model_parameters__T)) ? (58062575.210589647 * (8.6113989637305703e-9 * model_parameters__T + membrane__Vm) * (0.0096500000000000006 * (-model_parameters__Ko * exp(1.0000000000000001e-7) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr / (1.0 - exp(1.0000000000000001e-7)) + 0.0096500000000000006 * (-model_parameters__Ko * exp(-1.0000000000000001e-7) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr / (1.0 - exp(-1.0000000000000001e-7))) / model_parameters__T - 0.0096500000000000006 * (-model_parameters__Ko * exp(1.0000000000000001e-7) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr / (1.0 - exp(1.0000000000000001e-7))) : (1120607.7015643802 * (-model_parameters__Ko * exp(-11.612515042117931 * membrane__Vm / model_parameters__T) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr * membrane__Vm / ((1.0 - exp(-11.612515042117931 * membrane__Vm / model_parameters__T)) * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/sachse_moreno_abildskov_2008_b/1_0.png)

Number of singularities:  1
# Model: sakmann_model_2000_epi(sakmann_model_2000_epi.cellml)
Number of piecewises: 1
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = ((fabs(-50.0 + membrane__V) < 1.3356880330661625e-6) ? (374338.90820464725 * (-49.999998664311967 + membrane__V) * (2.2000000001340402e-8 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.2000000001340402e-8 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.2000000001340402e-8 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (0.016470911962008009 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/sakmann_model_2000_epi/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K_ds = (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K_ds = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (2.2000000001340403e-11 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 2.2000000001340403e-11 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 2.2000000001340403e-11 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (8.2354559810040044e-6 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/sakmann_model_2000_epi/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_Na_ds = (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na_ds = ((fabs(-50.0 + membrane__V) < 2.6713760661323249e-6) ? (187169.45410232362 * (-49.999997328623934 + membrane__V) * (1.1000000000670202e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7)) + 1.1000000000670202e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-1.0000000000609274e-7)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-1.0000000000609274e-7))) - 1.1000000000670202e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.0000000000609274e-7)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.0000000000609274e-7))) : (4.1177279905020022e-5 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/sakmann_model_2000_epi/3_0.png)

## Equation 4:
```
L_type_Ca_channel_d_gate__alpha_d = 30.0 * (19.0 + membrane__V) / (1.0 - exp(-2.6388888888888888 - 0.1388888888888889 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__alpha_d = ((fabs(19.0 + membrane__V) < 7.1999999917693458e-7) ? (-2.1599999975308037e-5 / (1.0 - exp(9.9999999885685355e-8)) + 694444.44523829618 * (19.000000719999999 + membrane__V) * (2.1599999975308037e-5 / (1.0 - exp(9.9999999885685355e-8)) + 2.1599999975308037e-5 / (1.0 - exp(-9.9999999885685355e-8)))) : (30.0 * (19.0 + membrane__V) / (1.0 - exp(-2.6388888888888888 - 0.1388888888888889 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/sakmann_model_2000_epi/4_0.png)

## Equation 5:
```
L_type_Ca_channel_d_gate__beta_d = 12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.0555555555555556 + 0.055555555555555552 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__beta_d = ((fabs(19.0 + membrane__V) < 1.7999999997186933e-6) ? (2.1599999996624319e-5 / (-1.0 + exp(9.9999999984371841e-8)) - 277777.77782118932 * (18.9999982 + membrane__V) * (-2.1599999996624319e-5 / (-1.0 + exp(9.9999999984371841e-8)) - 2.1599999996624319e-5 / (-1.0 + exp(-9.9999999984371841e-8)))) : (12.0 * (19.0 + membrane__V) / (-1.0 + exp(1.0555555555555556 + 0.055555555555555552 * membrane__V))))
```
## Singularity point: -19.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/sakmann_model_2000_epi/5_0.png)

## Equation 6:
```
L_type_Ca_channel_f_gate__alpha_f = 6.25 * (34.0 + membrane__V) / (-1.0 + exp(6.666666666666667 + 0.19607843137254904 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_f_gate__alpha_f = ((fabs(34.0 + membrane__V) < 5.0999999956502506e-7) ? (3.1874999972814066e-6 / (-1.0 + exp(9.9999999914710805e-8)) - 980392.15769891371 * (33.99999949 + membrane__V) * (-3.1874999972814066e-6 / (-1.0 + exp(9.9999999914710805e-8)) - 3.1874999972814066e-6 / (-1.0 + exp(-9.9999999914710805e-8)))) : (6.25 * (34.0 + membrane__V) / (-1.0 + exp(6.666666666666667 + 0.19607843137254904 * membrane__V))))
```
## Singularity point: -34.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/sakmann_model_2000_epi/6_0.png)

## Equation 7:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + membrane__V) < 1.0000000010279564e-6) ? (-0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (41.000001000000005 + membrane__V) * (0.00019999999949504854 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00020000000091613401 / (1.0 - exp(1.0000000045806701e-7)))) : (200.0 * (41.0 + membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -41.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/sakmann_model_2000_epi/7_0.png)

## Equation 8:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 0.001 / (0.00060999999999999997 * (38.899999999999999 + membrane__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * membrane__V)) + 0.0013799999999999999 * (14.199999999999999 + membrane__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * membrane__V)))
```
## New Eq:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 0.001 / (((fabs(38.899999999999999 + membrane__V) < 6.8965517030505907e-7) ? (4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)) - 725000.00221680664 * (38.899999310344825 + membrane__V) * (-4.2068965171893065e-10 / (-1.0 + exp(-9.9999999179090074e-8)) - 4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)))) : (0.00060999999999999997 * (38.899999999999999 + membrane__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * membrane__V)))) + ((fabs(14.199999999999999 + membrane__V) < 8.1300813015161566e-7) ? (-1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 614999.99994681031 * (14.200000813008129 + membrane__V) * (1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 1.1219512196092296e-9 / (1.0 - exp(-1.0000000000864873e-7)))) : (0.0013799999999999999 * (14.199999999999999 + membrane__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * membrane__V)))))
```
## Singularity point: -14.199999999999999
![Singularity](diagrams/new/no_singularity_fixes/sakmann_model_2000_epi/8_0.png)
## Singularity point: -38.899999999999999
![Singularity](diagrams/new/no_singularity_fixes/sakmann_model_2000_epi/8_1.png)

## Equation 9:
```
slow_delayed_rectifier_potassium_current_xs_gate__tau_xs = 0.001 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs_gate__tau_xs = 0.001 * ((fabs(30.0 + membrane__V) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + membrane__V) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/sakmann_model_2000_epi/9_0.png)

Number of singularities:  10
# Model: shannon_wang_puglisi_weber_bers_2004_model_updated(shannon_wang_puglisi_weber_bers_2004.cellml)
Number of piecewises: 4
## Equation 1:
```
ICaL_d_gate__tau_d = 28.571428571428569 * (1.0 - exp(-2.4166666666666665 - 0.16666666666666666 * cell__V)) * ICaL_d_gate__d_infinity / (14.5 + cell__V)
```
## New Eq:
```
ICaL_d_gate__tau_d = ((fabs(14.5 + cell__V) < 5.999999999062311e-7) ? (833333.33346356789 * (14.5000006 + cell__V) * (47619047.626489595 * (1.0 - exp(9.9999999984371854e-8)) / (1.0 + exp(9.9999999984371854e-8)) + 47619047.626489595 * (1.0 - exp(-9.9999999984371854e-8)) / (1.0 + exp(-9.9999999984371854e-8))) - 47619047.626489595 * (1.0 - exp(9.9999999984371854e-8)) / (1.0 + exp(9.9999999984371854e-8))) : (28.571428571428569 * (1.0 - exp(-2.4166666666666665 - 0.16666666666666666 * cell__V)) / ((1.0 + exp(-2.4166666666666665 - 0.16666666666666666 * cell__V)) * (14.5 + cell__V))))
```
## Singularity point: -14.500000000000000
![Singularity](diagrams/new/no_singularity_fixes/shannon_wang_puglisi_weber_bers_2004/1_0.png)

## Equation 2:
```
IKr_Xr_gate__tau_Xr = 1 / (0.00060999999999999997 * (10.0 + cell__V) / (-1.0 + exp(1.45 + 0.14499999999999999 * cell__V)) + 0.0013799999999999999 * (7.0 + cell__V) / (1.0 - exp(-0.86099999999999999 - 0.123 * cell__V)))
```
## New Eq:
```
IKr_Xr_gate__tau_Xr = 1 / (((fabs(10.0 + cell__V) < 6.8965517296959433e-7) ? (4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)) - 724999.99941571394 * (9.9999993103448261 + cell__V) * (-4.206896549696637e-10 / (-1.0 + exp(-9.9999999951805303e-8)) - 4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)))) : (0.00060999999999999997 * (10.0 + cell__V) / (-1.0 + exp(1.45 + 0.14499999999999999 * cell__V)))) + ((fabs(7.0 + cell__V) < 8.1300813015161566e-7) ? (-1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 614999.99994681031 * (7.0000008130081302 + cell__V) * (1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 1.1219512196092296e-9 / (1.0 - exp(-1.0000000000864873e-7)))) : (0.0013799999999999999 * (7.0 + cell__V) / (1.0 - exp(-0.86099999999999999 - 0.123 * cell__V)))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/shannon_wang_puglisi_weber_bers_2004/2_0.png)
## Singularity point: -7.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/shannon_wang_puglisi_weber_bers_2004/2_1.png)

## Equation 3:
```
IKs_Xs_gate__tau_Xs = 1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))
```
## New Eq:
```
IKs_Xs_gate__tau_Xs = ((fabs(30.0 + cell__V) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + cell__V) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/shannon_wang_puglisi_weber_bers_2004/3_0.png)

## Equation 4:
```
INa_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa_m_gate__alpha_m = ((fabs(47.130000000000003 + cell__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + cell__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/shannon_wang_puglisi_weber_bers_2004/4_0.png)

## Equation 5:
```
ICaL__i_CaL_Ca_SL = 4.0 * (-ICaL__gamma_Cao * model_parameters__Cao + Ca_buffer__Ca_SL * ICaL__gamma_Cai * exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__Fx_ICaL_SL * ICaL__PCa * ICaL__temp * ICaL_fCa_gate__fCa_SL / (-1.0 + exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T)))
```
## New Eq:
```
ICaL__i_CaL_Ca_SL = ((fabs(cell__V) < 4.9999999999999998e-8 * fabs(model_parameters__R * model_parameters__T / model_parameters__F)) ? (-10000000.0 * (-4.9999999999999998e-8 * model_parameters__R * model_parameters__T / model_parameters__F + cell__V) * (-8.9999999999999995e-9 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_SL * exp(9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8)) - 8.9999999999999995e-9 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_SL * exp(-9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) * model_parameters__F / (model_parameters__R * model_parameters__T) + 8.9999999999999995e-9 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_SL * exp(9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8))) : (0.18000000000000002 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * pow(model_parameters__F, 2) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_SL * exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * cell__V / ((-1.0 + exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/shannon_wang_puglisi_weber_bers_2004/5_0.png)

## Equation 6:
```
ICaL__i_CaL_Ca_jct = 4.0 * (-ICaL__gamma_Cao * model_parameters__Cao + Ca_buffer__Ca_jct * ICaL__gamma_Cai * exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__Fx_ICaL_jct * ICaL__PCa * ICaL__temp * ICaL_fCa_gate__fCa_jct / (-1.0 + exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T)))
```
## New Eq:
```
ICaL__i_CaL_Ca_jct = ((fabs(cell__V) < 4.9999999999999998e-8 * fabs(model_parameters__R * model_parameters__T / model_parameters__F)) ? (-10000000.0 * (-4.9999999999999998e-8 * model_parameters__R * model_parameters__T / model_parameters__F + cell__V) * (-8.0999999999999997e-8 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_jct * exp(9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8)) - 8.0999999999999997e-8 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_jct * exp(-9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) * model_parameters__F / (model_parameters__R * model_parameters__T) + 8.0999999999999997e-8 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_jct * exp(9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8))) : (1.6200000000000001 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * pow(model_parameters__F, 2) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_jct * exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * cell__V / ((-1.0 + exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/shannon_wang_puglisi_weber_bers_2004/6_0.png)

## Equation 7:
```
ICaL__i_CaL_K = (ICaL__Fx_ICaL_SL * ICaL_fCa_gate__fCa_SL + ICaL__Fx_ICaL_jct * ICaL_fCa_gate__fCa_jct) * (-ICaL__gamma_Ko * model_parameters__Ko + ICaL__gamma_Ki * model_parameters__Ki * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__PK * ICaL__temp / (-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T)))
```
## New Eq:
```
ICaL__i_CaL_K = ((fabs(cell__V) < 9.9999999999999995e-8 * fabs(model_parameters__R * model_parameters__T / model_parameters__F)) ? (-5000000.0 * (-9.9999999999999995e-8 * model_parameters__R * model_parameters__T / model_parameters__F + cell__V) * (-1.2150000000000001e-14 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (-0.75 * model_parameters__Ko + 0.75 * model_parameters__Ki * exp(9.9999999999999995e-8)) * (1.0 - 0.10000000000000001 * ICaL_fCa_gate__fCaB_SL - 0.90000000000000002 * ICaL_fCa_gate__fCaB_jct) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.2150000000000001e-14 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (-0.75 * model_parameters__Ko + 0.75 * model_parameters__Ki * exp(-9.9999999999999995e-8)) * (1.0 - 0.10000000000000001 * ICaL_fCa_gate__fCaB_SL - 0.90000000000000002 * ICaL_fCa_gate__fCaB_jct) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) * model_parameters__F / (model_parameters__R * model_parameters__T) + 1.2150000000000001e-14 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (-0.75 * model_parameters__Ko + 0.75 * model_parameters__Ki * exp(9.9999999999999995e-8)) * (1.0 - 0.10000000000000001 * ICaL_fCa_gate__fCaB_SL - 0.90000000000000002 * ICaL_fCa_gate__fCaB_jct) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8))) : (1.215e-7 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * pow(model_parameters__F, 2) * (-0.75 * model_parameters__Ko + 0.75 * model_parameters__Ki * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * (1.0 - 0.10000000000000001 * ICaL_fCa_gate__fCaB_SL - 0.90000000000000002 * ICaL_fCa_gate__fCaB_jct) * ICaL_d_gate__d * ICaL_f_gate__f * cell__V / ((-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/shannon_wang_puglisi_weber_bers_2004/7_0.png)

## Equation 8:
```
ICaL__i_CaL_Na_SL = (-ICaL__gamma_Nao * model_parameters__Nao + ICaL__gamma_Nai * Na_buffer__Na_SL * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__Fx_ICaL_SL * ICaL__PNa * ICaL__temp * ICaL_fCa_gate__fCa_SL / (-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T)))
```
## New Eq:
```
ICaL__i_CaL_Na_SL = ((fabs(cell__V) < 9.9999999999999995e-8 * fabs(model_parameters__R * model_parameters__T / model_parameters__F)) ? (-5000000.0 * (-9.9999999999999995e-8 * model_parameters__R * model_parameters__T / model_parameters__F + cell__V) * (-6.75e-17 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_SL * exp(9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8)) - 6.75e-17 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_SL * exp(-9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) * model_parameters__F / (model_parameters__R * model_parameters__T) + 6.75e-17 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_SL * exp(9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8))) : (6.7499999999999994e-10 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * pow(model_parameters__F, 2) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_SL * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL_d_gate__d * ICaL_f_gate__f * cell__V / ((-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/shannon_wang_puglisi_weber_bers_2004/8_0.png)

## Equation 9:
```
ICaL__i_CaL_Na_jct = (-ICaL__gamma_Nao * model_parameters__Nao + ICaL__gamma_Nai * Na_buffer__Na_jct * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__Fx_ICaL_jct * ICaL__PNa * ICaL__temp * ICaL_fCa_gate__fCa_jct / (-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T)))
```
## New Eq:
```
ICaL__i_CaL_Na_jct = ((fabs(cell__V) < 9.9999999999999995e-8 * fabs(model_parameters__R * model_parameters__T / model_parameters__F)) ? (-5000000.0 * (-9.9999999999999995e-8 * model_parameters__R * model_parameters__T / model_parameters__F + cell__V) * (-6.0749999999999991e-16 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_jct * exp(9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8)) - 6.0749999999999991e-16 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_jct * exp(-9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) * model_parameters__F / (model_parameters__R * model_parameters__T) + 6.0749999999999991e-16 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_jct * exp(9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8))) : (6.0749999999999998e-9 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * pow(model_parameters__F, 2) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_jct * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL_d_gate__d * ICaL_f_gate__f * cell__V / ((-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/shannon_wang_puglisi_weber_bers_2004/9_0.png)

Number of singularities:  10
# Model: stewart_zhang_model_2008(stewart_zhang_model_2008_ss.cellml)
Number of piecewises: 4
## Equation 1:
```
L_type_Ca_current__i_CaL = 4.0 * pow(membrane__F, 2) * (-15.0 + membrane__V) * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_f2_gate__f2 * L_type_Ca_current_fCass_gate__fCass * L_type_Ca_current_f_gate__f / ((-1.0 + exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_CaL = ((fabs(-15.0 + membrane__V) < 1.3356880330661625e-6) ? (-374338.90820464725 * (-15.000001335688033 + membrane__V) * (-0.01929706830117572 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(1.0000000000609274e-7)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_f2_gate__f2 * L_type_Ca_current_fCass_gate__fCass * L_type_Ca_current_f_gate__f / (-1.0 + exp(1.0000000000609274e-7)) - 0.01929706830117572 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(-1.0000000000609274e-7)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_f2_gate__f2 * L_type_Ca_current_fCass_gate__fCass * L_type_Ca_current_f_gate__f / (-1.0 + exp(-1.0000000000609274e-7))) + 0.01929706830117572 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(1.0000000000609274e-7)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_f2_gate__f2 * L_type_Ca_current_fCass_gate__fCass * L_type_Ca_current_f_gate__f / (-1.0 + exp(1.0000000000609274e-7))) : (14447.286958825251 * (-15.0 + membrane__V) * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(-1.1230167246823641 + 0.074867781645490947 * membrane__V)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_f2_gate__f2 * L_type_Ca_current_fCass_gate__fCass * L_type_Ca_current_f_gate__f / (-1.0 + exp(-1.1230167246823641 + 0.074867781645490947 * membrane__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/stewart_zhang_model_2008_ss/1_0.png)

Number of singularities:  1
# Model: tentusscher_model_2004_endo(ten_tusscher_model_2004_endo.cellml)
Number of piecewises: 7
## Equation 1:
```
L_type_Ca_current__i_CaL = 4.0 * pow(membrane__F, 2) * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_CaL = ((fabs(membrane__V) < 1.3356880329847825e-6) ? (-374338.9082274547 * (-1.3356880329847825e-6 + membrane__V) * (-0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(9.9999999999999995e-8)) - 0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(-9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(-9.9999999999999995e-8))) + 0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(9.9999999999999995e-8))) : (14447.286958825251 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(0.074867781645490947 * membrane__V)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f * membrane__V / (-1.0 + exp(0.074867781645490947 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ten_tusscher_model_2004_endo/1_0.png)

Number of singularities:  1
# Model: tentusscher_model_2004_epi(ten_tusscher_model_2004_epi.cellml)
Number of piecewises: 7
## Equation 1:
```
L_type_Ca_current__i_CaL = 4.0 * pow(membrane__F, 2) * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_CaL = ((fabs(membrane__V) < 1.3356880329847825e-6) ? (-374338.9082274547 * (-1.3356880329847825e-6 + membrane__V) * (-0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(9.9999999999999995e-8)) - 0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(-9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(-9.9999999999999995e-8))) + 0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(9.9999999999999995e-8))) : (14447.286958825251 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(0.074867781645490947 * membrane__V)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f * membrane__V / (-1.0 + exp(0.074867781645490947 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ten_tusscher_model_2004_epi/1_0.png)

Number of singularities:  1
# Model: tentusscher_model_2004_M(ten_tusscher_model_2004_M.cellml)
Number of piecewises: 7
## Equation 1:
```
L_type_Ca_current__i_CaL = 4.0 * pow(membrane__F, 2) * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_CaL = ((fabs(membrane__V) < 1.3356880329847825e-6) ? (-374338.9082274547 * (-1.3356880329847825e-6 + membrane__V) * (-0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(9.9999999999999995e-8)) - 0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(-9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(-9.9999999999999995e-8))) + 0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(9.9999999999999995e-8))) : (14447.286958825251 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(0.074867781645490947 * membrane__V)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f * membrane__V / (-1.0 + exp(0.074867781645490947 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ten_tusscher_model_2004_M/1_0.png)

Number of singularities:  1
# Model: tentusscher_model_2006_endo(ten_tusscher_model_2006_endo.cellml)
Number of piecewises: 4
## Equation 1:
```
L_type_Ca_current__temp = (-15.0 + membrane__V) * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T))) / (-1.0 + exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T)))
```
## New Eq:
```
L_type_Ca_current__temp = ((fabs(-15.0 + membrane__V) < 1.3356880330661625e-6) ? (1.3356880330661625e-6 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(1.0000000000609274e-7)) / (-1.0 + exp(1.0000000000609274e-7)) - 374338.90820464725 * (-15.000001335688033 + membrane__V) * (-1.3356880330661625e-6 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(1.0000000000609274e-7)) / (-1.0 + exp(1.0000000000609274e-7)) - 1.3356880330661625e-6 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(-1.0000000000609274e-7)) / (-1.0 + exp(-1.0000000000609274e-7)))) : ((-15.0 + membrane__V) * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(-1.1230167246823641 + 0.074867781645490947 * membrane__V)) / (-1.0 + exp(-1.1230167246823641 + 0.074867781645490947 * membrane__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/ten_tusscher_model_2006_endo/1_0.png)

Number of singularities:  1
# Model: tentusscher_model_2006_epi(ten_tusscher_model_2006_epi.cellml)
Number of piecewises: 4
## Equation 1:
```
L_type_Ca_current__temp = (-15.0 + membrane__V) * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T))) / (-1.0 + exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T)))
```
## New Eq:
```
L_type_Ca_current__temp = ((fabs(-15.0 + membrane__V) < 4.9999999999999998e-8 * fabs(membrane__R * membrane__T / membrane__F)) ? (4.9999999999999998e-8 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(9.9999999999999995e-8)) * membrane__R * membrane__T / ((-1.0 + exp(9.9999999999999995e-8)) * membrane__F) - 10000000.0 * (-4.9999999999999998e-8 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(9.9999999999999995e-8)) * membrane__R * membrane__T / ((-1.0 + exp(9.9999999999999995e-8)) * membrane__F) - 4.9999999999999998e-8 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(-9.9999999999999995e-8)) * membrane__R * membrane__T / ((-1.0 + exp(-9.9999999999999995e-8)) * membrane__F)) * (-15.0 - 4.9999999999999998e-8 * membrane__R * membrane__T / membrane__F + membrane__V) * membrane__F / (membrane__R * membrane__T)) : ((-15.0 + membrane__V) * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T))) / (-1.0 + exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T)))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/ten_tusscher_model_2006_epi/1_0.png)

Number of singularities:  1
# Model: tentusscher_model_2006_M(ten_tusscher_model_2006_M.cellml)
Number of piecewises: 4
## Equation 1:
```
L_type_Ca_current__temp = (-15.0 + membrane__V) * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T))) / (-1.0 + exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T)))
```
## New Eq:
```
L_type_Ca_current__temp = ((fabs(-15.0 + membrane__V) < 1.3356880330661625e-6) ? (1.3356880330661625e-6 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(1.0000000000609274e-7)) / (-1.0 + exp(1.0000000000609274e-7)) - 374338.90820464725 * (-15.000001335688033 + membrane__V) * (-1.3356880330661625e-6 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(1.0000000000609274e-7)) / (-1.0 + exp(1.0000000000609274e-7)) - 1.3356880330661625e-6 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(-1.0000000000609274e-7)) / (-1.0 + exp(-1.0000000000609274e-7)))) : ((-15.0 + membrane__V) * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(-1.1230167246823641 + 0.074867781645490947 * membrane__V)) / (-1.0 + exp(-1.1230167246823641 + 0.074867781645490947 * membrane__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/ten_tusscher_model_2006_M/1_0.png)

Number of singularities:  1
# Model: Tomek_model13endo(ToRORd_fkatp_endo.cellml)
Number of piecewises: 21
## Equation 1:
```
ICaL__PhiCaK_i = (-ICaL__gamma_ko * extracellular__ko + ICaL__gamma_ki * intracellular_ions__ki * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK_i = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_endo/1_0.png)

## Equation 2:
```
ICaL__PhiCaK_ss = (-ICaL__gamma_ko * extracellular__ko + ICaL__gamma_kss * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK_ss = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_endo/2_0.png)

## Equation 3:
```
ICaL__PhiCaL_i = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cai * intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL_i = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_endo/3_0.png)

## Equation 4:
```
ICaL__PhiCaL_ss = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cass * intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL_ss = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_endo/4_0.png)

## Equation 5:
```
ICaL__PhiCaNa_i = (-ICaL__gamma_nao * extracellular__nao + ICaL__gamma_nai * intracellular_ions__nai * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa_i = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_endo/5_0.png)

## Equation 6:
```
ICaL__PhiCaNa_ss = (-ICaL__gamma_nao * extracellular__nao + ICaL__gamma_nass * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa_ss = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_endo/6_0.png)

## Equation 7:
```
ICab__ICab = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cai * intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (2.36776e-7 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_endo/7_0.png)

## Equation 8:
```
INab__INab = (-extracellular__nao + intracellular_ions__nai * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (1.9238999999999999e-9 * pow(physical_constants__F, 2) * (-extracellular__nao + intracellular_ions__nai * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_endo/8_0.png)

Number of singularities:  8
# Model: Tomek_model13epi(ToRORd_fkatp_epi.cellml)
Number of piecewises: 21
## Equation 1:
```
ICaL__PhiCaK_i = (-ICaL__gamma_ko * extracellular__ko + ICaL__gamma_ki * intracellular_ions__ki * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK_i = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_epi/1_0.png)

## Equation 2:
```
ICaL__PhiCaK_ss = (-ICaL__gamma_ko * extracellular__ko + ICaL__gamma_kss * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK_ss = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_epi/2_0.png)

## Equation 3:
```
ICaL__PhiCaL_i = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cai * intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL_i = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_epi/3_0.png)

## Equation 4:
```
ICaL__PhiCaL_ss = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cass * intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL_ss = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_epi/4_0.png)

## Equation 5:
```
ICaL__PhiCaNa_i = (-ICaL__gamma_nao * extracellular__nao + ICaL__gamma_nai * intracellular_ions__nai * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa_i = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_epi/5_0.png)

## Equation 6:
```
ICaL__PhiCaNa_ss = (-ICaL__gamma_nao * extracellular__nao + ICaL__gamma_nass * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa_ss = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_epi/6_0.png)

## Equation 7:
```
ICab__ICab = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cai * intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (2.36776e-7 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_epi/7_0.png)

## Equation 8:
```
INab__INab = (-extracellular__nao + intracellular_ions__nai * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (1.9238999999999999e-9 * pow(physical_constants__F, 2) * (-extracellular__nao + intracellular_ions__nai * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/ToRORd_fkatp_epi/8_0.png)

Number of singularities:  8
# Model: Trovato2020(Trovato2020.cellml)
Number of piecewises: 2
## Equation 1:
```
ICaL__PhiCaK = (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/Trovato2020/1_0.png)

## Equation 2:
```
ICaL__PhiCaL = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/Trovato2020/2_0.png)

## Equation 3:
```
ICaL__PhiCaNa = (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/Trovato2020/3_0.png)

## Equation 4:
```
ICab__ICab = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__casl * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (4.9999999999999992e-15 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__casl * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 10000000.0 * (-4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-4.9999999999999992e-15 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__casl * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 4.9999999999999992e-15 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__casl * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (9.9999999999999995e-8 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__casl * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/Trovato2020/4_0.png)

## Equation 5:
```
INab__INab = (-extracellular__nao + intracellular_ions__nasl * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (9.3749999999999983e-17 * (-extracellular__nao + intracellular_ions__nasl * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 5000000.0 * (-9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (-9.3749999999999983e-17 * (-extracellular__nao + intracellular_ions__nasl * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) - 9.3749999999999983e-17 * (-extracellular__nao + intracellular_ions__nasl * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (9.3749999999999992e-10 * pow(physical_constants__F, 2) * (-extracellular__nao + intracellular_ions__nasl * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/Trovato2020/5_0.png)

Number of singularities:  5
# Model: viswanathan_model_1999_epi(viswanathan_model_1999_epi.cellml)
Number of piecewises: 13
## Equation 1:
```
L_type_Ca_channel__I_CaCa = 4.0 * pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Cao * calcium_dynamics__Cao + L_type_Ca_channel__gamma_Cai * calcium_dynamics__Cai * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Ca * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaCa = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 374358.83507802623 * (-1.3356169352749131e-6 + membrane__V) * (-1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (7.8019226357407252 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(0.074871767015605231 * membrane__V)) * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/viswanathan_model_1999_epi/1_0.png)

## Equation 2:
```
L_type_Ca_channel__I_CaK = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_K * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaK = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.00069711623550831479 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037435883507802616 * membrane__V)) * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/viswanathan_model_1999_epi/2_0.png)

## Equation 3:
```
L_type_Ca_channel__I_CaNa = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Na * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaNa = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (6.5127374999999992e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 187179.41753901311 * (-2.6712338705498262e-6 + membrane__V) * (-6.5127374999999992e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) - 6.5127374999999992e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8)))) : (0.0024381008236689767 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037435883507802616 * membrane__V)) * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/viswanathan_model_1999_epi/3_0.png)

## Equation 4:
```
L_type_Ca_channel_d_gate__tau_d = 0.028571428571428571 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * L_type_Ca_channel_d_gate__d_infinity / (10.0 + membrane__V)
```
## New Eq:
```
L_type_Ca_channel_d_gate__tau_d = ((fabs(10.0 + membrane__V) < 6.2400000011564316e-7) ? (801282.05113355326 * (10.000000624 + membrane__V) * (45787.545779060179 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7)) + 45787.545779060179 * (1.0 - exp(-1.0000000001853256e-7)) / (1.0 + exp(-1.0000000001853256e-7))) - 45787.545779060179 * (1.0 - exp(1.0000000001853256e-7)) / (1.0 + exp(1.0000000001853256e-7))) : (0.028571428571428571 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * (10.0 + membrane__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/viswanathan_model_1999_epi/4_0.png)

## Equation 5:
```
fast_sodium_current_m_gate__alpha_m = 320.0 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-0.00032000000146581442 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (0.00031999999919207767 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00032000000146581442 / (1.0 - exp(1.0000000045806701e-7)))) : (320.0 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/viswanathan_model_1999_epi/5_0.png)

## Equation 6:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 0.001 / (0.00060999999999999997 * (38.899999999999999 + membrane__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * membrane__V)) + 0.0013799999999999999 * (14.199999999999999 + membrane__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * membrane__V)))
```
## New Eq:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 0.001 / (((fabs(38.899999999999999 + membrane__V) < 6.8965517030505907e-7) ? (4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)) - 725000.00221680664 * (38.899999310344825 + membrane__V) * (-4.2068965171893065e-10 / (-1.0 + exp(-9.9999999179090074e-8)) - 4.2068965605324136e-10 / (-1.0 + exp(1.0000000020937704e-7)))) : (0.00060999999999999997 * (38.899999999999999 + membrane__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * membrane__V)))) + ((fabs(14.199999999999999 + membrane__V) < 8.1300813015161566e-7) ? (-1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 614999.99994681031 * (14.200000813008129 + membrane__V) * (1.1219512196092296e-9 / (1.0 - exp(1.0000000000864873e-7)) + 1.1219512196092296e-9 / (1.0 - exp(-1.0000000000864873e-7)))) : (0.0013799999999999999 * (14.199999999999999 + membrane__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * membrane__V)))))
```
## Singularity point: -38.899999999999999
![Singularity](diagrams/new/no_singularity_fixes/viswanathan_model_1999_epi/6_0.png)
## Singularity point: -14.199999999999999
![Singularity](diagrams/new/no_singularity_fixes/viswanathan_model_1999_epi/6_1.png)

## Equation 7:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = 0.001 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = 0.001 * ((fabs(30.0 + membrane__V) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + membrane__V) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/viswanathan_model_1999_epi/7_0.png)

## Equation 8:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 0.0040000000000000001 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 0.0040000000000000001 * ((fabs(30.0 + membrane__V) < 1.4556040746072085e-6) ? (1 / (-1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) - 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 343500.00025585521 * (30.000001455604075 + membrane__V) * (1.9068413377354434e-10 / (-1.0 + exp(9.9999999925515227e-8)) + 1.9068413377354434e-10 / (-1.0 + exp(-9.9999999925515227e-8)) + 1.0465793296425829e-10 / (1.0 - exp(2.1542940304186685e-7)) + 1.0465793296425829e-10 / (1.0 - exp(-2.1542940304186685e-7))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/viswanathan_model_1999_epi/8_0.png)

Number of singularities:  9
# Model: wang_model_2008(wang_sobie_2008.cellml)
Number of piecewises: 4
## Equation 1:
```
calcium_activated_chloride_current__i_ClCa = pow(membrane__F, 2) * (-membrane__Cli + membrane__Clo * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * calcium_activated_chloride_current__P_ClCa * calcium_activated_chloride_current__f_ClCa * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
calcium_activated_chloride_current__i_ClCa = ((fabs(membrane__V) < 2.5674321243523316e-6) ? (-194747.11532096745 * (-2.5674321243523316e-6 + membrane__V) * (-4.13140625e-14 * pow(calcium_concentration__Cass, 3) * (-membrane__Cli + membrane__Clo * exp(9.9999999999999995e-8)) / (pow((1 + 0.25 * calcium_concentration__Cass), 3) * (-1.0 + exp(9.9999999999999995e-8))) - 4.13140625e-14 * pow(calcium_concentration__Cass, 3) * (-membrane__Cli + membrane__Clo * exp(-9.9999999999999995e-8)) / (pow((1 + 0.25 * calcium_concentration__Cass), 3) * (-1.0 + exp(-9.9999999999999995e-8)))) + 4.13140625e-14 * pow(calcium_concentration__Cass, 3) * (-membrane__Cli + membrane__Clo * exp(9.9999999999999995e-8)) / (pow((1 + 0.25 * calcium_concentration__Cass), 3) * (-1.0 + exp(9.9999999999999995e-8)))) : (1.6091588988130313e-8 * pow(calcium_concentration__Cass, 3) * (-membrane__Cli + membrane__Clo * exp(0.038949423064193495 * membrane__V)) * membrane__V / (pow((1 + 0.25 * calcium_concentration__Cass), 3) * (-1.0 + exp(0.038949423064193495 * membrane__V)))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/wang_sobie_2008/1_0.png)

## Equation 2:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (3.2000000146581445e-7 / (1.0 - exp(1.0000000045806701e-7)) + 3.1999999919207769e-7 / (1.0 - exp(-9.9999999747524276e-8)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/wang_sobie_2008/2_0.png)

## Equation 3:
```
slow_delayed_rectifier_potassium_current__alpha_n = 4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current__alpha_n = ((fabs(26.5 + membrane__V) < 7.812499998038902e-7) ? (-3.7604140701062501e-12 / (1.0 - exp(1.0000000020227162e-7)) + 640000.00016065314 * (26.500000781250002 + membrane__V) * (3.760414053005867e-12 / (1.0 - exp(-9.9999999747524276e-8)) + 3.7604140701062501e-12 / (1.0 - exp(1.0000000020227162e-7)))) : (4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))))
```
## Singularity point: -26.500000000000000
![Singularity](diagrams/new/no_singularity_fixes/wang_sobie_2008/3_0.png)

Number of singularities:  3
# Model: winslow_model_1999(winslow_model_1999.cellml)
Number of piecewises: 5
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 320.0 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000010279564e-6) ? (-0.00032000000146581442 / (1.0 - exp(1.0000000045806701e-7)) + 499999.99948602181 * (47.130001000000007 + membrane__V) * (0.00031999999919207767 / (1.0 - exp(-9.9999999747524276e-8)) + 0.00032000000146581442 / (1.0 - exp(1.0000000045806701e-7)))) : (320.0 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/new/no_singularity_fixes/winslow_model_1999/1_0.png)

## Equation 2:
```
slow_activating_delayed_rectifiyer_K_current_X_ks_gate__tau_X_ks = 0.001 / (0.00013100000000000001 * (-10.0 + membrane__V) / (-1.0 + exp(-0.68699999999999994 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (-10.0 + membrane__V) / (1.0 - exp(1.48 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_activating_delayed_rectifiyer_K_current_X_ks_gate__tau_X_ks = 0.001 * ((fabs(-10.0 + membrane__V) < 1.4556040763835654e-6) ? (1 / (-1.0465793309197835e-10 / (1.0 - exp(2.1542940330476766e-7)) - 1.9068413400624708e-10 / (-1.0 + exp(-1.0000000004755094e-7)) + 343499.99983666249 * (-9.9999985443959236 + membrane__V) * (1.0465793309197835e-10 / (1.0 - exp(2.1542940330476766e-7)) + 1.0465793309197835e-10 / (1.0 - exp(-2.1542940330476766e-7)) + 1.9068413400624708e-10 / (-1.0 + exp(1.0000000004755094e-7)) + 1.9068413400624708e-10 / (-1.0 + exp(-1.0000000004755094e-7))))) : (1 / (0.00013100000000000001 * (-10.0 + membrane__V) / (-1.0 + exp(-0.68699999999999994 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (-10.0 + membrane__V) / (1.0 - exp(1.48 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: 10.000000000000000
![Singularity](diagrams/new/no_singularity_fixes/winslow_model_1999/2_0.png)

## Equation 3:
```
L_type_Ca_current__i_Ca_max = 4000.0 * pow(membrane__F, 2) * (0.001 * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T)) - 0.34100000000000003 * standard_ionic_concentrations__Cao) * L_type_Ca_current__P_Ca * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_Ca_max = ((fabs(membrane__V) < 1.3356880329847825e-6) ? (-374338.9082274547 * (-1.3356880329847825e-6 + membrane__V) * (-0.019297068300000001 * (0.001 * exp(1.0000000000000001e-7) - 0.34100000000000003 * standard_ionic_concentrations__Cao) * L_type_Ca_current__P_Ca / (-1.0 + exp(1.0000000000000001e-7)) - 0.019297068300000001 * (0.001 * exp(-1.0000000000000001e-7) - 0.34100000000000003 * standard_ionic_concentrations__Cao) * L_type_Ca_current__P_Ca / (-1.0 + exp(-1.0000000000000001e-7))) + 0.019297068300000001 * (0.001 * exp(1.0000000000000001e-7) - 0.34100000000000003 * standard_ionic_concentrations__Cao) * L_type_Ca_current__P_Ca / (-1.0 + exp(1.0000000000000001e-7))) : (14447.286958825252 * (0.001 * exp(0.074867781645490947 * membrane__V) - 0.34100000000000003 * standard_ionic_concentrations__Cao) * L_type_Ca_current__P_Ca * membrane__V / (-1.0 + exp(0.074867781645490947 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/winslow_model_1999/3_0.png)

## Equation 4:
```
L_type_Ca_current__i_Ca_K = pow(membrane__F, 2) * (-standard_ionic_concentrations__Ko + intracellular_ion_concentrations__Ki * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * (L_type_Ca_current__O + L_type_Ca_current__O_Ca) * L_type_Ca_current__p_prime_k * L_type_Ca_current_y_gate__y * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_Ca_K = ((fabs(membrane__V) < 2.671376065969565e-6) ? (-187169.45411372735 * (-2.671376065969565e-6 + membrane__V) * (-5.5865012728500001e-12 * (-standard_ionic_concentrations__Ko + intracellular_ion_concentrations__Ki * exp(1.0000000000000001e-7)) * (L_type_Ca_current__O + L_type_Ca_current__O_Ca) * L_type_Ca_current_y_gate__y / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(1.0000000000000001e-7))) - 5.5865012728500001e-12 * (-standard_ionic_concentrations__Ko + intracellular_ion_concentrations__Ki * exp(-1.0000000000000001e-7)) * (L_type_Ca_current__O + L_type_Ca_current__O_Ca) * L_type_Ca_current_y_gate__y / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(-1.0000000000000001e-7)))) + 5.5865012728500001e-12 * (-standard_ionic_concentrations__Ko + intracellular_ion_concentrations__Ki * exp(1.0000000000000001e-7)) * (L_type_Ca_current__O + L_type_Ca_current__O_Ca) * L_type_Ca_current_y_gate__y / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(1.0000000000000001e-7)))) : (2.0912447872899554e-6 * (-standard_ionic_concentrations__Ko + intracellular_ion_concentrations__Ki * exp(0.037433890822745473 * membrane__V)) * (L_type_Ca_current__O + L_type_Ca_current__O_Ca) * L_type_Ca_current_y_gate__y * membrane__V / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(0.037433890822745473 * membrane__V)))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/winslow_model_1999/4_0.png)
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/winslow_model_1999/4_1.png)

Number of singularities:  4
# Model: zhang_SAN_model_2000_0D_capable(zhang_SAN_model_2000_0D_capable.cellml)
Number of piecewises: 0
## Equation 1:
```
L_type_Ca_channel_d_gate__alpha_d_L = -28.390000000000001 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)) - 84.900000000000006 * membrane__V / (-1.0 + exp(-0.20799999999999999 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__alpha_d_L = -28.390000000000001 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)) + ((fabs(membrane__V) < 4.8076923076923074e-7) ? (4.0817307692307694e-5 / (-1.0 + exp(9.9999999999999995e-8)) + 1040000.0 * (4.8076923076923074e-7 + membrane__V) * (-4.0817307692307694e-5 / (-1.0 + exp(9.9999999999999995e-8)) - 4.0817307692307694e-5 / (-1.0 + exp(-9.9999999999999995e-8)))) : (-84.900000000000006 * membrane__V / (-1.0 + exp(-0.20799999999999999 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/new/no_singularity_fixes/zhang_SAN_model_2000_0D_capable/1_0.png)

## Equation 2:
```
L_type_Ca_channel_d_gate__beta_d_L = 11.43 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__beta_d_L = ((fabs(-5.0 + membrane__V) < 2.4999999981289989e-7) ? (2.8575000029373855e-6 / (-1.0 + exp(1.0000000010279565e-7)) - 2000000.0014968009 * (-5.0000002500000003 + membrane__V) * (-2.8574999927855059e-6 / (-1.0 + exp(-9.9999999747524276e-8)) - 2.8575000029373855e-6 / (-1.0 + exp(1.0000000010279565e-7)))) : (11.43 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))))
```
## Singularity point: 5.0000000000000000
![Singularity](diagrams/new/no_singularity_fixes/zhang_SAN_model_2000_0D_capable/2_0.png)

Number of singularities:  2