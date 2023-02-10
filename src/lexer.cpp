#include "lexer.hpp"

namespace GoLF {

Lexer::Lexer(std::istream& istream, std::ostream& ostream): yyFlexLexer(istream, ostream) {}

// convert token enum to string for printing
const char* Lexer::symbolToString(const GoLF::Parser::symbol_type& symbol) {
    return "";
}

}