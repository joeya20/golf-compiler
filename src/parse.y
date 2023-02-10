%language "c++"
%require "3.2"  // needed to not generate position.hh and stack.hh
%locations

%code requires {
    #include<stdio.h>
    #include<stdlib.h>
    #include "location.hh"
    #include <string>

    //forward declaration needed because we are passing lexer as a param
    namespace GoLF {
        class Lexer;
    }
}   

%code top {
    #include <FlexLexer.h>
    #include "lexer.hpp"
    GoLF::Parser::symbol_type yylex(GoLF::Lexer &lexer) {
        return lexer.lex();
    }
}

%defines
%define api.parser.class { Parser }
%define api.namespace { GoLF }
%define api.token.constructor
%define api.value.type variant
%define parse.error verbose

%param { GoLF::Lexer &lexer }

// is the string necessary here?
%token <std::string>
    SEMICOLON   ";"
    LPAREN      "("
    RPAREN      ")"
    LBRACE      "{"
    RBRACE      "}"
    AND         "&&"
    EQ          "=="
    NEQ         "!="
    NOT         "!"
    OR          "||"
    LT          "<"
    LTE         "<="
    GT          ">"
    GTE         ">="
    ADD         "+"
    SUB         "-"
    MULT        "*"
    DIV         "/"
    MOD         "%"
    ASSIGN      "="
    COMMA       ","
    BREAK       "break"
    IF          "if"
    ELSE        "else"
    FOR         "for"
    FUNC        "func"
    RETURN      "return"
    VAR         "var"
    INT_LIT
    STR_LIT
    ID

/* %type <AstNode>  */

%start start

%%

start: 

%%

auto GoLF::Parser::error (const location_type& loc, const std::string& msg) -> void {
    std::cerr << msg << '\n';
}