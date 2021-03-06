//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.1.0
//!
//! Model: luo_rudy_1994
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on 2020-06-18 22:59:59
//!
//! <autogenerated>

#include "luo_rudy_1994.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Cellluo_rudy_1994FromCellML::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__membrane__stimCurrent_converted = 50.000000000000007; // uA_per_cm2
        const double var_chaste_interface__membrane__stimDuration = 0.5; // ms
        const double var_chaste_interface__membrane__stimPeriod = 1000.0; // ms
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__membrane__stimCurrent_converted),
                var_chaste_interface__membrane__stimDuration,
                var_chaste_interface__membrane__stimPeriod,
                0.0
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }
    double Cellluo_rudy_1994FromCellML::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    Cellluo_rudy_1994FromCellML::Cellluo_rudy_1994FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                12,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellluo_rudy_1994FromCellML>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
        this->mParameters[0] = 1.8; // (var_ionic_concentrations__Cao) [mM]
        this->mParameters[1] = 5.4000000000000004; // (var_ionic_concentrations__Ko) [mM]
        this->mParameters[2] = 140.0; // (var_ionic_concentrations__Nao) [mM]
        this->mParameters[3] = 0.01; // (var_membrane__Cm) [uF_per_mm2]
        this->mParameters[4] = 0.16; // (var_fast_sodium_current__g_Na) [mS_per_mm2]
        this->mParameters[5] = 0.0074999999999999997; // (var_time_independent_potassium_current__g_K1_max) [mS_per_mm2]
    }

    Cellluo_rudy_1994FromCellML::~Cellluo_rudy_1994FromCellML()
    {
    }
    
    double Cellluo_rudy_1994FromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__ionic_concentrations__Cai = rY[1];
        // Units: mM; Initial value: 0.00012
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__fast_sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__L_type_Ca_channel_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__L_type_Ca_channel_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__time_dependent_potassium_current_X_gate__X = rY[7];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__ionic_concentrations__Nai = rY[8];
        // Units: mM; Initial value: 10.0
        double var_chaste_interface__ionic_concentrations__Ki = rY[9];
        // Units: mM; Initial value: 145.0
        
        const double var_L_type_Ca_channel_f_Ca_gate__f_Ca = 1 / (1.0 + 2777777.7777777785 * pow(var_chaste_interface__ionic_concentrations__Cai, 2)); // dimensionless
        const double var_fast_sodium_current__E_Na = 26.614641953637257 * log(mParameters[2] / var_chaste_interface__ionic_concentrations__Nai); // mV
        const double var_L_type_Ca_channel__i_Ca_L = 7.0228579563684903e-6 * (-0.75 * mParameters[1] + 0.75 * var_chaste_interface__ionic_concentrations__Ki * exp(0.037573302761014088 * var_chaste_interface__membrane__V)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_L_type_Ca_channel_f_Ca_gate__f_Ca * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_chaste_interface__membrane__V / (-1.0 + exp(0.037573302761014088 * var_chaste_interface__membrane__V)) + 0.078597788527232842 * (-0.34000000000000002 * mParameters[0] + var_chaste_interface__ionic_concentrations__Cai * exp(0.075146605522028176 * var_chaste_interface__membrane__V)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_L_type_Ca_channel_f_Ca_gate__f_Ca * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_chaste_interface__membrane__V / (-1.0 + exp(0.075146605522028176 * var_chaste_interface__membrane__V)) + 2.4561808914760263e-5 * (-0.75 * mParameters[2] + 0.75 * var_chaste_interface__ionic_concentrations__Nai * exp(0.037573302761014088 * var_chaste_interface__membrane__V)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_L_type_Ca_channel_f_Ca_gate__f_Ca * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_chaste_interface__membrane__V / (-1.0 + exp(0.037573302761014088 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_Na_Ca_exchanger__i_NaCa = 20.0 * (pow(var_chaste_interface__ionic_concentrations__Nai, 3) * mParameters[0] * exp(0.013150655966354929 * var_chaste_interface__membrane__V) - pow(mParameters[2], 3) * var_chaste_interface__ionic_concentrations__Cai * exp(-0.024422646794659157 * var_chaste_interface__membrane__V)) / ((1.0 + 0.10000000000000001 * exp(-0.024422646794659157 * var_chaste_interface__membrane__V)) * (669921.875 + pow(mParameters[2], 3)) * (1.3799999999999999 + mParameters[0])); // uA_per_mm2
        const double var_calcium_background_current__i_Ca_b = 3.0159999999999999e-5 * var_chaste_interface__membrane__V - 0.00040134880066084979 * log(mParameters[0] / var_chaste_interface__ionic_concentrations__Cai); // uA_per_mm2
        const double var_fast_sodium_current__i_Na = pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-var_fast_sodium_current__E_Na + var_chaste_interface__membrane__V) * mParameters[4] * var_chaste_interface__fast_sodium_current_h_gate__h * var_chaste_interface__fast_sodium_current_j_gate__j; // uA_per_mm2
        const double var_non_specific_calcium_activated_current__Vns = -26.614641953637257 * log((mParameters[1] + mParameters[2]) / (var_chaste_interface__ionic_concentrations__Ki + var_chaste_interface__ionic_concentrations__Nai)) + var_chaste_interface__membrane__V; // mV
        const double var_non_specific_calcium_activated_current__i_ns_Ca = 6.3678763853082156e-6 * (-0.75 * mParameters[1] + 0.75 * var_chaste_interface__ionic_concentrations__Ki * exp(0.037573302761014088 * var_non_specific_calcium_activated_current__Vns)) * var_non_specific_calcium_activated_current__Vns / ((1.0 + 1.7279999999999996e-9 / pow(var_chaste_interface__ionic_concentrations__Cai, 3)) * (-1.0 + exp(0.037573302761014088 * var_non_specific_calcium_activated_current__Vns))) + 6.3678763853082156e-6 * (-0.75 * mParameters[2] + 0.75 * var_chaste_interface__ionic_concentrations__Nai * exp(0.037573302761014088 * var_non_specific_calcium_activated_current__Vns)) * var_non_specific_calcium_activated_current__Vns / ((1.0 + 1.7279999999999996e-9 / pow(var_chaste_interface__ionic_concentrations__Cai, 3)) * (-1.0 + exp(0.037573302761014088 * var_non_specific_calcium_activated_current__Vns))); // uA_per_mm2
        const double var_sarcolemmal_calcium_pump__i_p_Ca = 0.0115 * var_chaste_interface__ionic_concentrations__Cai / (0.00050000000000000001 + var_chaste_interface__ionic_concentrations__Cai); // uA_per_mm2
        const double var_sodium_background_current__i_Na_b = 1.4100000000000001e-5 * var_chaste_interface__membrane__V - 1.4100000000000001e-5 * var_fast_sodium_current__E_Na; // uA_per_mm2
        const double var_sodium_potassium_pump__i_NaK = 0.014999999999999999 * mParameters[1] / ((1.0 + 31.622776601683793 * pow(1 / var_chaste_interface__ionic_concentrations__Nai, 1.5)) * (1.5 + mParameters[1]) * (1.0 + 0.1245 * exp(-0.0037573302761014088 * var_chaste_interface__membrane__V) + 0.036499999999999998 * (-0.14285714285714285 + 0.14285714285714285 * exp(0.01485884101040119 * mParameters[2])) * exp(-0.037573302761014088 * var_chaste_interface__membrane__V))); // uA_per_mm2
        const double var_time_dependent_potassium_current__i_K = 0.0012135347818116574 * sqrt(mParameters[1]) * pow(var_chaste_interface__time_dependent_potassium_current_X_gate__X, 2) * (-26.614641953637257 * log((0.018329999999999999 * mParameters[2] + mParameters[1]) / (0.018329999999999999 * var_chaste_interface__ionic_concentrations__Nai + var_chaste_interface__ionic_concentrations__Ki)) + var_chaste_interface__membrane__V) / (1.0 + exp(-1.7526479750778814 + 0.031152647975077882 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_time_independent_potassium_current__E_K1 = 26.614641953637257 * log(mParameters[1] / var_chaste_interface__ionic_concentrations__Ki); // mV
        const double var_plateau_potassium_current__i_Kp = 0.000183 * (-var_time_independent_potassium_current__E_K1 + var_chaste_interface__membrane__V) / (1.0 + exp(1.2521739130434781 - 0.16722408026755853 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_time_independent_potassium_current__i_K1 = 0.4389381125701739 * sqrt(mParameters[1]) * (-var_time_independent_potassium_current__E_K1 + var_chaste_interface__membrane__V) * mParameters[5] / ((1.0 + exp(-14.1227775 + 0.23849999999999999 * var_chaste_interface__membrane__V - 0.23849999999999999 * var_time_independent_potassium_current__E_K1)) * (1.02 / (1.0 + exp(-14.1227775 + 0.23849999999999999 * var_chaste_interface__membrane__V - 0.23849999999999999 * var_time_independent_potassium_current__E_K1)) + (0.49124000000000001 * exp(0.43983232 + 0.080320000000000003 * var_chaste_interface__membrane__V - 0.080320000000000003 * var_time_independent_potassium_current__E_K1) + exp(-36.698642499999998 + 0.061749999999999999 * var_chaste_interface__membrane__V - 0.061749999999999999 * var_time_independent_potassium_current__E_K1)) / (1.0 + exp(-2.4444678999999998 + 0.51429999999999998 * var_time_independent_potassium_current__E_K1 - 0.51429999999999998 * var_chaste_interface__membrane__V)))); // uA_per_mm2
        const double var_chaste_interface__i_ionic = 100.00000000000001 * var_L_type_Ca_channel__i_Ca_L + 100.00000000000001 * var_Na_Ca_exchanger__i_NaCa + 100.00000000000001 * var_calcium_background_current__i_Ca_b + 100.00000000000001 * var_fast_sodium_current__i_Na + 100.00000000000001 * var_non_specific_calcium_activated_current__i_ns_Ca + 100.00000000000001 * var_plateau_potassium_current__i_Kp + 100.00000000000001 * var_sarcolemmal_calcium_pump__i_p_Ca + 100.00000000000001 * var_sodium_background_current__i_Na_b + 100.00000000000001 * var_sodium_potassium_pump__i_NaK + 100.00000000000001 * var_time_dependent_potassium_current__i_K + 100.00000000000001 * var_time_independent_potassium_current__i_K1; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellluo_rudy_1994FromCellML::EvaluateYDerivatives(double var_chaste_interface__environment__time, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__ionic_concentrations__Cai = rY[1];
        // Units: mM; Initial value: 0.00012
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__fast_sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__L_type_Ca_channel_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__L_type_Ca_channel_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__time_dependent_potassium_current_X_gate__X = rY[7];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__ionic_concentrations__Nai = rY[8];
        // Units: mM; Initial value: 10.0
        double var_chaste_interface__ionic_concentrations__Ki = rY[9];
        // Units: mM; Initial value: 145.0
        double var_chaste_interface__ionic_concentrations__Ca_JSR = rY[10];
        // Units: mM; Initial value: 1.8
        double var_chaste_interface__ionic_concentrations__Ca_NSR = rY[11];
        // Units: mM; Initial value: 1.8

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_calcium_fluxes_in_the_SR__delta_Ca_i2 = 0; // mM
        const double var_calcium_fluxes_in_the_SR__i_leak = 0.00033333333333333332 * var_chaste_interface__ionic_concentrations__Ca_NSR; // mM_per_ms
        const double var_calcium_fluxes_in_the_SR__i_tr = 0.0055555555555555558 * var_chaste_interface__ionic_concentrations__Ca_NSR - 0.0055555555555555558 * var_chaste_interface__ionic_concentrations__Ca_JSR; // mM_per_ms
        const double var_L_type_Ca_channel_f_Ca_gate__f_Ca = 1 / (1.0 + 2777777.7777777785 * pow(var_chaste_interface__ionic_concentrations__Cai, 2)); // dimensionless
        const double var_calcium_fluxes_in_the_SR__i_rel = (1.0 - exp(0)) * (-0.00018000000000000001 + var_calcium_fluxes_in_the_SR__delta_Ca_i2) * (-var_chaste_interface__ionic_concentrations__Cai + var_chaste_interface__ionic_concentrations__Ca_JSR) * ((var_calcium_fluxes_in_the_SR__delta_Ca_i2 < 0.00018000000000000001) ? (0) : (60.0)) * exp(0) / (0.00062 + var_calcium_fluxes_in_the_SR__delta_Ca_i2); // mM_per_ms
        const double var_calcium_fluxes_in_the_SR__i_up = 0.0050000000000000001 * var_chaste_interface__ionic_concentrations__Cai / (0.00092000000000000003 + var_chaste_interface__ionic_concentrations__Cai); // mM_per_ms
        const double d_dt_chaste_interface_var_ionic_concentrations__Ca_NSR = -var_calcium_fluxes_in_the_SR__i_leak - var_calcium_fluxes_in_the_SR__i_tr + var_calcium_fluxes_in_the_SR__i_up; // mM / ms
        const double d_dt_chaste_interface_var_ionic_concentrations__Ca_JSR = -var_calcium_fluxes_in_the_SR__i_rel + 11.5 * var_calcium_fluxes_in_the_SR__i_tr; // mM / ms
        const double var_fast_sodium_current__E_Na = 26.614641953637257 * log(mParameters[2] / var_chaste_interface__ionic_concentrations__Nai); // mV
        const double var_L_type_Ca_channel__i_CaCa = 0.078597788527232842 * (-0.34000000000000002 * mParameters[0] + var_chaste_interface__ionic_concentrations__Cai * exp(0.075146605522028176 * var_chaste_interface__membrane__V)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_L_type_Ca_channel_f_Ca_gate__f_Ca * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_chaste_interface__membrane__V / (-1.0 + exp(0.075146605522028176 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_L_type_Ca_channel__i_CaK = 7.0228579563684903e-6 * (-0.75 * mParameters[1] + 0.75 * var_chaste_interface__ionic_concentrations__Ki * exp(0.037573302761014088 * var_chaste_interface__membrane__V)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_L_type_Ca_channel_f_Ca_gate__f_Ca * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_chaste_interface__membrane__V / (-1.0 + exp(0.037573302761014088 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_L_type_Ca_channel__i_CaNa = 2.4561808914760263e-5 * (-0.75 * mParameters[2] + 0.75 * var_chaste_interface__ionic_concentrations__Nai * exp(0.037573302761014088 * var_chaste_interface__membrane__V)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_L_type_Ca_channel_f_Ca_gate__f_Ca * var_chaste_interface__L_type_Ca_channel_f_gate__f * var_chaste_interface__membrane__V / (-1.0 + exp(0.037573302761014088 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_L_type_Ca_channel_d_gate__d_infinity = 1 / (1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_L_type_Ca_channel_d_gate__tau_d = 28.571428571428569 * (1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * var_chaste_interface__membrane__V)) * var_L_type_Ca_channel_d_gate__d_infinity / (10.0 + var_chaste_interface__membrane__V); // ms
        const double d_dt_chaste_interface_var_L_type_Ca_channel_d_gate__d = (1.0 - var_chaste_interface__L_type_Ca_channel_d_gate__d) * var_L_type_Ca_channel_d_gate__d_infinity / var_L_type_Ca_channel_d_gate__tau_d - (1.0 - var_L_type_Ca_channel_d_gate__d_infinity) * var_chaste_interface__L_type_Ca_channel_d_gate__d / var_L_type_Ca_channel_d_gate__tau_d; // 1 / ms
        const double var_L_type_Ca_channel_f_gate__f_infinity = 1 / (1.0 + exp(4.0767441860465121 + 0.11627906976744186 * var_chaste_interface__membrane__V)) + 0.59999999999999998 / (1.0 + exp(2.5 - 0.050000000000000003 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_L_type_Ca_channel_f_gate__tau_f = 1 / (0.02 + 0.019699999999999999 * exp(-0.113569 * pow((1 + 0.10000000000000001 * var_chaste_interface__membrane__V), 2))); // ms
        const double d_dt_chaste_interface_var_L_type_Ca_channel_f_gate__f = (1.0 - var_chaste_interface__L_type_Ca_channel_f_gate__f) * var_L_type_Ca_channel_f_gate__f_infinity / var_L_type_Ca_channel_f_gate__tau_f - (1.0 - var_L_type_Ca_channel_f_gate__f_infinity) * var_chaste_interface__L_type_Ca_channel_f_gate__f / var_L_type_Ca_channel_f_gate__tau_f; // 1 / ms
        const double var_Na_Ca_exchanger__i_NaCa = 20.0 * (pow(var_chaste_interface__ionic_concentrations__Nai, 3) * mParameters[0] * exp(0.013150655966354929 * var_chaste_interface__membrane__V) - pow(mParameters[2], 3) * var_chaste_interface__ionic_concentrations__Cai * exp(-0.024422646794659157 * var_chaste_interface__membrane__V)) / ((1.0 + 0.10000000000000001 * exp(-0.024422646794659157 * var_chaste_interface__membrane__V)) * (669921.875 + pow(mParameters[2], 3)) * (1.3799999999999999 + mParameters[0])); // uA_per_mm2
        const double var_calcium_background_current__i_Ca_b = 3.0159999999999999e-5 * var_chaste_interface__membrane__V - 0.00040134880066084979 * log(mParameters[0] / var_chaste_interface__ionic_concentrations__Cai); // uA_per_mm2
        const double var_fast_sodium_current__i_Na = pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-var_fast_sodium_current__E_Na + var_chaste_interface__membrane__V) * mParameters[4] * var_chaste_interface__fast_sodium_current_h_gate__h * var_chaste_interface__fast_sodium_current_j_gate__j; // uA_per_mm2
        const double d_dt_chaste_interface_var_fast_sodium_current_h_gate__h = (1.0 - var_chaste_interface__fast_sodium_current_h_gate__h) * ((var_chaste_interface__membrane__V < -40.0) ? (0.13500000000000001 * exp(-11.764705882352942 - 0.14705882352941177 * var_chaste_interface__membrane__V)) : (0)) - ((var_chaste_interface__membrane__V < -40.0) ? (310000.0 * exp(0.34999999999999998 * var_chaste_interface__membrane__V) + 3.5600000000000001 * exp(0.079000000000000001 * var_chaste_interface__membrane__V)) : (7.6923076923076916 / (1.0 + exp(-0.96036036036036043 - 0.0900900900900901 * var_chaste_interface__membrane__V)))) * var_chaste_interface__fast_sodium_current_h_gate__h; // 1 / ms
        const double d_dt_chaste_interface_var_fast_sodium_current_j_gate__j = (1.0 - var_chaste_interface__fast_sodium_current_j_gate__j) * ((var_chaste_interface__membrane__V < -40.0) ? ((37.780000000000001 + var_chaste_interface__membrane__V) * (-127140.0 * exp(0.24440000000000001 * var_chaste_interface__membrane__V) - 3.4740000000000003e-5 * exp(-0.043909999999999998 * var_chaste_interface__membrane__V)) / (1.0 + exp(24.640530000000002 + 0.311 * var_chaste_interface__membrane__V))) : (0)) - ((var_chaste_interface__membrane__V < -40.0) ? (0.1212 * exp(-0.01052 * var_chaste_interface__membrane__V) / (1.0 + exp(-5.5312920000000005 - 0.13780000000000001 * var_chaste_interface__membrane__V))) : (0.29999999999999999 * exp(-2.5349999999999999e-7 * var_chaste_interface__membrane__V) / (1.0 + exp(-3.2000000000000002 - 0.10000000000000001 * var_chaste_interface__membrane__V)))) * var_chaste_interface__fast_sodium_current_j_gate__j; // 1 / ms
        const double d_dt_chaste_interface_var_fast_sodium_current_m_gate__m = -0.080000000000000002 * var_chaste_interface__fast_sodium_current_m_gate__m * exp(-0.090909090909090912 * var_chaste_interface__membrane__V) + 0.32000000000000001 * (1.0 - var_chaste_interface__fast_sodium_current_m_gate__m) * (47.130000000000003 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // 1 / ms
        const double var_non_specific_calcium_activated_current__Vns = -26.614641953637257 * log((mParameters[1] + mParameters[2]) / (var_chaste_interface__ionic_concentrations__Ki + var_chaste_interface__ionic_concentrations__Nai)) + var_chaste_interface__membrane__V; // mV
        const double var_non_specific_calcium_activated_current__i_ns_K = 6.3678763853082156e-6 * (-0.75 * mParameters[1] + 0.75 * var_chaste_interface__ionic_concentrations__Ki * exp(0.037573302761014088 * var_non_specific_calcium_activated_current__Vns)) * var_non_specific_calcium_activated_current__Vns / ((1.0 + 1.7279999999999996e-9 / pow(var_chaste_interface__ionic_concentrations__Cai, 3)) * (-1.0 + exp(0.037573302761014088 * var_non_specific_calcium_activated_current__Vns))); // uA_per_mm2
        const double var_non_specific_calcium_activated_current__i_ns_Na = 6.3678763853082156e-6 * (-0.75 * mParameters[2] + 0.75 * var_chaste_interface__ionic_concentrations__Nai * exp(0.037573302761014088 * var_non_specific_calcium_activated_current__Vns)) * var_non_specific_calcium_activated_current__Vns / ((1.0 + 1.7279999999999996e-9 / pow(var_chaste_interface__ionic_concentrations__Cai, 3)) * (-1.0 + exp(0.037573302761014088 * var_non_specific_calcium_activated_current__Vns))); // uA_per_mm2
        const double var_sarcolemmal_calcium_pump__i_p_Ca = 0.0115 * var_chaste_interface__ionic_concentrations__Cai / (0.00050000000000000001 + var_chaste_interface__ionic_concentrations__Cai); // uA_per_mm2
        const double d_dt_chaste_interface_var_ionic_concentrations__Cai = 0.081176470588235281 * var_calcium_fluxes_in_the_SR__i_leak + 0.0015184968096382029 * var_Na_Ca_exchanger__i_NaCa + 0.0070588235294117632 * var_calcium_fluxes_in_the_SR__i_rel - 0.081176470588235281 * var_calcium_fluxes_in_the_SR__i_up - 0.0015184968096382029 * var_L_type_Ca_channel__i_CaCa - 0.0015184968096382029 * var_calcium_background_current__i_Ca_b - 0.0015184968096382029 * var_sarcolemmal_calcium_pump__i_p_Ca; // mM / ms
        const double var_sodium_background_current__i_Na_b = 1.4100000000000001e-5 * var_chaste_interface__membrane__V - 1.4100000000000001e-5 * var_fast_sodium_current__E_Na; // uA_per_mm2
        const double var_sodium_potassium_pump__i_NaK = 0.014999999999999999 * mParameters[1] / ((1.0 + 31.622776601683793 * pow(1 / var_chaste_interface__ionic_concentrations__Nai, 1.5)) * (1.5 + mParameters[1]) * (1.0 + 0.1245 * exp(-0.0037573302761014088 * var_chaste_interface__membrane__V) + 0.036499999999999998 * (-0.14285714285714285 + 0.14285714285714285 * exp(0.01485884101040119 * mParameters[2])) * exp(-0.037573302761014088 * var_chaste_interface__membrane__V))); // uA_per_mm2
        const double d_dt_chaste_interface_var_ionic_concentrations__Nai = -0.0091109808578292168 * var_Na_Ca_exchanger__i_NaCa - 0.0091109808578292168 * var_sodium_potassium_pump__i_NaK - 0.0030369936192764057 * var_L_type_Ca_channel__i_CaNa - 0.0030369936192764057 * var_fast_sodium_current__i_Na - 0.0030369936192764057 * var_non_specific_calcium_activated_current__i_ns_Na - 0.0030369936192764057 * var_sodium_background_current__i_Na_b; // mM / ms
        const double d_dt_chaste_interface_var_time_dependent_potassium_current_X_gate__X = 7.1899999999999999e-5 * (1.0 - var_chaste_interface__time_dependent_potassium_current_X_gate__X) * (30.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * var_chaste_interface__membrane__V)) - 0.00013100000000000001 * (30.0 + var_chaste_interface__membrane__V) * var_chaste_interface__time_dependent_potassium_current_X_gate__X / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * var_chaste_interface__membrane__V)); // 1 / ms
        const double var_time_dependent_potassium_current__i_K = 0.0012135347818116574 * sqrt(mParameters[1]) * pow(var_chaste_interface__time_dependent_potassium_current_X_gate__X, 2) * (-26.614641953637257 * log((0.018329999999999999 * mParameters[2] + mParameters[1]) / (0.018329999999999999 * var_chaste_interface__ionic_concentrations__Nai + var_chaste_interface__ionic_concentrations__Ki)) + var_chaste_interface__membrane__V) / (1.0 + exp(-1.7526479750778814 + 0.031152647975077882 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_time_independent_potassium_current__E_K1 = 26.614641953637257 * log(mParameters[1] / var_chaste_interface__ionic_concentrations__Ki); // mV
        const double var_plateau_potassium_current__i_Kp = 0.000183 * (-var_time_independent_potassium_current__E_K1 + var_chaste_interface__membrane__V) / (1.0 + exp(1.2521739130434781 - 0.16722408026755853 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_time_independent_potassium_current__i_K1 = 0.4389381125701739 * sqrt(mParameters[1]) * (-var_time_independent_potassium_current__E_K1 + var_chaste_interface__membrane__V) * mParameters[5] / ((1.0 + exp(-14.1227775 + 0.23849999999999999 * var_chaste_interface__membrane__V - 0.23849999999999999 * var_time_independent_potassium_current__E_K1)) * (1.02 / (1.0 + exp(-14.1227775 + 0.23849999999999999 * var_chaste_interface__membrane__V - 0.23849999999999999 * var_time_independent_potassium_current__E_K1)) + (0.49124000000000001 * exp(0.43983232 + 0.080320000000000003 * var_chaste_interface__membrane__V - 0.080320000000000003 * var_time_independent_potassium_current__E_K1) + exp(-36.698642499999998 + 0.061749999999999999 * var_chaste_interface__membrane__V - 0.061749999999999999 * var_time_independent_potassium_current__E_K1)) / (1.0 + exp(-2.4444678999999998 + 0.51429999999999998 * var_time_independent_potassium_current__E_K1 - 0.51429999999999998 * var_chaste_interface__membrane__V)))); // uA_per_mm2
        const double d_dt_chaste_interface_var_ionic_concentrations__Ki = 0.0060739872385528115 * var_sodium_potassium_pump__i_NaK - 0.0030369936192764057 * var_L_type_Ca_channel__i_CaK - 0.0030369936192764057 * var_non_specific_calcium_activated_current__i_ns_K - 0.0030369936192764057 * var_plateau_potassium_current__i_Kp - 0.0030369936192764057 * var_time_dependent_potassium_current__i_K - 0.0030369936192764057 * var_time_independent_potassium_current__i_K1; // mM / ms

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_membrane__V = (-var_L_type_Ca_channel__i_CaCa - var_L_type_Ca_channel__i_CaK - var_L_type_Ca_channel__i_CaNa - var_Na_Ca_exchanger__i_NaCa - var_calcium_background_current__i_Ca_b - var_fast_sodium_current__i_Na - var_non_specific_calcium_activated_current__i_ns_K - var_non_specific_calcium_activated_current__i_ns_Na - var_plateau_potassium_current__i_Kp - var_sarcolemmal_calcium_pump__i_p_Ca - var_sodium_background_current__i_Na_b - var_sodium_potassium_pump__i_NaK - var_time_dependent_potassium_current__i_K - var_time_independent_potassium_current__i_K1 - 0.0099999999999999985 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time)) / mParameters[3]; // mV / ms
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rDY[1] = d_dt_chaste_interface_var_ionic_concentrations__Cai;
        rDY[2] = d_dt_chaste_interface_var_fast_sodium_current_m_gate__m;
        rDY[3] = d_dt_chaste_interface_var_fast_sodium_current_h_gate__h;
        rDY[4] = d_dt_chaste_interface_var_fast_sodium_current_j_gate__j;
        rDY[5] = d_dt_chaste_interface_var_L_type_Ca_channel_d_gate__d;
        rDY[6] = d_dt_chaste_interface_var_L_type_Ca_channel_f_gate__f;
        rDY[7] = d_dt_chaste_interface_var_time_dependent_potassium_current_X_gate__X;
        rDY[8] = d_dt_chaste_interface_var_ionic_concentrations__Nai;
        rDY[9] = d_dt_chaste_interface_var_ionic_concentrations__Ki;
        rDY[10] = d_dt_chaste_interface_var_ionic_concentrations__Ca_JSR;
        rDY[11] = d_dt_chaste_interface_var_ionic_concentrations__Ca_NSR;
    }

    std::vector<double> Cellluo_rudy_1994FromCellML::ComputeDerivedQuantities(double var_chaste_interface__environment__time, const std::vector<double> & rY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__fast_sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__ionic_concentrations__Nai = rY[8];
        // Units: mM; Initial value: 10.0
        double var_chaste_interface__ionic_concentrations__Ki = rY[9];
        // Units: mM; Initial value: 145.0
        

        // Mathematics
        const double var_membrane__F = 96845.0; // faradays_constant_units
        const double var_membrane__I_st_converted = -GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_cm2
        const double var_membrane__R = 8314.5; // gas_constant_units
        const double var_membrane__T = 310.0; // kelvin
        const double var_fast_sodium_current__E_Na = var_membrane__R * var_membrane__T * log(mParameters[2] / var_chaste_interface__ionic_concentrations__Nai) / var_membrane__F; // mV
        const double var_fast_sodium_current__i_Na = pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-var_fast_sodium_current__E_Na + var_chaste_interface__membrane__V) * mParameters[4] * var_chaste_interface__fast_sodium_current_h_gate__h * var_chaste_interface__fast_sodium_current_j_gate__j; // uA_per_mm2
        const double var_fast_sodium_current__i_Na_converted = 100.00000000000001 * var_fast_sodium_current__i_Na; // uA_per_cm2
        const double var_time_independent_potassium_current__E_K1 = var_membrane__R * var_membrane__T * log(mParameters[1] / var_chaste_interface__ionic_concentrations__Ki) / var_membrane__F; // mV
        const double var_time_independent_potassium_current__g_K1 = 0.43033148291193518 * sqrt(mParameters[1]) * mParameters[5]; // mS_per_mm2
        const double var_time_independent_potassium_current_K1_gate__alpha_K1 = 1.02 / (1.0 + exp(-14.1227775 + 0.23849999999999999 * var_chaste_interface__membrane__V - 0.23849999999999999 * var_time_independent_potassium_current__E_K1)); // per_ms
        const double var_time_independent_potassium_current_K1_gate__beta_K1 = (0.49124000000000001 * exp(0.43983232 + 0.080320000000000003 * var_chaste_interface__membrane__V - 0.080320000000000003 * var_time_independent_potassium_current__E_K1) + exp(-36.698642499999998 + 0.061749999999999999 * var_chaste_interface__membrane__V - 0.061749999999999999 * var_time_independent_potassium_current__E_K1)) / (1.0 + exp(-2.4444678999999998 + 0.51429999999999998 * var_time_independent_potassium_current__E_K1 - 0.51429999999999998 * var_chaste_interface__membrane__V)); // per_ms
        const double var_time_independent_potassium_current_K1_gate__K1_infinity = var_time_independent_potassium_current_K1_gate__alpha_K1 / (var_time_independent_potassium_current_K1_gate__alpha_K1 + var_time_independent_potassium_current_K1_gate__beta_K1); // dimensionless
        const double var_time_independent_potassium_current__i_K1 = (-var_time_independent_potassium_current__E_K1 + var_chaste_interface__membrane__V) * var_time_independent_potassium_current__g_K1 * var_time_independent_potassium_current_K1_gate__K1_infinity; // uA_per_mm2
        const double var_time_independent_potassium_current__i_K1_converted = 100.00000000000001 * var_time_independent_potassium_current__i_K1; // uA_per_cm2

        std::vector<double> dqs(4);
        dqs[0] = var_fast_sodium_current__i_Na_converted;
        dqs[1] = var_time_independent_potassium_current__i_K1_converted;
        dqs[2] = var_membrane__I_st_converted;
        dqs[3] = var_chaste_interface__environment__time;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellluo_rudy_1994FromCellML>::Initialise(void)
{
    this->mSystemName = "luo_rudy_1994";
    this->mFreeVariableName = "time";
    this->mFreeVariableUnits = "ms";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("mV");
    this->mInitialConditions.push_back(-84.624);

    // rY[1]:
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(0.00012);

    // rY[2]:
    this->mVariableNames.push_back("fast_sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[3]:
    this->mVariableNames.push_back("fast_sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[4]:
    this->mVariableNames.push_back("fast_sodium_current_j_gate__j");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[5]:
    this->mVariableNames.push_back("L_type_Ca_channel_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[6]:
    this->mVariableNames.push_back("L_type_Ca_channel_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[7]:
    this->mVariableNames.push_back("time_dependent_potassium_current_X_gate__X");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[8]:
    this->mVariableNames.push_back("cytosolic_sodium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(10.0);

    // rY[9]:
    this->mVariableNames.push_back("cytosolic_potassium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(145.0);

    // rY[10]:
    this->mVariableNames.push_back("JSR_calcium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(1.8);

    // rY[11]:
    this->mVariableNames.push_back("NSR_calcium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(1.8);

    // mParameters[0]:
    this->mParameterNames.push_back("extracellular_calcium_concentration");
    this->mParameterUnits.push_back("mM");

    // mParameters[1]:
    this->mParameterNames.push_back("extracellular_potassium_concentration");
    this->mParameterUnits.push_back("mM");

    // mParameters[2]:
    this->mParameterNames.push_back("extracellular_sodium_concentration");
    this->mParameterUnits.push_back("mM");

    // mParameters[3]:
    this->mParameterNames.push_back("membrane_capacitance");
    this->mParameterUnits.push_back("uF_per_mm2");

    // mParameters[4]:
    this->mParameterNames.push_back("membrane_fast_sodium_current_conductance");
    this->mParameterUnits.push_back("mS_per_mm2");

    // mParameters[5]:
    this->mParameterNames.push_back("membrane_inward_rectifier_potassium_current_conductance");
    this->mParameterUnits.push_back("mS_per_mm2");

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("membrane_fast_sodium_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("membrane_inward_rectifier_potassium_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [2]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [3]:
    this->mDerivedQuantityNames.push_back("time");
    this->mDerivedQuantityUnits.push_back("ms");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellluo_rudy_1994FromCellML)
