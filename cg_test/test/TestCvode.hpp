#ifndef TESTCGCVODE_HPP_
#define TESTCGCVODE_HPP_

#include <iomanip>
#include <cmath>
#include <boost/foreach.hpp>
#include <vector>

#include "HeartConfig.hpp"
#include <cxxtest/TestSuite.h>

#include "AbstractCardiacCell.hpp"
#include "AbstractCardiacCellInterface.hpp"
#include "AbstractCvodeCell.hpp"
#include "AbstractGeneralizedRushLarsenCardiacCell.hpp"
#include "AbstractRushLarsenCardiacCell.hpp"
#include "Timer.hpp"

#include "SimpleStimulus.hpp"
#include "EulerIvpOdeSolver.hpp"

#include "CellMLToSharedLibraryConverter.hpp"
#include "DynamicCellModelLoader.hpp"
#include "DynamicModelLoaderRegistry.hpp"
#include "FileFinder.hpp"

#include "CellProperties.hpp"
#include "Exception.hpp"
#include "HeartConfig.hpp"
#include "RunAndCheckIonicModels.hpp"
#include "Warnings.hpp"
#include "MathsCustomFunctions.hpp"

#include "all_models.hpp"
/**
 * Test PyCml functionality by dynamically loading (and hence converting) a wide
 * range of cell models.
 *
 * May need a test-suite setup or similar to define model-specific parameters?
 * Should we pick up the list of models by reading the folder heart/test/data/cellml?
 */
class TestCgCvode : public CxxTest::TestSuite{
public:
    double tolerance = 1e-3;
    boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
    boost::shared_ptr<AbstractIvpOdeSolver> p_solver;

    void setUp() {
	std::setprecision(13);
        std::cout << "Setup...\n";
	p_stimulus = boost::shared_ptr<AbstractStimulusFunction>(new SimpleStimulus(0.0, 0.0, 0.0));
	p_solver = boost::shared_ptr<AbstractIvpOdeSolver>(new EulerIvpOdeSolver);
    }

    void TestAnalyticCvodeCells(){
       std::cout << "Testing cvode jacobians...\n";
	boost::shared_ptr<AbstractCvodeCell> p_cell;
	boost::shared_ptr<AbstractCvodeCell> p_cell_original;
	std::vector<std::string> state_vars;


	//bondarenko_model_2004_apex
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellbondarenko_model_2004_apexFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicbondarenko_model_2004_apexFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "calcium_concentration__Cai", "calcium_concentration__Cass", "calcium_concentration__CaJSR", "calcium_concentration__CaNSR", "calcium_fluxes__P_RyR", "calcium_buffering__LTRPN_Ca", "calcium_buffering__HTRPN_Ca", "ryanodine_receptors__P_O1", "ryanodine_receptors__P_O2","ryanodine_receptors__P_C2", "L_type_calcium_current__O", "L_type_calcium_current__C2", "L_type_calcium_current__C3", "L_type_calcium_current__C4", "L_type_calcium_current__I1", "L_type_calcium_current__I2", "L_type_calcium_current__I3", "sodium_concentration__Nai", "fast_sodium_current__O_Na", "fast_sodium_current__C_Na1", "fast_sodium_current__C_Na2", "fast_sodium_current__I1_Na", "fast_sodium_current__I2_Na", "fast_sodium_current__IF_Na", "fast_sodium_current__IC_Na2", "fast_sodium_current__IC_Na3", "potassium_concentration__Ki", "fast_transient_outward_potassium_current__ato_f", "fast_transient_outward_potassium_current__ito_f", "slow_transient_outward_potassium_current__ato_s", "slow_transient_outward_potassium_current__ito_s", "slow_delayed_rectifier_potassium_current__nKs", "ultra_rapidly_activating_delayed_rectifier_potassium_current__aur", "ultra_rapidly_activating_delayed_rectifier_potassium_current__iur", "non_inactivating_steady_state_potassium_current__aKss", "non_inactivating_steady_state_potassium_current__iKss", "rapid_delayed_rectifier_potassium_current__O_K", "rapid_delayed_rectifier_potassium_current__C_K1", "rapid_delayed_rectifier_potassium_current__C_K2", "rapid_delayed_rectifier_potassium_current__I_K"};	//runModel(p_cell, p_cell_original, "bondarenko_model_2004_apex", state_vars);
	runModel(p_cell, p_cell_original, "bondarenko_model_2004_apex", state_vars);


