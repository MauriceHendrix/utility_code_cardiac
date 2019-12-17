//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: beeler_reuter_model_1977
//! 
//! Processed by weblab_cg: https://github.com/ModellingWebLab/weblab-cg
//!     (translator: weblab_cg, model type: normal, options: )
//! on 2019-12-17 10:22:20
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

    boost::shared_ptr<RegularStimulus> Cellbeeler_reuter_model_1977FromCellML::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__stimulus_protocol__IstimAmplitude = 100.0 * 0.5; // uA_per_cm2
        const double var_chaste_interface__stimulus_protocol__IstimPulseDuration = 1.0; // millisecond
        const double var_chaste_interface__stimulus_protocol__IstimPeriod = 1000.0; // millisecond
        const double var_chaste_interface__stimulus_protocol__IstimStart = 10.0; // millisecond
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__stimulus_protocol__IstimAmplitude),
                var_chaste_interface__stimulus_protocol__IstimPulseDuration,
                var_chaste_interface__stimulus_protocol__IstimPeriod,
                var_chaste_interface__stimulus_protocol__IstimStart
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }
    
    double Cellbeeler_reuter_model_1977FromCellML::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    
    Cellbeeler_reuter_model_1977FromCellML::Cellbeeler_reuter_model_1977FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                8,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Cellbeeler_reuter_model_1977FromCellML>::Instance();
        Init();
        
        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
    }
    
    Cellbeeler_reuter_model_1977FromCellML::~Cellbeeler_reuter_model_1977FromCellML()
    {
    }

    double Cellbeeler_reuter_model_1977FromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = rY[1];
        // Units: concentration_units; Initial value: 0.0001
        double var_chaste_interface__sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = rY[7];
        // Units: dimensionless; Initial value: 0.0001
        
        const double var_slow_inward_current__E_s = -82.3 - 13.0287 * log(0.001 * var_chaste_interface__slow_inward_current__Cai); // mV
        const double var_slow_inward_current__g_s = 0.0009; // mS_per_mm2
        const double var_slow_inward_current__i_s = (-var_slow_inward_current__E_s + var_chaste_interface__membrane__V) * var_slow_inward_current__g_s * var_chaste_interface__slow_inward_current_d_gate__d * var_chaste_interface__slow_inward_current_f_gate__f; // uA_per_mm2
        const double var_sodium_current__E_Na = 50.0; // mV
        const double var_sodium_current__g_Na = 0.04; // mS_per_mm2
        const double var_sodium_current__g_Nac = 3e-05; // mS_per_mm2
        const double var_sodium_current__i_Na = (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * (pow(var_chaste_interface__sodium_current_m_gate__m, 3.0) * var_sodium_current__g_Na * var_chaste_interface__sodium_current_h_gate__h * var_chaste_interface__sodium_current_j_gate__j + var_sodium_current__g_Nac); // uA_per_mm2
        const double var_time_dependent_outward_current__i_x1 = (-1.0 + exp((77.0 + var_chaste_interface__membrane__V) * 0.04)) * 0.008 * var_chaste_interface__time_dependent_outward_current_x1_gate__x1 * exp(-(35.0 + var_chaste_interface__membrane__V) * 0.04); // uA_per_mm2
        const double var_time_independent_outward_current__i_K1 = ((23.0 + var_chaste_interface__membrane__V) * 0.2 / (-exp(-(23.0 + var_chaste_interface__membrane__V) * 0.04) + 1.0) + (-1.0 + exp((85.0 + var_chaste_interface__membrane__V) * 0.04)) * 4.0 / (exp((53.0 + var_chaste_interface__membrane__V) * 0.08) + exp((53.0 + var_chaste_interface__membrane__V) * 0.04))) * 0.0035; // uA_per_mm2
        const double var_chaste_interface__i_ionic = 100.0 * var_slow_inward_current__i_s + 100.0 * var_sodium_current__i_Na + 100.0 * var_time_dependent_outward_current__i_x1 + 100.0 * var_time_independent_outward_current__i_K1; // uA_per_cm2
        
        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }
    
    void Cellbeeler_reuter_model_1977FromCellML::EvaluateYDerivatives(double var_chaste_interface__environment__time, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = rY[1];
        // Units: concentration_units; Initial value: 0.0001
        double var_chaste_interface__sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = rY[7];
        // Units: dimensionless; Initial value: 0.0001
        
        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_slow_inward_current__E_s = -82.3 - 13.0287 * log(0.001 * var_chaste_interface__slow_inward_current__Cai); // mV
        const double var_slow_inward_current__g_s = 0.0009; // mS_per_mm2
        const double var_slow_inward_current_d_gate__alpha_d = 0.095 * exp((-var_chaste_interface__membrane__V + 5.0) / 100.0) / (1.0 + exp((-var_chaste_interface__membrane__V + 5.0) / 13.89)); // per_ms
        const double var_slow_inward_current_d_gate__beta_d = 0.07 * exp((-44.0 - var_chaste_interface__membrane__V) / 59.0) / (1.0 + exp((44.0 + var_chaste_interface__membrane__V) / 20.0)); // per_ms
        const double d_dt_chaste_interface_var_slow_inward_current_d_gate__d = (-var_chaste_interface__slow_inward_current_d_gate__d + 1.0) * var_slow_inward_current_d_gate__alpha_d - var_slow_inward_current_d_gate__beta_d * var_chaste_interface__slow_inward_current_d_gate__d; // 1 / millisecond
        const double var_slow_inward_current_f_gate__alpha_f = 0.012 * exp((-28.0 - var_chaste_interface__membrane__V) / 125.0) / (1.0 + exp((28.0 + var_chaste_interface__membrane__V) / 6.67)); // per_ms
        const double var_slow_inward_current_f_gate__beta_f = 0.0065 * exp((-30.0 - var_chaste_interface__membrane__V) / 50.0) / (1.0 + exp((-30.0 - var_chaste_interface__membrane__V) / 5.0)); // per_ms
        const double d_dt_chaste_interface_var_slow_inward_current_f_gate__f = (-var_chaste_interface__slow_inward_current_f_gate__f + 1.0) * var_slow_inward_current_f_gate__alpha_f - var_slow_inward_current_f_gate__beta_f * var_chaste_interface__slow_inward_current_f_gate__f; // 1 / millisecond
        const double var_slow_inward_current__i_s = (-var_slow_inward_current__E_s + var_chaste_interface__membrane__V) * var_slow_inward_current__g_s * var_chaste_interface__slow_inward_current_d_gate__d * var_chaste_interface__slow_inward_current_f_gate__f; // uA_per_mm2
        const double d_dt_chaste_interface_var_slow_inward_current__Cai = (-var_chaste_interface__slow_inward_current__Cai + 0.0001) * 0.07 - 0.01 * var_slow_inward_current__i_s / 1.0; // millimolar / millisecond
        const double var_sodium_current_h_gate__alpha_h = 0.126 * exp(-(77.0 + var_chaste_interface__membrane__V) * 0.25); // per_ms
        const double var_sodium_current_h_gate__beta_h = 1.7 / (1.0 + exp(-(22.5 + var_chaste_interface__membrane__V) * 0.082)); // per_ms
        const double d_dt_chaste_interface_var_sodium_current_h_gate__h = (-var_chaste_interface__sodium_current_h_gate__h + 1.0) * var_sodium_current_h_gate__alpha_h - var_sodium_current_h_gate__beta_h * var_chaste_interface__sodium_current_h_gate__h; // 1 / millisecond
        const double var_sodium_current_j_gate__alpha_j = 0.055 * exp(-(78.0 + var_chaste_interface__membrane__V) * 0.25) / (1.0 + exp(-(78.0 + var_chaste_interface__membrane__V) * 0.2)); // per_ms
        const double var_sodium_current_j_gate__beta_j = 0.3 / (1.0 + exp(-(32.0 + var_chaste_interface__membrane__V) * 0.1)); // per_ms
        const double d_dt_chaste_interface_var_sodium_current_j_gate__j = (-var_chaste_interface__sodium_current_j_gate__j + 1.0) * var_sodium_current_j_gate__alpha_j - var_sodium_current_j_gate__beta_j * var_chaste_interface__sodium_current_j_gate__j; // 1 / millisecond
        const double var_sodium_current_m_gate__alpha_m = -(47.0 + var_chaste_interface__membrane__V) * 1.0 / (-1.0 + exp(-(47.0 + var_chaste_interface__membrane__V) * 0.1)); // per_ms
        const double var_sodium_current_m_gate__beta_m = 40.0 * exp(-(72.0 + var_chaste_interface__membrane__V) * 0.056); // per_ms
        const double d_dt_chaste_interface_var_sodium_current_m_gate__m = (-var_chaste_interface__sodium_current_m_gate__m + 1.0) * var_sodium_current_m_gate__alpha_m - var_sodium_current_m_gate__beta_m * var_chaste_interface__sodium_current_m_gate__m; // 1 / millisecond
        const double var_time_dependent_outward_current_x1_gate__alpha_x1 = 0.0005 * exp((50.0 + var_chaste_interface__membrane__V) / 12.1) / (1.0 + exp((50.0 + var_chaste_interface__membrane__V) / 17.5)); // per_ms
        const double var_time_dependent_outward_current_x1_gate__beta_x1 = 0.0013 * exp((-20.0 - var_chaste_interface__membrane__V) / 16.67) / (1.0 + exp((-20.0 - var_chaste_interface__membrane__V) / 25.0)); // per_ms
        const double d_dt_chaste_interface_var_time_dependent_outward_current_x1_gate__x1 = (-var_chaste_interface__time_dependent_outward_current_x1_gate__x1 + 1.0) * var_time_dependent_outward_current_x1_gate__alpha_x1 - var_time_dependent_outward_current_x1_gate__beta_x1 * var_chaste_interface__time_dependent_outward_current_x1_gate__x1; // 1 / millisecond
        
        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            const double var_membrane__C = 0.01; // uF_per_mm2
            const double var_sodium_current__E_Na = 50.0; // mV
            const double var_sodium_current__g_Na = 0.04; // mS_per_mm2
            const double var_sodium_current__g_Nac = 3e-05; // mS_per_mm2
            const double var_sodium_current__i_Na = (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * (pow(var_chaste_interface__sodium_current_m_gate__m, 3.0) * var_sodium_current__g_Na * var_chaste_interface__sodium_current_h_gate__h * var_chaste_interface__sodium_current_j_gate__j + var_sodium_current__g_Nac); // uA_per_mm2
            const double var_stimulus_protocol__Istim = -0.01 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_mm2
            const double var_time_dependent_outward_current__i_x1 = (-1.0 + exp((77.0 + var_chaste_interface__membrane__V) * 0.04)) * 0.008 * var_chaste_interface__time_dependent_outward_current_x1_gate__x1 * exp(-(35.0 + var_chaste_interface__membrane__V) * 0.04); // uA_per_mm2
            const double var_time_independent_outward_current__i_K1 = ((23.0 + var_chaste_interface__membrane__V) * 0.2 / (-exp(-(23.0 + var_chaste_interface__membrane__V) * 0.04) + 1.0) + (-1.0 + exp((85.0 + var_chaste_interface__membrane__V) * 0.04)) * 4.0 / (exp((53.0 + var_chaste_interface__membrane__V) * 0.08) + exp((53.0 + var_chaste_interface__membrane__V) * 0.04))) * 0.0035; // uA_per_mm2
            d_dt_chaste_interface_var_membrane__V = (-var_slow_inward_current__i_s - var_sodium_current__i_Na - var_time_dependent_outward_current__i_x1 - var_time_independent_outward_current__i_K1 + var_stimulus_protocol__Istim) / var_membrane__C; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rDY[1] = d_dt_chaste_interface_var_slow_inward_current__Cai;
        rDY[2] = d_dt_chaste_interface_var_sodium_current_m_gate__m;
        rDY[3] = d_dt_chaste_interface_var_sodium_current_h_gate__h;
        rDY[4] = d_dt_chaste_interface_var_sodium_current_j_gate__j;
        rDY[5] = d_dt_chaste_interface_var_slow_inward_current_d_gate__d;
        rDY[6] = d_dt_chaste_interface_var_slow_inward_current_f_gate__f;
        rDY[7] = d_dt_chaste_interface_var_time_dependent_outward_current_x1_gate__x1;
    }

template<>
void OdeSystemInformation<Cellbeeler_reuter_model_1977FromCellML>::Initialise(void)
{
    this->mSystemName = "beeler_reuter_model_1977";
    this->mFreeVariableName = "ar_environment__time";
    this->mFreeVariableUnits = "millisecond";
    
    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-84.624);
    
    // rY[1]:
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.0001);
    
    // rY[2]:
    this->mVariableNames.push_back("ar_sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.011);
    
    // rY[3]:
    this->mVariableNames.push_back("ar_sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.988);
    
    // rY[4]:
    this->mVariableNames.push_back("ar_sodium_current_j_gate__j");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.975);
    
    // rY[5]:
    this->mVariableNames.push_back("ar_slow_inward_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.003);
    
    // rY[6]:
    this->mVariableNames.push_back("ar_slow_inward_current_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.994);
    
    // rY[7]:
    this->mVariableNames.push_back("ar_time_dependent_outward_current_x1_gate__x1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0001);
    
    this->mInitialised = true;
}


// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellbeeler_reuter_model_1977FromCellML)
