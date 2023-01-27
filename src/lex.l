%{
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "lexer.h"

int charno = 0;
int lineno = 1;
extern enum Token currentToken;
%}

/* always have noyywrap for school server */
%option noyywrap
%option noinput

%x STRING

alph    [a-zA-Z]
alphNum [a-zA-Z0-9]
letter  [a-zA-Z\_]
digit   [0-9]

%%
([/]{2})(.*)                    { /* ignore comments */ }
[ \t]+                          { charno += yyleng; }
\n                              {
                                    /* this might move in the future */
                                    if(currentToken == T_IDENTIFIER || 
                                        currentToken == T_INT_LIT || 
                                        currentToken == T_STR_LIT || 
                                        currentToken == T_BREAK || 
                                        currentToken == T_RETURN || 
                                        currentToken == T_RPAREN || 
                                        currentToken == T_RBRACE) {
                                        yytext = "";
                                        unput('\n');
                                        return T_SEMICOLON;
                                    }
                                    charno = 0;
                                    ++lineno;
                                }
"break"                         { return T_BREAK; }
"if"                            { return T_IF; }
"else"                          { return T_ELSE; }
"for"                           { return T_FOR; }
"func"                          { return T_FUNC; }
"return"                        { return T_RETURN; }
"var"                           { return T_VAR; }
"&&"                            { return T_LOG_AND; }
"=="                            { return T_LOG_EQ; }
"!="                            { return T_LOG_NEQ; }
"!"                             { return T_LOG_NOT; }
"||"                            { return T_LOG_OR; }
"<"                             { return T_LOG_LT; }
"<="                            { return T_LOG_LTE; }
">"                             { return T_LOG_GT; }
">="                            { return T_LOG_GTE; }
"+"                             { return T_ADD; }
"-"                             { return T_SUB; }
"*"                             { return T_MULT; }
"/"                             { return T_DIV; }
"%"                             { return T_MOD; }
"="                             { return T_EQ; }
","                             { return T_COMMA; }
";"                             { return T_SEMICOLON; }
"("                             { return T_LPAREN; }
")"                             { return T_RPAREN; }
"{"                             { return T_LBRACE; }
"}"                             { return T_RBRACE; }
{letter}(({letter}|{digit})*)   { return T_IDENTIFIER; }
{digit}({digit}*)               { return T_INT_LIT; }
\"                              { yymore(); BEGIN(STRING); }
<STRING>\"                      { BEGIN(INITIAL); return T_STR_LIT; }
<STRING>\n                      { warning("Invalid string literal", lineno, charno); BEGIN(INITIAL); }
<STRING>.                       { yymore(); }
<<EOF>>                         {
                                    /* this might move in the future */
                                    if(currentToken == T_IDENTIFIER || 
                                        currentToken == T_INT_LIT || 
                                        currentToken == T_STR_LIT || 
                                        currentToken == T_BREAK || 
                                        currentToken == T_RETURN || 
                                        currentToken == T_RPAREN || 
                                        currentToken == T_RBRACE) {
                                        yytext = "";
                                        return T_SEMICOLON;
                                    }
                                    yyterminate();
                                }
.   { 
        charno += yyleng;
        warning("Invalid token in input file.", lineno, charno);
    }
%%