#include "defs.h"
#include <float.h>
#include <stdio.h>

#define N 4

static void set_T(number T[N][N]);
static void engin_qri(void);
static void engin_qrih(void);
static void engin_qrig(void);
static void engin_jcbi(void);
static void engin_sturm(void);

int main(void)
{
  logging_stream = stdout;
  engin_qri();
  engin_qrih();
  engin_qrig();
  engin_jcbi();
  engin_sturm();
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
  number T[N][N], e = 1e-10;
  int t0 = 60, t, i, j;

  set_T(T);
  t = qri(N, T, &e, t0);
  fprintf(stderr, "%s-%d: %lg\n", __func__, t, (double)e);
  for(i = 0; i < N; ++i)
  {
    for(j = 0; j < N; ++j)
      fprintf(stderr, "%16lg", (double)T[i][j]);
    fprintf(stderr, "\n");
  }
}

static void engin_qrih(void)
{
  number T[N][N], e = 1e-10;
  int t0 = 60, t, i, j;

  set_T(T);
  t = qrih(N, T, &e, t0);
  fprintf(stderr, "%s-%d: %lg\n", __func__, t, (double)e);
  for(i = 0; i < N; ++i)
  {
    for(j = 0; j < N; ++j)
      fprintf(stderr, "%16lg", (double)T[i][j]);
    fprintf(stderr, "\n");
  }
}

static void engin_qrig(void)
{
  number T[N][N], e = 1e-10;
  int t0 = 60, t, i, j;

  set_T(T);
  t = qrig(N, T, &e, t0);
  fprintf(stderr, "%s-%d: %lg\n", __func__, t, (double)e);
  for(i = 0; i < N; ++i)
  {
    for(j = 0; j < N; ++j)
      fprintf(stderr, "%16lg", (double)T[i][j]);
    fprintf(stderr, "\n");
  }
}

static void engin_jcbi(void)
{
  number T[N][N], e = 1e-10;
  int t0 = 60, t, i, j;

  set_T(T);
  t = jcbi(N, T, &e, t0);
  fprintf(stderr, "%s-%d: %lg\n", __func__, t, (double)e);
  for(i = 0; i < N; ++i)
  {
    for(j = 0; j < N; ++j)
      fprintf(stderr, "%16lg", (double)T[i][j]);
    fprintf(stderr, "\n");
  }
}

static void engin_sturm(void)
{
  number T[N][N];
  int t0 = 60, t[N], i, c;
  number a[N], b[N - 1], l[N], u[N], e[N];

  set_T(T);
  for(i = 0; i < N; ++i)
    a[i] = T[i][i];
  for(i = 0; i < N - 1; ++i)
    b[i] = T[i][i + 1];

  for(c = 0; c < N; ++c)
  {
    e[c] = NBR_EPSILON;
    t[c] = sgi(N, a, b, c, &l[c], &u[c], &e[c], t0);
  }

  fprintf(stderr, "%s:\n", __func__);
  for(i = 0; i < N; ++i)
    fprintf(stderr, "%4d it. %16lg  err: %lg\n",
        t[i], (double)((l[i]+u[i])/2), e[i]);
}
