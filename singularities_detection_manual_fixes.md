# Model: aslanidi_atrial_model_2009(aslanidi_atrial_model_2009.cellml)
No of piecewises: 6
## Equation 1:
```
L_type_Ca_channel_d_L_gate__alpha_d_L = -50.0 * L_type_Ca_channel_d_L_gate__E10 / (-1.0 + exp(-0.20798668885191349 * L_type_Ca_channel_d_L_gate__E10)) - 16.719999999999999 * L_type_Ca_channel_d_L_gate__E0_alpha_d_L / (-1.0 + exp(-0.40000000000000002 * L_type_Ca_channel_d_L_gate__E0_alpha_d_L))
```
## New Eq:
```
L_type_Ca_channel_d_L_gate__alpha_d_L = ((fabs(10.0 + membrane__V) < 4.8080000000089163e-7) ? (-2.4039999999697637e-5 / (-1.0 + exp(-9.9999999998742257e-8)) - 1039933.4442576389 * (9.9999995191999993 + membrane__V) * (2.4040000000391526e-5 / (-1.0 + exp(1.0000000000162864e-7)) + 2.4039999999697637e-5 / (-1.0 + exp(-9.9999999998742257e-8)))) : (-50.0 * (10.0 + membrane__V) / (-1.0 + exp(-2.0798668885191347 - 0.20798668885191349 * membrane__V)))) + ((fabs(45.0 + membrane__V) < 2.5000000000718892e-7) ? (-4.1800000005842713e-6 / (-1.0 + exp(-1.000000000139778e-7)) - 1999999.9999424887 * (44.999999750000001 + membrane__V) * (4.1800000005842713e-6 / (-1.0 + exp(-1.000000000139778e-7)) + 4.1799999996561256e-6 / (-1.0 + exp(9.9999999991773334e-8)))) : (-16.719999999999999 * (45.0 + membrane__V) / (-1.0 + exp(-18.0 - 0.40000000000000002 * membrane__V))))
```
## Singularity point: -45.000000000000000
![Singularity](diagrams/manual_fixes/aslanidi_atrial_model_2009/1_0.png)
## Singularity point: -10.000000000000000
![Singularity](diagrams/manual_fixes/aslanidi_atrial_model_2009/1_1.png)

## Equation 2:
```
L_type_Ca_channel_d_L_gate__beta_d_L = 4.4800000000000004 * L_type_Ca_channel_d_L_gate__E0_beta_d_L / (-1.0 + exp(0.40000000000000002 * L_type_Ca_channel_d_L_gate__E0_beta_d_L))
```
## New Eq:
```
L_type_Ca_channel_d_L_gate__beta_d_L = ((fabs(5.0 + membrane__V) < 2.5000000000025002e-7) ? (-1.1200000000011203e-6 / (-1.0 + exp(-1.0000000000010001e-7)) + 1999999.9999979998 * (5.0000002500000003 + membrane__V) * (1.1200000000011203e-6 / (-1.0 + exp(1.0000000000010001e-7)) + 1.1200000000011203e-6 / (-1.0 + exp(-1.0000000000010001e-7)))) : (4.4800000000000004 * (5.0 + membrane__V) / (-1.0 + exp(2.0 + 0.40000000000000002 * membrane__V))))
```
## Singularity point: -5.0000000000000000
![Singularity](diagrams/manual_fixes/aslanidi_atrial_model_2009/2_0.png)

## Equation 3:
```
L_type_Ca_channel_f_L_gate__alpha_f_L = 8.4900000000000002 * L_type_Ca_channel_f_L_gate__E0_f_L / (-1.0 + exp(0.25 * L_type_Ca_channel_f_L_gate__E0_f_L))
```
## New Eq:
```
L_type_Ca_channel_f_L_gate__alpha_f_L = ((fabs(18.0 + membrane__V) < 4.0000000001150227e-7) ? (-3.3960000000976542e-6 / (-1.0 + exp(-1.0000000000287557e-7)) + 1249999.9999640554 * (18.000000400000001 + membrane__V) * (3.3960000000976542e-6 / (-1.0 + exp(1.0000000000287557e-7)) + 3.3960000000976542e-6 / (-1.0 + exp(-1.0000000000287557e-7)))) : (8.4900000000000002 * (18.0 + membrane__V) / (-1.0 + exp(4.5 + 0.25 * membrane__V))))
```
## Singularity point: -18.000000000000000
![Singularity](diagrams/manual_fixes/aslanidi_atrial_model_2009/3_0.png)

## Equation 4:
```
sodium_current_m_gate__alpha_m = -460.0 * sodium_current_m_gate__E0_m / (-1.0 + exp(-0.078907914463820727 * sodium_current_m_gate__E0_m))
```
## New Eq:
```
sodium_current_m_gate__alpha_m = ((fabs(44.399999999999999 + membrane__V) < 1.2672999999963075e-6) ? (-0.00058295799999830145 / (-1.0 + exp(-9.9999999999708629e-8)) - 394539.57232025318 * (44.399998732699999 + membrane__V) * (0.00058295799999830145 / (-1.0 + exp(9.9999999999708629e-8)) + 0.00058295799999830145 / (-1.0 + exp(-9.9999999999708629e-8)))) : (-460.0 * (44.399999999999999 + membrane__V) / (-1.0 + exp(-3.5035114021936398 - 0.078907914463820727 * membrane__V))))
```
## Singularity point: -44.399999999999999
![Singularity](diagrams/manual_fixes/aslanidi_atrial_model_2009/4_0.png)

