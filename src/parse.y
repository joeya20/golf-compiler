%language "c++"
%require "3.2"  //needed to not generate position.hh and stack.hh
%locations

%code requires {
    #include<stdio.h>
    #include<stdlib.h>
    #include "location.hh"
    #include "AstNode.hpp"
    #include "util.hpp"
    #include <string>
    #include <iostream>
    #include <memory>
    
    //forward declaration needed because we are passing lexer as a param
    namespace GoLF {
        class Lexer;
        // test
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
%parse-param { std::shared_ptr<GoLF::AstNode>& root }

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

%type <std::shared_ptr<AstNode>>
    TopLevelDecl
    GlobVarDecl
    VarDecl
    Type
    FuncDecl
    FuncSign
    FuncCall
    Params
    ParamList
    ParamDecl
    Operand
    PrimaryExpr
    FuncArgs
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
//DONE
SourceFile  : %empty                    { root = std::make_shared<AstNode>(AstNode::Kind::Program); }
            | SourceFile Program YYEOF  { /* Janky workaround; maybe fix one day */   }
            ;

//DONE
Program     : TopLevelDecl ";"          { root->addChild($1); }
            | Program TopLevelDecl ";"  { root->addChild($2); }
            ;

//DONE
TopLevelDecl    : GlobVarDecl   { $$ = $1; }
                | FuncDecl      { $$ = $1; }
                ;

//DONE
GlobVarDecl     : "var" ID Type {
                                    $$ = std::make_shared<AstNode>(AstNode::Kind::GlobVarDecl, @$);
                                    std::shared_ptr<AstNode> id = std::make_shared<AstNode>(AstNode::Kind::Ident, $2, @2);
                                    $$->addChild(id);
                                    $$->addChild($3);
                                }
                ;

//DONE
VarDecl : "var" ID Type {
                            $$ = std::make_shared<AstNode>(AstNode::Kind::VarDecl, @$);
                            std::shared_ptr<AstNode> id = std::make_shared<AstNode>(AstNode::Kind::Ident, $2, @2);
                            $$->addChild(id);
                            $$->addChild($3);
                        }
        ;

//DONE
Type    : ID    {
                    $$ = std::make_shared<AstNode>(AstNode::Kind::Type, $1, @$);
                }
        ;

//DONE
FuncDecl    : "func" ID FuncSign Block  {
                                            $$ = std::make_shared<AstNode>(AstNode::Kind::FuncDecl, @$);
                                            std::shared_ptr<AstNode> id = std::make_shared<AstNode>(AstNode::Kind::Ident, $2, @2);
                                            $$->addChild(id);
                                            $$->addChild($3);
                                            $$->addChild($4);
                                        }
            ;

//DONE
FuncSign    : Params        {
                                $$ = std::make_shared<AstNode>(AstNode::Kind::FuncSign);
                                std::shared_ptr<AstNode> type = std::make_shared<AstNode>(AstNode::Kind::Type, "$void");
                                $$->addChild($1);
                                $$->addChild(type);
                            }
            | Params Type   {
                                $$ = std::make_shared<AstNode>(AstNode::Kind::FuncSign);
                                $$->addChild($1);
                                $$->addChild($2);
                            }
            ;

//DONE
Params      : "(" ")"                   { $$ = std::make_shared<AstNode>(AstNode::Kind::Params); }
            |  "(" ParamList ")"        {
                                            $$ = $2;
                                        }
            |  "(" ParamList "," ")"    {
                                            $$ = $2;
                                        }
            ;

//DONE
ParamList   : ParamDecl                 {
                                            $$ = std::make_shared<AstNode>(AstNode::Kind::Params);
                                            $$->addChild($1);
                                        }
            | ParamList "," ParamDecl   {
                                            $1->addChild($3);
                                            $$ = $1;
                                        }
            ;

//DONE
ParamDecl   : ID Type   {
                            $$ = std::make_shared<AstNode>(AstNode::Kind::ParamDecl, @$);
                            std::shared_ptr<AstNode> id = std::make_shared<AstNode>(AstNode::Kind::Ident, $1, @1);
                            $$->addChild(id);
                            $$->addChild($2);
                        }
            ;

//DONE
Block       : "{" StmtList "}"  {
                                    $$ = $2;
                                }
            ;

//DONE
StmtList    : %empty            { $$ = std::make_shared<AstNode>(AstNode::Kind::Block); }
            | StmtList Stmt ";" {
                                    $1->addChild($2);
                                    $$ = $1;
                                }
            ;

//DONE
Stmt        : VarDecl       { $$ = $1; }
            | SimpleStmt    { $$ = $1; }
            | ReturnStmt    { $$ = $1; }
            | BreakStmt     { $$ = $1; }
            | Block         { $$ = $1; }
            | IfStmt        { $$ = $1; }
            | ForStmt       { $$ = $1; }
            ;

//DONE
SimpleStmt  : EmptyStmt     { $$ = $1; }
            | ExprStmt      { $$ = $1; }
            | AssignStmt    { $$ = $1; }
            ;

//DONE
ReturnStmt  : "return"      { $$ = std::make_shared<AstNode>(AstNode::Kind::ReturnStmt, @$); }
            | "return" Expr {
                                $$ = std::make_shared<AstNode>(AstNode::Kind::ReturnStmt, @$);
                                $$->addChild($2);
                            }
            ;

//DONE
BreakStmt   : "break" { $$ = std::make_shared<AstNode>(AstNode::Kind::BreakStmt, @$); }
            ;

//DONE
IfStmt      : "if" Expr Block           {
                                            $$ = std::make_shared<AstNode>(AstNode::Kind::IfStmt);
                                            $$->addChild($2);
                                            $$->addChild($3);
                                        }
            | "if" Expr Block ElseStmt  {
                                            $$ = std::make_shared<AstNode>(AstNode::Kind::IfStmt);
                                            $$->addChild($2);
                                            $$->addChild($3);
                                            $$->addChild($4);
                                        }
            ;

//DONE
ElseStmt    : "else" IfStmt {
                                // just return the IfStmt
                                $$ = $2;
                            }
            | "else" Block  {
                                // just return the block
                                $$ = $2;
                            }
            ;

//DONE
ForStmt     : "for" Block       {
                                    $$ = std::make_shared<AstNode>(AstNode::Kind::ForStmt, @$);
                                    std::shared_ptr<AstNode> unExpr = std::make_shared<AstNode>(AstNode::Kind::UnaryExpr, "");
                                    std::shared_ptr<AstNode> ident = std::make_shared<AstNode>(AstNode::Kind::Ident, "$true");
                                    unExpr->addChild(ident);
                                    $$->addChild(unExpr);
                                    $$->addChild($2);
                                }
            | "for" Expr Block  {
                                    $$ = std::make_shared<AstNode>(AstNode::Kind::ForStmt, @$);
                                    $$->addChild($2);
                                    $$->addChild($3);
                                }
            ;

//DONE
EmptyStmt   : %empty    { $$ = std::make_shared<AstNode>(AstNode::Kind::EmptyStmt, @$); }
            ;

//DONE
ExprStmt    : Expr  {
                        $$ = std::make_shared<AstNode>(AstNode::Kind::ExprStmt, @$);
                        $$->addChild($1);
                    }
            ;

//DONE
AssignStmt  : Expr "=" Expr {
                                $$ = std::make_shared<AstNode>(AstNode::Kind::AssignStmt, @$);
                                $$->addChild($1);
                                $$->addChild($3);
                            }
            ;

//DONE
Expr        : Expr "||" AndExpr         {
                                            $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $2, @$);
                                            $$->addChild($1);
                                            $$->addChild($3);
                                        }
            | AndExpr                   { $$ = $1; }
            ;

//DONE
AndExpr     : AndExpr "&&" RelExpr      {
                                            $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $2, @$);
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

//DONE
UnaryExpr   : PrimaryExpr           {
                                        $$ = std::make_shared<AstNode>(AstNode::Kind::UnaryExpr, "", @$);
                                        $$->addChild($1);
                                    }
            | UnaryOp UnaryExpr     {
                                        if($1->attr == "-" && 
                                        $2->kind == AstNode::Kind::IntLit && 
                                        $2->attr[0] != '-') {
                                            $$ = std::make_shared<AstNode>(AstNode::Kind::IntLit, "-" + $2->attr, @$);
                                        }
                                        else {
                                            $$ = $1;
                                            $$->addChild($2);
                                        }
                                    }
            ;

//DONE
PrimaryExpr     : Operand           { $$ = $1; }
                | FuncCall          { $$ = $1; }
                ;

//DONE
FuncCall        : PrimaryExpr FuncArgs  {
                                            $$ = std::make_shared<AstNode>(AstNode::Kind::FuncCall, @$);
                                            $$->addChild($1);
                                            $$->addChild($2);
                                        }
                ;

//DONE
FuncArgs        : "(" ")"                   { $$ = std::make_shared<AstNode>(AstNode::Kind::FuncArgs); }
                |  "(" ExprList ")"         {
                                                $$ = $2;
                                            }
                |  "(" ExprList "," ")"     {
                                                $$ = $2;
                                            }
                ;
//DONE
ExprList    : Expr              {
                                    $$ = std::make_shared<AstNode>(AstNode::Kind::FuncArgs);
                                    $$->addChild($1);
                                }
            | ExprList "," Expr {
                                    $1->addChild($3);
                                    $$ = $1;
                                }
            ;

//DONE
Operand         : INT_LIT       { $$ = std::make_shared<AstNode>(AstNode::Kind::IntLit, $1, @$); }
                | STR_LIT       { $$ = std::make_shared<AstNode>(AstNode::Kind::StrLit, $1, @$); }
                | ID            { $$ = std::make_shared<AstNode>(AstNode::Kind::Ident, $1, @$); }
                | "(" Expr ")"  { $$ = $2; }
                ;

//DONE
UnaryOp     : "-"   { $$ = std::make_shared<AstNode>(AstNode::Kind::UnaryExpr, "u-", @$); }
            | "!"   { $$ = std::make_shared<AstNode>(AstNode::Kind::UnaryExpr, $1, @$); }
            ;

//DONE
RelOp       : "=="  { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            | "!="  { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            | "<"   { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            | "<="  { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            | ">"   { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            | ">="  { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            ;

//DONE
AddOp       : "+"   { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            | "-"   { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            ;

//DONE
MultOp      : "*"   { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            | "/"   { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            | "%"   { $$ = std::make_shared<AstNode>(AstNode::Kind::BinaryExpr, $1, @$); }
            ;
%%

void GoLF::Parser::error (const location_type& loc, const std::string& msg) {
   GoLF::handleError(msg.c_str(), loc.begin.line, loc.begin.column);
}