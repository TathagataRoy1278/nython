 #include "rref.h"

// convert A to reduced row echelon form
void to_reduced_row_echelon_form(NTL::Mat<NTL::GF2>& A)
{
  int lead = 0;//minimum row index is 0

  for (int row = lead;
       row <= A.NumRows()-1;
       ++row)
  {
    if (lead > A.NumCols() - 1)
      return;
    int i = row;
    while (A[i][lead] == 0)
    {
      ++i;
      if (i > (A.NumRows() - 1))
      {
        i = row;
        ++lead;
        if (lead > A.NumCols() -1)
          return;
      }
    }
    
    swap(A[i], A[row]);
    for (i = 0; i <= A.NumRows() - 1; ++i)
    {
      if (i != row)
	{
	  NTL::GF2 coeff = -A[i][lead];
	  A[i] = A[i] + coeff*A[row];
	}
    }
  }
}

int check_rref(NTL::Mat<NTL::GF2>& A)
{
  int f = 0;
  int in = -1;
  for(int i = 0;i<A.NumRows();i++)
    {
      for(int j = 0;j < A.NumCols(); j++)
	{
	  if (rep(A[i][j]))
	    {
	      f = 0;
	      if (j<=in)
		return 0;
	      in = j;
	      for(int k = 0;k<A.NumRows();k++)
		if(rep(A[k][j]))
		  if(f)
		    return 0;
	          else
		    f = 1;
	      break;
	    }
	}
    }
  return 1;
}
