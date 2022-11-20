#include "defs.h"
#include <float.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>

static void gd_test(void);

int main(void)
{
  gd_logging = stderr;
  gd_test();
  return 0;
}

void gd_test(void)
{
  number A[2][2] = {
    {2, 1},
    {1, 2},
  };
  number b[2] = {8, 7};
  number x_star[2] = {3, 2};
  number x[2] = {1e10, -1e10};
  int i;

  gd(2, A, b, x, DBL_EPSILON);
  for(i = 0; i < 2; ++i)
    printf("%lg\n", (double)x[i]);
  for(i = 0; i < 2; ++i)
    assert(fabs(x[i] - x_star[i]) < 1e-10);
}
