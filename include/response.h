#ifndef RESPONSE_H
#define RESPONSE_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

#include <http.h>
#include <logger.h>
#include <strview.h>

#define MAX_HEADER_SIZE 1024
#define MAX_HEADER_FIELDS 10

typedef struct {
  strview key;
  strview value;
} header;

/* typedef struct { */
/*   http_status status; */
/* } response; */

void reswrite(int sockfd, strview body, int status);

#endif