	//courtemanche_ramirez_nattel_model_1998
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellcourtemanche_ramirez_nattel_model_1998FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamiccourtemanche_ramirez_nattel_model_1998FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "fast_sodium_current_j_gate__j", "transient_outward_K_current_oa_gate__oa", "transient_outward_K_current_oi_gate__oi", "ultrarapid_delayed_rectifier_K_current_ua_gate__ua", "ultrarapid_delayed_rectifier_K_current_ui_gate__ui", "rapid_delayed_rectifier_K_current_xr_gate__xr", "slow_delayed_rectifier_K_current_xs_gate__xs", "L_type_Ca_channel_d_gate__d", "L_type_Ca_channel_f_gate__f", "L_type_Ca_channel_f_Ca_gate__f_Ca", "Ca_release_current_from_JSR_u_gate__u", "Ca_release_current_from_JSR_v_gate__v", "Ca_release_current_from_JSR_w_gate__w", "intracellular_ion_concentrations__Na_i", "intracellular_ion_concentrations__Ca_i","intracellular_ion_concentrations__K_i", "intracellular_ion_concentrations__Ca_rel", "intracellular_ion_concentrations__Ca_up"};
	runModel(p_cell, p_cell_original, "courtemanche_ramirez_nattel_model_1998", state_vars);


	//demir_model_1994
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Celldemir_model_1994FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicdemir_model_1994FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "sodium_current_m_gate__m", "sodium_current_h_gate__h1", "sodium_current_h_gate__h2", "L_type_Ca_channel_d_gate__d_L", "L_type_Ca_channel_f_gate__f_L", "T_type_Ca_channel_d_gate__d_T", "T_type_Ca_channel_f_gate__f_T", "delayed_rectifying_potassium_current_P_a_gate__P_a", "delayed_rectifying_potassium_current_P_i_gate__P_i", "hyperpolarisation_activated_current_y_gate__y", "intracellular_concentrations_and_buffer_equations__Na_i", "intracellular_concentrations_and_buffer_equations__Ca_i", "intracellular_concentrations_and_buffer_equations__K_i", "intracellular_concentrations_and_buffer_equations__Ca_Calmod", "intracellular_concentrations_and_buffer_equations__Ca_Trop", "intracellular_concentrations_and_buffer_equations__Ca_Mg_Trop", "intracellular_concentrations_and_buffer_equations__Mg_Mg_Trop", "cleft_space_equations__Na_c", "cleft_space_equations__Ca_c", "cleft_space_equations__K_c", "SR_Ca_uptake_and_release__Ca_up", "SR_Ca_uptake_and_release__Ca_rel", "SR_Ca_uptake_and_release__Ca_Calse", "SR_Ca_uptake_and_release__F1", "SR_Ca_uptake_and_release__F2", "SR_Ca_uptake_and_release__F3"};
	runModel(p_cell, p_cell_original, "demir_model_1994", state_vars);


	//dokos_model_1996
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Celldokos_model_1996FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicdokos_model_1996FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "L_type_calcium_current_d_gate__dL", "L_type_calcium_current_f_gate__fL", "L_type_calcium_current_f2_gate__fL2", "T_type_calcium_current_d_gate__dT", "T_type_calcium_current_f_gate__fT", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "delayed_rectifying_potassium_current_x_gate__x", "hyperpolarising_activated_current_y_gate__y", "ion_concentrations__Cai", "ion_concentrations__Cao", "ion_concentrations__Caup", "ion_concentrations__Carel", "ion_concentrations__Nai", "ion_concentrations__Nao", "ion_concentrations__Ki", "ion_concentrations__Ko"};
	runModel(p_cell, p_cell_original, "dokos_model_1996", state_vars);


	//espinosa_model_1998_normal
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellespinosa_model_1998_normalFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicespinosa_model_1998_normalFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "time_dependent_potassium_current_x_gate__x", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "L_type_Ca_channel_d_gate__d", "L_type_Ca_channel_f_gate__f", "L_type_Ca_channel_f2_gate__f2", "L_type_Ca_channel_f2ds_gate__f2ds", "transient_outward_current_s_gate__s", "transient_outward_current_r_gate__r", "calcium_release__ActFrac", "calcium_release__ProdFrac", "intracellular_sodium_concentration__Na_i", "extracellular_potassium_concentration__K_o", "intracellular_potassium_concentration__K_i", "intracellular_calcium_concentration__Ca_i", "intracellular_calcium_concentration__Ca_ds", "intracellular_calcium_concentration__Ca_up", "intracellular_calcium_concentration__Ca_rel", "intracellular_calcium_concentration__Ca_Calmod", "intracellular_calcium_concentration__Ca_Trop"};
	runModel(p_cell, p_cell_original, "espinosa_model_1998_normal", state_vars);


	//hodgkin_huxley_squid_axon_model_1952_modified
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamichodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "sodium_channel_m_gate__m", "sodium_channel_h_gate__h", "potassium_channel_n_gate__n"};
	runModel(p_cell, p_cell_original, "hodgkin_huxley_squid_axon_model_1952_modified", state_vars);


	//iribe_model_2006_without_otherwise_section
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Celliribe_model_2006_without_otherwise_sectionFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamiciribe_model_2006_without_otherwise_sectionFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "membrane_fast_sodium_current_m_gate", "membrane_fast_sodium_current_h_gate", "time_dependent_rectifier_potassium_current_x_gate__x", "transient_outward_current_s_gate__s", "transient_outward_current_r_gate__r", "membrane_L_type_calcium_current_d_gate", "membrane_L_type_calcium_current_f_gate", "CaMKII_factor__F_CaMK", "RyR__F_SRCa_RyR", "RyR__F_1", "RyR__F_2", "calmodulin__Cmdn_Ca", "troponin__Trpn_Ca", "cytosolic_calcium_concentration", "SR_calcium_concentration__Ca_SR", "cytosolic_sodium_concentration", "cytosolic_potassium_concentration", "Force__N_0", "Force__P_0", "Force__P_1", "Force__P_2", "Force__P_3"};
	runModel(p_cell, p_cell_original, "iribe_model_2006_without_otherwise_section", state_vars);

	//iyer_model_2004
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Celliyer_model_2004FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamiciyer_model_2004FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai", "COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki", "COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cai", "COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__CaSS", "COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__CaJSR", "COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__CaNSR", "membrane_voltage", "COMPUTE_Jtrpn_and_BUFFER_SCALE_FACTORS__LTRPNCa", "COMPUTE_Jtrpn_and_BUFFER_SCALE_FACTORS__HTRPNCa", "COMPUTE_DERIVATIVES_OF_RyR_RECEPTOR_STATES__C1_RyR", "COMPUTE_DERIVATIVES_OF_RyR_RECEPTOR_STATES__O2_RyR", "COMPUTE_DERIVATIVES_OF_RyR_RECEPTOR_STATES__C2_RyR", "COMPUTE_DERIVATIVES_OF_RyR_RECEPTOR_STATES__O1_RyR", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__C0", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__C1", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__C2", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__C3", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__C4", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__CCa0", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__CCa1", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__CCa2", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__CCa3", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__CCa4", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__C0Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__C1Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__C2Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__C3Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__OKv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__CI0Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__CI1Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__CI2Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__CI3Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__OIKv43", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__C0Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__C1Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__C2Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__C3Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__CI0Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__CI1Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__CI2Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__CI3Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OIKv14", "INa__na1", "INa__na2", "INa__na3", "INa__na4", "INa__na5", "INa__na6", "INa__na7", "INa__na8", "INa__na9", "INa__na10", "INa__na11", "INa__na12", "INa__na13", "IKr__C1Herg", "IKr__C2Herg", "IKr__C3Herg", "IKr__OHerg", "IKr__IHerg", "IKs__C0ks", "IKs__C1ks", "IKs__O1ks", "IKs__O2ks"};
	runModel(p_cell, p_cell_original, "iyer_model_2004", state_vars);


	//mahajan_2008
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellmahajan_2008FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicmahajan_2008FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "INa__xm", "INa__xh", "INa__xj", "ICaL__c1", "ICaL__c2", "ICaL__xi1ca", "ICaL__xi1ba", "ICaL__xi2ca", "ICaL__xi2ba", "IKr__xr", "IKs__xs1", "IKs__xs2", "Ito__xtos", "Ito__ytos", "Ito__xtof", "Ito__ytof", "Irel__Ca_JSR", "Irel__xir", "Na__Na_i", "Ca__Ca_dyad", "Ca__Ca_submem", "cytosolic_calcium_concentration", "Ca__Ca_NSR", "Ca__tropi", "Ca__trops"};
	runModel(p_cell, p_cell_original, "mahajan_2008", state_vars);

	//noble_model_1998
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellnoble_model_1998FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicnoble_model_1998FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "rapid_delayed_rectifier_potassium_current_xr1_gate__xr1", "rapid_delayed_rectifier_potassium_current_xr2_gate__xr2", "slow_delayed_rectifier_potassium_current_xs_gate__xs", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "L_type_Ca_channel_d_gate__d", "L_type_Ca_channel_f_gate__f", "L_type_Ca_channel_f2_gate__f2", "L_type_Ca_channel_f2ds_gate__f2ds", "transient_outward_current_s_gate__s", "transient_outward_current_r_gate__r", "calcium_release__ActFrac", "calcium_release__ProdFrac", "intracellular_sodium_concentration__Na_i", "intracellular_potassium_concentration__K_i", "intracellular_calcium_concentration__Ca_i", "intracellular_calcium_concentration__Ca_ds", "intracellular_calcium_concentration__Ca_up", "intracellular_calcium_concentration__Ca_rel", "intracellular_calcium_concentration__Ca_Calmod", "intracellular_calcium_concentration__Ca_Trop"};
	runModel(p_cell, p_cell_original, "noble_model_1998", state_vars);


	//noble_noble_SAN_model_1984
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellnoble_noble_SAN_model_1984FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicnoble_noble_SAN_model_1984FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "hyperpolarising_activated_current_y_gate__y", "time_dependent_potassium_current_x_gate__x", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "second_inward_current_d_gate__d", "second_inward_current_f_gate__f", "second_inward_current_f2_gate__f2", "intracellular_sodium_concentration__Nai", "intracellular_calcium_concentration__Cai", "intracellular_calcium_concentration__Ca_up", "intracellular_calcium_concentration__Ca_rel", "intracellular_calcium_concentration__p", "extracellular_potassium_concentration__Kc", "intracellular_potassium_concentration__Ki"};
	runModel(p_cell, p_cell_original, "noble_noble_SAN_model_1984", state_vars);


	//noble_SAN_model_1989
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellnoble_SAN_model_1989FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicnoble_SAN_model_1989FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "hyperpolarising_activated_current_y_gate__y", "time_dependent_potassium_current_x_gate__x", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "second_inward_current_d_gate__d", "second_inward_current_f_gate__f", "second_inward_current_f2_gate__f2", "intracellular_sodium_concentration__Nai", "intracellular_calcium_concentration__Cai", "intracellular_calcium_concentration__Ca_up", "intracellular_calcium_concentration__Ca_rel", "intracellular_calcium_concentration__p", "intracellular_potassium_concentration__Ki"};
	runModel(p_cell, p_cell_original, "noble_SAN_model_1989", state_vars);


	//nygren_atrial_model_1998
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellnygren_atrial_model_1998FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicnygren_atrial_model_1998FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "sodium_current_m_gate__m", "sodium_current_h1_gate__h1", "sodium_current_h2_gate__h2", "L_type_Ca_channel_d_L_gate__d_L", "L_type_Ca_channel_f_L1_gate__f_L_1", "L_type_Ca_channel_f_L2_gate__f_L_2", "Ca_independent_transient_outward_K_current_r_gate__r", "Ca_independent_transient_outward_K_current_s_gate__s", "sustained_outward_K_current_r_sus_gate__r_sus", "sustained_outward_K_current_s_sus_gate__s_sus", "delayed_rectifier_K_currents_n_gate__n", "delayed_rectifier_K_currents_pa_gate__p_a", "intracellular_ion_concentrations__Na_i", "intracellular_ion_concentrations__Ca_i", "intracellular_ion_concentrations__K_i", "intracellular_ion_concentrations__Ca_d", "intracellular_Ca_buffering__O_C", "intracellular_Ca_buffering__O_TC", "intracellular_Ca_buffering__O_TMgC", "intracellular_Ca_buffering__O_TMgMg", "cleft_space_ion_concentrations__Na_c", "cleft_space_ion_concentrations__Ca_c", "cleft_space_ion_concentrations__K_c", "Ca_handling_by_the_SR__Ca_rel", "Ca_handling_by_the_SR__Ca_up", "Ca_handling_by_the_SR__O_Calse", "Ca_handling_by_the_SR__F1", "Ca_handling_by_the_SR__F2"};
	runModel(p_cell, p_cell_original, "nygren_atrial_model_1998", state_vars);


	//pandit_model_2001_epi
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellpandit_model_2001_epiFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicpandit_model_2001_epiFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "sodium_current_m_gate__m", "sodium_current_h_gate__h", "sodium_current_j_gate__j", "L_type_Ca_channel_d_gate__d", "L_type_Ca_channel_f_11_gate__f_11", "L_type_Ca_channel_f_12_gate__f_12", "L_type_Ca_channel_Ca_inact_gate__Ca_inact", "Ca_independent_transient_outward_K_current_r_gate__r", "Ca_independent_transient_outward_K_current_s_gate__s", "Ca_independent_transient_outward_K_current_s_slow_gate__s_slow", "steady_state_outward_K_current_r_ss_gate__r_ss", "steady_state_outward_K_current_s_ss_gate__s_ss", "hyperpolarisation_activated_current_y_gate__y", "SR_Ca_release_channel__P_O1", "SR_Ca_release_channel__P_O2", "SR_Ca_release_channel__P_C1", "SR_Ca_release_channel__P_C2", "intracellular_and_SR_Ca_fluxes__HTRPNCa", "intracellular_and_SR_Ca_fluxes__LTRPNCa", "intracellular_ion_concentrations__Na_i", "intracellular_ion_concentrations__Ca_i", "intracellular_ion_concentrations__K_i", "intracellular_ion_concentrations__Ca_ss", "intracellular_ion_concentrations__Ca_JSR", "intracellular_ion_concentrations__Ca_NSR"};
	runModel(p_cell, p_cell_original, "pandit_model_2001_epi", state_vars);


	//priebe_beuckelmann_model_1998
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellpriebe_beuckelmann_model_1998FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicpriebe_beuckelmann_model_1998FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "INa_m_gate__m", "INa_h_gate__h", "INa_j_gate__j", "ICa_d_gate__d", "ICa_f_gate__f", "Ito_r_gate__r", "Ito_t_gate__t", "IKs_Xs_gate__Xs", "IKr_Xr_gate__Xr", "Irel__APtrack", "Irel__APtrack2", "Irel__APtrack3", "Irel__Cainfluxtrack", "Irel__OVRLDtrack", "Irel__OVRLDtrack2", "Irel__OVRLDtrack3", "Ionic_concentrations__Nai", "cytosolic_calcium_concentration", "Ionic_concentrations__Ki", "Ionic_concentrations__Ca_JSR", "Ionic_concentrations__Ca_NSR"};
	runModel(p_cell, p_cell_original, "priebe_beuckelmann_model_1998", state_vars);

	//viswanathan_model_1999_epi
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellviswanathan_model_1999_epiFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicviswanathan_model_1999_epiFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "fast_sodium_current_j_gate__j", "L_type_Ca_channel_d_gate__d", "L_type_Ca_channel_f_gate__f", "T_type_Ca_channel_b_gate__b", "T_type_Ca_channel_g_gate__g", "rapid_delayed_rectifier_potassium_current_xr_gate__xr", "slow_delayed_rectifier_potassium_current_xs1_gate__xs1", "slow_delayed_rectifier_potassium_current_xs2_gate__xs2", "transient_outward_current_zdv_gate__zdv", "transient_outward_current_ydv_gate__ydv", "calcium_dynamics__Cai", "calcium_dynamics__Ca_JSR", "calcium_dynamics__Ca_NSR", "calcium_dynamics__APtrack", "calcium_dynamics__APtrack2", "calcium_dynamics__APtrack3", "calcium_dynamics__Cainfluxtrack", "calcium_dynamics__OVRLDtrack", "calcium_dynamics__OVRLDtrack2", "calcium_dynamics__OVRLDtrack3", "ionic_concentrations__Nai", "ionic_concentrations__Ki"};
	runModel(p_cell, p_cell_original, "viswanathan_model_1999_epi", state_vars);


	//zhang_SAN_model_2000_0D_capable
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellzhang_SAN_model_2000_0D_capableFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamiczhang_SAN_model_2000_0D_capableFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "sodium_current_m_gate__m", "sodium_current_h_gate__h1", "sodium_current_h_gate__h2", "L_type_Ca_channel_d_gate__d_L", "L_type_Ca_channel_f_gate__f_L", "T_type_Ca_channel_d_gate__d_T", "T_type_Ca_channel_f_gate__f_T", "four_AP_sensitive_currents_q_gate__q", "four_AP_sensitive_currents_r_gate__r", "rapid_delayed_rectifying_potassium_current_P_af_gate__P_af", "rapid_delayed_rectifying_potassium_current_P_as_gate__P_as", "rapid_delayed_rectifying_potassium_current_P_i_gate__P_i", "slow_delayed_rectifying_potassium_current_xs_gate__xs", "hyperpolarisation_activated_current_y_gate__y"};
	runModel(p_cell, p_cell_original, "zhang_SAN_model_2000_0D_capable", state_vars);


	//zhang_SAN_model_2000_all
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellzhang_SAN_model_2000_allFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamiczhang_SAN_model_2000_allFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "sodium_current_m_gate__m", "sodium_current_h_gate__h1", "sodium_current_h_gate__h2", "L_type_Ca_channel_d_gate__d_L", "L_type_Ca_channel_f_gate__f_L", "T_type_Ca_channel_d_gate__d_T", "T_type_Ca_channel_f_gate__f_T", "four_AP_sensitive_currents_q_gate__q", "four_AP_sensitive_currents_r_gate__r", "rapid_delayed_rectifying_potassium_current_P_af_gate__P_af", "rapid_delayed_rectifying_potassium_current_P_as_gate__P_as", "rapid_delayed_rectifying_potassium_current_P_i_gate__P_i", "slow_delayed_rectifying_potassium_current_xs_gate__xs", "hyperpolarisation_activated_current_y_gate__y"};
	runModel(p_cell, p_cell_original, "zhang_SAN_model_2000_all", state_vars);


	//beeler_reuter_model_1977
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellbeeler_reuter_model_1977FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicbeeler_reuter_model_1977FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "sodium_current_m_gate__m", "sodium_current_h_gate__h", "sodium_current_j_gate__j", "cytosolic_calcium_concentration", "slow_inward_current_d_gate__d", "slow_inward_current_f_gate__f", "time_dependent_outward_current_x1_gate__x1"};
	runModel(p_cell, p_cell_original, "beeler_reuter_model_1977", state_vars);
    
	//jafri_rice_winslow_model_1998
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Celljafri_rice_winslow_model_1998FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicjafri_rice_winslow_model_1998FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "fast_sodium_current_j_gate__j", "L_type_Ca_channel__O", "L_type_Ca_channel__O_Ca", "L_type_Ca_channel__C0", "L_type_Ca_channel__C1", "L_type_Ca_channel__C2", "L_type_Ca_channel__C3", "L_type_Ca_channel__C4", "L_type_Ca_channel__C_Ca0", "L_type_Ca_channel__C_Ca1", "L_type_Ca_channel__C_Ca2", "L_type_Ca_channel__C_Ca3", "L_type_Ca_channel__C_Ca4", "L_type_Ca_channel_y_gate__y", "time_dependent_potassium_current_X_gate__X", "calcium_subsystem__Cai", "calcium_subsystem__Ca_SS", "calcium_subsystem__P_O1", "calcium_subsystem__P_O2", "calcium_subsystem__P_C1", "calcium_subsystem__P_C2", "calcium_subsystem__Ca_JSR", "calcium_subsystem__Ca_NSR", "calcium_subsystem__HTRPNCa", "calcium_subsystem__LTRPNCa", "ionic_concentrations__Nai", "ionic_concentrations__Ki", "ionic_concentrations__Ko"};
	runModel(p_cell, p_cell_original, "jafri_rice_winslow_model_1998", state_vars);


	//iyer_model_2007
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Celliyer_model_2007FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamiciyer_model_2007FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Nai", "COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Ki", "COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__Cai", "COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__CaSS", "COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__CaJSR", "COMPUTE_CONCENTRATION_AND_VOLTAGE_DERIVATIVES__CaNSR", "membrane_voltage", "COMPUTE_Jtrpn_and_BUFFER_SCALE_FACTORS__LTRPNCa", "COMPUTE_Jtrpn_and_BUFFER_SCALE_FACTORS__HTRPNCa", "COMPUTE_DERIVATIVES_OF_RyR_RECEPTOR_STATES__C1_RyR", "COMPUTE_DERIVATIVES_OF_RyR_RECEPTOR_STATES__O2_RyR", "COMPUTE_DERIVATIVES_OF_RyR_RECEPTOR_STATES__C2_RyR", "COMPUTE_DERIVATIVES_OF_RyR_RECEPTOR_STATES__O1_RyR", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__C0", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__C1", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__C2", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__C3", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__C4", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__CCa0", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__CCa1", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__CCa2", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__CCa3", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__CCa4", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__Open", "COMPUTE_DERIVATIVES_OF_LTYPE_CHANNEL_STATES__yCa", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__C0Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__C1Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__C2Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__C3Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__OKv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__CI0Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__CI1Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__CI2Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__CI3Kv43", "COMPUTE_DERIVATIVES_OF_Kv4_3_CHANNEL_STATES__OIKv43", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__C0Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__C1Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__C2Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__C3Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OKv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__CI0Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__CI1Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__CI2Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__CI3Kv14", "COMPUTE_DERIVATIVES_OF_Kv1_4_CHANNEL_STATES__OIKv14", "INa__na1", "INa__na2", "INa__na3", "INa__na4", "INa__na5", "INa__na6", "INa__na7", "INa__na8", "INa__na9", "INa__na10", "INa__na11", "INa__na12", "INa__na13", "IKr__C1Herg", "IKr__C2Herg", "IKr__C3Herg", "IKr__OHerg", "IKr__IHerg", "IKs__C0ks", "IKs__C1ks", "IKs__O1ks", "IKs__O2ks"};
	runModel(p_cell, p_cell_original, "iyer_model_2007", state_vars);


	//matsuoka_model_2003
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellmatsuoka_model_2003FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicmatsuoka_model_2003FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "internal_ion_concentrations__Nai", "internal_ion_concentrations__Ki", "internal_ion_concentrations__Ca_Total", "ATP_production__ATPi", "sodium_current_voltage_dependent_gate__p_AP_Na", "sodium_current_voltage_dependent_gate__p_RP_Na", "sodium_current_voltage_dependent_gate__p_AI_Na", "sodium_current_ultra_slow_gate__y", "L_type_Ca_channel_voltage_dependent_gate__p_AP_CaL", "L_type_Ca_channel_voltage_dependent_gate__p_RP_CaL", "L_type_Ca_channel_voltage_dependent_gate__p_AI_CaL", "L_type_Ca_channel_Ca_dependent_gate__p_U", "L_type_Ca_channel_Ca_dependent_gate__p_UCa", "L_type_Ca_channel_Ca_dependent_gate__p_C", "L_type_Ca_channel_ultra_slow_gate__y", "T_type_Ca_channel_y1_gate__y1", "T_type_Ca_channel_y2_gate__y2", "time_independent_potassium_current_y_gate__y", "rapid_time_dependent_potassium_current_y1_gate__y1", "rapid_time_dependent_potassium_current_y2_gate__y2", "rapid_time_dependent_potassium_current_y3_gate__y3", "slow_time_dependent_potassium_current_y1_gate__y1", "slow_time_dependent_potassium_current_y2_gate__y2", "transient_outward_current_y1_gate__y1", "transient_outward_current_y2_gate__y2", "sodium_calcium_exchanger_y_gate__y", "sodium_potassium_pump_y_gate__y", "SR_calcium_pump_y_gate__y", "RyR_channel__p_open_RyR", "RyR_channel__p_close_RyR", "Ca_concentrations_in_SR__Ca_Total", "Ca_concentrations_in_SR__Caup", "NL_model__pCa", "NL_model__pCaCB", "NL_model__pCB", "NL_model__X"};
	runModel(p_cell, p_cell_original, "matsuoka_model_2003", state_vars);


	//winslow_model_1999
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellwinslow_model_1999FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicwinslow_model_1999FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "fast_sodium_current_j_gate__j", "rapid_activating_delayed_rectifiyer_K_current_X_kr_gate__X_kr", "slow_activating_delayed_rectifiyer_K_current_X_ks_gate__X_ks", "transient_outward_potassium_current_X_to1_gate__X_to1", "transient_outward_potassium_current_Y_to1_gate__Y_to1", "L_type_Ca_current__O", "L_type_Ca_current__O_Ca", "L_type_Ca_current__C0", "L_type_Ca_current__C1", "L_type_Ca_current__C2", "L_type_Ca_current__C3", "L_type_Ca_current__C4", "L_type_Ca_current__C_Ca0", "L_type_Ca_current__C_Ca1", "L_type_Ca_current__C_Ca2", "L_type_Ca_current__C_Ca3", "L_type_Ca_current__C_Ca4", "L_type_Ca_current_y_gate__y", "RyR_channel__P_O1", "RyR_channel__P_O2", "RyR_channel__P_C1", "RyR_channel__P_C2", "intracellular_Ca_fluxes__HTRPNCa", "intracellular_Ca_fluxes__LTRPNCa", "intracellular_ion_concentrations__Nai", "intracellular_ion_concentrations__Cai", "intracellular_ion_concentrations__Ki", "intracellular_ion_concentrations__Ca_ss", "intracellular_ion_concentrations__Ca_JSR", "intracellular_ion_concentrations__Ca_NSR"};
	runModel(p_cell, p_cell_original, "winslow_model_1999", state_vars);

  
    //Models with issues

