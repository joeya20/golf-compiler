#pragma once

#include <string>
#include "location.hh"

namespace GoLF {

struct Symbol {
    std::string name;
    std::string sig;
    std::string rvSig;
    location loc;
    bool isType;
    bool isConst;

    Symbol(std::string& name, location& loc);
    Symbol(std::string& name, location& loc, bool isType, bool isConst);
    Symbol(std::string& name, std::string& sig, std::string& rvSig, bool& isType, bool& isConst);
};

}