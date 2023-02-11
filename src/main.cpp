#include "main.hpp"

std::string inputFilePath;

int main(int argc, char **argv) {
    std::ifstream inputFile;

    //check that input file was provided
    if(argc == 1) {
        error(1, "No input file provided");
    }
    else if(argc == 2){        
        inputFilePath = argv[1];
        inputFile.open(inputFilePath);
    }
    else {
        error(1, "Too many input files provided");
    }
    //check that file was opened successfully
    if(!inputFile.is_open()) {
        error(1, "Error opening input file");
    }

    GoLF::Lexer *lexer = new GoLF::Lexer(inputFile, std::cout);
    while((currentToken = lexer->lex()) != GoLFLexer::Token::T_EOF && !eofReached) {
        printf("%s\t[%s] @ line %i @ col %i\n", GoLFLexer::tokenToString(currentToken), lexer->YYText(), lexer->lineno(), colno-lexer->YYLeng());
    }
    //last check to see if we have a final semicolon to print
    if(currentToken != GoLFLexer::Token::T_EOF) {
        printf("%s\t[%s] @ line %i @ col %i\n", GoLFLexer::tokenToString(currentToken), lexer->YYText(), lexer->lineno(), colno-lexer->YYLeng());
    }

    //delete lexer
    delete(lexer);
    
    //close input file stream
    inputFile.close();
}