#ifndef TESTMANUALHODGKIN_HUXLEY_SQUID_AXON_MODEL_1952_MODIFIEDFROMCELLML_HPP_
#define TESTMANUALHODGKIN_HUXLEY_SQUID_AXON_MODEL_1952_MODIFIEDFROMCELLML_HPP_

//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: hodgkin_huxley_squid_axon_model_1952_modified
//! 
//! Processed by webalab_cg - CellML Tools in Python: https://github.com/ModellingWebLab/weblab-cg
//!     (translators: , webalab_cg: , options: normal)
//! on 2019-11-19 15:40:31
//! 
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractCardiacCell.hpp"

#include "AbstractStimulusFunction.hpp"

class TestManualhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML : public AbstractCardiacCell
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractCardiacCell >(*this);
        archive & boost::serialization::base_object<AbstractDynamicallyLoadableEntity>(*this);
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:
    TestManualhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~TestManualhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time, const std::vector<double>& rY, std::vector<double>& rDY);
};


// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(TestManualhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const TestManualhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }
        
        template<class Archive>
        inline void load_construct_data(
            Archive & ar, TestManualhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)TestManualhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML(p_solver, p_stimulus);
        }
        
    }
    
}

#endif // TESTMANUALHODGKIN_HUXLEY_SQUID_AXON_MODEL_1952_MODIFIEDFROMCELLML_HPP_