//fail
	//kurata_model_2002
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellkurata_model_2002FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamickurata_model_2002FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "L_type_calcium_channel_current_d_gate__d", "L_type_calcium_channel_current_f_gate__f", "L_type_calcium_channel_current_fCa_gate__fCa", "T_type_calcium_channel_current_d_gate__d", "T_type_calcium_channel_current_f_gate__f", "rapidly_activating_delayed_rectifier_potassium_current_pa_gate__paS", "rapidly_activating_delayed_rectifier_potassium_current_pa_gate__paF", "rapidly_activating_delayed_rectifier_potassium_current_pi_gate__piy", "slowly_activating_delayed_rectifier_potassium_current_n_gate__n", "AP_sensitive_currents_q_gate__q", "AP_sensitive_currents_r_gate__r", "hyperpolarisation_activated_current_y_gate__y", "sustained_inward_current_qa_gate__qa", "sustained_inward_current_qi_gate__qi", "intracellular_ion_concentrations__Cai", "intracellular_ion_concentrations__Ca_up", "intracellular_ion_concentrations__Ca_rel", "intracellular_ion_concentrations__Ca_sub", "intracellular_ion_concentrations__Nai", "intracellular_ion_concentrations__Ki", "calcium_buffering__fTMM", "calcium_buffering__fCMi", "calcium_buffering__fCMs", "calcium_buffering__fTC", "calcium_buffering__fTMC", "calcium_buffering__fCQ"};
	runModel(p_cell, p_cell_original, "kurata_model_2002", state_vars);

