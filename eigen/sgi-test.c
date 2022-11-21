#include "defs.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>

static void sgi_test_2(void);

int main(void)
{
  sgi_test_2();
  return 0;
}

void sgi_test_2(void)
{
  int n = 2, c, t;
  number a[2] = {1, 1};
  number b[1] = {2};
  number v[2] = {-1, 3};
  number l[2];
  number u[2];
  number e[2];

  for(c = 0; c < n; ++c)
  {
    e[c] = DBL_EPSILON;
    t = sgi(n, a, b, c, &l[c], &u[c], &e[c], 100);
    printf("eigenvalue %d: %lg ([%lg, %lg])  err: %lg\n", c,
        (double)((l[c] + u[c]) / 2), (double)l[c], (double)u[c],
        (double)((l[c] + u[c]) / 2 - v[c]));
    printf("%d: %lg\n", t, (double)v[c]);
    assert(e[c] < 1e-15);
  }
  for(c = 0; c < n; ++c)
    assert(fabs((l[c] + u[c]) / 2 - v[c]) < 1e-15);
}
