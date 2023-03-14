#include "util.hpp"

namespace GoLF {    

void warningCheck() {    
    static int warningCount = 0;
    // check that warning() wasnt called without an input file somehow :|
    if(inputFileName.size() == 0) {
        return;
    }
    // exit after 15 warnings
    if(warningCount++ == 15) {
        handleError("Too many warnings");
    }
}

void handleWarning(const char* msg) {
    fprintf(stderr, "warning: %s: %s\n", inputFileName.c_str(), msg);
}

void handleWarning(const char* msg, int lineno) {
    fprintf(stderr, "warning: %s:%i: %s\n", inputFileName.c_str(), lineno, msg);
}

void handleWarning(const char* msg, int lineno, int colno) {
    fprintf(stderr, "warning: %s:%i:%i: %s\n", inputFileName.c_str(), lineno, colno, msg);
}

void handleWarning(const char* msg, int lineno, int colno, const char* badString) {
    fprintf(stderr, "warning: %s:%i:%i: %s '%s'\n", inputFileName.c_str(), lineno, colno, msg, badString);
}

void handleError(const char* msg) {
    fprintf(stderr, "error: %s: %s\n", inputFileName.c_str(), msg);
    exit(EXIT_FAILURE);
}

void handleError(const char* msg, int lineno) {
    fprintf(stderr, "error: %s:%i: %s\n", inputFileName.c_str(), lineno, msg);
    exit(EXIT_FAILURE);
}

void handleError(const char* msg, int lineno, int colno) {
    fprintf(stderr, "error: %s:%i:%i: %s\n", inputFileName.c_str(), lineno, colno, msg);
    exit(EXIT_FAILURE);
}

void handleError(const char* msg, int lineno, int colno, const char* badString) {
    fprintf(stderr, "error: %s:%i:%i: %s '%s'\n", inputFileName.c_str(), lineno, colno, msg, badString);
    exit(EXIT_FAILURE);
}

void handleInvalidType(std::string& ident, location& loc) {
    std::string errorMsg = "expected type, got '" + ident + "'";
    handleError(errorMsg.c_str(), loc.begin.line, loc.begin.column);
}
}