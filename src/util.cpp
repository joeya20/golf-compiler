#include "util.h"

// prints error message and terminates program
void printError(std::string msg) {
    std::cerr << msg << std::endl;
    exit(EXIT_FAILURE);
}

void printError(std::string msg, uint64_t lineno, uint64_t charno) {
    printError(msg + " @charno " + std::to_string(charno) + " @lineno " + std::to_string(lineno));
}

//TODO: warning routine
