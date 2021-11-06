#ifndef RESPONSE_H
#define RESPONSE_H

/* TODO: Remove libc dependency */
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/socket.h>

#include <http.h>
#include <logger.h>
#include <strview.h>

#define MAX_HEADER_SIZE 1024
#define MAX_HEADER_FIELDS 10

typedef struct {
  strview key;
  strview value;
} field;

typedef struct {
  int count;
  field fields[MAX_HEADER_FIELDS];
} headers;

void reshtml(int sockfd, strview path, int status);
void reswrite(int sockfd, strview body, headers head, int status);


#endif /* RESPONSE_H */
