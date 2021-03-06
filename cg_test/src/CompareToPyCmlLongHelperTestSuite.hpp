/*

Copyright (c) 2005-2019, University of Oxford.
All rights reserved.

University of Oxford means the Chancellor, Masters and Scholars of the
University of Oxford, having an administrative office at Wellington
Square, Oxford OX1 2JD, UK.

This file is part of Chaste.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
 * Neither the name of the University of Oxford nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef COMPARETOPYCMLLONGHELPERCLASS_MANUAL_HPP_
#define COMPARETOPYCMLLONGHELPERCLASS_MANUAL_HPP_

#include <cxxtest/TestSuite.h>

#include <algorithm>
#include <boost/assign/list_of.hpp>
#include <boost/foreach.hpp>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>

#include "AbstractCardiacCell.hpp"
#include "AbstractCardiacCellInterface.hpp"
#include "AbstractCvodeCell.hpp"
#include "AbstractGeneralizedRushLarsenCardiacCell.hpp"
#include "AbstractRushLarsenCardiacCell.hpp"
#include "Timer.hpp"

#include "SimpleStimulus.hpp"
#include "EulerIvpOdeSolver.hpp"

#include "CellMLToSharedLibraryConverter.hpp"
#include "DynamicCellModelLoader.hpp"
#include "DynamicModelLoaderRegistry.hpp"
#include "FileFinder.hpp"

#include "CellProperties.hpp"
#include "Exception.hpp"
#include "HeartConfig.hpp"
#include "RunAndCheckIonicModels.hpp"
#include "Warnings.hpp"

#include "all_models.hpp"


/**
 * Helper class to allow us to split the PyCmlLong tests into multiple test suites.
 */
class CompareToPyCmlLongHelperTestSuite : public CxxTest::TestSuite
{

private:
    bool mUseCvodeJacobian = true;
    std::string modelType = "Normal";

    double GetAttribute(boost::shared_ptr<AbstractCardiacCellInterface> pCell,
                        const std::string& rAttrName,
                        double defaultValue)
    {
        AbstractUntemplatedParameterisedSystem* p_system
            = dynamic_cast<AbstractUntemplatedParameterisedSystem*>(pCell.get());
        assert(p_system);
        double attr_value;
        if (p_system->HasAttribute(rAttrName))
        {
            attr_value = p_system->GetAttribute(rAttrName);
        }
        else
        {
            attr_value = defaultValue;
        }
        return attr_value;
    }

    void Simulate(const std::string& rOutputDirName,
                  const std::string& rModelName,
                  boost::shared_ptr<AbstractCardiacCellInterface> pCell)
    {
        double end_time = GetAttribute(pCell, "SuggestedCycleLength", 700.0); // ms
        if (pCell->GetSolver() || dynamic_cast<AbstractRushLarsenCardiacCell*>(pCell.get()))
        {
            double dt = GetAttribute(pCell, "SuggestedForwardEulerTimestep", 0.0);
            if (dt > 0.0)
            {
                pCell->SetTimestep(dt);
            }
        }
#ifdef CHASTE_CVODE
        AbstractCvodeSystem* p_cvode_cell = dynamic_cast<AbstractCvodeSystem*>(pCell.get());
        if (p_cvode_cell)
        {
            // Set a larger max internal time steps per sampling interval (CVODE's default is 500)
            p_cvode_cell->SetMaxSteps(1000);
            // Numerical or analytic J for CVODE?
            if (!mUseCvodeJacobian)
            {
                p_cvode_cell->ForceUseOfNumericalJacobian();
            }
        }
#endif
        double sampling_interval = 1.0; // ms; used as max dt for CVODE too
        Timer::Reset();
        OdeSolution solution = pCell->Compute(0.0, end_time, sampling_interval);
        std::stringstream message;
        message << "Model " << rModelName << " writing to " << rOutputDirName << " took";
        Timer::Print(message.str());

        const unsigned output_freq = 10; // Only output every N samples
        solution.WriteToFile(rOutputDirName, rModelName, "ms", output_freq, false);
        // Check an AP was produced
        std::vector<double> voltages = solution.GetVariableAtIndex(pCell->GetVoltageIndex());
        CellProperties props(voltages, solution.rGetTimes());
        props.GetLastActionPotentialDuration(90.0); // Don't catch the exception here if it's thrown
        // Compare against saved results
        CheckResults(rModelName, voltages, solution.rGetTimes(), output_freq);
    }

