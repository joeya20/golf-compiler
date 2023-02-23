%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "util.hpp"
#include "parse.tab.hh"
#include "location.hh"
#include "lexer.hpp"
#include <iostream>

// filename from main to use for location
extern std::string inputFileName;
%}

/* always have noyywrap for school server */
%option noyywrap
%option c++
%option yyclass="Lexer"
%option yylineno

%x STRING

letter  [a-zA-Z\_]
digit   [0-9]

%%
([/]{2})(.*)                    { /* ignore comments */ }
[\x20\x09\x0D]+                 {   /* skip allowed (0x20, 0x09, 0x0D) whitespace */ 
                                    // colno += YYLeng();
                                    startPos.columns(YYLeng());
                                }
\x0A                            {   // newline
                                    if(checkCurrentToken()) {
                                        yyless(0);
                                        // create temp copy of startPos
                                        GoLF::position start = startPos;
                                        //increment startPos
                                        startPos.columns(1);
                                        //create location
                                        GoLF::location loc {start, startPos};
                                        return GoLF::Parser::make_SEMICOLON(std::string(""), loc);
                                    }
                                    // colno = 1;
                                    startPos.lines(1);
                                }
"break"                         {   
                                        // create temp copy of startPos
                                        GoLF::position start = startPos;
                                        //increment startPos
                                        startPos.columns(YYLeng());
                                        //create location
                                        GoLF::location loc {start, startPos};
                                        return GoLF::Parser::make_BREAK(std::string(yytext), loc);
                                }
"if"                            { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_IF(std::string(yytext), loc);
                                }
"else"                          { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_ELSE(std::string(yytext), loc);
                                }
"for"                           { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_FOR(std::string(yytext), loc);
                                }
"func"                          { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_FUNC(std::string(yytext), loc);
                                }
"return"                        { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_RETURN(std::string(yytext), loc);
                                }
"var"                           { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_VAR(std::string(yytext), loc); 
                                }
"&"                             { handleError(3, "Bitwise AND not supported in GoLF", startPos.line, startPos.column); }
"&&"                            { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_AND(std::string(yytext), loc);
                                }
"=="                            { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_EQ(std::string(yytext), loc);
                                }
"!="                            { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_NEQ(std::string(yytext), loc);
                                }
"!"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_NOT(std::string(yytext), loc);
                                }
"|"                             { handleError(3, "Bitwise OR not supported in GoLF", startPos.line, startPos.column); }
"||"                            { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_OR(std::string(yytext), loc);
                                }
"<"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_LT(std::string(yytext), loc);
                                }
"<="                            { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_LTE(std::string(yytext), loc);
                                }
">"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_GT(std::string(yytext), loc);
                                }
">="                            { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_GTE(std::string(yytext), loc);
                                }
"+"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_ADD(std::string(yytext), loc);
                                }
"-"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_SUB(std::string(yytext), loc);
                                }
"*"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_MULT(std::string(yytext), loc);
                                }
"/"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_DIV(std::string(yytext), loc);
                                }
"%"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_MOD(std::string(yytext), loc);
                                }
"="                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_ASSIGN(std::string(yytext), loc);
                                }
","                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_COMMA(std::string(yytext), loc);
                                }
";"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_SEMICOLON(std::string(yytext), loc);
                                }
"("                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_LPAREN(std::string(yytext), loc);
                                }
")"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_RPAREN(std::string(yytext), loc);
                                }
"{"                             { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_LBRACE(std::string(yytext), loc); 
                                }
"}"                             {
                                    if(currentTokenKind != Parser::symbol_kind_type::S_YYEOF && 
                                        currentTokenKind != Parser::symbol_kind_type::S_SEMICOLON) {
                                        yyless(0);
                                        // create temp copy of startPos
                                        GoLF::position start = startPos;
                                        //increment startPos
                                        startPos.columns(1);
                                        //create location
                                        GoLF::location loc {start, startPos};
                                        return GoLF::Parser::make_SEMICOLON(std::string(""), loc);
                                    }
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(1);
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_RBRACE(std::string(yytext), loc);
                                }
{letter}(({letter}|{digit})*)   { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_ID(std::string(yytext), loc); 
                                }
{digit}({digit}*)               { 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_INT_LIT(std::string(yytext), loc); 
                                }
