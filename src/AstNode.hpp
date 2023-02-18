#pragma once

#include <string>
#include <vector>
#include <array>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include "location.hh"
#include <memory>

#define ARR_SIZE 50
#define TAB_SIZE 4
/* AST Structure is loosely based off of the Go language AST available here: https://pkg.go.dev/go/ast */
namespace GoLF {

    struct AstNode {
        const std::array<const std::string, ARR_SIZE> nodeKindToString = {
            "Program",
            "AssignStmt",
            "ExprStmt",
            "EmptyStmt",
            "CondStmt",
            "IfStmt",
            "ForStmt",
            "BreakStmt",
            "ReturnStmt",
            "FuncSign",
            "FuncCall",
            "FuncArgs",
            "StmtList",
            "Params",
            "ParamList",
            "ParamDecl",
            "Block",
            "GlobVarDecl",
            "VarDecl",
            "FuncDecl",
            "ExprList",
            "BinaryExpr",
            "UnaryExpr",
            "PrimaryExpr",
            "Ident",
            "Type",
            "IntLit",
            "StrLit"
        };

        typedef enum Kind {
            //top level
            Program,
            // stmts
            AssignStmt,
            ExprStmt,
            EmptyStmt,
            CondStmt,
            IfStmt,
            ForStmt,
            BreakStmt,
            ReturnStmt,
            FuncSign,
            FuncCall,
            FuncArgs,
            StmtList,
            Params,
            ParamList,
            ParamDecl,
            Block,
            GlobVarDecl,
            VarDecl,
            FuncDecl,
            //exprs
            ExprList,
            BinaryExpr,
            UnaryExpr,
            PrimaryExpr,            
            // terminals aka symbols
            Ident,
            Type,   //special kind of identifier
            IntLit,
            StrLit
        } Kind;

        location loc;
        Kind kind;
        std::string attr;
        std::vector<std::shared_ptr<AstNode>> children;

        AstNode(Kind kind);
        AstNode(Kind kind, std::string attr);
        AstNode(Kind kind, location loc);
        AstNode(Kind kind, std::string attr, location loc);
        
        // nothing to really do here since we are using shared pointers
        // normally I would have to destroy the children before destroying the node
        ~AstNode();
        
        std::string toString(int tabSize = 0);

        void addChild(std::shared_ptr<AstNode> child);
    };

    std::ostream& operator<<(std::ostream& os, AstNode *node);

    // /********** Expressions ************/
    // struct Expr : public AstNode {

    // };

    // struct BinaryExpr : public Expr {

    // };

    // struct UnaryExpr : public Expr {
    //     typedef enum UnaryOp {
    //         NOP,    // no operation
    //         NEG,    // negative "-"
    //         NOT     // logical not
    //     } UnaryOp;

    //     Expr *expr;
    //     UnaryOp op;
    // };

    // /********** Statements *************/
    // struct Stmt : public AstNode {
        
    // };
    
    // struct AssignStmt : public AstNode {
    //     const Expr* l;
    //     const Expr* r;
    // };

    // struct ForStmt : public Stmt {
    //     const Expr* condition;
    //     const Stmt* body;
    // };

    // struct BreakStmt : public Stmt {
    //     //TODOs
    // };

    // struct ReturnStmt : public Stmt {
    //     // nullptr if no return expression
    //     AstNode *expr = nullptr;
    // };

    // struct FuncDeclStmt : public Stmt {
    //     const id* funcName;
    //     const 
    // };

    // struct ExprStmt : public Stmt {
    //     const AstNode *expr;
    // };
}