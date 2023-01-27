#include "util.h"

// prints error message and terminates program
void error(const char *msg, int lineno, int charno) {
    fprintf(stdout, "Error: %s @ line no %i, @ char no %i\n", msg, lineno, charno);
    fprintf(stderr, "Program terminating...\n");
    exit(EXIT_FAILURE);
}


void warning(const char *msg, int lineno, int charno) {
    fprintf(stdout, "Warning: %s @ line no %i, @ char no %i\n", msg, lineno, charno);
    fprintf(stderr, "Program continuing...\n");
}
