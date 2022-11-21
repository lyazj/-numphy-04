#pragma once

#include <stddef.h>

#ifndef number
#define number double
#define NBR_EPSILON DBL_EPSILON
#endif  /* number */

extern void *logging_stream;
int logging(const char *fmt, ...)
    __attribute__((__format__(__printf__, 1, 2)));

int qr(int n, number A[n][n], number Q[n][n], number R[n][n]);
int qrh(int n, number A[n][n], number Q[n][n], number R[n][n]);
int qri(int n, number A[n][n], number *e, int m);
int qrih(int n, number A[n][n], number *e, int m);
int hhr(int n, number A[n][n]);
int qrig(int n, number A[n][n], number *e, int m);
int jcbi(int n, number A[n][n], number *e, int m);
int sgi(int n, number a[n], number b[n - 1], int c,
    number *l, number *u, number *e, int m);
