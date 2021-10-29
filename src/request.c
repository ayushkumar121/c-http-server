#include <request.h>

strview STR_EMPTY;

request parsereq(int sockfd) {
  request req = {0};
  read(sockfd, req.body, sizeof(req.body));

  strview body = str(req.body);
  strview line = strsplit(body, '\n');
  strview reqstr = line;

  int count = 0;
  while (line.count > 0) {
    count += line.count;
    line = strsplit(STR_EMPTY, '\n');
  }

  strview method = strsplit(reqstr, ' ');
  strview url = strsplit(STR_EMPTY, ' ');
  strview version = strsplit(STR_EMPTY, ' ');

  req.method = parsemethod(method);
  memcpy(req.url, url.ptr, url.count);

  return req;
}
