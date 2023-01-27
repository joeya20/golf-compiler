#include "main.h"

int main(int argc, char **argv) {    
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
    }
    else {
        //TODO: use error routine
        fprintf(stderr, "No input file provided\n");
        fprintf(stderr, "Program terminating...\n");
        exit(EXIT_FAILURE);
    }

    if(yyin == NULL) {
        //TODO: use error routine
        fprintf(stderr, "Error opening input file\n");
        fprintf(stderr, "Program terminating...\n");
        exit(EXIT_FAILURE);
    }

    while((currentToken = lex()) != 0) {
        printf("%s\t[%s] @ line %i @ char %i\n", tokenToString(currentToken), yytext, lineno, charno);
        charno += yyleng;
    }
}