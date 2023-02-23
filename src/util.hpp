#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>

// defined in main from command line arg
extern std::string inputFileName;

// prints error message and terminates program
void handleError(const int argNum, ...);
void warning(const int argNum, ...);

#endif