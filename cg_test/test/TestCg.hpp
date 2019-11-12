#ifndef TESTCG_HPP_
#define TESTCG_HPP_

#include "PyCmlLongHelperTestSuite.hpp"

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


};

#endif /*TESTCG_HPP_*/
