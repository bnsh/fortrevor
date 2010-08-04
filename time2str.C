#include <stdio.h>
#include <time.h>
#include "time2str.H"

const char *time2str(char *buffer, int sz, const char *fmt, time_t t) {
	strftime(buffer,sz,fmt,localtime(&t));
	return(buffer);
}
