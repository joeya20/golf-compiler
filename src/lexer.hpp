#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include "util.hpp"

// from http://www.jonathanbeard.io/tutorials/FlexBisonC++
#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

extern int colno;

class GoLFLexer : public yyFlexLexer {
    private:
        int yylex();
        
    public:
        // enum for token types
        enum Token : int {
            T_EOF = 0,
            T_BREAK,
            T_IF,
            T_ELSE,
            T_FOR,
            T_FUNC,
            T_RETURN,
            T_VAR,
            T_AND,
            T_EQ,
            T_NEQ,
            T_NOT,
            T_OR,
            T_LT,
            T_LTE,
            T_GT,
            T_GTE,
            T_ADD,
            T_SUB,
            T_MULT,
            T_DIV,
            T_MOD,
            T_ASSIGN,
            T_COMMA,
            T_SEMICOLON,
            T_LPAREN,
            T_RPAREN,
            T_LBRACE,
            T_RBRACE,
            T_IDENTIFIER,
            T_BOOL_LIT,
            T_INT_LIT,
            T_STR_LIT,
            T_NEWLINE
        };

        GoLFLexer(std::istream& istream, std::ostream& ostream);

        enum Token lex();

        static const char* tokenToString(const enum Token token);
};

#endif