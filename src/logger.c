#include <logger.h>

void
logstr(const char *label, strview view)
{
  time_t t;
  struct tm* ts;
  
  time(&t);
  ts = localtime(&t);
 
  fprintf(stdout, ANSI_COLOR_GREEN "[%d-%d-%d %d:%d:%d]",
	  ts->tm_mday, ts->tm_mon, ts->tm_year, ts->tm_hour, ts->tm_min, ts->tm_sec);
  fprintf(stdout, " [STRVIEW(label=%s, count=%d)]\n\t" ANSI_COLOR_RESET,
	  label, view.count);

  for(int i=0; i<view.count; i++) {
    putchar(view.ptr[i]);
  }

  fprintf(stdout, "\n");
}

void
loginfo(const char *format, ...)
{
  time_t t;
  va_list args;
  struct tm* ts;
  
  time(&t);
  va_start(args, format);
  ts = localtime(&t);
 
  fprintf(stdout, ANSI_COLOR_BLUE LOG_DATE_FORMAT,
	  ts->tm_mday, ts->tm_mon, ts->tm_year, ts->tm_hour, ts->tm_min, ts->tm_sec);
  fprintf(stdout, " [INFO] ");
  vfprintf(stdout, format, args);
  fprintf(stdout, "\n" ANSI_COLOR_RESET);

  va_end(args);
}

void
logwarn(const char *format, ...)
{
  time_t t;
  va_list args;
  struct tm* ts;
  
  time(&t);
  va_start(args, format);
  ts = localtime(&t);
 
  fprintf(stdout, ANSI_COLOR_YELLOW LOG_DATE_FORMAT,
	  ts->tm_mday, ts->tm_mon, ts->tm_year, ts->tm_hour, ts->tm_min, ts->tm_sec);
  fprintf(stdout, " [WARN] ");
  vfprintf(stdout, format, args);
  fprintf(stdout, "\n" ANSI_COLOR_RESET);
  va_end(args);
}

void
logerror(const char *format, ...)
{
  time_t t;
  va_list args;
  struct tm* ts;
  
  time(&t);
  va_start(args, format);
  ts = localtime(&t);
 
  fprintf(stdout, ANSI_COLOR_RED LOG_DATE_FORMAT,
	  ts->tm_mday, ts->tm_mon, ts->tm_year, ts->tm_hour, ts->tm_min, ts->tm_sec);
  fprintf(stdout, " [ERROR] ");
  vfprintf(stderr, format, args);
  fprintf(stderr, "\n" ANSI_COLOR_RESET);
  va_end(args);
}
