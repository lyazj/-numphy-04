#pragma once

#include <stddef.h>

#ifndef number
#define number double
#define NBR_EPSILON DBL_EPSILON
#endif  /* number */

int qr(int n, number A[n][n], number Q[n][n], number R[n][n]);
int qri(int n, number A[n][n], number *e, int m);
int hhr(int n, number A[n][n]);
int qrig(int n, number A[n][n], number *e, int m);
