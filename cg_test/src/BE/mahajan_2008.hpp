#ifndef CELLMAHAJAN_2008FROMCELLMLBACKWARDEULER_HPP_
#define CELLMAHAJAN_2008FROMCELLMLBACKWARDEULER_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: mahajan_shiferaw_model_2008
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-04-09 00:43:17
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractBackwardEulerCardiacCell.hpp"

class Cellmahajan_2008FromCellMLBackwardEuler : public AbstractBackwardEulerCardiacCell<15>
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractBackwardEulerCardiacCell<15> >(*this);
        
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:

    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    double GetIntracellularCalciumConcentration();
    Cellmahajan_2008FromCellMLBackwardEuler(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellmahajan_2008FromCellMLBackwardEuler();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);void ComputeResidual(double var_chaste_interface__Environment__time, const double rCurrentGuess[15], double rResidual[15]);
    void ComputeJacobian(double var_chaste_interface__Environment__time, const double rCurrentGuess[15], double rJacobian[15][15]);protected:
    void UpdateTransmembranePotential(double var_chaste_interface__Environment__time);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__Environment__time);

};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellmahajan_2008FromCellMLBackwardEuler)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellmahajan_2008FromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellmahajan_2008FromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellmahajan_2008FromCellMLBackwardEuler(p_solver, p_stimulus);
        }

    }

}

#endif // CELLMAHAJAN_2008FROMCELLMLBACKWARDEULER_HPP_
