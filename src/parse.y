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
%start SourceFile

%%
SourceFile  : /* empty */
            | SourceFile TopLevelDeclaration ";"
            ;

TopLevelDeclaration     : Declaration 
                        | FunctionDeclaration
                        ;

Declaration : VarDeclaration
            ;

VarDeclaration      : "var" VarSpec
                    ;

VarSpec     : ID Type
            ;

Type        : TypeName
            ;

TypeName    : ID
            ;

FunctionDeclaration     : "func" FunctionName Signature FunctionBody
                        ;

FunctionName    : ID
                ;

FunctionBody    : Block
                ;

Signature       : Parameters
                | Parameters Result
                ;

Result          : Type
                ;

Parameters      : "(" ")"
                |  "(" ParameterList ")"
                |  "(" ParameterList "," ")"
                ;

ParameterList   : ParameterDeclaration
                | ParameterList "," ParameterDeclaration
                ;

ParameterDeclaration    : ID Type
                        ;

Operand         : Literal | OperandName | "(" Expression ")"
                ;

Literal         : BasicLiteral
                ;

BasicLiteral    : INT_LIT 
                | STR_LIT
                ;

OperandName     : ID
                ;

PrimaryExpression       : Operand 
                        | PrimaryExpression Arguments
                        ;

Arguments       : "(" ")"
                |  "(" ExpressionList ")"
                |  "(" ExpressionList "," ")"
                ;

ExpressionList  : Expression
                | ExpressionList "," Expression
                ;

Expression      : Expression "||" AndExpresion
                | AndExpresion 
                ;

AndExpresion    : AndExpresion "&&" RelationalExpression
                | RelationalExpression
                ;

RelationalExpression    : RelationalExpression RelationalOperation AdditionExpression
                        | AdditionExpression
                        ;

AdditionExpression  : AdditionExpression AdditionOperation MultiplicationExpression
                    | MultiplicationExpression
                    ;

MultiplicationExpression    : MultiplicationExpression MultiplicationOperation UnaryExpression
                            | UnaryExpression
                            ;

UnaryExpression : PrimaryExpression 
                | UnaryOperation UnaryExpression
                ;

UnaryOperation  : "-"
                | "!"
                ;

/* not used because of operation precedence but kept for now */
BinaryOperation : "||"
                | "&&"
                | RelationalOperation
                | AdditionOperation
                | MultiplicationOperation
                ;

RelationalOperation : "==" 
                    | "!="
                    | "<"
                    | "<="
                    | ">"
                    | ">="
                    ;

AdditionOperation   : "+"
                    | "-"
                    ;

MultiplicationOperation : "*"
                        | "/"
                        | "%"
                        ;

Block   : "{" StatementList "}"
        ;

StatementList   : /* empty */
                | StatementList Statement ";"
                ;

Statement   : Declaration
            | SimpleStatement
            | ReturnStatement
            | BreakStatement
            | Block
            | IfStatement
            | ForStatement
            ;

SimpleStatement : EmptyStatement
                | ExpressionStatement
                | AssignmentStatement
                ;
    
ReturnStatement : "return"
                | "return" Expression
                ;

BreakStatement  : "break"
                ;

IfStatement : "if" Expression Block
            | "if" Expression Block ElseStatement
            ;

ElseStatement   : "else" IfStatement
                | "else" Block
                ;

ForStatement    : "for" Block
                | "for" ConditionStatement Block
                ;

ConditionStatement  : Expression
                    ;

EmptyStatement  : /* empty */
                ;

ExpressionStatement : Expression;

AssignmentStatement : Expression "=" Expression
                    ;
%%

//TODO: call error routine
auto GoLF::Parser::error (const location_type& loc, const std::string& msg) -> void {
    std::cerr << msg << '\n';
}