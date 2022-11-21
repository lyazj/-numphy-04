#include "defs.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

static void qrig_test(void);
static int number_lt(number *a, number *b);

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
  number l0[4], l[4];

  t = qri(4, A0, &e0, 1000);
  printf("%d: %lg\n", t, e0);
  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
      printf("%16lg", (double)A0[i][j]);
    printf("\n");
  }
  printf("\n");

  t = jcbi(4, A, &e, 1000);
  printf("%d: %lg\n", t, e);
  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
      printf("%16lg", (double)A[i][j]);
    printf("\n");
  }

  for(i = 0; i < n; ++i)
    l0[i] = A0[i][i];
  qsort(l0, n, sizeof(number), (void *)number_lt);
  for(i = 0; i < n; ++i)
    l[i] = A[i][i];
  qsort(l, n, sizeof(number), (void *)number_lt);
  for(i = 0; i < n; ++i)
    assert(fabs(l[i] - l0[i]) < 1e-10);
}

int number_lt(number *a, number *b)
{
  return *a < *b;
}
