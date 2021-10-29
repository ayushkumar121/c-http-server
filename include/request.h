#ifndef REQUEST_H
#define REQUEST_H

#include <string.h>

#include <sys/mman.h>
#include <unistd.h>

#include <http.h>
#include <logger.h>
#include <strview.h>

#define MAX_URL_SIZE 256
#define MAX_BODY_SIZE 1024

typedef struct {
  http_method method;

  char url[MAX_URL_SIZE];
  char body[MAX_BODY_SIZE];
} request;

request parsereq(int sockfd);

#endif /* REQUEST_H */
