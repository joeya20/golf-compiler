#include "SemanticAnalyzer.hpp"
#include "location.hh"
#include <bits/types/struct_sched_param.h>
#include <memory>

namespace GoLF {
    // TODO: factor out common sets and only define once
    const std::unordered_map<std::string, std::vector<SemanticAnalyzer::AllowedType>> SemanticAnalyzer::allowedTypes {
        // binary operators
        {"||"   , { 
                AllowedType("bool", "bool", "bool"),
            }
        },
        {"&&"   , { 
                AllowedType("bool", "bool", "bool"),
            }
        },
        {"=="   , { 
                AllowedType("bool", "bool", "bool"),
                AllowedType("int", "int", "bool"),
                AllowedType("string", "string", "bool"),
            }
        },
        {"!="   , { 
                AllowedType("bool", "bool", "bool"),
                AllowedType("int", "int", "bool"),
                AllowedType("string", "string", "bool"),
            }
        },
        {"<"    , { 
                AllowedType("int", "int", "bool")
            }
        },
        {"<="   , { 
                AllowedType("int", "int", "bool")
            }
        },
        {">"    , { 
                AllowedType("int", "int", "bool")
            }
        },
        {">="   , { 
                AllowedType("int", "int", "bool")
            }
        },
        {"+"    , { 
                AllowedType("int", "int", "bool")
            }
        },
        {"-"    , { 
                AllowedType("int", "int", "bool")
            }
        },
        {"*"    , { 
                AllowedType("int", "int", "bool")
            }
        },
        {"/"    , { 
                AllowedType("int", "int", "bool")
            }
        },
        {"%"    , { 
                AllowedType("int", "int", "bool")
            }
        },
        //unary operators
        {"u-"   , { 
                AllowedType("int", "int")
            }
        },
        {"!"    , { 
                AllowedType("bool", "bool")
            }
        }
    };

    SemanticAnalyzer::SemanticAnalyzer(std::shared_ptr<AstNode> root) : root(root) {}

    void SemanticAnalyzer::preOrderTraversal(
    std::shared_ptr<AstNode> node,
    std::function<void(SemanticAnalyzer*,
    std::shared_ptr<AstNode>)> callback) {
        callback(this, node);
        for(size_t i = 0; i < node->children.size(); i++) {
            preOrderTraversal(node->children[i], callback);
        }
    }

