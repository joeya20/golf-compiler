#include "AstNode.hpp"
#include "SemanticAnalyzer.hpp"
#include <functional>
#include <memory>

namespace GoLF {
    AstNode::AstNode(Kind kind) {
        this->kind = kind;
        this->loc.initialize();
    }

    AstNode::AstNode(Kind kind, std::string attr) {
        this->kind = kind;
        this->attr = attr;
        this->loc.initialize();
    }

    AstNode::AstNode(Kind kind, location loc) {
        this->kind = kind;
        this->loc = loc;
    }

    AstNode::AstNode(Kind kind, std::string attr, location loc) {
        this->kind = kind;
        this->attr = attr;
        this->loc = loc;
    }

    // nothing to really do here since we are using shared pointers
    // normally I would have to destroy the children before destroying the node
    AstNode::~AstNode() {
        // while(children.size() > 0) {
        //     AstNode* child = children.back();
        //     children.pop_back();
                // delete child;
        // };
    }

    void AstNode::addChild(std::shared_ptr<AstNode> child) {
        children.push_back(child);
    }

    //tabSize default size is 0
    std::string AstNode::toString(int tabSize) {

        std::string res (tabSize, ' ');
        res += this->nodeKindToString[this->kind];
        if(this->attr.size() > 0) {
            res += " [";
            res += this->attr;
            res += ']';
        }
        if(this->sig != "") {
            res += " sig=";
            res += this->sig;
        }
        if(this->loc.begin.filename != nullptr) {
            res += " @ line ";
            res += std::to_string(this->loc.begin.line);
            res += " @ col ";
            res += std::to_string(this->loc.begin.column);
        }
        if(this->symbol != nullptr) {
            res += " <symbol addr: ";
            std::stringstream addr;
            addr << this->symbol.get();
            res += addr.str();
            res += '>';
        }
        res += '\n';
        for(size_t i = 0; i < this->children.size(); i++) {
            res += this->children[i]->toString(tabSize + TAB_SIZE);
        }
    // }
        return res;
    }

    template <class T>
    void AstNode::preOrderTraversal(
    const T* t,
    std::function<void(const T*,
    std::shared_ptr<AstNode>)> callback) {
        callback(t, shared_from_this());
        for(size_t i = 0; i < this->children.size(); i++) {
            preOrderTraversal(t, callback);
        }
    }

    template <class T>
    void AstNode::postOrderTraversal(
    const T* t,
    std::function<void(const T*, std::shared_ptr<AstNode>)> callback) {
        for(size_t i = 0; i < this->children.size(); i++) {
            postOrderTraversal(t, callback);
        }
        callback(t, shared_from_this());
    }

    template <class T>
    void AstNode::prePostOrderTraversal(
    const T* t,
    std::function<void(const T*, std::shared_ptr<AstNode>)> preCallback, 
    std::function<void(const T*, std::shared_ptr<AstNode>)> postCallback) {
        preCallback(t, shared_from_this());
        for(size_t i = 0; i < this->children.size(); i++) {
            prePostOrderTraversal(t, preCallback, postCallback);
        }        
        postCallback(t, shared_from_this());
    }

    template void AstNode::preOrderTraversal<SemanticAnalyzer>(
        const SemanticAnalyzer*, 
        std::function<void(const SemanticAnalyzer*, std::shared_ptr<AstNode>)>
    );
    template void AstNode::postOrderTraversal<SemanticAnalyzer>(
        const SemanticAnalyzer*,
        std::function<void(const SemanticAnalyzer*, std::shared_ptr<AstNode>)>
    );
    template void AstNode::prePostOrderTraversal<SemanticAnalyzer>(
        const SemanticAnalyzer*, 
        std::function<void(const SemanticAnalyzer*, std::shared_ptr<AstNode>)>,
        std::function<void(const SemanticAnalyzer*, std::shared_ptr<AstNode>)>
    );

    std::ostream& operator<<(std::ostream& os, AstNode *node) {
        os << node->toString();
        return os;
    }
}