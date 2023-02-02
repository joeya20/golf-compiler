#include "main.h"

enum Token currentToken = 0;
char *inputFilePath;

int main(int argc, char **argv) {

    //check that input file was provided
    if(argc == 1) {
        error(1, "No input file provided");
    }
    else if(argc == 2){        
        inputFilePath = argv[1];
        yyin = fopen(argv[1], "r");
    }
    else {
        error(1, "Too many input files provided");
    }

    //check that file was opened successfully
    if(yyin == NULL) {
        error(1, "Error opening input file");
    }

    //get all tokens from input file
    while((currentToken = lex()) != 0) {
        printf("%s\t[%s] @ line %i @ col %i\n", tokenToString(currentToken), yytext, lineno, charno-yyleng);
    }
}