import numpy as np
from array import array
import cppyy

cppyy.include("/usr/local/include/NTL/matrix.h")
cppyy.include("/usr/local/include/NTL/mat_GF2.h")
cppyy.include("./gf2mat.h")
cppyy.load_library("/usr/local/lib/libntl.so")
cppyy.load_library("./gf2mat.so")

ntl = cppyy.gbl.NTL
typelookup = {
    'i':'i',#integer
    'b':'b',#boolean/signed char
    'u':'B', #unsigned char
    'f':'d',#float -> double
}

class Binmat:
    def __init__(self, arr, typ, flattened=False):
        #Todo add checks for square matrix
        l = len(arr)
        m = len(arr[0])
        if not flattened:
            arr = (np.array(arr, dtype = typ).flatten())
            arr = list(arr)

        
        arr = array(typelookup[typ], arr)
        self.repwrap = cppyy.gbl.GF2Mat()
        self.rep = self.repwrap.fromMatrix(arr, l, m)

    def printmatrix(self, inv=False):
        if inv:
            self.repwrap.printInv()
            return
        self.repwrap.printMatrix()

    def inv(self):
        ret = self.repwrap.calcinv()
        if ret == -1:
            raise Exception("Singular Matrix has undefined Inverse.")

        inv = self.repwrap.getinvrep()

    def __mul__(b : Binmat)
