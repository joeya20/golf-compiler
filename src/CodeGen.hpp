#pragma once

#include "AstNode.hpp"
#include "util.hpp"

#include <array>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>

namespace GoLF {

class StopTraversalException : public std::exception {};

struct CodeGen {
	enum RegType { Arg, Ret, Saved, Temp };
	enum AllocType { Asciiz, Word };
	std::shared_ptr<AstNode> root;
	std::unordered_map<RegType, std::vector<std::string>> regPool;
	// this map will automatically store string literals in lexographic order
	// so comparisons in the assembly code can be simple address comparisons
	// also gets rid of duplicates
	// {strLit : label}
	std::map<std::string, std::string> orderedstringLits;

	// holds the complete program to emit at the end
	std::string prog;
	// holds the data segment of the entire program
	std::string dataSeg = "\t.data\n";
	// holds the text segment of the entire program
	std::string textSeg = "\t.text\n";

	// holds the instructions of the current function body
	std::string currFuncBody = "";

	// A template for function declarations.
	// The prologue only saves any saved registers used for
	// local variables, not the function arguments, etc.
	// Those are handled ad-hoc when a funcCall is actually encountered.
	const std::string funcTemplate {R"(
	# prologue
    addi $sp, $sp, -4 	# allocate space for $ra
    sw $ra, 4($sp)		# save $ra
{}
	# body
{}
	# epilogue
    lw $ra, 4($sp) 		# allocate space for $ra
    addi $sp, $sp, 4 	# allocate space for $ra
    jr $ra
{}
)"};
	// a template for if stmts
	const std::string ifTemplate {R"(

)"};
	// a template for for stmts
	const std::string forTemplate {R"(

)"};

	const std::string emptyStringLabel = "LemptyString";

	CodeGen(std::shared_ptr<AstNode> root);
	void generate();
	void emitPreamble();
	void emitDataSeg();
	void emitTextSeg();

	void emitDataWord(const std::string& label);
	void emitStrLits();

	const std::string allocReg(RegType type);
	void freeReg(CodeGen::RegType type, const std::string& regId);
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
void pass1PostOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node);
} // namespace GoLF