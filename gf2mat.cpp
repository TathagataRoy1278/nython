#include "gf2mat.h"

GF2Mat::GF2Mat(){//basic constructor
  __rep__ = NTL::Mat<NTL::GF2>();//init to 0
  det = NTL::GF2();//init to 0
  invrep = NTL::Mat<NTL::GF2>();//declares inverse
}

GF2Mat::GF2Mat(const NTL::Mat<NTL::GF2>& a){//param constructor
  __rep__ = a;//same as above, just copies the reference
  det = NTL::GF2();//same as above
  invrep = NTL::Mat<NTL::GF2>();//same as above
}


NTL::Mat<NTL::GF2> GF2Mat::fromMatrix(int *mat, int dimy, int dimx)//inputs a flattened matrix and its dimensions
  {
    l = dimy;
    m = dimx;
    __rep__.SetDims(l, m);
    for(int i = 0; i < dimy; ++i)
    {
        for(int j = 0; j < dimx; ++j)
        {
            int nIndexJ = i * dimx + j;
            // operate on array
            __rep__.put(i, j, mat[nIndexJ]);//populates the matrix
        }
    }
    return __rep__;
  }

void GF2Mat::printMatrix()
{
  for(int i = 0;i < l;i++)
    {
      for(int j = 0; j < m; j++)
	printf("%ld, ", rep(__rep__[i][j]));
      printf("\n");
    }
  
}

void GF2Mat::printMatrix(NTL::Mat<NTL::GF2> a)
{
  for(int i = 0;i < a.NumRows();i++)
    {
      for(int j = 0; j < a.NumCols(); j++)
	printf("%ld, ", rep(a[i][j]));
      printf("\n");
    }
  
}


void GF2Mat::printInv()
{
  for(int i = 0;i < l;i++)
    {
      for(int j = 0; j < m; j++)
	printf("%ld, ", rep(invrep[i][j]));
      printf("\n");
    }
  
}


int GF2Mat::calcinv()
{
  if (rep(det) == 0)
    determinant(det, __rep__);
  
  if (det == 0)
    return -1;//returns an error value if singular matrix
  
  inv(det, invrep, __rep__);
  return 1;
}

NTL::Mat<NTL::GF2> GF2Mat::getinvrep()
{
  return invrep;//debug function
}

void GF2Mat::test()
{
  int i = 2;
  int j = 8;
  int b_list[3];
  b_list[2] = 12;
  __rep__[2][8] = NTL::GF2(b_list[2]);
  
}
