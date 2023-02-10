%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.hpp"
#include "lexer.hpp"

// vars to store line and char no
int colno = 1;
bool eofReached = false;
extern enum GoLFLexer::Token currentToken;

%}

/* always have noyywrap for school server */
%option noyywrap
%option c++
%option yyclass="GoLFLexer"
%option yylineno

%x STRING

letter  [a-zA-Z\_]
digit   [0-9]

%%
([/]{2})(.*)                    { /* ignore comments */ }
[\x20\x09\x0D]+                 { /* skip allowed (0x20, 0x09, 0x0D) whitespace */ colno += YYLeng(); }
\x0A                            {   // newline
                                    /* this might move in the future */
                                    if(currentToken != GoLFLexer::Token::T_EOF && 
                                        (currentToken  == GoLFLexer::Token::T_IDENTIFIER || 
                                        currentToken == GoLFLexer::Token::T_INT_LIT || 
                                        currentToken == GoLFLexer::Token::T_STR_LIT || 
                                        currentToken == GoLFLexer::Token::T_BREAK || 
                                        currentToken == GoLFLexer::Token::T_RETURN || 
                                        currentToken == GoLFLexer::Token::T_RPAREN || 
                                        currentToken == GoLFLexer::Token::T_RBRACE)) {
                                        yyless(0);
                                        return GoLFLexer::Token::T_SEMICOLON;
                                    }
                                    colno = 1;
                                }
"break"                         { colno += YYLeng(); return GoLFLexer::Token::T_BREAK; }
"if"                            { colno += YYLeng(); return GoLFLexer::Token::T_IF; }
"else"                          { colno += YYLeng(); return GoLFLexer::Token::T_ELSE; }
"for"                           { colno += YYLeng(); return GoLFLexer::Token::T_FOR; }
"func"                          { colno += YYLeng(); return GoLFLexer::Token::T_FUNC; }
"return"                        { colno += YYLeng(); return GoLFLexer::Token::T_RETURN; }
"var"                           { colno += YYLeng(); return GoLFLexer::Token::T_VAR; }
"&"                             { error(3, "Bitwise AND not supported in GoLF", yylineno, colno); }
"&&"                            { colno += YYLeng(); return GoLFLexer::Token::T_AND; }
"=="                            { colno += YYLeng(); return GoLFLexer::Token::T_EQ; }
"!="                            { colno += YYLeng(); return GoLFLexer::Token::T_NEQ; }
"!"                             { colno += YYLeng(); return GoLFLexer::Token::T_NOT; }
"|"                             { error(3, "Bitwise OR not supported in GoLF", yylineno, colno); }
"||"                            { colno += YYLeng(); return GoLFLexer::Token::T_OR; }
"<"                             { colno += YYLeng(); return GoLFLexer::Token::T_LT; }
"<="                            { colno += YYLeng(); return GoLFLexer::Token::T_LTE; }
">"                             { colno += YYLeng(); return GoLFLexer::Token::T_GT; }
">="                            { colno += YYLeng(); return GoLFLexer::Token::T_GTE; }
"+"                             { colno += YYLeng(); return GoLFLexer::Token::T_ADD; }
"-"                             { colno += YYLeng(); return GoLFLexer::Token::T_SUB; }
"*"                             { colno += YYLeng(); return GoLFLexer::Token::T_MULT; }
"/"                             { colno += YYLeng(); return GoLFLexer::Token::T_DIV; }
"%"                             { colno += YYLeng(); return GoLFLexer::Token::T_MOD; }
"="                             { colno += YYLeng(); return GoLFLexer::Token::T_ASSIGN; }
","                             { colno += YYLeng(); return GoLFLexer::Token::T_COMMA; }
";"                             { colno += YYLeng(); return GoLFLexer::Token::T_SEMICOLON; }
"("                             { colno += YYLeng(); return GoLFLexer::Token::T_LPAREN; }
")"                             { colno += YYLeng(); return GoLFLexer::Token::T_RPAREN; }
"{"                             { colno += YYLeng(); return GoLFLexer::Token::T_LBRACE; }
"}"                             {
                                    /* this might move in the future */
                                    if(currentToken != GoLFLexer::Token::T_EOF && currentToken != GoLFLexer::Token::T_SEMICOLON) {
                                        yyless(0);
                                        return GoLFLexer::Token::T_SEMICOLON;
                                    }
                                    ++colno;
                                    return GoLFLexer::Token::T_RBRACE;
                                }
{letter}(({letter}|{digit})*)   { colno += YYLeng(); return GoLFLexer::Token::T_IDENTIFIER; }
{digit}({digit}*)               { colno += YYLeng(); return GoLFLexer::Token::T_INT_LIT; }
\"                              {
                                    // double-quote is the start of a string
                                    yymore();
                                    BEGIN(STRING);
                                }