//fail
	//fink_noble_giles_model_2008
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellfink_noble_giles_model_2008FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicfink_noble_giles_model_2008FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "iKr_Markov__Cr1", "iKr_Markov__Cr2", "iKr_Markov__Cr3", "iKr_Markov__Or4", "iKr_Markov__Ir5", "iKr_Markov_Sotalol_block__BCr1", "iKr_Markov_Sotalol_block__BCr2", "iKr_Markov_Sotalol_block__BCr3", "iKr_Markov_Sotalol_block__BOr4", "iKr_Markov_Sotalol_block__BIr5", "iKs_Xs_gate__Xs", "ito_s_gate__s", "ito_r_gate__r", "iNa_m_gate__m", "iNa_h_gate__h", "iNa_j_gate__j", "iCaL_d_gate__d", "iCaL_f_gate__f", "iCaL_f2_gate__f2", "iCaL_fCass_gate__fCass", "Ca__Ca_i", "Ca__Ca_SR", "Ca__Ca_ss", "Irel__R_prime", "Na__Na_i", "K__K_i"};
	runModel(p_cell, p_cell_original, "fink_noble_giles_model_2008", state_vars);


//fail
    //aslanidi_model_2009
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellaslanidi_model_2009FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicaslanidi_model_2009FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "sodium_current_m_gate__m", "sodium_current_h1_gate__h1", "sodium_current_h2_gate__h2", "L_type_Ca_channel_d_L_gate__d_L", "L_type_Ca_channel_f_L_gate__f_L", "T_type_Ca_channel_d_T_gate__d_T", "T_type_Ca_channel_f_T_gate__f_T", "Ca_independent_transient_outward_K_current_r_gate__r", "Ca_independent_transient_outward_K_current_s1_gate__s1", "Ca_independent_transient_outward_K_current_s2_gate__s2", "Ca_independent_transient_outward_K_current_s3_gate__s3", "delayed_rectifier_K_current_z_gate__z", "delayed_rectifier_K_current_pa_gate__p_a", "delayed_rectifier_K_current_pi_gate__p_i", "intracellular_ion_concentrations__Na_i", "intracellular_ion_concentrations__Ca_i", "intracellular_ion_concentrations__K_i", "intracellular_Ca_buffering__O_C", "intracellular_Ca_buffering__O_TC", "intracellular_Ca_buffering__O_TMgC", "intracellular_Ca_buffering__O_TMgMg", "cleft_space_ion_concentrations__K_c", "Ca_handling_by_the_SR__Ca_rel", "Ca_handling_by_the_SR__Ca_up", "Ca_handling_by_the_SR__O_Calse", "Ca_handling_by_the_SR__F1", "Ca_handling_by_the_SR__F2", "Ca_handling_by_the_SR__F3"};
	runModel(p_cell, p_cell_original, "aslanidi_model_2009", state_vars);

