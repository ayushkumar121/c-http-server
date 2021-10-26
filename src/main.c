#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <signal.h>

#include <logger.h>
#include <server.h>
#include <strview.h>

void handlereq(int sockfd)
{  
  char  buff[100];
  strview hello = str("HTTP/1.1 200 OK\r\n"
		     "Content-Type: text/plain; charset=utf-8\r\n"
		     "Content-Length: 14\r\n"
		     "\r\n"
		     "Hello world!\r\n");


  logInfo("Request handled:");

  read(sockfd, buff, sizeof(buff));
  send(sockfd, hello.ptr, hello.count, 0);
}

int
main(int argc, char *argv[])
{
  server s = screate();
  slisten(s, 8080);

  strview view = str("Hello world");
  strview view2 = slice(view, 5, 2);
  
  printf("count=%d, str=%s\n", view2.count, view2.ptr);
  
  while(1)
  {
    int pid       = 0;
    int connfd    = saccept(s);
    
    /* Accept client */
    if(connfd != -1)
    {
       if((pid = fork()) == 0)
       {
	 handlereq(connfd);
	 break;
       }
       else
       {
	 if(pid == -1)
	 {
	   logError("Cannot fork subprocess:\n\t %s",
		    strerror(errno));
	 }
	 else
	 {
	   logInfo("Processing requests for(PID=%d)",
		   pid);
	 }

	 /* Handle process exit */
	 signal(SIGCHLD, SIG_IGN);
       }
       
       close(connfd);
    }
  }
     
  sclose(s);
  return 0;
}
