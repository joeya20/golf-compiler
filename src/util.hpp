#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>

extern std::string inputFilePath;

// prints error message and terminates program
// void error(const char *msg, int lineno, int charno);
void error(const int argNum, ...);
void warning(const int argNum, ...);

#endif