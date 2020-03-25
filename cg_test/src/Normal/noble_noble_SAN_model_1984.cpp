//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: NN_SAN_model_1984
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on 2020-03-25 17:30:59
//!
//! <autogenerated>

#include "noble_noble_SAN_model_1984.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"



    double Cellnoble_noble_SAN_model_1984FromCellML::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    Cellnoble_noble_SAN_model_1984FromCellML::Cellnoble_noble_SAN_model_1984FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                15,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellnoble_noble_SAN_model_1984FromCellML>::Instance();
        Init();
        
    }

    Cellnoble_noble_SAN_model_1984FromCellML::~Cellnoble_noble_SAN_model_1984FromCellML()
    {
    }
    
    double Cellnoble_noble_SAN_model_1984FromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -60.0
        double var_chaste_interface__intracellular_calcium_concentration__Cai = rY[1];
        // Units: millimolar; Initial value: 5.8e-05
        double var_chaste_interface__hyperpolarising_activated_current_y_gate__y = rY[2];
        // Units: dimensionless; Initial value: 0.007
        double var_chaste_interface__time_dependent_potassium_current_x_gate__x = rY[3];
        // Units: dimensionless; Initial value: 0.54
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[4];
        // Units: dimensionless; Initial value: 0.076
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[5];
        // Units: dimensionless; Initial value: 0.015
        double var_chaste_interface__second_inward_current_d_gate__d = rY[6];
        // Units: dimensionless; Initial value: 0.0011
        double var_chaste_interface__second_inward_current_f_gate__f = rY[7];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__second_inward_current_f2_gate__f2 = rY[8];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__intracellular_sodium_concentration__Nai = rY[9];
        // Units: millimolar; Initial value: 7.5
        double var_chaste_interface__extracellular_potassium_concentration__Kc = rY[13];
        // Units: millimolar; Initial value: 3.0
        double var_chaste_interface__intracellular_potassium_concentration__Ki = rY[14];
        // Units: millimolar; Initial value: 140.0
        
        const double var_hyperpolarising_activated_current__E_K = 26.713760659695652 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki); // millivolt
        const double var_hyperpolarising_activated_current__E_Na = 26.713760659695652 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Nai); // millivolt
        const double var_Na_Ca_exchanger__i_NaCa = 0.002 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Nai, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Cai * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Cai) * (1.0 + 0.00020000000000000001 * pow(var_chaste_interface__intracellular_sodium_concentration__Nai, 3.0) + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Cai)); // nanoA
        const double var_calcium_background_current__i_Ca_b = 0.01 * var_chaste_interface__membrane__V - 0.13356880329847826 * log(2.0 / var_chaste_interface__intracellular_calcium_concentration__Cai); // nanoA
        const double var_fast_sodium_current__i_Na = 1.25 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-26.713760659695652 * log((140.0 + 0.12 * var_chaste_interface__extracellular_potassium_concentration__Kc) / (1.0 * var_chaste_interface__intracellular_sodium_concentration__Nai + 0.12 * var_chaste_interface__intracellular_potassium_concentration__Ki)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h; // nanoA
        const double var_hyperpolarising_activated_current__i_f = 6.0 * (-var_hyperpolarising_activated_current__E_K + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__hyperpolarising_activated_current_y_gate__y / (45.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) + 6.0 * (-var_hyperpolarising_activated_current__E_Na + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__hyperpolarising_activated_current_y_gate__y / (45.0 + var_chaste_interface__extracellular_potassium_concentration__Kc); // nanoA
        const double var_second_inward_current__i_si = 1.1230167246823641 * (-50.0 + var_chaste_interface__membrane__V) * (-2.0 * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_calcium_concentration__Cai * exp(3.7433890822745473)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)) + 0.0028075418117059106 * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Nai * exp(1.8716945411372736)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) + 0.0028075418117059106 * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - var_chaste_interface__extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // nanoA
        const double var_sodium_background_current__i_Na_b = 0.070000000000000007 * var_chaste_interface__membrane__V - 0.070000000000000007 * var_hyperpolarising_activated_current__E_Na; // nanoA
        const double var_sodium_potassium_pump__i_p = 50.0 * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__intracellular_sodium_concentration__Nai / ((1.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) * (40.0 + var_chaste_interface__intracellular_sodium_concentration__Nai)); // nanoA
        const double var_time_dependent_potassium_current__i_K = (0.14285714285714285 * var_chaste_interface__intracellular_potassium_concentration__Ki - 0.14285714285714285 * var_chaste_interface__extracellular_potassium_concentration__Kc * exp(-0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_potassium_current_x_gate__x; // nanoA
        const double var_time_independent_potassium_current__i_K1 = 0.75 * (-var_hyperpolarising_activated_current__E_K + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc / ((1.0 + exp(0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 0.074867781645490947 * var_hyperpolarising_activated_current__E_K)) * (10.0 + var_chaste_interface__extracellular_potassium_concentration__Kc)); // nanoA
        const double var_chaste_interface__i_ionic = 166.66666666666666 * (0.001 * var_Na_Ca_exchanger__i_NaCa + 0.001 * var_calcium_background_current__i_Ca_b + 0.001 * var_fast_sodium_current__i_Na + 0.001 * var_hyperpolarising_activated_current__i_f + 0.001 * var_second_inward_current__i_si + 0.001 * var_sodium_background_current__i_Na_b + 0.001 * var_sodium_potassium_pump__i_p + 0.001 * var_time_dependent_potassium_current__i_K + 0.001 * var_time_independent_potassium_current__i_K1) * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellnoble_noble_SAN_model_1984FromCellML::EvaluateYDerivatives(double var_chaste_interface__environment__time_converted, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -60.0
        double var_chaste_interface__intracellular_calcium_concentration__Cai = rY[1];
        // Units: millimolar; Initial value: 5.8e-05
        double var_chaste_interface__hyperpolarising_activated_current_y_gate__y = rY[2];
        // Units: dimensionless; Initial value: 0.007
        double var_chaste_interface__time_dependent_potassium_current_x_gate__x = rY[3];
        // Units: dimensionless; Initial value: 0.54
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[4];
        // Units: dimensionless; Initial value: 0.076
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[5];
        // Units: dimensionless; Initial value: 0.015
        double var_chaste_interface__second_inward_current_d_gate__d = rY[6];
        // Units: dimensionless; Initial value: 0.0011
        double var_chaste_interface__second_inward_current_f_gate__f = rY[7];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__second_inward_current_f2_gate__f2 = rY[8];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__intracellular_sodium_concentration__Nai = rY[9];
        // Units: millimolar; Initial value: 7.5
        double var_chaste_interface__intracellular_calcium_concentration__Ca_up = rY[10];
        // Units: millimolar; Initial value: 1.98
        double var_chaste_interface__intracellular_calcium_concentration__Ca_rel = rY[11];
        // Units: millimolar; Initial value: 0.55
        double var_chaste_interface__intracellular_calcium_concentration__p = rY[12];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__extracellular_potassium_concentration__Kc = rY[13];
        // Units: millimolar; Initial value: 3.0
        double var_chaste_interface__intracellular_potassium_concentration__Ki = rY[14];
        // Units: millimolar; Initial value: 140.0

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_intracellular_calcium_concentration__i_rel = 558.70643418638997 * pow(var_chaste_interface__intracellular_calcium_concentration__Cai, 2.0) * var_chaste_interface__intracellular_calcium_concentration__Ca_rel / (3.9999999999999998e-6 + pow(var_chaste_interface__intracellular_calcium_concentration__Cai, 2.0)); // nanoA
        const double var_intracellular_calcium_concentration__i_tr = 27.935321709319496 * (-var_chaste_interface__intracellular_calcium_concentration__Ca_rel + var_chaste_interface__intracellular_calcium_concentration__Ca_up) * var_chaste_interface__intracellular_calcium_concentration__p; // nanoA
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel = 0.00017898487270085568 * var_intracellular_calcium_concentration__i_tr - 0.00017898487270085568 * var_intracellular_calcium_concentration__i_rel; // millimolar / millisecond
        const double var_intracellular_calcium_concentration__i_up = 11174.128683727798 * (5.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_up) * var_chaste_interface__intracellular_calcium_concentration__Cai; // nanoA
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up = 7.1593949080342261e-5 * var_intracellular_calcium_concentration__i_up - 7.1593949080342261e-5 * var_intracellular_calcium_concentration__i_tr; // millimolar / millisecond
        const double var_hyperpolarising_activated_current__E_K = 26.713760659695652 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki); // millivolt
        const double var_hyperpolarising_activated_current__E_Na = 26.713760659695652 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Nai); // millivolt
        const double var_Na_Ca_exchanger__i_NaCa = 0.002 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Nai, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Cai * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Cai) * (1.0 + 0.00020000000000000001 * pow(var_chaste_interface__intracellular_sodium_concentration__Nai, 3.0) + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Cai)); // nanoA
        const double var_calcium_background_current__i_Ca_b = 0.01 * var_chaste_interface__membrane__V - 0.13356880329847826 * log(2.0 / var_chaste_interface__intracellular_calcium_concentration__Cai); // nanoA
        const double var_fast_sodium_current__i_Na = 1.25 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-26.713760659695652 * log((140.0 + 0.12 * var_chaste_interface__extracellular_potassium_concentration__Kc) / (1.0 * var_chaste_interface__intracellular_sodium_concentration__Nai + 0.12 * var_chaste_interface__intracellular_potassium_concentration__Ki)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h; // nanoA
        const double d_dt_chaste_interface_var_fast_sodium_current_h_gate__h = 0.02 * (1.0 - var_chaste_interface__fast_sodium_current_h_gate__h) * exp(-9.375 - 0.125 * var_chaste_interface__membrane__V) - 2.0 * var_chaste_interface__fast_sodium_current_h_gate__h / (1.0 + 320.0 * exp(-7.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // 1 / millisecond
        const double d_dt_chaste_interface_var_fast_sodium_current_m_gate__m = ((fabs(41.0 + var_chaste_interface__membrane__V) < 1.0000000000000001e-5) ? (2.0 - 2.0 * var_chaste_interface__fast_sodium_current_m_gate__m - 8.0 * var_chaste_interface__fast_sodium_current_m_gate__m * exp(-3.6960000000000002 - 0.056000000000000001 * var_chaste_interface__membrane__V)) : (-8.0 * var_chaste_interface__fast_sodium_current_m_gate__m * exp(-3.6960000000000002 - 0.056000000000000001 * var_chaste_interface__membrane__V) + 0.20000000000000001 * (1.0 - var_chaste_interface__fast_sodium_current_m_gate__m) * (41.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * var_chaste_interface__membrane__V)))); // 1 / millisecond
        const double var_hyperpolarising_activated_current__i_fK = 6.0 * (-var_hyperpolarising_activated_current__E_K + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__hyperpolarising_activated_current_y_gate__y / (45.0 + var_chaste_interface__extracellular_potassium_concentration__Kc); // nanoA
        const double var_hyperpolarising_activated_current__i_fNa = 6.0 * (-var_hyperpolarising_activated_current__E_Na + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__hyperpolarising_activated_current_y_gate__y / (45.0 + var_chaste_interface__extracellular_potassium_concentration__Kc); // nanoA
        const double var_hyperpolarising_activated_current_y_gate__E0_y = 52.0 + var_chaste_interface__membrane__V; // millivolt
        const double d_dt_chaste_interface_var_hyperpolarising_activated_current_y_gate__y = ((fabs(var_hyperpolarising_activated_current_y_gate__E0_y) < 1.0000000000000001e-5) ? (-0.0050000000000000001 * var_chaste_interface__hyperpolarising_activated_current_y_gate__y + 0.0001 * (1.0 - var_chaste_interface__hyperpolarising_activated_current_y_gate__y) * exp(-0.067000000000000004 * var_hyperpolarising_activated_current_y_gate__E0_y)) : (0.0001 * (1.0 - var_chaste_interface__hyperpolarising_activated_current_y_gate__y) * exp(-0.067000000000000004 * var_hyperpolarising_activated_current_y_gate__E0_y) - 0.002 * var_hyperpolarising_activated_current_y_gate__E0_y * var_chaste_interface__hyperpolarising_activated_current_y_gate__y / (1.0 - 1.0 * exp(-0.20000000000000001 * var_hyperpolarising_activated_current_y_gate__E0_y)))); // 1 / millisecond
        const double var_intracellular_calcium_concentration__E0_p = 64.0 + var_chaste_interface__membrane__V; // millivolt
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__p = -0.0050000000000000001 * var_chaste_interface__intracellular_calcium_concentration__p / (1.0 + exp(-0.25 * var_intracellular_calcium_concentration__E0_p)) + 0.00062500000000000001 * (1.0 - var_chaste_interface__intracellular_calcium_concentration__p) * var_intracellular_calcium_concentration__E0_p / (-1.0 + exp(0.25 * var_intracellular_calcium_concentration__E0_p)); // 1 / millisecond
        const double var_second_inward_current_d_gate__E0_d = 19.0 + var_chaste_interface__membrane__V; // millivolt
        const double d_dt_chaste_interface_var_second_inward_current_d_gate__d = ((fabs(var_second_inward_current_d_gate__E0_d) < 0.0001) ? (0.12 - 0.23999999999999999 * var_chaste_interface__second_inward_current_d_gate__d) : (0.029999999999999999 * (1.0 - var_chaste_interface__second_inward_current_d_gate__d) * var_second_inward_current_d_gate__E0_d / (1.0 - exp(-0.25 * var_second_inward_current_d_gate__E0_d)) - 0.012 * var_second_inward_current_d_gate__E0_d * var_chaste_interface__second_inward_current_d_gate__d / (-1.0 + exp(0.10000000000000001 * var_second_inward_current_d_gate__E0_d)))); // 1 / millisecond
        const double d_dt_chaste_interface_var_second_inward_current_f2_gate__f2 = 0.01 - 0.001 * (10.0 + 20000.0 * var_chaste_interface__intracellular_calcium_concentration__Cai) * var_chaste_interface__second_inward_current_f2_gate__f2; // 1 / millisecond
        const double var_second_inward_current__i_siCa = 1.1230167246823641 * (-50.0 + var_chaste_interface__membrane__V) * (-2.0 * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_calcium_concentration__Cai * exp(3.7433890822745473)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)); // nanoA
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Cai = 3.5796974540171135e-6 * var_intracellular_calcium_concentration__i_rel + 7.1593949080342271e-6 * var_Na_Ca_exchanger__i_NaCa - 3.5796974540171135e-6 * var_calcium_background_current__i_Ca_b - 3.5796974540171135e-6 * var_intracellular_calcium_concentration__i_up - 3.5796974540171135e-6 * var_second_inward_current__i_siCa; // millimolar / millisecond
        const double var_second_inward_current__i_siK = 0.0028075418117059106 * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - var_chaste_interface__extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // nanoA
        const double var_second_inward_current__i_siNa = 0.0028075418117059106 * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Nai * exp(1.8716945411372736)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // nanoA
        const double d_dt_chaste_interface_var_second_inward_current_f_gate__f = ((fabs(34.0 + var_chaste_interface__membrane__V) < 0.0001) ? (0.025000000000000001 - 0.025000000000000001 * var_chaste_interface__second_inward_current_f_gate__f - 0.050000000000000003 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 + exp(-8.5 - 0.25 * var_chaste_interface__membrane__V))) : (-0.050000000000000003 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 + exp(-8.5 - 0.25 * var_chaste_interface__membrane__V)) + 0.0062500000000000003 * (1.0 - var_chaste_interface__second_inward_current_f_gate__f) * (34.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(8.5 + 0.25 * var_chaste_interface__membrane__V)))); // 1 / millisecond
        const double var_sodium_background_current__i_Na_b = 0.070000000000000007 * var_chaste_interface__membrane__V - 0.070000000000000007 * var_hyperpolarising_activated_current__E_Na; // nanoA
        const double var_sodium_potassium_pump__i_p = 50.0 * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__intracellular_sodium_concentration__Nai / ((1.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) * (40.0 + var_chaste_interface__intracellular_sodium_concentration__Nai)); // nanoA
        const double d_dt_chaste_interface_var_intracellular_sodium_concentration__Nai = -2.147818472410268e-5 * var_Na_Ca_exchanger__i_NaCa - 2.147818472410268e-5 * var_sodium_potassium_pump__i_p - 7.1593949080342271e-6 * var_fast_sodium_current__i_Na - 7.1593949080342271e-6 * var_hyperpolarising_activated_current__i_fNa - 7.1593949080342271e-6 * var_second_inward_current__i_siNa - 7.1593949080342271e-6 * var_sodium_background_current__i_Na_b; // millimolar / millisecond
        const double var_time_dependent_potassium_current_x_gate__E0_x = 22.0 + var_chaste_interface__membrane__V; // millivolt
        const double var_time_dependent_potassium_current__i_K = (0.14285714285714285 * var_chaste_interface__intracellular_potassium_concentration__Ki - 0.14285714285714285 * var_chaste_interface__extracellular_potassium_concentration__Kc * exp(-0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_potassium_current_x_gate__x; // nanoA
        const double d_dt_chaste_interface_var_time_dependent_potassium_current_x_gate__x = ((fabs(var_time_dependent_potassium_current_x_gate__E0_x) < 0.0001) ? (0.0025000000000000001 - 0.0050000000000000001 * var_chaste_interface__time_dependent_potassium_current_x_gate__x) : (0.00050000000000000001 * (1.0 - var_chaste_interface__time_dependent_potassium_current_x_gate__x) * var_time_dependent_potassium_current_x_gate__E0_x / (1.0 - exp(-0.20000000000000001 * var_time_dependent_potassium_current_x_gate__E0_x)) - 0.00017799999999999999 * var_time_dependent_potassium_current_x_gate__E0_x * var_chaste_interface__time_dependent_potassium_current_x_gate__x / (-1.0 + exp(0.066666666666666666 * var_time_dependent_potassium_current_x_gate__E0_x)))); // 1 / millisecond
        const double var_time_independent_potassium_current__i_K1 = 0.75 * (-var_hyperpolarising_activated_current__E_K + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc / ((1.0 + exp(0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 0.074867781645490947 * var_hyperpolarising_activated_current__E_K)) * (10.0 + var_chaste_interface__extracellular_potassium_concentration__Kc)); // nanoA
        const double var_extracellular_potassium_concentration__i_mK = -2.0 * var_sodium_potassium_pump__i_p + var_hyperpolarising_activated_current__i_fK + var_second_inward_current__i_siK + var_time_dependent_potassium_current__i_K + var_time_independent_potassium_current__i_K1; // nanoA
        const double d_dt_chaste_interface_var_extracellular_potassium_concentration__Kc = 0.0030000000000000001 + 6.4466434341209093e-5 * var_extracellular_potassium_concentration__i_mK - 0.001 * var_chaste_interface__extracellular_potassium_concentration__Kc; // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_potassium_concentration__Ki = -7.1593949080342271e-6 * var_extracellular_potassium_concentration__i_mK; // millimolar / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_membrane__V = -0.16666666666666666 * var_Na_Ca_exchanger__i_NaCa - 0.16666666666666666 * var_calcium_background_current__i_Ca_b - 0.16666666666666666 * var_fast_sodium_current__i_Na - 0.16666666666666666 * var_hyperpolarising_activated_current__i_fK - 0.16666666666666666 * var_hyperpolarising_activated_current__i_fNa - 0.16666666666666666 * var_second_inward_current__i_siCa - 0.16666666666666666 * var_second_inward_current__i_siK - 0.16666666666666666 * var_second_inward_current__i_siNa - 0.16666666666666666 * var_sodium_background_current__i_Na_b - 0.16666666666666666 * var_sodium_potassium_pump__i_p - 0.16666666666666666 * var_time_dependent_potassium_current__i_K - 0.16666666666666666 * var_time_independent_potassium_current__i_K1; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rDY[1] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Cai;
        rDY[2] = d_dt_chaste_interface_var_hyperpolarising_activated_current_y_gate__y;
        rDY[3] = d_dt_chaste_interface_var_time_dependent_potassium_current_x_gate__x;
        rDY[4] = d_dt_chaste_interface_var_fast_sodium_current_m_gate__m;
        rDY[5] = d_dt_chaste_interface_var_fast_sodium_current_h_gate__h;
        rDY[6] = d_dt_chaste_interface_var_second_inward_current_d_gate__d;
        rDY[7] = d_dt_chaste_interface_var_second_inward_current_f_gate__f;
        rDY[8] = d_dt_chaste_interface_var_second_inward_current_f2_gate__f2;
        rDY[9] = d_dt_chaste_interface_var_intracellular_sodium_concentration__Nai;
        rDY[10] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up;
        rDY[11] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel;
        rDY[12] = d_dt_chaste_interface_var_intracellular_calcium_concentration__p;
        rDY[13] = d_dt_chaste_interface_var_extracellular_potassium_concentration__Kc;
        rDY[14] = d_dt_chaste_interface_var_intracellular_potassium_concentration__Ki;
    }

template<>
void OdeSystemInformation<Cellnoble_noble_SAN_model_1984FromCellML>::Initialise(void)
{
    this->mSystemName = "NN_SAN_model_1984";
    this->mFreeVariableName = "environment__time_converted";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-60.0);

    // rY[1]:
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(5.8e-05);

    // rY[2]:
    this->mVariableNames.push_back("hyperpolarising_activated_current_y_gate__y");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.007);

    // rY[3]:
    this->mVariableNames.push_back("time_dependent_potassium_current_x_gate__x");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.54);

    // rY[4]:
    this->mVariableNames.push_back("fast_sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.076);

    // rY[5]:
    this->mVariableNames.push_back("fast_sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.015);

    // rY[6]:
    this->mVariableNames.push_back("second_inward_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0011);

    // rY[7]:
    this->mVariableNames.push_back("second_inward_current_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.785);

    // rY[8]:
    this->mVariableNames.push_back("second_inward_current_f2_gate__f2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.785);

    // rY[9]:
    this->mVariableNames.push_back("intracellular_sodium_concentration__Nai");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(7.5);

    // rY[10]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_up");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(1.98);

    // rY[11]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_rel");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.55);

    // rY[12]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__p");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.785);

    // rY[13]:
    this->mVariableNames.push_back("extracellular_potassium_concentration__Kc");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(3.0);

    // rY[14]:
    this->mVariableNames.push_back("intracellular_potassium_concentration__Ki");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(140.0);

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellnoble_noble_SAN_model_1984FromCellML)
