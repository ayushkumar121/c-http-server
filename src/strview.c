#include <strview.h>
#include <stdio.h>

strview
str(char *string)
{
  strview view =
  {
    .count = strlen(string),
    .ptr   = string
  };
  return view;
}

int
streq(strview a, strview b)
{
  if(a.count != b.count)
    return 0;

  for(int i=0; i<a.count; i++) {
    if(*(a.ptr+i) != *(b.ptr+i))
      return 0;
  }

  return 1;
}

strview
strsplit(strview view, char del)
{
  static strview state = {0};
 
  if(view.count != 0) {
    state = view;
  }
  
  int i = 0;
  while(*(state.ptr + i) != del
	&& i < state.count)
    ++i;
  
  view.count = i;
  view.ptr   = state.ptr;

  state.count -= (i + 1);
  state.ptr   += (i + 1);

  return view;
}

strview
slice(strview view, int start, int count)
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
