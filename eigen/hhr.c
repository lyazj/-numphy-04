#include "defs.h"
#include <math.h>

// Do Hessenberg-Householder reduction.
int hhr(int n, number A[n][n])
{
  int i, j, k;
  number r, r0;

  for(j = 0; j < n - 2; ++j)
  {
    // r:= norm2(A[j+1:,j])
    // A[j+1,j] -= r
    // r0:= norm2(A[j+1:,j])
    // A[j+1:,j] /= r0
    r = 0;
    for(i = j + 2; i < n; ++i)
      r += A[i][j] * A[i][j];
    r0 = r;
    r += A[j + 1][j] * A[j + 1][j];
    r = sqrt(r);
    A[j + 1][j] -= r;
    r0 += A[j + 1][j] * A[j + 1][j];
    if((r0 = sqrt(r0)) == 0)
      return j;
    for(i = j + 1; i < n; ++i)
      A[i][j] /= r0;

    // A[:,k] -= 2 * A[:,k] @ A[:,j] * A[:,j]
    for(k = j + 1; k < n; ++k)
    {
      r0 = 0;
      for(i = j + 1; i < n; ++i)
        r0 += A[i][k] * A[i][j];
      for(i = j + 1; i < n; ++i)
        A[i][k] -= 2 * r0 * A[i][j];
    }

    // A[k,:] -= 2 * A[k,:] @ A[:,j] * A[:,j]
    for(k = 0; k < n; ++k)
    {
      r0 = 0;
      for(i = j + 1; i < n; ++i)
        r0 += A[k][i] * A[i][j];
      for(i = j + 1; i < n; ++i)
        A[k][i] -= 2 * r0 * A[i][j];
    }

    A[j + 1][j] = r;
    for(i = j + 2; i < n; ++i)
      A[i][j] = 0;
  }
  return n;
}
