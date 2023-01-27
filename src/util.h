#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <stdio.h>

// prints error message and terminates program
void error(const char *msg, int lineno, int charno);
void warning(const char *msg, int lineno, int charno);

#endif