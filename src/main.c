#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <signal.h>

#include <logger.h>
#include <strview.h>
#include <server.h>
#include <request.h>
#include <response.h>

void
reqhandle(int sockfd)
{
  response res;

  request req = parsereq(sockfd);
  strview url = str(req.url);

  loginfo("Request handled: %s", req.url);
  
  ressend(sockfd, res);
}

void
reqexit()
{
  signal(SIGCHLD, SIG_IGN);
}

int
main(int argc, char *argv[])
{
  server s = screate();
  slisten(s, 8080);

  while(1)
  {
    int pid       = 0;
    int sockfd    = saccept(s);
    
    /* Accept client */
    if(sockfd != -1)
    {
       if((pid = fork()) == 0)
       {
	 reqhandle(sockfd);
	 break;
       }
       else
       {
	 if(pid == -1)
	   logerror("Cannot fork subprocess:\n\t %s", strerror(errno));

	 reqexit();
       }
       
       close(sockfd);
    }
  }
     
  sclose(s);
  return 0;
}
