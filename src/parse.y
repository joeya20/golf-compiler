
%language "c++"
%require "3.2"  // needed to not generate position.hh and stack.hh
%locations
%defines
%define api.parser.class { Parser }
%define api.namespace { GoLF }
%define parse.error verbose

%code requires {
    // prologue
    // you can put C code here as well!
    #include<stdio.h>
    #include<stdlib.h>

    int yylex(void);
}

%code top {
    #include "parse.tab.hh"
    #include "location.hh"
}

// declarations
%union {
    
}

/* %token <AstNode> T_EOF;
%token <AstNode> T_BREAK;
%token <AstNode> T_IF;
%token <AstNode> T_ELSE;
%token <AstNode> T_FOR;
%token <AstNode> T_FUNC;
%token <AstNode> T_RETURN;
%token <AstNode> T_VAR;
%token <AstNode> T_AND;
%token <AstNode> T_EQ;
%token <AstNode> T_NEQ;
%token <AstNode> T_NOT;
%token <AstNode> T_OR;
%token <AstNode> T_LT;
%token <AstNode> T_LTE;
%token <AstNode> T_GT;
%token <AstNode> T_GTE;
%token <AstNode> T_ADD;
%token <AstNode> T_SUB;
%token <AstNode> T_MULT;
%token <AstNode> T_DIV;
%token <AstNode> T_MOD;
%token <AstNode> T_ASSIGN;
%token <AstNode> T_COMMA;
%token <AstNode> T_SEMICOLON;
%token <AstNode> T_LPAREN;
%token <AstNode> T_RPAREN;
%token <AstNode> T_LBRACE;
%token <AstNode> T_RBRACE;
%token <AstNode> T_IDENTIFIER;
%token <AstNode> T_BOOL_LIT;
%token <AstNode> T_INT_LIT;
%token <AstNode> T_STR_LIT;
%token <AstNode> T_NEWLINE;

%type <myAst> addExpr mulExpr factor */

%start start

%%

start: 

%%

auto GoLF::Parser::error (const location_type& loc, const std::string& msg) -> void {
    std::cerr << msg << '\n';
}

int main() {
    GoLF::Parser parser;
    return parser();
}