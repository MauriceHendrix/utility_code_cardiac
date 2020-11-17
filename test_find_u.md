# Model: mcallister_noble_tsien_1975_modelB
## Equation 1:
```
fast_sodium_current_m_gate__alpha_m = (47.0 + membrane__V) / (1.0 - 0.0090952771016958173 * exp(-0.10000000000000001 * membrane__V))
```
### Partially evaluated to: 
```
fast_sodium_current_m_gate__alpha_m = (47.0 + membrane__V) / (1.0 - 0.0090952771016958173 * exp(-0.10000000000000001 * membrane__V))
```
### Singulariy points detected:

{-47.000000000000000}
*U*
`-4.7000000000000002 - 0.10000000000000001 * membrane__V`

*V for 1e-07 range* 
`-47.000000999999997 - -46.999999000000003`

*Singularity point: -47.000000000000000*

![point](diagrams/u/mcallister_noble_tsien_1975_modelB/eq1-sing1.png)
## New Eq:
((fabs(47.0 + membrane__V) < 1.0000000000287557e-6) ? (-1.0000000000842668e-6 / (1.0 - exp(1.0000000000287557e-7)) + (23500000.499324244 + 499999.99998562218 * membrane__V) * (9.9999999997324451e-7 / (1.0 - exp(-1.0000000000287557e-7)) + 1.0000000000842668e-6 / (1.0 - exp(1.0000000000287557e-7)))) : ((47.0 + membrane__V) / (1.0 - exp(-4.7000000000000002 - 0.10000000000000001 * membrane__V))))

## Equation 2:
```
pacemaker_potassium_current_s_gate__alpha_s = 0.001 * (-pacemaker_potassium_current_s_gate__E_s + membrane__V) / (1.0 - exp(0.20000000000000001 * pacemaker_potassium_current_s_gate__E_s - 0.20000000000000001 * membrane__V))
```
### Partially evaluated to: 
```
pacemaker_potassium_current_s_gate__alpha_s = 0.001 * (52.0 + membrane__V) / (1.0 - 3.0432483008403618e-5 * exp(-0.20000000000000001 * membrane__V))
```
### Singulariy points detected:

{1.0*_pacemaker_potassium_current_s_gate$E_s}
*U*
`-10.4 - 0.20000000000000001 * membrane__V`

*V for 1e-07 range* 
`-52.000000499999999 - -51.999999500000001`

*Singularity point: -52.000000000000000*

![point](diagrams/u/mcallister_noble_tsien_1975_modelB/eq2-sing1.png)
## New Eq:
((51.999999500000001 + pacemaker_potassium_current_s_gate__E_s < -fabs(-pacemaker_potassium_current_s_gate__E_s + membrane__V)) ? (-5.0000000001437788e-10 / (1.0 - exp(1.0000000000287557e-7)) + (52000000.498504706 + 999999.99997124437 * membrane__V) * (5.0000000001437788e-10 / (1.0 - exp(1.0000000000287557e-7)) + 5.0000000001437788e-10 / (1.0 - exp(-1.0000000000287557e-7)))) : (0.001 * (-pacemaker_potassium_current_s_gate__E_s + membrane__V) / (1.0 - exp(0.20000000000000001 * pacemaker_potassium_current_s_gate__E_s - 0.20000000000000001 * membrane__V))))

## Equation 3:
```
secondary_inward_current_d_gate__alpha_d = 0.002 * (40.0 + membrane__V) / (1.0 - 0.018315638888734175 * exp(-0.10000000000000001 * membrane__V))
```
### Partially evaluated to: 
```
secondary_inward_current_d_gate__alpha_d = 0.002 * (40.0 + membrane__V) / (1.0 - 0.018315638888734175 * exp(-0.10000000000000001 * membrane__V))
```
### Singulariy points detected:

{-40.000000000000000}
*U*
`-4.0 - 0.10000000000000001 * membrane__V`

*V for 1e-07 range* 
`-40.000000999999997 - -39.999999000000003`

*Singularity point: -40.000000000000000*

![point](diagrams/u/mcallister_noble_tsien_1975_modelB/eq3-sing1.png)
## New Eq:
((fabs(40.0 + membrane__V) < 9.9999999997324451e-7) ? (-2.0000000000575115e-9 / (1.0 - exp(1.0000000000287557e-7)) + (20000000.499979999 + 499999.99999949994 * membrane__V) * (1.999999999946489e-9 / (1.0 - exp(-9.9999999995936673e-8)) + 2.0000000000575115e-9 / (1.0 - exp(1.0000000000287557e-7)))) : (0.002 * (40.0 + membrane__V) / (1.0 - exp(-4.0 - 0.10000000000000001 * membrane__V))))