    void CheckResults(const std::string& rModelName,
                      std::vector<double>& rVoltages,
                      std::vector<double>& rTimes,
                      unsigned outputFreq,
                      double tolerance = 1.0)
    {
        // Read data entries for the reference file
        ColumnDataReader data_reader("heart/test/data/cellml", rModelName, false);
        std::vector<double> valid_times = data_reader.GetValues("Time");
        std::vector<double> valid_voltages = GetVoltages(data_reader);

        TS_ASSERT_EQUALS(rTimes.size(), (valid_times.size() - 1) * outputFreq + 1);
        for (unsigned i = 0; i < valid_times.size(); i++)
        {
            TS_ASSERT_DELTA(rTimes[i * outputFreq], valid_times[i], 1e-12);
            TS_ASSERT_DELTA(rVoltages[i * outputFreq], valid_voltages[i], tolerance);
        }
    }

    void RunTest(const std::string& rOutputDirName,
                 const std::string& rModelName,
                 const std::vector<std::string>& rArgs,
                 bool testLookupTables = false,
                 double tableTestV = -1000)
    {
        // Copy CellML file (and .out if present) into output dir
        OutputFileHandler handler(rOutputDirName, true);
        FileFinder cellml_file("heart/test/data/cellml/" + rModelName + ".cellml", RelativeTo::ChasteSourceRoot);
        handler.CopyFileTo(cellml_file);
        FileFinder out_file("heart/test/data/cellml/" + rModelName + ".out", RelativeTo::ChasteSourceRoot);
        if (out_file.Exists())
        {
            handler.CopyFileTo(out_file);
        }

        // Create options file
        std::vector<std::string> args(rArgs);
        //        args.push_back("--profile");
        CellMLToSharedLibraryConverter converter(true);
        if (!args.empty())
        {
            converter.CreateOptionsFile(handler, rModelName, args);
        }

        // Do the conversion
        FileFinder copied_file(rOutputDirName + "/" + rModelName + ".cellml", RelativeTo::ChasteTestOutput);
//        DynamicCellModelLoaderPtr p_loader = converter.Convert(copied_file);
//        // Apply a stimulus of -40 uA/cm^2 - should work for all models
//        boost::shared_ptr<AbstractCardiacCellInterface> p_cell(CreateCellWithStandardStimulus(*p_loader, -40.0));
        boost::shared_ptr<AbstractCardiacCellInterface> p_cell = GetModel(rModelName, rArgs);

        // Check that the default stimulus units are correct
        if (p_cell->HasCellMLDefaultStimulus())
        {
            // Record the existing stimulus and re-apply it at the end
            boost::shared_ptr<AbstractStimulusFunction> original_stim = p_cell->GetStimulusFunction();

            // Tell the cell to use the default stimulus and retrieve it
            boost::shared_ptr<RegularStimulus> p_reg_stim = p_cell->UseCellMLDefaultStimulus();

            if (rModelName != "aslanidi_model_2009") // Even before recent changes aslanidi model has stimulus of -400 !
            {
                // Stimulus magnitude should be approximately between -5 and -81 uA/cm^2
                TS_ASSERT_LESS_THAN(p_reg_stim->GetMagnitude(), -5);
                TS_ASSERT_LESS_THAN(-81, p_reg_stim->GetMagnitude());
            }

            // Stimulus duration should be approximately between 0.1 and 5 ms.
            TS_ASSERT_LESS_THAN(p_reg_stim->GetDuration(), 6.01);
            TS_ASSERT_LESS_THAN(0.1, p_reg_stim->GetDuration());

            // Stimulus period should be approximately between 70 (for bondarenko - seems fast! - would expect 8-10 beats per second for mouse) and 2000ms.
            TS_ASSERT_LESS_THAN(p_reg_stim->GetPeriod(), 2000);
            TS_ASSERT_LESS_THAN(70, p_reg_stim->GetPeriod());

            p_cell->SetIntracellularStimulusFunction(original_stim);
        }

        // Check lookup tables exist if they should and throw appropriate errors if we go outside their range...
        if (testLookupTables && rModelName != "hodgkin_huxley_squid_axon_model_1952_modified")
        {
            double v = p_cell->GetVoltage();
            p_cell->SetVoltage(tableTestV);

          // This try catch used to be TS_ASSERT_THROWS_CONTAINS (see #2982)
            try
            {
                p_cell->GetIIonic();
            }
            catch (const Exception& e)
            {
                TS_ASSERT(e.CheckShortMessageContains("outside lookup table range") == "");
            }

            p_cell->SetVoltage(v);
        }
        std::cout << "Running simulation...\n"
                  << std::flush;
        Simulate(rOutputDirName, rModelName, p_cell);
    }

