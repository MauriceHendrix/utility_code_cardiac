#ifndef CELLHUND_RUDY_2004_AFROMCELLMLRUSHLARSEN_HPP_
#define CELLHUND_RUDY_2004_AFROMCELLMLRUSHLARSEN_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: hund_rudy_2004
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-04-09 01:22:16
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractRushLarsenCardiacCell.hpp"

class Cellhund_rudy_2004_aFromCellMLRushLarsen : public AbstractRushLarsenCardiacCell
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
    double GetIntracellularCalciumConcentration();
    Cellhund_rudy_2004_aFromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellhund_rudy_2004_aFromCellMLRushLarsen();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateEquations(double var_chaste_interface__Environment__time, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf);
    void ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf);

};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellhund_rudy_2004_aFromCellMLRushLarsen)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellhund_rudy_2004_aFromCellMLRushLarsen * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellhund_rudy_2004_aFromCellMLRushLarsen * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellhund_rudy_2004_aFromCellMLRushLarsen(p_solver, p_stimulus);
        }

    }

}

#endif // CELLHUND_RUDY_2004_AFROMCELLMLRUSHLARSEN_HPP_
