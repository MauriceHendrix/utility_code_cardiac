#ifndef CELLZHANG_SAN_MODEL_2000_0D_CAPABLEFROMCELLMLRUSHLARSEN_HPP_
#define CELLZHANG_SAN_MODEL_2000_0D_CAPABLEFROMCELLMLRUSHLARSEN_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: zhang_SAN_model_2000_0D_capable
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-04-29 14:24:56
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractRushLarsenCardiacCell.hpp"

class Cellzhang_SAN_model_2000_0D_capableFromCellMLRushLarsen : public AbstractRushLarsenCardiacCell
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractRushLarsenCardiacCell >(*this);
        
    }

    //
    // Settable parameters and readable variables
    //

public:

    Cellzhang_SAN_model_2000_0D_capableFromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellzhang_SAN_model_2000_0D_capableFromCellMLRushLarsen();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateEquations(double var_chaste_interface__environment__time_converted, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf);
    void ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf);

};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellzhang_SAN_model_2000_0D_capableFromCellMLRushLarsen)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellzhang_SAN_model_2000_0D_capableFromCellMLRushLarsen * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellzhang_SAN_model_2000_0D_capableFromCellMLRushLarsen * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellzhang_SAN_model_2000_0D_capableFromCellMLRushLarsen(p_solver, p_stimulus);
        }

    }

}

#endif // CELLZHANG_SAN_MODEL_2000_0D_CAPABLEFROMCELLMLRUSHLARSEN_HPP_