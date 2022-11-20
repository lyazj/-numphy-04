#include "defs.h"
#include <stdio.h>
#include <float.h>

int main(void)
{
  int i;

  gd_logging = stdout;
  number A[4][4] = {
    {.05, .07, .06, .05},
    {.07, .10, .08, .07},
    {.06, .08, .10, .09},
    {.05, .07, .09, .10},
  }, b[4] = {.23, .32, .33, .31}, x[4] = { };

  gd(4, A, b, x, DBL_EPSILON);

  for(i = 0; i < 4; ++i)
    fprintf(stderr, "%.18lf  %.13la\n", (double)x[i], (double)x[i]);
}
