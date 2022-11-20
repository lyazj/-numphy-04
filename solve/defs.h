#pragma once

#ifndef number
#define number double
#endif  /* number */

extern void *cg_logging;  // FILE *

void cg(int n, number A[n][n], number b[n], number x[n], number eps);
