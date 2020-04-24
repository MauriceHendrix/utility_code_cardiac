#ifndef CELLZHANG_SAN_MODEL_2000_0D_CAPABLEFROMCELLML_HPP_
#define CELLZHANG_SAN_MODEL_2000_0D_CAPABLEFROMCELLML_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: zhang_SAN_model_2000_0D_capable
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-04-21 23:38:24
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractCardiacCell.hpp"

class Cellzhang_SAN_model_2000_0D_capableFromCellML : public AbstractCardiacCell
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractCardiacCell >(*this);
        
    }

    //
    // Settable parameters and readable variables
    //

public:

    Cellzhang_SAN_model_2000_0D_capableFromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellzhang_SAN_model_2000_0D_capableFromCellML();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time_converted, const std::vector<double>& rY, std::vector<double>& rDY);

};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellzhang_SAN_model_2000_0D_capableFromCellML)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellzhang_SAN_model_2000_0D_capableFromCellML * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellzhang_SAN_model_2000_0D_capableFromCellML * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellzhang_SAN_model_2000_0D_capableFromCellML(p_solver, p_stimulus);
        }

    }

}

#endif // CELLZHANG_SAN_MODEL_2000_0D_CAPABLEFROMCELLML_HPP_
