#include <response.h>

void reswrite(int sockfd, strview message, headers head, int status) {

  size_t header_size = MAX_HEADER_SIZE * MAX_HEADER_FIELDS;
  size_t body_size = header_size + message.count;

  char header[header_size];
  char *body = malloc(body_size);

  for (int i = 0; i < head.count; i++) {
    strcat(header, head.fields[i].key.ptr);
    strcat(header, ":");
    strcat(header, head.fields[i].value.ptr);
    strcat(header, "\r\n");
  }

  sprintf(body,
          "HTTP/1.1 %d OK\r\n"
          "%s"
          "Content-Length: %d\r\n"
          "\r\n%s",
          status, header, message.count, message.ptr);

  write(sockfd, body, body_size);
  free(body);
}

void reshtml(int sockfd, strview path, int status) {
  int fd;
  struct stat sb;

  if (stat(path.ptr, &sb) == -1) {
    logerror("Cannot open file");
    return;
  }

  fd = open(path.ptr, O_RDONLY);
  char *addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

  if (addr == MAP_FAILED) {
    logerror("Cannot map file");
    return;
  }

  headers head = {.fields = {{.key = str("Content-Type"),
                              .value = str("text/html; charset=UTF-8")}},
                  .count = 1};

  reswrite(sockfd, str(addr), head, status);
}
