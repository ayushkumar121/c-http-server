#ifndef STRVIEW_H
#define STRVIEW_H

#include <string.h>

typedef struct
{
  int count;
  char *ptr;
} strview;

strview str(char *string);

strview slice(strview str, int start, int count);
//strview trim(strview str);

#endif /* STRVIEW_H */

