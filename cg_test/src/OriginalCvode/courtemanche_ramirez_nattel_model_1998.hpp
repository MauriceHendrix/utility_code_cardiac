#ifdef CHASTE_CVODE
#ifndef DYNAMICCOURTEMANCHE_RAMIREZ_NATTEL_MODEL_1998FROMCELLMLCVODE_HPP_
#define DYNAMICCOURTEMANCHE_RAMIREZ_NATTEL_MODEL_1998FROMCELLMLCVODE_HPP_

//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: courtemanche_ramirez_nattel_model_1998
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on Thu Jan 30 15:21:21 2020
//! 
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractCvodeCell.hpp"
#include "AbstractDynamicallyLoadableEntity.hpp"
#include "AbstractStimulusFunction.hpp"

class Dynamiccourtemanche_ramirez_nattel_model_1998FromCellMLCvode : public AbstractCvodeCell, public AbstractDynamicallyLoadableEntity
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
    Dynamiccourtemanche_ramirez_nattel_model_1998FromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Dynamiccourtemanche_ramirez_nattel_model_1998FromCellMLCvode();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time, const N_Vector rY, N_Vector rDY);
    void EvaluateAnalyticJacobian(double var_chaste_interface__environment__time, N_Vector rY, N_Vector rDY, CHASTE_CVODE_DENSE_MATRIX rJacobian, N_Vector rTmp1, N_Vector rTmp2, N_Vector rTmp3);
};


// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Dynamiccourtemanche_ramirez_nattel_model_1998FromCellMLCvode)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Dynamiccourtemanche_ramirez_nattel_model_1998FromCellMLCvode * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }
        
        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Dynamiccourtemanche_ramirez_nattel_model_1998FromCellMLCvode * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Dynamiccourtemanche_ramirez_nattel_model_1998FromCellMLCvode(p_solver, p_stimulus);
        }
        
    }
    
}

#endif // DYNAMICCOURTEMANCHE_RAMIREZ_NATTEL_MODEL_1998FROMCELLMLCVODE_HPP_
#endif // CHASTE_CVODE
