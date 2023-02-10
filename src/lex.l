%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "util.hpp"
#include "parse.tab.hh"
#include "location.hh"
#include "lexer.hpp"

// vars to store line and char no
int colno = 1;
bool eofReached = false;
// extern enum Lexer::Token currentToken;

// using namespace GoLF;
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
[\x20\x09\x0D]+                 { /* skip allowed (0x20, 0x09, 0x0D) whitespace */ colno += YYLeng(); }
\x0A                            {   // newline
                                    /* this might move in the future */
                                    // if(currentToken != Lexer::Token::T_EOF && 
                                    //     (currentToken  == Lexer::Token::T_IDENTIFIER || 
                                    //     currentToken == Lexer::Token::T_INT_LIT || 
                                    //     currentToken == Lexer::Token::T_STR_LIT || 
                                    //     currentToken == Lexer::Token::T_BREAK || 
                                    //     currentToken == Lexer::Token::T_RETURN || 
                                    //     currentToken == Lexer::Token::T_RPAREN || 
                                    //     currentToken == Lexer::Token::T_RBRACE)) {
                                    //     yyless(0);
                                    //     return GoLF::Parser::make_SEMICOLON(std::string(yytext), GoLF::location());
                                    // }
                                    colno = 1;
                                }
"break"                         { colno += YYLeng(); return GoLF::Parser::make_BREAK(std::string(yytext), GoLF::location()); }
"if"                            { colno += YYLeng(); return GoLF::Parser::make_IF(std::string(yytext), GoLF::location()); }
"else"                          { colno += YYLeng(); return GoLF::Parser::make_ELSE(std::string(yytext), GoLF::location()); }
"for"                           { colno += YYLeng(); return GoLF::Parser::make_FOR(std::string(yytext), GoLF::location()); }
"func"                          { colno += YYLeng(); return GoLF::Parser::make_FUNC(std::string(yytext), GoLF::location()); }
"return"                        { colno += YYLeng(); return GoLF::Parser::make_RETURN(std::string(yytext), GoLF::location()); }
"var"                           { colno += YYLeng(); return GoLF::Parser::make_VAR(std::string(yytext), GoLF::location()); }
"&"                             { error(3, "Bitwise AND not supported in GoLF", yylineno, colno); }
"&&"                            { colno += YYLeng(); return GoLF::Parser::make_AND(std::string(yytext), GoLF::location()); }
"=="                            { colno += YYLeng(); return GoLF::Parser::make_EQ(std::string(yytext), GoLF::location()); }
"!="                            { colno += YYLeng(); return GoLF::Parser::make_NEQ(std::string(yytext), GoLF::location()); }
"!"                             { colno += YYLeng(); return GoLF::Parser::make_NOT(std::string(yytext), GoLF::location()); }
"|"                             { error(3, "Bitwise OR not supported in GoLF", yylineno, colno); }
"||"                            { colno += YYLeng(); return GoLF::Parser::make_OR(std::string(yytext), GoLF::location()); }
"<"                             { colno += YYLeng(); return GoLF::Parser::make_LT(std::string(yytext), GoLF::location()); }
"<="                            { colno += YYLeng(); return GoLF::Parser::make_LTE(std::string(yytext), GoLF::location()); }
">"                             { colno += YYLeng(); return GoLF::Parser::make_GT(std::string(yytext), GoLF::location()); }
">="                            { colno += YYLeng(); return GoLF::Parser::make_GTE(std::string(yytext), GoLF::location()); }
"+"                             { colno += YYLeng(); return GoLF::Parser::make_ADD(std::string(yytext), GoLF::location()); }
"-"                             { colno += YYLeng(); return GoLF::Parser::make_SUB(std::string(yytext), GoLF::location()); }
"*"                             { colno += YYLeng(); return GoLF::Parser::make_MULT(std::string(yytext), GoLF::location()); }
"/"                             { colno += YYLeng(); return GoLF::Parser::make_DIV(std::string(yytext), GoLF::location()); }
"%"                             { colno += YYLeng(); return GoLF::Parser::make_MOD(std::string(yytext), GoLF::location()); }
"="                             { colno += YYLeng(); return GoLF::Parser::make_ASSIGN(std::string(yytext), GoLF::location()); }
","                             { colno += YYLeng(); return GoLF::Parser::make_COMMA(std::string(yytext), GoLF::location()); }
";"                             { colno += YYLeng(); return GoLF::Parser::make_SEMICOLON(std::string(yytext), GoLF::location()); }
"("                             { colno += YYLeng(); return GoLF::Parser::make_LPAREN(std::string(yytext), GoLF::location()); }
")"                             { colno += YYLeng(); return GoLF::Parser::make_RPAREN(std::string(yytext), GoLF::location()); }
"{"                             { colno += YYLeng(); return GoLF::Parser::make_LBRACE(std::string(yytext), GoLF::location()); }
"}"                             {
                                    /* this might move in the future */
                                    // if(currentToken != Lexer::Token::T_EOF && currentToken != Lexer::Token::T_SEMICOLON) {
                                    //     yyless(0);
                                    //     return Lexer::Token::T_SEMICOLON;
                                    // }
                                    ++colno;
                                    return GoLF::Parser::make_RBRACE(std::string(yytext), GoLF::location());;
                                }
{letter}(({letter}|{digit})*)   { colno += YYLeng(); return GoLF::Parser::make_ID(std::string(yytext), GoLF::location()); }
{digit}({digit}*)               { colno += YYLeng(); return GoLF::Parser::make_INT_LIT(std::string(yytext), GoLF::location()); }
\"                              {
                                    // double-quote is the start of a string
                                    yymore();
                                    BEGIN(STRING);
                                }
<STRING>\"                      {  /* double-quote is the end of a string */ BEGIN(INITIAL); colno += YYLeng(); return GoLF::Parser::make_STR_LIT(std::string(yytext), GoLF::location()); }
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
                                    // if(currentToken != Lexer::Token::T_EOF && 
                                    //     (currentToken == Lexer::Token::T_IDENTIFIER || 
                                    //     currentToken == Lexer::Token::T_INT_LIT || 
                                    //     currentToken == Lexer::Token::T_STR_LIT || 
                                    //     currentToken == Lexer::Token::T_BREAK || 
                                    //     currentToken == Lexer::Token::T_RETURN || 
                                    //     currentToken == Lexer::Token::T_RPAREN || 
                                    //     currentToken == Lexer::Token::T_RBRACE)) {
                                    //     eofReached = true;
                                    //     return GoLF::Parser::make_SEMICOLON(std::string(yytext), GoLF::location());
                                    // }
                                    // yyterminate();
                                    GoLF::Parser::make_YYEOF(GoLF::location());
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