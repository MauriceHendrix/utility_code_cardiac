#ifdef CHASTE_CVODE
#ifndef DYNAMICIRIBE_MODEL_2006_WITHOUT_OTHERWISE_SECTIONFROMCELLMLCVODE_HPP_
#define DYNAMICIRIBE_MODEL_2006_WITHOUT_OTHERWISE_SECTIONFROMCELLMLCVODE_HPP_

//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: iribe_model_2006
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on Tue Feb 18 17:10:30 2020
//! 
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractCvodeCell.hpp"
#include "AbstractDynamicallyLoadableEntity.hpp"
#include "AbstractStimulusFunction.hpp"

class Dynamiciribe_model_2006_without_otherwise_sectionFromCellMLCvode : public AbstractCvodeCell, public AbstractDynamicallyLoadableEntity
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractCvodeCell >(*this);
        archive & boost::serialization::base_object<AbstractDynamicallyLoadableEntity>(*this);
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:
    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    double GetIntracellularCalciumConcentration();
    Dynamiciribe_model_2006_without_otherwise_sectionFromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Dynamiciribe_model_2006_without_otherwise_sectionFromCellMLCvode();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time, const N_Vector rY, N_Vector rDY);
    void EvaluateAnalyticJacobian(double var_chaste_interface__environment__time, N_Vector rY, N_Vector rDY, CHASTE_CVODE_DENSE_MATRIX rJacobian, N_Vector rTmp1, N_Vector rTmp2, N_Vector rTmp3);
};


// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Dynamiciribe_model_2006_without_otherwise_sectionFromCellMLCvode)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Dynamiciribe_model_2006_without_otherwise_sectionFromCellMLCvode * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }
        
        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Dynamiciribe_model_2006_without_otherwise_sectionFromCellMLCvode * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Dynamiciribe_model_2006_without_otherwise_sectionFromCellMLCvode(p_solver, p_stimulus);
        }
        
    }
    
}

#endif // DYNAMICIRIBE_MODEL_2006_WITHOUT_OTHERWISE_SECTIONFROMCELLMLCVODE_HPP_
#endif // CHASTE_CVODE
