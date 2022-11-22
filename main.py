import cppyy

cppyy.include("NTL/matrix.h")
cppyy.include("NTL/GF2.h")
cppyy.load_library("/usr/local/lib/libntl.so")
from cppyy.gbl import std, NTL

print(NTL.ZZ(2909878))
