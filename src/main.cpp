#include "main.hpp"

std::string inputFileName;

int main(int argc, char **argv) {
    std::ifstream inputFile;

    //check that input file was provided
    if(argc == 1) {
        error(1, "No input file provided");
    }
    else if(argc == 2){        
        inputFileName = argv[1];
        inputFile.open(inputFileName);
    }
    else {
        error(1, "Too many input files provided");
    }
    //check that file was opened successfully
    if(!inputFile.is_open()) {
        error(1, "Error opening input file");
    }
    
    GoLF::Lexer lexer {inputFile, std::cout};
    GoLF::AstNode *root;
    GoLF::Parser parser {lexer, root};

    parser();
    std::cout << root << std::endl;
    
    // tear down ast
    //root will never be null :)
    delete root;

    //close input file stream
    inputFile.close();
}