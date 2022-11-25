#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <unistd.h>

#define number double
#define NBL_EPSILON DBL_EPSILON
#define N 10

static void set_A(number A[N][N]);
static void rand_q(number q[N]);
static double get_c(number A[N][N], number q[N]);
static double rmse(number a[N], number b[N]);

void set_A(number A[N][N])
{
  int i;

  for(i = 0; i < N; ++i)
  {
    A[i][(i - 1 + N) % N] = -1;
    A[i][i] = 2;
    A[i][(i + 1 + N) % N] = -1;
  }
}

void rand_q(number q[N])
{
  int i;
  number q2 = 0;

  srand(getpid());
again:
  for(i = 0; i < N; ++i)
  {
    q[i] = (signed char)rand();
    q2 += q[i] * q[i];
  }
  q2 = sqrt(q2);
  if(q2 == 0)
    goto again;
  for(i = 0; i < N; ++i)
    q[i] /= q2;
}

double get_c(number A[N][N], number q[N])
{
  int i, j;
  number qAq = 0;

  for(i = 0; i < N; ++i)
  {
    for(j = 0; j < i; ++j)
      qAq += 2 * (q[i] * A[i][j] * q[j]);
    qAq += q[i] * A[i][i] * q[i];
  }
  return qAq;
}

double rmse(number a[N], number b[N])
{
  int i;
  number sse = 0;

  for(i = 0; i < N; ++i)
    sse += (a[i] - b[i]) * (a[i] - b[i]);
  return sqrt(sse / N);
}

int main(void)
{
  number A[N][N], q[N], c, q_new[N], c_new, q1, q2;
  set_A(A);
  rand_q(q_new);
  c_new = get_c(A, q_new);
  int i, j, t = 0;

  do {
    for(i = 0; i < N; ++i)
      q[i] = q_new[i];
    c = c_new;

    printf("[%d]\n", t++);
    for(i = 0; i < N; ++i)
      printf("%+16.6lf%+25.13la\n", (double)q[i], (double)q[i]);
    printf("\n%+16.6lf%+25.13la\n\n", (double)c, (double)c);

    q2 = 0;
    for(i = 0; i < N; ++i)
    {
      q1 = 0;
      for(j = 0; j < N; ++j)
        q1 += A[i][j] * q[j];
      q_new[i] = q1;
      q2 += q1 * q1;
    }
    q2 = sqrt(q2);
    for(i = 0; i < N; ++i)
      q_new[i] /= q2;
    c_new = get_c(A, q_new);
  }
  while(rmse(q_new, q) >= NBL_EPSILON || fabs(c_new - c) >= NBL_EPSILON);

  fprintf(stderr, "[%d]\n", t++);
  for(i = 0; i < N; ++i)
    fprintf(stderr, "%+16.6lf%+25.13la\n", (double)q_new[i], (double)q_new[i]);
  fprintf(stderr, "\n%+16.6lf%+25.13la\n\n", (double)c_new, (double)c_new);
  return 0;
}
