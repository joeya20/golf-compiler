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
    void pass1PreOrderCallback(std::shared_ptr<AstNode> node) {
        
    }
    void pass1PostOrderCallback(std::shared_ptr<AstNode> node) {
        
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
        // first pass -- build up symbol table
        root->prePostOrderTraversal(&pass1PreOrderCallback, &pass1PostOrderCallback);

        // second pass -- ?
    }
}