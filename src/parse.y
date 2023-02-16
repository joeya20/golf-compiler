%language "c++"
%require "3.2"  //needed to not generate position.hh and stack.hh
%locations

%code requires {
    #include<stdio.h>
    #include<stdlib.h>
    #include "location.hh"
    #include "AstNode.hpp"
    #include <string>
    #include <iostream>
    #include <memory>
    
    //forward declaration needed because we are passing lexer as a param
    namespace GoLF {
        class Lexer;
    }
}

%code top {
    #include <FlexLexer.h>
    #include "lexer.hpp"
    GoLF::Parser::symbol_type yylex(GoLF::Lexer &lexer) {
        return lexer.getNextToken();
    }
}

%defines
%define api.parser.class { Parser }
%define api.namespace { GoLF }
%define api.token.constructor
%define api.value.type variant
%define parse.error verbose

%param { Lexer &lexer }
%parse-param { AstNode *& root }

//I don't need to use strings for all but the last 3, but too late
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

%type <AstNode*>
    TopLevelDecl
    GlobVarDecl
    VarDecl
    Type
    FuncDecl
    FuncName
    FuncBody
    Signature
    Parameters
    ParameterList
    ParameterDecl
    Operand
    PrimaryExpr
    Arguments
    ExprList
    Expr
    AndExpr
    RelExpr
    AddExpr
    MultExpr
    UnaryExpr
    UnaryOp
    RelOp
    AddOp
    MultOp
    Block
    StmtList
    Stmt
    SimpleStmt
    ReturnStmt
    BreakStmt
    IfStmt
    ElseStmt
    ForStmt
    EmptyStmt
    ExprStmt
    AssignStmt

%start SourceFile

%%
//TODO
SourceFile  : %empty                       { root = new AstNode(AstNode::Kind::Program); }
            | SourceFile Program YYEOF     { /* Janky workaround; maybe fix one day */ }
            ;

Program     : TopLevelDecl ";"          { root->addChild($1); }
            | Program TopLevelDecl ";"  { root->addChild($2); }
            ;

//DONE
TopLevelDecl    : GlobVarDecl   { $$ = $1; }
                | FuncDecl      { $$ = $1; }
                ;

//DONE
GlobVarDecl     : "var" ID Type { 
                                    $$ = new AstNode(AstNode::Kind::GlobVarDecl);
                                    AstNode *id = new AstNode(AstNode::Kind::Ident, $2);
                                    $$->addChild(id); 
                                    $$->addChild($3); 
                                }
        ;
//DONE
VarDecl : "var" ID Type { 
                            $$ = new AstNode(AstNode::Kind::VarDecl);
                            AstNode *id = new AstNode(AstNode::Kind::Ident, $2);
                            $$->addChild(id); 
                            $$->addChild($3); 
                        }
        ;

//DONE
Type    : ID    { 
                    $$ = new AstNode(AstNode::Kind::Ident, $1); 
                }
        ;

//TODO
FuncDecl    : "func" FuncName Signature FuncBody { std::cout << "funcdecl" << std::endl; }
                ;

//DONE
//kind of redundant but w/e -- "more readable"
FuncName    : ID    { 
                            $$ = new AstNode(AstNode::Kind::Ident, $1); 
                        }
                ;

//DONE
//kind of redundant but w/e -- "more readable"
FuncBody    : Block {
                            $$ = $1;
                        }
                ;

//DONE
Signature       : Parameters        { 
                                        $$ = new AstNode(AstNode::Kind::FuncSignStmt);
                                        $$->addChild($1);
                                    }
                | Parameters ID     { 
                                        $$ = new AstNode(AstNode::Kind::FuncSignStmt);
                                        AstNode* id = new AstNode(AstNode::Kind::Ident, $2);
                                        $$->addChild($1);
                                        $$->addChild(id);
                                    }
                ;

//DONE
Parameters      : "(" ")"                       { $$ = new AstNode(AstNode::Kind::EmptyStmt); }
                |  "(" ParameterList ")"        { 
                                                    $$ = $2;
                                                }
                |  "(" ParameterList "," ")"    { 
                                                    $$ = $2;
                                                }
                ;

//DONE
ParameterList   : ParameterDecl                     { 
                                                        $$ = new AstNode(AstNode::Kind::ParameterList);
                                                        $$->addChild($1);
                                                    }
                | ParameterList "," ParameterDecl   { 
                                                        $1->addChild($3);
                                                        $$ = $1;
                                                    }
                ;

//DONE
ParameterDecl   : ID Type       { 
                                    $$ = new AstNode(AstNode::Kind::ParameterDecl);
                                    AstNode* id = new AstNode(AstNode::Kind::Ident, $1);
                                    $$->addChild(id);
                                    $$->addChild($2);
                                }
                ;

//DONE
Operand         : INT_LIT       { $$ = new AstNode(AstNode::Kind::IntLit, $1); }
                | STR_LIT       { $$ = new AstNode(AstNode::Kind::StrLit, $1); }
                | ID            { $$ = new AstNode(AstNode::Kind::Ident, $1); }
                | "(" Expr ")"  { $$ = $2; }
                ;

//TODO - check reference compiler
PrimaryExpr     : Operand                   { $$ = $1; }
                | PrimaryExpr Arguments     { std::cout << "prim" << std::endl; }
                ;

