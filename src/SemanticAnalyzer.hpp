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

        AllowedType(std::string lType, std::string rType, std::string returnType) : lType(lType), rType(rType), returnType(returnType) {}

        AllowedType(std::string lType, std::string returnType) : lType(lType), returnType(returnType) {}

        bool operator ==(const AllowedType& rhs) {
            return lType == rhs.lType && rType == rhs.rType && returnType == rhs.returnType;
        }
    };
    const static std::unordered_map<std::string, std::vector<AllowedType>> allowedTypes;
    std::shared_ptr<AstNode> root;
    SymbolTable symTab;

    // vector to hold paramDecls so their symbols fall in the proper scope
    std::vector<std::shared_ptr<AstNode>> paramDecls;

    SemanticAnalyzer(std::shared_ptr<AstNode> root);

    // generic pre-order traversal function
    void preOrderTraversal(std::shared_ptr<AstNode>, std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)>);
    // generic post-order traversal function
    void postOrderTraversal(std::shared_ptr<AstNode>, std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)>);

    // generic "pre-post-order" traversal function
    // aka do action on the way down and the way up
    void prePostOrderTraversal(std::shared_ptr<AstNode>, std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)>, std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)>);
    
    // kickstarts semantic analysis
    void doAnalysis();
    // declaring all callbacks as friend functions so it works easier with std::function
    // check declarations
    void pass1();
    void pass2();
    // check types
    friend void pass2PreOrderCallback(SemanticAnalyzer*, std::shared_ptr<AstNode>);
    friend void pass2PostOrderCallback(SemanticAnalyzer*, std::shared_ptr<AstNode>);
};

void pass2PreOrderCallback(SemanticAnalyzer*, std::shared_ptr<AstNode>);
void pass2PostOrderCallback(SemanticAnalyzer*, std::shared_ptr<AstNode>);
void checkType(std::shared_ptr<AstNode> node, std::shared_ptr<Symbol> type);
void checkIdent(std::shared_ptr<AstNode> node, std::shared_ptr<Symbol> ident);

}