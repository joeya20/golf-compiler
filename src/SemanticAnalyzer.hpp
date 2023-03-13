#pragma once

#include <unordered_map>
#include <array>
#include <memory>

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
        SemanticAnalyzer(std::shared_ptr<AstNode> root);

        // kickstarts analysis of AST
        void doAnalysis();
        // declaring callbacks as friend functions so it works with std::function
        // check declarations
        friend void pass1PreOrderCallback(std::shared_ptr<AstNode> node);
        friend void pass1PostOrderCallback(std::shared_ptr<AstNode> node);
        // check types
        friend void pass2Callback(std::shared_ptr<AstNode> node);
    };
}