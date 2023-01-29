#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>
#include <stdio.h>

extern int yyleng;
extern FILE *yyin;
extern char *yytext;
extern int charno;
extern int lineno;

enum Token {
    // it's important that this starts at 1
    // because EOF = 0
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
    T_LPAREN,
    T_RPAREN,
    T_LBRACE,
    T_RBRACE,
    T_IDENTIFIER,
    T_BOOL_LIT,
    T_INT_LIT,
    T_STR_LIT
};

int yylex(void);
int lex(void);

char const* tokenToString(const enum Token token);

#endif