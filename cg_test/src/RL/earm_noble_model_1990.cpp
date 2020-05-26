//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: earm_noble_model_1990
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on 2020-05-21 18:20:52
//!
//! <autogenerated>

#include "earm_noble_model_1990.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Cellearm_noble_model_1990FromCellMLRushLarsen::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_membrane__C_m_converted = mParameters[0] / HeartConfig::Instance()->GetCapacitance(); // uA / uA_per_cm2
        const double var_chaste_interface__membrane__stim_amplitude_converted = -0.0013000000000000002 / var_membrane__C_m_converted; // uA_per_cm2
        const double var_chaste_interface__membrane__stim_duration_converted = 2.0; // millisecond
        const double var_chaste_interface__membrane__stim_period_converted = 1000.0; // millisecond
        const double var_chaste_interface__membrane__stim_start_converted = 100.0; // millisecond
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__membrane__stim_amplitude_converted),
                var_chaste_interface__membrane__stim_duration_converted,
                var_chaste_interface__membrane__stim_period_converted,
                var_chaste_interface__membrane__stim_start_converted
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }
    double Cellearm_noble_model_1990FromCellMLRushLarsen::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    Cellearm_noble_model_1990FromCellMLRushLarsen::Cellearm_noble_model_1990FromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractRushLarsenCardiacCell(
                16,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellearm_noble_model_1990FromCellMLRushLarsen>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
        this->mParameters[0] = 4.0000000000000003e-5; // (var_membrane__C_m) [microF]
    }

    Cellearm_noble_model_1990FromCellMLRushLarsen::~Cellearm_noble_model_1990FromCellMLRushLarsen()
    {
    }
    
    double Cellearm_noble_model_1990FromCellMLRushLarsen::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -91.6
        double var_chaste_interface__intracellular_calcium_concentration__Ca_i = rY[1];
        // Units: millimolar; Initial value: 1e-05
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.076
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.015
        double var_chaste_interface__transient_outward_current_r_gate__r = rY[4];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__transient_outward_current_s_gate__s = rY[5];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__L_type_calcium_current_d_gate__d = rY[6];
        // Units: dimensionless; Initial value: 0.0011
        double var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca = rY[7];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__intracellular_sodium_concentration__Na_i = rY[10];
        // Units: millimolar; Initial value: 6.48
        double var_chaste_interface__intracellular_potassium_concentration__K_i = rY[11];
        // Units: millimolar; Initial value: 140.0
        
        const double var_L_type_calcium_current_f_Ca_gate__CaChon = (1.0 - var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)); // dimensionless
        const double var_L_type_calcium_current__i_Ca_L = 1.8716945411372739e-5 * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Na_i * exp(1.8716945411372736)) * var_chaste_interface__L_type_calcium_current_d_gate__d * var_L_type_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) + 0.0074867781645490943 * (-50.0 + var_chaste_interface__membrane__V) * (-2.0 * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473)) * var_chaste_interface__L_type_calcium_current_d_gate__d * var_L_type_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)) + 3.7433890822745475e-6 * (-50.0 + var_chaste_interface__membrane__V) * (-4.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_potassium_concentration__K_i * exp(1.8716945411372736)) * var_chaste_interface__L_type_calcium_current_d_gate__d * var_L_type_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // nanoA
        const double var_Na_Ca_exchanger__i_NaCa = 0.0001 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 0.00020000000000000001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i)); // nanoA
        const double var_calcium_background_current__i_b_Ca = 5.0000000000000002e-5 * var_chaste_interface__membrane__V - 0.00066784401649239123 * log(2.0 / var_chaste_interface__intracellular_calcium_concentration__Ca_i); // nanoA
        const double var_fast_sodium_current__i_Na = 0.5 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-26.713760659695652 * log(140.47999999999999 / (0.12 * var_chaste_interface__intracellular_potassium_concentration__K_i + var_chaste_interface__intracellular_sodium_concentration__Na_i)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h; // nanoA
        const double var_sodium_background_current__i_b_Na = 0.00012 * var_chaste_interface__membrane__V - 0.0032056512791634783 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double var_sodium_potassium_pump__i_NaK = 0.11200000000000002 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double var_transient_outward_current__E_K = 26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i); // millivolt
        const double var_potassium_background_current__i_b_K = 0.0016999999999999999 * var_chaste_interface__membrane__V - 0.0016999999999999999 * var_transient_outward_current__E_K; // nanoA
        const double var_time_independent_potassium_current__i_K1 = 0.0048571428571428576 * (-var_transient_outward_current__E_K + var_chaste_interface__membrane__V) / (1.0 + exp(-0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 0.074867781645490947 * var_transient_outward_current__E_K)); // nanoA
        const double var_transient_outward_current__i_to = 0.01 * (-var_transient_outward_current__E_K + var_chaste_interface__membrane__V) * var_chaste_interface__transient_outward_current_r_gate__r * var_chaste_interface__transient_outward_current_s_gate__s; // nanoA
        const double var_chaste_interface__i_ionic = 0.001 * (var_L_type_calcium_current__i_Ca_L + var_Na_Ca_exchanger__i_NaCa + var_calcium_background_current__i_b_Ca + var_fast_sodium_current__i_Na + var_potassium_background_current__i_b_K + var_sodium_background_current__i_b_Na + var_sodium_potassium_pump__i_NaK + var_time_independent_potassium_current__i_K1 + var_transient_outward_current__i_to) * HeartConfig::Instance()->GetCapacitance() / mParameters[0]; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellearm_noble_model_1990FromCellMLRushLarsen::EvaluateEquations(double var_chaste_interface__environment__time_converted, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -91.6
        double var_chaste_interface__intracellular_calcium_concentration__Ca_i = rY[1];
        // Units: millimolar; Initial value: 1e-05
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.076
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.015
        double var_chaste_interface__transient_outward_current_r_gate__r = rY[4];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__transient_outward_current_s_gate__s = rY[5];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__L_type_calcium_current_d_gate__d = rY[6];
        // Units: dimensionless; Initial value: 0.0011
        double var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca = rY[7];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__calcium_release__ActFrac = rY[8];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__calcium_release__ProdFrac = rY[9];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__intracellular_sodium_concentration__Na_i = rY[10];
        // Units: millimolar; Initial value: 6.48
        double var_chaste_interface__intracellular_potassium_concentration__K_i = rY[11];
        // Units: millimolar; Initial value: 140.0
        double var_chaste_interface__intracellular_calcium_concentration__Ca_up = rY[12];
        // Units: millimolar; Initial value: 0.3
        double var_chaste_interface__intracellular_calcium_concentration__Ca_rel = rY[13];
        // Units: millimolar; Initial value: 0.3
        double var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod = rY[14];
        // Units: millimolar; Initial value: 0.0005
        double var_chaste_interface__intracellular_calcium_concentration__Ca_Trop = rY[15];
        // Units: millimolar; Initial value: 0.0015

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double d_dt_chaste_interface_var_calcium_release__ProdFrac = -0.00059999999999999995 * var_chaste_interface__calcium_release__ProdFrac + 0.001 * (60.0 + 500.0 * pow(var_chaste_interface__intracellular_calcium_concentration__Ca_i, 2) / pow((0.00050000000000000001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i), 2)) * var_chaste_interface__calcium_release__ActFrac; // 1 / millisecond
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel = 0.0050000000000000001 * var_chaste_interface__intracellular_calcium_concentration__Ca_up - 0.0050000000000000001 * var_chaste_interface__intracellular_calcium_concentration__Ca_rel - 0.25 * pow(var_chaste_interface__calcium_release__ActFrac, 2) * var_chaste_interface__intracellular_calcium_concentration__Ca_rel / pow((0.25 + var_chaste_interface__calcium_release__ActFrac), 2); // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Calmod = -0.050000000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod + 100.0 * (0.02 - var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod) * var_chaste_interface__intracellular_calcium_concentration__Ca_i; // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Trop = -0.20000000000000001 * var_chaste_interface__intracellular_calcium_concentration__Ca_Trop + 100.0 * (0.14999999999999999 - var_chaste_interface__intracellular_calcium_concentration__Ca_Trop) * var_chaste_interface__intracellular_calcium_concentration__Ca_i; // millimolar / millisecond
        const double var_L_type_calcium_current_d_gate__alpha_d = ((fabs(19.0 + var_chaste_interface__membrane__V) < 0.0001) ? (120.0) : (30.0 * (19.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.75 - 0.25 * var_chaste_interface__membrane__V)))); // per_second
        const double var_L_type_calcium_current_d_gate__beta_d = ((fabs(19.0 + var_chaste_interface__membrane__V) < 0.0001) ? (120.0) : (12.0 * (19.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * var_chaste_interface__membrane__V)))); // per_second
        const double d_dt_chaste_interface_var_L_type_calcium_current_f_Ca_gate__f_Ca = 0.012 * ((1.0 - var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) + 120.0 * (1.0 - var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca) * var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) / (1.0 + exp(-8.5 - 0.25 * var_chaste_interface__membrane__V)) - 0.001 * ((fabs(34.0 + var_chaste_interface__membrane__V) < 0.0001) ? (25.0) : (6.25 * (34.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(8.5 + 0.25 * var_chaste_interface__membrane__V)))) * var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca; // 1 / millisecond
        const double d_dt_chaste_interface_var_calcium_release__ActFrac = 0.001 * (600.0 * exp(-3.2000000000000002 + 0.080000000000000002 * var_chaste_interface__membrane__V) + 500.0 * pow(var_chaste_interface__intracellular_calcium_concentration__Ca_i, 2) / pow((0.00050000000000000001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i), 2)) * (1.0 - var_chaste_interface__calcium_release__ActFrac - var_chaste_interface__calcium_release__ProdFrac) - 0.001 * (60.0 + 500.0 * pow(var_chaste_interface__intracellular_calcium_concentration__Ca_i, 2) / pow((0.00050000000000000001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i), 2)) * var_chaste_interface__calcium_release__ActFrac; // 1 / millisecond
        const double var_fast_sodium_current_h_gate__alpha_h = 20.0 * exp(-9.375 - 0.125 * var_chaste_interface__membrane__V); // per_second
        const double var_fast_sodium_current_h_gate__beta_h = 2000.0 / (1.0 + 320.0 * exp(-7.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // per_second
        const double var_fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + var_chaste_interface__membrane__V) < 1.0000000000000001e-5) ? (2000.0) : (200.0 * (41.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * var_chaste_interface__membrane__V)))); // per_second
        const double var_fast_sodium_current_m_gate__beta_m = 8000.0 * exp(-3.6960000000000002 - 0.056000000000000001 * var_chaste_interface__membrane__V); // per_second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_i = 2.8102681769358871e-7 * log(2.0 / var_chaste_interface__intracellular_calcium_concentration__Ca_i) + 0.050000000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod + 0.20000000000000001 * var_chaste_interface__intracellular_calcium_concentration__Ca_Trop - 2.103985442361079e-8 * var_chaste_interface__membrane__V + 5.5199999999999998e-8 * var_chaste_interface__intracellular_calcium_concentration__Ca_up / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i) - 100.0 * (0.14999999999999999 - var_chaste_interface__intracellular_calcium_concentration__Ca_Trop) * var_chaste_interface__intracellular_calcium_concentration__Ca_i - 100.0 * (0.02 - var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod) * var_chaste_interface__intracellular_calcium_concentration__Ca_i - 0.0030000000000000001 * var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i) + 0.051020408163265314 * pow(var_chaste_interface__calcium_release__ActFrac, 2) * var_chaste_interface__intracellular_calcium_concentration__Ca_rel / pow((0.25 + var_chaste_interface__calcium_release__ActFrac), 2) + 8.4159417694443161e-8 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 0.00020000000000000001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i)) - 3.1504144536796187e-6 * (1.0 - var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (-2.0 * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473)) * var_chaste_interface__L_type_calcium_current_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)); // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up = 0.050000000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_rel - 0.050000000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + 0.14699999999999999 * var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i) - 2.7047999999999999e-6 * var_chaste_interface__intracellular_calcium_concentration__Ca_up / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i); // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_sodium_concentration__Na_i = 2.6978574498584515e-6 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Na_i) - 1.009913012333318e-7 * var_chaste_interface__membrane__V - 0.00028277564345332906 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i) - 2.5247825308332947e-7 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 0.00020000000000000001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i)) - 0.00042079708847221582 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-26.713760659695652 * log(140.47999999999999 / (0.12 * var_chaste_interface__intracellular_potassium_concentration__K_i + var_chaste_interface__intracellular_sodium_concentration__Na_i)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h - 1.5752072268398093e-8 * (1.0 - var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Na_i * exp(1.8716945411372736)) * var_chaste_interface__L_type_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // millimolar / millisecond
        const double var_transient_outward_current_s_gate__alpha_s = 0.033000000000000002 * exp(-0.058823529411764705 * var_chaste_interface__membrane__V); // per_second
        const double var_transient_outward_current_s_gate__beta_s = 33.0 / (1.0 + exp(-1.25 - 0.125 * var_chaste_interface__membrane__V)); // per_second
        const double d_dt_chaste_interface_var_intracellular_potassium_concentration__K_i = 3.8219647206328062e-5 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i) - 1.4307101008055335e-6 * var_chaste_interface__membrane__V + 0.0001885170956355527 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i) - 4.0877431451586679e-6 * (-26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i) + var_chaste_interface__membrane__V) / (1.0 + exp(-0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 2.0 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i))) - 8.4159417694443166e-6 * (-26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i) + var_chaste_interface__membrane__V) * var_chaste_interface__transient_outward_current_r_gate__r * var_chaste_interface__transient_outward_current_s_gate__s - 3.1504144536796189e-9 * (1.0 - var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (-4.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_potassium_concentration__K_i * exp(1.8716945411372736)) * var_chaste_interface__L_type_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // millimolar / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_membrane__V = -0.001 * (0.0018699999999999999 * var_chaste_interface__membrane__V - 0.0032056512791634783 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Na_i) - 0.00066784401649239123 * log(2.0 / var_chaste_interface__intracellular_calcium_concentration__Ca_i) - 0.045413393121482605 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i) + 0.0048571428571428576 * (-26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i) + var_chaste_interface__membrane__V) / (1.0 + exp(-0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 2.0 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i))) + 0.11200000000000002 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i) + 0.5 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-26.713760659695652 * log(140.47999999999999 / (0.12 * var_chaste_interface__intracellular_potassium_concentration__K_i + var_chaste_interface__intracellular_sodium_concentration__Na_i)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h + 1000.0 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time_converted) * mParameters[0] / HeartConfig::Instance()->GetCapacitance() + 0.01 * (-26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i) + var_chaste_interface__membrane__V) * var_chaste_interface__transient_outward_current_r_gate__r * var_chaste_interface__transient_outward_current_s_gate__s + 0.0001 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 0.00020000000000000001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i)) + 1.8716945411372739e-5 * (1.0 - var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Na_i * exp(1.8716945411372736)) * var_chaste_interface__L_type_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) + 0.0074867781645490943 * (1.0 - var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (-2.0 * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473)) * var_chaste_interface__L_type_calcium_current_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)) + 3.7433890822745475e-6 * (1.0 - var_chaste_interface__L_type_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (-4.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_potassium_concentration__K_i * exp(1.8716945411372736)) * var_chaste_interface__L_type_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V))) / mParameters[0]; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rDY[1] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_i;
        rAlphaOrTau[2] = 0.001 * var_fast_sodium_current_m_gate__alpha_m;
        rBetaOrInf[2] = 0.001 * var_fast_sodium_current_m_gate__beta_m;
        rAlphaOrTau[3] = 0.001 * var_fast_sodium_current_h_gate__alpha_h;
        rBetaOrInf[3] = 0.001 * var_fast_sodium_current_h_gate__beta_h;
        rAlphaOrTau[4] = 3.0030030030030028;
        rBetaOrInf[4] = 1 / (1.0 + exp(-0.80000000000000004 - 0.20000000000000001 * var_chaste_interface__membrane__V));
        rAlphaOrTau[5] = 0.001 * var_transient_outward_current_s_gate__alpha_s;
        rBetaOrInf[5] = 0.001 * var_transient_outward_current_s_gate__beta_s;
        rAlphaOrTau[6] = 0.001 * var_L_type_calcium_current_d_gate__alpha_d;
        rBetaOrInf[6] = 0.001 * var_L_type_calcium_current_d_gate__beta_d;
        rDY[7] = d_dt_chaste_interface_var_L_type_calcium_current_f_Ca_gate__f_Ca;
        rDY[8] = d_dt_chaste_interface_var_calcium_release__ActFrac;
        rDY[9] = d_dt_chaste_interface_var_calcium_release__ProdFrac;
        rDY[10] = d_dt_chaste_interface_var_intracellular_sodium_concentration__Na_i;
        rDY[11] = d_dt_chaste_interface_var_intracellular_potassium_concentration__K_i;
        rDY[12] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up;
        rDY[13] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel;
        rDY[14] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Calmod;
        rDY[15] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Trop;
    }
    void Cellearm_noble_model_1990FromCellMLRushLarsen::ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf)
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
        rY[4] = rBetaOrInf[4] + (rY[4] - rBetaOrInf[4])*exp(-mDt/rAlphaOrTau[4]);
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
        rY[7] += mDt * rDY[7];
        rY[8] += mDt * rDY[8];
        rY[9] += mDt * rDY[9];
        rY[10] += mDt * rDY[10];
        rY[11] += mDt * rDY[11];
        rY[12] += mDt * rDY[12];
        rY[13] += mDt * rDY[13];
        rY[14] += mDt * rDY[14];
        rY[15] += mDt * rDY[15];
    }

    std::vector<double> Cellearm_noble_model_1990FromCellMLRushLarsen::ComputeDerivedQuantities(double var_chaste_interface__environment__time_converted, const std::vector<double> & rY)
    {
        // Inputs:
        // Time units: millisecond
        

        // Mathematics
        const double var_membrane__C_m_converted = mParameters[0] / HeartConfig::Instance()->GetCapacitance(); // uA / uA_per_cm2
        const double var_membrane__i_Stim_converted = GetIntracellularAreaStimulus(var_chaste_interface__environment__time_converted); // uA_per_cm2

        std::vector<double> dqs(3);
        dqs[0] = var_chaste_interface__environment__time_converted;
        dqs[1] = var_membrane__C_m_converted;
        dqs[2] = var_membrane__i_Stim_converted;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellearm_noble_model_1990FromCellMLRushLarsen>::Initialise(void)
{
    this->mSystemName = "earm_noble_model_1990";
    this->mFreeVariableName = "environment__time";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-91.6);

    // rY[1]:
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(1e-05);

    // rY[2]:
    this->mVariableNames.push_back("fast_sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.076);

    // rY[3]:
    this->mVariableNames.push_back("fast_sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.015);

    // rY[4]:
    this->mVariableNames.push_back("transient_outward_current_r_gate__r");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[5]:
    this->mVariableNames.push_back("transient_outward_current_s_gate__s");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[6]:
    this->mVariableNames.push_back("L_type_calcium_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0011);

    // rY[7]:
    this->mVariableNames.push_back("L_type_calcium_current_f_Ca_gate__f_Ca");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.785);

    // rY[8]:
    this->mVariableNames.push_back("calcium_release__ActFrac");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[9]:
    this->mVariableNames.push_back("calcium_release__ProdFrac");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[10]:
    this->mVariableNames.push_back("intracellular_sodium_concentration__Na_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(6.48);

    // rY[11]:
    this->mVariableNames.push_back("intracellular_potassium_concentration__K_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(140.0);

    // rY[12]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_up");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.3);

    // rY[13]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_rel");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.3);

    // rY[14]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_Calmod");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.0005);

    // rY[15]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_Trop");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.0015);

    // mParameters[0]:
    this->mParameterNames.push_back("membrane__C_m");
    this->mParameterUnits.push_back("microF");

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("environment__time");
    this->mDerivedQuantityUnits.push_back("millisecond");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("membrane_capacitance");
    this->mDerivedQuantityUnits.push_back("uA / uA_per_cm2");

    // Derived Quantity index [2]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellearm_noble_model_1990FromCellMLRushLarsen)