//TODO - check emptystmt and no arguments node handling
Arguments       : "(" ")"                   { $$ = new AstNode(AstNode::Kind::EmptyStmt); }
                |  "(" ExprList ")"         { $$ = $2; }
                |  "(" ExprList "," ")"     { $$ = $2; }
                ;

//DONE
ExprList    : Expr                  { 
                                        $$ = new AstNode(AstNode::Kind::ExprList);
                                        $$->addChild($1);
                                    }
            | ExprList "," Expr     { 
                                        $1->addChild($3);
                                        $$ = $1;
                                    }
            ;

//DONE
Expr        : Expr "||" AndExpr         {
                                            $$ = new AstNode(AstNode::Kind::BinaryExpr, $2);
                                            $$->addChild($1);
                                            $$->addChild($3);
                                        }
            | AndExpr                   { $$ = $1; }
            ;

//DONE
AndExpr     : AndExpr "&&" RelExpr      {
                                            $$ = new AstNode(AstNode::Kind::BinaryExpr, $2);
                                            $$->addChild($1);
                                            $$->addChild($3);
                                        }
            | RelExpr                   { $$ = $1; }
            ;

//DONE
RelExpr     : RelExpr RelOp AddExpr     {
                                            $$ = $2;
                                            $$->addChild($1);
                                            $$->addChild($3);
                                        }
            | AddExpr                   { $$ = $1; }
            ;

//DONE
AddExpr     : AddExpr AddOp MultExpr    {
                                            $$ = $2;
                                            $$->addChild($1);
                                            $$->addChild($3);
                                        }
            | MultExpr                  { $$ = $1; }
            ;

//DONE
MultExpr    : MultExpr MultOp UnaryExpr {
                                            $$ = $2;
                                            $$->addChild($1);
                                            $$->addChild($3);
                                        }
            | UnaryExpr                 { $$ = $1; }
            ;

//TODO
UnaryExpr   : PrimaryExpr           {
                                        //skip creating a redundant UnaryExpr node
                                        //and just point directly to the PrimaryExpr
                                        $$ = $1;    
                                    }
            | UnaryOp UnaryExpr     {
                                        $$ = $1;
                                        $$->addChild($2);
                                    }
            ;

//DONE
UnaryOp     : "-"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            | "!"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            ;

//DONE
RelOp       : "=="  { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            | "!="  { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            | "<"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            | "<="  { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            | ">"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            | ">="  { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            ;

//DONE
AddOp       : "+"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            | "-"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            ;

//DONE
MultOp      : "*"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            | "/"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            | "%"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1); }
            ;

//DONE
Block       : "{" StmtList "}"  { 
                                    $$ = new AstNode(AstNode::Block);
                                    $$->addChild($2);
                                }
            ;

//DONE
StmtList    : %empty            { $$ = new AstNode(AstNode::Kind::StmtList); }
            | StmtList Stmt ";" {
                                    $1->addChild($2);
                                    $$ = $1;
                                }
            ;

//DONE
Stmt        : VarDecl           { $$ = $1; }    
            | SimpleStmt        { $$ = $1; }        
            | ReturnStmt        { $$ = $1; }        
            | BreakStmt         { $$ = $1; }    
            | Block             { $$ = $1; }
            | IfStmt            { $$ = $1; }    
            | ForStmt           { $$ = $1; }    
            ;

//DONE
SimpleStmt  : EmptyStmt         { $$ = $1; }
            | ExprStmt          { $$ = $1; }
            | AssignStmt        { $$ = $1; }
            ;

//DONE
ReturnStmt  : "return"          { $$ = new AstNode(AstNode::Kind::ReturnStmt); }
            | "return" Expr     { 
                                    $$ = new AstNode(AstNode::Kind::ReturnStmt);
                                    $$->addChild($2);
                                }
            ;

//DONE
BreakStmt   : "break" { $$ = new AstNode(AstNode::Kind::BreakStmt); }
            ;

//TODO
IfStmt      : "if" Expr Block           { std::cout << "if" << std::endl; }
            | "if" Expr Block ElseStmt  { std::cout << "if" << std::endl; }
            ;

//TODO
ElseStmt    : "else" IfStmt             { std::cout << "else" << std::endl; }
            | "else" Block              { std::cout << "else" << std::endl; }
            ;

//DONE
ForStmt     : "for" Block       { 
                                    $$ = new AstNode(AstNode::Kind::ForStmt); 
                                    $$->addChild($2); 
                                }
            | "for" Expr Block  { 
                                    $$ = new AstNode(AstNode::Kind::ForStmt);
                                    //intentionally add Expr after Block
                                    $$->addChild($3);
                                    $$->addChild($2); 
                                }
            ;

//DONE
EmptyStmt   : %empty  { $$ = new AstNode(AstNode::Kind::EmptyStmt); }
            ;

//DONE
ExprStmt    : Expr  { 
                        $$ = new AstNode(AstNode::Kind::ExprStmt);
                        $$->addChild($1); 
                    }
            ;

//DONE
AssignStmt  : Expr "=" Expr {   
                                $$ = new AstNode(AstNode::Kind::AssignStmt); 
                                $$->addChild($1); 
                                $$->addChild($3);
                            }
            ;
%%

//TODO: call error routine
void GoLF::Parser::error (const location_type& loc, const std::string& msg) {
    std::cerr << msg << '\n';
}