#include <logger.h>

void
logInfo(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  fprintf(stdout, ANSI_COLOR_BLUE "[INFO] ");
  vfprintf(stdout, format, args);
  fprintf(stdout, "\n" ANSI_COLOR_RESET);
  va_end(args);
}

void
logWarn(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  fprintf(stdout, ANSI_COLOR_YELLOW "[WARN] ");
  vfprintf(stdout, format, args);
  fprintf(stdout, "\n" ANSI_COLOR_RESET);
  va_end(args);
}

void
logError(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  fprintf(stderr, ANSI_COLOR_RED "[ERROR] ");
  vfprintf(stderr, format, args);
  fprintf(stderr, "\n" ANSI_COLOR_RESET);
  va_end(args);
}
