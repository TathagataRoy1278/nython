import time
import cppyy
from array import array#For passing to cppyy, as cppyy does not take numpy array as argument
import random
import numpy as np

cppyy.include("./gf2mat.h")#for Mat<GF2> class wrapper
cppyy.include("./rref.h")#for rref definitions
cppyy.include("/usr/local/include/NTL/GF2.h")
cppyy.load_library("/usr/local/lib/libntl.so")#for loading ntl libraries
cppyy.load_library("./gf2mat.so")#for declaration of GF2Mat
cppyy.load_library("./rref.so")#for declaration of to_reduced_row_echelon_form

#all the "start" and "end" variables are functionally useless and are only used as a time metric

start = time.time()
a, b  = (5, 10)
arr = np.array(np.random.choice([False, True], size=(a, b))).reshape(-1)
end = time.time()
print(f"%ds to generate matrix"%(end-start))

start = time.time()
ar = array('i', arr)#The numpy array must be converted to the array module before being passed into cppyy
obj = cppyy.gbl.GF2Mat()#This is used to wrap ar into an object that uses NTL to internally represent the matrix
rep = obj.fromMatrix(ar, a, b)#This is the function that does the above comment but returns a pure NTL Object which is passed in to the rrefing function
end = time.time()
print(f"%ds to buffer matrix to C++ datatype"%(end-start))

start = time.time()
cppyy.gbl.to_reduced_row_echelon_form(rep)#calls RREF on the NTL object and modifies it by reference
end = time.time()
print(f"%ds to calculate rref"%(end-start))

obj.printMatrix(rep)
l = rep[2][3]._ref_GF2__ptr
l = cppyy.bind_object(l, cppyy.gbl.NTL.GF2)
l._GF2__rep

#print(cppyy.gbl.check_rref(rep))
