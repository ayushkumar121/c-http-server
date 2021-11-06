#include <errno.h>
#include <signal.h>
#include <string.h>

#include <logger.h>
#include <request.h>
#include <response.h>
#include <server.h>
#include <strview.h>

void reqhandle(int sockfd) {
  request req = parsereq(sockfd);
  loginfo("Request handled: %s", req.url);
  reshtml(sockfd, str("../www/index.html"), HTTP_OK);
}

void reqexit() { signal(SIGCHLD, SIG_IGN); }

int main(int argc, char *argv[]) {
  server s = screate(8080);

  while (1) {
    int sockfd = saccept(s);

    /* Accept client */
    if (sockfd != -1) {
      int pid = 0;

      if ((pid = fork()) == 0) {
        reqhandle(sockfd);
        break;
      } else {
        if (pid == -1)
          logerror("Cannot fork subprocess:\n\t %s", strerror(errno));

        reqexit();
      }

      close(sockfd);
    }
  }

  sclose(s);
  return 0;
}
