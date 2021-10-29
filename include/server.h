#ifndef SERVER_H
#define SERVER_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <logger.h>

typedef struct {
  int sockfd;
} server;

server screate(int port);
int saccept(server s);
void sclose(server s);

#endif /* SERVER_H */
