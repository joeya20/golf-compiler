#include "util.h"

// prints error message and terminates program
// void error(const char *msg, int lineno, int charno) {
//     fprintf(stderr, "Error: %s @ line no %i, @ char no %i\n", msg, lineno, charno);
//     fprintf(stderr, "Program terminating...\n");
//     exit(EXIT_FAILURE);
// }


void warning(const char *msg, int lineno, int charno) {
    fprintf(stderr, "Warning: %s @ line %i @ char %i\n", msg, lineno, charno);
    fprintf(stderr, "Program continuing...\n");
}

void error(const int argNum, ...) {
    va_list args;
    va_start(args, argNum);
    if(argNum == 1) {
        char *msg = va_arg(args, char*);
        fprintf(stderr, "Error: %s\n", msg);
        fprintf(stderr, "Program terminating...\n");
    }
    else if(argNum == 2) {
        char *msg = va_arg(args, char*);
        int lineno = va_arg(args, int);
        fprintf(stderr, "Error: %s @ line %i\n", msg, lineno);
        fprintf(stderr, "Program terminating...\n");
    }
    else if(argNum == 3) {
        char *msg = va_arg(args, char*);
        int lineno = va_arg(args, int);
        int charno = va_arg(args, int);
        fprintf(stderr, "Error: %s @ line %i @ char %i\n", msg, lineno, charno);
        fprintf(stderr, "Program terminating...\n");
    }
    else {
        char *msg = va_arg(args, char*);
        int lineno = va_arg(args, int);
        int charno = va_arg(args, int);
        char badChar = va_arg(args, int);
        fprintf(stderr, "Error: %s '%c' @ line %i @ char %i\n", msg, badChar, lineno, charno);
        fprintf(stderr, "Program terminating...\n");
    }
    va_end(args);    
    exit(EXIT_FAILURE);
}