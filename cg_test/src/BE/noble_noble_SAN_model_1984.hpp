#ifndef CELLNOBLE_NOBLE_SAN_MODEL_1984FROMCELLMLBACKWARDEULER_HPP_
#define CELLNOBLE_NOBLE_SAN_MODEL_1984FROMCELLMLBACKWARDEULER_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: NN_SAN_model_1984
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-03-14 15:03:25
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractBackwardEulerCardiacCell.hpp"

class Cellnoble_noble_SAN_model_1984FromCellMLBackwardEuler : public AbstractBackwardEulerCardiacCell<7>
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
    Cellnoble_noble_SAN_model_1984FromCellMLBackwardEuler(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellnoble_noble_SAN_model_1984FromCellMLBackwardEuler();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);void ComputeResidual(double var_chaste_interface__environment__time_converted, const double rCurrentGuess[7], double rResidual[7]);
    void ComputeJacobian(double var_chaste_interface__environment__time_converted, const double rCurrentGuess[7], double rJacobian[7][7]);protected:
    void UpdateTransmembranePotential(double var_chaste_interface__environment__time_converted);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time_converted);

};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellnoble_noble_SAN_model_1984FromCellMLBackwardEuler)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellnoble_noble_SAN_model_1984FromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellnoble_noble_SAN_model_1984FromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellnoble_noble_SAN_model_1984FromCellMLBackwardEuler(p_solver, p_stimulus);
        }

    }

}

#endif // CELLNOBLE_NOBLE_SAN_MODEL_1984FROMCELLMLBACKWARDEULER_HPP_
