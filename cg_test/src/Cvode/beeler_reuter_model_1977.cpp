#ifdef CHASTE_CVODE
//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.1.0
//!
//! Model: beeler_reuter_model_1977
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on 2020-06-18 23:10:14
//!
//! <autogenerated>

#include "beeler_reuter_model_1977.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Cellbeeler_reuter_model_1977FromCellMLCvode::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__stimulus_protocol__IstimAmplitude_converted = 50.000000000000007; // uA_per_cm2
        const double var_chaste_interface__stimulus_protocol__IstimPeriod = 1000.0; // ms
        const double var_chaste_interface__stimulus_protocol__IstimPulseDuration = 1.0; // ms
        const double var_chaste_interface__stimulus_protocol__IstimStart = 10.0; // ms
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__stimulus_protocol__IstimAmplitude_converted),
                var_chaste_interface__stimulus_protocol__IstimPulseDuration,
                var_chaste_interface__stimulus_protocol__IstimPeriod,
                var_chaste_interface__stimulus_protocol__IstimStart
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }

    double Cellbeeler_reuter_model_1977FromCellMLCvode::GetIntracellularCalciumConcentration()
    {
        return NV_Ith_S(mStateVariables, 1);
    }
    
    Cellbeeler_reuter_model_1977FromCellMLCvode::Cellbeeler_reuter_model_1977FromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCvodeCell(
                pOdeSolver,
                8,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellbeeler_reuter_model_1977FromCellMLCvode>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        mUseAnalyticJacobian = true;
        mHasAnalyticJacobian = true;
        
    }

    Cellbeeler_reuter_model_1977FromCellMLCvode::~Cellbeeler_reuter_model_1977FromCellMLCvode()
    {
    }
    
    double Cellbeeler_reuter_model_1977FromCellMLCvode::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        N_Vector rY;
        bool made_new_cvode_vector = false;
        if (!pStateVariables)
        {
            rY = rGetStateVariables();
        }
        else
        {
            made_new_cvode_vector = true;
            rY = MakeNVector(*pStateVariables);
        }
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = NV_Ith_S(rY, 1);
        // Units: concentration_units; Initial value: 0.0001
        double var_chaste_interface__sodium_current_m_gate__m = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = NV_Ith_S(rY, 4);
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = NV_Ith_S(rY, 5);
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = NV_Ith_S(rY, 6);
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = NV_Ith_S(rY, 7);
        // Units: dimensionless; Initial value: 0.0001
        
        const double var_slow_inward_current__E_s = 7.6990712032745758 - 13.028700000000001 * log(var_chaste_interface__slow_inward_current__Cai); // mV
        const double var_slow_inward_current__g_s = 0.00089999999999999998; // mS_per_mm2
        const double var_slow_inward_current__i_s = (-var_slow_inward_current__E_s + var_chaste_interface__membrane__V) * var_slow_inward_current__g_s * var_chaste_interface__slow_inward_current_d_gate__d * var_chaste_interface__slow_inward_current_f_gate__f; // uA_per_mm2
        const double var_sodium_current__E_Na = 50.0; // mV
        const double var_sodium_current__g_Na = 0.040000000000000001; // mS_per_mm2
        const double var_sodium_current__g_Nac = 3.0000000000000001e-5; // mS_per_mm2
        const double var_sodium_current__i_Na = (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * (pow(var_chaste_interface__sodium_current_m_gate__m, 3) * var_sodium_current__g_Na * var_chaste_interface__sodium_current_h_gate__h * var_chaste_interface__sodium_current_j_gate__j + var_sodium_current__g_Nac); // uA_per_mm2
        const double var_time_dependent_outward_current__i_x1 = 0.0080000000000000002 * (-1.0 + exp(3.0800000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_outward_current_x1_gate__x1 / exp(1.4000000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V); // uA_per_mm2
        const double var_time_independent_outward_current__i_K1 = 0.014 * (-1.0 + exp(3.3999999999999999 + 0.040000000000000001 * var_chaste_interface__membrane__V)) / (exp(2.1200000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V) + exp(4.2400000000000002 + 0.080000000000000002 * var_chaste_interface__membrane__V)) + 0.0007000000000000001 * (23.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-0.92000000000000004 - 0.040000000000000001 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_chaste_interface__i_ionic = 100.00000000000001 * var_slow_inward_current__i_s + 100.00000000000001 * var_sodium_current__i_Na + 100.00000000000001 * var_time_dependent_outward_current__i_x1 + 100.00000000000001 * var_time_independent_outward_current__i_K1; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        if (made_new_cvode_vector)
        {
            DeleteVector(rY);
        }
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellbeeler_reuter_model_1977FromCellMLCvode::EvaluateYDerivatives(double var_chaste_interface__environment__time, const N_Vector rY, N_Vector rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = NV_Ith_S(rY, 1);
        // Units: concentration_units; Initial value: 0.0001
        double var_chaste_interface__sodium_current_m_gate__m = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = NV_Ith_S(rY, 4);
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = NV_Ith_S(rY, 5);
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = NV_Ith_S(rY, 6);
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = NV_Ith_S(rY, 7);
        // Units: dimensionless; Initial value: 0.0001

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_slow_inward_current__E_s = 7.6990712032745758 - 13.028700000000001 * log(var_chaste_interface__slow_inward_current__Cai); // mV
        const double var_slow_inward_current__g_s = 0.00089999999999999998; // mS_per_mm2
        const double var_slow_inward_current_d_gate__alpha_d = 0.095000000000000001 * exp(0.050000000000000003 - 0.01 * var_chaste_interface__membrane__V) / (1.0 + exp(0.35997120230381568 - 0.071994240460763137 * var_chaste_interface__membrane__V)); // per_ms
        const double var_slow_inward_current_d_gate__beta_d = 0.070000000000000007 * exp(-0.74576271186440679 - 0.016949152542372881 * var_chaste_interface__membrane__V) / (1.0 + exp(2.2000000000000002 + 0.050000000000000003 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface_var_slow_inward_current_d_gate__d = (1.0 - var_chaste_interface__slow_inward_current_d_gate__d) * var_slow_inward_current_d_gate__alpha_d - var_slow_inward_current_d_gate__beta_d * var_chaste_interface__slow_inward_current_d_gate__d; // 1 / ms
        const double var_slow_inward_current_f_gate__alpha_f = 0.012 * exp(-0.224 - 0.0080000000000000002 * var_chaste_interface__membrane__V) / (1.0 + exp(4.197901049475262 + 0.14992503748125938 * var_chaste_interface__membrane__V)); // per_ms
        const double var_slow_inward_current_f_gate__beta_f = 0.0064999999999999997 * exp(-0.59999999999999998 - 0.02 * var_chaste_interface__membrane__V) / (1.0 + exp(-6.0 - 0.20000000000000001 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface_var_slow_inward_current_f_gate__f = (1.0 - var_chaste_interface__slow_inward_current_f_gate__f) * var_slow_inward_current_f_gate__alpha_f - var_slow_inward_current_f_gate__beta_f * var_chaste_interface__slow_inward_current_f_gate__f; // 1 / ms
        const double var_slow_inward_current__i_s = (-var_slow_inward_current__E_s + var_chaste_interface__membrane__V) * var_slow_inward_current__g_s * var_chaste_interface__slow_inward_current_d_gate__d * var_chaste_interface__slow_inward_current_f_gate__f; // uA_per_mm2
        const double d_dt_chaste_interface_var_slow_inward_current__Cai = 7.0000000000000007e-6 - 0.070000000000000007 * var_chaste_interface__slow_inward_current__Cai - 0.01 * var_slow_inward_current__i_s; // concentration_units / ms
        const double var_sodium_current_h_gate__alpha_h = 0.126 * exp(-19.25 - 0.25 * var_chaste_interface__membrane__V); // per_ms
        const double var_sodium_current_h_gate__beta_h = 1.7 / (1.0 + exp(-1.845 - 0.082000000000000003 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface_var_sodium_current_h_gate__h = (1.0 - var_chaste_interface__sodium_current_h_gate__h) * var_sodium_current_h_gate__alpha_h - var_sodium_current_h_gate__beta_h * var_chaste_interface__sodium_current_h_gate__h; // 1 / ms
        const double var_sodium_current_j_gate__alpha_j = 0.055 * exp(-19.5 - 0.25 * var_chaste_interface__membrane__V) / (1.0 + exp(-15.600000000000001 - 0.20000000000000001 * var_chaste_interface__membrane__V)); // per_ms
        const double var_sodium_current_j_gate__beta_j = 0.29999999999999999 / (1.0 + exp(-3.2000000000000002 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface_var_sodium_current_j_gate__j = (1.0 - var_chaste_interface__sodium_current_j_gate__j) * var_sodium_current_j_gate__alpha_j - var_sodium_current_j_gate__beta_j * var_chaste_interface__sodium_current_j_gate__j; // 1 / ms
        const double var_sodium_current_m_gate__alpha_m = -1.0 * (47.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-4.7000000000000002 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // per_ms
        const double var_sodium_current_m_gate__beta_m = 40.0 * exp(-4.032 - 0.056000000000000001 * var_chaste_interface__membrane__V); // per_ms
        const double d_dt_chaste_interface_var_sodium_current_m_gate__m = (1.0 - var_chaste_interface__sodium_current_m_gate__m) * var_sodium_current_m_gate__alpha_m - var_sodium_current_m_gate__beta_m * var_chaste_interface__sodium_current_m_gate__m; // 1 / ms
        const double var_time_dependent_outward_current_x1_gate__alpha_x1 = 0.00050000000000000001 * exp(4.1322314049586781 + 0.082644628099173556 * var_chaste_interface__membrane__V) / (1.0 + exp(2.8571428571428572 + 0.057142857142857141 * var_chaste_interface__membrane__V)); // per_ms
        const double var_time_dependent_outward_current_x1_gate__beta_x1 = 0.0012999999999999999 * exp(-1.1997600479904018 - 0.059988002399520089 * var_chaste_interface__membrane__V) / (1.0 + exp(-0.80000000000000004 - 0.040000000000000001 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface_var_time_dependent_outward_current_x1_gate__x1 = (1.0 - var_chaste_interface__time_dependent_outward_current_x1_gate__x1) * var_time_dependent_outward_current_x1_gate__alpha_x1 - var_time_dependent_outward_current_x1_gate__beta_x1 * var_chaste_interface__time_dependent_outward_current_x1_gate__x1; // 1 / ms

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            const double var_membrane__C = 0.01; // uF_per_mm2
            const double var_sodium_current__E_Na = 50.0; // mV
            const double var_sodium_current__g_Na = 0.040000000000000001; // mS_per_mm2
            const double var_sodium_current__g_Nac = 3.0000000000000001e-5; // mS_per_mm2
            const double var_sodium_current__i_Na = (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * (pow(var_chaste_interface__sodium_current_m_gate__m, 3) * var_sodium_current__g_Na * var_chaste_interface__sodium_current_h_gate__h * var_chaste_interface__sodium_current_j_gate__j + var_sodium_current__g_Nac); // uA_per_mm2
            const double var_stimulus_protocol__Istim_converted = -GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_cm2
            const double var_stimulus_protocol__Istim = 0.0099999999999999985 * var_stimulus_protocol__Istim_converted; // uA_per_mm2
            const double var_time_dependent_outward_current__i_x1 = 0.0080000000000000002 * (-1.0 + exp(3.0800000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_outward_current_x1_gate__x1 / exp(1.4000000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V); // uA_per_mm2
            const double var_time_independent_outward_current__i_K1 = 0.014 * (-1.0 + exp(3.3999999999999999 + 0.040000000000000001 * var_chaste_interface__membrane__V)) / (exp(2.1200000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V) + exp(4.2400000000000002 + 0.080000000000000002 * var_chaste_interface__membrane__V)) + 0.0007000000000000001 * (23.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-0.92000000000000004 - 0.040000000000000001 * var_chaste_interface__membrane__V)); // uA_per_mm2
            d_dt_chaste_interface_var_membrane__V = (-var_slow_inward_current__i_s - var_sodium_current__i_Na - var_time_dependent_outward_current__i_x1 - var_time_independent_outward_current__i_K1 + var_stimulus_protocol__Istim) / var_membrane__C; // mV / ms
        }
        
        NV_Ith_S(rDY,0) = d_dt_chaste_interface_var_membrane__V;
        NV_Ith_S(rDY,1) = d_dt_chaste_interface_var_slow_inward_current__Cai;
        NV_Ith_S(rDY,2) = d_dt_chaste_interface_var_sodium_current_m_gate__m;
        NV_Ith_S(rDY,3) = d_dt_chaste_interface_var_sodium_current_h_gate__h;
        NV_Ith_S(rDY,4) = d_dt_chaste_interface_var_sodium_current_j_gate__j;
        NV_Ith_S(rDY,5) = d_dt_chaste_interface_var_slow_inward_current_d_gate__d;
        NV_Ith_S(rDY,6) = d_dt_chaste_interface_var_slow_inward_current_f_gate__f;
        NV_Ith_S(rDY,7) = d_dt_chaste_interface_var_time_dependent_outward_current_x1_gate__x1;
    }

    void Cellbeeler_reuter_model_1977FromCellMLCvode::EvaluateAnalyticJacobian(double var_chaste_interface__environment__time, N_Vector rY, N_Vector rDY, CHASTE_CVODE_DENSE_MATRIX rJacobian, N_Vector rTmp1, N_Vector rTmp2, N_Vector rTmp3)
    {
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = NV_Ith_S(rY, 1);
        // Units: concentration_units; Initial value: 0.0001
        double var_chaste_interface__sodium_current_m_gate__m = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = NV_Ith_S(rY, 4);
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = NV_Ith_S(rY, 5);
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = NV_Ith_S(rY, 6);
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = NV_Ith_S(rY, 7);
        // Units: dimensionless; Initial value: 0.0001
        
        const double var_x0 = 0.040000000000000001 * var_chaste_interface__membrane__V;
        const double var_x1 = exp(-0.92000000000000004 - var_x0);
        const double var_x2 = 1.0 - var_x1;
        const double var_x3 = exp(2.1200000000000001 + var_x0);
        const double var_x4 = exp(4.2400000000000002 + 0.080000000000000002 * var_chaste_interface__membrane__V);
        const double var_x5 = var_x3 + var_x4;
        const double var_x6 = exp(3.3999999999999999 + var_x0);
        const double var_x7 = var_chaste_interface__slow_inward_current_d_gate__d * var_chaste_interface__slow_inward_current_f_gate__f;
        const double var_x8 = 1 / exp(1.4000000000000001 + var_x0);
        const double var_x9 = exp(3.0800000000000001 + var_x0);
        const double var_x10 = var_x8 * (-1.0 + var_x9);
        const double var_x11 = 0.032000000000000001 * var_chaste_interface__time_dependent_outward_current_x1_gate__x1;
        const double var_x12 = var_chaste_interface__sodium_current_h_gate__h * var_chaste_interface__sodium_current_j_gate__j;
        const double var_x13 = 4.0 * pow(var_chaste_interface__sodium_current_m_gate__m, 3);
        const double var_x14 = var_x7 / var_chaste_interface__slow_inward_current__Cai;
        const double var_x15 = -50.0 + var_chaste_interface__membrane__V;
        const double var_x16 = var_x13 * var_x15;
        const double var_x17 = log(var_chaste_interface__slow_inward_current__Cai);
        const double var_x18 = 0.69291640829471179 - 0.089999999999999997 * var_chaste_interface__membrane__V - 1.1725829999999999 * var_x17;
        const double var_x19 = 6.9291640829471178e-5 - 9.0000000000000002e-6 * var_chaste_interface__membrane__V - 0.0001172583 * var_x17;
        const double var_x20 = exp(-4.032 - 0.056000000000000001 * var_chaste_interface__membrane__V);
        const double var_x21 = 1.0 - var_chaste_interface__sodium_current_m_gate__m;
        const double var_x22 = -0.10000000000000001 * var_chaste_interface__membrane__V;
        const double var_x23 = exp(-4.7000000000000002 + var_x22);
        const double var_x24 = -1.0 + var_x23;
        const double var_x25 = 1 / var_x24;
        const double var_x26 = 47.0 + var_chaste_interface__membrane__V;
        const double var_x27 = -0.25 * var_chaste_interface__membrane__V;
        const double var_x28 = exp(-19.25 + var_x27);
        const double var_x29 = exp(-1.845 - 0.082000000000000003 * var_chaste_interface__membrane__V);
        const double var_x30 = 1.0 + var_x29;
        const double var_x31 = 1.0 - var_chaste_interface__sodium_current_j_gate__j;
        const double var_x32 = exp(-15.600000000000001 - 0.20000000000000001 * var_chaste_interface__membrane__V);
        const double var_x33 = 1.0 + var_x32;
        const double var_x34 = exp(-19.5 + var_x27);
        const double var_x35 = var_x34 / var_x33;
        const double var_x36 = exp(-3.2000000000000002 + var_x22);
        const double var_x37 = 1.0 + var_x36;
        const double var_x38 = exp(2.2000000000000002 + 0.050000000000000003 * var_chaste_interface__membrane__V);
        const double var_x39 = 1.0 + var_x38;
        const double var_x40 = exp(-0.74576271186440679 - 0.016949152542372881 * var_chaste_interface__membrane__V);
        const double var_x41 = var_x40 / var_x39;
        const double var_x42 = 1.0 - var_chaste_interface__slow_inward_current_d_gate__d;
        const double var_x43 = exp(0.35997120230381568 - 0.071994240460763137 * var_chaste_interface__membrane__V);
        const double var_x44 = 1.0 + var_x43;
        const double var_x45 = exp(0.050000000000000003 - 0.01 * var_chaste_interface__membrane__V);
        const double var_x46 = var_x45 / var_x44;
        const double var_x47 = exp(-6.0 - 0.20000000000000001 * var_chaste_interface__membrane__V);
        const double var_x48 = 1.0 + var_x47;
        const double var_x49 = exp(-0.59999999999999998 - 0.02 * var_chaste_interface__membrane__V);
        const double var_x50 = var_x49 / var_x48;
        const double var_x51 = 1.0 - var_chaste_interface__slow_inward_current_f_gate__f;
        const double var_x52 = exp(4.197901049475262 + 0.14992503748125938 * var_chaste_interface__membrane__V);
        const double var_x53 = 1.0 + var_x52;
        const double var_x54 = exp(-0.224 - 0.0080000000000000002 * var_chaste_interface__membrane__V);
        const double var_x55 = var_x54 / var_x53;
        const double var_x56 = exp(-0.80000000000000004 - 0.040000000000000001 * var_chaste_interface__membrane__V);
        const double var_x57 = 1.0 + var_x56;
        const double var_x58 = exp(-1.1997600479904018 - 0.059988002399520089 * var_chaste_interface__membrane__V);
        const double var_x59 = var_x58 / var_x57;
        const double var_x60 = 1.0 - var_chaste_interface__time_dependent_outward_current_x1_gate__x1;
        const double var_x61 = exp(2.8571428571428572 + 0.057142857142857141 * var_chaste_interface__membrane__V);
        const double var_x62 = 1.0 + var_x61;
        const double var_x63 = exp(4.1322314049586781 + 0.082644628099173556 * var_chaste_interface__membrane__V);
        const double var_x64 = var_x63 / var_x62;
        
        // Matrix entries
        IJth(rJacobian, 0, 0) = mSetVoltageDerivativeToZero ? 0.0 : (-0.0030000000000000001 - 0.070000000000000007 / var_x2 - 0.089999999999999997 * var_x7 + var_x10 * var_x11 - var_x12 * var_x13 - 0.056000000000000001 * var_x6 / var_x5 - var_x11 * var_x8 * var_x9 + 0.0028000000000000004 * var_x1 * (23.0 + var_chaste_interface__membrane__V) / pow(var_x2, 2) - 1.3999999999999999 * (-1.0 + var_x6) * (-0.040000000000000001 * var_x3 - 0.080000000000000002 * var_x4) / pow(var_x5, 2));
        IJth(rJacobian, 1, 0) = -9.0000000000000002e-6 * var_x7;
        IJth(rJacobian, 2, 0) = -var_x21 * var_x25 + 2.2400000000000002 * var_x20 * var_chaste_interface__sodium_current_m_gate__m - 0.10000000000000001 * var_x21 * var_x23 * var_x26 / pow(var_x24, 2);
        IJth(rJacobian, 3, 0) = -0.25 * var_x28 * (0.126 - 0.126 * var_chaste_interface__sodium_current_h_gate__h) - 0.1394 * var_x29 * var_chaste_interface__sodium_current_h_gate__h / pow(var_x30, 2);
        IJth(rJacobian, 4, 0) = -0.01375 * var_x31 * var_x35 - 0.029999999999999999 * var_x36 * var_chaste_interface__sodium_current_j_gate__j / pow(var_x37, 2) + 0.011000000000000001 * var_x31 * var_x32 * var_x34 / pow(var_x33, 2);
        IJth(rJacobian, 5, 0) = 0.0011864406779661019 * var_x41 * var_chaste_interface__slow_inward_current_d_gate__d - 0.00095 * var_x42 * var_x46 + 0.0068394528437724983 * var_x42 * var_x43 * var_x45 / pow(var_x44, 2) + 0.0035000000000000005 * var_x38 * var_x40 * var_chaste_interface__slow_inward_current_d_gate__d / pow(var_x39, 2);
        IJth(rJacobian, 6, 0) = 0.00012999999999999999 * var_x50 * var_chaste_interface__slow_inward_current_f_gate__f - 9.6000000000000002e-5 * var_x51 * var_x55 - 0.0012999999999999999 * var_x47 * var_x49 * var_chaste_interface__slow_inward_current_f_gate__f / pow(var_x48, 2) - 0.0017991004497751124 * var_x51 * var_x52 * var_x54 / pow(var_x53, 2);
        IJth(rJacobian, 7, 0) = 7.7984403119376114e-5 * var_x59 * var_chaste_interface__time_dependent_outward_current_x1_gate__x1 + 4.132231404958678e-5 * var_x60 * var_x64 - 5.1999999999999997e-5 * var_x56 * var_x58 * var_chaste_interface__time_dependent_outward_current_x1_gate__x1 / pow(var_x57, 2) - 2.8571428571428571e-5 * var_x60 * var_x61 * var_x63 / pow(var_x62, 2);
        IJth(rJacobian, 0, 1) = mSetVoltageDerivativeToZero ? 0.0 : (-1.1725829999999999 * var_x14);
        IJth(rJacobian, 1, 1) = -0.070000000000000007 - 0.0001172583 * var_x14;
        IJth(rJacobian, 0, 2) = mSetVoltageDerivativeToZero ? 0.0 : (-12.0 * var_x12 * var_x15 * pow(var_chaste_interface__sodium_current_m_gate__m, 2));
        IJth(rJacobian, 2, 2) = -40.0 * var_x20 + var_x25 * var_x26;
        IJth(rJacobian, 0, 3) = mSetVoltageDerivativeToZero ? 0.0 : (-var_x16 * var_chaste_interface__sodium_current_j_gate__j);
        IJth(rJacobian, 3, 3) = -0.126 * var_x28 - 1.7 / var_x30;
        IJth(rJacobian, 0, 4) = mSetVoltageDerivativeToZero ? 0.0 : (-var_x16 * var_chaste_interface__sodium_current_h_gate__h);
        IJth(rJacobian, 4, 4) = -0.29999999999999999 / var_x37 - 0.055 * var_x35;
        IJth(rJacobian, 0, 5) = mSetVoltageDerivativeToZero ? 0.0 : (var_x18 * var_chaste_interface__slow_inward_current_f_gate__f);
        IJth(rJacobian, 1, 5) = var_x19 * var_chaste_interface__slow_inward_current_f_gate__f;
        IJth(rJacobian, 5, 5) = -0.070000000000000007 * var_x41 - 0.095000000000000001 * var_x46;
        IJth(rJacobian, 0, 6) = mSetVoltageDerivativeToZero ? 0.0 : (var_x18 * var_chaste_interface__slow_inward_current_d_gate__d);
        IJth(rJacobian, 1, 6) = var_x19 * var_chaste_interface__slow_inward_current_d_gate__d;
        IJth(rJacobian, 6, 6) = -0.012 * var_x55 - 0.0064999999999999997 * var_x50;
        IJth(rJacobian, 0, 7) = mSetVoltageDerivativeToZero ? 0.0 : (-0.80000000000000004 * var_x10);
        IJth(rJacobian, 7, 7) = -0.00050000000000000001 * var_x64 - 0.0012999999999999999 * var_x59;
    }

    N_Vector Cellbeeler_reuter_model_1977FromCellMLCvode::ComputeDerivedQuantities(double var_chaste_interface__environment__time, const N_Vector & rY)
    {
        // Inputs:
        // Time units: millisecond
        
        // Mathematics
        const double var_stimulus_protocol__Istim_converted = -GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_cm2

        N_Vector dqs = N_VNew_Serial(2);
        NV_Ith_S(dqs, 0) = var_chaste_interface__environment__time;
        NV_Ith_S(dqs, 1) = var_stimulus_protocol__Istim_converted;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellbeeler_reuter_model_1977FromCellMLCvode>::Initialise(void)
{
    this->mSystemName = "beeler_reuter_model_1977";
    this->mFreeVariableName = "environment__time";
    this->mFreeVariableUnits = "ms";

    // NV_Ith_S(rY, 0):
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("mV");
    this->mInitialConditions.push_back(-84.624);

    // NV_Ith_S(rY, 1):
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("concentration_units");
    this->mInitialConditions.push_back(0.0001);

    // NV_Ith_S(rY, 2):
    this->mVariableNames.push_back("sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.011);

    // NV_Ith_S(rY, 3):
    this->mVariableNames.push_back("sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.988);

    // NV_Ith_S(rY, 4):
    this->mVariableNames.push_back("sodium_current_j_gate__j");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.975);

    // NV_Ith_S(rY, 5):
    this->mVariableNames.push_back("slow_inward_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.003);

    // NV_Ith_S(rY, 6):
    this->mVariableNames.push_back("slow_inward_current_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.994);

    // NV_Ith_S(rY, 7):
    this->mVariableNames.push_back("time_dependent_outward_current_x1_gate__x1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0001);

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("environment__time");
    this->mDerivedQuantityUnits.push_back("ms");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellbeeler_reuter_model_1977FromCellMLCvode)
#endif // CHASTE_CVODE
