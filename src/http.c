#include <http.h>

int parsemethod(strview method) {
  if (streq(str("GET"), method)) {
    return HTTP_GET;
  } else if (streq(str("POST"), method)) {
    return HTTP_POST;
  } else if (streq(str("PUT"), method)) {
    return HTTP_PUT;
  } else if (streq(str("HEAD"), method)) {
    return HTTP_HEAD;
  } else if (streq(str("OPTIONS"), method)) {
    return HTTP_OPTIONS;
  } else if (streq(str("DELETE"), method)) {
    return HTTP_DELETE;
  } else {
    return HTTP_UNRECOGNISED_METHOD;
  }
}
