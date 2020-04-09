#ifndef CELLSTEWART_ZHANG_MODEL_2008_SSFROMCELLMLBACKWARDEULER_HPP_
#define CELLSTEWART_ZHANG_MODEL_2008_SSFROMCELLMLBACKWARDEULER_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: stewart_zhang_model_2008
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-04-09 00:49:09
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractBackwardEulerCardiacCell.hpp"

class Cellstewart_zhang_model_2008_ssFromCellMLBackwardEuler : public AbstractBackwardEulerCardiacCell<7>
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractBackwardEulerCardiacCell<7> >(*this);
        
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:

    double GetIntracellularCalciumConcentration();
    Cellstewart_zhang_model_2008_ssFromCellMLBackwardEuler(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellstewart_zhang_model_2008_ssFromCellMLBackwardEuler();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);void ComputeResidual(double var_chaste_interface__environment__time, const double rCurrentGuess[7], double rResidual[7]);
    void ComputeJacobian(double var_chaste_interface__environment__time, const double rCurrentGuess[7], double rJacobian[7][7]);protected:
    void UpdateTransmembranePotential(double var_chaste_interface__environment__time);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time);

};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellstewart_zhang_model_2008_ssFromCellMLBackwardEuler)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellstewart_zhang_model_2008_ssFromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellstewart_zhang_model_2008_ssFromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellstewart_zhang_model_2008_ssFromCellMLBackwardEuler(p_solver, p_stimulus);
        }

    }

}

#endif // CELLSTEWART_ZHANG_MODEL_2008_SSFROMCELLMLBACKWARDEULER_HPP_
