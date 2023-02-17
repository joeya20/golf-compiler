#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "util.hpp"
#include "parse.tab.hh"
#include "location.hh"

// from http://www.jonathanbeard.io/tutorials/FlexBisonC++
#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

// redeclaring lex function of Lexer;
// Thanks to Jared for showing me you can't rename it to yylex
#undef YY_DECL
#define YY_DECL GoLF::Parser::symbol_type GoLF::Lexer::lex()

extern std::string inputFileName;

namespace GoLF {

class Lexer : public yyFlexLexer {
    private:
        // vars needed because of semicolon insertion on new line and eof
        Parser::symbol_kind_type currentTokenKind;
        bool eofReached;

        // checks if a semicolon must be inserted based on currentTokenKind
        bool checkCurrentToken();

    public:
        GoLF::position startPos;

        // re-defined yylex() function that Flex implements
        Parser::symbol_type lex();

        // wrapper around lex() to do some internal stuff
        // gets called by bison parser
        Parser::symbol_type getNextToken();

        Lexer(std::istream& istream, std::ostream& ostream);

        static const char* symbolToString(const Parser::symbol_type& symbol);
};

}