#include <server.h>

server
screate()
{
  server s = {0};
  int opt = 1;
  
  /* Creating a socket for ipv4 */
  if((s.sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    logError("Socket creation fad with error:\n\t %s",
	    strerror(errno));

    exit(EXIT_FAILURE);
  }
  
  /* Setting socket options */
  if(setsockopt(s.sockfd, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(int)) == -1)
  {
    logError("Cannot set socket options:\n\t REUSEADDR:%s",
	    strerror(errno));

    exit(EXIT_FAILURE);
  }
  
  return s;
}

void
slisten(server s, int port)
{  
  struct sockaddr_in addr = {
    .sin_family = AF_INET,
    .sin_addr.s_addr = htonl(INADDR_ANY),
    .sin_port = htons(port)
  };

  socklen_t socklen = sizeof(addr);

  /* Binding socket to address */
  if(bind(s.sockfd, (struct sockaddr *)&addr, sizeof(addr)) != 0)
  {
    logError("Cannot bind socket to address:\n\t %s",
	    strerror(errno));

    exit(EXIT_FAILURE);
  }
  
  /* Listening to port */
  if(listen(s.sockfd, 5) != 0)
  {
    logError("Cannot listen on port:\n\t %s",
	    strerror(errno));

    exit(EXIT_FAILURE);
  }
  
  logInfo( "Server listening on port: %d", port);
}

int
saccept(server s)
{
  struct sockaddr_in addr = {0};
  socklen_t socklen = sizeof(addr);

  return accept(s.sockfd, (struct sockaddr*)&addr, &socklen);
}

void
sclose(server s)
{
  close(s.sockfd);
}
