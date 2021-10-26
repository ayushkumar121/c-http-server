#include <strview.h>

strview str(char *string)
{
  strview view =
  {
    .count = strlen(string),
    .ptr   = string
  };
  return view;
}

strview slice(strview view, int start, int count)
{
  view.ptr += start;
  view.count = count;

  return view;
}

/*
strview trim(strview str)
{
  return str("");
}
*/
