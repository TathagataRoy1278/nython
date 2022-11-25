import cppyy
from array import array
cppyy.include("./gf2mat.h")
cppyy.load_library("/usr/local/lib/libntl.so")
cppyy.include("/usr/local/include/NTL/GF2.h")
cppyy.load_library("./gf2mat.so")
obj = cppyy.gbl.NTL.GF2(45)

print(obj._GF2__rep)
