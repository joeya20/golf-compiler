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
    FuncSign
    FuncCall
    Params
    ParamList
    ParamDecl
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
//DONE
SourceFile  : %empty                    { root = new AstNode(AstNode::Kind::Program); }
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
                                    $$ = new AstNode(AstNode::Kind::GlobVarDecl, @$);
                                    AstNode *id = new AstNode(AstNode::Kind::Ident, $2, @2);
                                    $$->addChild(id);
                                    $$->addChild($3); 
                                }
        ;

//DONE
VarDecl : "var" ID Type { 
                            $$ = new AstNode(AstNode::Kind::VarDecl, @$);
                            AstNode *id = new AstNode(AstNode::Kind::Ident, $2, @2);
                            $$->addChild(id); 
                            $$->addChild($3); 
                        }
        ;

//DONE
Type    : ID    { 
                    $$ = new AstNode(AstNode::Kind::Type, $1, @$); 
                }
        ;

//DONE
FuncDecl    : "func" ID FuncSign Block  { 
                                            $$ = new AstNode(AstNode::Kind::FuncDecl, @$);
                                            AstNode* id = new AstNode(AstNode::Kind::Ident, $2, @$);
                                            $$->addChild(id);
                                            $$->addChild($3);
                                            $$->addChild($4);
                                        }
            ;

//DONE
FuncSign    : Params        { 
                                $$ = new AstNode(AstNode::Kind::FuncSign);
                                AstNode* type = new AstNode(AstNode::Kind::Type, "$void", @$); 
                                $$->addChild($1);
                                $$->addChild(type);
                            }
            | Params Type   {
                                $$ = new AstNode(AstNode::Kind::FuncSign);
                                $$->addChild($1);
                                $$->addChild($2);
                            }
            ;

//DONE
Params      : "(" ")"                   { $$ = new AstNode(AstNode::Kind::Params); }
            |  "(" ParamList ")"        { 
                                            $$ = new AstNode(AstNode::Kind::Params);
                                            $$->addChild($2);
                                        }
            |  "(" ParamList "," ")"    { 
                                            $$ = new AstNode(AstNode::Kind::Params);
                                            $$->addChild($2);
                                        }
            ;

//DONE
ParamList   : ParamDecl                 { 
                                            $$ = new AstNode(AstNode::Kind::ParamList);
                                            $$->addChild($1);
                                        }
            | ParamList "," ParamDecl   { 
                                            $1->addChild($3);
                                            $$ = $1;
                                        }
            ;

//DONE
ParamDecl   : ID Type   { 
                            $$ = new AstNode(AstNode::Kind::ParamDecl, @$);
                            AstNode* id = new AstNode(AstNode::Kind::Ident, $1, @1);
                            $$->addChild(id);
                            $$->addChild($2);
                        }
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
ReturnStmt  : "return"          { $$ = new AstNode(AstNode::Kind::ReturnStmt, @$); }
            | "return" Expr     { 
                                    $$ = new AstNode(AstNode::Kind::ReturnStmt, @$);
                                    $$->addChild($2);
                                }
            ;

//DONE
BreakStmt   : "break" { $$ = new AstNode(AstNode::Kind::BreakStmt, @$); }
            ;

//DONE
IfStmt      : "if" Expr Block           {
                                            $$ = new AstNode(AstNode::Kind::IfStmt);
                                            $$->addChild($2);
                                            $$->addChild($3);
                                        }
            | "if" Expr Block ElseStmt  {
                                            $$ = new AstNode(AstNode::Kind::IfStmt);
                                            $$->addChild($2);
                                            $$->addChild($3);
                                            $$->addChild($4);
                                        }
            ;

//DONE
ElseStmt    : "else" IfStmt             {
                                            // just return the IfStmt
                                            $$ = $2;
                                        }
            | "else" Block              {
                                            // just return the block
                                            $$ = $2;
                                        }
            ;

//DONE
ForStmt     : "for" Block       { 
                                    $$ = new AstNode(AstNode::Kind::ForStmt, @$);
                                    AstNode *e = new AstNode(AstNode::Kind::Ident, "$true", @$);
                                    $$->addChild(e);
                                    $$->addChild($2); 
                                }
            | "for" Expr Block  {
                                    $$ = new AstNode(AstNode::Kind::ForStmt, @$);
                                    //intentionally add Expr after Block
                                    $$->addChild($3);
                                    $$->addChild($2);
                                }
            ;

//DONE
EmptyStmt   : %empty  { $$ = new AstNode(AstNode::Kind::EmptyStmt, @$); }
            ;

//DONE
ExprStmt    : Expr  { 
                        $$ = new AstNode(AstNode::Kind::ExprStmt, @$);
                        $$->addChild($1); 
                    }
            ;

//DONE
AssignStmt  : Expr "=" Expr {   
                                $$ = new AstNode(AstNode::Kind::AssignStmt, @$); 
                                $$->addChild($1); 
                                $$->addChild($3);
                            }
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
                                            $$ = new AstNode(AstNode::Kind::BinaryExpr, $2, @$);
                                            $$->addChild($1);
                                            $$->addChild($3);
                                        }
            | AndExpr                   { $$ = $1; }
            ;

//DONE
AndExpr     : AndExpr "&&" RelExpr      {
                                            $$ = new AstNode(AstNode::Kind::BinaryExpr, $2, @$);
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
                                        $$ = $1;    
                                    }
            | UnaryOp UnaryExpr     {
                                        $$ = $1;
                                        $$->addChild($2);
                                    }
            ;

//DONE
PrimaryExpr     : Operand           { $$ = $1; }
                | FuncCall          { $$ = $1; }
                ;

//DONE
FuncCall        : Operand Arguments {
                                        $$ = new AstNode(AstNode::Kind::FuncCall, @$);
                                        $$->addChild($1);
                                        $$->addChild($2);
                                    }

//DONE
Arguments       : "(" ")"                   { $$ = new AstNode(AstNode::Kind::ExprList); }
                |  "(" ExprList ")"         { $$ = $2; }
                |  "(" ExprList "," ")"     { $$ = $2; }
                ;
                
//DONE
Operand         : INT_LIT       { $$ = new AstNode(AstNode::Kind::IntLit, $1, @$); }
                | STR_LIT       { $$ = new AstNode(AstNode::Kind::StrLit, $1, @$); }
                | ID            { $$ = new AstNode(AstNode::Kind::Ident, $1, @$); }
                | "(" Expr ")"  { $$ = $2; }
                ;

//DONE
UnaryOp     : "-"   { $$ = new AstNode(AstNode::Kind::UnaryExpr, $1, @$); }
            | "!"   { $$ = new AstNode(AstNode::Kind::UnaryExpr, $1, @$); }
            ;

//DONE
RelOp       : "=="  { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            | "!="  { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            | "<"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            | "<="  { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            | ">"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            | ">="  { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            ;

//DONE
AddOp       : "+"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            | "-"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            ;

//DONE
MultOp      : "*"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            | "/"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            | "%"   { $$ = new AstNode(AstNode::Kind::BinaryExpr, $1, @$); }
            ;
%%

//TODO: call error routine
void GoLF::Parser::error (const location_type& loc, const std::string& msg) {
    std::cerr << msg << " @ line " << loc.begin.line << '\n';
}