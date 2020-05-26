#ifdef CHASTE_CVODE
#ifndef CELLNYGREN_ATRIAL_MODEL_1998FROMCELLMLCVODE_HPP_
#define CELLNYGREN_ATRIAL_MODEL_1998FROMCELLMLCVODE_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: nygren_atrial_model_1998
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-05-21 17:14:39
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractStimulusFunction.hpp"
#include "AbstractCvodeCell.hpp"

class Cellnygren_atrial_model_1998FromCellMLCvode : public AbstractCvodeCell
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractCvodeCell >(*this);
        
    }

    //
    // Settable parameters and readable variables
    //

public:

    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    double GetIntracellularCalciumConcentration();
    Cellnygren_atrial_model_1998FromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellnygren_atrial_model_1998FromCellMLCvode();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time_converted, const N_Vector rY, N_Vector rDY);
    N_Vector ComputeDerivedQuantities(double var_chaste_interface__environment__time_converted, const N_Vector & rY);
    void EvaluateAnalyticJacobian(double var_chaste_interface__environment__time_converted, N_Vector rY, N_Vector rDY, CHASTE_CVODE_DENSE_MATRIX rJacobian, N_Vector rTmp1, N_Vector rTmp2, N_Vector rTmp3);
};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellnygren_atrial_model_1998FromCellMLCvode)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellnygren_atrial_model_1998FromCellMLCvode * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellnygren_atrial_model_1998FromCellMLCvode * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellnygren_atrial_model_1998FromCellMLCvode(p_solver, p_stimulus);
        }

    }

}

#endif // CELLNYGREN_ATRIAL_MODEL_1998FROMCELLMLCVODE_HPP_
#endif // CHASTE_CVODE