import cppyy
from array import array
cppyy.include("./gf2mat.h")
cppyy.load_library("/usr/local/lib/libntl.so")
cppyy.load_library("./gf2mat.so")
obj = cppyy.gbl.GF2Mat()
obj.fromMatrix(array('i', [1, 2, 1, 1]),2, 2)
obj.calcinv()