## Equation 4:
```
time_independent_outward_current__i_K1 = 0.35714285714285715 * pacemaker_potassium_current__I_K2 + 0.20000000000000001 * (-time_independent_outward_current__E_K1 + membrane__V) / (1.0 - exp(0.040000000000000001 * time_independent_outward_current__E_K1 - 0.040000000000000001 * membrane__V))
```
### Partially evaluated to: 
```
time_independent_outward_current__i_K1 = (-1.0 + 81.450868664968112 * exp(0.040000000000000001 * membrane__V)) / (11.023176380641601 * exp(0.040000000000000001 * membrane__V) + 121.51041751873488 * exp(0.080000000000000002 * membrane__V)) + 0.20000000000000001 * (30.0 + membrane__V) / (1.0 - 0.30119421191220208 * exp(-0.040000000000000001 * membrane__V))
```
### Singulariy points detected:

{1.0*_time_independent_outward_current$E_K1}
####A + B:

`0.20000000000000001 * (30.0 + membrane__V) / (1.0 - 0.30119421191220208 * exp(-0.040000000000000001 * membrane__V))`
`(-1.0 + 81.450868664968112 * exp(0.040000000000000001 * membrane__V)) / (11.023176380641601 * exp(0.040000000000000001 * membrane__V) + 121.51041751873488 * exp(0.080000000000000002 * membrane__V))`

*U*
`-1.2 - 0.040000000000000001 * membrane__V`

*V for 1e-07 range* 
`-30.000002500000001 - -29.999997499999999`

*Singularity point: -30.000000000000000*

![point](diagrams/u/mcallister_noble_tsien_1975_modelB/eq4-sing1.png)
## New Eq:
((fabs(30.0 + membrane__V) < 2.500000000016378e-6) ? (-4.9999999999772453e-7 / (1.0 - exp(9.9999999999406119e-8)) + (6000000.5000273064 + 200000.00000091019 * membrane__V) * (4.9999999999772453e-7 / (1.0 - exp(9.9999999999406119e-8)) + 4.9999999999772453e-7 / (1.0 - exp(-9.9999999999406119e-8)) + (-1.0 + exp(3.2000001)) / (exp(1.2000001) + exp(2.4000002)) - (-1.0 + exp(3.1999998999999999)) / (exp(1.1999998999999999) + exp(2.3999997999999998))) + (-1.0 + exp(3.1999998999999999)) / (exp(1.1999998999999999) + exp(2.3999997999999998))) : (0.35714285714285715 * pacemaker_potassium_current__I_K2 + 0.20000000000000001 * (-time_independent_outward_current__E_K1 + membrane__V) / (1.0 - exp(0.040000000000000001 * time_independent_outward_current__E_K1 - 0.040000000000000001 * membrane__V))))

## Equation 5:
```
transient_chloride_current_q_gate__alpha_q = 0.0080000000000000002 * membrane__V / (1.0 - exp(-0.10000000000000001 * membrane__V))
```
### Partially evaluated to: 
```
transient_chloride_current_q_gate__alpha_q = 0.0080000000000000002 * membrane__V / (1.0 - exp(-0.10000000000000001 * membrane__V))
```
### Singulariy points detected:

{0}
*U*
`0.10000000000000001 * membrane__V`

*V for 1e-07 range* 
`-9.9999999999999995e-7 - 9.9999999999999995e-7`

*Singularity point: 0*

![point](diagrams/u/mcallister_noble_tsien_1975_modelB/eq5-sing1.png)
## New Eq:
((fabs(membrane__V) < 9.9999999999999995e-7) ? (-7.9999999999999988e-9 / (1.0 - exp(9.9999999999999995e-8)) + (0.5 + 500000.00000000006 * membrane__V) * (7.9999999999999988e-9 / (1.0 - exp(9.9999999999999995e-8)) + 7.9999999999999988e-9 / (1.0 - exp(-9.9999999999999995e-8)))) : (0.0080000000000000002 * membrane__V / (1.0 - exp(-0.10000000000000001 * membrane__V))))

# Model: sachse_model_2007
## Equation 1:
```
I_Shkr__I_Shkr = pow(model_parameters__F, 2) * (-model_parameters__Ko * exp(-membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T)) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr * membrane__Vm / ((1.0 - exp(-membrane__Vm * model_parameters__F / (model_parameters__R * model_parameters__T))) * model_parameters__R * model_parameters__T)
```
### Partially evaluated to: 
```
I_Shkr__I_Shkr = 1120607.7015643802 * (-model_parameters__Ko * exp(-11.612515042117931 * membrane__Vm / model_parameters__T) + model_parameters__Ki) * I_Shkr__OShkr * I_Shkr__PShkr * membrane__Vm / ((1.0 - exp(-11.612515042117931 * membrane__Vm / model_parameters__T)) * model_parameters__T)
```
### Singulariy points detected:

{0}
#### float * A

####Failed!

<class 'sympy.core.mul.Mul'>
_I_Shkr$OShkr*_I_Shkr$PShkr*_membrane$Vm*(_model_parameters$Ki - _model_parameters$Ko*exp(-11.61251504211793*_membrane$Vm/_model_parameters$T))/(_model_parameters$T*(1.0 - exp(-11.61251504211793*_membrane$Vm/_model_parameters$T)))

*try substituting parameters*

#### Eq == 0!
