#include "defs.h"
#include <math.h>

// Do Jacobi iteration with Givens transformation.
int jcbi(int n, number A[n][n], number *e, int m)
{
  int i, j, k, t0;
  number eta, t, c, s, x, y, e0 = *e, r = e0;

  for(t0 = 0; t0 < m && r >= e0; ++t0)
  {
    for(i = 0; i < n; ++i)
      for(j = 0; j < n; ++j)
        if(i != j)
        {
          eta = (A[j][j] - A[i][i]) / (A[i][j] + A[j][i]);
          t = eta >= 0
            ? +1.0 / (+eta + hypot(1, eta))
            : -1.0 / (-eta + hypot(1, eta));
          c = 1 / hypot(1, t);
          s = c * t;
          for(k = 0; k < n; ++k)
          {
            x = c * A[i][k] - s * A[j][k];
            y = s * A[i][k] + c * A[j][k];
            A[i][k] = x;
            A[j][k] = y;
          }
          for(k = 0; k < n; ++k)
          {
            x = c * A[k][i] - s * A[k][j];
            y = s * A[k][i] + c * A[k][j];
            A[k][i] = x;
            A[k][j] = y;
          }
        }
    r = 0;
    for(i = 0; i < n; ++i)
      for(j = 0; j < n; ++j)
        if(i != j)
          r += fabs(A[i][j]);
    if((t0 + 1) % 5 == 0)
    {
      logging("%s-%d:\n", __func__, t0 + 1);
      for(i = 0; i < n; ++i)
      {
        for(j = 0; j < n; ++j)
          logging("%16lg", A[i][j]);
        logging("\n");
      }
    }
  }
  *e = r;
  return t0;
}
