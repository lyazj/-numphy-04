#include "defs.h"
#include <float.h>
#include <stdio.h>

#define N 4

static void set_T(number T[N][N]);
static void engin_qri(void);
static void engin_qrig(void);

int main(void)
{
  engin_qri();
  engin_qrig();
  return 0;
}

static void set_T(number T[N][N])
{
  int i, j;
  const number T0[N][N] = {
    { 1, -1,  0,  0,},
    {-1,  2, -1,  0,},
    { 0, -1,  3, -1,},
    { 0,  0, -1,  4,},
  };
  for(i = 0; i < N; ++i)
    for(j = 0; j < N; ++j)
      T[i][j] = T0[i][j];
}

static void engin_qri(void)
{
  number T[N][N], e = NBR_EPSILON;
  int t0 = 1000, t, i, j;

  set_T(T);
  t = qri(N, T, &e, t0);
  printf("%d\n", t);
  for(i = 0; i < N; ++i)
  {
    for(j = 0; j < N; ++j)
      printf("%16lg", T[i][j]);
    printf("\n");
  }
}

static void engin_qrig(void)
{
  number T[N][N], e = NBR_EPSILON;
  int t0 = 1000, t, i, j;

  set_T(T);
  t = qrig(N, T, &e, t0);
  printf("%d\n", t);
  for(i = 0; i < N; ++i)
  {
    for(j = 0; j < N; ++j)
      printf("%16lg", T[i][j]);
    printf("\n");
  }
}
