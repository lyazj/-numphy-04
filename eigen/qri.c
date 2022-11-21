#include "defs.h"
#include <math.h>

int qri(int n, number A[n][n], number *e, int m)
{
  int i, j, k, t;
  number Q[n][n], R[n][n], e0 = *e, r = e0;

  for(t = 0; t < m && r >= e0; ++t)
  {
    if(qr(n, A, Q, R) != n)
      break;
    // A = R @ Q
    r = 0;
    for(i = 0; i < n; ++i)
    {
      for(j = 0; j < n; ++j)
        A[i][j] = 0;
      for(k = 0; k < n; ++k)
        for(j = 0; j < n; ++j)
          A[i][j] += R[i][k] * Q[k][j];
      for(j = 0; j < n; ++j)
        r = i == j ? r : r + fabs(A[i][j]);
    }
    if((t + 1) % 5 == 0)
    {
      logging("%s-%d:\n", __func__, t + 1);
      for(i = 0; i < n; ++i)
      {
        for(j = 0; j < n; ++j)
          logging("%+25.13la", (double)A[i][j]);
        logging("\n");
      }
    }
  }
  *e = r;
  return t;
}
