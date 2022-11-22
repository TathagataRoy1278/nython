#include <NTL/vector.h>
#include <NTL/matrix.h>
#include <NTL/GF2.h>
#include <NTL/vec_vec_GF2.h>

// convert A to reduced row echelon form
int check_rref(NTL::Mat<NTL::GF2>& A);
void to_reduced_row_echelon_form(NTL::Mat<NTL::GF2>& A);
