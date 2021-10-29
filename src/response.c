#include <response.h>

void reswrite(int sockfd, strview message, int status) {
 
  size_t size = (MAX_HEADER_SIZE * MAX_HEADER_FIELDS) + message.count;
  char *body = malloc(size);

  sprintf(body, "HTTP/1.1 %d OK\r\n"
	  "Content-Type: text/plain; charset=utf-8\r\n"
	  "Content-Length: %d\r\n"
	  "\r\n%s", status, message.count, message.ptr);
  
  write(sockfd, body, size);
  free(body);
}
