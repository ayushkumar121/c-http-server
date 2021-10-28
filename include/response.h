#ifndef RESPONSE_H
#define RESPONSE_H

#include <sys/socket.h>

#include <http.h>
#include <logger.h>
#include <strview.h>

typedef struct
{
  http_status status;
} response;

void ressend(int sockfd, response response);

#endif
