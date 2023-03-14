#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include "location.hh"
#include "util.hpp"
#include "Symbol.hpp"

namespace GoLF {

class SymbolTable {
    private:
        std::vector<std::unordered_map<std::string, std::shared_ptr<Symbol>>> scopeStack;
    
    public:
        void insertUniverseBlock();
        void pushScope();
        std::unordered_map<std::string, std::shared_ptr<Symbol>> popScope();
        std::shared_ptr<Symbol> lookup(std::string name);
        std::shared_ptr<Symbol> define(std::string& name, location& loc);
};

} // namespace GoLF
