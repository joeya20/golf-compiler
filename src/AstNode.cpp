#include "AstNode.hpp"

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
        // std::cout << "here" << std::endl;
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
        // handle lists; just ignore them and go to the next level
        // this is done for output consistency with reference compiler
        // if (this->kind == AstNode::Kind::ExprList ||
        // this->kind == AstNode::Kind::ParamList ||
        // this->kind == AstNode::Kind::StmtList) {
        //     for(size_t i = 0; i < this->children.size(); i++) {
        //         // std::cout << "tab size: " << tabSize << std::endl;
        //         res += this->children[i]->toString(tabSize);
        //     }
        // }
        // else {
            //initiate res with tabSize * ' '
            // res = std::string(tabSize, ' ');
        res += this->nodeKindToString[this->kind];
        if(this->attr.size() > 0) {
            res += ' ';
            res += '[';
            res += this->attr;
            res += ']';
        }
        if(this->loc.begin.filename != nullptr) {
            res += ' ';
            res += "@ line ";
            res += std::to_string(this->loc.begin.line);
            res += " @ col ";
            res += std::to_string(this->loc.begin.column);
        }
        res += '\n';
        for(size_t i = 0; i < this->children.size(); i++) {
            res += this->children[i]->toString(tabSize + TAB_SIZE);
        }
    // }
        return res;
    }

    void AstNode::preOrderTraversal(std::function<void(const std::shared_ptr<AstNode>)> callback) {
        callback(shared_from_this());
        for(size_t i = 0; i < this->children.size(); i++) {
            this->children[i]->preOrderTraversal(callback);
        }
    }

    void AstNode::postOrderTraversal(std::function<void(const std::shared_ptr<AstNode>)> callback) {
        callback(shared_from_this());
        for(size_t i = 0; i < this->children.size(); i++) {
            this->children[i]->preOrderTraversal(callback);
        }
    }

    void AstNode::prePostOrderTraversal(std::function<void(std::shared_ptr<AstNode>)> preCallback, std::function<void(std::shared_ptr<AstNode>)> postCallback) {
        preOrderTraversal(preCallback);

        for(size_t i = 0; i < this->children.size(); i++) {
            this->children[i]->prePostOrderTraversal(preCallback, postCallback);
        }
        
        postOrderTraversal(postCallback);
    }

    std::ostream& operator<<(std::ostream& os, AstNode *node) {
        os << node->toString();
        return os;
    }
}