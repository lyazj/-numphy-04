#pragma once

#ifndef number
#define number double
#endif  /* number */

extern void *cg_logging;  // FILE *
extern void *gd_logging;  // FILE *

void cg(int n, number A[n][n], number b[n], number x[n], number eps);
void gd(int n, number A[n][n], number b[n], number x[n], number eps);
