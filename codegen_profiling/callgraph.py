import logging
import os

import cellmlmanip
import pytest
import sympy as sp
from cellmlmanip.rdf import create_rdf_node

import chaste_codegen as cg
import chaste_codegen.tests.chaste_test_utils as test_utils

from pycallgraph2 import PyCallGraph
from pycallgraph2.output import GraphvizOutput

graphviz = GraphvizOutput()
graphviz.output_file = 'C:/Users/uczmh2/Desktop/venv_weblab/chaste-codegen/codegen.png'
    
model_file = os.path.join(cg.DATA_DIR, 'tests', 'cellml', 'Shannon2004.cellml')
model = cellmlmanip.load_model(model_file)
with PyCallGraph(output=graphviz):
    cg.ChasteModel(model, 'Shannon2004', class_name='CellShannon2004FromCellML')