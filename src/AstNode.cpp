#include "AstNode.hpp"

GoLF::AstNode::AstNode(Kind kind) {
    this->kind = kind;
}

GoLF::AstNode::AstNode(Kind kind, std::string attr) {
    this->kind = kind;
    this->attr = attr;
}

GoLF::AstNode::AstNode(Kind kind, int lineno, int startCol, int endCol) {
    this->kind = kind;
    this->lineno = lineno;
    this->startCol = startCol;
    this->endCol = endCol;
}

GoLF::AstNode::AstNode(Kind kind, std::string attr, int lineno, int startCol, int endCol) {
    this->kind = kind;
    this->lineno = lineno;
    this->startCol = startCol;
    this->endCol = endCol;
    this->attr = attr;
}

GoLF::AstNode::~AstNode() {
    while(children.size() > 0) {
        std::cout << "here" << std::endl;
        AstNode* child = children.back();
        children.pop_back();
        delete child;
    };
}

void GoLF::AstNode::addChild(AstNode* child) {
    children.push_back(child);
}