\"                              {
                                    // double-quote is the start of a string
                                    yymore();
                                    BEGIN(STRING);
                                }
<STRING>\"                      {  // double-quote is the end of a string
                                    BEGIN(INITIAL); 
                                    // create temp copy of startPos
                                    GoLF::position start = startPos;
                                    //increment startPos
                                    startPos.columns(YYLeng());
                                    //create location
                                    GoLF::location loc {start, startPos};
                                    return GoLF::Parser::make_STR_LIT(std::string(yytext), loc); 
                                }
<STRING>[\\]{1}[bfnrt\"\\]{1}   {  /* valid escape character */ yymore(); }
<STRING>\\                      {
                                    // invalid escape character
                                    // check if newline or EOF is after; those take precedence but doesn't matter either way
                                    char badChar = yyinput();
                                    if(badChar == 0) {
                                        handleError(3, "String literal terminated with EOF", startPos.line, startPos.column+YYLeng());
                                    }
                                    else if (badChar == 0x0A) {
                                        handleError(3, "Invalid newline in string literal", startPos.line, startPos.column+YYLeng());
                                    }
                                    else {
                                        char badString[] = {'\\', badChar, '\0'};
                                        handleError(4, "Invalid escape in string literal", startPos.line, startPos.column+YYLeng(), badString);
                                    }
                                }
<STRING>\n                      { handleError(3, "Invalid newline in string literal", startPos.line, startPos.column+YYLeng()); }
<STRING>.                       { yymore(); }
<STRING><<EOF>>                 { handleError(3, "String literal terminated with EOF", startPos.line, startPos.column+YYLeng()); }
<<EOF>>                         {
                                    if(checkCurrentToken()) {
                                        eofReached = true;
                                        // create temp copy of startPos
                                        GoLF::position start = startPos;
                                        //increment startPos
                                        startPos.columns(1);
                                        //create location
                                        GoLF::location loc {start, startPos};
                                        return GoLF::Parser::make_SEMICOLON(std::string(""), loc);
                                    }
                                    return GoLF::Parser::make_YYEOF(GoLF::location(startPos));
                                }
\a                              {
                                    warning(4, "Skipping invalid character: ", startPos.line, startPos.column, "\\a");
                                    startPos.columns(YYLeng());
                                }
\b                              {
                                    warning(4, "Skipping invalid character: ", startPos.line, startPos.column+YYLeng(), "\\b");
                                    startPos.columns(YYLeng());
                                }
\f                              {
                                    warning(4, "Skipping invalid character: ", startPos.line, startPos.column+YYLeng(), "\\f");
                                    startPos.columns(YYLeng());
                                }
\v                              {
                                    warning(4, "Skipping invalid character: ", startPos.line, startPos.column+YYLeng(), "\\v");
                                    startPos.columns(YYLeng());
                                }
\\                              {
                                    warning(4, "Skipping invalid character: ", startPos.line, startPos.column+YYLeng(), "\\\\");
                                    startPos.columns(YYLeng());
                                }
\'                              {
                                    warning(4, "Skipping invalid character: ", startPos.line, startPos.column+YYLeng(), "\\'");
                                    startPos.columns(YYLeng());
                                }                            
\0                              { 
                                    warning(3, "Skipping NUL character", startPos.line, startPos.column+YYLeng());
                                    startPos.columns(YYLeng());
                                }
[\x80-\xff]                     { 
                                    warning(3, "Skipping non-ascii character", startPos.line, startPos.column+YYLeng());
                                    startPos.columns(YYLeng());
                                }
.                               {
                                    warning(4, "Skipping invalid character: ", startPos.line, startPos.column+YYLeng(), yytext);
                                    startPos.columns(YYLeng());
                                }
%%