    boost::shared_ptr<AbstractCardiacCellInterface> GetModel(std::string rModelName, std::vector<std::string> rArgs){

        double magnitude=-40.0;
        double duration = 2.0; // ms
        double when = 50.0; // ms
        boost::shared_ptr<AbstractStimulusFunction> p_stimulus(new SimpleStimulus(magnitude, duration, when));
        boost::shared_ptr<AbstractIvpOdeSolver> p_solver(new EulerIvpOdeSolver);
	std::cout<<"--------- "<<modelType<<" -------\n";
        boost::shared_ptr<AbstractCardiacCellInterface> p_cell;
        if(rModelName == "aslanidi_model_2009"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellaslanidi_model_2009FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellaslanidi_model_2009FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellaslanidi_model_2009FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellaslanidi_model_2009FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellaslanidi_model_2009FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellaslanidi_model_2009FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "beeler_reuter_model_1977"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbeeler_reuter_model_1977FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbeeler_reuter_model_1977FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbeeler_reuter_model_1977FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbeeler_reuter_model_1977FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbeeler_reuter_model_1977FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbeeler_reuter_model_1977FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "bondarenko_model_2004_apex"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbondarenko_model_2004_apexFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbondarenko_model_2004_apexFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbondarenko_model_2004_apexFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbondarenko_model_2004_apexFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbondarenko_model_2004_apexFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellbondarenko_model_2004_apexFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "courtemanche_ramirez_nattel_model_1998"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellcourtemanche_ramirez_nattel_model_1998FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellcourtemanche_ramirez_nattel_model_1998FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellcourtemanche_ramirez_nattel_model_1998FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellcourtemanche_ramirez_nattel_model_1998FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellcourtemanche_ramirez_nattel_model_1998FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellcourtemanche_ramirez_nattel_model_1998FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "decker_2009"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldecker_2009FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldecker_2009FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldecker_2009FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldecker_2009FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldecker_2009FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldecker_2009FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "demir_model_1994"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldemir_model_1994FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldemir_model_1994FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldemir_model_1994FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldemir_model_1994FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldemir_model_1994FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldemir_model_1994FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "dokos_model_1996"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldokos_model_1996FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldokos_model_1996FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldokos_model_1996FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldokos_model_1996FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldokos_model_1996FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celldokos_model_1996FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "earm_noble_model_1990"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellearm_noble_model_1990FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellearm_noble_model_1990FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellearm_noble_model_1990FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellearm_noble_model_1990FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellearm_noble_model_1990FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellearm_noble_model_1990FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "espinosa_model_1998_normal"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellespinosa_model_1998_normalFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellespinosa_model_1998_normalFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellespinosa_model_1998_normalFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellespinosa_model_1998_normalFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellespinosa_model_1998_normalFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellespinosa_model_1998_normalFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "fink_noble_giles_model_2008"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellfink_noble_giles_model_2008FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellfink_noble_giles_model_2008FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellfink_noble_giles_model_2008FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellfink_noble_giles_model_2008FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellfink_noble_giles_model_2008FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellfink_noble_giles_model_2008FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "grandi2010ss"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellgrandi2010ssFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellgrandi2010ssFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellgrandi2010ssFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellgrandi2010ssFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellgrandi2010ssFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellgrandi2010ssFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "hilgemann_noble_model_1987"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhilgemann_noble_model_1987FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhilgemann_noble_model_1987FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhilgemann_noble_model_1987FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhilgemann_noble_model_1987FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhilgemann_noble_model_1987FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhilgemann_noble_model_1987FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "hodgkin_huxley_squid_axon_model_1952_modified"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "hund_rudy_2004_a"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhund_rudy_2004_aFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhund_rudy_2004_aFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhund_rudy_2004_aFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhund_rudy_2004_aFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhund_rudy_2004_aFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellhund_rudy_2004_aFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "iribe_model_2006_without_otherwise_section"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliribe_model_2006_without_otherwise_sectionFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliribe_model_2006_without_otherwise_sectionFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliribe_model_2006_without_otherwise_sectionFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliribe_model_2006_without_otherwise_sectionFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliribe_model_2006_without_otherwise_sectionFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliribe_model_2006_without_otherwise_sectionFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "iyer_model_2004"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2004FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2004FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2004FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2004FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2004FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "iyer_model_2007"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2007FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2007FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2007FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2007FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2007FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celliyer_model_2007FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "jafri_rice_winslow_model_1998"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celljafri_rice_winslow_model_1998FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celljafri_rice_winslow_model_1998FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celljafri_rice_winslow_model_1998FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celljafri_rice_winslow_model_1998FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celljafri_rice_winslow_model_1998FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celljafri_rice_winslow_model_1998FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "kurata_model_2002"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellkurata_model_2002FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellkurata_model_2002FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellkurata_model_2002FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellkurata_model_2002FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellkurata_model_2002FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellkurata_model_2002FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "livshitz_rudy_2007"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celllivshitz_rudy_2007FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celllivshitz_rudy_2007FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celllivshitz_rudy_2007FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celllivshitz_rudy_2007FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celllivshitz_rudy_2007FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Celllivshitz_rudy_2007FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "luo_rudy_1994"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellluo_rudy_1994FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellluo_rudy_1994FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellluo_rudy_1994FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellluo_rudy_1994FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellluo_rudy_1994FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellluo_rudy_1994FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "mahajan_2008"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmahajan_2008FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmahajan_2008FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmahajan_2008FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmahajan_2008FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmahajan_2008FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmahajan_2008FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "matsuoka_model_2003"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmatsuoka_model_2003FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmatsuoka_model_2003FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmatsuoka_model_2003FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmatsuoka_model_2003FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmatsuoka_model_2003FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellmatsuoka_model_2003FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "noble_model_1991"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1991FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1991FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1991FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1991FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1991FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1991FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "noble_model_1998"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1998FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1998FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1998FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1998FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1998FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_model_1998FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "noble_noble_SAN_model_1984"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_noble_SAN_model_1984FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_noble_SAN_model_1984FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_noble_SAN_model_1984FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_noble_SAN_model_1984FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_noble_SAN_model_1984FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_noble_SAN_model_1984FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "noble_SAN_model_1989"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_SAN_model_1989FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_SAN_model_1989FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_SAN_model_1989FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_SAN_model_1989FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_SAN_model_1989FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnoble_SAN_model_1989FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "nygren_atrial_model_1998"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnygren_atrial_model_1998FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnygren_atrial_model_1998FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnygren_atrial_model_1998FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnygren_atrial_model_1998FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnygren_atrial_model_1998FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellnygren_atrial_model_1998FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "pandit_model_2001_epi"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpandit_model_2001_epiFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpandit_model_2001_epiFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpandit_model_2001_epiFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpandit_model_2001_epiFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpandit_model_2001_epiFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpandit_model_2001_epiFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "priebe_beuckelmann_model_1998"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpriebe_beuckelmann_model_1998FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpriebe_beuckelmann_model_1998FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpriebe_beuckelmann_model_1998FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpriebe_beuckelmann_model_1998FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpriebe_beuckelmann_model_1998FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellpriebe_beuckelmann_model_1998FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "sakmann_model_2000_epi"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellsakmann_model_2000_epiFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellsakmann_model_2000_epiFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellsakmann_model_2000_epiFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellsakmann_model_2000_epiFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellsakmann_model_2000_epiFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellsakmann_model_2000_epiFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "Shannon2004"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new CellShannon2004FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new CellShannon2004FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new CellShannon2004FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new CellShannon2004FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new CellShannon2004FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new CellShannon2004FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "stewart_zhang_model_2008_ss"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellstewart_zhang_model_2008_ssFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellstewart_zhang_model_2008_ssFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellstewart_zhang_model_2008_ssFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellstewart_zhang_model_2008_ssFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellstewart_zhang_model_2008_ssFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellstewart_zhang_model_2008_ssFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "ten_tusscher_model_2004_endo"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_endoFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_endoFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_endoFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_endoFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_endoFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_endoFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "ten_tusscher_model_2004_epi"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_epiFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_epiFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_epiFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_epiFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_epiFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2004_epiFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "ten_tusscher_model_2006_epi"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2006_epiFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2006_epiFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2006_epiFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2006_epiFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2006_epiFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellten_tusscher_model_2006_epiFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "viswanathan_model_1999_epi"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellviswanathan_model_1999_epiFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellviswanathan_model_1999_epiFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellviswanathan_model_1999_epiFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellviswanathan_model_1999_epiFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellviswanathan_model_1999_epiFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellviswanathan_model_1999_epiFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "winslow_model_1999"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellwinslow_model_1999FromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellwinslow_model_1999FromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellwinslow_model_1999FromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellwinslow_model_1999FromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellwinslow_model_1999FromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellwinslow_model_1999FromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "zhang_SAN_model_2000_0D_capable"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_0D_capableFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_0D_capableFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_0D_capableFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_0D_capableFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_0D_capableFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_0D_capableFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else if(rModelName == "zhang_SAN_model_2000_all"){
            if (modelType =="Normal"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_allFromCellML(p_solver, p_stimulus));
            } else if (modelType =="Cvode"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_allFromCellMLCvode(p_solver, p_stimulus));
            } else if (modelType =="BE"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_allFromCellMLBackwardEuler(p_solver, p_stimulus));
            } else if (modelType =="RL"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_allFromCellMLRushLarsen(p_solver, p_stimulus));
            } else if (modelType =="GRL1"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_allFromCellMLGRL1(p_solver, p_stimulus));
            } else if (modelType =="GRL2"){
                p_cell = boost::shared_ptr<AbstractCardiacCellInterface>(new Cellzhang_SAN_model_2000_allFromCellMLGRL2(p_solver, p_stimulus));
            }
            return p_cell;
        }else{
            return NULL;
        }
    }