<STRING>\"                      {  /* double-quote is the end of a string */ BEGIN(INITIAL); colno += YYLeng(); return GoLFLexer::Token::T_STR_LIT; }
<STRING>[\\]{1}[bfnrt\"\\]{1}   {  /* valid escape character */ yymore(); }
<STRING>\\                      {
                                    // invalid escape character
                                    // check if newline or EOF is after; those take precedence but doesn't matter either way
                                    char badChar = yyinput();
                                    if(badChar == 0) {
                                        error(3, "String literal terminated with EOF", yylineno, colno+YYLeng());
                                    }
                                    else if (badChar == 0x0A) {
                                        error(3, "Invalid newline in string literal", yylineno, colno+YYLeng());
                                    }
                                    else {
                                        char badString[] = {'\\', badChar, '\0'};
                                        error(4, "Invalid escape in string literal", yylineno, YYLeng()+colno, badString);
                                    }
                                }
<STRING>\n                      { error(3, "Invalid newline in string literal", yylineno, colno+YYLeng()-1); }
<STRING>.                       { yymore(); }
<STRING><<EOF>>                 { error(3, "String literal terminated with EOF", yylineno, colno+YYLeng()-1); }
<<EOF>>                         {
                                    /* this might move in the future */
                                    if(currentToken != GoLFLexer::Token::T_EOF && 
                                        (currentToken == GoLFLexer::Token::T_IDENTIFIER || 
                                        currentToken == GoLFLexer::Token::T_INT_LIT || 
                                        currentToken == GoLFLexer::Token::T_STR_LIT || 
                                        currentToken == GoLFLexer::Token::T_BREAK || 
                                        currentToken == GoLFLexer::Token::T_RETURN || 
                                        currentToken == GoLFLexer::Token::T_RPAREN || 
                                        currentToken == GoLFLexer::Token::T_RBRACE)) {
                                        eofReached = true;
                                        return GoLFLexer::Token::T_SEMICOLON;
                                    }
                                    yyterminate();
                                }
\a                              {
                                    warning(4, "Skipping invalid character: ", yylineno, colno, "\\a");
                                    colno += YYLeng();
                                }
\b                              {
                                    warning(4, "Skipping invalid character: ", yylineno, colno, "\\b");
                                    colno += YYLeng();
                                }
\f                              {
                                    warning(4, "Skipping invalid character: ", yylineno, colno, "\\f");
                                    colno += YYLeng();
                                }
\v                              {
                                    warning(4, "Skipping invalid character: ", yylineno, colno, "\\v");
                                    colno += YYLeng();
                                }
\\                              {
                                    warning(4, "Skipping invalid character: ", yylineno, colno, "\\\\");
                                    colno += YYLeng();
                                }
\'                              {
                                    warning(4, "Skipping invalid character: ", yylineno, colno, "\\'");
                                    colno += YYLeng();
                                }                            
\0                              { 
                                    warning(3, "Skipping NUL character", yylineno, colno);
                                    colno += YYLeng();
                                }
[\x80-\xff]                     { 
                                    warning(3, "Skipping non-ascii character", yylineno, colno);
                                    colno += YYLeng();
                                }
.                               {
                                    warning(4, "Skipping invalid character: ", yylineno, colno, yytext);
                                    colno += YYLeng();
                                }
%%