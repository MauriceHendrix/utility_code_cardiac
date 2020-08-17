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

config = Config()
config.trace_filter = GlobbingFilter(include=['__main__', 'nottingham_covid_modelling.*'])

graphviz = GraphvizOutput()
graphviz.output_file = '/home/uczmh2/optimise_model.png'

testargs = ["run_optimise", "--limit_pints_iterations", "10"]
    
with PyCallGraph(output=graphviz, config=config):
    with mock.patch.object(sys, 'argv', testargs):
        run_optimise()
