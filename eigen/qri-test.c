#include "defs.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>

static void qri_test_2(void);

int main(void)
{
  qri_test_2();
  return 0;
}

void qri_test_2(void)
{
  int n = 2, i, j, t;
  number A[2][2] = {
    {1, 2},
    {2, 1},
  };
  number e = DBL_EPSILON;

  t = qri(n, A, &e, 100);
  printf("%d: %lg\n\n", t, (double)e);
  assert(e < DBL_EPSILON);
  assert(t < 100);

  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
      printf("%16lg", (double)A[i][j]);
    printf("\n");
  }
  assert(fabs(A[0][0] - 3) < 1e-10);
  assert(fabs(A[1][1] + 1) < 1e-10);
}
