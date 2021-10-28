#include <response.h>

void ressend(int sockfd, response response)
{
    
    strview hello = str("HTTP/1.1 200 OK\r\n"
		     "Content-Type: text/plain; charset=utf-8\r\n"
		     "Content-Length: 14\r\n"
		     "\r\n"
		     "Hello world!\r\n");

  send(sockfd, hello.ptr, hello.count, 0);
}
