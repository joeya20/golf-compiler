%{
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "lexer.h"

int charno = 0;
%}

/* flex declarations */

/* always have noyywrap for school server */
%option noyywrap
%option yylineno

/* rules; i.e. mapping of patterns (regex) to actions */
/* no return in actions will keep going; no tokens returned */
alph    [a-zA-Z]
alphNum [a-zA-Z0-9]
letter  [a-zA-Z\_]
digit   [0-9]

%%
[ \t]+                              { charno += yyleng; }
\n                                  { charno = 0; }
"break"                             { return T_BREAK; }
"if"                                { return T_IF; }
"else"                              { return T_ELSE; }
"for"                               { return T_FOR; }
"func"                              { return T_FUNC; }
"return"                            { return T_RETURN; }
"var"                               { return T_VAR; }
"&&"                                { return T_LOG_AND; }
"=="                                { return T_LOG_EQ; }
"!="                                { return T_LOG_NEQ; }
"!"                                 { return T_LOG_NOT; }
"||"                                { return T_LOG_OR; }
"<"                                 { return T_LOG_LT; }
"<="                                { return T_LOG_LTE; }
">"                                 { return T_LOG_GT; }
">="                                { return T_LOG_GTE; }
"+"                                 { return T_ADD; }
"-"                                 { return T_SUB; }
"*"                                 { return T_MULT; }
"/"                                 { return T_DIV; }
"%"                                 { return T_MOD; }
"="                                 { return T_EQ; }
","                                 { return T_COMMA; }
";"                                 { return T_SEMICOLON; }
"("                                 { return T_LPAREN; }
")"                                 { return T_RPAREN; }
"{"                                 { return T_LBRACE; }
"}"                                 { return T_RBRACE; }
{letter}(({letter}|{digit})*)       { return T_IDENTIFIER; }
{digit}({digit}*)                   { return T_INT_LIT; }

.   { 
        charno += yyleng;
        warning("Invalid token", yylineno, charno); 
    }
%%