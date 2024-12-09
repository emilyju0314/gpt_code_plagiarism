import clang.cindex
from clang.cindex import Index 
from clang.cindex import Config  
from clang.cindex import CursorKind  
from clang.cindex import TypeKind
from collections import defaultdict
import csv
import lizard
import numpy as np
import subprocess
import os
from os import walk
import difflib
#libclangPath = '/usr/lib/llvm-14/lib/libclang.so'
#Config.set_library_file(libclangPath)
#index = Index.create()

def style_guideline(filename):
    path = os.getcwd()+"/compare.cpp"
    command = f"/usr/bin/clang-format --style='{{Language: Cpp,BasedOnStyle: Google,IndentWidth: 4,TabWidth: 4,IndentAccessModifiers: false,AllowShortIfStatementsOnASingleLine: false,AllowShortLoopsOnASingleLine: false}}' {filename} > {path}"
    subprocess.run(command,shell=True)
    
    with open(filename,'r',encoding="big5",errors="ignore") as file1, open(path,'r',encoding="big5",errors="ignore") as file2:
        origin = file1.readlines()
        modify = file2.readlines()
        result = list(difflib.Differ().compare(origin,modify))
        modify_number = 0
        for r in result:
            if r.startswith('?'):
                modify_number += r.count('-')+r.count('+')+r.count('^')
    if sum(len(i) for i in origin) == 0 :
        return 0.0
    return modify_number/sum(len(i) for i in origin)
    
def cyclomatic_complexity(filename):
    analysis_result = lizard.analyze_file(filename)
    total_complexity = sum(function.cyclomatic_complexity for function in analysis_result.function_list) 
  
    return total_complexity
    
def duplicate_pattern(filename):
    path = os.getcwd()+"/compare.csv"
    command = f"$HOME/pmd-bin-7.3.0/bin/pmd cpd --minimum-tokens 10 --dir {filename} --format csv --language cpp --no-fail-on-error > {path}"
    subprocess.run(command,shell=True)
    duplicate = 0
    with open(path,newline="") as result_file: 
        result_file.readline()
        result = result_file.readlines()
        for r in result:
            r = r.split(',')
            duplicate += int(r[0])*(int(r[2])-1)
   
    return duplicate
    
    
def find_inden(filename):
    translation_unit = Index.create().parse(filename)
    inden = []
    mapping = defaultdict(list)
    def location(cursor):
        for cur in cursor.get_children():
            if cur.location.file and cur.location.file.name == filename:
                #print(cur.kind.name)
                #print(cur.spelling)
                #print(cur.location.line,cur.location.column)
                mapping[cur.location.line].append(cur.location.column-1)
                inden.append(cur.location.column-1)
                #if cur.location.line not in inden:
                 #   inden[cur.location.line] = cur.location.column
                #else:
                 #   inden[cur.location.line] = min(cur.location.column,inden[cur.location.line])
                location(cur)
   
    #location(translation_unit.cursor)
    cursor = translation_unit.cursor
    
    for token in cursor.get_tokens():
        if token.location.column-1 not in mapping[token.location.line]:
            mapping[token.location.line].append(token.location.column-1)
            if token.location.column-1 == min(mapping[token.location.line]):
                inden.append(token.location.column-1)
    #print(inden)
    mad = np.median([np.abs(i - np.median(inden)) for i in inden])
    return mad
    


'''
dataset = os.getcwd()+"/tt"
resultfile = open(os.getcwd()+"/result.csv",'w',encoding="big5")
writer = csv.writer(resultfile)
writer.writerow(["filename","guideline","indentation","repeat","cycle"])
for root, dirs, files in walk(dataset):
    for file in files:
        ff = os.path.join(root,file)
        row = [file]
        row.append( style_guideline(ff) )       
        row.append( find_inden(ff) )
        row.append( duplicate_pattern(ff) )
        row.append( cyclomatic_complexity(ff) )
        print(row)
        writer.writerow(row)
'''




