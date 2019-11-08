###SImple script to get an overview of a specific attribute across cellml models in a specific folder
###Usage: run the file with python3 interpreter. Adjust the folder path and variable name in the main

import sys
from os import walk
import xml.etree.ElementTree
from collections import Counter

def get_file_list(path,extension):
    '''Returns a list of all files from path, which end in extension'''
    files = []
    for (dirpath, dirnames, filenames) in walk(path):
        for fname in filenames:
            if (fname.endswith(extension)):
                files.append(open(path+"/"+fname, 'r'))
        break
    return files

def get_attribute_values_for_variables(files, attribute_name, variable_name):
    '''Returns a dictionary containing {model_name: value} for variable_name for all models in files'''

    cyto_calcium_units_by_model = {}
    for f in files:
        found_cytosolic_calcium_concentration = False
        #root = xml.etree.ElementTree.parse(path + "/" + f).getroot()
        root = xml.etree.ElementTree.parse(f).getroot()

        for type_tag in root.findall('{http://www.cellml.org/cellml/1.0#}component/{http://www.cellml.org/cellml/1.0#}variable'):
            value = type_tag.get('{http://www.cellml.org/metadata/1.0#}id')
            if (value and value.lower() == variable_name):
                cyto_calcium_units_by_model[f] = type_tag.get(attribute_name)
                found_cytosolic_calcium_concentration = True

        if not found_cytosolic_calcium_concentration:
            cyto_calcium_units_by_model[f] = "model has no cytosolic_calcium_concentration"
    return (cyto_calcium_units_by_model)


def main(argv):
    path = "C:/Users/maurice/Desktop/cellml"
    
    files = get_file_list(path,".cellml")
    cyto_calcium_units_by_model = get_attribute_values_for_variables(files, "units","cytosolic_calcium_concentration")
    
    print ("\n---")
    print (cyto_calcium_units_by_model)
    print ("\n---")
    print (Counter(cyto_calcium_units_by_model.values()))    

if __name__ == "__main__":
    main(sys.argv)