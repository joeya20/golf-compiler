#include "SemanticAnalyzer.hpp"

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

    /* Pass 1 */
    // gather global definitions
    // its not necessary to use the traversal engine for this
    // since we just need to check the children of the Program node
    void SemanticAnalyzer::pass1() {
        for(auto & topLevelDecl : root->children) {
            if(topLevelDecl->kind == AstNode::Kind::GlobVarDecl) {
                auto IdentNode = topLevelDecl->children[0];
                auto symbol = symTab.define(IdentNode->attr, IdentNode->loc);
                symbol->isConst = false;
                symbol->isType = false;
                symbol->sig = topLevelDecl->children[1]->attr;
                topLevelDecl->symbol = symbol;
            }
            else if(topLevelDecl->kind == AstNode::Kind::FuncDecl) {
                auto IdentNode = topLevelDecl->children[0];
                auto symbol = symTab.define(IdentNode->attr, IdentNode->loc);
                symbol->isConst = false;
                symbol->isType = false;
                symbol->rvSig = topLevelDecl->children[1]->attr;
                topLevelDecl->symbol = symbol;
            }
            else {
                handleError("unexpected node kind under program node!");
            }
        }
    }

    /* Pass 2 */
    void pass2Callback(std::shared_ptr<AstNode> node) {
        switch (node->kind)
        {
        case AstNode::Kind::IntLit:
            /* code */
            break;
        
        default:
            break;
        }
    };

    void SemanticAnalyzer::doAnalysis() {
        this->symTab.insertUniverseBlock();
        // first pass -- add global declarations
        this->symTab.pushScope();
        this->pass1();
        // second pass -- ?
    }
}