#ifndef TESTCG_HPP_
#define TESTCG_HPP_

#include <boost/foreach.hpp>
#include <vector>

#include "HeartConfig.hpp"

#include "CompareToPyCmlLongHelperTestSuite.hpp"

/**
 * Test PyCml functionality by dynamically loading (and hence converting) a wide
 * range of cell models.
 *
 * May need a test-suite setup or similar to define model-specific parameters?
 * Should we pick up the list of models by reading the folder heart/test/data/cellml?
 */
class TestCg : public CompareToPyCmlLongHelperTestSuite
{
public:
    void TestNormalCells()
    {
        std::cout << "Search for 'Failure', ': ***', 'Error', or 'Failed' to find problems." << std::endl;

        std::string dirname("TestCgLongNormal");
        std::vector<std::string> args;
        args.push_back("--Wu");
        std::vector<std::string> models;
        AddAllModels(models);
        HeartConfig::Instance()->SetOdePdeAndPrintingTimeSteps(0.005, 0.1, 1.0);
        RunTests(dirname, models, args);
    }

    void TestCvodeCells()
    {
        std::cout << "CVODE models-----" << std::endl;
#ifdef CHASTE_CVODE
        std::string dirname("TestPyCmlLongCvodeNumericalJ");
        std::vector<std::string> args;
        args.push_back("--Wu");
        args.push_back("--cvode");
        std::vector<std::string> models;
        AddAllModels(models);

	SetModelType("Cvode");
        SetUseCvodeJacobian(false);
        RunTests(dirname, models, args);
        SetUseCvodeJacobian(true);
#endif
    }

    void TestAnalyticCvodeCells()
    {
       std::cout << "CVODE with JACOBIAN-----" << std::endl;
#ifdef CHASTE_CVODE
       std::string dirname("TestPyCmlLongCvodeAnalyticJ");
       std::vector<std::string> args;
       args.push_back("--Wu");
       args.push_back("--cvode");
       std::vector<std::string> models;
       SetModelType("Cvode");
	   SetUseCvodeJacobian(true);
       AddAllModels(models);
        // These have NaN in the jacobian due to massive exponentials
       std::vector<std::string> bad_models = boost::assign::list_of("aslanidi_model_2009")("hund_rudy_2004_a")("livshitz_rudy_2007");
       BOOST_FOREACH (std::string bad_model, bad_models)
       {
           models.erase(std::find(models.begin(), models.end(), bad_model));
       }

       RunTests(dirname, models, args);
#endif
    }

    void TestBackwardEulerCells()
    {
        std::string dirname("TestPyCmlLongBE");
        std::vector<std::string> args;
        args.push_back("--Wu");
        args.push_back("--backward-euler");
        SetModelType("BE");

        std::vector<std::string> models;
        AddAllModels(models);

        std::vector<std::string> diff_models; // Models that need a smaller dt
        diff_models.push_back("iyer_model_2004");
        diff_models.push_back("iyer_model_2007");
        diff_models.push_back("jafri_rice_winslow_model_1998");
        diff_models.push_back("pandit_model_2001_epi");
        diff_models.push_back("priebe_beuckelmann_model_1998");
        diff_models.push_back("viswanathan_model_1999_epi");
        diff_models.push_back("winslow_model_1999");
        BOOST_FOREACH (std::string diff_model, diff_models)
        {
            models.erase(std::find(models.begin(), models.end(), diff_model));
        }

        // These have NaN in the jacobian due to massive exponentials
        std::vector<std::string> bad_models = boost::assign::list_of("hund_rudy_2004_a");
        BOOST_FOREACH (std::string bad_model, bad_models)
        {
            models.erase(std::find(models.begin(), models.end(), bad_model));
        }

        HeartConfig::Instance()->SetOdePdeAndPrintingTimeSteps(0.01, 0.1, 1.0);
        RunTests(dirname, models, args, true);

        dirname = dirname + "-difficult";
        HeartConfig::Instance()->SetOdePdeAndPrintingTimeSteps(0.001, 0.1, 1.0);
        RunTests(dirname, diff_models, args, true);
    }



};

#endif /*TESTCG_HPP_*/
