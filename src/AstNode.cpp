#include "AstNode.hpp"

GoLF::AstNode::AstNode(Kind kind) {
    this->kind = kind;
    this->loc.initialize();
}

GoLF::AstNode::AstNode(Kind kind, std::string attr) {
    this->kind = kind;
    this->attr = attr;
    this->loc.initialize();
}

GoLF::AstNode::AstNode(Kind kind, location loc) {
    this->kind = kind;
    this->loc = loc;
}

GoLF::AstNode::AstNode(Kind kind, std::string attr, location loc) {
    this->kind = kind;
    this->attr = attr;
    this->loc = loc;
}

GoLF::AstNode::~AstNode() {
    while(children.size() > 0) {
        AstNode* child = children.back();
        children.pop_back();
        delete child;
    };
}

void GoLF::AstNode::addChild(AstNode* child) {
    children.push_back(child);
}

//tabSize default size is 0
std::string GoLF::AstNode::toString(int tabSize) {

    std::string res;
    // handle lists; just ignore them and go to the next level
    // this is done for output consistency with reference compiler
    if (this->kind == AstNode::Kind::ExprList ||
    this->kind == AstNode::Kind::ParamList ||
    this->kind == AstNode::Kind::StmtList) {
        for(size_t i = 0; i < this->children.size(); i++) {
            // std::cout << "tab size: " << tabSize << std::endl;
            res += this->children[i]->toString(tabSize);
        }
    }
    else {
        //initiate res with tabSize * ' '
        res = std::string(tabSize, ' ');
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
        }
        res += '\n';
        for(size_t i = 0; i < this->children.size(); i++) {
            res += this->children[i]->toString(tabSize + TAB_SIZE);
        }
    }
    return res;
}

std::ostream& GoLF::operator<<(std::ostream& os, GoLF::AstNode *node) {
    os << node->toString();
    return os;
}