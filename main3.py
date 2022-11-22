import cppyy
from array import array
import random
import numpy as np

cppyy.include("./gf2mat.h")
cppyy.include("./rref.h")
cppyy.load_library("/usr/local/lib/libntl.so")
cppyy.load_library("./gf2mat.so")
cppyy.load_library("./rref.so")

a, b  = (17000, 10000)
arr = np.array(np.random.choice([False, True], size=(a, b))).reshape(-1)



obj = cppyy.gbl.GF2Mat()
rep = obj.fromMatrix(ar, a, b)

cppyy.gbl.to_reduced_row_echelon_form(rep)
print(cppyy.gbl.check_rref(rep))
