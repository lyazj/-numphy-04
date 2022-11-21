#include "defs.h"
#include <math.h>

static int sturm(int n, number a[n], number b[n - 1], number v)
{
  _Bool sign;  // current sign (need C99+)
  int c;       // sign alteration counter
  number p0, p1, p2;
  int i;

  p0 = 1;
  sign = signbit(p0);  // need C99+
  c = 0;
  p1 = a[0] - v;
  if(p1 == 0 || signbit(p1) != sign)
  {
    sign = !sign;
    ++c;
  }
  for(i = 1; i < n; ++i)
  {
    p2 = (a[i] - v) * p1 - b[i - 1] * b[i - 1] * p0;
    p0 = p1;
    p1 = p2;
    if(p1 == 0 || signbit(p1) != sign)
    {
      sign = !sign;
      ++c;
    }
  }
  return c;
}

// Do Sturm-Gershgorin iteration.
int sgi(int n, number a[n], number b[n - 1], int c,
    number *lp, number *up, number *e, int m)
{
  int i, s, t;
  number l, u, v, l0, u0, r, e0 = *e;

  if(n < 2)
    return -1;
  l = a[0] - fabs(b[0]);
  u = a[0] + fabs(b[0]);
  l0 = a[n - 1] - fabs(b[n - 2]);
  u0 = a[n - 1] + fabs(b[n - 2]);
  l = l0 < l ? l0 : l;
  u = u0 > u ? u0 : u;
  for(i = 1; i < n - 1; ++i)
  {
    l0 = a[i] - fabs(b[i]) - fabs(b[i - 1]);
    u0 = a[i] + fabs(b[i]) + fabs(b[i - 1]);
    l = l0 < l ? l0 : l;
    u = u0 > u ? u0 : u;
  }
  r = u - l;

  for(t = 0; t < m && r >= e0; ++t)
  {
    v = (l + u) / 2;
    s = sturm(n, a, b, v);
    if(s > c)
      u = v;
    else
      l = v;
    r = u - l;
    if((t + 1) % 5 == 0)
    {
      logging("%s-%d(%d):\n", __func__, t + 1, c);
      logging("approx: %+25.13la  err: %+23.13la\n",
          (double)((l + u) / 2), (double)r);
    }
  }
  *lp = l;
  *up = u;
  *e = r;
  return t;
}
