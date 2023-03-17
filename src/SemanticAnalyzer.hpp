#pragma once

#include <unordered_map>
#include <array>
#include <memory>
#include <vector>

#include "AstNode.hpp"
#include "util.hpp"
#include "SymbolTable.hpp"

namespace GoLF {

struct SemanticAnalyzer {
    struct AllowedType {
        enum Kind {
            binary,
            unary
        } kind;
        std::string lType;
        // rtype is empty string for unary
        std::string rType;
        std::string returnType;

        AllowedType(std::string lType, std::string rType, std::string returnType) 
        : lType(lType), rType(rType), returnType(returnType) {}

        AllowedType(std::string lType, std::string returnType) 
        : lType(lType), returnType(returnType) {}

        AllowedType(std::string lType) 
        : lType(lType) {}
    };

    const static std::unordered_map<std::string, const std::string> returnTypes;
    const static std::vector<AllowedType> arithmeticTypes;
    const static std::vector<AllowedType> logicalEqualityTypes;
    const static std::vector<AllowedType> unaryNotTypes;
    const static std::vector<AllowedType> unaryMinusTypes;
    const static std::vector<AllowedType> comparisonTypes;
    const static std::vector<AllowedType> equalityTypes;
    const static std::vector<AllowedType> logicalTypes;
    const static std::unordered_map<std::string, const std::vector<AllowedType>*> allowedTypes;
    std::shared_ptr<AstNode> root;
    SymbolTable symTab;

    /* helper variables */
    // vector to hold paramDecls so their symbols fall in the proper scope for pass 2
    std::vector<std::shared_ptr<AstNode>> paramDecls;
    // counter to store number of for loops for pass 4
    int forLoopCount;
    //string to store the current funcDecl's rvSig for pass 4
    std::string funcReturnSig;

    SemanticAnalyzer(std::shared_ptr<AstNode> root);

    // generic pre-order traversal function
    void preOrderTraversal(std::shared_ptr<AstNode>, std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)>);
    // generic post-order traversal function
    void postOrderTraversal(std::shared_ptr<AstNode>, std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)>);

    // generic "pre-post-order" traversal function
    // aka do action on the way down and the way up
    void prePostOrderTraversal(std::shared_ptr<AstNode>, std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)>, std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)>);
    
    std::shared_ptr<Symbol> getIdent(std::shared_ptr<AstNode> node);

    // kickstarts semantic analysis
    void doAnalysis();
    void pass1();
    void pass2();
    void pass3();
    void pass4();
};

void pass2PreOrderCallback(SemanticAnalyzer*, std::shared_ptr<AstNode>);
void pass2PostOrderCallback(SemanticAnalyzer*, std::shared_ptr<AstNode>);
void pass3PostOrderCallback(SemanticAnalyzer*, std::shared_ptr<AstNode>); 
void pass4PreOrderCallback(SemanticAnalyzer*, std::shared_ptr<AstNode>);
void pass4PostOrderCallback(SemanticAnalyzer*, std::shared_ptr<AstNode>);
void checkType(std::shared_ptr<AstNode> node, std::shared_ptr<Symbol> type);
void checkIdent(std::shared_ptr<AstNode> node, std::shared_ptr<Symbol> ident);

}