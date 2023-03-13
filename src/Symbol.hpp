#pragma once

#include <string>
#include "location.hh"

namespace GoLF {

struct Symbol {
    std::string name;
    std::string sig;
    std::string rvSig;
    position pos;
    bool isType;
    bool isConst;

    Symbol(std::string& name, position& pos);
    Symbol(std::string& name, std::string& sig, std::string& rvSig, bool& isType, bool& isConst);
};

}