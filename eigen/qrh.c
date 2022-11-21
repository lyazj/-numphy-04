#include "defs.h"
#include <math.h>

// Do QR decomposition, with Householder transformation.
int qrh(int n, number A[n][n], number Q[n][n], number R[n][n])
{
  int i, j, k;
  number r, r0;

  // Q := I
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      Q[i][j] = i == j;

  // R := A
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      R[i][j] = A[i][j];

  for(j = 0; j < n - 1; ++j)
  {
    // r := norm2(R[j:,j])
    // R[j,j] -= r
    // r0 := norm2(R[j:,j])
    // R[j:,j] := R[j:,j] / r0
    r = 0;
    for(i = j + 1; i < n; ++i)
      r += R[i][j] * R[i][j];
    r0 = r;
    r += R[j][j] * R[j][j];
    r = sqrt(r);
    R[j][j] -= r;
    r0 += R[j][j] * R[j][j];
    if((r0 = sqrt(r0)) == 0)
      return j;
    for(i = j; i < n; ++i)
      R[i][j] = R[i][j] / r0;

    // R[j:,k] -= 2 * R[j:,k] @ R[j:,j] * R[j:,j]
    for(k = j + 1; k < n; ++k)
    {
      r0 = 0;
      for(i = j; i < n; ++i)
        r0 += R[i][k] * R[i][j];
      for(i = j; i < n; ++i)
        R[i][k] -= 2 * r0 * R[i][j];
    }

    // Q[k,j:] -= 2 * Q[k,j:] @ R[j:,j] * R[j:,j]
    for(k = 0; k < n; ++k)
    {
      r0 = 0;
      for(i = j; i < n; ++i)
        r0 += Q[k][i] * R[i][j];
      for(i = j; i < n; ++i)
        Q[k][i] -= 2 * r0 * R[i][j];
    }

    // R[j,j] := r
    // R[j+1:,j] := 0
    R[j][j] = r;
    for(i = j + 1; i < n; ++i)
      R[i][j] = 0;
  }
  return n;
}
