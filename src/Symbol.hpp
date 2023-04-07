#pragma once

#include <string>
#include <vector>
#include "location.hh"

namespace GoLF {

struct Symbol {
    std::string name;
    std::string sig;
    std::string rvSig;
    location loc;
    bool isType;
    bool isConst;
    std::string reg;
    std::string label;
    Symbol(std::string& name, location& loc);
    Symbol(std::string& name, location& loc, bool isType, bool isConst);
    Symbol(std::string& name, std::string& sig, std::string& rvSig, std::string& asmLabel, bool& isType, bool& isConst);
};

}