#include "defs.h"
#include <math.h>

// Do QR iteration with Givens transformation.
int qrig(int n, number A[n][n], number *e, int m)
{
  int i, j, k, t;
  number c[n], s[n], x, y, e0 = *e, r = e0;

  for(t = 0; t < m && r >= e0; ++t)
  {
    // victim: A[j + 1][j]
    for(j = 0; j < n - 1; ++j)
    {
      r = sqrt(A[j][j] * A[j][j] + A[j + 1][j] * A[j + 1][j]);
      c[j] = A[j][j] / r;
      s[j] = A[j + 1][j] / r;
      // for(k = 0; k < n; ++k)
      for(k = j; k < n; ++k)
      {
        x =  c[j] * A[j][k] + s[j] * A[j + 1][k];
        y = -s[j] * A[j][k] + c[j] * A[j + 1][k];
        A[j][k] = x;
        A[j + 1][k] = y;
      }
    }
    r = 0;
    for(j = 0; j < n - 1; ++j)
    {
      // for(i = 0; i < n; ++i)
      for(i = 0; i <= j + 1; ++i)
      {
        x =  c[j] * A[i][j] + s[j] * A[i][j + 1];
        y = -s[j] * A[i][j] + c[j] * A[i][j + 1];
        A[i][j] = x;
        A[i][j + 1] = y;
        if(i != j)
          r += fabs(x);
      }
    }
    for(i = 0; i < j; ++i)
      r += fabs(A[i][j]);
    if((t + 1) % 5 == 0)
    {
      logging("%s-%d:\n", __func__, t + 1);
      for(i = 0; i < n; ++i)
      {
        for(j = 0; j < n; ++j)
          logging("%16lg", A[i][j]);
        logging("\n");
      }
    }
  }
  *e = r;
  return t;
}