//fail
	//sakmann_model_2000_epi
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellsakmann_model_2000_epiFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicsakmann_model_2000_epiFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "rapid_delayed_rectifier_potassium_current_xr_gate__xr", "slow_delayed_rectifier_potassium_current_xs_gate__xs", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "L_type_Ca_channel_d_gate__d", "L_type_Ca_channel_f_gate__f", "L_type_Ca_channel_f2_gate__f2", "L_type_Ca_channel_f2ds_gate__f2ds", "transient_outward_current_s_gate__s", "transient_outward_current_r_gate__r", "calcium_release__ActFrac", "calcium_release__ProdFrac", "intracellular_sodium_concentration__Na_i", "intracellular_potassium_concentration__K_i", "intracellular_calcium_concentration__Ca_i", "intracellular_calcium_concentration__Ca_ds", "intracellular_calcium_concentration__Ca_up", "intracellular_calcium_concentration__Ca_rel", "intracellular_calcium_concentration__Ca_Calmod", "intracellular_calcium_concentration__Ca_Trop"};
	runModel(p_cell, p_cell_original, "sakmann_model_2000_epi", state_vars);


//fail
//stewart_zhang_model_2008_ss
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellstewart_zhang_model_2008_ssFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicstewart_zhang_model_2008_ssFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "hyperpolarization_activated_current_y_gate__y", "rapid_time_dependent_potassium_current_Xr1_gate__Xr1", "rapid_time_dependent_potassium_current_Xr2_gate__Xr2", "slow_time_dependent_potassium_current_Xs_gate__Xs", "membrane_fast_sodium_current_m_gate", "membrane_fast_sodium_current_h_gate", "membrane_fast_sodium_current_j_gate", "membrane_L_type_calcium_current_d_gate", "membrane_L_type_calcium_current_f_gate", "membrane_L_type_calcium_current_f2_gate", "membrane_L_type_calcium_current_fCa2_gate", "transient_outward_current_s_gate__s", "transient_outward_current_r_gate__r", "cytosolic_calcium_concentration", "calcium_dynamics__Ca_SR", "diadicspace_calcium_concentration", "calcium_dynamics__R_prime", "cytosolic_sodium_concentration", "cytosolic_potassium_concentration"};
	runModel(p_cell, p_cell_original, "stewart_zhang_model_2008_ss", state_vars);


