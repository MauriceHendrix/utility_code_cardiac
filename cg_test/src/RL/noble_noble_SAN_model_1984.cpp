//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: NN_SAN_model_1984
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on 2020-04-09 01:29:30
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



    double Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen::Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractRushLarsenCardiacCell(
                15,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen>::Instance();
        Init();
        
    }

    Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen::~Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen()
    {
    }
    
    double Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen::GetIIonic(const std::vector<double>* pStateVariables)
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

    void Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen::EvaluateEquations(double var_chaste_interface__environment__time_converted, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
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
        const double var_hyperpolarising_activated_current_y_gate__speed_y = 2.0; // dimensionless
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel = 0.0050000000000000001 * (-var_chaste_interface__intracellular_calcium_concentration__Ca_rel + var_chaste_interface__intracellular_calcium_concentration__Ca_up) * var_chaste_interface__intracellular_calcium_concentration__p - 0.10000000000000001 * pow(var_chaste_interface__intracellular_calcium_concentration__Cai, 2.0) * var_chaste_interface__intracellular_calcium_concentration__Ca_rel / (3.9999999999999998e-6 + pow(var_chaste_interface__intracellular_calcium_concentration__Cai, 2.0)); // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up = 0.79999999999999993 * (5.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_up) * var_chaste_interface__intracellular_calcium_concentration__Cai - 0.002 * (-var_chaste_interface__intracellular_calcium_concentration__Ca_rel + var_chaste_interface__intracellular_calcium_concentration__Ca_up) * var_chaste_interface__intracellular_calcium_concentration__p; // millimolar / millisecond
        const double var_fast_sodium_current_h_gate__alpha_h = 20.0 * exp(-9.375 - 0.125 * var_chaste_interface__membrane__V); // per_second
        const double var_fast_sodium_current_h_gate__beta_h = 2000.0 / (1.0 + 320.0 * exp(-7.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // per_second
        const double var_fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + var_chaste_interface__membrane__V) < 1.0000000000000001e-5) ? (2000.0) : (200.0 * (41.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * var_chaste_interface__membrane__V)))); // per_second
        const double var_fast_sodium_current_m_gate__beta_m = 8000.0 * exp(-3.6960000000000002 - 0.056000000000000001 * var_chaste_interface__membrane__V); // per_second
        const double var_hyperpolarising_activated_current_y_gate__alpha_y = 0.050000000000000003 * exp(-3.484 - 0.067000000000000004 * var_chaste_interface__membrane__V); // per_second
        const double var_hyperpolarising_activated_current_y_gate__beta_y = ((fabs(52.0 + var_chaste_interface__membrane__V) < 1.0000000000000001e-5) ? (2.5) : ((52.0 + var_chaste_interface__membrane__V) / (1.0 - 1.0 * exp(-10.4 - 0.20000000000000001 * var_chaste_interface__membrane__V)))); // per_second
        const double var_intracellular_calcium_concentration__alpha_p = 0.625 * (64.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(16.0 + 0.25 * var_chaste_interface__membrane__V)); // per_second
        const double var_intracellular_calcium_concentration__beta_p = 5.0 / (1.0 + exp(-16.0 - 0.25 * var_chaste_interface__membrane__V)); // per_second
        const double var_second_inward_current_d_gate__alpha_d = ((fabs(19.0 + var_chaste_interface__membrane__V) < 0.0001) ? (120.0) : (30.0 * (19.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.75 - 0.25 * var_chaste_interface__membrane__V)))); // per_second
        const double var_second_inward_current_d_gate__beta_d = ((fabs(19.0 + var_chaste_interface__membrane__V) < 0.0001) ? (120.0) : (12.0 * (19.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * var_chaste_interface__membrane__V)))); // per_second
        const double d_dt_chaste_interface_var_second_inward_current_f2_gate__f2 = 0.01 - 0.001 * (10.0 + 20000.0 * var_chaste_interface__intracellular_calcium_concentration__Cai) * var_chaste_interface__second_inward_current_f2_gate__f2; // 1 / millisecond
        const double var_second_inward_current_f_gate__beta_f = 50.0 / (1.0 + exp(-8.5 - 0.25 * var_chaste_interface__membrane__V)); // per_second
        const double var_second_inward_current_f_gate__alpha_f = ((fabs(34.0 + var_chaste_interface__membrane__V) < 0.0001) ? (25.0) : (6.25 * (34.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(8.5 + 0.25 * var_chaste_interface__membrane__V)))); // per_second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Cai = 4.7813590510367518e-7 * log(2.0 / var_chaste_interface__intracellular_calcium_concentration__Cai) - 3.5796974540171133e-8 * var_chaste_interface__membrane__V - 0.040000000000000001 * (5.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_up) * var_chaste_interface__intracellular_calcium_concentration__Cai + 0.002 * pow(var_chaste_interface__intracellular_calcium_concentration__Cai, 2.0) * var_chaste_interface__intracellular_calcium_concentration__Ca_rel / (3.9999999999999998e-6 + pow(var_chaste_interface__intracellular_calcium_concentration__Cai, 2.0)) + 1.4318789816068455e-8 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Nai, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Cai * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Cai) * (1.0 + 0.00020000000000000001 * pow(var_chaste_interface__intracellular_sodium_concentration__Nai, 3.0) + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Cai)) - 4.0200601101640967e-6 * (-50.0 + var_chaste_interface__membrane__V) * (-2.0 * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_calcium_concentration__Cai * exp(3.7433890822745473)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)); // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_sodium_concentration__Nai = 1.3387805342902908e-5 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Nai) - 5.0115764356239594e-7 * var_chaste_interface__membrane__V - 8.9492436350427843e-6 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-26.713760659695652 * log((140.0 + 0.12 * var_chaste_interface__extracellular_potassium_concentration__Kc) / (1.0 * var_chaste_interface__intracellular_sodium_concentration__Nai + 0.12 * var_chaste_interface__intracellular_potassium_concentration__Ki)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h - 4.2956369448205359e-8 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Nai, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Cai * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Cai) * (1.0 + 0.00020000000000000001 * pow(var_chaste_interface__intracellular_sodium_concentration__Nai, 3.0) + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Cai)) - 0.0010739092362051341 * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__intracellular_sodium_concentration__Nai / ((1.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) * (40.0 + var_chaste_interface__intracellular_sodium_concentration__Nai)) - 4.2956369448205359e-5 * (-26.713760659695652 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Nai) + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__hyperpolarising_activated_current_y_gate__y / (45.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) - 2.0100300550820484e-8 * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Nai * exp(1.8716945411372736)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // millimolar / millisecond
        const double var_time_dependent_potassium_current_x_gate__alpha_x = ((fabs(22.0 + var_chaste_interface__membrane__V) < 0.0001) ? (2.5) : (0.5 * (22.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.4000000000000004 - 0.20000000000000001 * var_chaste_interface__membrane__V)))); // per_second
        const double var_time_dependent_potassium_current_x_gate__beta_x = ((fabs(22.0 + var_chaste_interface__membrane__V) < 0.0001) ? (2.5) : (0.17799999999999999 * (22.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(1.4666666666666666 + 0.066666666666666666 * var_chaste_interface__membrane__V)))); // per_second
        const double d_dt_chaste_interface_var_extracellular_potassium_concentration__Kc = 0.0030000000000000001 - 0.001 * var_chaste_interface__extracellular_potassium_concentration__Kc + 6.4466434341209093e-5 * (0.14285714285714285 * var_chaste_interface__intracellular_potassium_concentration__Ki - 0.14285714285714285 * var_chaste_interface__extracellular_potassium_concentration__Kc * exp(-0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_potassium_current_x_gate__x + 4.8349825755906823e-5 * (-26.713760659695652 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki) + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc / ((1.0 + exp(0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 2.0 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki))) * (10.0 + var_chaste_interface__extracellular_potassium_concentration__Kc)) + 0.00038679860604725458 * (-26.713760659695652 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki) + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__hyperpolarising_activated_current_y_gate__y / (45.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) - 0.0064466434341209095 * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__intracellular_sodium_concentration__Nai / ((1.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) * (40.0 + var_chaste_interface__intracellular_sodium_concentration__Nai)) + 1.8099220986453831e-7 * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - var_chaste_interface__extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_potassium_concentration__Ki = -7.1593949080342271e-6 * (0.14285714285714285 * var_chaste_interface__intracellular_potassium_concentration__Ki - 0.14285714285714285 * var_chaste_interface__extracellular_potassium_concentration__Kc * exp(-0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_potassium_current_x_gate__x + 0.00071593949080342272 * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__intracellular_sodium_concentration__Nai / ((1.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) * (40.0 + var_chaste_interface__intracellular_sodium_concentration__Nai)) - 5.3695461810256699e-6 * (-26.713760659695652 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki) + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc / ((1.0 + exp(0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 2.0 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki))) * (10.0 + var_chaste_interface__extracellular_potassium_concentration__Kc)) - 4.2956369448205359e-5 * (-26.713760659695652 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki) + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__hyperpolarising_activated_current_y_gate__y / (45.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) - 2.0100300550820484e-8 * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - var_chaste_interface__extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // millimolar / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_membrane__V = 0.31166054102978263 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Nai) + 0.02226146721641304 * log(2.0 / var_chaste_interface__intracellular_calcium_concentration__Cai) - 0.013333333333333334 * var_chaste_interface__membrane__V - 0.16666666666666666 * (0.14285714285714285 * var_chaste_interface__intracellular_potassium_concentration__Ki - 0.14285714285714285 * var_chaste_interface__extracellular_potassium_concentration__Kc * exp(-0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_potassium_current_x_gate__x - 0.20833333333333334 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-26.713760659695652 * log((140.0 + 0.12 * var_chaste_interface__extracellular_potassium_concentration__Kc) / (1.0 * var_chaste_interface__intracellular_sodium_concentration__Nai + 0.12 * var_chaste_interface__intracellular_potassium_concentration__Ki)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h - 0.00033333333333333332 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Nai, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Cai * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Cai) * (1.0 + 0.00020000000000000001 * pow(var_chaste_interface__intracellular_sodium_concentration__Nai, 3.0) + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Cai)) - 8.3333333333333339 * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__intracellular_sodium_concentration__Nai / ((1.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) * (40.0 + var_chaste_interface__intracellular_sodium_concentration__Nai)) - 0.125 * (-26.713760659695652 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki) + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc / ((1.0 + exp(0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 2.0 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki))) * (10.0 + var_chaste_interface__extracellular_potassium_concentration__Kc)) - 1.0 * (-26.713760659695652 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Nai) + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__hyperpolarising_activated_current_y_gate__y / (45.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) - 1.0 * (-26.713760659695652 * log(var_chaste_interface__extracellular_potassium_concentration__Kc / var_chaste_interface__intracellular_potassium_concentration__Ki) + var_chaste_interface__membrane__V) * var_chaste_interface__extracellular_potassium_concentration__Kc * var_chaste_interface__hyperpolarising_activated_current_y_gate__y / (45.0 + var_chaste_interface__extracellular_potassium_concentration__Kc) - 0.0004679236352843184 * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Nai * exp(1.8716945411372736)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) - 0.0004679236352843184 * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_potassium_concentration__Ki * exp(1.8716945411372736) - var_chaste_interface__extracellular_potassium_concentration__Kc * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) - 0.18716945411372735 * (-50.0 + var_chaste_interface__membrane__V) * (-2.0 * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_calcium_concentration__Cai * exp(3.7433890822745473)) * var_chaste_interface__second_inward_current_d_gate__d * var_chaste_interface__second_inward_current_f2_gate__f2 * var_chaste_interface__second_inward_current_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)); // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rDY[1] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Cai;
        rAlphaOrTau[2] = 0.001 * var_hyperpolarising_activated_current_y_gate__alpha_y * var_hyperpolarising_activated_current_y_gate__speed_y;
        rBetaOrInf[2] = 0.001 * var_hyperpolarising_activated_current_y_gate__beta_y * var_hyperpolarising_activated_current_y_gate__speed_y;
        rAlphaOrTau[3] = 0.001 * var_time_dependent_potassium_current_x_gate__alpha_x;
        rBetaOrInf[3] = 0.001 * var_time_dependent_potassium_current_x_gate__beta_x;
        rAlphaOrTau[4] = 0.001 * var_fast_sodium_current_m_gate__alpha_m;
        rBetaOrInf[4] = 0.001 * var_fast_sodium_current_m_gate__beta_m;
        rAlphaOrTau[5] = 0.001 * var_fast_sodium_current_h_gate__alpha_h;
        rBetaOrInf[5] = 0.001 * var_fast_sodium_current_h_gate__beta_h;
        rAlphaOrTau[6] = 0.001 * var_second_inward_current_d_gate__alpha_d;
        rBetaOrInf[6] = 0.001 * var_second_inward_current_d_gate__beta_d;
        rAlphaOrTau[7] = 0.001 * var_second_inward_current_f_gate__alpha_f;
        rBetaOrInf[7] = 0.001 * var_second_inward_current_f_gate__beta_f;
        rDY[8] = d_dt_chaste_interface_var_second_inward_current_f2_gate__f2;
        rDY[9] = d_dt_chaste_interface_var_intracellular_sodium_concentration__Nai;
        rDY[10] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up;
        rDY[11] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel;
        rAlphaOrTau[12] = 0.001 * var_intracellular_calcium_concentration__alpha_p;
        rBetaOrInf[12] = 0.001 * var_intracellular_calcium_concentration__beta_p;
        rDY[13] = d_dt_chaste_interface_var_extracellular_potassium_concentration__Kc;
        rDY[14] = d_dt_chaste_interface_var_intracellular_potassium_concentration__Ki;
    }
    void Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen::ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        
        rY[1] += mDt * rDY[1];
        {
            const double tau_inv = rAlphaOrTau[2] + rBetaOrInf[2];
            const double y_inf = rAlphaOrTau[2] / tau_inv;
            rY[2] = y_inf + (rY[2] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[3] + rBetaOrInf[3];
            const double y_inf = rAlphaOrTau[3] / tau_inv;
            rY[3] = y_inf + (rY[3] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[4] + rBetaOrInf[4];
            const double y_inf = rAlphaOrTau[4] / tau_inv;
            rY[4] = y_inf + (rY[4] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[5] + rBetaOrInf[5];
            const double y_inf = rAlphaOrTau[5] / tau_inv;
            rY[5] = y_inf + (rY[5] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[6] + rBetaOrInf[6];
            const double y_inf = rAlphaOrTau[6] / tau_inv;
            rY[6] = y_inf + (rY[6] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[7] + rBetaOrInf[7];
            const double y_inf = rAlphaOrTau[7] / tau_inv;
            rY[7] = y_inf + (rY[7] - y_inf)*exp(-mDt*tau_inv);
        }
        rY[8] += mDt * rDY[8];
        rY[9] += mDt * rDY[9];
        rY[10] += mDt * rDY[10];
        rY[11] += mDt * rDY[11];
        {
            const double tau_inv = rAlphaOrTau[12] + rBetaOrInf[12];
            const double y_inf = rAlphaOrTau[12] / tau_inv;
            rY[12] = y_inf + (rY[12] - y_inf)*exp(-mDt*tau_inv);
        }
        rY[13] += mDt * rDY[13];
        rY[14] += mDt * rDY[14];
    }

template<>
void OdeSystemInformation<Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen>::Initialise(void)
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
CHASTE_CLASS_EXPORT(Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen)
