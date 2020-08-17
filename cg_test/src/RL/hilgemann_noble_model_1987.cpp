//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.1.0
//!
//! Model: hilgemann_noble_model_1987
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on 2020-06-18 23:37:25
//!
//! <autogenerated>

#include "hilgemann_noble_model_1987.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Cellhilgemann_noble_model_1987FromCellMLRushLarsen::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__membrane__stim_amplitude_converted = -0.20000000000000001 * HeartConfig::Instance()->GetCapacitance() / mParameters[0]; // uA_per_cm2
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
    double Cellhilgemann_noble_model_1987FromCellMLRushLarsen::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    Cellhilgemann_noble_model_1987FromCellMLRushLarsen::Cellhilgemann_noble_model_1987FromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractRushLarsenCardiacCell(
                15,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellhilgemann_noble_model_1987FromCellMLRushLarsen>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
        this->mParameters[0] = 0.0060000000000000001; // (var_membrane__C_m) [microF]
    }

    Cellhilgemann_noble_model_1987FromCellMLRushLarsen::~Cellhilgemann_noble_model_1987FromCellMLRushLarsen()
    {
    }
    
    double Cellhilgemann_noble_model_1987FromCellMLRushLarsen::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -88.0
        double var_chaste_interface__intracellular_calcium_concentration__Ca_i = rY[1];
        // Units: millimolar; Initial value: 1e-05
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.076
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.015
        double var_chaste_interface__second_inward_calcium_current_d_gate__d = rY[4];
        // Units: dimensionless; Initial value: 0.0011
        double var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca = rY[5];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__intracellular_sodium_concentration__Na_i = rY[8];
        // Units: millimolar; Initial value: 6.5
        double var_chaste_interface__extracellular_calcium_concentration__Ca_o = rY[9];
        // Units: millimolar; Initial value: 2.0
        double var_chaste_interface__intracellular_potassium_concentration__K_i = rY[10];
        // Units: millimolar; Initial value: 140.0
        
        const double var_Na_Ca_exchanger__i_NaCa = 0.01 * (-2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V) + pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i + 0.0001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o)); // nanoA
        const double var_calcium_background_current__i_b_Ca = 0.0050000000000000001 * var_chaste_interface__membrane__V - 0.066784401649239128 * log(var_chaste_interface__extracellular_calcium_concentration__Ca_o / var_chaste_interface__intracellular_calcium_concentration__Ca_i); // nanoA
        const double var_fast_sodium_current__i_Na = 50.0 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-26.713760659695652 * log(140.47999999999999 / (var_chaste_interface__intracellular_sodium_concentration__Na_i + 0.12 * var_chaste_interface__intracellular_potassium_concentration__K_i)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h; // nanoA
        const double var_second_inward_calcium_current_f_Ca_gate__CaChon = (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)); // dimensionless
        const double var_second_inward_calcium_current__i_si = 0.00037433890822745472 * (-50.0 + var_chaste_interface__membrane__V) * (-4.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_potassium_concentration__K_i * exp(1.8716945411372736)) * var_chaste_interface__second_inward_calcium_current_d_gate__d * var_second_inward_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) + 0.0018716945411372736 * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Na_i * exp(1.8716945411372736)) * var_chaste_interface__second_inward_calcium_current_d_gate__d * var_second_inward_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) + 0.74867781645490938 * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_calcium_current_d_gate__d * var_second_inward_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)); // nanoA
        const double var_sodium_background_current__i_b_Na = 0.012 * var_chaste_interface__membrane__V - 0.32056512791634778 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double var_sodium_potassium_pump__i_NaK = 11.199999999999999 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double var_time_independent_potassium_current__E_K = 26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i); // millivolt
        const double var_potassium_background_current__i_b_K = 0.17000000000000001 * var_chaste_interface__membrane__V - 0.17000000000000001 * var_time_independent_potassium_current__E_K; // nanoA
        const double var_time_independent_potassium_current__i_K1 = 0.48571428571428571 * (-var_time_independent_potassium_current__E_K + var_chaste_interface__membrane__V) / (1.0 + exp(-0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 0.074867781645490947 * var_time_independent_potassium_current__E_K)); // nanoA
        const double var_chaste_interface__i_ionic = 0.001 * (var_Na_Ca_exchanger__i_NaCa + var_calcium_background_current__i_b_Ca + var_fast_sodium_current__i_Na + var_potassium_background_current__i_b_K + var_second_inward_calcium_current__i_si + var_sodium_background_current__i_b_Na + var_sodium_potassium_pump__i_NaK + var_time_independent_potassium_current__i_K1) * HeartConfig::Instance()->GetCapacitance() / mParameters[0]; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellhilgemann_noble_model_1987FromCellMLRushLarsen::EvaluateEquations(double var_chaste_interface__environment__time_converted, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -88.0
        double var_chaste_interface__intracellular_calcium_concentration__Ca_i = rY[1];
        // Units: millimolar; Initial value: 1e-05
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.076
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.015
        double var_chaste_interface__second_inward_calcium_current_d_gate__d = rY[4];
        // Units: dimensionless; Initial value: 0.0011
        double var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca = rY[5];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__calcium_release__ActFrac = rY[6];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__calcium_release__ProdFrac = rY[7];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__intracellular_sodium_concentration__Na_i = rY[8];
        // Units: millimolar; Initial value: 6.5
        double var_chaste_interface__extracellular_calcium_concentration__Ca_o = rY[9];
        // Units: millimolar; Initial value: 2.0
        double var_chaste_interface__intracellular_potassium_concentration__K_i = rY[10];
        // Units: millimolar; Initial value: 140.0
        double var_chaste_interface__intracellular_calcium_concentration__Ca_up = rY[11];
        // Units: millimolar; Initial value: 0.3
        double var_chaste_interface__intracellular_calcium_concentration__Ca_rel = rY[12];
        // Units: millimolar; Initial value: 0.3
        double var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod = rY[13];
        // Units: millimolar; Initial value: 0.0005
        double var_chaste_interface__intracellular_calcium_concentration__Ca_Trop = rY[14];
        // Units: millimolar; Initial value: 0.0015

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double d_dt_chaste_interface_var_calcium_release__ProdFrac = -0.00059999999999999995 * var_chaste_interface__calcium_release__ProdFrac + 0.001 * (60.0 + 500.0 * pow(var_chaste_interface__intracellular_calcium_concentration__Ca_i, 2) / pow((0.00050000000000000001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i), 2)) * var_chaste_interface__calcium_release__ActFrac; // 1 / millisecond
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel = 0.0050000000000000001 * var_chaste_interface__intracellular_calcium_concentration__Ca_up - 0.0050000000000000001 * var_chaste_interface__intracellular_calcium_concentration__Ca_rel - 0.25 * pow(var_chaste_interface__calcium_release__ActFrac, 2) * var_chaste_interface__intracellular_calcium_concentration__Ca_rel / pow((0.25 + var_chaste_interface__calcium_release__ActFrac), 2); // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Calmod = -0.050000000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod + 100.0 * (0.02 - var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod) * var_chaste_interface__intracellular_calcium_concentration__Ca_i; // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Trop = -0.20000000000000001 * var_chaste_interface__intracellular_calcium_concentration__Ca_Trop + 100.0 * (0.14999999999999999 - var_chaste_interface__intracellular_calcium_concentration__Ca_Trop) * var_chaste_interface__intracellular_calcium_concentration__Ca_i; // millimolar / millisecond
        const double d_dt_chaste_interface_var_calcium_release__ActFrac = 0.001 * (600.0 * exp(-3.2000000000000002 + 0.080000000000000002 * var_chaste_interface__membrane__V) + 500.0 * pow(var_chaste_interface__intracellular_calcium_concentration__Ca_i, 2) / pow((0.00050000000000000001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i), 2)) * (1.0 - var_chaste_interface__calcium_release__ActFrac - var_chaste_interface__calcium_release__ProdFrac) - 0.001 * (60.0 + 500.0 * pow(var_chaste_interface__intracellular_calcium_concentration__Ca_i, 2) / pow((0.00050000000000000001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i), 2)) * var_chaste_interface__calcium_release__ActFrac; // 1 / millisecond
        const double var_fast_sodium_current_h_gate__alpha_h = 20.0 * exp(-9.375 - 0.125 * var_chaste_interface__membrane__V); // per_second
        const double var_fast_sodium_current_h_gate__beta_h = 2000.0 / (1.0 + 320.0 * exp(-7.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // per_second
        const double var_fast_sodium_current_m_gate__alpha_m = ((fabs(41.0 + var_chaste_interface__membrane__V) < 1.0000000000000001e-5) ? (2000.0) : (200.0 * (41.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * var_chaste_interface__membrane__V)))); // per_second
        const double var_fast_sodium_current_m_gate__beta_m = 8000.0 * exp(-3.6960000000000002 - 0.056000000000000001 * var_chaste_interface__membrane__V); // per_second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up = 0.050000000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_rel - 0.050000000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + 0.14699999999999999 * var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i) - 2.7047999999999999e-6 * var_chaste_interface__intracellular_calcium_concentration__Ca_up / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i); // millimolar / millisecond
        const double var_second_inward_calcium_current_d_gate__alpha_d = ((fabs(19.0 + var_chaste_interface__membrane__V) < 0.0001) ? (120.0) : (30.0 * (19.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.75 - 0.25 * var_chaste_interface__membrane__V)))); // per_second
        const double var_second_inward_calcium_current_d_gate__beta_d = ((fabs(19.0 + var_chaste_interface__membrane__V) < 0.0001) ? (120.0) : (12.0 * (19.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(1.8999999999999999 + 0.10000000000000001 * var_chaste_interface__membrane__V)))); // per_second
        const double d_dt_chaste_interface_var_extracellular_calcium_concentration__Ca_o = 9.9999999999999995e-7 + 5.3790289324163455e-7 * log(var_chaste_interface__extracellular_calcium_concentration__Ca_o / var_chaste_interface__intracellular_calcium_concentration__Ca_i) - 4.9999999999999998e-7 * var_chaste_interface__extracellular_calcium_concentration__Ca_o - 4.0271596357692526e-8 * var_chaste_interface__membrane__V - 8.0543192715385052e-8 * (-2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V) + pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i + 0.0001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o)) - 6.0300901652461443e-6 * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_calcium_current_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)); // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_i = 0.050000000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod + 0.20000000000000001 * var_chaste_interface__intracellular_calcium_concentration__Ca_Trop + 4.3910440264623234e-7 * log(var_chaste_interface__extracellular_calcium_concentration__Ca_o / var_chaste_interface__intracellular_calcium_concentration__Ca_i) - 3.2874772536891862e-8 * var_chaste_interface__membrane__V + 5.5199999999999998e-8 * var_chaste_interface__intracellular_calcium_concentration__Ca_up / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i) - 100.0 * (0.14999999999999999 - var_chaste_interface__intracellular_calcium_concentration__Ca_Trop) * var_chaste_interface__intracellular_calcium_concentration__Ca_i - 100.0 * (0.02 - var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod) * var_chaste_interface__intracellular_calcium_concentration__Ca_i - 0.0030000000000000001 * var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i) + 0.051020408163265314 * pow(var_chaste_interface__calcium_release__ActFrac, 2) * var_chaste_interface__intracellular_calcium_concentration__Ca_rel / pow((0.25 + var_chaste_interface__calcium_release__ActFrac), 2) + 1.3149909014756745e-7 * (-2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V) + pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i + 0.0001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o)) - 4.9225225838744041e-6 * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_calcium_current_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)); // millimolar / millisecond
        const double d_dt_chaste_interface_var_second_inward_calcium_current_f_Ca_gate__f_Ca = 0.012 * ((1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) + 120.0 * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) / (1.0 + exp(-8.5 - 0.25 * var_chaste_interface__membrane__V)) - 0.001 * ((fabs(34.0 + var_chaste_interface__membrane__V) < 0.0001) ? (25.0) : (6.25 * (34.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(8.5 + 0.25 * var_chaste_interface__membrane__V)))) * var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca; // 1 / millisecond
        const double d_dt_chaste_interface_var_intracellular_sodium_concentration__Na_i = 4.215402265403831e-6 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Na_i) - 1.5779890817708093e-7 * var_chaste_interface__membrane__V - 0.00044183694289582661 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i) - 0.00065749545073783716 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-26.713760659695652 * log(140.47999999999999 / (var_chaste_interface__intracellular_sodium_concentration__Na_i + 0.12 * var_chaste_interface__intracellular_potassium_concentration__K_i)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h - 3.9449727044270234e-7 * (-2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V) + pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i + 0.0001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o)) - 2.4612612919372021e-8 * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Na_i * exp(1.8716945411372736)) * var_chaste_interface__second_inward_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_potassium_concentration__K_i = 5.9718198759887604e-5 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i) - 2.2354845325086465e-6 * var_chaste_interface__membrane__V + 0.00029455796193055103 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i) - 6.3870986643104186e-6 * (-26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i) + var_chaste_interface__membrane__V) / (1.0 + exp(-0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 2.0 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i))) - 4.922522583874404e-9 * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (-4.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_potassium_concentration__K_i * exp(1.8716945411372736)) * var_chaste_interface__second_inward_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // millimolar / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_membrane__V = 0.001 * (0.066784401649239128 * log(var_chaste_interface__extracellular_calcium_concentration__Ca_o / var_chaste_interface__intracellular_calcium_concentration__Ca_i) + 4.5413393121482608 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i) + 0.32056512791634778 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Na_i) - 0.187 * var_chaste_interface__membrane__V - 0.48571428571428571 * (-26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i) + var_chaste_interface__membrane__V) / (1.0 + exp(-0.74867781645490938 + 0.074867781645490947 * var_chaste_interface__membrane__V - 2.0 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i))) - 11.199999999999999 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i) - 50.0 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-26.713760659695652 * log(140.47999999999999 / (var_chaste_interface__intracellular_sodium_concentration__Na_i + 0.12 * var_chaste_interface__intracellular_potassium_concentration__K_i)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h - 1000.0 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time_converted) * mParameters[0] / HeartConfig::Instance()->GetCapacitance() - 0.01 * (-2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V) + pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(0.018716945411372737 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i + 0.0001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o)) - 0.00037433890822745472 * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (-4.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_potassium_concentration__K_i * exp(1.8716945411372736)) * var_chaste_interface__second_inward_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) - 0.0018716945411372736 * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Na_i * exp(1.8716945411372736)) * var_chaste_interface__second_inward_calcium_current_d_gate__d / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)) - 0.74867781645490938 * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)) * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473) - var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_calcium_current_d_gate__d / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V))) / mParameters[0]; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rDY[1] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_i;
        rAlphaOrTau[2] = 0.001 * var_fast_sodium_current_m_gate__alpha_m;
        rBetaOrInf[2] = 0.001 * var_fast_sodium_current_m_gate__beta_m;
        rAlphaOrTau[3] = 0.001 * var_fast_sodium_current_h_gate__alpha_h;
        rBetaOrInf[3] = 0.001 * var_fast_sodium_current_h_gate__beta_h;
        rAlphaOrTau[4] = 0.001 * var_second_inward_calcium_current_d_gate__alpha_d;
        rBetaOrInf[4] = 0.001 * var_second_inward_calcium_current_d_gate__beta_d;
        rDY[5] = d_dt_chaste_interface_var_second_inward_calcium_current_f_Ca_gate__f_Ca;
        rDY[6] = d_dt_chaste_interface_var_calcium_release__ActFrac;
        rDY[7] = d_dt_chaste_interface_var_calcium_release__ProdFrac;
        rDY[8] = d_dt_chaste_interface_var_intracellular_sodium_concentration__Na_i;
        rDY[9] = d_dt_chaste_interface_var_extracellular_calcium_concentration__Ca_o;
        rDY[10] = d_dt_chaste_interface_var_intracellular_potassium_concentration__K_i;
        rDY[11] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up;
        rDY[12] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel;
        rDY[13] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Calmod;
        rDY[14] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Trop;
    }
    void Cellhilgemann_noble_model_1987FromCellMLRushLarsen::ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf)
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
        rY[5] += mDt * rDY[5];
        rY[6] += mDt * rDY[6];
        rY[7] += mDt * rDY[7];
        rY[8] += mDt * rDY[8];
        rY[9] += mDt * rDY[9];
        rY[10] += mDt * rDY[10];
        rY[11] += mDt * rDY[11];
        rY[12] += mDt * rDY[12];
        rY[13] += mDt * rDY[13];
        rY[14] += mDt * rDY[14];
    }

    std::vector<double> Cellhilgemann_noble_model_1987FromCellMLRushLarsen::ComputeDerivedQuantities(double var_chaste_interface__environment__time_converted, const std::vector<double> & rY)
    {
        // Inputs:
        // Time units: millisecond
        

        // Mathematics
        const double var_membrane__i_Stim_converted = GetIntracellularAreaStimulus(var_chaste_interface__environment__time_converted); // uA_per_cm2

        std::vector<double> dqs(2);
        dqs[0] = var_chaste_interface__environment__time_converted;
        dqs[1] = var_membrane__i_Stim_converted;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellhilgemann_noble_model_1987FromCellMLRushLarsen>::Initialise(void)
{
    this->mSystemName = "hilgemann_noble_model_1987";
    this->mFreeVariableName = "environment__time";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-88.0);

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
    this->mVariableNames.push_back("second_inward_calcium_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0011);

    // rY[5]:
    this->mVariableNames.push_back("second_inward_calcium_current_f_Ca_gate__f_Ca");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.785);

    // rY[6]:
    this->mVariableNames.push_back("calcium_release__ActFrac");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[7]:
    this->mVariableNames.push_back("calcium_release__ProdFrac");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[8]:
    this->mVariableNames.push_back("intracellular_sodium_concentration__Na_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(6.5);

    // rY[9]:
    this->mVariableNames.push_back("extracellular_calcium_concentration__Ca_o");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(2.0);

    // rY[10]:
    this->mVariableNames.push_back("intracellular_potassium_concentration__K_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(140.0);

    // rY[11]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_up");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.3);

    // rY[12]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_rel");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.3);

    // rY[13]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_Calmod");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.0005);

    // rY[14]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_Trop");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.0015);

    // mParameters[0]:
    this->mParameterNames.push_back("membrane_capacitance");
    this->mParameterUnits.push_back("microF");

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("environment__time");
    this->mDerivedQuantityUnits.push_back("millisecond");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellhilgemann_noble_model_1987FromCellMLRushLarsen)