//fail
	//ten_tusscher_model_2006_epi
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellten_tusscher_model_2006_epiFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicten_tusscher_model_2006_epiFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "rapid_time_dependent_potassium_current_Xr1_gate__Xr1", "rapid_time_dependent_potassium_current_Xr2_gate__Xr2", "slow_time_dependent_potassium_current_Xs_gate__Xs", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "fast_sodium_current_j_gate__j", "L_type_Ca_current_d_gate__d", "L_type_Ca_current_f_gate__f", "L_type_Ca_current_f2_gate__f2", "L_type_Ca_current_fCass_gate__fCass", "transient_outward_current_s_gate__s", "transient_outward_current_r_gate__r", "cytosolic_calcium_concentration", "calcium_dynamics__Ca_SR", "calcium_dynamics__Ca_ss", "calcium_dynamics__R_prime", "sodium_dynamics__Na_i", "potassium_dynamics__K_i"};
	runModel(p_cell, p_cell_original, "ten_tusscher_model_2006_epi", state_vars);


// number != nan
	//Shannon2004
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new CellShannon2004FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new DynamicShannon2004FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "membrane_fast_sodium_current_h_gate", "membrane_fast_sodium_current_j_gate", "membrane_fast_sodium_current_m_gate", "IKr_Xr_gate__Xr", "IKs_Xs_gate__Xs", "Itos_X_gate__X_tos", "Itos_Y_gate__Y_tos", "Itos_R_gate__R_tos", "Itof_X_gate__X_tof", "Itof_Y_gate__Y_tof", "membrane_L_type_calcium_current_d_gate", "membrane_L_type_calcium_current_f_gate", "ICaL_fCa_gate__fCaB_SL", "ICaL_fCa_gate__fCaB_jct", "Jrel_SR__R", "Jrel_SR__I", "Jrel_SR__O", "Na_buffer__Na_SL", "Na_buffer__Na_jct", "Na_buffer__Na_SL_buf", "Na_buffer__Na_jct_buf", "Na_buffer__Nai", "JSR_calcium_concentration", "Ca_buffer__Ca_SL", "Ca_buffer__Ca_jct", "cytosolic_calcium_concentration", "Ca_buffer__Ca_SLB_SL", "Ca_buffer__Ca_SLB_jct", "Ca_buffer__Ca_SLHigh_SL", "Ca_buffer__Ca_SLHigh_jct", "Ca_buffer__Ca_Calsequestrin", "cytosolic_Ca_buffer__Ca_TroponinC", "cytosolic_Ca_buffer__Ca_TroponinC_Ca_Mg", "cytosolic_Ca_buffer__Mg_TroponinC_Ca_Mg", "cytosolic_Ca_buffer__Ca_Calmodulin", "cytosolic_Ca_buffer__Ca_Myosin", "cytosolic_Ca_buffer__Mg_Myosin", "cytosolic_Ca_buffer__Ca_SRB"};
	runModel(p_cell, p_cell_original, "Shannon2004", state_vars);


