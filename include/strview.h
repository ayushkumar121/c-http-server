#ifndef STRVIEW_H
#define STRVIEW_H

#include <string.h>

typedef struct
{
  int count;
  char *ptr;
} strview;

strview str(char *string);
int streq(strview a, strview b);

strview strsplit(strview view, char del);
strview slice(strview view, int start, int count);

//strview trim(strview str);

#endif /* STRVIEW_H */

