#ifndef CELLCOURTEMANCHE_RAMIREZ_NATTEL_MODEL_1998FROMCELLMLRUSHLARSEN_HPP_
#define CELLCOURTEMANCHE_RAMIREZ_NATTEL_MODEL_1998FROMCELLMLRUSHLARSEN_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: courtemanche_ramirez_nattel_model_1998
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-04-09 01:17:17
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractRushLarsenCardiacCell.hpp"

class Cellcourtemanche_ramirez_nattel_model_1998FromCellMLRushLarsen : public AbstractRushLarsenCardiacCell
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

    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    Cellcourtemanche_ramirez_nattel_model_1998FromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellcourtemanche_ramirez_nattel_model_1998FromCellMLRushLarsen();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateEquations(double var_chaste_interface__environment__time, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf);
    void ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf);

};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellcourtemanche_ramirez_nattel_model_1998FromCellMLRushLarsen)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellcourtemanche_ramirez_nattel_model_1998FromCellMLRushLarsen * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellcourtemanche_ramirez_nattel_model_1998FromCellMLRushLarsen * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellcourtemanche_ramirez_nattel_model_1998FromCellMLRushLarsen(p_solver, p_stimulus);
        }

    }

}

#endif // CELLCOURTEMANCHE_RAMIREZ_NATTEL_MODEL_1998FROMCELLMLRUSHLARSEN_HPP_
