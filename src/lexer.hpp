#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "util.hpp"
#include "parse.tab.hh"

// from http://www.jonathanbeard.io/tutorials/FlexBisonC++
#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

// redeclaring lex function of Lexer;
// Thanks to Jared for showing me you can't rename it to yylex
#undef YY_DECL
#define YY_DECL GoLF::Parser::symbol_type GoLF::Lexer::lex()

extern int colno;
namespace GoLF {

class Lexer : public yyFlexLexer {
    public:
        GoLF::Parser::symbol_type lex();

        Lexer(std::istream& istream, std::ostream& ostream);

        static const char* symbolToString(const GoLF::Parser::symbol_type& symbol);
};

}

#endif