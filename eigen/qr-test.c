#include "defs.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

static void qr_test_2(void);
static void qr_test_3(void);
static void qr_test_100(void);

int main(void)
{
  qr_test_2();
  printf("\n");
  qr_test_3();
  qr_test_100();
  return 0;
}

void qr_test_2(void)
{
  int n = 2, i, j, k;
  number A[2][2] = {
    {1, 2},
    {2, 1},
  };
  number Q[2][2], R[2][2];
  number r;

  qr(n, A, Q, R);

  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
      printf("%16lg", (double)Q[i][j]);
    printf("\n");
  }
  printf("\n");
  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
      printf("%16lg", (double)R[i][j]);
    printf("\n");
  }

  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
    {
      r = 0;
      for(k = 0; k < n; ++k)
        r += Q[i][k] * Q[j][k];
      assert(fabs(r - (i == j)) < 1e-10);
    }
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
    {
      r = 0;
      for(k = 0; k < n; ++k)
        r += Q[i][k] * R[k][j];
      assert(fabs(r - A[i][j]) < 1e-10);
    }
}

void qr_test_3(void)
{
  int n = 3, i, j, k;
  number A[3][3] = {
    {1, 2, 3},
    {2, 4, 5},
    {3, 5, 6},
  };
  number Q[3][3], R[3][3];
  number r;

  qr(n, A, Q, R);

  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
      printf("%16lg", (double)Q[i][j]);
    printf("\n");
  }
  printf("\n");
  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
      printf("%16lg", (double)R[i][j]);
    printf("\n");
  }

  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
    {
      r = 0;
      for(k = 0; k < n; ++k)
        r += Q[i][k] * Q[j][k];
      assert(fabs(r - (i == j)) < 1e-10);
    }
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
    {
      r = 0;
      for(k = 0; k < n; ++k)
        r += Q[i][k] * R[k][j];
      assert(fabs(r - A[i][j]) < 1e-10);
    }
}

void qr_test_100(void)
{
  int n = 100, i, j, k;
  number A[100][100];
  number Q[100][100], R[100][100];
  number r;

again:
  srand(time(0));
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      A[i][j] = rand() % 4;
  if(qr(n, A, Q, R) != n)
    goto again;

  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
    {
      r = 0;
      for(k = 0; k < n; ++k)
        r += Q[i][k] * Q[j][k];
      assert(fabs(r - (i == j)) < 1e-10);
    }
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
    {
      r = 0;
      for(k = 0; k < n; ++k)
        r += Q[i][k] * R[k][j];
      assert(fabs(r - A[i][j]) < 1e-10);
    }
}
