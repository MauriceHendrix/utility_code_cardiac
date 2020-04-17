//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: priebe_beuckelmann_model_1998
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on 2020-04-09 01:31:16
//!
//! <autogenerated>

#include "priebe_beuckelmann_model_1998.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__cell__stim_amplitude = -15.0 * HeartConfig::Instance()->GetCapacitance(); // uA_per_uF
        const double var_chaste_interface__cell__stim_duration = 3.0; // millisecond
        const double var_chaste_interface__cell__stim_offset = 0.0; // millisecond
        const double var_chaste_interface__cell__stim_period = 1000.0; // millisecond
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__cell__stim_amplitude),
                var_chaste_interface__cell__stim_duration,
                var_chaste_interface__cell__stim_period,
                var_chaste_interface__cell__stim_offset
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }


    double Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen::Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractRushLarsenCardiacCell(
                22,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
    }

    Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen::~Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen()
    {
    }
    
    double Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__cell__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -90.7796417483135
        double var_chaste_interface__Ionic_concentrations__Cai = rY[1];
        // Units: mM; Initial value: 0.0002
        double var_chaste_interface__INa_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.000585525582501575
        double var_chaste_interface__INa_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.995865529216237
        double var_chaste_interface__INa_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 0.997011204496203
        double var_chaste_interface__ICa_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 2.50653215966786e-10
        double var_chaste_interface__ICa_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 0.92130376850548
        double var_chaste_interface__Ito_r_gate__r = rY[7];
        // Units: dimensionless; Initial value: 1.75032478501027e-05
        double var_chaste_interface__Ito_t_gate__t = rY[8];
        // Units: dimensionless; Initial value: 0.999897251531651
        double var_chaste_interface__IKs_Xs_gate__Xs = rY[9];
        // Units: dimensionless; Initial value: 0.00885658064818147
        double var_chaste_interface__IKr_Xr_gate__Xr = rY[10];
        // Units: dimensionless; Initial value: 0.000215523048438941
        double var_chaste_interface__Ionic_concentrations__Nai = rY[18];
        // Units: mM; Initial value: 10.0
        double var_chaste_interface__Ionic_concentrations__Ki = rY[19];
        // Units: mM; Initial value: 140.0
        
        const double var_ICa__E_Ca = 13.36287874390978 * log(2.0 / var_chaste_interface__Ionic_concentrations__Cai); // mV
        const double var_IK1__E_K1 = 26.725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki); // mV
        const double var_INa__E_Na = 26.725757487819561 * log(138.0 / var_chaste_interface__Ionic_concentrations__Nai); // mV
        const double var_cell__dVdt = 0.001 * var_INa__E_Na + 0.00084999999999999995 * var_ICa__E_Ca - 0.0018500000000000001 * var_chaste_interface__cell__V - 0.02 * pow(var_chaste_interface__IKs_Xs_gate__Xs, 2) * (-26.725757487819561 * log(6.5295399999999999 / (1.0 * var_chaste_interface__Ionic_concentrations__Ki + 0.018329999999999999 * var_chaste_interface__Ionic_concentrations__Nai)) + var_chaste_interface__cell__V) - 8.9708471082494196e-5 * (2.0 * pow(var_chaste_interface__Ionic_concentrations__Nai, 3) * exp(0.013095980540851452 * var_chaste_interface__cell__V) - 2628072.0 * var_chaste_interface__Ionic_concentrations__Cai * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) / (1.0 + 0.10000000000000001 * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) - 0.94545454545454544 / ((1.0 + 31.622776601683793 * pow(1 / var_chaste_interface__Ionic_concentrations__Nai, 1.5)) * (1.0 + 0.1245 * exp(-0.0037417087259575582 * var_chaste_interface__cell__V) + 0.036499999999999998 * (-0.14285714285714285 + 0.14285714285714285 * exp(2.0505200594353643)) * exp(-0.037417087259575585 * var_chaste_interface__cell__V))) - 0.014999999999999999 * (-26.725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki) + var_chaste_interface__cell__V) * var_chaste_interface__IKr_Xr_gate__Xr / (1.0 + exp(1.1304347826086956 + 0.043478260869565216 * var_chaste_interface__cell__V)) - 0.29999999999999999 * (-26.725757487819561 * log(9.9339999999999993 / (1.0 * var_chaste_interface__Ionic_concentrations__Ki + 0.042999999999999997 * var_chaste_interface__Ionic_concentrations__Nai)) + var_chaste_interface__cell__V) * var_chaste_interface__Ito_r_gate__r * var_chaste_interface__Ito_t_gate__t - 0.25 * (-var_IK1__E_K1 + var_chaste_interface__cell__V) / ((1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__cell__V - 0.059999999999999998 * var_IK1__E_K1)) * (0.10000000000000001 / (1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__cell__V - 0.059999999999999998 * var_IK1__E_K1)) + (1.0 * exp(-1.0 + 0.10000000000000001 * var_chaste_interface__cell__V - 0.10000000000000001 * var_IK1__E_K1) + 3.0 * exp(0.02 + 0.00020000000000000001 * var_chaste_interface__cell__V - 0.00020000000000000001 * var_IK1__E_K1)) / (1.0 + exp(0.5 * var_IK1__E_K1 - 0.5 * var_chaste_interface__cell__V)))) - 16.0 * pow(var_chaste_interface__INa_m_gate__m, 3) * (-var_INa__E_Na + var_chaste_interface__cell__V) * var_chaste_interface__INa_h_gate__h * var_chaste_interface__INa_j_gate__j - 3.8399999999999998e-5 * (-var_ICa__E_Ca + var_chaste_interface__cell__V) * var_chaste_interface__ICa_d_gate__d * var_chaste_interface__ICa_f_gate__f / (0.00059999999999999995 + var_chaste_interface__Ionic_concentrations__Cai); // mV_per_ms
        const double var_chaste_interface__i_ionic = HeartConfig::Instance()->GetCapacitance() * var_cell__dVdt; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen::EvaluateEquations(double var_chaste_interface__environment__time, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__cell__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -90.7796417483135
        double var_chaste_interface__Ionic_concentrations__Cai = rY[1];
        // Units: mM; Initial value: 0.0002
        double var_chaste_interface__INa_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.000585525582501575
        double var_chaste_interface__INa_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.995865529216237
        double var_chaste_interface__INa_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 0.997011204496203
        double var_chaste_interface__ICa_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 2.50653215966786e-10
        double var_chaste_interface__ICa_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 0.92130376850548
        double var_chaste_interface__Ito_r_gate__r = rY[7];
        // Units: dimensionless; Initial value: 1.75032478501027e-05
        double var_chaste_interface__Ito_t_gate__t = rY[8];
        // Units: dimensionless; Initial value: 0.999897251531651
        double var_chaste_interface__IKs_Xs_gate__Xs = rY[9];
        // Units: dimensionless; Initial value: 0.00885658064818147
        double var_chaste_interface__IKr_Xr_gate__Xr = rY[10];
        // Units: dimensionless; Initial value: 0.000215523048438941
        double var_chaste_interface__Irel__APtrack = rY[11];
        // Units: dimensionless; Initial value: -1.372158997089e-136
        double var_chaste_interface__Irel__APtrack2 = rY[12];
        // Units: dimensionless; Initial value: -7.58517896402761e-136
        double var_chaste_interface__Irel__APtrack3 = rY[13];
        // Units: dimensionless; Initial value: 4.82035353592764e-05
        double var_chaste_interface__Irel__Cainfluxtrack = rY[14];
        // Units: mM; Initial value: -7.71120176147331e-138
        
        // Units: dimensionless; Initial value: 1e-06
        
        // Units: dimensionless; Initial value: 1e-06
        
        // Units: dimensionless; Initial value: 1e-06
        double var_chaste_interface__Ionic_concentrations__Nai = rY[18];
        // Units: mM; Initial value: 10.0
        double var_chaste_interface__Ionic_concentrations__Ki = rY[19];
        // Units: mM; Initial value: 140.0
        double var_chaste_interface__Ionic_concentrations__Ca_JSR = rY[20];
        // Units: mM; Initial value: 2.5
        double var_chaste_interface__Ionic_concentrations__Ca_NSR = rY[21];
        // Units: mM; Initial value: 2.5

        // Mathematics
        double d_dt_chaste_interface_var_cell__V;
        const double d_dt_chaste_interface_var_Irel__OVRLDtrack = 0; // 1 / ms
        const double d_dt_chaste_interface_var_Irel__OVRLDtrack2 = 0; // 1 / ms
        const double d_dt_chaste_interface_var_Irel__OVRLDtrack3 = 0; // 1 / ms
        const double d_dt_chaste_interface_var_Irel__APtrack2 = (((var_chaste_interface__Irel__APtrack > 0.17999999999999999) && (var_chaste_interface__Irel__APtrack < 0.20000000000000001)) ? (100.0 - 100.5 * var_chaste_interface__Irel__APtrack2) : (-0.5 * var_chaste_interface__Irel__APtrack2)); // 1 / ms
        const double d_dt_chaste_interface_var_Irel__APtrack3 = (((var_chaste_interface__Irel__APtrack > 0.17999999999999999) && (var_chaste_interface__Irel__APtrack < 0.20000000000000001)) ? (100.0 - 100.5 * var_chaste_interface__Irel__APtrack3) : (-0.01 * var_chaste_interface__Irel__APtrack3)); // 1 / ms
        const double d_dt_chaste_interface_var_Ionic_concentrations__Ca_JSR = 1.0 * (0.0055555555555555558 * var_chaste_interface__Ionic_concentrations__Ca_NSR - 0.0055555555555555558 * var_chaste_interface__Ionic_concentrations__Ca_JSR - (-var_chaste_interface__Ionic_concentrations__Cai + var_chaste_interface__Ionic_concentrations__Ca_JSR) * ((var_chaste_interface__Irel__Cainfluxtrack > 5.0000000000000004e-6) ? (22.0 * (1.0 - var_chaste_interface__Irel__APtrack2) * (-5.0000000000000004e-6 + var_chaste_interface__Irel__Cainfluxtrack) * var_chaste_interface__Irel__APtrack2 / (0.00079500000000000003 + var_chaste_interface__Irel__Cainfluxtrack)) : (0.0))) / (1.0 + 8.0 / pow((0.80000000000000004 + var_chaste_interface__Ionic_concentrations__Ca_JSR), 2)); // mM / ms
        const double var_ICa_d_gate__alpha_d = 0.63524014987941491 * exp(-0.89836705491478086 * pow((-1 + 0.044722719141323794 * var_chaste_interface__cell__V), 2)) / sqrt(M_PI); // per_ms
        const double var_ICa_d_gate__beta_d = 0.14710000000000001 - 0.25101580310038191 * exp(-0.08830693125184777 * pow((-1 + 0.15937778911130945 * var_chaste_interface__cell__V), 2)) / sqrt(M_PI); // per_ms
        const double var_ICa_f_gate__alpha_f = 0.0068719999999999996 / (1.0 + exp(-1.0052757950443461 + 0.16333730787449161 * var_chaste_interface__cell__V)); // per_ms
        const double var_ICa_f_gate__beta_f = 0.00054739999999999997 + (0.0112 + 0.068699999999999997 * exp(-1.06213655 - 0.1081 * var_chaste_interface__cell__V)) / (1.0 + exp(-2.7305064499999996 - 0.27789999999999998 * var_chaste_interface__cell__V)); // per_ms
        const double var_IKr_Xr_gate__alpha_Xr = 0.0050000000000000001 * exp(0.0021416822000000003 + 0.00052660000000000001 * var_chaste_interface__cell__V) / (1.0 + exp(-0.51325540000000003 - 0.12620000000000001 * var_chaste_interface__cell__V)); // per_ms
        const double var_IKr_Xr_gate__beta_Xr = 0.016 * exp(0.105056 + 0.0016000000000000001 * var_chaste_interface__cell__V) / (1.0 + exp(5.1411779999999991 + 0.078299999999999995 * var_chaste_interface__cell__V)); // per_ms
        const double var_IKs_Xs_gate__alpha_Xs = 0.0030130000000000001 / (1.0 + exp(-0.17842998931347828 - 0.069846547135942336 * var_chaste_interface__cell__V)); // per_ms
        const double var_IKs_Xs_gate__beta_Xs = 0.0058700000000000002 / (1.0 + exp(1.0082174462705435 + 0.063211125158027806 * var_chaste_interface__cell__V)); // per_ms
        const double var_INa_h_gate__alpha_h = ((var_chaste_interface__cell__V < -40.0) ? (0.13500000000000001 * exp(-11.764705882352942 - 0.14705882352941177 * var_chaste_interface__cell__V)) : (0.0)); // per_ms
        const double var_INa_h_gate__beta_h = ((var_chaste_interface__cell__V < -40.0) ? (310000.0 * exp(0.34999999999999998 * var_chaste_interface__cell__V) + 3.5600000000000001 * exp(0.079000000000000001 * var_chaste_interface__cell__V)) : (7.6923076923076916 / (1.0 + exp(-0.96036036036036043 - 0.0900900900900901 * var_chaste_interface__cell__V)))); // per_ms
        const double var_INa_j_gate__alpha_j = ((var_chaste_interface__cell__V < -40.0) ? ((37.780000000000001 + var_chaste_interface__cell__V) * (-127140.0 * exp(0.24399999999999999 * var_chaste_interface__cell__V) - 3.4740000000000003e-5 * exp(-0.043909999999999998 * var_chaste_interface__cell__V)) / (1.0 + exp(24.640530000000002 + 0.311 * var_chaste_interface__cell__V))) : (0.0)); // per_ms
        const double var_INa_j_gate__beta_j = ((var_chaste_interface__cell__V < -40.0) ? (0.1212 * exp(-0.01052 * var_chaste_interface__cell__V) / (1.0 + exp(-5.5312920000000005 - 0.13780000000000001 * var_chaste_interface__cell__V))) : (0.29999999999999999 * exp(-2.5349999999999999e-7 * var_chaste_interface__cell__V) / (1.0 + exp(-3.2000000000000002 - 0.10000000000000001 * var_chaste_interface__cell__V)))); // per_ms
        const double var_INa_m_gate__alpha_m = ((fabs(47.130000000000003 + var_chaste_interface__cell__V) > 0.001) ? (0.32000000000000001 * (47.130000000000003 + var_chaste_interface__cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * var_chaste_interface__cell__V))) : (3.2000000000000002)); // per_ms
        const double var_INa_m_gate__beta_m = 0.080000000000000002 * exp(-0.090909090909090912 * var_chaste_interface__cell__V); // per_ms
        const double var_Ito_r_gate__alpha_r = 0.52659999999999996 * exp(0.70203392000000009 - 0.0166 * var_chaste_interface__cell__V) / (1.0 + exp(3.9880601600000003 - 0.094299999999999995 * var_chaste_interface__cell__V)); // per_ms
        const double var_Ito_r_gate__beta_r = (0.51490000000000002 * exp(0.67236288 - 0.13439999999999999 * var_chaste_interface__cell__V) + 5.1860000000000002e-5 * var_chaste_interface__cell__V) / (1.0 + exp(6.9907280000000006e-6 - 0.1348 * var_chaste_interface__cell__V)); // per_ms
        const double var_Ito_t_gate__alpha_t = (5.6119999999999998e-5 * var_chaste_interface__cell__V + 0.072099999999999997 * exp(-5.9257863000000004 - 0.17299999999999999 * var_chaste_interface__cell__V)) / (1.0 + exp(-5.9326369200000002 - 0.17319999999999999 * var_chaste_interface__cell__V)); // per_ms
        const double var_Ito_t_gate__beta_t = (0.0001215 * var_chaste_interface__cell__V + 0.076700000000000004 * exp(-5.6479010000000002e-8 - 1.6600000000000001e-9 * var_chaste_interface__cell__V)) / (1.0 + exp(-5.4573693999999993 - 0.16039999999999999 * var_chaste_interface__cell__V)); // per_ms
        const double d_dt_chaste_interface_var_Irel__Cainfluxtrack = ((var_chaste_interface__Irel__APtrack > 0.20000000000000001) ? (-9.661256841321762e-5 * (0.00084999999999999995 * var_chaste_interface__cell__V - 0.011358446932323314 * log(2.0 / var_chaste_interface__Ionic_concentrations__Cai) - 8.9708471082494196e-5 * (2.0 * pow(var_chaste_interface__Ionic_concentrations__Nai, 3) * exp(0.013095980540851452 * var_chaste_interface__cell__V) - 2628072.0 * var_chaste_interface__Ionic_concentrations__Cai * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) / (1.0 + 0.10000000000000001 * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) + 3.8399999999999998e-5 * (-13.36287874390978 * log(2.0 / var_chaste_interface__Ionic_concentrations__Cai) + var_chaste_interface__cell__V) * var_chaste_interface__ICa_d_gate__d * var_chaste_interface__ICa_f_gate__f / (0.00059999999999999995 + var_chaste_interface__Ionic_concentrations__Cai)) / M_PI) : ((var_chaste_interface__Irel__APtrack2 > 0.01) ? (0.0) : (-0.5 * var_chaste_interface__Irel__Cainfluxtrack))); // mM / ms
        const double d_dt_chaste_interface_var_Ionic_concentrations__Nai = -0.00019322513682643524 * (0.001 * var_chaste_interface__cell__V - 0.026725757487819562 * log(138.0 / var_chaste_interface__Ionic_concentrations__Nai) + 0.00026912541324748262 * (2.0 * pow(var_chaste_interface__Ionic_concentrations__Nai, 3) * exp(0.013095980540851452 * var_chaste_interface__cell__V) - 2628072.0 * var_chaste_interface__Ionic_concentrations__Cai * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) / (1.0 + 0.10000000000000001 * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) + 2.8363636363636364 / ((1.0 + 31.622776601683793 * pow(1 / var_chaste_interface__Ionic_concentrations__Nai, 1.5)) * (1.0 + 0.1245 * exp(-0.0037417087259575582 * var_chaste_interface__cell__V) + 0.036499999999999998 * (-0.14285714285714285 + 0.14285714285714285 * exp(2.0505200594353643)) * exp(-0.037417087259575585 * var_chaste_interface__cell__V))) + 16.0 * pow(var_chaste_interface__INa_m_gate__m, 3) * (-26.725757487819561 * log(138.0 / var_chaste_interface__Ionic_concentrations__Nai) + var_chaste_interface__cell__V) * var_chaste_interface__INa_h_gate__h * var_chaste_interface__INa_j_gate__j) / M_PI; // mM / ms
        const double d_dt_chaste_interface_var_Ionic_concentrations__Ca_NSR = 0.00048309178743961351 * var_chaste_interface__Ionic_concentrations__Ca_JSR - 0.00074309178743961349 * var_chaste_interface__Ionic_concentrations__Ca_NSR + 0.0044999999999999997 * var_chaste_interface__Ionic_concentrations__Cai / (0.00092000000000000003 + var_chaste_interface__Ionic_concentrations__Cai); // mM / ms
        const double d_dt_chaste_interface_var_Ionic_concentrations__Cai = 1.0 * (2.1105882352941172e-5 * var_chaste_interface__Ionic_concentrations__Ca_NSR + 0.0070588235294117632 * (-var_chaste_interface__Ionic_concentrations__Cai + var_chaste_interface__Ionic_concentrations__Ca_JSR) * ((var_chaste_interface__Irel__Cainfluxtrack > 5.0000000000000004e-6) ? (22.0 * (1.0 - var_chaste_interface__Irel__APtrack2) * (-5.0000000000000004e-6 + var_chaste_interface__Irel__Cainfluxtrack) * var_chaste_interface__Irel__APtrack2 / (0.00079500000000000003 + var_chaste_interface__Irel__Cainfluxtrack)) : (0.0)) - 0.00036529411764705876 * var_chaste_interface__Ionic_concentrations__Cai / (0.00092000000000000003 + var_chaste_interface__Ionic_concentrations__Cai) - 9.661256841321762e-5 * (0.00084999999999999995 * var_chaste_interface__cell__V - 0.011358446932323314 * log(2.0 / var_chaste_interface__Ionic_concentrations__Cai) - 0.00017941694216498839 * (2.0 * pow(var_chaste_interface__Ionic_concentrations__Nai, 3) * exp(0.013095980540851452 * var_chaste_interface__cell__V) - 2628072.0 * var_chaste_interface__Ionic_concentrations__Cai * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) / (1.0 + 0.10000000000000001 * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) + 3.8399999999999998e-5 * (-13.36287874390978 * log(2.0 / var_chaste_interface__Ionic_concentrations__Cai) + var_chaste_interface__cell__V) * var_chaste_interface__ICa_d_gate__d * var_chaste_interface__ICa_f_gate__f / (0.00059999999999999995 + var_chaste_interface__Ionic_concentrations__Cai)) / M_PI) / (1.0 + 0.00011900000000000002 / pow((0.0023800000000000002 + var_chaste_interface__Ionic_concentrations__Cai), 2) + 3.5000000000000004e-5 / pow((0.00050000000000000001 + var_chaste_interface__Ionic_concentrations__Cai), 2)); // mM / ms
        const double d_dt_chaste_interface_var_Ionic_concentrations__Ki = -0.00019322513682643524 * (GetIntracellularAreaStimulus(var_chaste_interface__environment__time) / HeartConfig::Instance()->GetCapacitance() + 0.02 * pow(var_chaste_interface__IKs_Xs_gate__Xs, 2) * (-26.725757487819561 * log(6.5295399999999999 / (1.0 * var_chaste_interface__Ionic_concentrations__Ki + 0.018329999999999999 * var_chaste_interface__Ionic_concentrations__Nai)) + var_chaste_interface__cell__V) - 1.8909090909090909 / ((1.0 + 31.622776601683793 * pow(1 / var_chaste_interface__Ionic_concentrations__Nai, 1.5)) * (1.0 + 0.1245 * exp(-0.0037417087259575582 * var_chaste_interface__cell__V) + 0.036499999999999998 * (-0.14285714285714285 + 0.14285714285714285 * exp(2.0505200594353643)) * exp(-0.037417087259575585 * var_chaste_interface__cell__V))) + 0.014999999999999999 * (-26.725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki) + var_chaste_interface__cell__V) * var_chaste_interface__IKr_Xr_gate__Xr / (1.0 + exp(1.1304347826086956 + 0.043478260869565216 * var_chaste_interface__cell__V)) + 0.29999999999999999 * (-26.725757487819561 * log(9.9339999999999993 / (1.0 * var_chaste_interface__Ionic_concentrations__Ki + 0.042999999999999997 * var_chaste_interface__Ionic_concentrations__Nai)) + var_chaste_interface__cell__V) * var_chaste_interface__Ito_r_gate__r * var_chaste_interface__Ito_t_gate__t + 0.25 * (-26.725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki) + var_chaste_interface__cell__V) / ((1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__cell__V - 1.6035454492691736 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki))) * (0.10000000000000001 / (1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__cell__V - 1.6035454492691736 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki))) + (1.0 * exp(-1.0 + 0.10000000000000001 * var_chaste_interface__cell__V - 2.6725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki)) + 3.0 * exp(0.02 + 0.00020000000000000001 * var_chaste_interface__cell__V - 0.0053451514975639122 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki))) / (1.0 + exp(13.36287874390978 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki) - 0.5 * var_chaste_interface__cell__V))))) / M_PI; // mM / ms
        const double d_dt_chaste_interface_var_Irel__APtrack = ((0.0018500000000000001 * var_chaste_interface__cell__V - 0.026725757487819562 * log(138.0 / var_chaste_interface__Ionic_concentrations__Nai) - 0.011358446932323314 * log(2.0 / var_chaste_interface__Ionic_concentrations__Cai) + 1.0 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time) / HeartConfig::Instance()->GetCapacitance() + 0.02 * pow(var_chaste_interface__IKs_Xs_gate__Xs, 2) * (-26.725757487819561 * log(6.5295399999999999 / (1.0 * var_chaste_interface__Ionic_concentrations__Ki + 0.018329999999999999 * var_chaste_interface__Ionic_concentrations__Nai)) + var_chaste_interface__cell__V) + 8.9708471082494196e-5 * (2.0 * pow(var_chaste_interface__Ionic_concentrations__Nai, 3) * exp(0.013095980540851452 * var_chaste_interface__cell__V) - 2628072.0 * var_chaste_interface__Ionic_concentrations__Cai * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) / (1.0 + 0.10000000000000001 * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) + 0.94545454545454544 / ((1.0 + 31.622776601683793 * pow(1 / var_chaste_interface__Ionic_concentrations__Nai, 1.5)) * (1.0 + 0.1245 * exp(-0.0037417087259575582 * var_chaste_interface__cell__V) + 0.036499999999999998 * (-0.14285714285714285 + 0.14285714285714285 * exp(2.0505200594353643)) * exp(-0.037417087259575585 * var_chaste_interface__cell__V))) + 0.014999999999999999 * (-26.725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki) + var_chaste_interface__cell__V) * var_chaste_interface__IKr_Xr_gate__Xr / (1.0 + exp(1.1304347826086956 + 0.043478260869565216 * var_chaste_interface__cell__V)) + 0.29999999999999999 * (-26.725757487819561 * log(9.9339999999999993 / (1.0 * var_chaste_interface__Ionic_concentrations__Ki + 0.042999999999999997 * var_chaste_interface__Ionic_concentrations__Nai)) + var_chaste_interface__cell__V) * var_chaste_interface__Ito_r_gate__r * var_chaste_interface__Ito_t_gate__t + 0.25 * (-26.725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki) + var_chaste_interface__cell__V) / ((1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__cell__V - 1.6035454492691736 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki))) * (0.10000000000000001 / (1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__cell__V - 1.6035454492691736 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki))) + (1.0 * exp(-1.0 + 0.10000000000000001 * var_chaste_interface__cell__V - 2.6725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki)) + 3.0 * exp(0.02 + 0.00020000000000000001 * var_chaste_interface__cell__V - 0.0053451514975639122 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki))) / (1.0 + exp(13.36287874390978 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki) - 0.5 * var_chaste_interface__cell__V)))) + 16.0 * pow(var_chaste_interface__INa_m_gate__m, 3) * (-26.725757487819561 * log(138.0 / var_chaste_interface__Ionic_concentrations__Nai) + var_chaste_interface__cell__V) * var_chaste_interface__INa_h_gate__h * var_chaste_interface__INa_j_gate__j + 3.8399999999999998e-5 * (-13.36287874390978 * log(2.0 / var_chaste_interface__Ionic_concentrations__Cai) + var_chaste_interface__cell__V) * var_chaste_interface__ICa_d_gate__d * var_chaste_interface__ICa_f_gate__f / (0.00059999999999999995 + var_chaste_interface__Ionic_concentrations__Cai) < -150.0) ? (100.0 - 100.5 * var_chaste_interface__Irel__APtrack) : (-0.5 * var_chaste_interface__Irel__APtrack)); // 1 / ms

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_cell__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_cell__V = 0.026725757487819562 * log(138.0 / var_chaste_interface__Ionic_concentrations__Nai) + 0.011358446932323314 * log(2.0 / var_chaste_interface__Ionic_concentrations__Cai) - 0.0018500000000000001 * var_chaste_interface__cell__V - 1.0 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time) / HeartConfig::Instance()->GetCapacitance() - 0.02 * pow(var_chaste_interface__IKs_Xs_gate__Xs, 2) * (-26.725757487819561 * log(6.5295399999999999 / (1.0 * var_chaste_interface__Ionic_concentrations__Ki + 0.018329999999999999 * var_chaste_interface__Ionic_concentrations__Nai)) + var_chaste_interface__cell__V) - 8.9708471082494196e-5 * (2.0 * pow(var_chaste_interface__Ionic_concentrations__Nai, 3) * exp(0.013095980540851452 * var_chaste_interface__cell__V) - 2628072.0 * var_chaste_interface__Ionic_concentrations__Cai * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) / (1.0 + 0.10000000000000001 * exp(-0.024321106718724127 * var_chaste_interface__cell__V)) - 0.94545454545454544 / ((1.0 + 31.622776601683793 * pow(1 / var_chaste_interface__Ionic_concentrations__Nai, 1.5)) * (1.0 + 0.1245 * exp(-0.0037417087259575582 * var_chaste_interface__cell__V) + 0.036499999999999998 * (-0.14285714285714285 + 0.14285714285714285 * exp(2.0505200594353643)) * exp(-0.037417087259575585 * var_chaste_interface__cell__V))) - 0.014999999999999999 * (-26.725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki) + var_chaste_interface__cell__V) * var_chaste_interface__IKr_Xr_gate__Xr / (1.0 + exp(1.1304347826086956 + 0.043478260869565216 * var_chaste_interface__cell__V)) - 0.29999999999999999 * (-26.725757487819561 * log(9.9339999999999993 / (1.0 * var_chaste_interface__Ionic_concentrations__Ki + 0.042999999999999997 * var_chaste_interface__Ionic_concentrations__Nai)) + var_chaste_interface__cell__V) * var_chaste_interface__Ito_r_gate__r * var_chaste_interface__Ito_t_gate__t - 0.25 * (-26.725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki) + var_chaste_interface__cell__V) / ((1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__cell__V - 1.6035454492691736 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki))) * (0.10000000000000001 / (1.0 + exp(-12.0 + 0.059999999999999998 * var_chaste_interface__cell__V - 1.6035454492691736 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki))) + (1.0 * exp(-1.0 + 0.10000000000000001 * var_chaste_interface__cell__V - 2.6725757487819561 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki)) + 3.0 * exp(0.02 + 0.00020000000000000001 * var_chaste_interface__cell__V - 0.0053451514975639122 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki))) / (1.0 + exp(13.36287874390978 * log(4.0 / var_chaste_interface__Ionic_concentrations__Ki) - 0.5 * var_chaste_interface__cell__V)))) - 16.0 * pow(var_chaste_interface__INa_m_gate__m, 3) * (-26.725757487819561 * log(138.0 / var_chaste_interface__Ionic_concentrations__Nai) + var_chaste_interface__cell__V) * var_chaste_interface__INa_h_gate__h * var_chaste_interface__INa_j_gate__j - 3.8399999999999998e-5 * (-13.36287874390978 * log(2.0 / var_chaste_interface__Ionic_concentrations__Cai) + var_chaste_interface__cell__V) * var_chaste_interface__ICa_d_gate__d * var_chaste_interface__ICa_f_gate__f / (0.00059999999999999995 + var_chaste_interface__Ionic_concentrations__Cai); // mV / ms
        }
        
        rDY[0] = d_dt_chaste_interface_var_cell__V;
        rDY[1] = d_dt_chaste_interface_var_Ionic_concentrations__Cai;
        rAlphaOrTau[2] = var_INa_m_gate__alpha_m;
        rBetaOrInf[2] = var_INa_m_gate__beta_m;
        rAlphaOrTau[3] = var_INa_h_gate__alpha_h;
        rBetaOrInf[3] = var_INa_h_gate__beta_h;
        rAlphaOrTau[4] = var_INa_j_gate__alpha_j;
        rBetaOrInf[4] = var_INa_j_gate__beta_j;
        rAlphaOrTau[5] = var_ICa_d_gate__alpha_d;
        rBetaOrInf[5] = var_ICa_d_gate__beta_d;
        rAlphaOrTau[6] = var_ICa_f_gate__alpha_f;
        rBetaOrInf[6] = var_ICa_f_gate__beta_f;
        rAlphaOrTau[7] = var_Ito_r_gate__alpha_r;
        rBetaOrInf[7] = var_Ito_r_gate__beta_r;
        rAlphaOrTau[8] = var_Ito_t_gate__alpha_t;
        rBetaOrInf[8] = var_Ito_t_gate__beta_t;
        rAlphaOrTau[9] = var_IKs_Xs_gate__alpha_Xs;
        rBetaOrInf[9] = var_IKs_Xs_gate__beta_Xs;
        rAlphaOrTau[10] = var_IKr_Xr_gate__alpha_Xr;
        rBetaOrInf[10] = var_IKr_Xr_gate__beta_Xr;
        rDY[11] = d_dt_chaste_interface_var_Irel__APtrack;
        rDY[12] = d_dt_chaste_interface_var_Irel__APtrack2;
        rDY[13] = d_dt_chaste_interface_var_Irel__APtrack3;
        rDY[14] = d_dt_chaste_interface_var_Irel__Cainfluxtrack;
        rDY[15] = d_dt_chaste_interface_var_Irel__OVRLDtrack;
        rDY[16] = d_dt_chaste_interface_var_Irel__OVRLDtrack2;
        rDY[17] = d_dt_chaste_interface_var_Irel__OVRLDtrack3;
        rDY[18] = d_dt_chaste_interface_var_Ionic_concentrations__Nai;
        rDY[19] = d_dt_chaste_interface_var_Ionic_concentrations__Ki;
        rDY[20] = d_dt_chaste_interface_var_Ionic_concentrations__Ca_JSR;
        rDY[21] = d_dt_chaste_interface_var_Ionic_concentrations__Ca_NSR;
    }
    void Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen::ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf)
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
        {
            const double tau_inv = rAlphaOrTau[8] + rBetaOrInf[8];
            const double y_inf = rAlphaOrTau[8] / tau_inv;
            rY[8] = y_inf + (rY[8] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[9] + rBetaOrInf[9];
            const double y_inf = rAlphaOrTau[9] / tau_inv;
            rY[9] = y_inf + (rY[9] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[10] + rBetaOrInf[10];
            const double y_inf = rAlphaOrTau[10] / tau_inv;
            rY[10] = y_inf + (rY[10] - y_inf)*exp(-mDt*tau_inv);
        }
        rY[11] += mDt * rDY[11];
        rY[12] += mDt * rDY[12];
        rY[13] += mDt * rDY[13];
        rY[14] += mDt * rDY[14];
        rY[15] += mDt * rDY[15];
        rY[16] += mDt * rDY[16];
        rY[17] += mDt * rDY[17];
        rY[18] += mDt * rDY[18];
        rY[19] += mDt * rDY[19];
        rY[20] += mDt * rDY[20];
        rY[21] += mDt * rDY[21];
    }

template<>
void OdeSystemInformation<Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen>::Initialise(void)
{
    this->mSystemName = "priebe_beuckelmann_model_1998";
    this->mFreeVariableName = "environment__time";
    this->mFreeVariableUnits = "ms";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("mV");
    this->mInitialConditions.push_back(-90.7796417483135);

    // rY[1]:
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(0.0002);

    // rY[2]:
    this->mVariableNames.push_back("INa_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.000585525582501575);

    // rY[3]:
    this->mVariableNames.push_back("INa_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.995865529216237);

    // rY[4]:
    this->mVariableNames.push_back("INa_j_gate__j");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.997011204496203);

    // rY[5]:
    this->mVariableNames.push_back("ICa_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(2.50653215966786e-10);

    // rY[6]:
    this->mVariableNames.push_back("ICa_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.92130376850548);

    // rY[7]:
    this->mVariableNames.push_back("Ito_r_gate__r");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.75032478501027e-05);

    // rY[8]:
    this->mVariableNames.push_back("Ito_t_gate__t");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.999897251531651);

    // rY[9]:
    this->mVariableNames.push_back("IKs_Xs_gate__Xs");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.00885658064818147);

    // rY[10]:
    this->mVariableNames.push_back("IKr_Xr_gate__Xr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.000215523048438941);

    // rY[11]:
    this->mVariableNames.push_back("Irel__APtrack");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(-1.372158997089e-136);

    // rY[12]:
    this->mVariableNames.push_back("Irel__APtrack2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(-7.58517896402761e-136);

    // rY[13]:
    this->mVariableNames.push_back("Irel__APtrack3");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(4.82035353592764e-05);

    // rY[14]:
    this->mVariableNames.push_back("Irel__Cainfluxtrack");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(-7.71120176147331e-138);

    // rY[15]:
    this->mVariableNames.push_back("Irel__OVRLDtrack");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1e-06);

    // rY[16]:
    this->mVariableNames.push_back("Irel__OVRLDtrack2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1e-06);

    // rY[17]:
    this->mVariableNames.push_back("Irel__OVRLDtrack3");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1e-06);

    // rY[18]:
    this->mVariableNames.push_back("Ionic_concentrations__Nai");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(10.0);

    // rY[19]:
    this->mVariableNames.push_back("Ionic_concentrations__Ki");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(140.0);

    // rY[20]:
    this->mVariableNames.push_back("Ionic_concentrations__Ca_JSR");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(2.5);

    // rY[21]:
    this->mVariableNames.push_back("Ionic_concentrations__Ca_NSR");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(2.5);

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen)