## Equation 5:
```
sodium_current__i_Na = pow(membrane__F, 2) * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp((-sodium_current__E_Na + membrane__V) * membrane__F / (membrane__R * membrane__T))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
sodium_current__i_Na = ((fabs(membrane__V) < 2.6539450910485349e-6) ? (188398.77346612973 * (2.6539450910485349e-6 + membrane__V) * (0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(9.9999999999999995e-8)) + 0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-9.9999999999999995e-8))) - 0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-9.9999999999999995e-8))) : (3635.606491085292 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(0.037679754693225945 * membrane__V - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / (-1.0 + exp(0.037679754693225945 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/aslanidi_atrial_model_2009/5_0.png)

# of singularities:  6
# Model: aslanidi_2009(aslanidi_Purkinje_model_2009.cellml)
No of piecewises: 4
## Equation 1:
```
i_Ks_xs1_gate__tau_xs1 = 1 / (7.6100000000000007e-5 * (44.600000000000001 + membrane__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * membrane__V)) + 0.00036000000000000002 * (-0.55000000000000004 + membrane__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * membrane__V)))
```
## New Eq:
```
i_Ks_xs1_gate__tau_xs1 = 1 / (((fabs(44.600000000000001 + membrane__V) < 1.0030090258350555e-8) ? (7.6328986866047728e-13 / (1.0 - exp(-9.9999999875755032e-8)) - 49850000.061936118 * (44.599999989969909 + membrane__V) * (-7.6328986866047728e-13 / (1.0 - exp(9.9999999875755032e-8)) - 7.6328986866047728e-13 / (1.0 - exp(-9.9999999875755032e-8)))) : (7.6100000000000007e-5 * (44.600000000000001 + membrane__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * membrane__V)))) + ((fabs(-0.55000000000000004 + membrane__V) < 7.8124999999948028e-7) ? (-2.8124999999965681e-10 / (-1.0 + exp(-9.999999999987797e-8)) + 640000.00000042573 * (-0.54999921875000002 + membrane__V) * (2.8124999999996902e-10 / (-1.0 + exp(9.9999999999988984e-8)) + 2.8124999999965681e-10 / (-1.0 + exp(-9.999999999987797e-8)))) : (0.00036000000000000002 * (-0.55000000000000004 + membrane__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * membrane__V)))))
```
## Singularity point: 0.55000000000000004
![Singularity](diagrams/manual_fixes/aslanidi_Purkinje_model_2009/1_0.png)
## Singularity point: -44.600000000000001
![Singularity](diagrams/manual_fixes/aslanidi_Purkinje_model_2009/1_1.png)

## Equation 2:
```
i_Ks_xs2_gate__tau_xs2 = 2.0 / (7.6100000000000007e-5 * (44.600000000000001 + membrane__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * membrane__V)) + 0.00036000000000000002 * (-0.55000000000000004 + membrane__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * membrane__V)))
```
## New Eq:
```
i_Ks_xs2_gate__tau_xs2 = 2.0 / (((fabs(44.600000000000001 + membrane__V) < 1.0030090258350555e-8) ? (7.6328986866047728e-13 / (1.0 - exp(-9.9999999875755032e-8)) - 49850000.061936118 * (44.599999989969909 + membrane__V) * (-7.6328986866047728e-13 / (1.0 - exp(9.9999999875755032e-8)) - 7.6328986866047728e-13 / (1.0 - exp(-9.9999999875755032e-8)))) : (7.6100000000000007e-5 * (44.600000000000001 + membrane__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * membrane__V)))) + ((fabs(-0.55000000000000004 + membrane__V) < 7.8124999999948028e-7) ? (-2.8124999999965681e-10 / (-1.0 + exp(-9.999999999987797e-8)) + 640000.00000042573 * (-0.54999921875000002 + membrane__V) * (2.8124999999996902e-10 / (-1.0 + exp(9.9999999999988984e-8)) + 2.8124999999965681e-10 / (-1.0 + exp(-9.999999999987797e-8)))) : (0.00036000000000000002 * (-0.55000000000000004 + membrane__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * membrane__V)))))
```
## Singularity point: 0.55000000000000004
![Singularity](diagrams/manual_fixes/aslanidi_Purkinje_model_2009/2_0.png)
## Singularity point: -44.600000000000001
![Singularity](diagrams/manual_fixes/aslanidi_Purkinje_model_2009/2_1.png)

## Equation 3:
```
i_Na_L_m_L_gate__alpha_m_L = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
i_Na_L_m_L_gate__alpha_m_L = ((fabs(47.130000000000003 + membrane__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + membrane__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/aslanidi_Purkinje_model_2009/3_0.png)

## Equation 4:
```
i_Na_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
i_Na_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + membrane__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/aslanidi_Purkinje_model_2009/4_0.png)

## Equation 5:
```
i_to_2__i_to_2_max = pow(i_to_2__z_Cl, 2) * pow(model_parameters__F, 2) * (-model_parameters__Cl_o * exp(-i_to_2__z_Cl * membrane__V * model_parameters__F / (model_parameters__R * model_parameters__T)) + intracellular_ion_concentrations__Cl_i) * i_to_2__p_Cl * membrane__V / ((1.0 - exp(-i_to_2__z_Cl * membrane__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__Cm * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_to_2__i_to_2_max = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (3.8593999999999993e-9 * (-100.0 * exp(9.9999999999999995e-8) + intracellular_ion_concentrations__Cl_i) / (1.0 - exp(9.9999999999999995e-8)) + 3.8593999999999993e-9 * (-100.0 * exp(-9.9999999999999995e-8) + intracellular_ion_concentrations__Cl_i) / (1.0 - exp(-9.9999999999999995e-8))) - 3.8593999999999993e-9 * (-100.0 * exp(-9.9999999999999995e-8) + intracellular_ion_concentrations__Cl_i) / (1.0 - exp(-9.9999999999999995e-8))) : (0.0014448004881001341 * (-100.0 * exp(0.037435883507802616 * membrane__V) + intracellular_ion_concentrations__Cl_i) * membrane__V / (1.0 - exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/aslanidi_Purkinje_model_2009/5_0.png)

## Equation 6:
```
background_currents__i_Ca_b = pow(model_parameters__F, 2) * pow(model_parameters__z_Ca, 2) * (-model_parameters__Ca_o * model_parameters__gamma_Cao + Ca_i__Ca_i * model_parameters__gamma_Cai * exp(membrane__V * model_parameters__F * model_parameters__z_Ca / (model_parameters__R * model_parameters__T))) * background_currents__p_Ca_b * membrane__V / ((-1.0 + exp(membrane__V * model_parameters__F * model_parameters__z_Ca / (model_parameters__R * model_parameters__T))) * model_parameters__Cm * model_parameters__R * model_parameters__T)
```
## New Eq:
```
background_currents__i_Ca_b = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + membrane__V) * (3.8499135947999997e-9 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_i__Ca_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 3.8499135947999997e-9 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_i__Ca_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 3.8499135947999997e-9 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_i__Ca_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.0028824983370007683 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_i__Ca_i * exp(0.074871767015605231 * membrane__V)) * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/aslanidi_Purkinje_model_2009/6_0.png)

## Equation 7:
```
i_Ca_L__i_Ca_L_max = pow(model_parameters__F, 2) * pow(model_parameters__z_Ca, 2) * (-15.0 + membrane__V) * (-model_parameters__Ca_o * model_parameters__gamma_Cao + Ca_r__Ca_r * model_parameters__gamma_Cai * exp((-15.0 + membrane__V) * model_parameters__F * model_parameters__z_Ca / (model_parameters__R * model_parameters__T))) * i_Ca_L__p_Ca / ((-1.0 + exp((-15.0 + membrane__V) * model_parameters__F * model_parameters__z_Ca / (model_parameters__R * model_parameters__T))) * model_parameters__Cm * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_Ca_L__i_Ca_L_max = ((fabs(-15.0 + membrane__V) < 1.3356169352718439e-6) ? (374358.83507888648 * (-14.999998664383064 + membrane__V) * (4.6891709999892238e-6 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_r__Ca_r * exp(9.9999999999770198e-8)) / (-1.0 + exp(9.9999999999770198e-8)) + 4.6891709999892238e-6 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_r__Ca_r * exp(-9.9999999999770198e-8)) / (-1.0 + exp(-9.9999999999770198e-8))) - 4.6891709999892238e-6 * (-0.34100000000000003 * model_parameters__Ca_o + Ca_r__Ca_r * exp(-9.9999999999770198e-8)) / (-1.0 + exp(-9.9999999999770198e-8))) : (3.510865186083326 * (-15.0 + membrane__V) * (-0.34100000000000003 * model_parameters__Ca_o + Ca_r__Ca_r * exp(-1.1230765052340785 + 0.074871767015605231 * membrane__V)) / (-1.0 + exp(-1.1230765052340785 + 0.074871767015605231 * membrane__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/manual_fixes/aslanidi_Purkinje_model_2009/7_0.png)

# of singularities:  9
# Model: beeler_reuter_model_1977(beeler_reuter_model_1977.cellml)
No of piecewises: 2
# of singularities:  0
# Model: benson_epicardial_2008(benson_epicardial_2008.cellml)
No of piecewises: 7
## Equation 1:
```
ICaL__ibarca = 4.0 * (-15.0 + cell__V) * (-Environment__Ca_o * ICaL__gacao + Ca__Ca_ss * ICaL__gacai * exp(2.0 * (-15.0 + cell__V) * Environment__FonRT)) * Environment__F * Environment__FonRT * ICaL__pca / (-1.0 + exp(2.0 * (-15.0 + cell__V) * Environment__FonRT))
```
## New Eq:
```
ICaL__ibarca = ((fabs(-15.0 + cell__V) < 1.3356169352718439e-6) ? (374358.83507888648 * (-14.999998664383064 + cell__V) * (0.019296999999954306 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(9.9999999999763197e-8)) * ICaL__pca / (-1.0 + exp(9.9999999999763197e-8)) + 0.019296999999954306 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-9.9999999999763197e-8)) * ICaL__pca / (-1.0 + exp(-9.9999999999763197e-8))) - 0.019296999999954306 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-9.9999999999763197e-8)) * ICaL__pca / (-1.0 + exp(-9.9999999999763197e-8))) : (14448.004881000332 * (-15.0 + cell__V) * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-1.1230765052339999 + 0.074871767015599999 * cell__V)) * ICaL__pca / (-1.0 + exp(-1.1230765052339999 + 0.074871767015599999 * cell__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/manual_fixes/benson_epicardial_2008/1_0.png)

## Equation 2:
```
ICab__ICab = 7.9803360000000004e-7 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(2.0 * Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * cell__V / (-1.0 + exp(2.0 * Environment__FonRT * cell__V))
```
## New Eq:
```
ICab__ICab = ((fabs(cell__V) < 1.3356169352750065e-6) ? (374358.83507800003 * (1.3356169352750065e-6 + cell__V) * (3.8499135947999997e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 3.8499135947999997e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 3.8499135947999997e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.0028824983370005666 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(0.074871767015599999 * cell__V)) * cell__V / (-1.0 + exp(0.074871767015599999 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/benson_epicardial_2008/2_0.png)

## Equation 3:
```
IKr__tauxr = 1 / (0.00029999999999999997 * (38.360799999999998 + cell__V) / (-1.0 + exp(5.8385137599999997 + 0.1522 * cell__V)) + 0.00059999999999999995 * (-1.7383999999999999 + cell__V) / (1.0 - exp(0.2364224 - 0.13600000000000001 * cell__V)))
```
## New Eq:
```
IKr__tauxr = 1 / (((fabs(-1.7383999999999999 + cell__V) < 7.352941176468758e-7) ? (4.4117647058812543e-10 / (1.0 - exp(-9.9999999999975114e-8)) - 680000.00000016927 * (-1.7384007352941175 + cell__V) * (-4.4117647058812543e-10 / (1.0 - exp(9.9999999999975114e-8)) - 4.4117647058812543e-10 / (1.0 - exp(-9.9999999999975114e-8)))) : (0.00059999999999999995 * (-1.7383999999999999 + cell__V) / (1.0 - exp(0.2364224 - 0.13600000000000001 * cell__V)))) + ((fabs(38.360799999999998 + cell__V) < 6.5703022339436146e-7) ? (-1.9710906701830842e-10 / (-1.0 + exp(-1.0000000000062181e-7)) + 760999.99999526795 * (38.360800657030218 + cell__V) * (1.9710906701830842e-10 / (-1.0 + exp(1.0000000000062181e-7)) + 1.9710906701830842e-10 / (-1.0 + exp(-1.0000000000062181e-7)))) : (0.00029999999999999997 * (38.360799999999998 + cell__V) / (-1.0 + exp(5.8385137599999997 + 0.1522 * cell__V)))))
```
## Singularity point: 1.7383999999999999
![Singularity](diagrams/manual_fixes/benson_epicardial_2008/3_0.png)
## Singularity point: -38.360799999999998
![Singularity](diagrams/manual_fixes/benson_epicardial_2008/3_1.png)

## Equation 4:
```
IKs__tauxs = 1 / (7.6100000000000007e-5 * (44.600000000000001 + cell__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * cell__V)) + 0.00036000000000000002 * (-0.55000000000000004 + cell__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * cell__V)))
```
## New Eq:
```
IKs__tauxs = 1 / (((fabs(44.600000000000001 + cell__V) < 1.0030090258350555e-8) ? (7.6328986866047728e-13 / (1.0 - exp(-9.9999999875755032e-8)) - 49850000.061936118 * (44.599999989969909 + cell__V) * (-7.6328986866047728e-13 / (1.0 - exp(9.9999999875755032e-8)) - 7.6328986866047728e-13 / (1.0 - exp(-9.9999999875755032e-8)))) : (7.6100000000000007e-5 * (44.600000000000001 + cell__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * cell__V)))) + ((fabs(-0.55000000000000004 + cell__V) < 7.8124999999948028e-7) ? (-2.8124999999965681e-10 / (-1.0 + exp(-9.999999999987797e-8)) + 640000.00000042573 * (-0.54999921875000002 + cell__V) * (2.8124999999996902e-10 / (-1.0 + exp(9.9999999999988984e-8)) + 2.8124999999965681e-10 / (-1.0 + exp(-9.999999999987797e-8)))) : (0.00036000000000000002 * (-0.55000000000000004 + cell__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * cell__V)))))
```
## Singularity point: -44.600000000000001
![Singularity](diagrams/manual_fixes/benson_epicardial_2008/4_0.png)
## Singularity point: 0.55000000000000004
![Singularity](diagrams/manual_fixes/benson_epicardial_2008/4_1.png)

## Equation 5:
```
INa__am = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa__am = ((fabs(47.130000000000003 + cell__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + cell__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/benson_epicardial_2008/5_0.png)

## Equation 6:
```
INal__amL = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INal__amL = ((fabs(47.130000000000003 + cell__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + cell__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/benson_epicardial_2008/6_0.png)

## Equation 7:
```
Ito2__Ito2_max = (-Environment__Cl_o * exp(Environment__FonRT * cell__V) + Cl__Cl_i) * Environment__F * Environment__FonRT * Ito2__PCl * cell__V / (1.0 - exp(Environment__FonRT * cell__V))
```
## New Eq:
```
Ito2__Ito2_max = ((fabs(cell__V) < 2.671233870550013e-6) ? (187179.41753900002 * (2.671233870550013e-6 + cell__V) * (3.8593999999999993e-9 * (-100.0 * exp(9.9999999999999995e-8) + Cl__Cl_i) / (1.0 - exp(9.9999999999999995e-8)) + 3.8593999999999993e-9 * (-100.0 * exp(-9.9999999999999995e-8) + Cl__Cl_i) / (1.0 - exp(-9.9999999999999995e-8))) - 3.8593999999999993e-9 * (-100.0 * exp(-9.9999999999999995e-8) + Cl__Cl_i) / (1.0 - exp(-9.9999999999999995e-8))) : (0.001444800488100033 * (-100.0 * exp(0.0374358835078 * cell__V) + Cl__Cl_i) * cell__V / (1.0 - exp(0.0374358835078 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/benson_epicardial_2008/7_0.png)

# of singularities:  9
# Model: bernus_wilders_zemlin_verschelde_panfilov_2002_version01(bernus_wilders_zemlin_verschelde_panfilov_2002.cellml)
No of piecewises: 0
## Equation 1:
```
sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + membrane__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/bernus_wilders_zemlin_verschelde_panfilov_2002/1_0.png)

# of singularities:  1
# Model: bondarenko_2004_apical(bondarenko_szigeti_bett_kim_rasmusson_2004_apical.cellml)
No of piecewises: 0
## Equation 1:
```
slow_delayed_rectifier_potassium_current__alpha_n = 4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current__alpha_n = ((fabs(26.5 + membrane__V) < 7.8124999999817923e-7) ? (3.7604140624912359e-12 / (1.0 - exp(-9.9999999999766942e-8)) - 640000.00000149151 * (26.499999218749998 + membrane__V) * (-3.7604140624912359e-12 / (1.0 - exp(9.9999999999766942e-8)) - 3.7604140624912359e-12 / (1.0 - exp(-9.9999999999766942e-8)))) : (4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))))
```
## Singularity point: -26.500000000000000
![Singularity](diagrams/manual_fixes/bondarenko_szigeti_bett_kim_rasmusson_2004_apical/1_0.png)

# of singularities:  1
# Model: bondarenko_2004_septum(bondarenko_szigeti_bett_kim_rasmusson_2004_septal.cellml)
No of piecewises: 0
## Equation 1:
```
slow_delayed_rectifier_potassium_current__alpha_n = 4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current__alpha_n = ((fabs(26.5 + membrane__V) < 7.8124999999817923e-7) ? (3.7604140624912359e-12 / (1.0 - exp(-9.9999999999766942e-8)) - 640000.00000149151 * (26.499999218749998 + membrane__V) * (-3.7604140624912359e-12 / (1.0 - exp(9.9999999999766942e-8)) - 3.7604140624912359e-12 / (1.0 - exp(-9.9999999999766942e-8)))) : (4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))))
```
## Singularity point: -26.500000000000000
![Singularity](diagrams/manual_fixes/bondarenko_szigeti_bett_kim_rasmusson_2004_septal/1_0.png)

# of singularities:  1
# Model: bueno_2007(bueno_2007_endo.cellml)
No of piecewises: 5
# of singularities:  0
# Model: bueno_2007(bueno_2007_epi.cellml)
No of piecewises: 5
# of singularities:  0
# Model: Carro_Rodriguez_Laguna_Pueyo_CinC2010_EPI(carro_2011_endo.cellml)
No of piecewises: 4
## Equation 1:
```
L_Type_Calcium_Current__Ibar_Ca_j = (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(2.0 * membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Ca * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(2.0 * membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Ca_j = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + membrane__V) * (9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (0.71831868267118426 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(0.074871767015605231 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/carro_2011_endo/1_0.png)

## Equation 2:
```
L_Type_Calcium_Current__Ibar_Ca_sl = (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(2.0 * membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Ca * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(2.0 * membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Ca_sl = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + membrane__V) * (9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (0.71831868267118426 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(0.074871767015605231 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/carro_2011_endo/2_0.png)

## Equation 3:
```
L_Type_Calcium_Current__Ibar_K = (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_K * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_K = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (0.00019748616671718709 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/carro_2011_endo/3_0.png)

## Equation 4:
```
L_Type_Calcium_Current__Ibar_Na_j = (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Na * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Na_j = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (1.0971453706510394e-5 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/carro_2011_endo/4_0.png)

## Equation 5:
```
L_Type_Calcium_Current__Ibar_Na_sl = (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Na * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Na_sl = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (1.0971453706510394e-5 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/carro_2011_endo/5_0.png)

# of singularities:  5
# Model: Carro_Rodriguez_Laguna_Pueyo_CinC2010_EPI(carro_2011_epi.cellml)
No of piecewises: 4
## Equation 1:
```
L_Type_Calcium_Current__Ibar_Ca_j = (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(2.0 * membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Ca * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(2.0 * membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Ca_j = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + membrane__V) * (9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (0.71831868267118426 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_j * exp(0.074871767015605231 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/carro_2011_epi/1_0.png)

## Equation 2:
```
L_Type_Calcium_Current__Ibar_Ca_sl = (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(2.0 * membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Ca * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(2.0 * membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Ca_sl = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + membrane__V) * (9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 9.5939859749999992e-7 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (0.71831868267118426 * (-Calcium_Concentrations__Ca_o + Calcium_Concentrations__Ca_sl * exp(0.074871767015605231 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/carro_2011_epi/2_0.png)

## Equation 3:
```
L_Type_Calcium_Current__Ibar_K = (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_K * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_K = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 5.2753173749999997e-10 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (0.00019748616671718709 * (-Potassium_Concentrations__K_o + Potassium_Concentrations__K_i * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/carro_2011_epi/3_0.png)

## Equation 4:
```
L_Type_Calcium_Current__Ibar_Na_j = (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Na * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Na_j = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (1.0971453706510394e-5 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_j * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/carro_2011_epi/4_0.png)

## Equation 5:
```
L_Type_Calcium_Current__Ibar_Na_sl = (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(membrane__FoRT * membrane__V)) * L_Type_Calcium_Current__P_scale * L_Type_Calcium_Current__p_Na * membrane__FoRT * membrane__Frdy * membrane__V / (-1.0 + exp(membrane__FoRT * membrane__V))
```
## New Eq:
```
L_Type_Calcium_Current__Ibar_Na_sl = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 2.9307318749999998e-11 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) * L_Type_Calcium_Current__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (1.0971453706510394e-5 * (-Sodium_Concentrations__Na_o + Sodium_Concentrations__Na_sl * exp(0.037435883507802616 * membrane__V)) * L_Type_Calcium_Current__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/carro_2011_epi/5_0.png)

# of singularities:  5
# Model: clancy_rudy_2002(clancy_rudy_2002.cellml)
No of piecewises: 10
## Equation 1:
```
L_type_Ca_channel__I_CaCa = 4.0 * pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Cao * calcium_dynamics__Cao + L_type_Ca_channel__gamma_Cai * calcium_dynamics__Cai * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Ca * L_type_Ca_channel__P_scale * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaCa = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + membrane__V) * (1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (7.8019226357407252 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(0.074871767015605231 * membrane__V)) * L_type_Ca_channel__P_scale * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/clancy_rudy_2002/1_0.png)

## Equation 2:
```
L_type_Ca_channel__I_CaK = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_K * L_type_Ca_channel__P_scale * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaK = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (0.00069711623550831479 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037435883507802616 * membrane__V)) * L_type_Ca_channel__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/clancy_rudy_2002/2_0.png)

## Equation 3:
```
L_type_Ca_channel__I_CaNa = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Na * L_type_Ca_channel__P_scale * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaNa = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (6.5127375e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(9.9999999999999995e-8)) + 6.5127375e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) - 6.5127375e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_scale / (-1.0 + exp(-9.9999999999999995e-8))) : (0.0024381008236689767 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037435883507802616 * membrane__V)) * L_type_Ca_channel__P_scale * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/clancy_rudy_2002/3_0.png)

## Equation 4:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = 0.001 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = 0.001 * ((fabs(30.0 + membrane__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + membrane__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/clancy_rudy_2002/4_0.png)

## Equation 5:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 0.0040000000000000001 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 0.0040000000000000001 * ((fabs(30.0 + membrane__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + membrane__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/clancy_rudy_2002/5_0.png)

# of singularities:  5
# Model: Corrias_rabbit_purkinje_model(corrias_purkinje_2011.cellml)
No of piecewises: 3
# of singularities:  0
# Model: courtemanche_1998(courtemanche_ramirez_nattel_1998.cellml)
No of piecewises: 11
# of singularities:  0
# Model: davies_isap_2012(davies_isap_2012.cellml)
No of piecewises: 12
# of singularities:  0
# Model: decker_2009(decker_2009.cellml)
No of piecewises: 12
# of singularities:  0
# Model: demir_model_1994(demir_model_1994.cellml)
No of piecewises: 0
## Equation 1:
```
L_type_Ca_channel_d_gate__alpha_d_L = -28.390000000000001 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)) - 84.900000000000006 * membrane__V / (-1.0 + exp(-0.20799999999999999 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__alpha_d_L = ((fabs(membrane__V) < 4.8076923076923074e-7) ? (-4.0817307692307694e-5 / (-1.0 + exp(-9.9999999999999995e-8)) - 1040000.0 * (-4.8076923076923074e-7 + membrane__V) * (4.0817307692307694e-5 / (-1.0 + exp(9.9999999999999995e-8)) + 4.0817307692307694e-5 / (-1.0 + exp(-9.9999999999999995e-8)))) : (-84.900000000000006 * membrane__V / (-1.0 + exp(-0.20799999999999999 * membrane__V)))) + ((fabs(35.0 + membrane__V) < 2.5000000000718892e-7) ? (-7.097500000992074e-6 / (-1.0 + exp(-1.000000000139778e-7)) - 1999999.9999424887 * (34.999999750000001 + membrane__V) * (7.0974999994161125e-6 / (-1.0 + exp(9.9999999991773334e-8)) + 7.097500000992074e-6 / (-1.0 + exp(-1.000000000139778e-7)))) : (-28.390000000000001 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V))))
```
## Singularity point: -35.000000000000000
![Singularity](diagrams/manual_fixes/demir_model_1994/1_0.png)
## Singularity point: 0
![Singularity](diagrams/manual_fixes/demir_model_1994/1_1.png)

## Equation 2:
```
L_type_Ca_channel_d_gate__beta_d_L = 11.43 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__beta_d_L = ((fabs(-5.0 + membrane__V) < 2.5000000000025002e-7) ? (-2.8575000000028576e-6 / (-1.0 + exp(-1.0000000000010001e-7)) + 1999999.9999979998 * (-4.9999997499999997 + membrane__V) * (2.8575000000028576e-6 / (-1.0 + exp(1.0000000000010001e-7)) + 2.8575000000028576e-6 / (-1.0 + exp(-1.0000000000010001e-7)))) : (11.43 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))))
```
## Singularity point: 5.0000000000000000
![Singularity](diagrams/manual_fixes/demir_model_1994/2_0.png)

## Equation 3:
```
L_type_Ca_channel_f_gate__alpha_f_L = 3.75 * (28.0 + membrane__V) / (-1.0 + exp(7.0 + 0.25 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_f_gate__alpha_f_L = ((fabs(28.0 + membrane__V) < 4.0000000001150227e-7) ? (-1.5000000000431335e-6 / (-1.0 + exp(-1.0000000000287557e-7)) + 1249999.9999640554 * (28.000000400000001 + membrane__V) * (1.5000000000431335e-6 / (-1.0 + exp(1.0000000000287557e-7)) + 1.5000000000431335e-6 / (-1.0 + exp(-1.0000000000287557e-7)))) : (3.75 * (28.0 + membrane__V) / (-1.0 + exp(7.0 + 0.25 * membrane__V))))
```
## Singularity point: -28.000000000000000
![Singularity](diagrams/manual_fixes/demir_model_1994/3_0.png)

## Equation 4:
```
sodium_current_m_gate__alpha_m = -824.0 * (51.899999999999999 + membrane__V) / (-1.0 + exp(-5.8314606741573032 - 0.11235955056179775 * membrane__V))
```
## New Eq:
```
sodium_current_m_gate__alpha_m = ((fabs(51.899999999999999 + membrane__V) < 8.9000000000338808e-7) ? (-0.00073336000002566237 / (-1.0 + exp(-1.0000000000349929e-7)) - 561797.75280685013 * (51.899999109999996 + membrane__V) * (0.00073336000002566237 / (-1.0 + exp(-1.0000000000349929e-7)) + 0.00073335999997992118 / (-1.0 + exp(9.9999999997262081e-8)))) : (-824.0 * (51.899999999999999 + membrane__V) / (-1.0 + exp(-5.8314606741573032 - 0.11235955056179775 * membrane__V))))
```
## Singularity point: -51.899999999999999
![Singularity](diagrams/manual_fixes/demir_model_1994/4_0.png)

## Equation 5:
```
sodium_current__i_Na = pow(membrane__F, 2) * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp((-reversal_potentials__E_Na + membrane__V) * membrane__F / (membrane__R * membrane__T))) * cleft_space_equations__Na_c * membrane__V * sodium_current__P_Na * sodium_current_h_gate__h1 * sodium_current_h_gate__h2 / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
sodium_current__i_Na = ((fabs(membrane__V) < 2.671376065969565e-6) ? (187169.45411372738 * (2.671376065969565e-6 + membrane__V) * (0.0096485341499999988 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(9.9999999999999995e-8 - 1.0 * log(cleft_space_equations__Na_c / intracellular_concentrations_and_buffer_equations__Na_i))) * cleft_space_equations__Na_c * sodium_current__P_Na * sodium_current_h_gate__h1 * sodium_current_h_gate__h2 / (-1.0 + exp(9.9999999999999995e-8)) + 0.0096485341499999988 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - 1.0 * log(cleft_space_equations__Na_c / intracellular_concentrations_and_buffer_equations__Na_i))) * cleft_space_equations__Na_c * sodium_current__P_Na * sodium_current_h_gate__h1 * sodium_current_h_gate__h2 / (-1.0 + exp(-9.9999999999999995e-8))) - 0.0096485341499999988 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - 1.0 * log(cleft_space_equations__Na_c / intracellular_concentrations_and_buffer_equations__Na_i))) * cleft_space_equations__Na_c * sodium_current__P_Na * sodium_current_h_gate__h1 * sodium_current_h_gate__h2 / (-1.0 + exp(-9.9999999999999995e-8))) : (3611.8217397063127 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(0.037433890822745473 * membrane__V - 1.0 * log(cleft_space_equations__Na_c / intracellular_concentrations_and_buffer_equations__Na_i))) * cleft_space_equations__Na_c * membrane__V * sodium_current__P_Na * sodium_current_h_gate__h1 * sodium_current_h_gate__h2 / (-1.0 + exp(0.037433890822745473 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/demir_model_1994/5_0.png)

# of singularities:  6
# Model: difrancesco_noble_model_1985(difrancesco_noble_model_1985.cellml)
No of piecewises: 5
## Equation 1:
```
intracellular_calcium_concentration__alpha_p = 0.625 * (34.0 + membrane__V) / (-1.0 + exp(8.5 + 0.25 * membrane__V))
```
## New Eq:
```
intracellular_calcium_concentration__alpha_p = ((fabs(34.0 + membrane__V) < 4.0000000001150227e-7) ? (-2.5000000000718892e-7 / (-1.0 + exp(-1.0000000000287557e-7)) + 1249999.9999640554 * (34.000000399999998 + membrane__V) * (2.5000000000718892e-7 / (-1.0 + exp(1.0000000000287557e-7)) + 2.5000000000718892e-7 / (-1.0 + exp(-1.0000000000287557e-7)))) : (0.625 * (34.0 + membrane__V) / (-1.0 + exp(8.5 + 0.25 * membrane__V))))
```
## Singularity point: -34.000000000000000
![Singularity](diagrams/manual_fixes/difrancesco_noble_model_1985/1_0.png)

## Equation 2:
```
second_inward_current__i_siCa = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(100.0 / membrane__RTONF) - extracellular_calcium_concentration__Cao * exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siCa = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-1.9999999999556149e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(9.9999999997780743e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(9.9999999997780743e-8)) - 1.9999999999556149e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(-9.9999999997780743e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) + 1.9999999999556149e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(-9.9999999997780743e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/difrancesco_noble_model_1985/2_0.png)

## Equation 3:
```
second_inward_current__i_siK = 0.01 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(50.0 / membrane__RTONF) - extracellular_potassium_concentration__Kc * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siK = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/difrancesco_noble_model_1985/3_0.png)

## Equation 4:
```
second_inward_current__i_siNa = 0.01 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(50.0 / membrane__RTONF) - extracellular_sodium_concentration__Nao * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siNa = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/difrancesco_noble_model_1985/4_0.png)

## Equation 5:
```
transient_outward_current__i_to = (10.0 + membrane__V) * (0.20000000000000001 + extracellular_potassium_concentration__Kc / (extracellular_potassium_concentration__Kc + transient_outward_current__Km_to)) * (intracellular_potassium_concentration__Ki * exp(0.5 * membrane__V / membrane__RTONF) - extracellular_potassium_concentration__Kc * exp(-0.5 * membrane__V / membrane__RTONF)) * intracellular_calcium_concentration__Cai * transient_outward_current__g_to * transient_outward_current_s_gate__s / ((1.0 - exp(-2.0 - 0.20000000000000001 * membrane__V)) * (intracellular_calcium_concentration__Cai + transient_outward_current__Km_Ca))
```
## New Eq:
```
transient_outward_current__i_to = ((fabs(10.0 + membrane__V) < 5.0000000000050004e-7) ? (-999999.99999899988 * (9.9999994999999995 + membrane__V) * (-5.0000000000050004e-7 * (0.20000000000000001 + extracellular_potassium_concentration__Kc / (10.0 + extracellular_potassium_concentration__Kc)) * (intracellular_potassium_concentration__Ki * exp(-0.18716946347220006) - extracellular_potassium_concentration__Kc * exp(0.18716946347220006)) * intracellular_calcium_concentration__Cai * transient_outward_current__g_to * transient_outward_current_s_gate__s / ((1.0 - exp(1.0000000000010001e-7)) * (0.00050000000000000001 + intracellular_calcium_concentration__Cai)) - 5.0000000000050004e-7 * (0.20000000000000001 + extracellular_potassium_concentration__Kc / (10.0 + extracellular_potassium_concentration__Kc)) * (intracellular_potassium_concentration__Ki * exp(-0.18716944475525465) - extracellular_potassium_concentration__Kc * exp(0.18716944475525465)) * intracellular_calcium_concentration__Cai * transient_outward_current__g_to * transient_outward_current_s_gate__s / ((1.0 - exp(-1.0000000000010001e-7)) * (0.00050000000000000001 + intracellular_calcium_concentration__Cai))) + 5.0000000000050004e-7 * (0.20000000000000001 + extracellular_potassium_concentration__Kc / (10.0 + extracellular_potassium_concentration__Kc)) * (intracellular_potassium_concentration__Ki * exp(-0.18716944475525465) - extracellular_potassium_concentration__Kc * exp(0.18716944475525465)) * intracellular_calcium_concentration__Cai * transient_outward_current__g_to * transient_outward_current_s_gate__s / ((1.0 - exp(-1.0000000000010001e-7)) * (0.00050000000000000001 + intracellular_calcium_concentration__Cai))) : ((10.0 + membrane__V) * (0.20000000000000001 + extracellular_potassium_concentration__Kc / (10.0 + extracellular_potassium_concentration__Kc)) * (intracellular_potassium_concentration__Ki * exp(0.018716945411372737 * membrane__V) - extracellular_potassium_concentration__Kc * exp(-0.018716945411372737 * membrane__V)) * intracellular_calcium_concentration__Cai * transient_outward_current__g_to * transient_outward_current_s_gate__s / ((1.0 - exp(-2.0 - 0.20000000000000001 * membrane__V)) * (0.00050000000000000001 + intracellular_calcium_concentration__Cai))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/manual_fixes/difrancesco_noble_model_1985/5_0.png)

# of singularities:  5
# Model: dokos_model_1996(dokos_model_1996.cellml)
No of piecewises: 0
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 200.0 * (34.299999999999997 + membrane__E) / (1.0 - exp(-3.0869999999999997 - 0.089999999999999997 * membrane__E))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(34.299999999999997 + membrane__E) < 1.1111111111183902e-6) ? (0.00022222222222367805 / (1.0 - exp(-1.0000000000065512e-7)) - 449999.99999705196 * (34.299998888888886 + membrane__E) * (-0.00022222222222367805 / (1.0 - exp(1.0000000000065512e-7)) - 0.00022222222222367805 / (1.0 - exp(-1.0000000000065512e-7)))) : (200.0 * (34.299999999999997 + membrane__E) / (1.0 - exp(-3.0869999999999997 - 0.089999999999999997 * membrane__E))))
```
## Singularity point: -34.299999999999997
![Singularity](diagrams/manual_fixes/dokos_model_1996/1_0.png)

## Equation 2:
```
hyperpolarising_activated_current_y_gate__alpha_y = 0.35999999999999999 * (137.80000000000001 + membrane__E) / (-1.0 + exp(9.0948000000000011 + 0.066000000000000003 * membrane__E))
```
## New Eq:
```
hyperpolarising_activated_current_y_gate__alpha_y = ((fabs(137.80000000000001 + membrane__E) < 1.5151515151412553e-6) ? (-5.4545454545085189e-7 / (-1.0 + exp(-9.9999999999322859e-8)) + 330000.00000223459 * (137.80000151515154 + membrane__E) * (5.4545454545085189e-7 / (-1.0 + exp(9.9999999999322859e-8)) + 5.4545454545085189e-7 / (-1.0 + exp(-9.9999999999322859e-8)))) : (0.35999999999999999 * (137.80000000000001 + membrane__E) / (-1.0 + exp(9.0948000000000011 + 0.066000000000000003 * membrane__E))))
```
## Singularity point: -137.80000000000001
![Singularity](diagrams/manual_fixes/dokos_model_1996/2_0.png)

## Equation 3:
```
hyperpolarising_activated_current_y_gate__beta_y = 0.10000000000000001 * (76.299999999999997 + membrane__E) / (1.0 - exp(-16.023 - 0.20999999999999999 * membrane__E))
```
## New Eq:
```
hyperpolarising_activated_current_y_gate__beta_y = ((fabs(76.299999999999997 + membrane__E) < 4.761904762173863e-7) ? (4.7619047627289747e-8 / (1.0 - exp(-1.0000000001730847e-7)) - 1049999.9999406631 * (76.299999523809518 + membrane__E) * (-4.7619047627289747e-8 / (1.0 - exp(-1.0000000001730847e-7)) - 4.7619047616187521e-8 / (1.0 - exp(9.9999999993993777e-8)))) : (0.10000000000000001 * (76.299999999999997 + membrane__E) / (1.0 - exp(-16.023 - 0.20999999999999999 * membrane__E))))
```
## Singularity point: -76.299999999999997
![Singularity](diagrams/manual_fixes/dokos_model_1996/3_0.png)

# of singularities:  3
# Model: earm_noble_model_1990(earm_noble_model_1990.cellml)
No of piecewises: 4
## Equation 1:
```
L_type_calcium_current__i_Ca_L_Ca = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 / membrane__RTONF) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) / membrane__RTONF)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d * L_type_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp(2.0 * (50.0 - membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
L_type_calcium_current__i_Ca_L_Ca = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-1.9999999999556149e-7 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(9.9999999997780743e-8)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(9.9999999997780743e-8)) - 1.9999999999556149e-7 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(-9.9999999997780743e-8))) + 1.9999999999556149e-7 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(-9.9999999997780743e-8))) : (0.14973556329098189 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/earm_noble_model_1990/1_0.png)

## Equation 2:
```
L_type_calcium_current__i_Ca_L_K = 0.002 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 / membrane__RTONF) - extracellular_potassium_concentration__K_c * exp((50.0 - membrane__V) / membrane__RTONF)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d * L_type_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp((50.0 - membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
L_type_calcium_current__i_Ca_L_K = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-1.999999999997175e-10 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(9.9999999999858739e-8)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(9.9999999999858739e-8)) - 1.999999999997175e-10 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(-9.9999999999858739e-8)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) + 1.999999999997175e-10 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(-9.9999999999858739e-8)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) : (7.4867781645490941e-5 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/earm_noble_model_1990/2_0.png)

## Equation 3:
```
L_type_calcium_current__i_Ca_L_Na = 0.01 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 / membrane__RTONF) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) / membrane__RTONF)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d * L_type_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp((50.0 - membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
L_type_calcium_current__i_Ca_L_Na = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(9.9999999999858739e-8)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (1.0 - L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_calcium_current__P_Ca_L * L_type_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/earm_noble_model_1990/3_0.png)

# of singularities:  3
# Model: espinosa_model_1998(espinosa_model_1998_normal.cellml)
No of piecewises: 7
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999997780743e-8)) - 1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) + 1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/espinosa_model_1998_normal/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K_ds = (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K_ds = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-2.9999999999957622e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 2.9999999999957622e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 2.9999999999957622e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00011230167246823642 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/espinosa_model_1998_normal/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_Na_ds = (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na_ds = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/espinosa_model_1998_normal/3_0.png)

# of singularities:  3
# Model: faber_rudy_2000(faber_rudy_2000.cellml)
No of piecewises: 15
## Equation 1:
```
L_type_Ca_channel__I_CaCa = 4.0 * pow(cell__F, 2) * (-L_type_Ca_channel__gamma_Cao * calcium_dynamics__Cao + L_type_Ca_channel__gamma_Cai * calcium_dynamics__Cai * exp(2.0 * cell__F * cell__V / (cell__R * cell__T))) * L_type_Ca_channel__P_Ca * cell__V / ((-1.0 + exp(2.0 * cell__F * cell__V / (cell__R * cell__T))) * cell__R * cell__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaCa = ((fabs(cell__V) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + cell__V) * (0.019296999999999998 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * L_type_Ca_channel__P_Ca / (-1.0 + exp(9.9999999999999995e-8)) + 0.019296999999999998 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_Ca / (-1.0 + exp(-9.9999999999999995e-8))) - 0.019296999999999998 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * L_type_Ca_channel__P_Ca / (-1.0 + exp(-9.9999999999999995e-8))) : (14448.004881001343 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(0.074871767015605231 * cell__V)) * L_type_Ca_channel__P_Ca * cell__V / (-1.0 + exp(0.074871767015605231 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/faber_rudy_2000/1_0.png)

## Equation 2:
```
L_type_Ca_channel__I_CaK = pow(cell__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(cell__F * cell__V / (cell__R * cell__T))) * L_type_Ca_channel__P_K * cell__V / ((-1.0 + exp(cell__F * cell__V / (cell__R * cell__T))) * cell__R * cell__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaK = ((fabs(cell__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + cell__V) * (1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.00069711623550831479 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/faber_rudy_2000/2_0.png)

## Equation 3:
```
L_type_Ca_channel__I_CaNa = pow(cell__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(cell__F * cell__V / (cell__R * cell__T))) * L_type_Ca_channel__P_Na * cell__V / ((-1.0 + exp(cell__F * cell__V / (cell__R * cell__T))) * cell__R * cell__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaNa = ((fabs(cell__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + cell__V) * (6.5127375e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 6.5127375e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 6.5127375e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.0024381008236689767 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/faber_rudy_2000/3_0.png)

## Equation 4:
```
non_specific_calcium_activated_current__I_ns_K = pow(cell__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(cell__F * cell__V / (cell__R * cell__T))) * cell__V * non_specific_calcium_activated_current__P_ns_Ca / ((-1.0 + exp(cell__F * cell__V / (cell__R * cell__T))) * cell__R * cell__T)
```
## New Eq:
```
non_specific_calcium_activated_current__I_ns_K = ((fabs(cell__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + cell__V) * (1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.00063210021354380874 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/faber_rudy_2000/4_0.png)

## Equation 5:
```
non_specific_calcium_activated_current__I_ns_Na = pow(cell__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(cell__F * cell__V / (cell__R * cell__T))) * cell__V * non_specific_calcium_activated_current__P_ns_Ca / ((-1.0 + exp(cell__F * cell__V / (cell__R * cell__T))) * cell__R * cell__T)
```
## New Eq:
```
non_specific_calcium_activated_current__I_ns_Na = ((fabs(cell__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + cell__V) * (1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 1.6884874999999999e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.00063210021354380874 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/faber_rudy_2000/5_0.png)

## Equation 6:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 1 / (0.00060999999999999997 * (38.899999999999999 + cell__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * cell__V)) + 0.0013799999999999999 * (14.199999999999999 + cell__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * cell__V)))
```
## New Eq:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 1 / (((fabs(14.199999999999999 + cell__V) < 8.1300813007528783e-7) ? (1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)) - 615000.00000454858 * (14.199999186991869 + cell__V) * (-1.1219512194943214e-9 / (1.0 - exp(9.9999999998406912e-8)) - 1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)))) : (0.0013799999999999999 * (14.199999999999999 + cell__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * cell__V)))) + ((fabs(38.899999999999999 + cell__V) < 6.896551724422384e-7) ? (-4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 724999.99997009686 * (38.900000689655172 + cell__V) * (4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 4.2068965520669629e-10 / (-1.0 + exp(1.0000000000814911e-7)))) : (0.00060999999999999997 * (38.899999999999999 + cell__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * cell__V)))))
```
## Singularity point: -38.899999999999999
![Singularity](diagrams/manual_fixes/faber_rudy_2000/6_0.png)
## Singularity point: -14.199999999999999
![Singularity](diagrams/manual_fixes/faber_rudy_2000/6_1.png)

## Equation 7:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = 1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = ((fabs(30.0 + cell__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + cell__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/faber_rudy_2000/7_0.png)

## Equation 8:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 4.0 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 4.0 * ((fabs(30.0 + cell__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + cell__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/faber_rudy_2000/8_0.png)

# of singularities:  9
# Model: fink_noble_giles_model_2008(fink_noble_giles_model_2008.cellml)
No of piecewises: 4
## Equation 1:
```
ICaL__i_CaL = pow(Environment__F, 2) * pow(ICaL__z, 2) * (-15.0 + cell__V) * (-Environment__Ca_o + 0.25 * Ca__Ca_ss * exp(2.0 * (-15.0 + cell__V) * Environment__F / (Environment__R * Environment__T))) * ICaL__g_CaL * iCaL_d_gate__d * iCaL_f2_gate__f2 * iCaL_fCass_gate__fCass * iCaL_f_gate__f / ((-1.0 + exp(2.0 * (-15.0 + cell__V) * Environment__F / (Environment__R * Environment__T))) * Environment__R * Environment__T)
```
## New Eq:
```
ICaL__i_CaL = ((fabs(-15.0 + cell__V) < 1.3356880329828957e-6) ? (374338.90822798351 * (-14.999998664311967 + cell__V) * (0.019297068299972742 * (-Environment__Ca_o + 0.25 * Ca__Ca_ss * exp(9.9999999999858739e-8)) * ICaL__g_CaL * iCaL_d_gate__d * iCaL_f2_gate__f2 * iCaL_fCass_gate__fCass * iCaL_f_gate__f / (-1.0 + exp(9.9999999999858739e-8)) + 0.019297068299972742 * (-Environment__Ca_o + 0.25 * Ca__Ca_ss * exp(-9.9999999999858739e-8)) * ICaL__g_CaL * iCaL_d_gate__d * iCaL_f2_gate__f2 * iCaL_fCass_gate__fCass * iCaL_f_gate__f / (-1.0 + exp(-9.9999999999858739e-8))) - 0.019297068299972742 * (-Environment__Ca_o + 0.25 * Ca__Ca_ss * exp(-9.9999999999858739e-8)) * ICaL__g_CaL * iCaL_d_gate__d * iCaL_f2_gate__f2 * iCaL_fCass_gate__fCass * iCaL_f_gate__f / (-1.0 + exp(-9.9999999999858739e-8))) : (14447.286958825251 * (-15.0 + cell__V) * (-Environment__Ca_o + 0.25 * Ca__Ca_ss * exp(-1.1230167246823641 + 0.074867781645490947 * cell__V)) * ICaL__g_CaL * iCaL_d_gate__d * iCaL_f2_gate__f2 * iCaL_fCass_gate__fCass * iCaL_f_gate__f / (-1.0 + exp(-1.1230167246823641 + 0.074867781645490947 * cell__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/manual_fixes/fink_noble_giles_model_2008/1_0.png)

# of singularities:  1
# Model: fox_model_2001(fox_mcharg_gilmour_2002.cellml)
No of piecewises: 0
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * fast_sodium_current_m_gate__E0_m / (1.0 - exp(-0.10000000000000001 * fast_sodium_current_m_gate__E0_m))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + membrane__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/fox_mcharg_gilmour_2002/1_0.png)

## Equation 2:
```
slow_activating_delayed_rectifiyer_K_current_X_ks_gate__tau_X_ks = 1 / (0.00013100000000000001 * (-10.0 + membrane__V) / (-1.0 + exp(-0.68699999999999994 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (-10.0 + membrane__V) / (1.0 - exp(1.48 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_activating_delayed_rectifiyer_K_current_X_ks_gate__tau_X_ks = ((fabs(-10.0 + membrane__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (-9.9999985443959236 + membrane__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (-10.0 + membrane__V) / (-1.0 + exp(-0.68699999999999994 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (-10.0 + membrane__V) / (1.0 - exp(1.48 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: 10.000000000000000
![Singularity](diagrams/manual_fixes/fox_mcharg_gilmour_2002/2_0.png)

## Equation 3:
```
L_type_Ca_current__i_Ca_max = 4.0 * pow(membrane__F, 2) * (-0.34100000000000003 * standard_ionic_concentrations__Ca_o + calcium_dynamics__Ca_i * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__P_Ca * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__C_sc * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_Ca_max = ((fabs(membrane__V) < 1.3354093264248704e-6) ? (374417.03461708582 * (1.3354093264248704e-6 + membrane__V) * (1.9299999999999998e-5 * (-0.34100000000000003 * standard_ionic_concentrations__Ca_o + 1000.0 * calcium_dynamics__Ca_i_converted * exp(9.9999999999999995e-8)) * L_type_Ca_current__P_Ca / (-1.0 + exp(9.9999999999999995e-8)) + 1.9299999999999998e-5 * (-0.34100000000000003 * standard_ionic_concentrations__Ca_o + 1000.0 * calcium_dynamics__Ca_i_converted * exp(-9.9999999999999995e-8)) * L_type_Ca_current__P_Ca / (-1.0 + exp(-9.9999999999999995e-8))) - 1.9299999999999998e-5 * (-0.34100000000000003 * standard_ionic_concentrations__Ca_o + 1000.0 * calcium_dynamics__Ca_i_converted * exp(-9.9999999999999995e-8)) * L_type_Ca_current__P_Ca / (-1.0 + exp(-9.9999999999999995e-8))) : (14.452497536219512 * (-0.34100000000000003 * standard_ionic_concentrations__Ca_o + 1000.0 * calcium_dynamics__Ca_i_converted * exp(0.074883406923417162 * membrane__V)) * L_type_Ca_current__P_Ca * membrane__V / (-1.0 + exp(0.074883406923417162 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/fox_mcharg_gilmour_2002/3_0.png)

## Equation 4:
```
L_type_Ca_current__i_CaK = 1000.0 * pow(membrane__F, 2) * (-standard_ionic_concentrations__K_o + standard_ionic_concentrations__K_i * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__P_CaK * L_type_Ca_current_d_gate__d * L_type_Ca_current_f_Ca_gate__f_Ca * L_type_Ca_current_f_gate__f * membrane__V / ((1.0 + L_type_Ca_current__i_Ca_max / L_type_Ca_current__i_Ca_half) * (-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__C_sc * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_CaK = ((fabs(membrane__V) < 2.6708186528497407e-6) ? (187208.51730854291 * (2.6708186528497407e-6 + membrane__V) * (5.5873499999999997e-9 * (-standard_ionic_concentrations__K_o + standard_ionic_concentrations__K_i * exp(9.9999999999999995e-8)) * L_type_Ca_current_d_gate__d * L_type_Ca_current_f_Ca_gate__f_Ca * L_type_Ca_current_f_gate__f / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(9.9999999999999995e-8))) + 5.5873499999999997e-9 * (-standard_ionic_concentrations__K_o + standard_ionic_concentrations__K_i * exp(-9.9999999999999995e-8)) * L_type_Ca_current_d_gate__d * L_type_Ca_current_f_Ca_gate__f_Ca * L_type_Ca_current_f_gate__f / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(-9.9999999999999995e-8)))) - 5.5873499999999997e-9 * (-standard_ionic_concentrations__K_o + standard_ionic_concentrations__K_i * exp(-9.9999999999999995e-8)) * L_type_Ca_current_d_gate__d * L_type_Ca_current_f_Ca_gate__f_Ca * L_type_Ca_current_f_gate__f / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(-9.9999999999999995e-8)))) : (0.0020919990183677745 * (-standard_ionic_concentrations__K_o + standard_ionic_concentrations__K_i * exp(0.037441703461708581 * membrane__V)) * L_type_Ca_current_d_gate__d * L_type_Ca_current_f_Ca_gate__f_Ca * L_type_Ca_current_f_gate__f * membrane__V / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(0.037441703461708581 * membrane__V)))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/fox_mcharg_gilmour_2002/4_0.png)
## Singularity point: 0
![Singularity](diagrams/manual_fixes/fox_mcharg_gilmour_2002/4_1.png)

# of singularities:  4
# Model: grandi_pasqualini_bers_2010(grandi_pasqualini_bers_2010_ss.cellml)
No of piecewises: 6
## Equation 1:
```
I_Ca__taud = 28.571428571428569 * (1.0 - exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) * I_Ca__dss / (5.0 + membrane_potential__V_m)
```
## New Eq:
```
I_Ca__taud = ((fabs(5.0 + membrane_potential__V_m) < 6.0000000000337561e-7) ? (47619047.618779711 * (1.0 - exp(-1.000000000005626e-7)) / (1.0 + exp(-1.000000000005626e-7)) - 833333.33332864498 * (4.9999994000000001 + membrane_potential__V_m) * (-47619047.618779711 * (1.0 - exp(1.000000000005626e-7)) / (1.0 + exp(1.000000000005626e-7)) - 47619047.618779711 * (1.0 - exp(-1.000000000005626e-7)) / (1.0 + exp(-1.000000000005626e-7)))) : (28.571428571428569 * (1.0 - exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) / ((1.0 + exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) * (5.0 + membrane_potential__V_m))))
```
## Singularity point: -5.0000000000000000
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss/1_0.png)

## Equation 2:
```
I_Ca__ibarca_j = 4.0 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(2.0 * membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pCa / (-1.0 + exp(2.0 * membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarca_j = ((fabs(membrane_potential__V_m) < 4.9999999999999998e-8 * fabs(parameters__R * parameters__Temp / parameters__Frdy)) ? (-1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * parameters__R * parameters__Temp / parameters__Frdy + membrane_potential__V_m) * (1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8)) + 1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8))) * parameters__Frdy / (parameters__R * parameters__Temp)) : (0.00216 * pow(parameters__Frdy, 2) * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(2.0 * membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * membrane_potential__V_m * parameters__pCa_max / ((-1.0 + exp(2.0 * membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * parameters__R * parameters__Temp)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss/2_0.png)

## Equation 3:
```
I_Ca__ibarca_sl = 4.0 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(2.0 * membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pCa / (-1.0 + exp(2.0 * membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarca_sl = ((fabs(membrane_potential__V_m) < 4.9999999999999998e-8 * fabs(parameters__R * parameters__Temp / parameters__Frdy)) ? (-1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * parameters__R * parameters__Temp / parameters__Frdy + membrane_potential__V_m) * (1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8)) + 1.08e-10 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * parameters__Frdy * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8))) * parameters__Frdy / (parameters__R * parameters__Temp)) : (0.00216 * pow(parameters__Frdy, 2) * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(2.0 * membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * membrane_potential__V_m * parameters__pCa_max / ((-1.0 + exp(2.0 * membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * parameters__R * parameters__Temp)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss/3_0.png)

## Equation 4:
```
I_Ca__ibark = (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pK / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibark = ((fabs(membrane_potential__V_m) < 9.9999999999999995e-8 * fabs(parameters__R * parameters__Temp / parameters__Frdy)) ? (-1.3499999999999999e-14 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(-9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * parameters__R * parameters__Temp / parameters__Frdy + membrane_potential__V_m) * (1.3499999999999999e-14 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(9.9999999999999995e-8)) + 1.3499999999999999e-14 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(-9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(-9.9999999999999995e-8))) * parameters__Frdy / (parameters__R * parameters__Temp)) : (1.35e-7 * pow(parameters__Frdy, 2) * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * membrane_potential__V_m / ((-1.0 + exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * parameters__R * parameters__Temp)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss/4_0.png)

## Equation 5:
```
I_Ca__ibarna_j = (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pNa / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarna_j = ((fabs(membrane_potential__V_m) < 9.9999999999999995e-8 * fabs(parameters__R * parameters__Temp / parameters__Frdy)) ? (-7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(-9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * parameters__R * parameters__Temp / parameters__Frdy + membrane_potential__V_m) * (7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(9.9999999999999995e-8)) + 7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(-9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(-9.9999999999999995e-8))) * parameters__Frdy / (parameters__R * parameters__Temp)) : (7.4999999999999993e-9 * pow(parameters__Frdy, 2) * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * membrane_potential__V_m / ((-1.0 + exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * parameters__R * parameters__Temp)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss/5_0.png)

## Equation 6:
```
I_Ca__ibarna_sl = (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pNa / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarna_sl = ((fabs(membrane_potential__V_m) < 9.9999999999999995e-8 * fabs(parameters__R * parameters__Temp / parameters__Frdy)) ? (-7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * parameters__R * parameters__Temp / parameters__Frdy + membrane_potential__V_m) * (7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(9.9999999999999995e-8)) + 7.4999999999999986e-16 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) * parameters__Frdy / (-1.0 + exp(-9.9999999999999995e-8))) * parameters__Frdy / (parameters__R * parameters__Temp)) : (7.4999999999999993e-9 * pow(parameters__Frdy, 2) * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * membrane_potential__V_m / ((-1.0 + exp(membrane_potential__V_m * parameters__Frdy / (parameters__R * parameters__Temp))) * parameters__R * parameters__Temp)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss/6_0.png)

# of singularities:  6
# Model: grandi_pasqualini_bers_2010(grandi_pasqualini_bers_2010_ss_endo.cellml)
No of piecewises: 6
## Equation 1:
```
I_Ca__taud = 28.571428571428569 * (1.0 - exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) * I_Ca__dss / (5.0 + membrane_potential__V_m)
```
## New Eq:
```
I_Ca__taud = ((fabs(5.0 + membrane_potential__V_m) < 6.0000000000337561e-7) ? (47619047.618779711 * (1.0 - exp(-1.000000000005626e-7)) / (1.0 + exp(-1.000000000005626e-7)) - 833333.33332864498 * (4.9999994000000001 + membrane_potential__V_m) * (-47619047.618779711 * (1.0 - exp(1.000000000005626e-7)) / (1.0 + exp(1.000000000005626e-7)) - 47619047.618779711 * (1.0 - exp(-1.000000000005626e-7)) / (1.0 + exp(-1.000000000005626e-7)))) : (28.571428571428569 * (1.0 - exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) / ((1.0 + exp(-0.83333333333333337 - 0.16666666666666666 * membrane_potential__V_m)) * (5.0 + membrane_potential__V_m))))
```
## Singularity point: -5.0000000000000000
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss_endo/1_0.png)

## Equation 2:
```
I_Ca__ibarca_j = 4.0 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(2.0 * membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pCa / (-1.0 + exp(2.0 * membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarca_j = ((fabs(membrane_potential__V_m) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + membrane_potential__V_m) * (1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8)) + 1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8))) - 1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(-9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8))) : (7.8019226357407252 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_j * exp(0.074871767015605231 * membrane_potential__V_m)) * membrane_potential__V_m * parameters__pCa_max / (-1.0 + exp(0.074871767015605231 * membrane_potential__V_m))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss_endo/2_0.png)

## Equation 3:
```
I_Ca__ibarca_sl = 4.0 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(2.0 * membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pCa / (-1.0 + exp(2.0 * membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarca_sl = ((fabs(membrane_potential__V_m) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + membrane_potential__V_m) * (1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(9.9999999999999995e-8)) + 1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8))) - 1.042038e-5 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(-9.9999999999999995e-8)) * parameters__pCa_max / (-1.0 + exp(-9.9999999999999995e-8))) : (7.8019226357407252 * (-0.34100000000000003 * parameters__Cao + 0.34100000000000003 * Ca_Concentrations__Ca_sl * exp(0.074871767015605231 * membrane_potential__V_m)) * membrane_potential__V_m * parameters__pCa_max / (-1.0 + exp(0.074871767015605231 * membrane_potential__V_m))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss_endo/3_0.png)

## Equation 4:
```
I_Ca__ibark = (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pK / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibark = ((fabs(membrane_potential__V_m) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane_potential__V_m) * (1.3025475e-9 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.3025475e-9 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 1.3025475e-9 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.00048762016473379531 * (-0.75 * parameters__Ko + 0.75 * K_Concentration__K_i * exp(0.037435883507802616 * membrane_potential__V_m)) * membrane_potential__V_m / (-1.0 + exp(0.037435883507802616 * membrane_potential__V_m))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss_endo/4_0.png)

## Equation 5:
```
I_Ca__ibarna_j = (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pNa / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarna_j = ((fabs(membrane_potential__V_m) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane_potential__V_m) * (7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (2.7090009151877515e-5 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_j * exp(0.037435883507802616 * membrane_potential__V_m)) * membrane_potential__V_m / (-1.0 + exp(0.037435883507802616 * membrane_potential__V_m))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss_endo/5_0.png)

## Equation 6:
```
I_Ca__ibarna_sl = (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(membrane_potential__V_m * parameters__FoRT)) * membrane_potential__V_m * parameters__FoRT * parameters__Frdy * parameters__pNa / (-1.0 + exp(membrane_potential__V_m * parameters__FoRT))
```
## New Eq:
```
I_Ca__ibarna_sl = ((fabs(membrane_potential__V_m) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane_potential__V_m) * (7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 7.236374999999999e-11 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (2.7090009151877515e-5 * (-0.75 * parameters__Nao + 0.75 * Na_Concentrations__Na_sl * exp(0.037435883507802616 * membrane_potential__V_m)) * membrane_potential__V_m / (-1.0 + exp(0.037435883507802616 * membrane_potential__V_m))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/grandi_pasqualini_bers_2010_ss_endo/6_0.png)

# of singularities:  6
# Model: hilgemann_noble_model_1987(hilgemann_noble_model_1987.cellml)
No of piecewises: 4
## Equation 1:
```
second_inward_calcium_current__i_siCa = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 / membrane__RTONF) - extracellular_calcium_concentration__Ca_o * exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d * second_inward_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_calcium_current__i_siCa = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-1.9999999999556149e-7 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(9.9999999997780743e-8)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(9.9999999997780743e-8)) - 1.9999999999556149e-7 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(-9.9999999997780743e-8))) + 1.9999999999556149e-7 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(-9.9999999997780743e-8))) : (0.14973556329098189 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/hilgemann_noble_model_1987/1_0.png)

## Equation 2:
```
second_inward_calcium_current__i_siK = 0.002 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 / membrane__RTONF) - extracellular_potassium_concentration__K_c * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d * second_inward_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_calcium_current__i_siK = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-1.999999999997175e-10 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(9.9999999999858739e-8)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(9.9999999999858739e-8)) - 1.999999999997175e-10 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(-9.9999999999858739e-8)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) + 1.999999999997175e-10 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(-9.9999999999858739e-8)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) : (7.4867781645490941e-5 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_c * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/hilgemann_noble_model_1987/2_0.png)

## Equation 3:
```
second_inward_calcium_current__i_siNa = 0.01 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 / membrane__RTONF) - extracellular_sodium_concentration__Na_o * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d * second_inward_calcium_current_f_Ca_gate__CaChon / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_calcium_current__i_siNa = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(9.9999999999858739e-8)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (1.0 - second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.001 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_calcium_current__P_si * second_inward_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/hilgemann_noble_model_1987/3_0.png)

# of singularities:  3
# Model: hodgkin_huxley_squid_axon_model_1952_modified(hodgkin_huxley_squid_axon_model_1952_modified.cellml)
No of piecewises: 2
# of singularities:  0
# Model: HundRudy2004_units(hund_rudy_2004.cellml)
No of piecewises: 7
## Equation 1:
```
ICaL__ibarca = 4.0 * (-15.0 + cell__V) * (-Environment__Ca_o * ICaL__gacao + Ca__Ca_ss * ICaL__gacai * exp(2.0 * (-15.0 + cell__V) * Environment__FonRT)) * Environment__F * Environment__FonRT * ICaL__pca / (-1.0 + exp(2.0 * (-15.0 + cell__V) * Environment__FonRT))
```
## New Eq:
```
ICaL__ibarca = ((fabs(-15.0 + cell__V) < 1.3356169352718439e-6) ? (374358.83507888648 * (-14.999998664383064 + cell__V) * (0.019296999999954306 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(9.9999999999763197e-8)) * ICaL__pca / (-1.0 + exp(9.9999999999763197e-8)) + 0.019296999999954306 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-9.9999999999763197e-8)) * ICaL__pca / (-1.0 + exp(-9.9999999999763197e-8))) - 0.019296999999954306 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-9.9999999999763197e-8)) * ICaL__pca / (-1.0 + exp(-9.9999999999763197e-8))) : (14448.004881000332 * (-15.0 + cell__V) * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_ss * exp(-1.1230765052339999 + 0.074871767015599999 * cell__V)) * ICaL__pca / (-1.0 + exp(-1.1230765052339999 + 0.074871767015599999 * cell__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/manual_fixes/hund_rudy_2004/1_0.png)

## Equation 2:
```
ICab__ICab = 7.9803360000000004e-7 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(2.0 * Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * cell__V / (-1.0 + exp(2.0 * Environment__FonRT * cell__V))
```
## New Eq:
```
ICab__ICab = ((fabs(cell__V) < 1.3356169352750065e-6) ? (374358.83507800003 * (1.3356169352750065e-6 + cell__V) * (3.8499135947999997e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 3.8499135947999997e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 3.8499135947999997e-9 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.0028824983370005666 * (-0.34100000000000003 * Environment__Ca_o + Ca__Ca_i * exp(0.074871767015599999 * cell__V)) * cell__V / (-1.0 + exp(0.074871767015599999 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/hund_rudy_2004/2_0.png)

## Equation 3:
```
IKr__tauxr = 1 / (0.00029999999999999997 * (38.360799999999998 + cell__V) / (-1.0 + exp(5.8385137599999997 + 0.1522 * cell__V)) + 0.00059999999999999995 * (-1.7383999999999999 + cell__V) / (1.0 - exp(0.2364224 - 0.13600000000000001 * cell__V)))
```
## New Eq:
```
IKr__tauxr = 1 / (((fabs(-1.7383999999999999 + cell__V) < 7.352941176468758e-7) ? (4.4117647058812543e-10 / (1.0 - exp(-9.9999999999975114e-8)) - 680000.00000016927 * (-1.7384007352941175 + cell__V) * (-4.4117647058812543e-10 / (1.0 - exp(9.9999999999975114e-8)) - 4.4117647058812543e-10 / (1.0 - exp(-9.9999999999975114e-8)))) : (0.00059999999999999995 * (-1.7383999999999999 + cell__V) / (1.0 - exp(0.2364224 - 0.13600000000000001 * cell__V)))) + ((fabs(38.360799999999998 + cell__V) < 6.5703022339436146e-7) ? (-1.9710906701830842e-10 / (-1.0 + exp(-1.0000000000062181e-7)) + 760999.99999526795 * (38.360800657030218 + cell__V) * (1.9710906701830842e-10 / (-1.0 + exp(1.0000000000062181e-7)) + 1.9710906701830842e-10 / (-1.0 + exp(-1.0000000000062181e-7)))) : (0.00029999999999999997 * (38.360799999999998 + cell__V) / (-1.0 + exp(5.8385137599999997 + 0.1522 * cell__V)))))
```
## Singularity point: -38.360799999999998
![Singularity](diagrams/manual_fixes/hund_rudy_2004/3_0.png)
## Singularity point: 1.7383999999999999
![Singularity](diagrams/manual_fixes/hund_rudy_2004/3_1.png)

## Equation 4:
```
IKs__tauxs = 1 / (7.6100000000000007e-5 * (44.600000000000001 + cell__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * cell__V)) + 0.00036000000000000002 * (-0.55000000000000004 + cell__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * cell__V)))
```
## New Eq:
```
IKs__tauxs = 1 / (((fabs(44.600000000000001 + cell__V) < 1.0030090258350555e-8) ? (7.6328986866047728e-13 / (1.0 - exp(-9.9999999875755032e-8)) - 49850000.061936118 * (44.599999989969909 + cell__V) * (-7.6328986866047728e-13 / (1.0 - exp(9.9999999875755032e-8)) - 7.6328986866047728e-13 / (1.0 - exp(-9.9999999875755032e-8)))) : (7.6100000000000007e-5 * (44.600000000000001 + cell__V) / (1.0 - exp(-444.66200000000003 - 9.9700000000000006 * cell__V)))) + ((fabs(-0.55000000000000004 + cell__V) < 7.8124999999948028e-7) ? (-2.8124999999965681e-10 / (-1.0 + exp(-9.999999999987797e-8)) + 640000.00000042573 * (-0.54999921875000002 + cell__V) * (2.8124999999996902e-10 / (-1.0 + exp(9.9999999999988984e-8)) + 2.8124999999965681e-10 / (-1.0 + exp(-9.999999999987797e-8)))) : (0.00036000000000000002 * (-0.55000000000000004 + cell__V) / (-1.0 + exp(-0.070400000000000004 + 0.128 * cell__V)))))
```
## Singularity point: 0.55000000000000004
![Singularity](diagrams/manual_fixes/hund_rudy_2004/4_0.png)
## Singularity point: -44.600000000000001
![Singularity](diagrams/manual_fixes/hund_rudy_2004/4_1.png)

## Equation 5:
```
INa__am = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa__am = ((fabs(47.130000000000003 + cell__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + cell__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/hund_rudy_2004/5_0.png)

## Equation 6:
```
INal__amL = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INal__amL = ((fabs(47.130000000000003 + cell__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + cell__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/hund_rudy_2004/6_0.png)

## Equation 7:
```
Ito2__Ito2_max = (-Environment__Cl_o * exp(Environment__FonRT * cell__V) + Cl__Cl_i) * Environment__F * Environment__FonRT * Ito2__PCl * cell__V / (1.0 - exp(Environment__FonRT * cell__V))
```
## New Eq:
```
Ito2__Ito2_max = ((fabs(cell__V) < 2.671233870550013e-6) ? (187179.41753900002 * (2.671233870550013e-6 + cell__V) * (3.8593999999999993e-9 * (-Environment__Cl_o * exp(9.9999999999999995e-8) + Cl__Cl_i) / (1.0 - exp(9.9999999999999995e-8)) + 3.8593999999999993e-9 * (-Environment__Cl_o * exp(-9.9999999999999995e-8) + Cl__Cl_i) / (1.0 - exp(-9.9999999999999995e-8))) - 3.8593999999999993e-9 * (-Environment__Cl_o * exp(-9.9999999999999995e-8) + Cl__Cl_i) / (1.0 - exp(-9.9999999999999995e-8))) : (0.001444800488100033 * (-Environment__Cl_o * exp(0.0374358835078 * cell__V) + Cl__Cl_i) * cell__V / (1.0 - exp(0.0374358835078 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/hund_rudy_2004/7_0.png)

# of singularities:  9
# Model: iribe_model_2006(iribe_model_2006.cellml)
No of piecewises: 5
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca = 4.0 * (-50.0 + membrane_potential__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * cell_parameters__F / (cell_parameters__R * cell_parameters__T)) - cell_parameters__Ca_o * exp(-2.0 * (-50.0 + membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * cell_parameters__F / ((1.0 - exp(-2.0 * (-50.0 + membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * cell_parameters__R * cell_parameters__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca = ((fabs(-50.0 + membrane_potential__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane_potential__V) * (-1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - cell_parameters__Ca_o * exp(9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999997780743e-8)) - 1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - cell_parameters__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) + 1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - cell_parameters__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) : (0.14973556329098189 * (-50.0 + membrane_potential__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - cell_parameters__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane_potential__V)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane_potential__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/iribe_model_2006/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K = 0.002 * (-50.0 + membrane_potential__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * cell_parameters__F / (cell_parameters__R * cell_parameters__T)) - cell_parameters__K_o * exp((50.0 - membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * cell_parameters__F / ((1.0 - exp((50.0 - membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * cell_parameters__R * cell_parameters__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K = ((fabs(-50.0 + membrane_potential__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane_potential__V) * (-1.999999999997175e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - cell_parameters__K_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 1.999999999997175e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - cell_parameters__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 1.999999999997175e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - cell_parameters__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (7.4867781645490941e-5 * (-50.0 + membrane_potential__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - cell_parameters__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane_potential__V)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane_potential__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/iribe_model_2006/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_Na = 0.01 * (-50.0 + membrane_potential__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * cell_parameters__F / (cell_parameters__R * cell_parameters__T)) - cell_parameters__Na_o * exp((50.0 - membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * cell_parameters__F / ((1.0 - exp((50.0 - membrane_potential__V) * cell_parameters__F / (cell_parameters__R * cell_parameters__T))) * cell_parameters__R * cell_parameters__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na = ((fabs(-50.0 + membrane_potential__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane_potential__V) * (-9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - cell_parameters__Na_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - cell_parameters__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - cell_parameters__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (-50.0 + membrane_potential__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - cell_parameters__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane_potential__V)) * L_type_Ca_channel__P_Ca_L_Ca * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane_potential__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/iribe_model_2006/3_0.png)

# of singularities:  3
# Model: IyerMazhariWinslow2004(iyer_2004.cellml)
No of piecewises: 1
## Equation 1:
```
COMPUTE_ICa_ICaK__ICamax = 4.0 * COMPUTE_ICa_ICaK__PCa * COMPUTE_ICa_ICaK__VFsq_over_RT * COMPUTE_ICa_ICaK__a1_Ca / COMPUTE_ICa_ICaK__a2_Ca
```
## New Eq:
```
COMPUTE_ICa_ICaK__ICamax = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 1.3355699481865283e-6) ? (374372.00550889381 * (1.3355699481865283e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (0.1351 * (0.001 * exp(9.9999999999999995e-8) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa_max / (-1.0 + exp(9.9999999999999995e-8)) + 0.1351 * (0.001 * exp(-9.9999999999999995e-8) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa_max / (-1.0 + exp(-9.9999999999999995e-8))) - 0.1351 * (0.001 * exp(-9.9999999999999995e-8) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa_max / (-1.0 + exp(-9.9999999999999995e-8))) : (101155.3158885031 * (0.001 * exp(0.074874401101778759 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_ICa_ICaK__PCa_max / (-1.0 + exp(0.074874401101778759 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/iyer_2004/1_0.png)

## Equation 2:
```
COMPUTE_ICa_ICaK__ICaK = COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa * COMPUTE_ICa_ICaK__PKprime * COMPUTE_ICa_ICaK__VFsq_over_RT * COMPUTE_ICa_ICaK__a1_K / COMPUTE_ICa_ICaK__a2_K
```
## New Eq:
```
COMPUTE_ICa_ICaK__ICaK = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.6711398963730566e-6) ? (187186.0027544469 * (2.6711398963730566e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(9.9999999999999995e-8))) + 3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(-9.9999999999999995e-8)))) - 3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(-9.9999999999999995e-8)))) : (0.01156711037185033 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/iyer_2004/2_1.png)
## Singularity point: 0
![Singularity](diagrams/manual_fixes/iyer_2004/2_2.png)

## Equation 3:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_K = COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__VFsq_over_RT * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a1_K / COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a2
```
## New Eq:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_K = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.6711398963730566e-6) ? (187186.0027544469 * (2.6711398963730566e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (0.0010711499999999999 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(9.9999999999999995e-8)) + 0.0010711499999999999 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(-9.9999999999999995e-8))) - 0.0010711499999999999 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(-9.9999999999999995e-8))) : (401.00857370085151 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/iyer_2004/3_0.png)

## Equation 4:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_Na = 0.02 * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__VFsq_over_RT * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a1_Na / COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a2
```
## New Eq:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_Na = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.6711398963730566e-6) ? (187186.0027544469 * (2.6711398963730566e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (2.1422999999999998e-5 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(9.9999999999999995e-8)) + 2.1422999999999998e-5 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(-9.9999999999999995e-8))) - 2.1422999999999998e-5 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(-9.9999999999999995e-8))) : (8.0201714740170313 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PtoSfactor / (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/iyer_2004/4_0.png)

# of singularities:  4
# Model: iyer_model_2007(iyer_model_2007.cellml)
No of piecewises: 7
## Equation 1:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_K = COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__VFsq_over_RT * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a1_K / COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a2
```
## New Eq:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_K = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.6711398963730566e-6) ? (187186.0027544469 * (2.6711398963730566e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (4.0150763800799996e-10 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(9.9999999999999995e-8)) + 4.0150763800799996e-10 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(-9.9999999999999995e-8))) - 4.0150763800799996e-10 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(-9.9999999999999995e-8))) : (0.00015031321966819388 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/iyer_model_2007/1_0.png)

## Equation 2:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_Na = 0.02 * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__PKv14 * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__VFsq_over_RT * COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a1_Na / COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__a2
```
## New Eq:
```
COMPUTE_INa_IKr_IKs_Ito1_IK1_INab_IKp__IKv14_Na = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.6711398963730566e-6) ? (187186.0027544469 * (2.6711398963730566e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (8.030152760159999e-12 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(9.9999999999999995e-8)) + 8.030152760159999e-12 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(-9.9999999999999995e-8))) - 8.030152760159999e-12 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(-9.9999999999999995e-8))) : (3.006264393363878e-6 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nao + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14 / (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/iyer_model_2007/2_0.png)

## Equation 3:
```
COMPUTE_ICa_ICaK__ICamax = 4.0 * COMPUTE_ICa_ICaK__PCa * COMPUTE_ICa_ICaK__VFsq_over_RT * COMPUTE_ICa_ICaK__a1_Ca / COMPUTE_ICa_ICaK__a2_Ca
```
## New Eq:
```
COMPUTE_ICa_ICaK__ICamax = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 1.3355699481865283e-6) ? (374372.00550889381 * (1.3355699481865283e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (0.019299999999999998 * (0.001 * exp(9.9999999999999995e-8) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa / (-1.0 + exp(9.9999999999999995e-8)) + 0.019299999999999998 * (0.001 * exp(-9.9999999999999995e-8) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa / (-1.0 + exp(-9.9999999999999995e-8))) - 0.019299999999999998 * (0.001 * exp(-9.9999999999999995e-8) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_ICa_ICaK__PCa / (-1.0 + exp(-9.9999999999999995e-8))) : (14450.7594126433 * (0.001 * exp(0.074874401101778759 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) - 0.34100000000000003 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cao) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_ICa_ICaK__PCa / (-1.0 + exp(0.074874401101778759 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/iyer_model_2007/3_0.png)

## Equation 4:
```
COMPUTE_ICa_ICaK__ICaK = COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa * COMPUTE_ICa_ICaK__PKprime * COMPUTE_ICa_ICaK__VFsq_over_RT * COMPUTE_ICa_ICaK__a1_K / COMPUTE_ICa_ICaK__a2_K
```
## New Eq:
```
COMPUTE_ICa_ICaK__ICaK = ((fabs(COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) < 2.6711398963730566e-6) ? (187186.0027544469 * (2.6711398963730566e-6 + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V) * (3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(9.9999999999999995e-8))) + 3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(-9.9999999999999995e-8)))) - 3.0897370000000001e-8 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(-9.9999999999999995e-8)) * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(-9.9999999999999995e-8)))) : (0.01156711037185033 * (-COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ko + COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki * exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)) * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open * COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa / ((1.0 - 3.773584905660377 * COMPUTE_ICa_ICaK__Icabar) * (-1.0 + exp(0.03743720055088938 * COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__V)))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/iyer_model_2007/4_0.png)
## Singularity point: 0
![Singularity](diagrams/manual_fixes/iyer_model_2007/4_1.png)

# of singularities:  4
# Model: jafri_rice_winslow_1998(jafri_rice_winslow_model_1998.cellml)
No of piecewises: 4
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca_max = 4.0 * pow(membrane__F, 2) * (0.001 * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T)) - 0.34100000000000003 * ionic_concentrations__Cao) * L_type_Ca_channel__P_Ca * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_max = ((fabs(membrane__V) < 1.3307320976818627e-6) ? (375733.02761014085 * (1.3307320976818627e-6 + membrane__V) * (0.019369000000000001 * (0.001 * exp(9.9999999999999995e-8) - 0.34100000000000003 * ionic_concentrations__Cao) * L_type_Ca_channel__P_Ca / (-1.0 + exp(9.9999999999999995e-8)) + 0.019369000000000001 * (0.001 * exp(-9.9999999999999995e-8) - 0.34100000000000003 * ionic_concentrations__Cao) * L_type_Ca_channel__P_Ca / (-1.0 + exp(-9.9999999999999995e-8))) - 0.019369000000000001 * (0.001 * exp(-9.9999999999999995e-8) - 0.34100000000000003 * ionic_concentrations__Cao) * L_type_Ca_channel__P_Ca / (-1.0 + exp(-9.9999999999999995e-8))) : (14555.146023561636 * (0.001 * exp(0.075146605522028176 * membrane__V) - 0.34100000000000003 * ionic_concentrations__Cao) * L_type_Ca_channel__P_Ca * membrane__V / (-1.0 + exp(0.075146605522028176 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/jafri_rice_winslow_model_1998/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K = pow(membrane__F, 2) * (-ionic_concentrations__Ko + ionic_concentrations__Ki * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * (L_type_Ca_channel__O + L_type_Ca_channel__O_Ca) * L_type_Ca_channel__p_k * L_type_Ca_channel_y_gate__y * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K = ((fabs(membrane__V) < 2.6614641953637254e-6) ? (187866.51380507043 * (2.6614641953637254e-6 + membrane__V) * (9.6845000000000006e-12 * (-ionic_concentrations__Ko + ionic_concentrations__Ki * exp(9.9999999999999995e-8)) * (L_type_Ca_channel__O + L_type_Ca_channel__O_Ca) * L_type_Ca_channel_y_gate__y / ((1.0 - 218.34061135371181 * L_type_Ca_channel__i_Ca_L_Ca_max) * (-1.0 + exp(9.9999999999999995e-8))) + 9.6845000000000006e-12 * (-ionic_concentrations__Ko + ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) * (L_type_Ca_channel__O + L_type_Ca_channel__O_Ca) * L_type_Ca_channel_y_gate__y / ((1.0 - 218.34061135371181 * L_type_Ca_channel__i_Ca_L_Ca_max) * (-1.0 + exp(-9.9999999999999995e-8)))) - 9.6845000000000006e-12 * (-ionic_concentrations__Ko + ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) * (L_type_Ca_channel__O + L_type_Ca_channel__O_Ca) * L_type_Ca_channel_y_gate__y / ((1.0 - 218.34061135371181 * L_type_Ca_channel__i_Ca_L_Ca_max) * (-1.0 + exp(-9.9999999999999995e-8)))) : (3.6387865058904094e-6 * (-ionic_concentrations__Ko + ionic_concentrations__Ki * exp(0.037573302761014088 * membrane__V)) * (L_type_Ca_channel__O + L_type_Ca_channel__O_Ca) * L_type_Ca_channel_y_gate__y * membrane__V / ((1.0 - 218.34061135371181 * L_type_Ca_channel__i_Ca_L_Ca_max) * (-1.0 + exp(0.037573302761014088 * membrane__V)))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/jafri_rice_winslow_model_1998/2_0.png)
## Singularity point: 0
![Singularity](diagrams/manual_fixes/jafri_rice_winslow_model_1998/2_1.png)

## Equation 3:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + membrane__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/jafri_rice_winslow_model_1998/3_0.png)

## Equation 4:
```
non_specific_calcium_activated_current__I_ns_K = pow(membrane__F, 2) * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(membrane__F * non_specific_calcium_activated_current__VnsCa / (membrane__R * membrane__T))) * non_specific_calcium_activated_current__P_ns_Ca * non_specific_calcium_activated_current__VnsCa / ((-1.0 + exp(membrane__F * non_specific_calcium_activated_current__VnsCa / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
non_specific_calcium_activated_current__I_ns_K = ((fabs(-26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) < 2.6614641953637254e-6) ? (187866.51380507043 * (1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) * (2.6614641953637254e-6 - 26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) - 1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (6.3678763853082156e-6 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037573302761014088 * membrane__V - log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)))) * (-26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) / (-1.0 + exp(0.037573302761014088 * membrane__V - log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai))))))
```
## Singularity point: -1.5174919438451304
![Singularity](diagrams/manual_fixes/jafri_rice_winslow_model_1998/4_0.png)

## Equation 5:
```
non_specific_calcium_activated_current__I_ns_Na = pow(membrane__F, 2) * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(membrane__F * non_specific_calcium_activated_current__VnsCa / (membrane__R * membrane__T))) * non_specific_calcium_activated_current__P_ns_Ca * non_specific_calcium_activated_current__VnsCa / ((-1.0 + exp(membrane__F * non_specific_calcium_activated_current__VnsCa / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
non_specific_calcium_activated_current__I_ns_Na = ((fabs(-26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) < 2.6614641953637254e-6) ? (187866.51380507043 * (1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) * (2.6614641953637254e-6 - 26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) - 1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (6.3678763853082156e-6 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037573302761014088 * membrane__V - log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)))) * (-26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) / (-1.0 + exp(0.037573302761014088 * membrane__V - log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai))))))
```
## Singularity point: -1.5174919438451304
![Singularity](diagrams/manual_fixes/jafri_rice_winslow_model_1998/5_0.png)

## Equation 6:
```
time_dependent_potassium_current_X_gate__alpha_X = 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_X_gate__alpha_X = ((fabs(30.0 + membrane__V) < 6.7567567568760367e-7) ? (4.8581081081938701e-11 / (1.0 - exp(-1.0000000000176534e-7)) - 739999.99998693645 * (29.999999324324325 + membrane__V) * (-4.8581081081938701e-11 / (1.0 - exp(1.0000000000176534e-7)) - 4.8581081081938701e-11 / (1.0 - exp(-1.0000000000176534e-7)))) : (7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/jafri_rice_winslow_model_1998/6_0.png)

## Equation 7:
```
time_dependent_potassium_current_X_gate__beta_X = 0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_X_gate__beta_X = ((fabs(30.0 + membrane__V) < 1.455604075689676e-6) ? (-1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + membrane__V) * (1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)))) : (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/jafri_rice_winslow_model_1998/7_0.png)

# of singularities:  7
# Model: kurata_model_2002(kurata_model_2002.cellml)
No of piecewises: 0
## Equation 1:
```
L_type_calcium_channel_current_d_gate__alpha_d = -0.028389999999999999 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)) - 0.084900000000000003 * membrane__V / (-1.0 + exp(-0.20798668885191349 * membrane__V))
```
## New Eq:
```
L_type_calcium_channel_current_d_gate__alpha_d = ((fabs(35.0 + membrane__V) < 2.5000000000718892e-7) ? (-7.0975000009920736e-9 / (-1.0 + exp(-1.000000000139778e-7)) - 1999999.9999424887 * (34.999999750000001 + membrane__V) * (7.0975000009920736e-9 / (-1.0 + exp(-1.000000000139778e-7)) + 7.0974999994161126e-9 / (-1.0 + exp(9.9999999991773334e-8)))) : (-0.028389999999999999 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)))) + ((fabs(membrane__V) < 4.8079999999999991e-7) ? (-4.0819919999999999e-8 / (-1.0 + exp(-9.9999999999999995e-8)) - 1039933.4442595674 * (-4.8079999999999991e-7 + membrane__V) * (4.0819919999999999e-8 / (-1.0 + exp(9.9999999999999995e-8)) + 4.0819919999999999e-8 / (-1.0 + exp(-9.9999999999999995e-8)))) : (-0.084900000000000003 * membrane__V / (-1.0 + exp(-0.20798668885191349 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/kurata_model_2002/1_0.png)
## Singularity point: -35.000000000000000
![Singularity](diagrams/manual_fixes/kurata_model_2002/1_1.png)

## Equation 2:
```
L_type_calcium_channel_current_d_gate__beta_d = 0.011429999999999999 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))
```
## New Eq:
```
L_type_calcium_channel_current_d_gate__beta_d = ((fabs(-5.0 + membrane__V) < 2.5000000000025002e-7) ? (-2.8575000000028576e-9 / (-1.0 + exp(-1.0000000000010001e-7)) + 1999999.9999979998 * (-4.9999997499999997 + membrane__V) * (2.8575000000028576e-9 / (-1.0 + exp(1.0000000000010001e-7)) + 2.8575000000028576e-9 / (-1.0 + exp(-1.0000000000010001e-7)))) : (0.011429999999999999 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))))
```
## Singularity point: 5.0000000000000000
![Singularity](diagrams/manual_fixes/kurata_model_2002/2_0.png)

# of singularities:  3
# Model: lindblad_atrial_model_1996(lindblad_model_1996.cellml)
No of piecewises: 0
## Equation 1:
```
L_type_Ca_channel_d_L_gate__alpha_d_L = -50.0 * membrane__V / (-1.0 + exp(-0.20798668885191349 * membrane__V)) - 16.719999999999999 * L_type_Ca_channel_d_L_gate__E0_alpha_d_L / (-1.0 + exp(-0.40000000000000002 * L_type_Ca_channel_d_L_gate__E0_alpha_d_L))
```
## New Eq:
```
L_type_Ca_channel_d_L_gate__alpha_d_L = ((fabs(35.0 + membrane__V) < 2.5000000000718892e-7) ? (-4.1800000005842713e-6 / (-1.0 + exp(-1.000000000139778e-7)) - 1999999.9999424887 * (34.999999750000001 + membrane__V) * (4.1800000005842713e-6 / (-1.0 + exp(-1.000000000139778e-7)) + 4.1799999996561256e-6 / (-1.0 + exp(9.9999999991773334e-8)))) : (-16.719999999999999 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)))) + ((fabs(membrane__V) < 4.8079999999999991e-7) ? (-2.4039999999999997e-5 / (-1.0 + exp(-9.9999999999999995e-8)) - 1039933.4442595674 * (-4.8079999999999991e-7 + membrane__V) * (2.4039999999999997e-5 / (-1.0 + exp(9.9999999999999995e-8)) + 2.4039999999999997e-5 / (-1.0 + exp(-9.9999999999999995e-8)))) : (-50.0 * membrane__V / (-1.0 + exp(-0.20798668885191349 * membrane__V))))
```
## Singularity point: -35.000000000000000
![Singularity](diagrams/manual_fixes/lindblad_model_1996/1_0.png)
## Singularity point: 0
![Singularity](diagrams/manual_fixes/lindblad_model_1996/1_1.png)

## Equation 2:
```
L_type_Ca_channel_d_L_gate__beta_d_L = 4.4800000000000004 * L_type_Ca_channel_d_L_gate__E0_beta_d_L / (-1.0 + exp(0.40000000000000002 * L_type_Ca_channel_d_L_gate__E0_beta_d_L))
```
## New Eq:
```
L_type_Ca_channel_d_L_gate__beta_d_L = ((fabs(-5.0 + membrane__V) < 2.5000000000025002e-7) ? (-1.1200000000011203e-6 / (-1.0 + exp(-1.0000000000010001e-7)) + 1999999.9999979998 * (-4.9999997499999997 + membrane__V) * (1.1200000000011203e-6 / (-1.0 + exp(1.0000000000010001e-7)) + 1.1200000000011203e-6 / (-1.0 + exp(-1.0000000000010001e-7)))) : (4.4800000000000004 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))))
```
## Singularity point: 5.0000000000000000
![Singularity](diagrams/manual_fixes/lindblad_model_1996/2_0.png)

## Equation 3:
```
L_type_Ca_channel_f_L_gate__alpha_f_L = 8.4900000000000002 * L_type_Ca_channel_f_L_gate__E0_f_L / (-1.0 + exp(0.25 * L_type_Ca_channel_f_L_gate__E0_f_L))
```
## New Eq:
```
L_type_Ca_channel_f_L_gate__alpha_f_L = ((fabs(28.0 + membrane__V) < 4.0000000001150227e-7) ? (-3.3960000000976542e-6 / (-1.0 + exp(-1.0000000000287557e-7)) + 1249999.9999640554 * (28.000000400000001 + membrane__V) * (3.3960000000976542e-6 / (-1.0 + exp(1.0000000000287557e-7)) + 3.3960000000976542e-6 / (-1.0 + exp(-1.0000000000287557e-7)))) : (8.4900000000000002 * (28.0 + membrane__V) / (-1.0 + exp(7.0 + 0.25 * membrane__V))))
```
## Singularity point: -28.000000000000000
![Singularity](diagrams/manual_fixes/lindblad_model_1996/3_0.png)

## Equation 4:
```
sodium_current_m_gate__alpha_m = -460.0 * sodium_current_m_gate__E0_m / (-1.0 + exp(-0.078907914463820727 * sodium_current_m_gate__E0_m))
```
## New Eq:
```
sodium_current_m_gate__alpha_m = ((fabs(44.399999999999999 + membrane__V) < 1.2672999999963075e-6) ? (-0.00058295799999830145 / (-1.0 + exp(-9.9999999999708629e-8)) - 394539.57232025318 * (44.399998732699999 + membrane__V) * (0.00058295799999830145 / (-1.0 + exp(9.9999999999708629e-8)) + 0.00058295799999830145 / (-1.0 + exp(-9.9999999999708629e-8)))) : (-460.0 * (44.399999999999999 + membrane__V) / (-1.0 + exp(-3.5035114021936398 - 0.078907914463820727 * membrane__V))))
```
## Singularity point: -44.399999999999999
![Singularity](diagrams/manual_fixes/lindblad_model_1996/4_0.png)

## Equation 5:
```
sodium_current__i_Na = pow(membrane__F, 2) * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp((-sodium_current__E_Na + membrane__V) * membrane__F / (membrane__R * membrane__T))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
sodium_current__i_Na = ((fabs(membrane__V) < 2.6541413816729869e-6) ? (188384.84017940093 * (2.6541413816729869e-6 + membrane__V) * (0.0096485341499999988 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(9.9999999999999995e-8)) + 0.0096485341499999988 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-9.9999999999999995e-8))) - 0.0096485341499999988 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-9.9999999999999995e-8))) : (3635.2751276264835 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(0.037676968035880179 * membrane__V - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.36499999999999999 * sodium_current_h2_gate__h2 + 0.63500000000000001 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / (-1.0 + exp(0.037676968035880179 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/lindblad_model_1996/5_0.png)

# of singularities:  6
# Model: LivshitzRudy2007(livshitz_rudy_2007.cellml)
No of piecewises: 0
## Equation 1:
```
ICaL__ibarca = 4.0 * (-Environment__Ca_o * ICaL__gacao + Ca__Ca_i * ICaL__gacai * exp(2.0 * Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * ICaL__pca * cell__V / (-1.0 + exp(2.0 * Environment__FonRT * cell__V))
```
## New Eq:
```
ICaL__ibarca = ((fabs(cell__V) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + cell__V) * (0.019296999999999998 * (-0.34100000000000003 * Environment__Ca_o + (-0.040960000000000003 + 0.33333333333333331 * Ca__Ca_T + 0.66666666666666663 * sqrt(-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T) * cos(0.33333333333333331 * acos(0.5 * pow((-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T), (-1.5)) * (3.2130000000000006e-5 * Ca__Ca_T - 2.0 * pow((0.12288 - Ca__Ca_T), 3) + 9.0 * (0.12288 - Ca__Ca_T) * (0.00019279000000000003 - 0.0028800000000000002 * Ca__Ca_T))))) * exp(9.9999999999999995e-8)) * ICaL__pca / (-1.0 + exp(9.9999999999999995e-8)) + 0.019296999999999998 * (-0.34100000000000003 * Environment__Ca_o + (-0.040960000000000003 + 0.33333333333333331 * Ca__Ca_T + 0.66666666666666663 * sqrt(-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T) * cos(0.33333333333333331 * acos(0.5 * pow((-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T), (-1.5)) * (3.2130000000000006e-5 * Ca__Ca_T - 2.0 * pow((0.12288 - Ca__Ca_T), 3) + 9.0 * (0.12288 - Ca__Ca_T) * (0.00019279000000000003 - 0.0028800000000000002 * Ca__Ca_T))))) * exp(-9.9999999999999995e-8)) * ICaL__pca / (-1.0 + exp(-9.9999999999999995e-8))) - 0.019296999999999998 * (-0.34100000000000003 * Environment__Ca_o + (-0.040960000000000003 + 0.33333333333333331 * Ca__Ca_T + 0.66666666666666663 * sqrt(-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T) * cos(0.33333333333333331 * acos(0.5 * pow((-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T), (-1.5)) * (3.2130000000000006e-5 * Ca__Ca_T - 2.0 * pow((0.12288 - Ca__Ca_T), 3) + 9.0 * (0.12288 - Ca__Ca_T) * (0.00019279000000000003 - 0.0028800000000000002 * Ca__Ca_T))))) * exp(-9.9999999999999995e-8)) * ICaL__pca / (-1.0 + exp(-9.9999999999999995e-8))) : (14448.004881001343 * (-0.34100000000000003 * Environment__Ca_o + (-0.040960000000000003 + 0.33333333333333331 * Ca__Ca_T + 0.66666666666666663 * sqrt(-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T) * cos(0.33333333333333331 * acos(0.5 * pow((-0.00057837000000000014 + pow((0.12288 - Ca__Ca_T), 2) + 0.0086400000000000001 * Ca__Ca_T), (-1.5)) * (3.2130000000000006e-5 * Ca__Ca_T - 2.0 * pow((0.12288 - Ca__Ca_T), 3) + 9.0 * (0.12288 - Ca__Ca_T) * (0.00019279000000000003 - 0.0028800000000000002 * Ca__Ca_T))))) * exp(0.074871767015605231 * cell__V)) * ICaL__pca * cell__V / (-1.0 + exp(0.074871767015605231 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/livshitz_rudy_2007/1_0.png)

## Equation 2:
```
ICaL__ibark = (-Environment__K_o * ICaL__gako + ICaL__gaki * K__K_i * exp(Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * ICaL__pk * cell__V / (-1.0 + exp(Environment__FonRT * cell__V))
```
## New Eq:
```
ICaL__ibark = ((fabs(cell__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + cell__V) * (1.8621604999999999e-9 * (-0.75 * Environment__K_o + 0.75 * K__K_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.8621604999999999e-9 * (-0.75 * Environment__K_o + 0.75 * K__K_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 1.8621604999999999e-9 * (-0.75 * Environment__K_o + 0.75 * K__K_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.00069711623550831479 * (-0.75 * Environment__K_o + 0.75 * K__K_i * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/livshitz_rudy_2007/2_0.png)

## Equation 3:
```
ICaL__ibarna = (-Environment__Na_o * ICaL__ganao + ICaL__ganai * Na__Na_i * exp(Environment__FonRT * cell__V)) * Environment__F * Environment__FonRT * ICaL__pna * cell__V / (-1.0 + exp(Environment__FonRT * cell__V))
```
## New Eq:
```
ICaL__ibarna = ((fabs(cell__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + cell__V) * (6.5127375e-9 * (-0.75 * Environment__Na_o + 0.75 * Na__Na_i * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 6.5127375e-9 * (-0.75 * Environment__Na_o + 0.75 * Na__Na_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 6.5127375e-9 * (-0.75 * Environment__Na_o + 0.75 * Na__Na_i * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.0024381008236689767 * (-0.75 * Environment__Na_o + 0.75 * Na__Na_i * exp(0.037435883507802616 * cell__V)) * cell__V / (-1.0 + exp(0.037435883507802616 * cell__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/livshitz_rudy_2007/3_0.png)

## Equation 4:
```
ICaL__taud = 28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * cell__V)) * ICaL__dss0 / (10.0 + cell__V)
```
## New Eq:
```
ICaL__taud = ((fabs(10.0 + cell__V) < 6.2399999999074307e-7) ? (45787545.788225032 * (1.0 - exp(-9.999999999851651e-8)) / (1.0 + exp(-9.999999999851651e-8)) - 801282.05129393819 * (9.9999993759999999 + cell__V) * (-45787545.788225032 * (1.0 - exp(9.999999999851651e-8)) / (1.0 + exp(9.999999999851651e-8)) - 45787545.788225032 * (1.0 - exp(-9.999999999851651e-8)) / (1.0 + exp(-9.999999999851651e-8)))) : (28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * cell__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * cell__V)) * (10.0 + cell__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/manual_fixes/livshitz_rudy_2007/4_0.png)

## Equation 5:
```
IKr__tauxr = 1 / (0.00060999999999999997 * (38.899999999999999 + cell__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * cell__V)) + 0.0013799999999999999 * (14.199999999999999 + cell__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * cell__V)))
```
## New Eq:
```
IKr__tauxr = 1 / (((fabs(14.199999999999999 + cell__V) < 8.1300813007528783e-7) ? (1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)) - 615000.00000454858 * (14.199999186991869 + cell__V) * (-1.1219512194943214e-9 / (1.0 - exp(9.9999999998406912e-8)) - 1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)))) : (0.0013799999999999999 * (14.199999999999999 + cell__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * cell__V)))) + ((fabs(38.899999999999999 + cell__V) < 6.896551724422384e-7) ? (-4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 724999.99997009686 * (38.900000689655172 + cell__V) * (4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 4.2068965520669629e-10 / (-1.0 + exp(1.0000000000814911e-7)))) : (0.00060999999999999997 * (38.899999999999999 + cell__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * cell__V)))))
```
## Singularity point: -14.199999999999999
![Singularity](diagrams/manual_fixes/livshitz_rudy_2007/5_0.png)
## Singularity point: -38.899999999999999
![Singularity](diagrams/manual_fixes/livshitz_rudy_2007/5_1.png)

## Equation 6:
```
IKs__tauxs = 1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))
```
## New Eq:
```
IKs__tauxs = ((fabs(30.0 + cell__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + cell__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/livshitz_rudy_2007/6_0.png)

## Equation 7:
```
INa__am = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa__am = ((fabs(47.130000000000003 + cell__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + cell__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/livshitz_rudy_2007/7_0.png)

# of singularities:  8
# Model: Li_Mouse_2010(li_mouse_2010.cellml)
No of piecewises: 3
## Equation 1:
```
slow_delayed_rectifier_K_I__alpha_n = 4.8133299999999997e-6 * (26.5 + cell__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * cell__V))
```
## New Eq:
```
slow_delayed_rectifier_K_I__alpha_n = ((fabs(26.5 + cell__V) < 7.8124999999817923e-7) ? (3.7604140624912359e-12 / (1.0 - exp(-9.9999999999766942e-8)) - 640000.00000149151 * (26.499999218749998 + cell__V) * (-3.7604140624912359e-12 / (1.0 - exp(9.9999999999766942e-8)) - 3.7604140624912359e-12 / (1.0 - exp(-9.9999999999766942e-8)))) : (4.8133299999999997e-6 * (26.5 + cell__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * cell__V))))
```
## Singularity point: -26.500000000000000
![Singularity](diagrams/manual_fixes/li_mouse_2010/1_0.png)

# of singularities:  1
# Model: luo_rudy_1991(luo_rudy_1991.cellml)
No of piecewises: 7
# of singularities:  0
# Model: luo_rudy_1994(luo_rudy_1994.cellml)
No of piecewises: 5
## Equation 1:
```
L_type_Ca_channel__I_CaCa = 4.0 * pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Cao * ionic_concentrations__Cao + L_type_Ca_channel__gamma_Cai * ionic_concentrations__Cai * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Ca * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaCa = ((fabs(membrane__V) < 1.3307320976818627e-6) ? (375733.02761014085 * (1.3307320976818627e-6 + membrane__V) * (1.0459259999999999e-7 * (-0.34000000000000002 * ionic_concentrations__Cao + ionic_concentrations__Cai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.0459259999999999e-7 * (-0.34000000000000002 * ionic_concentrations__Cao + ionic_concentrations__Cai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 1.0459259999999999e-7 * (-0.34000000000000002 * ionic_concentrations__Cao + ionic_concentrations__Cai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.078597788527232842 * (-0.34000000000000002 * ionic_concentrations__Cao + ionic_concentrations__Cai * exp(0.075146605522028176 * membrane__V)) * membrane__V / (-1.0 + exp(0.075146605522028176 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/luo_rudy_1994/1_0.png)

## Equation 2:
```
L_type_Ca_channel__I_CaK = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_K * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaK = ((fabs(membrane__V) < 2.6614641953637254e-6) ? (187866.51380507043 * (2.6614641953637254e-6 + membrane__V) * (1.8691085000000002e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.8691085000000002e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 1.8691085000000002e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (7.0228579563684903e-6 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037573302761014088 * membrane__V)) * membrane__V / (-1.0 + exp(0.037573302761014088 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/luo_rudy_1994/2_0.png)

## Equation 3:
```
L_type_Ca_channel__I_CaNa = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Na * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaNa = ((fabs(membrane__V) < 2.6614641953637254e-6) ? (187866.51380507043 * (2.6614641953637254e-6 + membrane__V) * (6.5370374999999993e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 6.5370374999999993e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 6.5370374999999993e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (2.4561808914760263e-5 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037573302761014088 * membrane__V)) * membrane__V / (-1.0 + exp(0.037573302761014088 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/luo_rudy_1994/3_0.png)

## Equation 4:
```
L_type_Ca_channel_d_gate__tau_d = 28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * L_type_Ca_channel_d_gate__d_infinity / (10.0 + membrane__V)
```
## New Eq:
```
L_type_Ca_channel_d_gate__tau_d = ((fabs(10.0 + membrane__V) < 6.2399999999074307e-7) ? (45787545.788225032 * (1.0 - exp(-9.999999999851651e-8)) / (1.0 + exp(-9.999999999851651e-8)) - 801282.05129393819 * (9.9999993759999999 + membrane__V) * (-45787545.788225032 * (1.0 - exp(9.999999999851651e-8)) / (1.0 + exp(9.999999999851651e-8)) - 45787545.788225032 * (1.0 - exp(-9.999999999851651e-8)) / (1.0 + exp(-9.999999999851651e-8)))) : (28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * (10.0 + membrane__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/manual_fixes/luo_rudy_1994/4_0.png)

## Equation 5:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + membrane__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/luo_rudy_1994/5_0.png)

## Equation 6:
```
non_specific_calcium_activated_current__I_ns_K = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(membrane__F * non_specific_calcium_activated_current__Vns / (membrane__R * membrane__T))) * non_specific_calcium_activated_current__P_ns_Ca * non_specific_calcium_activated_current__Vns / ((-1.0 + exp(membrane__F * non_specific_calcium_activated_current__Vns / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
non_specific_calcium_activated_current__I_ns_K = ((fabs(-26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) < 2.6614641953637254e-6) ? (187866.51380507043 * (1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) * (2.6614641953637254e-6 - 26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) - 1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (6.3678763853082156e-6 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037573302761014088 * membrane__V - log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)))) * (-26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) / (-1.0 + exp(0.037573302761014088 * membrane__V - log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai))))))
```
## Singularity point: -1.7016484344348868
![Singularity](diagrams/manual_fixes/luo_rudy_1994/6_0.png)

## Equation 7:
```
non_specific_calcium_activated_current__I_ns_Na = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(membrane__F * non_specific_calcium_activated_current__Vns / (membrane__R * membrane__T))) * non_specific_calcium_activated_current__P_ns_Ca * non_specific_calcium_activated_current__Vns / ((-1.0 + exp(membrane__F * non_specific_calcium_activated_current__Vns / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
non_specific_calcium_activated_current__I_ns_Na = ((fabs(-26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) < 2.6614641953637254e-6) ? (187866.51380507043 * (1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) * (2.6614641953637254e-6 - 26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) - 1.6947874999999998e-11 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (6.3678763853082156e-6 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037573302761014088 * membrane__V - log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)))) * (-26.614641953637257 * log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai)) + membrane__V) / (-1.0 + exp(0.037573302761014088 * membrane__V - log((ionic_concentrations__Ko + ionic_concentrations__Nao) / (ionic_concentrations__Ki + ionic_concentrations__Nai))))))
```
## Singularity point: -1.7016484344348868
![Singularity](diagrams/manual_fixes/luo_rudy_1994/7_0.png)

## Equation 8:
```
time_dependent_potassium_current_X_gate__alpha_X = 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_X_gate__alpha_X = ((fabs(30.0 + membrane__V) < 6.7567567568760367e-7) ? (4.8581081081938701e-11 / (1.0 - exp(-1.0000000000176534e-7)) - 739999.99998693645 * (29.999999324324325 + membrane__V) * (-4.8581081081938701e-11 / (1.0 - exp(1.0000000000176534e-7)) - 4.8581081081938701e-11 / (1.0 - exp(-1.0000000000176534e-7)))) : (7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/luo_rudy_1994/8_0.png)

## Equation 9:
```
time_dependent_potassium_current_X_gate__beta_X = 0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V))
```
## New Eq:
```
time_dependent_potassium_current_X_gate__beta_X = ((fabs(30.0 + membrane__V) < 1.455604075689676e-6) ? (-1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + membrane__V) * (1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)))) : (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/luo_rudy_1994/9_0.png)

# of singularities:  9
# Model: MahajanShiferaw2008_units(mahajan_shiferaw_2008.cellml)
No of piecewises: 10
# of singularities:  0
# Model: Maleckar(maleckar_model_2009.cellml)
No of piecewises: 0
## Equation 1:
```
sodium_current__i_Na = pow(membrane__F, 2) * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp((-sodium_current__E_Na + membrane__V) * membrane__F / (membrane__R * membrane__T))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
sodium_current__i_Na = ((fabs(membrane__V) < 2.6380041870925613e-6) ? (189537.22759290531 * (2.6380041870925613e-6 + membrane__V) * (0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(9.9999999999999995e-8)) + 0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-9.9999999999999995e-8))) - 0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-9.9999999999999995e-8))) : (3657.5756957513308 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(0.037907445518581065 * membrane__V - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / (-1.0 + exp(0.037907445518581065 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/maleckar_model_2009/1_0.png)

# of singularities:  1
# Model: maltsev_2009(maltsev_2009.cellml)
No of piecewises: 2
# of singularities:  0
# Model: matsuoka_model_2003(matsuoka_model_2003.cellml)
No of piecewises: 4
# of singularities:  0
# Model: mcallister_noble_tsien_1975_modelB(mcallister_noble_tsien_1975_b.cellml)
No of piecewises: 0
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = (47.0 + membrane__V) / (1.0 - exp(-4.7000000000000002 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.0 + membrane__V) < 1.0000000000287557e-6) ? (9.9999999997324451e-7 / (1.0 - exp(-9.9999999997324457e-8)) - 499999.99998562218 * (46.999999000000003 + membrane__V) * (-9.9999999997324451e-7 / (1.0 - exp(-9.9999999997324457e-8)) - 1.0000000000842668e-6 / (1.0 - exp(1.0000000000842668e-7)))) : ((47.0 + membrane__V) / (1.0 - exp(-4.7000000000000002 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.000000000000000
![Singularity](diagrams/manual_fixes/mcallister_noble_tsien_1975_b/1_0.png)

## Equation 2:
```
pacemaker_potassium_current_s_gate__alpha_s = 0.001 * (-pacemaker_potassium_current_s_gate__E_s + membrane__V) / (1.0 - exp(0.20000000000000001 * pacemaker_potassium_current_s_gate__E_s - 0.20000000000000001 * membrane__V))
```
## New Eq:
```
pacemaker_potassium_current_s_gate__alpha_s = ((fabs(52.0 + membrane__V) < 5.0000000001437783e-7) ? (5.0000000001437788e-10 / (1.0 - exp(-1.0000000000287557e-7)) - 999999.99997124437 * (51.999999500000001 + membrane__V) * (-5.0000000001437788e-10 / (1.0 - exp(1.0000000000287557e-7)) - 5.0000000001437788e-10 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.001 * (52.0 + membrane__V) / (1.0 - exp(-10.4 - 0.20000000000000001 * membrane__V))))
```
## Singularity point: -52.000000000000000
![Singularity](diagrams/manual_fixes/mcallister_noble_tsien_1975_b/2_0.png)

## Equation 3:
```
secondary_inward_current_d_gate__alpha_d = 0.002 * (40.0 + membrane__V) / (1.0 - exp(-4.0 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
secondary_inward_current_d_gate__alpha_d = ((fabs(40.0 + membrane__V) < 1.0000000000010001e-6) ? (1.999999999946489e-9 / (1.0 - exp(-9.9999999997324457e-8)) - 499999.99999949994 * (39.999999000000003 + membrane__V) * (-1.999999999946489e-9 / (1.0 - exp(-9.9999999997324457e-8)) - 2.0000000000575115e-9 / (1.0 - exp(1.0000000000287557e-7)))) : (0.002 * (40.0 + membrane__V) / (1.0 - exp(-4.0 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -40.000000000000000
![Singularity](diagrams/manual_fixes/mcallister_noble_tsien_1975_b/3_0.png)

## Equation 4:
```
time_independent_outward_current__i_K1 = 0.35714285714285715 * pacemaker_potassium_current__I_K2 + 0.20000000000000001 * (-time_independent_outward_current__E_K1 + membrane__V) / (1.0 - exp(0.040000000000000001 * time_independent_outward_current__E_K1 - 0.040000000000000001 * membrane__V))
```
## New Eq:
```
time_independent_outward_current__i_K1 = (-1.0 + exp(4.4000000000000004 + 0.040000000000000001 * membrane__V)) / (exp(2.3999999999999999 + 0.040000000000000001 * membrane__V) + exp(4.7999999999999998 + 0.080000000000000002 * membrane__V)) + ((fabs(30.0 + membrane__V) < 2.4999999999886224e-6) ? (4.9999999999772453e-7 / (1.0 - exp(-9.9999999999544901e-8)) - 200000.00000091019 * (29.999997499999999 + membrane__V) * (-4.9999999999772453e-7 / (1.0 - exp(9.9999999999544901e-8)) - 4.9999999999772453e-7 / (1.0 - exp(-9.9999999999544901e-8)))) : (0.20000000000000001 * (30.0 + membrane__V) / (1.0 - exp(-1.2 - 0.040000000000000001 * membrane__V))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/mcallister_noble_tsien_1975_b/4_0.png)

## Equation 5:
```
transient_chloride_current_q_gate__alpha_q = 0.0080000000000000002 * membrane__V / (1.0 - exp(-0.10000000000000001 * membrane__V))
```
## New Eq:
```
transient_chloride_current_q_gate__alpha_q = ((fabs(membrane__V) < 9.9999999999999995e-7) ? (7.9999999999999988e-9 / (1.0 - exp(-9.9999999999999995e-8)) - 500000.00000000006 * (-9.9999999999999995e-7 + membrane__V) * (-7.9999999999999988e-9 / (1.0 - exp(9.9999999999999995e-8)) - 7.9999999999999988e-9 / (1.0 - exp(-9.9999999999999995e-8)))) : (0.0080000000000000002 * membrane__V / (1.0 - exp(-0.10000000000000001 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/mcallister_noble_tsien_1975_b/5_0.png)

# of singularities:  5
# Model: noble_model_1962(noble_model_1962.cellml)
No of piecewises: 0
## Equation 1:
```
potassium_channel_n_gate__alpha_n = 0.0001 * (-50.0 - membrane__V) / (-1.0 + exp(-5.0 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
potassium_channel_n_gate__alpha_n = ((fabs(50.0 + membrane__V) < 1.0000000000287557e-6) ? (-1.0000000000287557e-10 / (-1.0 + exp(-1.0000000000287557e-7)) - 499999.99998562218 * (49.999999000000003 + membrane__V) * (1.0000000000287557e-10 / (-1.0 + exp(1.0000000000287557e-7)) + 1.0000000000287557e-10 / (-1.0 + exp(-1.0000000000287557e-7)))) : (0.0001 * (-50.0 - membrane__V) / (-1.0 + exp(-5.0 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_1962/1_0.png)

## Equation 2:
```
sodium_channel_m_gate__alpha_m = 0.10000000000000001 * (-48.0 - membrane__V) / (-1.0 + exp(-3.2000000000000002 - 0.066666666666666666 * membrane__V))
```
## New Eq:
```
sodium_channel_m_gate__alpha_m = ((fabs(48.0 + membrane__V) < 1.5000000000153779e-6) ? (-1.4999999999876224e-7 / (-1.0 + exp(-9.9999999999174827e-8)) - 333333.333329916 * (47.999998499999997 + membrane__V) * (1.5000000000431335e-7 / (-1.0 + exp(1.0000000000287557e-7)) + 1.4999999999876224e-7 / (-1.0 + exp(-9.9999999999174827e-8)))) : (0.10000000000000001 * (-48.0 - membrane__V) / (-1.0 + exp(-3.2000000000000002 - 0.066666666666666666 * membrane__V))))
```
## Singularity point: -48.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_1962/2_0.png)

## Equation 3:
```
sodium_channel_m_gate__beta_m = 0.12 * (8.0 + membrane__V) / (-1.0 + exp(1.6000000000000001 + 0.20000000000000001 * membrane__V))
```
## New Eq:
```
sodium_channel_m_gate__beta_m = ((fabs(8.0 + membrane__V) < 4.999999999970306e-7) ? (-6.0000000000060002e-8 / (-1.0 + exp(-1.0000000000010001e-7)) + 1000000.0000059388 * (8.0000005000000005 + membrane__V) * (6.0000000000060002e-8 / (-1.0 + exp(-1.0000000000010001e-7)) + 5.9999999999227342e-8 / (-1.0 + exp(9.9999999998712227e-8)))) : (0.12 * (8.0 + membrane__V) / (-1.0 + exp(1.6000000000000001 + 0.20000000000000001 * membrane__V))))
```
## Singularity point: -8.0000000000000000
![Singularity](diagrams/manual_fixes/noble_model_1962/3_0.png)

# of singularities:  3
# Model: noble_model_1991(noble_model_1991.cellml)
No of piecewises: 4
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999997780743e-8)) - 1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) + 1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_1991/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K = (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-1.999999999997175e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 1.999999999997175e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 1.999999999997175e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (7.4867781645490941e-5 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_1991/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_Na = (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_1991/3_0.png)

# of singularities:  3
# Model: noble_model_1998(noble_model_1998.cellml)
No of piecewises: 5
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999997780743e-8)) - 1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) + 1.9999999999556149e-7 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_1998/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K_ds = (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K_ds = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-1.999999999997175e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 1.999999999997175e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 1.999999999997175e-10 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (7.4867781645490941e-5 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_1998/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_Na_ds = (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na_ds = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_1998/3_0.png)

# of singularities:  3
# Model: noble_model_2001(noble_model_2001.cellml)
No of piecewises: 5
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca_cyt = 4.0 * (1.0 - L_type_Ca_channel__FrICa) * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChoncyt * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_cyt = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-5.9999999998668459e-8 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(9.9999999997780743e-8)) - 5.9999999998668459e-8 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999997780743e-8))) + 5.9999999998668459e-8 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999997780743e-8))) : (0.044920668987294569 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_2001/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChonds * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-1.3999999999689304e-7 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(9.9999999997780743e-8)) - 1.3999999999689304e-7 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999997780743e-8))) + 1.3999999999689304e-7 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999997780743e-8))) : (0.10481489430368732 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_2001/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_K_cyt = (1.0 - L_type_Ca_channel__FrICa) * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChoncyt * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K_cyt = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-5.9999999999915252e-11 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(9.9999999999858739e-8)) - 5.9999999999915252e-11 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) + 5.9999999999915252e-11 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) : (2.2460334493647287e-5 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_2001/3_0.png)

## Equation 4:
```
L_type_Ca_channel__i_Ca_L_K_ds = (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChonds * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K_ds = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-1.3999999999980223e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(9.9999999999858739e-8)) - 1.3999999999980223e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) + 1.3999999999980223e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) : (5.2407447151843657e-5 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_2001/4_0.png)

## Equation 5:
```
L_type_Ca_channel__i_Ca_L_Na_cyt = (1.0 - L_type_Ca_channel__FrICa) * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChoncyt * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na_cyt = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-2.9999999999957627e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(9.9999999999858739e-8)) - 2.9999999999957627e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) + 2.9999999999957627e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) : (0.00011230167246823643 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_i / (0.01 + intracellular_calcium_concentration__Ca_i)) * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_2001/5_0.png)

## Equation 6:
```
L_type_Ca_channel__i_Ca_L_Na_ds = (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f_gate__CaChonds * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na_ds = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-6.9999999999901117e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(9.9999999999858739e-8)) - 6.9999999999901117e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) + 6.9999999999901117e-10 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(-9.9999999999858739e-8))) : (0.00026203723575921831 * (1.0 - L_type_Ca_channel_f_gate__f) * (1.0 - intracellular_calcium_concentration__Ca_ds / (0.001 + intracellular_calcium_concentration__Ca_ds)) * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_model_2001/6_0.png)

# of singularities:  6
# Model: NN_SAN_model_1984(noble_noble_SAN_model_1984.cellml)
No of piecewises: 7
## Equation 1:
```
intracellular_calcium_concentration__alpha_p = 0.625 * intracellular_calcium_concentration__E0_p / (-1.0 + exp(0.25 * intracellular_calcium_concentration__E0_p))
```
## New Eq:
```
intracellular_calcium_concentration__alpha_p = ((fabs(64.0 + membrane__V) < 4.0000000001150227e-7) ? (-2.5000000000718892e-7 / (-1.0 + exp(-1.0000000000287557e-7)) + 1249999.9999640554 * (64.000000400000005 + membrane__V) * (2.5000000000718892e-7 / (-1.0 + exp(1.0000000000287557e-7)) + 2.5000000000718892e-7 / (-1.0 + exp(-1.0000000000287557e-7)))) : (0.625 * (64.0 + membrane__V) / (-1.0 + exp(16.0 + 0.25 * membrane__V))))
```
## Singularity point: -64.000000000000000
![Singularity](diagrams/manual_fixes/noble_noble_SAN_model_1984/1_0.png)

## Equation 2:
```
second_inward_current__i_siCa = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(100.0 / membrane__RTONF) - extracellular_calcium_concentration__Cao * exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siCa = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-1.9999999999556149e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(9.9999999997780743e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(9.9999999997780743e-8)) - 1.9999999999556149e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(-9.9999999997780743e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) + 1.9999999999556149e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(-9.9999999997780743e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_noble_SAN_model_1984/2_0.png)

## Equation 3:
```
second_inward_current__i_siK = 0.01 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(50.0 / membrane__RTONF) - extracellular_potassium_concentration__Kc * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siK = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_noble_SAN_model_1984/3_0.png)

## Equation 4:
```
second_inward_current__i_siNa = 0.01 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(50.0 / membrane__RTONF) - extracellular_sodium_concentration__Nao * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siNa = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_noble_SAN_model_1984/4_0.png)

# of singularities:  4
# Model: Noble_SAN_model_1989(noble_SAN_model_1989.cellml)
No of piecewises: 4
## Equation 1:
```
intracellular_calcium_concentration__alpha_p = 0.625 * intracellular_calcium_concentration__E0_p / (-1.0 + exp(0.25 * intracellular_calcium_concentration__E0_p))
```
## New Eq:
```
intracellular_calcium_concentration__alpha_p = ((fabs(64.0 + membrane__V) < 4.0000000001150227e-7) ? (-2.5000000000718892e-7 / (-1.0 + exp(-1.0000000000287557e-7)) + 1249999.9999640554 * (64.000000400000005 + membrane__V) * (2.5000000000718892e-7 / (-1.0 + exp(1.0000000000287557e-7)) + 2.5000000000718892e-7 / (-1.0 + exp(-1.0000000000287557e-7)))) : (0.625 * (64.0 + membrane__V) / (-1.0 + exp(16.0 + 0.25 * membrane__V))))
```
## Singularity point: -64.000000000000000
![Singularity](diagrams/manual_fixes/noble_SAN_model_1989/1_0.png)

## Equation 2:
```
second_inward_current__i_siCa = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(100.0 / membrane__RTONF) - extracellular_calcium_concentration__Cao * exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-2.0 * (-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siCa = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-1.9999999999556149e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(9.9999999997780743e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(9.9999999997780743e-8)) - 1.9999999999556149e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(-9.9999999997780743e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) + 1.9999999999556149e-7 * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(-9.9999999997780743e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) : (0.14973556329098189 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Cai * exp(3.7433890822745473) - extracellular_calcium_concentration__Cao * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_SAN_model_1989/2_0.png)

## Equation 3:
```
second_inward_current__i_siK = 0.01 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(50.0 / membrane__RTONF) - extracellular_potassium_concentration__Kc * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siK = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_SAN_model_1989/3_0.png)

## Equation 4:
```
second_inward_current__i_siNa = 0.01 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(50.0 / membrane__RTONF) - extracellular_sodium_concentration__Nao * exp(-(-50.0 + membrane__V) / membrane__RTONF)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / ((1.0 - exp(-(-50.0 + membrane__V) / membrane__RTONF)) * membrane__RTONF)
```
## New Eq:
```
second_inward_current__i_siNa = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-9.9999999999858744e-10 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 9.9999999999858744e-10 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 9.9999999999858744e-10 * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(-9.9999999999858739e-8)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (0.00037433890822745472 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Nai * exp(1.8716945411372736) - extracellular_sodium_concentration__Nao * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * second_inward_current__P_si * second_inward_current_d_gate__d * second_inward_current_f2_gate__f2 * second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/noble_SAN_model_1989/4_0.png)

# of singularities:  4
# Model: nygren_atrial_model_1998(nygren_atrial_model_1998.cellml)
No of piecewises: 0
## Equation 1:
```
sodium_current__i_Na = pow(membrane__F, 2) * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp((-sodium_current__E_Na + membrane__V) * membrane__F / (membrane__R * membrane__T))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
sodium_current__i_Na = ((fabs(membrane__V) < 2.6380041870925613e-6) ? (189537.22759290531 * (2.6380041870925613e-6 + membrane__V) * (0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(9.9999999999999995e-8)) + 0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-9.9999999999999995e-8))) - 0.0096486999999999996 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(-9.9999999999999995e-8 - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * sodium_current__P_Na / (-1.0 + exp(-9.9999999999999995e-8))) : (3657.5756957513308 * pow(sodium_current_m_gate__m, 3) * (-1.0 + exp(0.037907445518581065 * membrane__V - log(cleft_space_ion_concentrations__Na_c / intracellular_ion_concentrations__Na_i))) * (0.10000000000000001 * sodium_current_h2_gate__h2 + 0.90000000000000002 * sodium_current_h1_gate__h1) * cleft_space_ion_concentrations__Na_c * membrane__V * sodium_current__P_Na / (-1.0 + exp(0.037907445518581065 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/nygren_atrial_model_1998/1_0.png)

# of singularities:  1
# Model: ohara_rudy_2011_endo(ohara_rudy_2011_endo.cellml)
No of piecewises: 16
## Equation 1:
```
ICaL__PhiCaK = (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ohara_rudy_2011_endo/1_0.png)

## Equation 2:
```
ICaL__PhiCaL = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ohara_rudy_2011_endo/2_0.png)

## Equation 3:
```
ICaL__PhiCaNa = (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ohara_rudy_2011_endo/3_0.png)

## Equation 4:
```
ICab__ICab = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(-9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(-9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * ICab__PCab * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ohara_rudy_2011_endo/4_0.png)

## Equation 5:
```
INab__INab = (-extracellular__nao + intracellular_ions__nai * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (3.75e-10 * pow(physical_constants__F, 2) * (-extracellular__nao + intracellular_ions__nai * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ohara_rudy_2011_endo/5_0.png)

# of singularities:  5
# Model: ohara_rudy_2011_epi(ohara_rudy_2011_epi.cellml)
No of piecewises: 16
## Equation 1:
```
ICaL__PhiCaK = (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ohara_rudy_2011_epi/1_0.png)

## Equation 2:
```
ICaL__PhiCaL = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ohara_rudy_2011_epi/2_0.png)

## Equation 3:
```
ICaL__PhiCaNa = (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ohara_rudy_2011_epi/3_0.png)

## Equation 4:
```
ICab__ICab = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(-9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(-9.9999999999999995e-8)) * ICab__PCab * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cai * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * ICab__PCab * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ohara_rudy_2011_epi/4_0.png)

## Equation 5:
```
INab__INab = (-extracellular__nao + intracellular_ions__nai * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 3.7499999999999999e-17 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (3.75e-10 * pow(physical_constants__F, 2) * (-extracellular__nao + intracellular_ions__nai * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ohara_rudy_2011_epi/5_0.png)

# of singularities:  5
# Model: ohara_rudy_cipa_v1_2017(ohara_rudy_cipa_v1_2017.cellml)
No of piecewises: 21
# of singularities:  0
# Model: paci_hyttinen_aaltosetala_severi_atrialVersion(paci_hyttinen_aaltosetala_severi_atrialVersion.cellml)
No of piecewises: 9
## Equation 1:
```
i_CaL__i_CaL = 4.0 * pow(model_parameters__F, 2) * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(2.0 * Membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * Membrane__Vm * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / ((-1.0 + exp(2.0 * Membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_CaL__i_CaL = ((fabs(Membrane__Vm_converted) < 4.30867107414446e-9 * fabs(model_parameters__T)) ? (116045061.55051096 * (4.30867107414446e-9 * model_parameters__T + Membrane__Vm_converted) * (0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(9.9999999999999995e-8)) + 0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(-9.9999999999999995e-8))) / model_parameters__T - 0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(-9.9999999999999995e-8))) : (4478658.9572358271 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(23.209012310102192 * Membrane__Vm_converted / model_parameters__T)) * Membrane__Vm_converted * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / ((-1.0 + exp(23.209012310102192 * Membrane__Vm_converted / model_parameters__T)) * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/paci_hyttinen_aaltosetala_severi_atrialVersion/1_0.png)

# of singularities:  1
# Model: paci_hyttinen_aaltosetala_severi_ventricularVersion(paci_hyttinen_aaltosetala_severi_ventricularVersion.cellml)
No of piecewises: 13
## Equation 1:
```
i_CaL__i_CaL = 4.0 * pow(model_parameters__F, 2) * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(2.0 * Membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * Membrane__Vm * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / ((-1.0 + exp(2.0 * Membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_CaL__i_CaL = ((fabs(Membrane__Vm_converted) < 4.30867107414446e-9 * fabs(model_parameters__T)) ? (116045061.55051096 * (4.30867107414446e-9 * model_parameters__T + Membrane__Vm_converted) * (0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(9.9999999999999995e-8)) + 0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(-9.9999999999999995e-8))) / model_parameters__T - 0.019297068299999998 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / (-1.0 + exp(-9.9999999999999995e-8))) : (4478658.9572358271 * (-0.34100000000000003 * model_parameters__Cao + calcium_dynamics__Cai * exp(23.209012310102192 * Membrane__Vm_converted / model_parameters__T)) * Membrane__Vm_converted * i_CaL__g_CaL * i_CaL_d_gate__d * i_CaL_f1_gate__f1 * i_CaL_f2_gate__f2 * i_CaL_fCa_gate__fCa / ((-1.0 + exp(23.209012310102192 * Membrane__Vm_converted / model_parameters__T)) * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/paci_hyttinen_aaltosetala_severi_ventricularVersion/1_0.png)

# of singularities:  1
# Model: pandit_clark_giles_demir_2001_version06_variant01(pandit_clark_giles_demir_2001_endocardial_cell.cellml)
No of piecewises: 2
## Equation 1:
```
sodium_current_m_gate__tau_m = 0.0013600000000000001 / (0.080000000000000002 * exp(-0.090909090909090912 * membrane__V) + 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V)))
```
## New Eq:
```
sodium_current_m_gate__tau_m = 0.0013600000000000001 / (0.080000000000000002 * exp(-0.090909090909090912 * membrane__V) + ((fabs(47.130000000000003 + membrane__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + membrane__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V)))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/pandit_clark_giles_demir_2001_endocardial_cell/1_0.png)

# of singularities:  1
# Model: pandit_clark_giles_demir_2001(pandit_clark_giles_demir_2001_epicardial_cell.cellml)
No of piecewises: 2
## Equation 1:
```
sodium_current_m_gate__tau_m = 0.0013600000000000001 / (0.080000000000000002 * exp(-0.090909090909090912 * membrane__V) + 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V)))
```
## New Eq:
```
sodium_current_m_gate__tau_m = 0.0013600000000000001 / (0.080000000000000002 * exp(-0.090909090909090912 * membrane__V) + ((fabs(47.130000000000003 + membrane__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + membrane__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V)))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/pandit_clark_giles_demir_2001_epicardial_cell/1_0.png)

# of singularities:  1
# Model: pasek_simurda_christe_2006(pasek_simurda_christe_2006.cellml)
No of piecewises: 0
## Equation 1:
```
i_Nas_h_gate__beta_h = 18.77 * (64.400000000000006 + Vms__Vms) / (1.0 - exp(-14.168000000000001 - 0.22 * Vms__Vms))
```
## New Eq:
```
i_Nas_h_gate__beta_h = ((fabs(64.400000000000006 + Vms__Vms) < 4.5454545455347883e-7) ? (8.5318181809268536e-6 / (1.0 - exp(-9.999999998955289e-8)) - 1099999.9999805812 * (64.399999545454548 + Vms__Vms) * (-8.5318181809268536e-6 / (1.0 - exp(-9.999999998955289e-8)) - 8.531818183010741e-6 / (1.0 - exp(1.000000000139778e-7)))) : (18.77 * (64.400000000000006 + Vms__Vms) / (1.0 - exp(-14.168000000000001 - 0.22 * Vms__Vms))))
```
## Singularity point: -64.400000000000006
![Singularity](diagrams/manual_fixes/pasek_simurda_christe_2006/1_0.png)

## Equation 2:
```
i_Nas_m_gate__alpha_m = 117.26000000000001 * (59.299999999999997 + Vms__Vms) / (1.0 - exp(-32.615000000000002 - 0.55000000000000004 * Vms__Vms))
```
## New Eq:
```
i_Nas_m_gate__alpha_m = ((fabs(59.299999999999997 + Vms__Vms) < 1.8181818181584042e-7) ? (2.1320000002980068e-5 / (1.0 - exp(-1.000000000139778e-7)) - 2750000.0000354135 * (59.299999818181817 + Vms__Vms) * (-2.131999999647083e-5 / (1.0 - exp(9.9999999983446669e-8)) - 2.1320000002980068e-5 / (1.0 - exp(-1.000000000139778e-7)))) : (117.26000000000001 * (59.299999999999997 + Vms__Vms) / (1.0 - exp(-32.615000000000002 - 0.55000000000000004 * Vms__Vms))))
```
## Singularity point: -59.299999999999997
![Singularity](diagrams/manual_fixes/pasek_simurda_christe_2006/2_0.png)

## Equation 3:
```
i_Cas__i_Cas = 4.0 * pow(model_parameters__F, 2) * (-0.34100000000000003 * model_parameters__Cae + ion_concentrations__Cass * exp(2.0 * Vms__Vms * model_parameters__F / (model_parameters__R * model_parameters__T))) * ((0.10000000000000001 - 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C2 + (0.90000000000000002 + 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C1) * Vms__Vms * i_Cas__Co * membrane_permeabilities__gCas / ((-1.0 + exp(2.0 * Vms__Vms * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_Cas__i_Cas = ((fabs(Vms__Vms) < 1.2701813471502589e-6) ? (393644.57769891288 * (1.2701813471502589e-6 + Vms__Vms) * (5.2689000000000005e-11 * (-0.40920000000000001 + ion_concentrations__Cass * exp(9.9999999999999995e-8)) * ((0.10000000000000001 - 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C2 + (0.90000000000000002 + 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C1) * i_Cas__Co / (-1.0 + exp(9.9999999999999995e-8)) + 5.2689000000000005e-11 * (-0.40920000000000001 + ion_concentrations__Cass * exp(-9.9999999999999995e-8)) * ((0.10000000000000001 - 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C2 + (0.90000000000000002 + 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C1) * i_Cas__Co / (-1.0 + exp(-9.9999999999999995e-8))) - 5.2689000000000005e-11 * (-0.40920000000000001 + ion_concentrations__Cass * exp(-9.9999999999999995e-8)) * ((0.10000000000000001 - 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C2 + (0.90000000000000002 + 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C1) * i_Cas__Co / (-1.0 + exp(-9.9999999999999995e-8))) : (4.1481478308756044e-5 * (-0.40920000000000001 + ion_concentrations__Cass * exp(0.078728915539782576 * Vms__Vms)) * ((0.10000000000000001 - 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C2 + (0.90000000000000002 + 0.10000000000000001 * i_Cas__Ccast) * i_Cas__C1) * Vms__Vms * i_Cas__Co / (-1.0 + exp(0.078728915539782576 * Vms__Vms))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/pasek_simurda_christe_2006/3_0.png)

# of singularities:  3
# Model: pasek_model_2008(pasek_simurda_orchard_christe_2008.cellml)
No of piecewises: 0
## Equation 1:
```
i_Kr_s_xr_gate__tau_xr = 0.001 / (0.00060999999999999997 * (38.899999999999999 + Vm_s__Vm_s) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * Vm_s__Vm_s)) + 0.0013799999999999999 * (14.199999999999999 + Vm_s__Vm_s) / (1.0 - exp(-1.7465999999999999 - 0.123 * Vm_s__Vm_s)))
```
## New Eq:
```
i_Kr_s_xr_gate__tau_xr = 0.001 / (((fabs(14.199999999999999 + Vm_s__Vm_s) < 8.1300813007528783e-7) ? (1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)) - 615000.00000454858 * (14.199999186991869 + Vm_s__Vm_s) * (-1.1219512194943214e-9 / (1.0 - exp(9.9999999998406912e-8)) - 1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)))) : (0.0013799999999999999 * (14.199999999999999 + Vm_s__Vm_s) / (1.0 - exp(-1.7465999999999999 - 0.123 * Vm_s__Vm_s)))) + ((fabs(38.899999999999999 + Vm_s__Vm_s) < 6.896551724422384e-7) ? (-4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 724999.99997009686 * (38.900000689655172 + Vm_s__Vm_s) * (4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 4.2068965520669629e-10 / (-1.0 + exp(1.0000000000814911e-7)))) : (0.00060999999999999997 * (38.899999999999999 + Vm_s__Vm_s) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * Vm_s__Vm_s)))))
```
## Singularity point: -38.899999999999999
![Singularity](diagrams/manual_fixes/pasek_simurda_orchard_christe_2008/1_0.png)
## Singularity point: -14.199999999999999
![Singularity](diagrams/manual_fixes/pasek_simurda_orchard_christe_2008/1_1.png)

## Equation 2:
```
i_Ks_s_xs_gate__tau_xs = 0.001 / (0.00013100000000000001 * (30.0 + Vm_s__Vm_s) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * Vm_s__Vm_s)) + 7.1899999999999999e-5 * (30.0 + Vm_s__Vm_s) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * Vm_s__Vm_s)))
```
## New Eq:
```
i_Ks_s_xs_gate__tau_xs = 0.001 * ((fabs(30.0 + Vm_s__Vm_s) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + Vm_s__Vm_s) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (30.0 + Vm_s__Vm_s) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * Vm_s__Vm_s)) + 7.1899999999999999e-5 * (30.0 + Vm_s__Vm_s) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * Vm_s__Vm_s)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/pasek_simurda_orchard_christe_2008/2_0.png)

## Equation 3:
```
i_CaL_s__i_CaL_s = 4.0 * pow(model_parameters__F, 2) * (0.001 * exp(2.0 * Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T)) - 0.34100000000000003 * model_parameters__Ca_e) * (i_CaL_s__Ccao + i_CaL_s__Co) * Vm_s__Vm_s * i_CaL_s_y_gate__y * membrane_permeabilities__P_CaL_s / ((-1.0 + exp(2.0 * Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_CaL_s__i_CaL_s = ((fabs(Vm_s__Vm_s) < 1.3347668393782383e-6) ? (374597.25942315906 * (1.3347668393782383e-6 + Vm_s__Vm_s) * (7.425432175987399e-7 * (-0.61380000000000001 + 0.001 * exp(9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(9.9999999999999995e-8)) + 7.425432175987399e-7 * (-0.61380000000000001 + 0.001 * exp(-9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(-9.9999999999999995e-8))) - 7.425432175987399e-7 * (-0.61380000000000001 + 0.001 * exp(-9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(-9.9999999999999995e-8))) : (0.55630930863148487 * (-0.61380000000000001 + 0.001 * exp(0.07491945188463181 * Vm_s__Vm_s)) * (i_CaL_s__Ccao + i_CaL_s__Co) * Vm_s__Vm_s * i_CaL_s_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(0.07491945188463181 * Vm_s__Vm_s))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/pasek_simurda_orchard_christe_2008/3_0.png)

## Equation 4:
```
i_CaL_s__i_KL_s = pow(model_parameters__F, 2) * (-model_parameters__K_e + ion_concentrations__K_i * exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * (i_CaL_s__Ccao + i_CaL_s__Co) * Vm_s__Vm_s * i_CaL_s_y_gate__y * membrane_permeabilities__P_KL_s / ((1.0 - 2.1834061135371177 * (i_CaL_s__i_CaL_s + i_CaL_t__i_CaL_t) / (model_parameters__Sms + model_parameters__Smt)) * (-1.0 + exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_CaL_s__i_KL_s = ((fabs(Vm_s__Vm_s) < 2.6695336787564767e-6) ? (187298.62971157953 * (2.6695336787564767e-6 + Vm_s__Vm_s) * (1.7821037222369756e-12 * (-5.4000000000000004 + ion_concentrations__K_i * exp(9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y / ((-1.0 + exp(9.9999999999999995e-8)) * (1.0 - 20430.198966619231 * i_CaL_s__i_CaL_s - 20205.350866353103 * (0.001 * exp(0.07491945188463181 * Vm_t__Vm_t) - 0.34100000000000003 * ion_concentrations__Ca_t) * (i_CaL_t__TCcao + i_CaL_t__TCo) * Vm_t__Vm_t * i_CaL_t_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(0.07491945188463181 * Vm_t__Vm_t)))) + 1.7821037222369756e-12 * (-5.4000000000000004 + ion_concentrations__K_i * exp(-9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y / ((-1.0 + exp(-9.9999999999999995e-8)) * (1.0 - 20430.198966619231 * i_CaL_s__i_CaL_s - 20205.350866353103 * (0.001 * exp(0.07491945188463181 * Vm_t__Vm_t) - 0.34100000000000003 * ion_concentrations__Ca_t) * (i_CaL_t__TCcao + i_CaL_t__TCo) * Vm_t__Vm_t * i_CaL_t_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(0.07491945188463181 * Vm_t__Vm_t))))) - 1.7821037222369756e-12 * (-5.4000000000000004 + ion_concentrations__K_i * exp(-9.9999999999999995e-8)) * (i_CaL_s__Ccao + i_CaL_s__Co) * i_CaL_s_y_gate__y / ((-1.0 + exp(-9.9999999999999995e-8)) * (1.0 - 20430.198966619231 * i_CaL_s__i_CaL_s - 20205.350866353103 * (0.001 * exp(0.07491945188463181 * Vm_t__Vm_t) - 0.34100000000000003 * ion_concentrations__Ca_t) * (i_CaL_t__TCcao + i_CaL_t__TCo) * Vm_t__Vm_t * i_CaL_t_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(0.07491945188463181 * Vm_t__Vm_t))))) : (6.6757117035778174e-7 * (-5.4000000000000004 + ion_concentrations__K_i * exp(0.037459725942315905 * Vm_s__Vm_s)) * (i_CaL_s__Ccao + i_CaL_s__Co) * Vm_s__Vm_s * i_CaL_s_y_gate__y / ((-1.0 + exp(0.037459725942315905 * Vm_s__Vm_s)) * (1.0 - 20430.198966619231 * i_CaL_s__i_CaL_s - 20205.350866353103 * (0.001 * exp(0.07491945188463181 * Vm_t__Vm_t) - 0.34100000000000003 * ion_concentrations__Ca_t) * (i_CaL_t__TCcao + i_CaL_t__TCo) * Vm_t__Vm_t * i_CaL_t_y_gate__y * membrane_permeabilities__P_CaL / (-1.0 + exp(0.07491945188463181 * Vm_t__Vm_t))))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/pasek_simurda_orchard_christe_2008/4_0.png)
## Singularity point: 0
![Singularity](diagrams/manual_fixes/pasek_simurda_orchard_christe_2008/4_1.png)

## Equation 5:
```
i_nsK_s__i_nsK_s = pow(model_parameters__F, 2) * (-0.75 * model_parameters__K_e + 0.75 * ion_concentrations__K_i * exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * Vm_s__Vm_s * membrane_permeabilities__P_nsK_s / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_nsK_s__i_nsK_s = ((fabs(Vm_s__Vm_s) < 2.6695336787564767e-6) ? (187298.62971157953 * (2.6695336787564767e-6 + Vm_s__Vm_s) * (8.554716652752149e-14 * (-4.0500000000000007 + 0.75 * ion_concentrations__K_i * exp(9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(9.9999999999999995e-8))) + 8.554716652752149e-14 * (-4.0500000000000007 + 0.75 * ion_concentrations__K_i * exp(-9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(-9.9999999999999995e-8)))) - 8.554716652752149e-14 * (-4.0500000000000007 + 0.75 * ion_concentrations__K_i * exp(-9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(-9.9999999999999995e-8)))) : (3.2045734132626158e-8 * (-4.0500000000000007 + 0.75 * ion_concentrations__K_i * exp(0.037459725942315905 * Vm_s__Vm_s)) * Vm_s__Vm_s / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(0.037459725942315905 * Vm_s__Vm_s)))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/pasek_simurda_orchard_christe_2008/5_0.png)

## Equation 6:
```
i_nsNa_s__i_nsNa_s = pow(model_parameters__F, 2) * (-0.75 * model_parameters__Na_e + 0.75 * ion_concentrations__Na_i * exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * Vm_s__Vm_s * membrane_permeabilities__P_nsNa_s / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(Vm_s__Vm_s * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
i_nsNa_s__i_nsNa_s = ((fabs(Vm_s__Vm_s) < 2.6695336787564767e-6) ? (187298.62971157953 * (2.6695336787564767e-6 + Vm_s__Vm_s) * (8.554716652752149e-14 * (-105.0 + 0.75 * ion_concentrations__Na_i * exp(9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(9.9999999999999995e-8))) + 8.554716652752149e-14 * (-105.0 + 0.75 * ion_concentrations__Na_i * exp(-9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(-9.9999999999999995e-8)))) - 8.554716652752149e-14 * (-105.0 + 0.75 * ion_concentrations__Na_i * exp(-9.9999999999999995e-8)) / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(-9.9999999999999995e-8)))) : (3.2045734132626158e-8 * (-105.0 + 0.75 * ion_concentrations__Na_i * exp(0.037459725942315905 * Vm_s__Vm_s)) * Vm_s__Vm_s / ((1.0 + 1.5625000000000003e-8 / pow(ion_concentrations__Ca_i, 3)) * (-1.0 + exp(0.037459725942315905 * Vm_s__Vm_s)))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/pasek_simurda_orchard_christe_2008/6_0.png)

# of singularities:  7
# Model: priebe_beuckelmann_1998(priebe_beuckelmann_1998.cellml)
No of piecewises: 21
# of singularities:  0
# Model: ramirez_2000(ramirez_nattel_courtemanche_2000.cellml)
No of piecewises: 4
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + membrane__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/ramirez_nattel_courtemanche_2000/1_0.png)

## Equation 2:
```
rapid_delayed_rectifier_K_current_xr_gate__alpha_xr = 0.040000000000000001 * (-248.0 + membrane__V) / (1.0 - exp(8.8571428571428577 - 0.035714285714285712 * membrane__V))
```
## New Eq:
```
rapid_delayed_rectifier_K_current_xr_gate__alpha_xr = ((fabs(-248.0 + membrane__V) < 2.8000000000805159e-6) ? (1.1200000000322064e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 178571.42856629365 * (-248.0000028 + membrane__V) * (-1.1200000000322064e-7 / (1.0 - exp(1.0000000000287557e-7)) - 1.1200000000322064e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.040000000000000001 * (-248.0 + membrane__V) / (1.0 - exp(8.8571428571428577 - 0.035714285714285712 * membrane__V))))
```
## Singularity point: 248.00000000000000
![Singularity](diagrams/manual_fixes/ramirez_nattel_courtemanche_2000/2_0.png)

## Equation 3:
```
rapid_delayed_rectifier_K_current_xr_gate__beta_xr = 0.028000000000000001 * (163.0 + membrane__V) / (-1.0 + exp(7.7619047619047619 + 0.047619047619047616 * membrane__V))
```
## New Eq:
```
rapid_delayed_rectifier_K_current_xr_gate__beta_xr = ((fabs(163.0 + membrane__V) < 2.1000000000048757e-6) ? (-5.8799999997027897e-8 / (-1.0 + exp(-9.9999999994945406e-8)) + 238095.23809468528 * (163.00000209999999 + membrane__V) * (5.8799999997027897e-8 / (-1.0 + exp(-9.9999999994945406e-8)) + 5.8800000003245146e-8 / (-1.0 + exp(1.0000000000551896e-7)))) : (0.028000000000000001 * (163.0 + membrane__V) / (-1.0 + exp(7.7619047619047619 + 0.047619047619047616 * membrane__V))))
```
## Singularity point: -163.00000000000000
![Singularity](diagrams/manual_fixes/ramirez_nattel_courtemanche_2000/3_0.png)

## Equation 4:
```
sarcolemmal_Ca_current_d_gate__tau_d = 28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * (10.0 + membrane__V))
```
## New Eq:
```
sarcolemmal_Ca_current_d_gate__tau_d = ((fabs(10.0 + membrane__V) < 6.2399999999074307e-7) ? (45787545.788225032 * (1.0 - exp(-9.999999999851651e-8)) / (1.0 + exp(-9.999999999851651e-8)) - 801282.05129393819 * (9.9999993759999999 + membrane__V) * (-45787545.788225032 * (1.0 - exp(9.999999999851651e-8)) / (1.0 + exp(9.999999999851651e-8)) - 45787545.788225032 * (1.0 - exp(-9.999999999851651e-8)) / (1.0 + exp(-9.999999999851651e-8)))) : (28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) / ((1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * membrane__V)) * (10.0 + membrane__V))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/manual_fixes/ramirez_nattel_courtemanche_2000/4_0.png)

## Equation 5:
```
slow_delayed_rectifier_K_current_xs_gate__alpha_xs = 1.0000000000000001e-5 * (28.5 + membrane__V) / (1.0 - exp(-0.24782608695652175 - 0.0086956521739130436 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_K_current_xs_gate__alpha_xs = ((fabs(28.5 + membrane__V) < 1.1500000000011501e-5) ? (1.1499999999997625e-10 / (1.0 - exp(-9.9999999999979336e-8)) - 43478.260869521735 * (28.499988500000001 + membrane__V) * (-1.1500000000025379e-10 / (1.0 - exp(1.0000000000022069e-7)) - 1.1499999999997625e-10 / (1.0 - exp(-9.9999999999979336e-8)))) : (1.0000000000000001e-5 * (28.5 + membrane__V) / (1.0 - exp(-0.24782608695652175 - 0.0086956521739130436 * membrane__V))))
```
## Singularity point: -28.500000000000000
![Singularity](diagrams/manual_fixes/ramirez_nattel_courtemanche_2000/5_0.png)

## Equation 6:
```
slow_delayed_rectifier_K_current_xs_gate__beta_xs = 0.00023000000000000001 * (28.5 + membrane__V) / (-1.0 + exp(8.6363636363636367 + 0.30303030303030304 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_K_current_xs_gate__beta_xs = ((fabs(28.5 + membrane__V) < 3.300000000205916e-7) ? (-7.5900000004736066e-11 / (-1.0 + exp(-1.0000000000623989e-7)) + 1515151.5150569715 * (28.500000329999999 + membrane__V) * (7.5900000004736066e-11 / (-1.0 + exp(1.0000000000623989e-7)) + 7.5900000004736066e-11 / (-1.0 + exp(-1.0000000000623989e-7)))) : (0.00023000000000000001 * (28.5 + membrane__V) / (-1.0 + exp(8.6363636363636367 + 0.30303030303030304 * membrane__V))))
```
## Singularity point: -28.500000000000000
![Singularity](diagrams/manual_fixes/ramirez_nattel_courtemanche_2000/6_0.png)

# of singularities:  6
# Model: sachse_model_2007(sachse_moreno_abildskov_2008_b.cellml)
No of piecewises: 0
## Equation 1:
```
I_Shkr__I_Shkr = pow(model_parameters__F, 2) * (-model_parameters__Ko * exp(-membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T)) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr * membrane__Vm / ((1.0 - exp(-membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
## New Eq:
```
I_Shkr__I_Shkr = ((fabs(membrane__Vm) < 8.6113989637305703e-9 * fabs(model_parameters__T)) ? (-58062575.210589655 * (-8.6113989637305703e-9 * model_parameters__T + membrane__Vm) * (-0.0096499999999999989 * (-model_parameters__Ko * exp(9.9999999999999995e-8) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr / (1.0 - exp(9.9999999999999995e-8)) - 0.0096499999999999989 * (-model_parameters__Ko * exp(-9.9999999999999995e-8) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr / (1.0 - exp(-9.9999999999999995e-8))) / model_parameters__T + 0.0096499999999999989 * (-model_parameters__Ko * exp(-9.9999999999999995e-8) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr / (1.0 - exp(-9.9999999999999995e-8))) : (1120607.7015643802 * (-model_parameters__Ko * exp(-11.612515042117931 * membrane__Vm / model_parameters__T) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr * membrane__Vm / ((1.0 - exp(-11.612515042117931 * membrane__Vm / model_parameters__T)) * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/sachse_moreno_abildskov_2008_b/1_0.png)

# of singularities:  1
# Model: sakmann_model_2000_epi(sakmann_model_2000_epi.cellml)
No of piecewises: 5
## Equation 1:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = 4.0 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(100.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_calcium_concentration__Ca_o * exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp(2.0 * (50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Ca_ds = ((fabs(-50.0 + membrane__V) < 1.3356880329551402e-6) ? (-374338.90823576227 * (-50.000001335688033 + membrane__V) * (-2.1999999999511763e-8 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(9.9999999997780743e-8)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999997780743e-8)) - 2.1999999999511763e-8 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) + 2.1999999999511763e-8 * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(-9.9999999997780743e-8)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999997780743e-8))) : (0.016470911962008009 * (-50.0 + membrane__V) * (intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * membrane__V)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/sakmann_model_2000_epi/1_0.png)

## Equation 2:
```
L_type_Ca_channel__i_Ca_L_K_ds = (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_potassium_concentration__K_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaK * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_K_ds = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-2.1999999999968924e-11 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 2.1999999999968924e-11 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 2.1999999999968924e-11 * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (8.2354559810040044e-6 * (-50.0 + membrane__V) * (intracellular_potassium_concentration__K_i * exp(1.8716945411372736) - extracellular_potassium_concentration__K_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/sakmann_model_2000_epi/2_0.png)

## Equation 3:
```
L_type_Ca_channel__i_Ca_L_Na_ds = (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(50.0 * membrane__F / (membrane__R * membrane__T)) - extracellular_sodium_concentration__Na_o * exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_channel__FrICa * L_type_Ca_channel__P_CaNa * L_type_Ca_channel__P_Ca_L * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f * membrane__F / ((1.0 - exp((50.0 - membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__i_Ca_L_Na_ds = ((fabs(-50.0 + membrane__V) < 2.6713760659657915e-6) ? (-187169.45411399176 * (-50.000002671376066 + membrane__V) * (-1.0999999999984461e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(9.9999999999858739e-8)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(9.9999999999858739e-8)) - 1.0999999999984461e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) + 1.0999999999984461e-10 * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(-9.9999999999858739e-8)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(-9.9999999999858739e-8))) : (4.1177279905020022e-5 * (-50.0 + membrane__V) * (intracellular_sodium_concentration__Na_i * exp(1.8716945411372736) - extracellular_sodium_concentration__Na_o * exp(1.8716945411372736 - 0.037433890822745473 * membrane__V)) * L_type_Ca_channel_d_gate__d * L_type_Ca_channel_f2ds_gate__f2ds * L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * membrane__V))))
```
## Singularity point: 50.000000000000000
![Singularity](diagrams/manual_fixes/sakmann_model_2000_epi/3_0.png)

## Equation 4:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 0.001 / (0.00060999999999999997 * (38.899999999999999 + membrane__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * membrane__V)) + 0.0013799999999999999 * (14.199999999999999 + membrane__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * membrane__V)))
```
## New Eq:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 0.001 / (((fabs(14.199999999999999 + membrane__V) < 8.1300813007528783e-7) ? (1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)) - 615000.00000454858 * (14.199999186991869 + membrane__V) * (-1.1219512194943214e-9 / (1.0 - exp(9.9999999998406912e-8)) - 1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)))) : (0.0013799999999999999 * (14.199999999999999 + membrane__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * membrane__V)))) + ((fabs(38.899999999999999 + membrane__V) < 6.896551724422384e-7) ? (-4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 724999.99997009686 * (38.900000689655172 + membrane__V) * (4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 4.2068965520669629e-10 / (-1.0 + exp(1.0000000000814911e-7)))) : (0.00060999999999999997 * (38.899999999999999 + membrane__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * membrane__V)))))
```
## Singularity point: -38.899999999999999
![Singularity](diagrams/manual_fixes/sakmann_model_2000_epi/4_0.png)
## Singularity point: -14.199999999999999
![Singularity](diagrams/manual_fixes/sakmann_model_2000_epi/4_1.png)

## Equation 5:
```
slow_delayed_rectifier_potassium_current_xs_gate__tau_xs = 0.001 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs_gate__tau_xs = 0.001 * ((fabs(30.0 + membrane__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + membrane__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/sakmann_model_2000_epi/5_0.png)

# of singularities:  6
# Model: shannon_wang_puglisi_weber_bers_2004_model_updated(shannon_wang_puglisi_weber_bers_2004.cellml)
No of piecewises: 4
## Equation 1:
```
ICaL_d_gate__tau_d = 28.571428571428569 * (1.0 - exp(-2.4166666666666665 - 0.16666666666666666 * cell__V)) * ICaL_d_gate__d_infinity / (14.5 + cell__V)
```
## New Eq:
```
ICaL_d_gate__tau_d = ((fabs(14.5 + cell__V) < 5.9999999999643672e-7) ? (47619047.619881123 * (1.0 - exp(-9.9999999998249642e-8)) / (1.0 + exp(-9.9999999998249642e-8)) - 833333.3333382823 * (14.4999994 + cell__V) * (-47619047.619881123 * (1.0 - exp(-9.9999999998249642e-8)) / (1.0 + exp(-9.9999999998249642e-8)) - 47619047.618779711 * (1.0 - exp(1.000000000005626e-7)) / (1.0 + exp(1.000000000005626e-7)))) : (28.571428571428569 * (1.0 - exp(-2.4166666666666665 - 0.16666666666666666 * cell__V)) / ((1.0 + exp(-2.4166666666666665 - 0.16666666666666666 * cell__V)) * (14.5 + cell__V))))
```
## Singularity point: -14.500000000000000
![Singularity](diagrams/manual_fixes/shannon_wang_puglisi_weber_bers_2004/1_0.png)

## Equation 2:
```
IKr_Xr_gate__tau_Xr = 1 / (0.00060999999999999997 * (10.0 + cell__V) / (-1.0 + exp(1.45 + 0.14499999999999999 * cell__V)) + 0.0013799999999999999 * (7.0 + cell__V) / (1.0 - exp(-0.86099999999999999 - 0.123 * cell__V)))
```
## New Eq:
```
IKr_Xr_gate__tau_Xr = 1 / (((fabs(7.0 + cell__V) < 8.1300813008222672e-7) ? (1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)) - 614999.99999929965 * (6.9999991869918698 + cell__V) * (-1.1219512195134727e-9 / (1.0 - exp(1.0000000000011388e-7)) - 1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)))) : (0.0013799999999999999 * (7.0 + cell__V) / (1.0 - exp(-0.86099999999999999 - 0.123 * cell__V)))) + ((fabs(10.0 + cell__V) < 6.8965517241448282e-7) ? (-4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 724999.99999927497 * (10.000000689655172 + cell__V) * (4.2068965517283451e-10 / (-1.0 + exp(1.000000000001e-7)) + 4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)))) : (0.00060999999999999997 * (10.0 + cell__V) / (-1.0 + exp(1.45 + 0.14499999999999999 * cell__V)))))
```
## Singularity point: -10.000000000000000
![Singularity](diagrams/manual_fixes/shannon_wang_puglisi_weber_bers_2004/2_0.png)
## Singularity point: -7.0000000000000000
![Singularity](diagrams/manual_fixes/shannon_wang_puglisi_weber_bers_2004/2_1.png)

## Equation 3:
```
IKs_Xs_gate__tau_Xs = 1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))
```
## New Eq:
```
IKs_Xs_gate__tau_Xs = ((fabs(30.0 + cell__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + cell__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (30.0 + cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * cell__V)) + 7.1899999999999999e-5 * (30.0 + cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * cell__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/shannon_wang_puglisi_weber_bers_2004/3_0.png)

## Equation 4:
```
INa_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))
```
## New Eq:
```
INa_m_gate__alpha_m = ((fabs(47.130000000000003 + cell__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + cell__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * cell__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/shannon_wang_puglisi_weber_bers_2004/4_0.png)

## Equation 5:
```
ICaL__i_CaL_Ca_SL = 4.0 * (-ICaL__gamma_Cao * model_parameters__Cao + Ca_buffer__Ca_SL * ICaL__gamma_Cai * exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__Fx_ICaL_SL * ICaL__PCa * ICaL__temp * ICaL_fCa_gate__fCa_SL / (-1.0 + exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T)))
```
## New Eq:
```
ICaL__i_CaL_Ca_SL = ((fabs(cell__V) < 4.9999999999999998e-8 * fabs(model_parameters__R * model_parameters__T / model_parameters__F)) ? (10000000.0 * (4.9999999999999998e-8 * model_parameters__R * model_parameters__T / model_parameters__F + cell__V) * (8.9999999999999995e-9 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_SL * exp(9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8)) + 8.9999999999999995e-9 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_SL * exp(-9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) * model_parameters__F / (model_parameters__R * model_parameters__T) - 8.9999999999999995e-9 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_SL * exp(-9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) : (0.18000000000000002 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * pow(model_parameters__F, 2) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_SL * exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * cell__V / ((-1.0 + exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/shannon_wang_puglisi_weber_bers_2004/5_0.png)

## Equation 6:
```
ICaL__i_CaL_Ca_jct = 4.0 * (-ICaL__gamma_Cao * model_parameters__Cao + Ca_buffer__Ca_jct * ICaL__gamma_Cai * exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__Fx_ICaL_jct * ICaL__PCa * ICaL__temp * ICaL_fCa_gate__fCa_jct / (-1.0 + exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T)))
```
## New Eq:
```
ICaL__i_CaL_Ca_jct = ((fabs(cell__V) < 4.9999999999999998e-8 * fabs(model_parameters__R * model_parameters__T / model_parameters__F)) ? (10000000.0 * (4.9999999999999998e-8 * model_parameters__R * model_parameters__T / model_parameters__F + cell__V) * (8.0999999999999997e-8 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_jct * exp(9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8)) + 8.0999999999999997e-8 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_jct * exp(-9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) * model_parameters__F / (model_parameters__R * model_parameters__T) - 8.0999999999999997e-8 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_jct * exp(-9.9999999999999995e-8)) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) : (1.6200000000000001 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * pow(model_parameters__F, 2) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.34100000000000003 * model_parameters__Cao + 0.34100000000000003 * Ca_buffer__Ca_jct * exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__PCa * ICaL_d_gate__d * ICaL_f_gate__f * cell__V / ((-1.0 + exp(2.0 * cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/shannon_wang_puglisi_weber_bers_2004/6_0.png)

## Equation 7:
```
ICaL__i_CaL_K = (ICaL__Fx_ICaL_SL * ICaL_fCa_gate__fCa_SL + ICaL__Fx_ICaL_jct * ICaL_fCa_gate__fCa_jct) * (-ICaL__gamma_Ko * model_parameters__Ko + ICaL__gamma_Ki * model_parameters__Ki * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__PK * ICaL__temp / (-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T)))
```
## New Eq:
```
ICaL__i_CaL_K = ((fabs(cell__V) < 9.9999999999999995e-8 * fabs(model_parameters__R * model_parameters__T / model_parameters__F)) ? (5000000.0 * (9.9999999999999995e-8 * model_parameters__R * model_parameters__T / model_parameters__F + cell__V) * (1.2150000000000001e-14 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (-0.75 * model_parameters__Ko + 0.75 * model_parameters__Ki * exp(9.9999999999999995e-8)) * (1.0 - 0.10000000000000001 * ICaL_fCa_gate__fCaB_SL - 0.90000000000000002 * ICaL_fCa_gate__fCaB_jct) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.2150000000000001e-14 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (-0.75 * model_parameters__Ko + 0.75 * model_parameters__Ki * exp(-9.9999999999999995e-8)) * (1.0 - 0.10000000000000001 * ICaL_fCa_gate__fCaB_SL - 0.90000000000000002 * ICaL_fCa_gate__fCaB_jct) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) * model_parameters__F / (model_parameters__R * model_parameters__T) - 1.2150000000000001e-14 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (-0.75 * model_parameters__Ko + 0.75 * model_parameters__Ki * exp(-9.9999999999999995e-8)) * (1.0 - 0.10000000000000001 * ICaL_fCa_gate__fCaB_SL - 0.90000000000000002 * ICaL_fCa_gate__fCaB_jct) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) : (1.215e-7 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * pow(model_parameters__F, 2) * (-0.75 * model_parameters__Ko + 0.75 * model_parameters__Ki * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * (1.0 - 0.10000000000000001 * ICaL_fCa_gate__fCaB_SL - 0.90000000000000002 * ICaL_fCa_gate__fCaB_jct) * ICaL_d_gate__d * ICaL_f_gate__f * cell__V / ((-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/shannon_wang_puglisi_weber_bers_2004/7_0.png)

## Equation 8:
```
ICaL__i_CaL_Na_SL = (-ICaL__gamma_Nao * model_parameters__Nao + ICaL__gamma_Nai * Na_buffer__Na_SL * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__Fx_ICaL_SL * ICaL__PNa * ICaL__temp * ICaL_fCa_gate__fCa_SL / (-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T)))
```
## New Eq:
```
ICaL__i_CaL_Na_SL = ((fabs(cell__V) < 9.9999999999999995e-8 * fabs(model_parameters__R * model_parameters__T / model_parameters__F)) ? (5000000.0 * (9.9999999999999995e-8 * model_parameters__R * model_parameters__T / model_parameters__F + cell__V) * (6.75e-17 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_SL * exp(9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8)) + 6.75e-17 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_SL * exp(-9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) * model_parameters__F / (model_parameters__R * model_parameters__T) - 6.75e-17 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_SL * exp(-9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) : (6.7499999999999994e-10 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * pow(model_parameters__F, 2) * (1.0 - ICaL_fCa_gate__fCaB_SL) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_SL * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL_d_gate__d * ICaL_f_gate__f * cell__V / ((-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/shannon_wang_puglisi_weber_bers_2004/8_0.png)

## Equation 9:
```
ICaL__i_CaL_Na_jct = (-ICaL__gamma_Nao * model_parameters__Nao + ICaL__gamma_Nai * Na_buffer__Na_jct * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL__Fx_ICaL_jct * ICaL__PNa * ICaL__temp * ICaL_fCa_gate__fCa_jct / (-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T)))
```
## New Eq:
```
ICaL__i_CaL_Na_jct = ((fabs(cell__V) < 9.9999999999999995e-8 * fabs(model_parameters__R * model_parameters__T / model_parameters__F)) ? (5000000.0 * (9.9999999999999995e-8 * model_parameters__R * model_parameters__T / model_parameters__F + cell__V) * (6.0749999999999991e-16 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_jct * exp(9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(9.9999999999999995e-8)) + 6.0749999999999991e-16 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_jct * exp(-9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) * model_parameters__F / (model_parameters__R * model_parameters__T) - 6.0749999999999991e-16 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_jct * exp(-9.9999999999999995e-8)) * ICaL_d_gate__d * ICaL_f_gate__f * model_parameters__F / (-1.0 + exp(-9.9999999999999995e-8))) : (6.0749999999999998e-9 * pow(1.8, (-31.0 + 0.10000000000000001 * model_parameters__T)) * pow(model_parameters__F, 2) * (1.0 - ICaL_fCa_gate__fCaB_jct) * (-0.75 * model_parameters__Nao + 0.75 * Na_buffer__Na_jct * exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * ICaL_d_gate__d * ICaL_f_gate__f * cell__V / ((-1.0 + exp(cell__V * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/shannon_wang_puglisi_weber_bers_2004/9_0.png)

# of singularities:  10
# Model: stewart_zhang_model_2008(stewart_zhang_model_2008_ss.cellml)
No of piecewises: 4
## Equation 1:
```
L_type_Ca_current__i_CaL = 4.0 * pow(membrane__F, 2) * (-15.0 + membrane__V) * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T))) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_f2_gate__f2 * L_type_Ca_current_fCass_gate__fCass * L_type_Ca_current_f_gate__f / ((-1.0 + exp(2.0 * (-15.0 + membrane__V) * membrane__F / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_CaL = ((fabs(-15.0 + membrane__V) < 1.3356880329828957e-6) ? (374338.90822798351 * (-14.999998664311967 + membrane__V) * (0.019297068299972742 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(9.9999999999858739e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_f2_gate__f2 * L_type_Ca_current_fCass_gate__fCass * L_type_Ca_current_f_gate__f / (-1.0 + exp(9.9999999999858739e-8)) + 0.019297068299972742 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(-9.9999999999858739e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_f2_gate__f2 * L_type_Ca_current_fCass_gate__fCass * L_type_Ca_current_f_gate__f / (-1.0 + exp(-9.9999999999858739e-8))) - 0.019297068299972742 * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(-9.9999999999858739e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_f2_gate__f2 * L_type_Ca_current_fCass_gate__fCass * L_type_Ca_current_f_gate__f / (-1.0 + exp(-9.9999999999858739e-8))) : (14447.286958825251 * (-15.0 + membrane__V) * (-calcium_dynamics__Ca_o + 0.25 * calcium_dynamics__Ca_ss * exp(-1.1230167246823641 + 0.074867781645490947 * membrane__V)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_f2_gate__f2 * L_type_Ca_current_fCass_gate__fCass * L_type_Ca_current_f_gate__f / (-1.0 + exp(-1.1230167246823641 + 0.074867781645490947 * membrane__V))))
```
## Singularity point: 15.000000000000000
![Singularity](diagrams/manual_fixes/stewart_zhang_model_2008_ss/1_0.png)

# of singularities:  1
# Model: tentusscher_model_2004_endo(ten_tusscher_model_2004_endo.cellml)
No of piecewises: 7
## Equation 1:
```
L_type_Ca_current__i_CaL = 4.0 * pow(membrane__F, 2) * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_CaL = ((fabs(membrane__V) < 1.3356880329847825e-6) ? (374338.90822745475 * (1.3356880329847825e-6 + membrane__V) * (0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(9.9999999999999995e-8)) + 0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(-9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(-9.9999999999999995e-8))) - 0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(-9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(-9.9999999999999995e-8))) : (14447.286958825251 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(0.074867781645490947 * membrane__V)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f * membrane__V / (-1.0 + exp(0.074867781645490947 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ten_tusscher_model_2004_endo/1_0.png)

# of singularities:  1
# Model: tentusscher_model_2004_epi(ten_tusscher_model_2004_epi.cellml)
No of piecewises: 8
# of singularities:  0
# Model: tentusscher_model_2004_M(ten_tusscher_model_2004_M.cellml)
No of piecewises: 7
## Equation 1:
```
L_type_Ca_current__i_CaL = 4.0 * pow(membrane__F, 2) * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_CaL = ((fabs(membrane__V) < 1.3356880329847825e-6) ? (374338.90822745475 * (1.3356880329847825e-6 + membrane__V) * (0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(9.9999999999999995e-8)) + 0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(-9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(-9.9999999999999995e-8))) - 0.019297068299999998 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(-9.9999999999999995e-8)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f / (-1.0 + exp(-9.9999999999999995e-8))) : (14447.286958825251 * (-0.34100000000000003 * calcium_dynamics__Ca_o + calcium_dynamics__Ca_i * exp(0.074867781645490947 * membrane__V)) * L_type_Ca_current__g_CaL * L_type_Ca_current_d_gate__d * L_type_Ca_current_fCa_gate__fCa * L_type_Ca_current_f_gate__f * membrane__V / (-1.0 + exp(0.074867781645490947 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ten_tusscher_model_2004_M/1_0.png)

# of singularities:  1
# Model: tentusscher_model_2006_endo(ten_tusscher_model_2006_endo.cellml)
No of piecewises: 5
# of singularities:  0
# Model: tentusscher_model_2006_epi(ten_tusscher_model_2006_epi.cellml)
No of piecewises: 5
# of singularities:  0
# Model: tentusscher_model_2006_M(ten_tusscher_model_2006_M.cellml)
No of piecewises: 5
# of singularities:  0
# Model: Tomek_model13endo(ToRORd_fkatp_endo.cellml)
No of piecewises: 21
## Equation 1:
```
ICaL__PhiCaK_i = (-ICaL__gamma_ko * extracellular__ko + ICaL__gamma_ki * intracellular_ions__ki * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK_i = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_endo/1_0.png)

## Equation 2:
```
ICaL__PhiCaK_ss = (-ICaL__gamma_ko * extracellular__ko + ICaL__gamma_kss * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK_ss = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_endo/2_0.png)

## Equation 3:
```
ICaL__PhiCaL_i = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cai * intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL_i = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_endo/3_0.png)

## Equation 4:
```
ICaL__PhiCaL_ss = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cass * intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL_ss = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_endo/4_0.png)

## Equation 5:
```
ICaL__PhiCaNa_i = (-ICaL__gamma_nao * extracellular__nao + ICaL__gamma_nai * intracellular_ions__nai * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa_i = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_endo/5_0.png)

## Equation 6:
```
ICaL__PhiCaNa_ss = (-ICaL__gamma_nao * extracellular__nao + ICaL__gamma_nass * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa_ss = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_endo/6_0.png)

## Equation 7:
```
ICab__ICab = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cai * intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (2.36776e-7 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_endo/7_0.png)

## Equation 8:
```
INab__INab = (-extracellular__nao + intracellular_ions__nai * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (1.9238999999999999e-9 * pow(physical_constants__F, 2) * (-extracellular__nao + intracellular_ions__nai * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_endo/8_0.png)

# of singularities:  8
# Model: Tomek_model13epi(ToRORd_fkatp_epi.cellml)
No of piecewises: 21
## Equation 1:
```
ICaL__PhiCaK_i = (-ICaL__gamma_ko * extracellular__ko + ICaL__gamma_ki * intracellular_ions__ki * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK_i = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__ki * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_epi/1_0.png)

## Equation 2:
```
ICaL__PhiCaK_ss = (-ICaL__gamma_ko * extracellular__ko + ICaL__gamma_kss * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK_ss = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__ko * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__kss * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_epi/2_0.png)

## Equation 3:
```
ICaL__PhiCaL_i = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cai * intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL_i = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_epi/3_0.png)

## Equation 4:
```
ICaL__PhiCaL_ss = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cass * intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL_ss = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9999999999999999e-7 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cass * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_epi/4_0.png)

## Equation 5:
```
ICaL__PhiCaNa_i = (-ICaL__gamma_nao * extracellular__nao + ICaL__gamma_nai * intracellular_ions__nai * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa_i = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nai * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_epi/5_0.png)

## Equation 6:
```
ICaL__PhiCaNa_ss = (-ICaL__gamma_nao * extracellular__nao + ICaL__gamma_nass * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa_ss = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(-9.9999999999999995e-8) * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-extracellular__nao * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__nass * exp(-2859.0635474831229 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__kss - 0.00014999999999999999 * intracellular_ions__nass - 0.00059999999999999995 * intracellular_ions__cass + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__kss + 0.25 * intracellular_ions__nass + intracellular_ions__cass)))) * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_epi/6_0.png)

## Equation 7:
```
ICab__ICab = 4.0 * (-ICaL__gamma_cao * extracellular__cao + ICaL__gamma_cai * intracellular_ions__cai * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.18388e-14 * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-9.9999999999999995e-8) * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai))))) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (2.36776e-7 * pow(physical_constants__F, 2) * (-extracellular__cao * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * extracellular__clo - 0.00014999999999999999 * extracellular__ko - 0.00014999999999999999 * extracellular__nao - 0.00059999999999999995 * extracellular__cao + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao) / (1.0 + 0.044721359549995794 * sqrt(0.25 * extracellular__clo + 0.25 * extracellular__ko + 0.25 * extracellular__nao + extracellular__cao)))) + intracellular_ions__cai * exp(-11436.254189932491 * pow(physical_constants__T, (-1.5)) * (-0.00014999999999999999 * intracellular_ions__cli - 0.00014999999999999999 * intracellular_ions__ki - 0.00014999999999999999 * intracellular_ions__nai - 0.00059999999999999995 * intracellular_ions__cai + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai) / (1.0 + 0.044721359549995794 * sqrt(0.25 * intracellular_ions__cli + 0.25 * intracellular_ions__ki + 0.25 * intracellular_ions__nai + intracellular_ions__cai)))) * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_epi/7_0.png)

## Equation 8:
```
INab__INab = (-extracellular__nao + intracellular_ions__nai * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9238999999999998e-16 * (-extracellular__nao + intracellular_ions__nai * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (1.9238999999999999e-9 * pow(physical_constants__F, 2) * (-extracellular__nao + intracellular_ions__nai * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/ToRORd_fkatp_epi/8_0.png)

# of singularities:  8
# Model: Trovato2020(Trovato2020.cellml)
No of piecewises: 2
## Equation 1:
```
ICaL__PhiCaK = (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaK = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__ko + 0.75 * intracellular_ions__kss * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/Trovato2020/1_0.png)

## Equation 2:
```
ICaL__PhiCaL = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaL = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 1.9999999999999999e-7 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (4.0 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__cass * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/Trovato2020/2_0.png)

## Equation 3:
```
ICaL__PhiCaNa = (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__vfrt)) * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
ICaL__PhiCaNa = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.9999999999999995e-8 * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (pow(physical_constants__F, 2) * (-0.75 * extracellular__nao + 0.75 * intracellular_ions__nass * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/Trovato2020/3_0.png)

## Equation 4:
```
ICab__ICab = 4.0 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__casl * exp(2.0 * membrane__vfrt)) * ICab__PCab * membrane__vffrt / (-1.0 + exp(2.0 * membrane__vfrt))
```
## New Eq:
```
ICab__ICab = ((fabs(membrane__v) < 4.9999999999999998e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-4.9999999999999992e-15 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__casl * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 10000000.0 * (4.9999999999999998e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (4.9999999999999992e-15 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__casl * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 4.9999999999999992e-15 * (-0.34100000000000003 * extracellular__cao + intracellular_ions__casl * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (9.9999999999999995e-8 * pow(physical_constants__F, 2) * (-0.34100000000000003 * extracellular__cao + intracellular_ions__casl * exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(2.0 * membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/Trovato2020/4_0.png)

## Equation 5:
```
INab__INab = (-extracellular__nao + intracellular_ions__nasl * exp(membrane__vfrt)) * INab__PNab * membrane__vffrt / (-1.0 + exp(membrane__vfrt))
```
## New Eq:
```
INab__INab = ((fabs(membrane__v) < 9.9999999999999995e-8 * fabs(physical_constants__R * physical_constants__T / physical_constants__F)) ? (-9.3749999999999983e-17 * (-extracellular__nao + intracellular_ions__nasl * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8)) + 5000000.0 * (9.9999999999999995e-8 * physical_constants__R * physical_constants__T / physical_constants__F + membrane__v) * (9.3749999999999983e-17 * (-extracellular__nao + intracellular_ions__nasl * exp(9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(9.9999999999999995e-8)) + 9.3749999999999983e-17 * (-extracellular__nao + intracellular_ions__nasl * exp(-9.9999999999999995e-8)) * physical_constants__F / (-1.0 + exp(-9.9999999999999995e-8))) * physical_constants__F / (physical_constants__R * physical_constants__T)) : (9.3749999999999992e-10 * pow(physical_constants__F, 2) * (-extracellular__nao + intracellular_ions__nasl * exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * membrane__v / ((-1.0 + exp(membrane__v * physical_constants__F / (physical_constants__R * physical_constants__T))) * physical_constants__R * physical_constants__T)))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/Trovato2020/5_0.png)

# of singularities:  5
# Model: viswanathan_model_1999_epi(viswanathan_model_1999_epi.cellml)
No of piecewises: 15
## Equation 1:
```
L_type_Ca_channel__I_CaCa = 4.0 * pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Cao * calcium_dynamics__Cao + L_type_Ca_channel__gamma_Cai * calcium_dynamics__Cai * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Ca * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaCa = ((fabs(membrane__V) < 1.3356169352749131e-6) ? (374358.83507802623 * (1.3356169352749131e-6 + membrane__V) * (1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 1.042038e-5 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (7.8019226357407252 * (-0.34100000000000003 * calcium_dynamics__Cao + calcium_dynamics__Cai * exp(0.074871767015605231 * membrane__V)) * membrane__V / (-1.0 + exp(0.074871767015605231 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/viswanathan_model_1999_epi/1_0.png)

## Equation 2:
```
L_type_Ca_channel__I_CaK = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Ko * ionic_concentrations__Ko + L_type_Ca_channel__gamma_Ki * ionic_concentrations__Ki * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_K * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaK = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 1.8621604999999999e-9 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.00069711623550831479 * (-0.75 * ionic_concentrations__Ko + 0.75 * ionic_concentrations__Ki * exp(0.037435883507802616 * membrane__V)) * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/viswanathan_model_1999_epi/2_0.png)

## Equation 3:
```
L_type_Ca_channel__I_CaNa = pow(membrane__F, 2) * (-L_type_Ca_channel__gamma_Nao * ionic_concentrations__Nao + L_type_Ca_channel__gamma_Nai * ionic_concentrations__Nai * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * L_type_Ca_channel__P_Na * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_channel__I_CaNa = ((fabs(membrane__V) < 2.6712338705498262e-6) ? (187179.41753901311 * (2.6712338705498262e-6 + membrane__V) * (6.5127375e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(9.9999999999999995e-8)) / (-1.0 + exp(9.9999999999999995e-8)) + 6.5127375e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) - 6.5127375e-9 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(-9.9999999999999995e-8)) / (-1.0 + exp(-9.9999999999999995e-8))) : (0.0024381008236689767 * (-0.75 * ionic_concentrations__Nao + 0.75 * ionic_concentrations__Nai * exp(0.037435883507802616 * membrane__V)) * membrane__V / (-1.0 + exp(0.037435883507802616 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/viswanathan_model_1999_epi/3_0.png)

## Equation 4:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 0.001 / (0.00060999999999999997 * (38.899999999999999 + membrane__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * membrane__V)) + 0.0013799999999999999 * (14.199999999999999 + membrane__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * membrane__V)))
```
## New Eq:
```
rapid_delayed_rectifier_potassium_current_xr_gate__tau_xr = 0.001 / (((fabs(14.199999999999999 + membrane__V) < 8.1300813007528783e-7) ? (1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)) - 615000.00000454858 * (14.199999186991869 + membrane__V) * (-1.1219512194943214e-9 / (1.0 - exp(9.9999999998406912e-8)) - 1.1219512195134727e-9 / (1.0 - exp(-1.0000000000011388e-7)))) : (0.0013799999999999999 * (14.199999999999999 + membrane__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * membrane__V)))) + ((fabs(38.899999999999999 + membrane__V) < 6.896551724422384e-7) ? (-4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 724999.99997009686 * (38.900000689655172 + membrane__V) * (4.2068965517283451e-10 / (-1.0 + exp(-1.000000000001e-7)) + 4.2068965520669629e-10 / (-1.0 + exp(1.0000000000814911e-7)))) : (0.00060999999999999997 * (38.899999999999999 + membrane__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * membrane__V)))))
```
## Singularity point: -14.199999999999999
![Singularity](diagrams/manual_fixes/viswanathan_model_1999_epi/4_0.png)
## Singularity point: -38.899999999999999
![Singularity](diagrams/manual_fixes/viswanathan_model_1999_epi/4_1.png)

## Equation 5:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = 0.001 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs1_gate__tau_xs1 = 0.001 * ((fabs(30.0 + membrane__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + membrane__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/viswanathan_model_1999_epi/5_0.png)

## Equation 6:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 0.0040000000000000001 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current_xs2_gate__tau_xs2 = 0.0040000000000000001 * ((fabs(30.0 + membrane__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (30.000001455604075 + membrane__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (30.0 + membrane__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (30.0 + membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: -30.000000000000000
![Singularity](diagrams/manual_fixes/viswanathan_model_1999_epi/6_0.png)

# of singularities:  7
# Model: wang_model_2008(wang_sobie_2008.cellml)
No of piecewises: 4
## Equation 1:
```
calcium_activated_chloride_current__i_ClCa = pow(membrane__F, 2) * (-membrane__Cli + membrane__Clo * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * calcium_activated_chloride_current__P_ClCa * calcium_activated_chloride_current__f_ClCa * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
calcium_activated_chloride_current__i_ClCa = ((fabs(membrane__V) < 2.5674321243523316e-6) ? (194747.11532096748 * (2.5674321243523316e-6 + membrane__V) * (4.1314062499999994e-14 * pow(calcium_concentration__Cass, 3) * (-membrane__Cli + membrane__Clo * exp(9.9999999999999995e-8)) / (pow((1 + 0.25 * calcium_concentration__Cass), 3) * (-1.0 + exp(9.9999999999999995e-8))) + 4.1314062499999994e-14 * pow(calcium_concentration__Cass, 3) * (-membrane__Cli + membrane__Clo * exp(-9.9999999999999995e-8)) / (pow((1 + 0.25 * calcium_concentration__Cass), 3) * (-1.0 + exp(-9.9999999999999995e-8)))) - 4.1314062499999994e-14 * pow(calcium_concentration__Cass, 3) * (-membrane__Cli + membrane__Clo * exp(-9.9999999999999995e-8)) / (pow((1 + 0.25 * calcium_concentration__Cass), 3) * (-1.0 + exp(-9.9999999999999995e-8)))) : (1.6091588988130313e-8 * pow(calcium_concentration__Cass, 3) * (-membrane__Cli + membrane__Clo * exp(0.038949423064193495 * membrane__V)) * membrane__V / (pow((1 + 0.25 * calcium_concentration__Cass), 3) * (-1.0 + exp(0.038949423064193495 * membrane__V)))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/wang_sobie_2008/1_0.png)

## Equation 2:
```
fast_sodium_current_m_gate__alpha_m = 0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))
```
## New Eq:
```
fast_sodium_current_m_gate__alpha_m = ((fabs(47.130000000000003 + membrane__V) < 1.0000000000287557e-6) ? (3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)) - 499999.99998562218 * (47.129999000000005 + membrane__V) * (-3.200000000092018e-7 / (1.0 - exp(1.0000000000287557e-7)) - 3.200000000092018e-7 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.32000000000000001 * (47.130000000000003 + membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * membrane__V))))
```
## Singularity point: -47.130000000000003
![Singularity](diagrams/manual_fixes/wang_sobie_2008/2_0.png)

## Equation 3:
```
slow_delayed_rectifier_potassium_current__alpha_n = 4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))
```
## New Eq:
```
slow_delayed_rectifier_potassium_current__alpha_n = ((fabs(26.5 + membrane__V) < 7.8124999999817923e-7) ? (3.7604140624912359e-12 / (1.0 - exp(-9.9999999999766942e-8)) - 640000.00000149151 * (26.499999218749998 + membrane__V) * (-3.7604140624912359e-12 / (1.0 - exp(9.9999999999766942e-8)) - 3.7604140624912359e-12 / (1.0 - exp(-9.9999999999766942e-8)))) : (4.8133299999999997e-6 * (26.5 + membrane__V) / (1.0 - exp(-3.3919999999999999 - 0.128 * membrane__V))))
```
## Singularity point: -26.500000000000000
![Singularity](diagrams/manual_fixes/wang_sobie_2008/3_0.png)

# of singularities:  3
# Model: winslow_model_1999(winslow_model_1999.cellml)
No of piecewises: 6
## Equation 1:
```
slow_activating_delayed_rectifiyer_K_current_X_ks_gate__tau_X_ks = 0.001 / (0.00013100000000000001 * (-10.0 + membrane__V) / (-1.0 + exp(-0.68699999999999994 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (-10.0 + membrane__V) / (1.0 - exp(1.48 - 0.14799999999999999 * membrane__V)))
```
## New Eq:
```
slow_activating_delayed_rectifiyer_K_current_X_ks_gate__tau_X_ks = 0.001 * ((fabs(-10.0 + membrane__V) < 1.455604075689676e-6) ? (1 / (-1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) - 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8)) + 343500.00000040967 * (-9.9999985443959236 + membrane__V) * (1.0465793304208771e-10 / (1.0 - exp(2.1542940320207204e-7)) + 1.0465793304208771e-10 / (1.0 - exp(-2.1542940320207204e-7)) + 1.9068413391534758e-10 / (-1.0 + exp(9.9999999999880736e-8)) + 1.9068413391534758e-10 / (-1.0 + exp(-9.9999999999880736e-8))))) : (1 / (0.00013100000000000001 * (-10.0 + membrane__V) / (-1.0 + exp(-0.68699999999999994 + 0.068699999999999997 * membrane__V)) + 7.1899999999999999e-5 * (-10.0 + membrane__V) / (1.0 - exp(1.48 - 0.14799999999999999 * membrane__V)))))
```
## Singularity point: 10.000000000000000
![Singularity](diagrams/manual_fixes/winslow_model_1999/1_0.png)

## Equation 2:
```
L_type_Ca_current__i_Ca_max = 4000.0 * pow(membrane__F, 2) * (0.001 * exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T)) - 0.34100000000000003 * standard_ionic_concentrations__Cao) * L_type_Ca_current__P_Ca * membrane__V / ((-1.0 + exp(2.0 * membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_Ca_max = ((fabs(membrane__V) < 1.3356880329847825e-6) ? (374338.90822745475 * (1.3356880329847825e-6 + membrane__V) * (0.019297068300000001 * (0.001 * exp(9.9999999999999995e-8) - 0.34100000000000003 * standard_ionic_concentrations__Cao) * L_type_Ca_current__P_Ca / (-1.0 + exp(9.9999999999999995e-8)) + 0.019297068300000001 * (0.001 * exp(-9.9999999999999995e-8) - 0.34100000000000003 * standard_ionic_concentrations__Cao) * L_type_Ca_current__P_Ca / (-1.0 + exp(-9.9999999999999995e-8))) - 0.019297068300000001 * (0.001 * exp(-9.9999999999999995e-8) - 0.34100000000000003 * standard_ionic_concentrations__Cao) * L_type_Ca_current__P_Ca / (-1.0 + exp(-9.9999999999999995e-8))) : (14447.286958825252 * (0.001 * exp(0.074867781645490947 * membrane__V) - 0.34100000000000003 * standard_ionic_concentrations__Cao) * L_type_Ca_current__P_Ca * membrane__V / (-1.0 + exp(0.074867781645490947 * membrane__V))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/winslow_model_1999/2_0.png)

## Equation 3:
```
L_type_Ca_current__i_Ca_K = pow(membrane__F, 2) * (-standard_ionic_concentrations__Ko + intracellular_ion_concentrations__Ki * exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * (L_type_Ca_current__O + L_type_Ca_current__O_Ca) * L_type_Ca_current__p_prime_k * L_type_Ca_current_y_gate__y * membrane__V / ((-1.0 + exp(membrane__F * membrane__V / (membrane__R * membrane__T))) * membrane__R * membrane__T)
```
## New Eq:
```
L_type_Ca_current__i_Ca_K = ((fabs(membrane__V) < 2.671376065969565e-6) ? (187169.45411372738 * (2.671376065969565e-6 + membrane__V) * (5.5865012728500001e-12 * (-standard_ionic_concentrations__Ko + intracellular_ion_concentrations__Ki * exp(9.9999999999999995e-8)) * (L_type_Ca_current__O + L_type_Ca_current__O_Ca) * L_type_Ca_current_y_gate__y / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(9.9999999999999995e-8))) + 5.5865012728500001e-12 * (-standard_ionic_concentrations__Ko + intracellular_ion_concentrations__Ki * exp(-9.9999999999999995e-8)) * (L_type_Ca_current__O + L_type_Ca_current__O_Ca) * L_type_Ca_current_y_gate__y / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(-9.9999999999999995e-8)))) - 5.5865012728500001e-12 * (-standard_ionic_concentrations__Ko + intracellular_ion_concentrations__Ki * exp(-9.9999999999999995e-8)) * (L_type_Ca_current__O + L_type_Ca_current__O_Ca) * L_type_Ca_current_y_gate__y / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(-9.9999999999999995e-8)))) : (2.0912447872899554e-6 * (-standard_ionic_concentrations__Ko + intracellular_ion_concentrations__Ki * exp(0.037433890822745473 * membrane__V)) * (L_type_Ca_current__O + L_type_Ca_current__O_Ca) * L_type_Ca_current_y_gate__y * membrane__V / ((1.0 - 3.773584905660377 * L_type_Ca_current__i_Ca_max) * (-1.0 + exp(0.037433890822745473 * membrane__V)))))
```
## Singularity point: 0
![Singularity](diagrams/manual_fixes/winslow_model_1999/3_0.png)
## Singularity point: 0
![Singularity](diagrams/manual_fixes/winslow_model_1999/3_1.png)

# of singularities:  3
# Model: zhang_SAN_model_2000_0D_capable(zhang_SAN_model_2000_0D_capable.cellml)
No of piecewises: 0
## Equation 1:
```
L_type_Ca_channel_d_gate__alpha_d_L = -28.390000000000001 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V)) - 84.900000000000006 * membrane__V / (-1.0 + exp(-0.20799999999999999 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__alpha_d_L = ((fabs(membrane__V) < 4.8076923076923074e-7) ? (-4.0817307692307694e-5 / (-1.0 + exp(-9.9999999999999995e-8)) - 1040000.0 * (-4.8076923076923074e-7 + membrane__V) * (4.0817307692307694e-5 / (-1.0 + exp(9.9999999999999995e-8)) + 4.0817307692307694e-5 / (-1.0 + exp(-9.9999999999999995e-8)))) : (-84.900000000000006 * membrane__V / (-1.0 + exp(-0.20799999999999999 * membrane__V)))) + ((fabs(35.0 + membrane__V) < 2.5000000000718892e-7) ? (-7.097500000992074e-6 / (-1.0 + exp(-1.000000000139778e-7)) - 1999999.9999424887 * (34.999999750000001 + membrane__V) * (7.0974999994161125e-6 / (-1.0 + exp(9.9999999991773334e-8)) + 7.097500000992074e-6 / (-1.0 + exp(-1.000000000139778e-7)))) : (-28.390000000000001 * (35.0 + membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * membrane__V))))
```
## Singularity point: -35.000000000000000
![Singularity](diagrams/manual_fixes/zhang_SAN_model_2000_0D_capable/1_0.png)
## Singularity point: 0
![Singularity](diagrams/manual_fixes/zhang_SAN_model_2000_0D_capable/1_1.png)

## Equation 2:
```
L_type_Ca_channel_d_gate__beta_d_L = 11.43 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_d_gate__beta_d_L = ((fabs(-5.0 + membrane__V) < 2.5000000000025002e-7) ? (-2.8575000000028576e-6 / (-1.0 + exp(-1.0000000000010001e-7)) + 1999999.9999979998 * (-4.9999997499999997 + membrane__V) * (2.8575000000028576e-6 / (-1.0 + exp(1.0000000000010001e-7)) + 2.8575000000028576e-6 / (-1.0 + exp(-1.0000000000010001e-7)))) : (11.43 * (-5.0 + membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * membrane__V))))
```
## Singularity point: 5.0000000000000000
![Singularity](diagrams/manual_fixes/zhang_SAN_model_2000_0D_capable/2_0.png)

## Equation 3:
```
L_type_Ca_channel_f_gate__alpha_f_L = 3.75 * (28.0 + membrane__V) / (-1.0 + exp(7.0 + 0.25 * membrane__V))
```
## New Eq:
```
L_type_Ca_channel_f_gate__alpha_f_L = ((fabs(28.0 + membrane__V) < 4.0000000001150227e-7) ? (-1.5000000000431335e-6 / (-1.0 + exp(-1.0000000000287557e-7)) + 1249999.9999640554 * (28.000000400000001 + membrane__V) * (1.5000000000431335e-6 / (-1.0 + exp(1.0000000000287557e-7)) + 1.5000000000431335e-6 / (-1.0 + exp(-1.0000000000287557e-7)))) : (3.75 * (28.0 + membrane__V) / (-1.0 + exp(7.0 + 0.25 * membrane__V))))
```
## Singularity point: -28.000000000000000
![Singularity](diagrams/manual_fixes/zhang_SAN_model_2000_0D_capable/3_0.png)

# of singularities:  4
