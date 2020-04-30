#ifndef CELLNOBLE_NOBLE_SAN_MODEL_1984FROMCELLMLGRL1_HPP_
#define CELLNOBLE_NOBLE_SAN_MODEL_1984FROMCELLMLGRL1_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: NN_SAN_model_1984
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-04-30 02:43:53
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractGeneralizedRushLarsenCardiacCell.hpp"

class Cellnoble_noble_SAN_model_1984FromCellMLGRL1 : public AbstractGeneralizedRushLarsenCardiacCell
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractGeneralizedRushLarsenCardiacCell >(*this);
        
    }

    //
    // Settable parameters and readable variables
    //

public:

    double GetIntracellularCalciumConcentration();
    Cellnoble_noble_SAN_model_1984FromCellMLGRL1(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellnoble_noble_SAN_model_1984FromCellMLGRL1();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void UpdateTransmembranePotential(double var_chaste_interface__environment__time_converted);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time_converted);
    
    double EvaluateYDerivative0(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative0(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative1(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative1(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative2(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative2(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative3(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative3(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative4(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative4(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative5(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative5(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative6(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative6(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative7(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative7(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative8(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative8(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative9(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative9(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative10(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative10(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative11(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative11(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative12(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative12(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative13(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative13(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative14(double var_chaste_interface__environment__time_converted, std::vector<double>& rY);
    double EvaluatePartialDerivative14(double var_chaste_interface__environment__time_converted, std::vector<double>& rY, double delta, bool forceNumerical=false);

};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellnoble_noble_SAN_model_1984FromCellMLGRL1)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellnoble_noble_SAN_model_1984FromCellMLGRL1 * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellnoble_noble_SAN_model_1984FromCellMLGRL1 * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellnoble_noble_SAN_model_1984FromCellMLGRL1(p_solver, p_stimulus);
        }

    }

}

#endif // CELLNOBLE_NOBLE_SAN_MODEL_1984FROMCELLMLGRL1_HPP_