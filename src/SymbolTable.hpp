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
        SymbolTable();
        std::shared_ptr<const Symbol> lookup(std::string name);
        void define(std::string name, position pos);        
        void pushScope();
        std::unordered_map<std::string, std::shared_ptr<Symbol>> popScope();
};

} // namespace GoLF
