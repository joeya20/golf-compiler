#include "SemanticAnalyzer.hpp"
#include "AstNode.hpp"
#include "location.hh"
#include "util.hpp"
#include <bits/types/struct_sched_param.h>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace GoLF {
    const std::vector<SemanticAnalyzer::AllowedType> SemanticAnalyzer::arithmeticTypes =  {
        SemanticAnalyzer::AllowedType("int", "int", "int")
    };
    
    const std::vector<SemanticAnalyzer::AllowedType> SemanticAnalyzer::logicalTypes =  {
        SemanticAnalyzer::AllowedType("bool", "bool", "bool")
    };

    const std::vector<SemanticAnalyzer::AllowedType> SemanticAnalyzer::equalityTypes = {
        SemanticAnalyzer::AllowedType("int", "int", "bool"),
        SemanticAnalyzer::AllowedType("bool", "bool", "bool"),
        SemanticAnalyzer::AllowedType("string", "string", "bool")
    };

    const std::vector<SemanticAnalyzer::AllowedType> SemanticAnalyzer::comparisonTypes = {
        SemanticAnalyzer::AllowedType("int", "int", "bool"),
        SemanticAnalyzer::AllowedType("string", "string", "bool")
    };

    const std::vector<SemanticAnalyzer::AllowedType> SemanticAnalyzer::unaryMinusTypes = {
        SemanticAnalyzer::AllowedType("int", "int")
    };

    
    const std::vector<SemanticAnalyzer::AllowedType> SemanticAnalyzer::unaryNotTypes = {
        SemanticAnalyzer::AllowedType("bool", "bool")
    };

    const std::unordered_map<std::string, const std::string> SemanticAnalyzer::returnTypes = {
        {"||"   , "bool"    },
        {"&&"   , "bool"    },
        {"=="   , "bool"    },
        {"!="   , "bool"    },
        {"<"    , "bool"    },
        {"<="   , "bool"    },
        {">"    , "bool"    },
        {">="   , "bool"    },
        {"+"    , "int"     },
        {"-"    , "int"     },
        {"*"    , "int"     },
        {"/"    , "int"     },
        {"%"    , "int"     },
        {"u-"   , "int"     },
        {"!"    , "bool"    }
    };

    const std::unordered_map<std::string, const std::vector<SemanticAnalyzer::AllowedType>*> SemanticAnalyzer::allowedTypes {
        {"||"   , &SemanticAnalyzer::logicalTypes       },
        {"&&"   , &SemanticAnalyzer::logicalTypes       },
        {"=="   , &SemanticAnalyzer::equalityTypes      },
        {"!="   , &SemanticAnalyzer::equalityTypes      },
        {"<"    , &SemanticAnalyzer::comparisonTypes    },
        {"<="   , &SemanticAnalyzer::comparisonTypes    },
        {">"    , &SemanticAnalyzer::comparisonTypes    },
        {">="   , &SemanticAnalyzer::comparisonTypes    },
        {"+"    , &SemanticAnalyzer::arithmeticTypes    },
        {"-"    , &SemanticAnalyzer::arithmeticTypes    },
        {"*"    , &SemanticAnalyzer::arithmeticTypes    },
        {"/"    , &SemanticAnalyzer::arithmeticTypes    },
        {"%"    , &SemanticAnalyzer::arithmeticTypes    },
        {"u-"   , &SemanticAnalyzer::unaryMinusTypes    },
        {"!"    , &SemanticAnalyzer::unaryNotTypes      }
    };

    SemanticAnalyzer::SemanticAnalyzer(std::shared_ptr<AstNode> root) : root(root) {
        forLoopCount = 0;
    }

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
                auto identNode = topLevelDecl->children[0];
                auto symbol = symTab.define(identNode->attr, identNode->loc, false, false);
                // cannot determine type at this point
                // symbol->sig = topLevelDecl->children[1]->attr;
                identNode->symbol = symbol;
            }
            else if(topLevelDecl->kind == NodeKind::FuncDecl) {
                auto identNode = topLevelDecl->children[0];
                auto symbol = symTab.define(identNode->attr, identNode->loc, false, false);
                // cannot determine type at this point
                // symbol->rvSig = topLevelDecl->children[1]->attr;
                identNode->symbol = symbol;
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

    std::shared_ptr<Symbol> SemanticAnalyzer::getIdent(std::shared_ptr<AstNode> node) {
        auto ident = symTab.lookup(node->attr);
        if(ident == nullptr) {
            std::string errorMsg = "identifier '" + node->attr + "' is not defined.";
            handleError(errorMsg.c_str(), node->loc.begin.line, node->loc.begin.column);
        }
        if(ident->isType) {
           std::string errorMsg = "expected identifier, got type '" + ident->name + "'";
            handleError(errorMsg.c_str(), node->loc.begin.line, node->loc.begin.column);
        }
        return ident;
    }

    std::shared_ptr<Symbol> SemanticAnalyzer::getSig(std::shared_ptr<AstNode> node) {
        auto sig = symTab.lookup(node->attr);
        if(sig == nullptr) {            
            std::string errorMsg = "type '" + node->attr + "' is not defined.";
            handleError(errorMsg.c_str(), node->loc.begin.line,  node->loc.begin.column);
        }
        // the symbol was overridden and is no longer a type
        if(!sig->isType) {
            std::string errorMsg = "expected type, got '" + sig->name + "'";
            handleError(errorMsg.c_str(), node->loc.begin.line,  node->loc.begin.column);
        }
        return sig;
    }

    void pass2PreOrderCallback(SemanticAnalyzer* anal /* lol */, std::shared_ptr<AstNode> node) {
        std::string errorMsg;
        switch (node->kind)
        {
        case NodeKind::GlobVarDecl: { // fully define symbol (i.e. type)
            auto sig = anal->getSig(node->children[1]);
            node->children[0]->symbol->sig = sig->sig;
            node->children[1]->symbol = sig;
            break;
        }
        case NodeKind::FuncDecl: { // fully define symbol (i.e. type and rv type)  
            auto funcSign = node->children[1];
            // handle return value
            auto rvType = anal->getSig(funcSign->children[1]);
            node->children[0]->symbol->rvSig = rvType->sig;
            funcSign->children[1]->symbol = rvType;

            // handle param values
            std::string sig = "f(";
            for(auto & paramDecl : funcSign->children[0]->children) {
                // add this to vector so symbols are defined instead of the following block's scope
                anal->paramDecls.push_back(paramDecl);

                // check type and add to sig
                auto paramType = anal->getSig(paramDecl->children[1]);
                sig += (paramType->name + ",");
            }
            if(sig.back() == ',') sig.pop_back();
            sig += ")";
            node->children[0]->symbol->sig = sig;  
            break;
        }
        case NodeKind::VarDecl: {
            auto sig = anal->getSig(node->children[1]);
            auto ident = anal->symTab.define(node->children[0]->attr, node->children[0]->loc, false, false);
            ident->sig = sig->sig;
            node->children[0]->symbol = ident;
            node->children[1]->symbol = sig;
            break;
        }
        case NodeKind::UnaryExpr: {
            // funccalls are handled in their own case stmt
            auto expr = node->children[0];
            if(expr->kind == NodeKind::Ident) {
                expr->symbol = anal->getIdent(expr);
            }
            else if(expr->kind == NodeKind::FuncCall) {
                expr->children[0]->symbol = anal->getIdent(expr->children[0]);
            }
            break;
        }
        case NodeKind::Block:
            /* create new scope */
            anal->symTab.pushScope();
            // need to check fpr params to add to this block scope
            // in case this block is for a FuncDecl
            while(anal->paramDecls.size() > 0) {
                auto paramDecl = anal->paramDecls.back();
                auto ident = paramDecl->children[0];
                auto sig = paramDecl->children[1];
                auto typeSymbol = anal->getSig(sig);
                auto identSymbol = anal->symTab.define(ident->attr, ident->loc, false, false);
                identSymbol->sig = typeSymbol->name;
                sig->symbol = typeSymbol;
                ident->symbol = identSymbol;
                anal->paramDecls.pop_back();
            }
            break;
        // case NodeKind::AssignStmt: {
        //     /* check for symbol */
        //     std::cout << "start AssignStmt" << std::endl;
        //     auto lhs = node->children[0]->children[0];
        //     lhs->symbol = anal->getIdent(lhs);
        //     if(lhs->symbol->isConst) {
        //         handleError("can't assign to a constant", node->children[0]->loc.begin.line, node->children[0]->loc.begin.column);
        //     }
        //     std::cout << "end AssignStmt" << std::endl;
        //     break;
        // }
        // case NodeKind::FuncCall: {
        //     std::cout << "start FuncCall" << std::endl;
        //     auto expr = node->children[0]; 
        //     expr->symbol = anal->getIdent(expr);
        // //     for(auto & funcArg : node->children[1]->children) {
        // //         funcArg->symbol = anal->getIdent(funcArg);
        // //     }
        //     std::cout << "end FuncCall" << std::endl;
        //     break;
        // }
        // case NodeKind::BinaryExpr: {
        //     auto lhs = node->children[0];
        //     if(lhs->kind == NodeKind::Ident) {
        //         lhs->symbol = anal->getIdent(lhs);
        //     }
        //     auto rhs = node->children[1];
        //     if(rhs->kind == NodeKind::Ident) {
        //         rhs->symbol = anal->getIdent(rhs);
        //     }
        //     break;
        // }
        /* this used to be need before but I changed my AST structure instead */
        // case NodeKind::IfStmt: {
        //     auto expr = node->children[0]; 
        //     if(expr->kind == NodeKind::Ident) {
        //         expr->symbol = anal->getIdent(expr);
        //     }
        // }
        // case NodeKind::ForStmt: {
        //     auto expr = node->children[0]; 
        //     if(expr->kind == NodeKind::Ident) {
        //         expr->symbol = anal->getIdent(expr);
        //     }
        // }
        // case NodeKind::ReturnStmt: {
        //     if(node->children.size() > 0) {
        //         auto expr = node->children[0]; 
        //         if(expr->kind == NodeKind::Ident) {
        //             expr->symbol = anal->getIdent(expr);
        //         }
        //     }
        // }
        // case NodeKind::ExprStmt: {
        //     auto & expr = node->children[0];
        //     if(expr->kind == NodeKind::Ident) {
        //             expr->symbol = anal->getIdent(expr);
        //     }
        // }
        default:
            break;
        }
    }

    void pass2PostOrderCallback(SemanticAnalyzer* anal /* lol */, std::shared_ptr<AstNode> node) {
        if (node->kind == NodeKind::Block) {
            anal->symTab.popScope();
        }
    }

    void SemanticAnalyzer::pass3() {
        postOrderTraversal(this->root, pass3PostOrderCallback);
    };

    // propagating types starting from leaf nodes and type checking
    void pass3PostOrderCallback(SemanticAnalyzer *anal, std::shared_ptr<AstNode> node) {
        switch (node->kind) {
        case NodeKind::IntLit:
            node->sig = "int";
            break;
        case NodeKind::StrLit:
            node->sig = "string";
            break;
        case NodeKind::Ident:
            node->sig = node->symbol->sig;
            break;
        case NodeKind::UnaryExpr: {
            if(node->attr == "") {
                node->sig = node->children[0]->sig;
            }
            else {
                // first find type of this expr based on operator
                auto returnType = anal->returnTypes.find(node->attr);
                if(returnType != anal->returnTypes.end()) {
                    node->sig = returnType->second;
                    bool valid = false;
                    // then check it is valid
                    // we don't have to check for return type?
                    auto allowedTypes = anal->allowedTypes.at(node->attr);
                    for(auto & allowedType : *allowedTypes) {
                        if(allowedType.lType == node->children[0]->sig && 
                        allowedType.returnType == node->sig) {
                            valid = true;
                            break;
                        }
                    }
                    if(!valid) {
                        handleError("invalid type");
                    }
                }
                else {
                    handleError("debug unary expr type");
                }    
            }
            break;
        }
        case NodeKind::BinaryExpr: {
            // first find type of this expr based on operator
            auto returnType = anal->returnTypes.find(node->attr);
            if(returnType != anal->returnTypes.end()) {
                node->sig = returnType->second;
                bool valid = false;
                // then check it is valid
                // we don't have to check for return type?
                auto allowedTypes = anal->allowedTypes.at(node->attr);
                for(auto & allowedType : *allowedTypes) {
                    if(allowedType.lType == node->children[0]->sig && 
                    allowedType.rType == node->children[1]->sig &&
                    allowedType.returnType == node->sig) {
                        valid = true;
                        break;
                    }
                }
                if(!valid) {
                    auto errorMsg = "operand type mismatch for '" + node->attr + "'";
                    handleError(errorMsg.c_str(), node->loc.begin.line, node->loc.begin.column);
                }
            }
            else {
                handleError("debug bin expr type");
            }    
            break;
        }
        case NodeKind::IfStmt:
            if(node->children[0]->sig != "bool") {
                handleError(
                    "if expression must be boolean type"
                    , node->children[0]->loc.begin.line
                    , node->children[0]->loc.begin.column
                );
            }
            break;
        case NodeKind::ForStmt:
            if(node->children[0]->sig != "bool") {
                handleError(
                    "for expression must be boolean type"
                    , node->children[0]->loc.begin.line
                    , node->children[0]->loc.begin.column);
            }
            break;
        case NodeKind::FuncCall: {
            auto identNode = node->children[0];
            node->sig = identNode->symbol->rvSig;
            if(identNode->sig[0] == 'f') {
                std::string argsSig = "f(";
                for(auto & funcArg : node->children[1]->children) {
                    argsSig += (funcArg->sig + ',');
                }
                if(argsSig.back() != '(') argsSig.pop_back();
                argsSig += ')';
                if(argsSig != identNode->sig) {
                    handleError(
                        "number/type of arguments in function call doesn't match function declaration"
                        , identNode->loc.begin.line
                        , identNode->loc.begin.column
                    );
                }
            }
            else {
                handleError(
                    "can't call something that isn't a function"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            break;
        }
        case NodeKind::AssignStmt: {
            auto & lhs = node->children[0];
            auto & rhs = node->children[1];
            if(lhs->sig != rhs->sig) {
                handleError(
                    "operand type mismatch for '='"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
        }
        default:
            break;
        }
    }

    void SemanticAnalyzer::pass4() {
        prePostOrderTraversal(root, pass4PreOrderCallback, pass4PostOrderCallback);
    }

    // actions
    void pass4PreOrderCallback(SemanticAnalyzer* anal, std::shared_ptr<AstNode> node) {
        switch (node->kind) {
        case NodeKind::FuncDecl: 
            if(node->children[0]->attr == "main") {
                // first check its return type
                auto & funcSign = node->children[1];
                if(funcSign->children[1]->attr != "$void") {
                    handleError(
                        " main() can't have a return value"
                        , node->loc.begin.line
                        , node->loc.begin.column
                    );
                }
                auto & params = funcSign->children[0];
                // then check its parameters
                if(params->children.size() > 0) {
                    handleError(
                        "main() can't have arguments"
                        , node->loc.begin.line
                        , node->loc.begin.column
                    );
                }
            }
            anal->funcReturnSig = node->children[0]->symbol->rvSig;
            break;
        case NodeKind::ReturnStmt:
            if(node->children.size() > 0 && anal->funcReturnSig == "void") {
                handleError(
                    "this function can't return a value"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            else if(node->children.size() == 0 && anal->funcReturnSig != "void") {
                handleError(
                    "this function must return a value"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            else if(node->children.size() > 0 && anal->funcReturnSig != "void") {
                if(node->children[0]->sig != anal->funcReturnSig) {
                    auto errorMsg = "returned value has the wrong type";
                    handleError(
                        errorMsg
                        , node->loc.begin.line
                        , node->loc.begin.column
                    );
                }
                anal->funcReturnSig = "";
            }
            break;
        case NodeKind::IntLit: {
            if(node->attr.size() > 11) {
                handleError(
                    "integer literal out of range"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            auto val = std::stol(node->attr);
            if(val > INT32_MAX || val < INT32_MIN) {
                handleError(
                    "integer literal out of range"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            break;
        }
        case NodeKind::ForStmt:
            anal->forLoopCount++;
            break;
        case NodeKind::BreakStmt:
            if(anal->forLoopCount == 0) {
                handleError(
                    "break statement must be inside a for loop"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            break;
        case NodeKind::AssignStmt: {
            auto lhs = node->children[0];
            if(lhs->kind != NodeKind::UnaryExpr) {
                handleError(
                    "can only assign to a variable"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            lhs = lhs->children[0];
            if(lhs->kind != NodeKind::Ident) {
                handleError(
                    "can only assign to a variable"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            if(lhs->sig[0] == 'f') {    //TODO: review
                handleError(
                    "can only assign to a variable"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            else if(lhs->symbol->isConst) {
                handleError(
                    "can't assign to a constant"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            else if(lhs->symbol->isType) {
                handleError(
                    "can only assign to a variable"
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            break;
        }
        default:
            break;
        }
    };

    // actions
    void pass4PostOrderCallback(SemanticAnalyzer* anal, std::shared_ptr<AstNode> node) {
        switch (node->kind) {
        case NodeKind::ForStmt:
            anal->forLoopCount--;
            break;
        case NodeKind::FuncDecl:
            if(anal->funcReturnSig != "" && anal->funcReturnSig != "void") {
                std::string errorMsg = "no return statement in function '" + node->children[0]->attr + "'";
                handleError(
                    errorMsg.c_str()
                    , node->loc.begin.line
                    , node->loc.begin.column
                );
            }
            break;
        default:
            break;
        }
    };


    void SemanticAnalyzer::doAnalysis() {
        this->symTab.insertUniverseBlock();
        this->symTab.pushScope();
        // first pass -- add global declarations
        this->pass1();
        // second pass -- handle all identifiers
        this->pass2();
        // third pass -- type checking
        this->pass3();
        // fourth pass -- everything else 
        this->pass4();
        std::string main = "main";
        auto mainFunc = symTab.lookup(main);
        if(mainFunc == nullptr) {
            handleError("missing main() function");
        }
        root->symbol = mainFunc;
    }
}