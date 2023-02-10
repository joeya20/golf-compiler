%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "lexer.h"

// vars to store line and char no
int charno = 1;
int lineno = 1;

extern enum Token currentToken;
%}

/* always have noyywrap for school server */
%option noyywrap

%x STRING

letter  [a-zA-Z\_]
digit   [0-9]

%%
([/]{2})(.*)                    { /* ignore comments */ }
[\x20\x09\x0D]+                 { /* skip allowed (0x20, 0x09, 0x0D) whitespace */ charno += yyleng; }
\x0A                            {   // newline
                                    /* this might move in the future */
                                    if(currentToken != 0 && 
                                        (currentToken  == T_IDENTIFIER || 
                                        currentToken == T_INT_LIT || 
                                        currentToken == T_STR_LIT || 
                                        currentToken == T_BREAK || 
                                        currentToken == T_RETURN || 
                                        currentToken == T_RPAREN || 
                                        currentToken == T_RBRACE)) {
                                        yytext = "";
                                        unput('\n');
                                        return T_SEMICOLON;
                                    }
                                    charno = 1;
                                    ++lineno;
                                }
"break"                         { return T_BREAK; }
"if"                            { return T_IF; }
"else"                          { return T_ELSE; }
"for"                           { return T_FOR; }
"func"                          { return T_FUNC; }
"return"                        { return T_RETURN; }
"var"                           { return T_VAR; }
"&"                             { error(3, "Bitwise AND not supported in GoLF", lineno, charno); }
"&&"                            { return T_AND; }
"=="                            { return T_EQ; }
"!="                            { return T_NEQ; }
"!"                             { return T_NOT; }
"|"                             { error(3, "Bitwise OR not supported in GoLF", lineno, charno); }
"||"                            { return T_OR; }
"<"                             { return T_LT; }
"<="                            { return T_LTE; }
">"                             { return T_GT; }
">="                            { return T_GTE; }
"+"                             { return T_ADD; }
"-"                             { return T_SUB; }
"*"                             { return T_MULT; }
"/"                             { return T_DIV; }
"%"                             { return T_MOD; }
"="                             { return T_ASSIGN; }
","                             { return T_COMMA; }
";"                             { return T_SEMICOLON; }
"("                             { return T_LPAREN; }
")"                             { return T_RPAREN; }
"{"                             { return T_LBRACE; }
"}"                             { 
                                    /* this might move in the future */
                                    if(currentToken != 0 && currentToken != T_SEMICOLON) {
                                        yytext = "";
                                        unput('}');
                                        return T_SEMICOLON;
                                    }
                                    return T_RBRACE;
                                }
{letter}(({letter}|{digit})*)   { return T_IDENTIFIER; }
{digit}({digit}*)               { return T_INT_LIT; }
\"                              {
                                    // double-quote is the start of a string
                                    yymore();
                                    BEGIN(STRING);
                                }
<STRING>\"                      {  /* double-quote is the end of a string */ BEGIN(INITIAL); return T_STR_LIT; }
<STRING>[\\]{1}[bfnrt\"\\]{1}   {  /* valid escape character */ yymore(); }
<STRING>\\                      {
                                    // invalid escape character
                                    // check if newline or EOF is after; those take precedence but doesn't matter either way
                                    char badChar = input();
                                    if(badChar == 0) {
                                        error(2, "String literal terminated with EOF", lineno);
                                    }
                                    else if (badChar == 0x0A) {
                                        error(2, "Invalid newline in string literal", lineno);
                                    }
                                    else {
                                        char badString[] = {'\\', badChar, '\0'};
                                        error(4, "Invalid escape in string literal", lineno, yyleng+charno, badString);
                                    }
                                }
<STRING>\n                      { error(2, "Invalid newline in string literal", lineno); }
<STRING>.                       { yymore(); }
<STRING><<EOF>>                 { error(2, "String literal terminated with EOF", lineno); }
<<EOF>>                         {
                                    /* this might move in the future */
                                    if(currentToken != 0 && 
                                        (currentToken == T_IDENTIFIER || 
                                        currentToken == T_INT_LIT || 
                                        currentToken == T_STR_LIT || 
                                        currentToken == T_BREAK || 
                                        currentToken == T_RETURN || 
                                        currentToken == T_RPAREN || 
                                        currentToken == T_RBRACE)) {
                                        yytext = "";
                                        return T_SEMICOLON;
                                    }
                                    yyterminate();
                                }
\a                              {
                                    warning(4, "Skipping invalid character: ", lineno, charno, "\\a");
                                    charno += yyleng;
                                }
\b                              {
                                    warning(4, "Skipping invalid character: ", lineno, charno, "\\b");
                                    charno += yyleng;
                                }
\f                              {
                                    warning(4, "Skipping invalid character: ", lineno, charno, "\\f");
                                    charno += yyleng;
                                }
\v                              {
                                    warning(4, "Skipping invalid character: ", lineno, charno, "\\v");
                                    charno += yyleng;
                                }
\\                              {
                                    warning(4, "Skipping invalid character: ", lineno, charno, "\\\\");
                                    charno += yyleng;
                                }
\'                              {
                                    warning(4, "Skipping invalid character: ", lineno, charno, "\\'");
                                    charno += yyleng;
                                }                            
\0                              { 
                                    warning(3, "Skipping NUL character", lineno, charno);
                                    charno += yyleng;
                                }
[\x80-\xff]                     { 
                                    warning(3, "Skipping non-ascii character", lineno, charno);
                                    charno += yyleng;
                                }
.                               {
                                    warning(4, "Skipping invalid character: ", lineno, charno, yytext);
                                    charno += yyleng;
                                }
%%