//nan != 0.0000
	//earm_noble_model_1990
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellearm_noble_model_1990FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicearm_noble_model_1990FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "transient_outward_current_r_gate__r", "transient_outward_current_s_gate__s", "L_type_calcium_current_d_gate__d", "L_type_calcium_current_f_Ca_gate__f_Ca", "calcium_release__ActFrac", "calcium_release__ProdFrac", "intracellular_sodium_concentration__Na_i", "intracellular_potassium_concentration__K_i", "intracellular_calcium_concentration__Ca_i", "intracellular_calcium_concentration__Ca_up", "intracellular_calcium_concentration__Ca_rel", "intracellular_calcium_concentration__Ca_Calmod", "intracellular_calcium_concentration__Ca_Trop"};
	runModel(p_cell, p_cell_original, "earm_noble_model_1990", state_vars);


//nan != 0.0000
	//hilgemann_noble_model_1987
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellhilgemann_noble_model_1987FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamichilgemann_noble_model_1987FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "second_inward_calcium_current_d_gate__d", "second_inward_calcium_current_f_Ca_gate__f_Ca", "calcium_release__ActFrac", "calcium_release__ProdFrac", "intracellular_sodium_concentration__Na_i", "extracellular_calcium_concentration__Ca_o", "intracellular_potassium_concentration__K_i", "intracellular_calcium_concentration__Ca_i", "intracellular_calcium_concentration__Ca_up", "intracellular_calcium_concentration__Ca_rel", "intracellular_calcium_concentration__Ca_Calmod", "intracellular_calcium_concentration__Ca_Trop"};
	runModel(p_cell, p_cell_original, "hilgemann_noble_model_1987", state_vars);

//nan != 0.0000
	//noble_model_1991
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellnoble_model_1991FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicnoble_model_1991FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "time_dependent_potassium_current_x_gate__x", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "L_type_Ca_channel_d_gate__d", "L_type_Ca_channel_f_gate__f", "transient_outward_current_s_gate__s", "transient_outward_current_r_gate__r", "calcium_release__ActFrac", "calcium_release__ProdFrac", "intracellular_sodium_concentration__Na_i", "intracellular_potassium_concentration__K_i", "intracellular_calcium_concentration__Ca_i", "intracellular_calcium_concentration__Ca_up", "intracellular_calcium_concentration__Ca_rel", "intracellular_calcium_concentration__Ca_Calmod", "intracellular_calcium_concentration__Ca_Trop"};
	runModel(p_cell, p_cell_original, "noble_model_1991", state_vars);


//nan != nan
	//ten_tusscher_model_2004_endo
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellten_tusscher_model_2004_endoFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicten_tusscher_model_2004_endoFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "rapid_time_dependent_potassium_current_Xr1_gate__Xr1", "rapid_time_dependent_potassium_current_Xr2_gate__Xr2", "slow_time_dependent_potassium_current_Xs_gate__Xs", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "fast_sodium_current_j_gate__j", "L_type_Ca_current_d_gate__d", "L_type_Ca_current_f_gate__f", "L_type_Ca_current_fCa_gate__fCa", "transient_outward_current_s_gate__s", "transient_outward_current_r_gate__r", "cytosolic_calcium_concentration", "calcium_dynamics__Ca_SR", "calcium_dynamics__g", "sodium_dynamics__Na_i", "potassium_dynamics__K_i"};
	runModel(p_cell, p_cell_original, "ten_tusscher_model_2004_endo", state_vars);


// nan != nan
	//livshitz_rudy_2007
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Celllivshitz_rudy_2007FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamiclivshitz_rudy_2007FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "INa__H", "INa__m", "INa__J", "ICaL__d", "ICaL__f", "IKr__xr", "IKs__xs1", "IKs__xs2", "ICaT__b", "ICaT__g", "Irel__Rel", "Na__Na_i", "K__K_i", "Ca__Ca_T", "Ca__Ca_JSR_T", "Ca__Ca_NSR", "Ca__Over"};;
	runModel(p_cell, p_cell_original, "livshitz_rudy_2007", state_vars);

// nan != nan
	//grandi2010ss
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellgrandi2010ssFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicgrandi2010ssFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"cell__sm", "cell__sh", "cell__sj", "cell__sd", "cell__sf", "cell__sfcaBj", "cell__sfcaBsl", "cell__sxtos", "cell__sytos", "cell__sxtof", "cell__sytof", "cell__sxkr", "cell__sxks", "cell__sRyRr", "cell__sRyRo", "cell__sRyRi", "cell__sNaBj", "cell__sNaBsl", "cell__sTnCL", "cell__sTnCHc", "cell__sTnCHm", "cell__sCaM", "cell__sMyoc", "cell__sMyom", "cell__sSRB", "cell__sSLLj", "cell__sSLLsl", "cell__sSLHj", "cell__sSLHsl", "cell__sCsqnb", "cell__sCa_sr", "cell__sNaj", "cell__sNasl", "cell__sNai", "cell__sCaj", "cell__sCasl", "cytosolic_calcium_concentration", "membrane_voltage"};
	runModel(p_cell, p_cell_original, "grandi2010ss", state_vars);


