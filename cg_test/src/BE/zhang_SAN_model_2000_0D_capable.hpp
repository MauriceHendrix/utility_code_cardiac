#ifndef CELLZHANG_SAN_MODEL_2000_0D_CAPABLEFROMCELLMLBACKWARDEULER_HPP_
#define CELLZHANG_SAN_MODEL_2000_0D_CAPABLEFROMCELLMLBACKWARDEULER_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: zhang_SAN_model_2000_0D_capable
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-03-25 18:42:23
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractBackwardEulerCardiacCell.hpp"

class Cellzhang_SAN_model_2000_0D_capableFromCellMLBackwardEuler : public AbstractBackwardEulerCardiacCell<0>
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractBackwardEulerCardiacCell<0> >(*this);
        
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:

    Cellzhang_SAN_model_2000_0D_capableFromCellMLBackwardEuler(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellzhang_SAN_model_2000_0D_capableFromCellMLBackwardEuler();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);protected:
    void UpdateTransmembranePotential(double var_chaste_interface__environment__time_converted);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time_converted);

};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellzhang_SAN_model_2000_0D_capableFromCellMLBackwardEuler)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellzhang_SAN_model_2000_0D_capableFromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellzhang_SAN_model_2000_0D_capableFromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellzhang_SAN_model_2000_0D_capableFromCellMLBackwardEuler(p_solver, p_stimulus);
        }

    }

}

#endif // CELLZHANG_SAN_MODEL_2000_0D_CAPABLEFROMCELLMLBACKWARDEULER_HPP_
