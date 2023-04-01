#pragma once

#include "AstNode.hpp"
#include "util.hpp"

#include <array>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace GoLF {

class StopTraversalException : public std::exception {};

struct CodeGen {
	enum RegType { Arg, Ret, Saved, Temp };

	std::shared_ptr<AstNode> root;
	std::unordered_map<RegType, std::vector<std::string>> regPool;
	std::string prog;
	
	CodeGen(std::shared_ptr<AstNode> root);
	void generate();
	const std::string allocReg(RegType type);
	void freeReg(RegType type, std::string& regId);
	void emitPreamble();
	std::string getLabel();

	// generic pre-order traversal function
	void preOrderTraversal(
		std::shared_ptr<AstNode>,
		std::function<void(CodeGen *, std::shared_ptr<AstNode>)>);
	void postOrderTraversal(
		std::shared_ptr<AstNode>,
		std::function<void(CodeGen *, std::shared_ptr<AstNode>)>);
	void prePostOrderTraversal(
		std::shared_ptr<AstNode>,
		std::function<void(CodeGen *, std::shared_ptr<AstNode>)>,
		std::function<void(CodeGen *, std::shared_ptr<AstNode>)>);
};

} // namespace GoLF