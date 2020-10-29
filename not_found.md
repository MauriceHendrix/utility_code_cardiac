# Model: nygren_atrial_model_1998
## Equation 2:
```
sodium_potassium_pump__i_NaK = pow(intracellular_ion_concentrations__Na_i, 1.5) * (150.0 + membrane__V) * cleft_space_ion_concentrations__K_c * sodium_potassium_pump__i_NaK_max / ((200.0 + membrane__V) * (pow(intracellular_ion_concentrations__Na_i, 1.5) + pow(sodium_potassium_pump__k_NaK_Na, 1.5)) * (cleft_space_ion_concentrations__K_c + sodium_potassium_pump__k_NaK_K))
```
### Partially evaluated to: 
```
sodium_potassium_pump__i_NaK = 24.281503485861936 * (150.0 + membrane__V) / (200.0 + membrane__V)
```
### Singulariy points detected:
{-200.00000000000000}
####A + B:
`3642.2255228792906 / (200.0 + membrane__V)`
`24.281503485861936 * membrane__V / (200.0 + membrane__V)`

#### float * A

####1 / A

#### float * A

####1 / A