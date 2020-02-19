#ifdef CHASTE_CVODE
#ifndef DYNAMICDOKOS_MODEL_1996FROMCELLMLCVODE_HPP_
#define DYNAMICDOKOS_MODEL_1996FROMCELLMLCVODE_HPP_

//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: dokos_model_1996
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on Tue Feb 18 17:08:57 2020
//! 
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractCvodeCell.hpp"
#include "AbstractDynamicallyLoadableEntity.hpp"
#include "AbstractStimulusFunction.hpp"

class Dynamicdokos_model_1996FromCellMLCvode : public AbstractCvodeCell, public AbstractDynamicallyLoadableEntity
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
    double GetIntracellularCalciumConcentration();
    Dynamicdokos_model_1996FromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Dynamicdokos_model_1996FromCellMLCvode();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time, const N_Vector rY, N_Vector rDY);
    void EvaluateAnalyticJacobian(double var_chaste_interface__environment__time, N_Vector rY, N_Vector rDY, CHASTE_CVODE_DENSE_MATRIX rJacobian, N_Vector rTmp1, N_Vector rTmp2, N_Vector rTmp3);
};


// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Dynamicdokos_model_1996FromCellMLCvode)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Dynamicdokos_model_1996FromCellMLCvode * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }
        
        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Dynamicdokos_model_1996FromCellMLCvode * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Dynamicdokos_model_1996FromCellMLCvode(p_solver, p_stimulus);
        }
        
    }
    
}

#endif // DYNAMICDOKOS_MODEL_1996FROMCELLMLCVODE_HPP_
#endif // CHASTE_CVODE