//nan != nan
	//hund_rudy_2004_a
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellhund_rudy_2004_aFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamichund_rudy_2004_aFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "INa__H", "INa__m", "INa__J", "ICaL__d", "ICaL__dp", "ICaL__f", "ICaL__fca", "ICaL__fca2", "ICaL__f2", "IKr__xr", "IKs__xs1", "IKs__xs2", "Ito__ydv", "Ito__ydv2", "Ito__zdv", "Ito2__AA", "INal__mL", "INal__hL", "Irel__CaMKtrap", "Irel__ro", "Irel__ri", "Na__Na_i", "K__K_i", "Cl__Cl_i", "cytosolic_calcium_concentration", "Ca__Ca_jsr", "Ca__Ca_nsr", "Ca__Ca_ss"};
	runModel(p_cell, p_cell_original, "hund_rudy_2004_a", state_vars);


// nan != nan
	//luo_rudy_1994
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellluo_rudy_1994FromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicluo_rudy_1994FromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "fast_sodium_current_j_gate__j", "L_type_Ca_channel_d_gate__d", "L_type_Ca_channel_f_gate__f", "time_dependent_potassium_current_X_gate__X", "cytosolic_sodium_concentration", "cytosolic_calcium_concentration", "cytosolic_potassium_concentration", "JSR_calcium_concentration", "NSR_calcium_concentration"};
	runModel(p_cell, p_cell_original, "luo_rudy_1994", state_vars);


// nan != nan
	//ten_tusscher_model_2004_epi
	p_cell = boost::shared_ptr<AbstractCvodeCell>(new Cellten_tusscher_model_2004_epiFromCellMLCvode(p_solver, p_stimulus));
	p_cell_original = boost::shared_ptr<AbstractCvodeCell>(new Dynamicten_tusscher_model_2004_epiFromCellMLCvode(p_solver, p_stimulus));
	state_vars = {"membrane_voltage", "rapid_time_dependent_potassium_current_Xr1_gate__Xr1", "rapid_time_dependent_potassium_current_Xr2_gate__Xr2", "slow_time_dependent_potassium_current_Xs_gate__Xs", "fast_sodium_current_m_gate__m", "fast_sodium_current_h_gate__h", "fast_sodium_current_j_gate__j", "L_type_Ca_current_d_gate__d", "L_type_Ca_current_f_gate__f", "L_type_Ca_current_fCa_gate__fCa", "transient_outward_current_s_gate__s", "transient_outward_current_r_gate__r", "cytosolic_calcium_concentration", "calcium_dynamics__Ca_SR", "calcium_dynamics__g", "sodium_dynamics__Na_i", "potassium_dynamics__K_i"};
	runModel(p_cell, p_cell_original, "ten_tusscher_model_2004_epi", state_vars);


    }


   void runModel(boost::shared_ptr<AbstractCvodeCell> pCell, boost::shared_ptr<AbstractCvodeCell> pCell2, std::string modelName, std::vector<std::string> state_vars){
	int num_state_vars = state_vars.size();

	ColumnDataReader data_reader("heart/test/data/cellml", modelName, false);
	std::vector<double> times = data_reader.GetValues("Time");
	std::vector<std::vector<double>> state_vector;
	for (unsigned int i=0; i< state_vars.size(); i++){
		state_vector.push_back(data_reader.GetValues(state_vars[i]));
	} 

	std::cout << "running " + modelName << std::endl;
	for(unsigned int i=0; i< times.size(); i++){
		// populate state vector

		const N_Vector rY = MakeNVector(*new std::vector<double>(num_state_vars));
		for (int l=0; l< num_state_vars; l++){
			NV_Ith_S(rY, l) = state_vector[l][i];
			TS_ASSERT(!isnan(state_vector[l][i]));
			TS_ASSERT(!isinf(state_vector[l][i]));

		}

		// create new empty parameters
		const N_Vector rDY = MakeNVector(*new std::vector<double>());
		const N_Vector rTmp1 = MakeNVector(*new std::vector<double>());
		const N_Vector rTmp2 = MakeNVector(*new std::vector<double>());
		const N_Vector rTmp3 = MakeNVector(*new std::vector<double>());

		//call jacobian method
		CHASTE_CVODE_DENSE_MATRIX rJacobian = NewDenseMat(num_state_vars, num_state_vars);
		CHASTE_CVODE_DENSE_MATRIX rJacobian2 = NewDenseMat(num_state_vars, num_state_vars);
		for (int j=0; j< num_state_vars; j++){
			for (int k=0; k< num_state_vars; k++){
				IJth(rJacobian, k, j) = 0.0;
				IJth(rJacobian2, k, j) = 0.0;
			}
		}

		pCell->EvaluateAnalyticJacobian(times[i], rY, rDY, rJacobian, rTmp1, rTmp2, rTmp3);
		pCell2->EvaluateAnalyticJacobian(times[i], rY, rDY, rJacobian2, rTmp1, rTmp2, rTmp3);

		for (int j=0; j< num_state_vars; j++){
			for (int k=0; k< num_state_vars; k++){
				if(k==6 && j ==0 ){
//						std::cout<< "(time, i,j): ("<<times[i]<< ", " << k <<", " <<j <<")"<<std::endl;
//						std::cout<< IJth(rJacobian, k, j)<< ", "<< IJth(rJacobian2, k, j)<<std::endl;
				}

				if (isnan(IJth(rJacobian, k, j)) && isnan(IJth(rJacobian2, k, j))){
					TS_WARN("NaN in both versions");
				}else if(isinf(IJth(rJacobian, k, j)) && isinf(IJth(rJacobian2, k, j)) && isinf(IJth(rJacobian, k, j)) == isinf(IJth(rJacobian2, k, j))){
					TS_WARN("INF in both versions");
				}else{
					if (abs(IJth(rJacobian, k, j) - IJth(rJacobian2, k, j)) > tolerance){
						std::cout<< "(time, i,j): ("<<times[i]<< ", " << k <<", " <<j <<")"<<std::endl;
						TS_ASSERT_DELTA(IJth(rJacobian, k, j), IJth(rJacobian2, k, j), tolerance);
					}
		                }
			}
		}

	}
	std::cout << "done!\n";
   }
};

#endif /*TESTCGCVODE_HPP_*/