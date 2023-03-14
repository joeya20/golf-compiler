#include "SemanticAnalyzer.hpp"
#include "location.hh"

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

    void pass2PreOrderCallback(SemanticAnalyzer* anal /* lol */, std::shared_ptr<AstNode> node) {
        std::string errorMsg;
        switch (node->kind)
        {
        case NodeKind::GlobVarDecl: {// DONE
            std::cout << "GlobVarDecl" << std::endl;
            /* fully define symbol (i.e. type) */
            auto type = anal->symTab.lookup(node->children[1]->attr);
            // the type does not exist
            if(type == nullptr) {
                handleInvalidType(node->children[1]->attr, node->children[1]->loc);
            }
            // the symbol was overridden and is no longer a type
            if(!type->isType) {
                handleInvalidType(type->name, type->loc);
            }
            // update node's symbol with sig
            node->symbol->sig = type->name;
            break;
        }
        // case NodeKind::FuncDecl:    // TODO
        //     /* fully define symbol */
        //     symbol = anal->symTab.lookup(node->children[1]->attr);
        //     // the type does not exist
        //     if(symbol == nullptr) {
        //         handleInvalidType(node->children[1]->attr, node->children[1]->loc);
        //     }
        //     // check if identifier is a type
        //     if(!symbol->isType) {
        //         handleInvalidType(symbol->name, symbol->loc);
        //     }
        //     break;
        case NodeKind::VarDecl: { // DONE
            auto ident = anal->symTab.define(node->children[0]->attr, node->children[0]->loc, false, false);
            node->children[0]->symbol = ident;
            auto type = anal->symTab.lookup(node->children[1]->attr);
            if(type == nullptr) {
                handleInvalidType(node->children[1]->attr, node->children[1]->loc);
            }
            // the symbol was overridden and is no longer a type
            if(!type->isType) {
                handleInvalidType(type->name, type->loc);
            }
            ident->sig = type->name;
            break;
        }
        case NodeKind::AssignStmt: {
            std::cout << "AssignStmt" << std::endl;
            /* check for symbol */
            auto lhs = node->children[0];
            auto ident = anal->symTab.lookup(lhs->attr);
            if(ident == nullptr) {
                errorMsg = "Variable '" + lhs->attr + "' was not declared.";
                handleError(errorMsg.c_str(), lhs->loc.begin.line, lhs->loc.begin.column);
            }
            if(ident->isType) {
                errorMsg = "can only assign to a variable";
                handleError(errorMsg.c_str(), lhs->loc.begin.line, lhs->loc.begin.column);
            }
            // I guess the reference compiler doenst check for this
            // if(symbol->isConst) {
            //     errorMsg = "Assigning to constant'" + symbol->name + "'";
            //     handleError(errorMsg.c_str());
            // }
            // if we pass all checks, update identifier node
            lhs->symbol = ident;
            break;
        }
        case NodeKind::BinaryExpr:
            
            break;
        case NodeKind::UnaryExpr:

            break;
        case NodeKind::FuncCall:

            break;
        case NodeKind::Block:
            /* create new scope */
            anal->symTab.pushScope();
            break;
        default:
            break;
        }
    }

    void pass2PostOrderCallback(SemanticAnalyzer* anal /* lol */, std::shared_ptr<AstNode> node) {
        switch (node->kind)
        {
        case NodeKind::Block:
            /* code */
            anal->symTab.popScope();
            break;
        default:
            break;
        }
    }

    void SemanticAnalyzer::doAnalysis() {
        this->symTab.insertUniverseBlock();
        // first pass -- add global declarations
        this->symTab.pushScope();
        this->pass1();
        this->pass2();
        // second pass -- ?
    }
}