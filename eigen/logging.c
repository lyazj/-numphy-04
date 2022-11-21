#include "defs.h"
#include <stdio.h>
#include <stdarg.h>

void *logging_stream;

int logging(const char *fmt, ...)
{
  FILE *stream = (FILE *)logging_stream;
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
