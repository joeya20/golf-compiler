#pragma once

#include <string>
#include <vector>
#include <array>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>

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

        int lineno;
        int startCol;
        int endCol;
        Kind kind;
        std::string attr;
        std::vector<AstNode*> children;

        AstNode(Kind kind);
        AstNode(Kind kind, std::string attr);
        AstNode(Kind kind, int lineno, int startCol, int endCol);
        AstNode(Kind kind, std::string attr, int lineno, int startCol, int endCol);
        ~AstNode();
        
        std::string toString(int tabSize = 0);

        void addChild(AstNode* child);
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