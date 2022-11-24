#include <stdio.h>

#define number double

// function parameters
#define SIGMA ((number)10.0)
#define RHO   ((number)28.0)
#define BETA  ((number)(5.0 / 3.0))

// initial values
#define Y10   ((number)12.0)
#define Y20   ((number)4.0)
#define Y30   ((number)0.0)

// argument interval and fragment #
#define T0    ((number)0.0)
#define TN    ((number)10.0)
#define N     100000
#define DT    ((TN - T0) / N)

// variable aliases
#define y1    (y[0])
#define y2    (y[1])
#define y3    (y[2])
#define yp1   (yp[0])
#define yp2   (yp[1])
#define yp3   (yp[2])

// implement the Lorenz equation
static void Lorenz(number yp[3], const number y[3])
{
  yp1 = -BETA * y1 + y2 * y3;
  yp2 = -SIGMA * y2 + SIGMA * y3;
  yp3 = -y2 * y1 + RHO * y2 - y3;
}

// report argument and derivative values
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
static void report(int i, const number y[3], const number yp[3])
{
  for(i = 0; i < 3; ++i)
    printf("%16lg", y[i]);
  printf("\n");
}
#pragma GCC diagnostic pop

// solve the Lorenz equation with forward difference
int main(void)
{
  int i, j;
  number y[3] = {Y10, Y20, Y30};
  number yp[3];

  for(i = 0; i <= N; ++i)
  {
    Lorenz(yp, y);
    report(i, y, yp);
    for(j = 0; j < 3; ++j)
      y[j] += yp[j] * DT;
  }
  return 0;
}
