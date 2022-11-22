#include "rref.h"
#include "gf2mat.h"

int main()
{
  NTL::Mat<NTL::GF2> a;
  a.SetDims(4, 4);
  a[0][0] = 1;
  a[0][1] = 0;
  a[0][2] = 0;
  a[0][3] = 1;
  a[1][0] = 1;
  a[1][1] = 1;
  a[1][2] = 1;
  a[1][3] = 0;
  a[2][0] = 0;
  a[2][1] = 0;
  a[2][2] = 1;
  a[2][3] = 1;
  a[3][0] = 0;
  a[3][1] = 0;
  a[3][2] = 0;
  a[3][3] = 1;
  GF2Mat().printMatrix(a);
  printf("%d, \n", check_rref(a));
}