public:
    void RunTests(const std::string& rOutputDirName,
                  const std::vector<std::string>& rModels,
                  const std::vector<std::string>& rArgs,
                  bool testLookupTables = false,
                  double tableTestV = -1000,
                  bool warningsOk = true)
    {
        OutputFileHandler handler(rOutputDirName); // Clear folder (collective)
        PetscTools::IsolateProcesses(true); // Simple parallelism
        std::vector<std::string> failures;
        for (unsigned i = 0; i < rModels.size(); ++i)
        {
            if (PetscTools::IsParallel() && i % PetscTools::GetNumProcs() != PetscTools::GetMyRank())
            {
                continue; // Let someone else do this model
            }
            try
            {
                unsigned num_failed_asserts = CxxTest::tracker().testFailedAsserts();
                RunTest(rOutputDirName + "/" + rModels[i], rModels[i], rArgs, testLookupTables, tableTestV);
                if (CxxTest::tracker().testFailedAsserts() > num_failed_asserts)
                {
                    std::cout << "Counted a failed TS_ASSERT\n"
                              << std::flush;
                    EXCEPTION((CxxTest::tracker().testFailedAsserts() - num_failed_asserts) << " test assertion failure(s).");
                }
            }
            catch (const Exception& e)
            {
                failures.push_back(rModels[i]);
                TS_FAIL("Failure testing cell model " + rModels[i] + ": " + e.GetMessage());
            }
            if (!warningsOk)
            {
                if (rModels[i] == "demir_model_1994" || strncmp((rModels[i]).c_str(), "zhang_SAN_model_2000", strlen("zhang_SAN_model_2000")) == 0)
                {
                    // We know this model does something that provokes one warning...
                    TS_ASSERT_EQUALS(Warnings::Instance()->GetNumWarnings(), 1u);
                }
                else
                {
                    TS_ASSERT_EQUALS(Warnings::Instance()->GetNumWarnings(), 0u);
                }
            }
            Warnings::NoisyDestroy(); // Print out any warnings now, not at program exit
        }
        // Wait for all simulations to finish before printing summary of failures
        PetscTools::IsolateProcesses(false);
        PetscTools::Barrier("RunTests");

        if (!failures.empty())
        {
            std::cout << failures.size() << " models failed for " << rOutputDirName << ":" << std::endl;
            for (unsigned i = 0; i < failures.size(); ++i)
            {
                std::cout << "   " << failures[i] << std::endl;
            }
        }
    }

    void AddAllModels(std::vector<std::string>& rModels)
    {
        rModels.emplace_back("aslanidi_model_2009");
        rModels.emplace_back("beeler_reuter_model_1977");
        rModels.emplace_back("bondarenko_model_2004_apex");
        rModels.emplace_back("courtemanche_ramirez_nattel_model_1998");
        rModels.emplace_back("decker_2009");
        rModels.emplace_back("demir_model_1994");
        rModels.emplace_back("dokos_model_1996");
        rModels.emplace_back("earm_noble_model_1990");
        rModels.emplace_back("espinosa_model_1998_normal");
        rModels.emplace_back("fink_noble_giles_model_2008");
        rModels.emplace_back("grandi2010ss");
        rModels.emplace_back("hilgemann_noble_model_1987");
        rModels.emplace_back("hodgkin_huxley_squid_axon_model_1952_modified");
        rModels.emplace_back("hund_rudy_2004_a");
        rModels.emplace_back("iribe_model_2006_without_otherwise_section");
        rModels.emplace_back("iyer_model_2004");
        rModels.emplace_back("iyer_model_2007");
        rModels.emplace_back("jafri_rice_winslow_model_1998");
        rModels.emplace_back("kurata_model_2002");
        rModels.emplace_back("livshitz_rudy_2007");
        rModels.emplace_back("luo_rudy_1994");
        rModels.emplace_back("mahajan_2008");
        rModels.emplace_back("matsuoka_model_2003");
        rModels.emplace_back("noble_model_1991");
        rModels.emplace_back("noble_model_1998");
        rModels.emplace_back("noble_noble_SAN_model_1984");
        rModels.emplace_back("noble_SAN_model_1989");
        rModels.emplace_back("nygren_atrial_model_1998");
        rModels.emplace_back("pandit_model_2001_epi");
        rModels.emplace_back("priebe_beuckelmann_model_1998");
        rModels.emplace_back("sakmann_model_2000_epi");
        rModels.emplace_back("Shannon2004");
        rModels.emplace_back("stewart_zhang_model_2008_ss");
        rModels.emplace_back("ten_tusscher_model_2004_endo");
        rModels.emplace_back("ten_tusscher_model_2004_epi");
        rModels.emplace_back("ten_tusscher_model_2006_epi");
        rModels.emplace_back("viswanathan_model_1999_epi");
        rModels.emplace_back("winslow_model_1999");
        rModels.emplace_back("zhang_SAN_model_2000_0D_capable");
        rModels.emplace_back("zhang_SAN_model_2000_all");
    }

    void SetUseCvodeJacobian(bool useCvodeJacobian)
    {
        mUseCvodeJacobian = useCvodeJacobian;
    }

    void SetModelType(std::string type)
    {
        modelType = type;
    }    
};

#endif // COMPARETOPYCMLLONGHELPERCLASS_MANUAL_HPP_
