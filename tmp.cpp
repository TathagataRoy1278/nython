#include "gf2mat.h"

int main()
{
  int *a;
  a = (int*)malloc(sizeof(int) * 4);
  a[0] = 1;
  a[1] = 0;
  a[2] = 1;
  a[3] = 1;
  GF2Mat(a, 1, 4);
}
