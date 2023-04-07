#pragma once

#include "AstNode.hpp"
#include "util.hpp"

#include <array>
#include <memory>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <map>

namespace GoLF {

class StopTraversalException : public std::exception {};

struct CodeGen {
	// enum RegType { Arg, Ret, Saved, Temp };
	enum AllocType { Asciiz, Word };
	std::shared_ptr<AstNode> root;
	std::vector<std::string> regPool;
	// this map will automatically store string literals in lexographic order
	// so comparisons in the assembly code can be simple address comparisons
	// also gets rid of duplicates
	// {strLit : label}
	std::map<std::string, std::string> orderedstringLits;
	std::set<std::string> regsInUse;
	// holds the complete program to emit at the end
	std::string prog;
	// holds the data segment of the entire program
	std::string dataSeg = "\t.data\n";
	// holds the text segment of the entire program
	std::string textSeg = R"(
	.text
	.globl main
main:
	jal Lmain
	j Lhalt
)";
	// holds the current offset from the frame pointer when allocating local variables
	// offset 0 is reserved for $fp
	// offset -4 is reserved for $ra
	int offsetFromFp = -4;
	// holds the instructions of the current function body
	std::string currFuncBody = "";
	std::string lastExitLabel = "";
	std::string lastRetLabel = "";
	const std::string emptyStringLabel = "LemptyString";

	CodeGen(std::shared_ptr<AstNode> root);
	void generate();
	void emitRTS();
	void emitDataSeg();
	void emitTextSeg();

	void emitDataWord(const std::string& label);
	void emitStrLits();

	const std::string allocReg();
	void freeReg(const std::string& regId);
	std::string getLabel();
	std::string idToAsm(std::string& id);
	void emitLabel(const std::string& label);
	void emitInst(const std::string& inst);
	
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

void pass1PreOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node);
void pass2PreOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node);
void pass2PostOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node);
} // namespace GoLF