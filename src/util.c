#include "util.h"

int warningCount = 0;

void warning(const int argNum, ...) {
    // check that warning() wasnt called without an input file somehow :|
    if(inputFilePath == NULL) {
        return;
    }
    // exit after 15 warnings
    if(warningCount++ == 15) {
        error(1, "Too many warnings");
    }
    // print different messages based on amount of information given
    va_list args;
    va_start(args, argNum);
    if(argNum == 1) {
        char *msg = va_arg(args, char*);
        fprintf(stderr, "warning: %s: %s\n", inputFilePath, msg);
    }
    else if(argNum == 2) {
        char *msg = va_arg(args, char*);
        int lineno = va_arg(args, int);
        fprintf(stderr, "warning: %s:%i: %s\n", inputFilePath, lineno, msg);
    }
    else if(argNum == 3) {
        char *msg = va_arg(args, char*);
        int lineno = va_arg(args, int);
        int charno = va_arg(args, int);
        fprintf(stderr, "warning: %s:%i:%i: %s\n", inputFilePath, lineno, charno, msg);
    }
    else {
        char *msg = va_arg(args, char*);
        int lineno = va_arg(args, int);
        int charno = va_arg(args, int);
        char *badString = va_arg(args,  char*);
        fprintf(stderr, "warning: %s:%i:%i: %s '%s'\n", inputFilePath, lineno, charno, msg, badString);
    }
    va_end(args);
}

void error(const int argNum, ...) {
    va_list args;
    va_start(args, argNum);
    // print different messages based on amount of information given
    if(argNum == 1) {
        char *msg = va_arg(args, char*);
        fprintf(stderr, "error: %s: %s\n", inputFilePath, msg);
    }
    else if(argNum == 2) {
        char *msg = va_arg(args, char*);
        int lineno = va_arg(args, int);
        fprintf(stderr, "error: %s:%i: %s\n", inputFilePath, lineno, msg);
    }
    else if(argNum == 3) {
        char *msg = va_arg(args, char*);
        int lineno = va_arg(args, int);
        int charno = va_arg(args, int);
        fprintf(stderr, "error: %s:%i:%i: %s\n", inputFilePath, lineno, charno, msg);
    }
    else {
        char *msg = va_arg(args, char*);
        int lineno = va_arg(args, int);
        int charno = va_arg(args, int);
        char *badString = va_arg(args,  char*);
        fprintf(stderr, "error: %s:%i:%i: %s '%s'\n", inputFilePath, lineno, charno, msg, badString);
    }
    va_end(args);
    exit(EXIT_FAILURE);
}