    void SemanticAnalyzer::postOrderTraversal(
    std::shared_ptr<AstNode> node, 
    std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)> callback) {
        for(size_t i = 0; i < node->children.size(); i++) {
            postOrderTraversal(node->children[i], callback);
        }
        callback(this, node);
    }

    void SemanticAnalyzer::prePostOrderTraversal(
    std::shared_ptr<AstNode> node, 
    std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)> preCallback, 
    std::function<void(SemanticAnalyzer*, std::shared_ptr<AstNode>)> postCallback) {
        preCallback(this, node);
        for(size_t i = 0; i < node->children.size(); i++) {
            prePostOrderTraversal(node->children[i], preCallback, postCallback);
        }        
        postCallback(this, node);
    }

    using NodeKind = AstNode::Kind;
    /* Pass 1 */
    // gather global definitions
    // its not necessary to use the traversal engine for this
    // since we just need to check the children of the Program node
    void SemanticAnalyzer::pass1() {
        for(auto & topLevelDecl : root->children) {
            if(topLevelDecl->kind == NodeKind::GlobVarDecl) {
                auto IdentNode = topLevelDecl->children[0];
                auto symbol = symTab.define(IdentNode->attr, IdentNode->loc, false, false);
                // cannot determine type at this point
                // symbol->sig = topLevelDecl->children[1]->attr;
                topLevelDecl->symbol = symbol;
            }
            else if(topLevelDecl->kind == NodeKind::FuncDecl) {
                auto IdentNode = topLevelDecl->children[0];
                auto symbol = symTab.define(IdentNode->attr, IdentNode->loc, false, false);
                // cannot determine type at this point
                // symbol->rvSig = topLevelDecl->children[1]->attr;
                topLevelDecl->symbol = symbol;
            }
            else {
                // this should be a parser error but here just in case
                handleError("unexpected node kind under program node!");
            }
        }
    }

    /* Pass 2 */
    void SemanticAnalyzer::pass2() {
        prePostOrderTraversal(this->root, pass2PreOrderCallback, pass2PostOrderCallback);
    }

    void checkType(std::shared_ptr<AstNode> node, std::shared_ptr<Symbol> type) {
        if(type == nullptr) {
            handleInvalidType(node->children[1]->attr, node->children[1]->loc);
        }
        // the symbol was overridden and is no longer a type
        if(!type->isType) {
            handleInvalidType(type->name, type->loc);
        }
    }

    void checkIdent(std::shared_ptr<AstNode> node, std::shared_ptr<Symbol> ident) {
        if(ident == nullptr) {
            std::string errorMsg = "Identifier '" + node->attr + "' is not defined.";
            handleError(errorMsg.c_str(), node->loc.begin.line, node->loc.begin.column);
        }
        if(ident->isType) {
           std::string errorMsg = "Got type '" + ident->name + "', was expecting identifier.";
            handleError(errorMsg.c_str(), ident->loc.begin.line, ident->loc.begin.column);
        }
        // I guess the reference compiler doenst check for this
        // if(ident->isConst) {
        //     errorMsg = "Cannot assign to constant'" + symbol->name + "'";
        //     handleError(errorMsg.c_str());
        // }
    }

    void pass2PreOrderCallback(SemanticAnalyzer* anal /* lol */, std::shared_ptr<AstNode> node) {
        std::string errorMsg;
        switch (node->kind)
        {
        case NodeKind::GlobVarDecl: { // DONE
            std::cout << "GlobVarDecl" << std::endl;
            /* fully define symbol (i.e. type) */
            auto type = anal->symTab.lookup(node->children[1]->attr);
            // the type does not exist
            checkType(node, type);
            // update node's symbol with sig
            node->symbol->sig = type->name;
            break;
        }
        case NodeKind::FuncDecl: { // TODO
            /* fully define symbol (i.e. type and rv type)*/
            auto funcSign = node->children[1];
            // handle return value
            auto rvType = anal->symTab.lookup(funcSign->children[1]->attr);
            checkType(funcSign->children[1], rvType);
            node->symbol->rvSig = rvType->name;
            // update rv identifier node
            funcSign->children[1]->symbol = rvType;
            // handle param values
            std::string type = "f(";
            for(auto & paramDecl : funcSign->children[0]->children) {
                // copy constructor would do practically the same thing so we might as well do it here
                anal->paramDecls.push_back(paramDecl);
                auto paramType = anal->symTab.lookup(paramDecl->children[1]->attr);
                checkType(paramDecl, paramType);
                type += (paramType->name + ",");
            }
            type += ")";
            node->symbol->sig = type;
            break;
        }
        case NodeKind::VarDecl: { // DONE
            auto ident = anal->symTab.define(node->children[0]->attr, node->children[0]->loc, false, false);
            node->symbol = ident;
            auto type = anal->symTab.lookup(node->children[1]->attr);
            checkType(node, type);
            ident->sig = type->name;
            node->children[1]->symbol = type;
            break;
        }
        case NodeKind::AssignStmt: {
            std::cout << "AssignStmt" << std::endl;
            /* check for symbol */
            auto lhs = node->children[0];
            auto ident = anal->symTab.lookup(lhs->attr);
            checkIdent(lhs, ident);
            lhs->symbol = ident;
            break;
        }
        case NodeKind::BinaryExpr: {
            auto lhs = node->children[0];
            if(lhs->kind == NodeKind::Ident) {
                auto ident = anal->symTab.lookup(lhs->attr);
                checkIdent(lhs, ident);
                lhs->symbol = ident;
            }
            auto rhs = node->children[1];
            if(rhs->kind == NodeKind::Ident) {
                auto ident = anal->symTab.lookup(rhs->attr);
                checkIdent(rhs, ident);
                rhs->symbol = ident;
            }
            break;
        }
        case NodeKind::UnaryExpr: {
            // funccalls are handled in their own case stmt
            auto expr = node->children[0];
            if(expr->kind == NodeKind::Ident) {
                auto ident = anal->symTab.lookup(expr->attr);
                checkIdent(expr, ident);
                expr->symbol = ident;
            }
            break;
        }
        case NodeKind::FuncCall: {
            auto expr = node->children[0]; 
            auto ident = anal->symTab.lookup(expr->attr);
            checkIdent(expr, ident);
            expr->symbol = ident;
            break;            
        }
        case NodeKind::Block:
            /* create new scope */
            anal->symTab.pushScope();
            // need to add params to this block scope
            // in case this block is for a FuncDecl
            while(anal->paramDecls.size() > 0) {
                auto paramDecl = anal->paramDecls.back();
                auto ident = paramDecl->children[0];
                auto type = paramDecl->children[1];
                auto identSymbol = anal->symTab.define(ident->attr, ident->loc, false, false);
                auto typeSymbol = anal->symTab.lookup(type->attr);
                checkType(type, typeSymbol);
                identSymbol->sig = typeSymbol->name;
                type->symbol = typeSymbol;
                ident->symbol = identSymbol;
                anal->paramDecls.pop_back();
            }
            break;
        default:
            break;
        }
    }

    void pass2PostOrderCallback(SemanticAnalyzer* anal /* lol */, std::shared_ptr<AstNode> node) {
        switch (node->kind)
        {
        case NodeKind::Block:
            anal->symTab.popScope();
            break;
        default:

            break;
        }
    }

    void SemanticAnalyzer::doAnalysis() {
        this->symTab.insertUniverseBlock();
        this->symTab.pushScope();
        // first pass -- add global declarations
        this->pass1();
        // second pass -- handle all identifiers
        this->pass2();
        std::string main = "main";
        auto mainFunc = symTab.lookup(main);
        if(mainFunc == nullptr) {
            handleError("missing main() function");
        }
        root->symbol = mainFunc;
        // third pass -- handle type checking
        // fourth pass -- clean up random checks
    }
}