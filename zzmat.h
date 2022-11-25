#include <NTL/vector.h>
#include <NTL/matrix.h>
#include <NTL/ZZ.h>
#include <NTL/vec_vec_ZZ.h>
#include <NTL/mat_ZZ.h>

class ZZMat{
public:
  NTL::Mat<NTL::ZZ> __rep__;
  NTL::ZZ det;
  NTL::Mat<NTL::ZZ> invrep;
  int l, m;

  ZZMat();
  ZZMat(const NTL::Mat<NTL::ZZ>& a);
  NTL::Mat<NTL::ZZ> fromMatrix(int *mat, int dimy, int dimx);
  void printMatrix();
  void printMatrix(NTL::Mat<NTL::ZZ> a);
  void printInv();
  int calcinv();
  NTL::Mat<NTL::ZZ> getinvrep();
  
};

