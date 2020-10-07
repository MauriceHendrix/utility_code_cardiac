import os
import sys
import warnings
from unittest import mock

import matplotlib
import numpy as np
import pytest
from nottingham_covid_modelling import MODULE_DIR
from nottingham_covid_modelling.optimise_model import run_optimise

from pycallgraph2 import PyCallGraph
from pycallgraph2.output import GraphvizOutput
from pycallgraph2 import Config
from pycallgraph2 import GlobbingFilter


#config.trace_filter = GlobbingFilter(include=['__main__', 'nottingham_covid_modelling.*', 'pints'])
#config.trace_filter = GlobbingFilter(exclude=['argparse', 'argparse.*' 'nottingham_covid_modelling.lib.data', 'nottingham_covid_modelling.lib.data.*', 'unittest', 'unittest.*', 'codecs', 'codecs.*', 'amax', 'argsort', '_bootlocale', 'all', 'logging', 'logging.*', '--new--', '-handle_fromlist', 'warnings', 'warnings.*', 'posixpath', 'posixpath.*', 'os', 'os.*', 'genericpath', 'genericpath.*', 'locle', 'locale.*'])

graphviz = GraphvizOutput()
graphviz.output_file = '/home/uczmh2/optimise_model.png'

testargs = ["run_optimise", "--limit_pints_iterations", "10"]


config = Config(max_depth=5)
config.trace_filter = GlobbingFilter(exclude=['pycallgraph.*', 'argparse', 'argparse.*', 'unittest', 'unittest.*', 'logging', 'logging.*', '--new--', 'nottingham_covid_modelling.data.*', 'nottingham_covid_modelling.data.DataLoader', 'nottingham_covid_modelling.data.DataLoader.*'])
with PyCallGraph(output=graphviz, config=config):
    with mock.patch.object(sys, 'argv', testargs):
        run_optimise()

