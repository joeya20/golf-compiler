#include "SymbolTable.hpp"
#include "util.hpp"
#include <memory>
#include <unordered_map>

namespace GoLF {

void SymbolTable::insertUniverseBlock() {    
    // set up universe scope
    struct Entry {
        std::string name;
        std::string sig;
        std::string rvSig;
        std::string asmLabel;
        bool isConst;
        bool isType;
        Entry(std::string name, std::string sig, std::string rvSig, std::string asmLabel, bool isConst, bool isType)
        : name(name), sig(sig), rvSig(rvSig), asmLabel(asmLabel), isConst(isConst), isType(isType) {}
    };
    Entry temp[14] = {
        // name       sig           rvsig        asmLabel       isConst     isType
        {"$void",   "void",         ""      , "",           false,    true},
        {"bool" ,   "bool",         ""      , "",           false,    true},
        {"int",     "int",          ""      , "",           false,    true},
        {"string",  "string",       ""      , "",           false,    true},
        {"$true",   "bool",         ""      , "Ltrue",           true,     false},
        {"true",    "bool",         ""      , "Ltrue",           true,     false},
        {"false",   "bool",         ""      , "Lfalse",           true,     false},
        {"printb",  "f(bool)",      "void"  , "Lprintb",           false,    false},
        {"printc",  "f(int)",       "void"  , "Lprintc",           false,    false},
        {"printi",  "f(int)",       "void"  , "Lprinti",           false,    false},
        {"prints",  "f(string)",    "void"  , "Lprints",           false,    false},
        {"getchar", "f()",          "int"   , "LgetChar",           false,    false},
        {"halt",    "f()",          "void"  , "Lhalt",           false,    false},
        {"len",     "f(str)",       "int"   , "Llen",           false,    false},    //TODO: ask about this function
    };
    std::unordered_map<std::string, std::shared_ptr<Symbol>> universe;
    for(int i = 0; i < 14; ++i) {
        universe[temp[i].name] = std::make_shared<Symbol>(temp[i].name, temp[i].sig, temp[i].rvSig, temp[i].asmLabel, temp[i].isConst, temp[i].isType);
    }
    scopeStack.push_back(universe);
}

std::shared_ptr<Symbol> SymbolTable::lookup(std::string& name) {
    for(auto it = scopeStack.rbegin(); it!= scopeStack.rend(); ++it) {
        auto res = it->find(name);
        if(res != it->end()) {
            return res->second;
        }
    }
    return nullptr;
}

std::shared_ptr<Symbol> SymbolTable::define(std::string& name, location& loc, bool isType, bool isConst) {
    auto & currScope = scopeStack.back();
    if(currScope.find(name) == currScope.end()) {
        auto sym = std::make_shared<Symbol>(name, loc, isType, isConst);
        currScope[name] = sym;
        return sym;
    }
    std::string errorMsg = "identifier '" + name+ "' already defined" ; 
    handleError(errorMsg.c_str(), loc.begin.line, loc.begin.column);
    return nullptr; // silence warning
}

void SymbolTable::pushScope() {
    scopeStack.emplace_back();
}

std::unordered_map<std::string, std::shared_ptr<Symbol>> SymbolTable::popScope() {
    auto temp = scopeStack.back();
    scopeStack.pop_back();
    return temp;
} 

}