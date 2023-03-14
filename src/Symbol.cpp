#include "Symbol.hpp"

namespace GoLF {

Symbol::Symbol(std::string& name, location& loc) {
    this->name = name;
    this->loc = loc;
}

Symbol::Symbol(std::string& name, std::string& sig, std::string& rvSig, bool& isConst, bool& isType) {
    this->name = name;
    this->sig = sig;
    this->rvSig = rvSig;
    this->isType = isType;
    this->isConst = isConst;
}

}