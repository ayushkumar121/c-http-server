#include <request.h>

strview STR_EMPTY;

http_method
parsemethod(strview method)
{
  if(streq(str("GET"), method)) {
    return HTTP_GET;
  }
  else if(streq(str("POST"), method)) {
    return HTTP_POST;
  }
  else if(streq(str("PUT"), method)) {
    return HTTP_PUT;
  }
  else if(streq(str("HEAD"), method)) {
    return HTTP_HEAD;
  }
  else if(streq(str("OPTIONS"), method)) {
    return HTTP_OPTIONS;
  }
  else if(streq(str("DELETE"), method)) {
    return HTTP_DELETE;
  }
  else {
    return HTTP_UNRECOGNISED_METHOD;
  }
}

request
parsereq(int sockfd)
{
  request req = {0};
  read(sockfd, req.body, sizeof(req.body));

  strview body = str(req.body);
  strview line = strsplit(body, '\n');
  strview reqstr = line;

  int count = 0;
  while(line.count > 0) {
    count += line.count;
    line  = strsplit(STR_EMPTY, '\n');
  }
  
  strview method  = strsplit(reqstr, ' ');
  strview url     = strsplit(STR_EMPTY, ' ');
  strview version = strsplit(STR_EMPTY, ' '); 

  req.method = parsemethod(method);
  memcpy(req.url, url.ptr, url.count);
  
  return req;
}
