#include "zzmat.h"

ZZMat::ZZMat(){//basic constructor
  __rep__ = NTL::Mat<NTL::ZZ>();//init to 0
  det = NTL::ZZ();//init to 0
  invrep = NTL::Mat<NTL::ZZ>();//declares inverse
}

ZZMat::ZZMat(const NTL::Mat<NTL::ZZ>& a){//param constructor
  __rep__ = a;//same as above, just copies the reference
  det = NTL::ZZ();//same as above
  invrep = NTL::Mat<NTL::ZZ>();//same as above
}


NTL::Mat<NTL::ZZ> ZZMat::fromMatrix(int *mat, int dimy, int dimx)//inputs a flattened matrix and its dimensions
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

void ZZMat::printMatrix()
{
  for(int i = 0;i < l;i++)
    {
      for(int j = 0; j < m; j++)
	printf("%ld, ", __rep__[i][j]);
      printf("\n");
    }
  
}

void ZZMat::printMatrix(NTL::Mat<NTL::ZZ> a)
{
  for(int i = 0;i < a.NumRows();i++)
    {
      for(int j = 0; j < a.NumCols(); j++)
	printf("%ld, ", a[i][j]);
      printf("\n");
    }
  
}


void ZZMat::printInv()
{
  for(int i = 0;i < l;i++)
    {
      for(int j = 0; j < m; j++)
	printf("%ld, ", invrep[i][j]);
      printf("\n");
    }
  
}


int ZZMat::calcinv()
{
  if ((det) == 0)
    determinant(det, __rep__);
  
  if (det == 0)
    return -1;//returns an error value if singular matrix
  
  inv(det, invrep, __rep__);
  return 1;
}

NTL::Mat<NTL::ZZ> ZZMat::getinvrep()
{
  return invrep;//debug function
}

