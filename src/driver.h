#ifndef DRIVER_H
#define DRIVER_H

#include <stdio.h>
#include <iostream>
#include <fstream>

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

enum Token {
    // it's important that this starts at 1
    T_BREAK = 1,
    T_IF,
    T_ELSE,
    T_FOR,
    T_FUNC,
    T_RETURN,
    T_VAR,
    T_LOG_AND,
    T_LOG_EQ,
    T_LOG_NEQ,
    T_LOG_NOT,
    T_LOG_OR,
    T_LOG_LT,
    T_LOG_LTE,
    T_LOG_GT,
    T_LOG_GTE,
    T_ADD,
    T_SUB,
    T_MULT,
    T_DIV,
    T_MOD,
    T_EQ,
    T_COMMA,
    T_SEMICOLON,
    T_OP_BRACKET,
    T_CL_BRACKET,
    T_OP_CUR_BRACKET,
    T_CL_CUR_BRACKET,
    T_IDENTIFIER,
    T_INT_LIT,
    T_STR_LIT
};

#endif