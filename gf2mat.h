#include <NTL/vector.h>
#include <NTL/matrix.h>
#include <NTL/GF2.h>
#include <NTL/vec_vec_GF2.h>
#include <NTL/mat_GF2.h>

class GF2Mat{
public:
  NTL::Mat<NTL::GF2> __rep__;
  NTL::GF2 det;
  NTL::Mat<NTL::GF2> invrep;
  int l, m;

  GF2Mat();
  GF2Mat(const NTL::Mat<NTL::GF2>& a);
  NTL::Mat<NTL::GF2> fromMatrix(int *mat, int dimy, int dimx);
  void printMatrix();
  void printMatrix(NTL::Mat<NTL::GF2> a);
  void printInv();
  int calcinv();
  NTL::Mat<NTL::GF2> getinvrep();
  
};

