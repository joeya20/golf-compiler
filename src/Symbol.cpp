#include "Symbol.hpp"

namespace GoLF {

Symbol::Symbol(std::string& name, position& pos) {
    this->name = name;
    this->pos = pos;
}

Symbol::Symbol(std::string& name, std::string& sig, std::string& rvSig, bool& isConst, bool& isType) {
    this->name = name;
    this->sig = sig;
    this->rvSig = rvSig;
    this->isType = isType;
    this->isConst = isConst;
}

}