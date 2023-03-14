#include "main.hpp"

std::string inputFileName;

int main(int argc, char **argv) {
    std::ifstream inputFile;

    //check that input file was provided
    if(argc == 1) {
        GoLF::handleError("No input file provided");
    }
    else if(argc == 2){        
        inputFileName = argv[1];
        inputFile.open(inputFileName);
    }
    else {
        GoLF::handleError("Too many input files provided");
    }
    //check that file was opened successfully
    if(!inputFile.is_open()) {
        GoLF::handleError("Error opening input file");
    }
    
    GoLF::Lexer lexer {inputFile, std::cout};
    std::shared_ptr<GoLF::AstNode> root;
    GoLF::Parser parser {lexer, root};
    parser();
    // std::cout << root << std::endl;
    
    GoLF::SemanticAnalyzer analyzer(root);
    analyzer.doAnalysis();
    std::cout << root << std::endl;
    // root->dfsPreOrderTraversal(&testDfs);

    //close input file stream
    inputFile.close();
}