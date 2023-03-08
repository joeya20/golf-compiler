#pragma once

#include <memory>
#include "AstNode.hpp"
#include "util.h"
#include <unordered_map>

namespace GoLF {
    struct SemanticAnalyzer {
        std::shared_ptr<AstNode> root;

        SemanticAnalyzer(std::shared_ptr<AstNode> root);
        // kickstarts analysis of AST
        void doAnalysis();
        // helper function to build symbol table
        void buildSymbolTable();
    };
}