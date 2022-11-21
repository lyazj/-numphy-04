#include "defs.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>

static void qrig_test(void);

int main(void)
{
  qrig_test();
  return 0;
}

void qrig_test(void)
{
  int n = 4, i, j, t;
  number A0[4][4] = {
    { 4,  1, -2,  2},
    { 1,  2,  0,  1},
    {-2,  0,  3, -2},
    { 2,  1, -2, -1},
  };
  number A[4][4] = {
    { 4,  1, -2,  2},
    { 1,  2,  0,  1},
    {-2,  0,  3, -2},
    { 2,  1, -2, -1},
  };
  number e0 = DBL_EPSILON, e = DBL_EPSILON;

  hhr(4, A);

  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
      printf("%16lg", (double)A[i][j]);
    printf("\n");
  }
  printf("\n");
  t = qri(4, A0, &e0, 1000);
  printf("%d: %lg\n", t, e0);
  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
      printf("%16lg", (double)A0[i][j]);
    printf("\n");
  }
  printf("\n");

  t = qrig(4, A, &e, 1000);
  printf("%d: %lg\n", t, e);
  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
      printf("%16lg", (double)A[i][j]);
    printf("\n");
  }

  for(i = 0; i < n; ++i)
    assert(fabs(A[i][i] - A0[i][i]) < 1e-10);
}
