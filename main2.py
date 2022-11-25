import cppyy
from array import array
import random

cppyy.include("NTL/ZZ.h")
cppyy.load_library("/usr/local/lib/libntl.so")


int1 = cppyy.gbl.NTL.ZZ(67)
e = 1000000000
int3 = cppyy.gbl.NTL.ZZ()

cppyy.gbl.NTL.power(int3, int1, e)
