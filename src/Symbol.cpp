#include "Symbol.hpp"

namespace GoLF {

Symbol::Symbol(std::string& name, location& loc) {
    this->name = name;
    this->loc = loc;
}

Symbol::Symbol(std::string& name, location& loc, bool isType, bool isConst) {
    this->name = name;
    this->loc = loc;
    this->isType = isType;
    this->isConst = isConst; 
}

Symbol::Symbol(std::string& name, std::string& sig, std::string& rvSig, bool& isConst, bool& isType) {
    this->name = name;
    this->sig = sig;
    this->rvSig = rvSig;
    this->isType = isType;
    this->isConst = isConst;
}

}