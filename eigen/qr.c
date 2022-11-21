#include "defs.h"
#include <math.h>

// Do QR decomposition, with optimized spatial locality.
int qr(int n, number A[n][n], number Q[n][n], number R[n][n])
{
  int i, j, k;
  number r, r0;

  for(j = 0; j < n; ++j)
  {
    // compute Q[:,j]:
    //   R[k,j] == Q[:,k] @ A[:,j]
    //   Q[:,j] := A[:,j] - Q[:,k] * R[k,j]
    //   then normalize Q[:,j]
    r = 0;
    for(i = 0; i < n; ++i)
    {
      r0 = A[i][j];
      for(k = 0; k < j; ++k)
        r0 -= Q[i][k] * R[k][j];
      Q[i][j] = r0;
      r += r0 * r0;
    }
    if((r = sqrt(r)) == 0)
      return j;
    for(i = 0; i < n; ++i)
      Q[i][j] /= r;

    // compute R[j,:]:
    //   R[j,k] := Q[:,j] @ A[:,k]
    for(k = 0; k < n; ++k)
      R[j][k] = 0;
    for(i = 0; i < n; ++i)
      for(k = j; k < n; ++k)
        R[j][k] += Q[i][j] * A[i][k];
  }
  return n;
}
