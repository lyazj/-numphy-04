#include "defs.h"
#include <math.h>
#include <stdio.h>
#include <stdarg.h>

void *gd_logging;

static int logging(const char *fmt, ...)
{
  FILE *stream = (FILE *)gd_logging;
  va_list vl;
  int r = 0;

  if(stream)
  {
    va_start(vl, fmt);
    r = vfprintf(stream, fmt, vl);
    va_end(vl);
  }
  return r;
}

static number vec_dot(int n, number *a, number *b)
{
  number ab = 0;
  int i;

  for(i = 0; i < n; ++i)
    ab += a[i] * b[i];
  return ab;
}

/* IMPORTANT: A^T == A */
static number vec_dotA(int n, number *a, number *b, number (*A)[n])
{
  number aAb = 0;
  int i, j;

  for(i = 0; i < n; ++i)
  {
    aAb += a[i] * A[i][i] * b[i];
    for(j = i + 1; j < n; ++j)
      aAb += 2 * a[i] * A[i][j] * b[j];
  }
  return aAb;
}

void gd(int n, number A[n][n], number b[n], number x[n], number eps)
{
  number r[n], p[n], ri, r2, alpha;
  int i;

  r2 = 0;
  for(i = 0; i < n; ++i)
  {
    ri = b[i] - vec_dot(n, A[i], x);
    r[i] = ri;  // r = b - A*x
    r2 += ri * ri;  // r2 = r*r
  }

  while(sqrt(r2) > eps)
  {
    alpha = r2 / vec_dotA(n, r, r, A);  // alpha = r*r / r*A*r
    for(i = 0; i < n; ++i)
    {
      x[i] += alpha * r[i];  // x += alpha * r
      logging("%+23.13la", (double)x[i]);
    }
    logging("\n");
    for(i = 0; i < n; ++i)
      p[i] = r[i];
    r2 = 0;
    for(i = 0; i < n; ++i)
    {
      ri = r[i] - alpha * vec_dot(n, A[i], p);
      r[i] = ri;  // r -= alpha * A * p
      r2 += ri * ri;  // r2 = r*r
    }
  }
}
