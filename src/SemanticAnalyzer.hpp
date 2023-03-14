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
        SymbolTable symTab;

        SemanticAnalyzer(std::shared_ptr<AstNode> root);

        // kickstarts semantic analysis
        void doAnalysis();
        // declaring all callbacks as friend functions so it works easier with std::function
        // check declarations
        void pass1();
        // check types
        friend void pass2Callback(std::shared_ptr<AstNode> node);
    };
}