#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <iostream>

// defined in main from command line arg
extern std::string inputFileName;

#include "util.hpp"
#include "location.hh"

namespace GoLF {
void warningCheck();

void handleWarning(const char* msg);
void handleWarning(const char* msg, int lineno);
void handleWarning(const char* msg, int lineno, int colno);
void handleWarning(const char* msg, int lineno, int colno, const char* badString);

void handleError(const char* msg);
void handleError(const char* msg, int lineno);
void handleError(const char* msg, int lineno, int colno);
void handleError(const char* msg, int lineno, int colno, const char* badString);
}