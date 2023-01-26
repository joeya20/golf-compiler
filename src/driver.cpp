#include "driver.h"

int main(int argc, char *argv[]) {
    FlexLexer* lexer;
    std::ifstream inputFile;

    if(argc >= 1) {
        try{
            // open file
            inputFile.open(argv[1], std::ifstream::in);
            // create lexer
            lexer = new yyFlexLexer(inputFile, std::cout);
        }
        catch (std::exception& ex) {
            //TODO: error routine
        }
    }
    else {
        //TODO: throw error
    }

    // yylex will run until EOF (returns 0)
    int currentToken;
    while((currentToken = lexer->yylex()) != 0) {      
        printf("The token we just lexed is %s at line number %i with type %i\n", lexer->YYText(), lexer->lineno(), currentToken);
        // charno += lexer->YYLeng();
    }
}