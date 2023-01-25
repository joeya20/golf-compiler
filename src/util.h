#include <string>
#include <iostream>
#include <cstdlib>

// prints error message and terminates program
void printError(std::string msg);
void printError(std::string msg, uint64_t lineno, uint64_t charno);