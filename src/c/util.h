#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

extern char *inputFilePath;
extern int yyleng;
extern char *yytext;

// prints error message and terminates program
// void error(const char *msg, int lineno, int charno);
void error(const int argNum, ...);
void warning(const int argNum, ...);

#endif