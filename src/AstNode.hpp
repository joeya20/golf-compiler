#pragma once

#include <string>
#include <vector>
#include <array>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <functional>
#include <sstream>

#include "location.hh"
#include "Symbol.hpp"

#define ARR_SIZE 50
#define TAB_SIZE 4

/* AST Structure is loosely based off of the Go language AST available here: https://pkg.go.dev/go/ast */
namespace GoLF {

    struct AstNode : std::enable_shared_from_this<AstNode> {
        // it is crucial that the ordering of the array is the same as the enum
        // as it is __just__ an array that we index into
        const std::array<const std::string, ARR_SIZE> nodeKindToString = {
            "Program",
            "AssignStmt",
            "ExprStmt",
            "EmptyStmt",
            "IfStmt",
            "ForStmt",
            "BreakStmt",
            "ReturnStmt",
            "FuncSign",
            "FuncCall",
            "FuncArgs",
            "Params",
            "ParamDecl",
            "Block",
            "GlobVarDecl",
            "VarDecl",
            "FuncDecl",
            "BinaryExpr",
            "UnaryExpr",
            "Ident",
            "Type",
            "IntLit",
            "StrLit"
        };


        typedef enum Kind {
            //children 0 to n: top level decls like funcs and globvars
            Program,
            /* stmts */
            // children[0] = lhs
            // children[1] = rhs
            AssignStmt,
            // children[0] = expr
            ExprStmt,
            // no children
            EmptyStmt,
            // children[0] = expr
            // children[1] = block
            // children[2] = IfStmt/block/None
            IfStmt,
            // children[0] = expr (Ident '$true' if missing)
            // children[1] = block
            ForStmt,
            // no children
            BreakStmt,
            // children[0] = Expr or None
            ReturnStmt,
            // children[0] = params
            // children[1] = Type ($void if missing)
            FuncSign,
            // children[0] = operand (Ident)
            // children[1] = FuncArgs
            FuncCall,
            // children 0 to N: expr
            FuncArgs,
            // children 0 to N: ParamDecl
            Params,
            // A defined function parameter
            // children[0] = Ident
            // children[1] = Type
            ParamDecl,
            // children 0 to N: Stmt
            Block,
            // children[0] = Ident
            // children[1] = Type
            GlobVarDecl,
            // children[0] = Ident
            // children[1] = Type
            VarDecl,
            // children[0] = Ident
            // children[1] = FuncSign
            // children[2] = Block
            FuncDecl,
            // children[0] = lhs
            // children[1] = rhs
            BinaryExpr,
            // children[0] = UnaryExpr or None
            // resolves to Operand (Ident, Int Lit, Str Lit) or FuncCall
            UnaryExpr,
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

        // populated in semantic analysis stage
        std::shared_ptr<Symbol> symbol = nullptr;
        std::string sig;    // return type for exprs; gets defined in pass 3 of semantic analysis

        // populated in codegen
        std::string reg;

        AstNode(Kind kind);
        AstNode(Kind kind, std::string attr);
        AstNode(Kind kind, location loc);
        AstNode(Kind kind, std::string attr, location loc);
        
        ~AstNode();
        
        std::string toString(int tabSize = 0);

        void addChild(std::shared_ptr<AstNode> child);
        
        // generic traversal functions
        template <class T>
        void preOrderTraversal(
            const T *t, 
            std::function<void(const T *, std::shared_ptr<AstNode>)> callback
        );
        template <class T>
        void postOrderTraversal(
            const T *t, 
            std::function<void(const T *, std::shared_ptr<AstNode>)> callback
        );
        template <class T>
        void prePostOrderTraversal(
            const T *t,
            std::function<void(const T *, std::shared_ptr<AstNode>)> preCallback,
            std::function<void(const T *, std::shared_ptr<AstNode>)> postCallback
        );
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