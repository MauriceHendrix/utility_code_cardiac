#ifndef CELLFINK_NOBLE_GILES_MODEL_2008FROMCELLMLRUSHLARSEN_HPP_
#define CELLFINK_NOBLE_GILES_MODEL_2008FROMCELLMLRUSHLARSEN_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: fink_noble_giles_model_2008
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-04-09 01:20:33
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractRushLarsenCardiacCell.hpp"

class Cellfink_noble_giles_model_2008FromCellMLRushLarsen : public AbstractRushLarsenCardiacCell
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
    Cellfink_noble_giles_model_2008FromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellfink_noble_giles_model_2008FromCellMLRushLarsen();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateEquations(double var_chaste_interface__Environment__time, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf);
    void ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf);

};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellfink_noble_giles_model_2008FromCellMLRushLarsen)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellfink_noble_giles_model_2008FromCellMLRushLarsen * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellfink_noble_giles_model_2008FromCellMLRushLarsen * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellfink_noble_giles_model_2008FromCellMLRushLarsen(p_solver, p_stimulus);
        }

    }

}

#endif // CELLFINK_NOBLE_GILES_MODEL_2008FROMCELLMLRUSHLARSEN_HPP_
