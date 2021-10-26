#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <logger.h>

typedef struct
{
  int sockfd;
} server;

server screate();
void   slisten(server s, int port);
int    saccept(server s);
void   sclose(server s);

#endif /* SERVER_H */
