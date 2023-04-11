#include "CodeGen.hpp"
#include "util.hpp"
#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <assert.h>
#include <algorithm>

// use table-driven generation
// generate string on entry and exit of a node
namespace GoLF {

static std::unordered_map<std::string, std::string> opToAsm = {
    // binary ops
    {   "+"     ,
		"addu %s, %s, %s"  
	},
    {   "-"     ,
		"subu %s, %s, %s"  
	}, 
    {
		"*"     ,
		"mul %s, %s, %s"
	},
    {
		"/"     ,
		"div %s, %s, %s"
	}, 
    {   
        "%"     ,
		"rem %s, %s, %s"
	},
    {   
        "<"     ,    
        "slt %s, %s, %s"  
    },
    {   
        "<="    ,    
        "sle %s, %s, %s"  
    },
    {   
        ">"     ,
        "sgt %s, %s, %s"  
    },
    {   
        ">="    ,
        "sge %s, %s, %s"  
    },
    {   
        "=="    ,
        "seq %s, %s, %s"  
    },
    {
        "!="    ,
        "sne %s, %s, %s"  
    }
};

CodeGen::CodeGen(std::shared_ptr<AstNode> root) {
    // crappy reg allocator
    // $v0 is reserved for return values
    // $v1 is not used
    // there is at most 1 return value so this makes life easier
    // $a0 - $a3 are used for arguments 1 - 4
    this->regPool = {"$s7", "$s6",
                     "$s5", "$s4", "$s3", "$s2", "$s1", "$s0", "$t9", "$t8",
                     "$t7", "$t6", "$t5", "$t4", "$t3", "$t2", "$t1", "$t0"};
    this->root = root;
    this->orderedstringLits[std::string{"\"\""}] = this->emptyStringLabel;
}

void CodeGen::preOrderTraversal(
    std::shared_ptr<AstNode> node,
    std::function<void(CodeGen *, std::shared_ptr<AstNode>)>
        callback) {
    try {
        callback(this, node);
    }
    catch (StopTraversalException& stop) {
        return;
    }
    for (size_t i = 0; i < node->children.size(); i++) {
        preOrderTraversal(node->children[i], callback);
    }
}

void CodeGen::postOrderTraversal(
    std::shared_ptr<AstNode> node,
    std::function<void(CodeGen *, std::shared_ptr<AstNode>)>
        callback) {
    for (size_t i = 0; i < node->children.size(); i++) {
        try {
            postOrderTraversal(node->children[i], callback);
        }
        catch (StopTraversalException& stop) {
            break;
        }
    }
    callback(this, node);
}

void CodeGen::prePostOrderTraversal(
    std::shared_ptr<AstNode> node,
    std::function<void(CodeGen *, std::shared_ptr<AstNode>)>
        preCallback,
    std::function<void(CodeGen *, std::shared_ptr<AstNode>)>
        postCallback) {
    try {
        preCallback(this, node);
    }
    catch (StopTraversalException& stop) {
        return;
    }
    for (size_t i = 0; i < node->children.size(); i++) {
        prePostOrderTraversal(node->children[i], preCallback, postCallback);
    }
    postCallback(this, node);
}

// main function that gets called to generate MIPS assembly
void CodeGen::generate() {
    // do traversal(s)
    preOrderTraversal(this->root, pass1PreOrderCallback);
    prePostOrderTraversal(this->root, pass2PreOrderCallback, pass2PostOrderCallback);
    // emit code
    emitTextSeg();
    prog += "\n";
    emitDataSeg();
    emitRTS();
}

// emit things that are always output, such as the built-in functions
void CodeGen::emitRTS() {
    prog += 
R"(

# start of RTS
	.data
trueString:
	.asciiz "true"
falseString:
	.asciiz "false"
noReturnErrorString:
	.asciiz "Runtime error: no value returned from function"
divByZeroString:
	.asciiz "Runtime error: division by zero"
input:  .space 2
	.align 4
Ltrue:
	.word 1
Lfalse:
	.word 0

	.text
# $a0 - dividend
# $a1 - divisor
# checking for two things:
# division by 0: runtime error
# right operand = INT_MIN: return $v0 = 1
# we use $v1 here since we know its never used elsewhere
divModChk:
	beq $0, $a1, divByZeroError
    li $v1, -2147483648
    beq $a0, $v1, secondCheck
divModChkDone:
    move $v0, $a1
    jr $ra
secondCheck:
    li $v1, -1
    bne $a1, $v1, divModChkDone
    li $v0, 1
    jr $ra
divByZeroError:
	la $a0, divByZeroString
	jal Lprints
	jal halt
noReturnError:
	la $a0, noReturnErrorString
	jal Lprints
	jal halt
halt:
	li, $v0, 10
	syscall
    jr $ra
# will populate $v0
# literally copy-pasted from Shankar's Tutorial notes "RTS Functions"
# https://pages.cpsc.ucalgary.ca/~sankarasubramanian.g/411/
LgetChar:
    addiu $sp, $sp, -4
    sw $ra, 0($sp)

    li $v0, 8                       # System call for read_string
    la $a0, input                   # Pass in buffer (size = n+1)
    li $a1, 2                       # Size = n+1 as read_string adds null
    syscall

    lb $v0, input
    bne $v0, $zero, ret

    li $v0, -1                      # If 0, map to -1 and return
ret:
    lw $ra 0($sp)
    addiu $sp $sp, 4
    jr $ra

# assumes $a0 is loaded with address of string
Llen:
	# initialize length variable to 0
	addiu $t0, $0, 0
count:
	# load in character at address in $a0
	lb $t1, ($a0)
	# we've reached EOS if the byte == 0
	beq $t1, $0, retLen
	# else we increment length and the address
	addiu $t0, $t0, 1
	addiu $a0, $a0, 1
	j count
retLen:
	# move length to return register and return
	addiu $v0, $t0, 0
	jr $ra

# assumes $a0 is loaded with boolean to print
Lprintb:
	# if the boolean value is 0 then print false
	beq $0 $a0 printFalse
	# else print true
	addiu $sp, $sp, -8
	sw $ra, -4($sp)
	sw $a0, 0($sp)
	la $a0, trueString
	jal Lprints
	lw $a0, 0($sp)
	lw $ra, -4($sp)
	addiu $sp, $sp, 8
	jr $ra
printFalse:
	addiu $sp, $sp, -8
	sw $ra, -4($sp)
	sw $a0, 0($sp)
	la $a0, falseString
	jal Lprints
	lw $a0, 0($sp)
	lw $ra, -4($sp)
	addiu $sp, $sp, 8
	jr $ra

# assume $a0 is loaded with integer to print
Lprintc:
	li $v0 11
	syscall
	jr $ra

# assume $a0 is loaded with integer to print
Lprinti:
	li $v0 1
	syscall
	jr $ra

# assume $a0 is loaded with adress of string to print
Lprints:
	li $v0 4
	syscall
	jr $ra
# end of RTS
)";
}

void CodeGen::emitDataSeg() {
    emitStrLits();
    prog += dataSeg;
}

void CodeGen::emitTextSeg() {
    prog += textSeg;
}

void CodeGen::emitDataWord(const std::string& label, const std::string& initVal) {
    dataSeg += label + ":\n";
    dataSeg += "\t.word " + initVal + "\n";
}

// emit all strings after traversal, before emitDataSeg
void CodeGen::emitStrLits() {
    for(auto & str : orderedstringLits) {
        dataSeg += str.second + ":\n";
        // we omit the quotes
        for(size_t i = 1; i < str.first.length()-1; i++) {
            int c = str.first[i];
            dataSeg += "\t.byte " + std::to_string(c) + "\n";
        }
        dataSeg += "\t.byte 0\n";
    }
}

void CodeGen::emitLabel(const std::string& label) {
    currFuncBody += label + ":\n";
}

void CodeGen::emitInst(const std::string& inst) {
    currFuncBody += "\t" + inst + "\n";
}

// returns label for jump and branch instructions
std::string CodeGen::getLabel() {
    static int count = 1;
    return "L" + std::to_string(count++);
}

std::string CodeGen::idToAsm(std::string& id) {
    return "L" + id;
}

const std::string CodeGen::allocReg() {
    
    // std::cout << "adding\n";
    if(this->regPool.size() == 0) {
        // output error for now
        handleError("No register available!");
        // return "";
    }
    auto res = regPool.back();
    regPool.pop_back();
    assert(std::find(regsInUse.begin(), regsInUse.end(), res) == regsInUse.end());
    regsInUse.insert(res);
    return res;
}

void CodeGen::freeReg(const std::string& regId) {
	if(regId[1] == 'a') {
		return;
	}
    // std::cout << "removing " << regId << "\n";
    // DEBUG: make sure we allocated the register properly
    assert(std::find(regPool.begin(), regPool.end(), regId) == regPool.end());
    regPool.push_back(regId);
    assert(std::find(regsInUse.begin(), regsInUse.end(), regId) != regsInUse.end());
    regsInUse.erase(regId);
}


/**************** callback functions ******************/ 
using NodeKind = AstNode::Kind;

// we need to visit global variables first so we populate their label
void pass1PreOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node) {
    if(node->kind == NodeKind::GlobVarDecl) {
        // here we just emit to the .data segment
        // and update the symbol with the appropriate label
        // we should have a special case for strings
        auto ident = node->children[0];
        auto type = node->children[1];
        ident->symbol->label = gen->idToAsm(ident->attr);
        if(type->attr == "int" || type->attr == "bool") {
            gen->emitDataWord(ident->symbol->label, "0");
        }
        else {
            gen->emitDataWord(ident->symbol->label, gen->emptyStringLabel);
        }
    }
    else if(node->kind == NodeKind::FuncDecl) {
        auto ident = node->children[0];
        ident->symbol->label = gen->idToAsm(ident->attr);
    }
}

void pass2PreOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node) {
    switch (node->kind) {
        case NodeKind::FuncDecl: {
            auto ident = node->children[0];
            auto sign = node->children[1];
            auto params = sign->children[0];
            auto body = node->children[2];

            //do prologue
            //do function body
            auto label = gen->idToAsm(ident->attr);
            gen->textSeg += label + ":\n";
            gen->lastRetLabel = gen->getLabel();

            // set up the argument registers
            // argument 1 will be stored at -4($fp)
            // argument 2 will be stored at -8($fp)
            // argument 3 will be stored at -12($fp)
            // argument 4 will be stored at -16($fp)
            for(size_t i = 0; i < params->children.size(); i++) {
                auto paramIdent = params->children[i]->children[0];
                paramIdent->symbol->label = std::to_string(int(i+1)*-4) + "($fp)" ;
            }
            gen->offsetFromFp = int(params->children.size()+1) * -4; // evaluates to -4 if there are no params
            // std::cout << "res: " << gen->offsetFromFp << "\n";
            // traverse function body to generate body instructions and determine stack size
            gen->prePostOrderTraversal(body, pass2PreOrderCallback, pass2PostOrderCallback);

            // add prologue
            std::stringstream prologue;
            prologue << "\t# prologue\n";
            // grow stack to save $fp and $ra
            prologue << "\taddiu $sp, $sp, -8\n";
            // save $ra
            prologue << "\tsw   $ra, 4($sp)\n";
            // save $fp
            prologue << "\tsw   $fp, 0($sp)\n";
            // move $sp to $fp
            prologue << "\tmove $fp, $sp\n";
            // now allocate memory for local variables if necessary
            if(gen->offsetFromFp < -4) {
                prologue << "\taddiu $sp, $sp, " << gen->offsetFromFp+4 << "\n";
                for(size_t i = 0; i < params->children.size(); i++) {
                    auto paramIdent = params->children[i]->children[0];
                    prologue << "\tsw $a" << i << ", " << paramIdent->symbol->label << "\n";
                }
            }

            gen->textSeg += prologue.str();
            
            gen->textSeg += "\t# body\n";
            // add function body
            gen->textSeg += gen->currFuncBody;

            // at this point we should have jumped to the ret label for non-void functions
            if(ident->symbol->rvSig != "void") {
                gen->textSeg += "\t# error\n\tj noReturnError\n";
            }

            gen->textSeg += gen->lastRetLabel + ":\n";
            std::stringstream epilogue;
            epilogue << "\t# epilogue\n";
            // now deallocate memory used for local variables if necessary
            if(gen->offsetFromFp < -4) {
                epilogue << "\taddiu $sp, $sp, " << abs(gen->offsetFromFp+4) << "\n";
            }
            // restore $ra and $fp
            epilogue << "\tlw   $fp, 0($sp)\n";
            epilogue << "\tlw   $ra, 4($sp)\n";
            // shrink stack again
            epilogue << "\taddiu $sp, $sp, 8\n";
            epilogue << "\tjr $ra\n";
            gen->textSeg += epilogue.str();

            // cleanup
            gen->currFuncBody = "";
            throw StopTraversalException();
            break;
        }
        // we need to clean up the stack
        // and setup the return value in $v0 if applicable
        case NodeKind::ReturnStmt: {
            std::stringstream retInst;
            retInst << "# return inst\n";
            // if there is a return expr
            // we need to evaluate it and put it in $v0
            if(node->children.size() > 0) {
                // first evaluate return expr
                gen->prePostOrderTraversal(node->children[0], pass2PreOrderCallback, pass2PostOrderCallback);
                // then move the expr value to $v0
                retInst << "\tmove $v0, " << node->children[0]->reg << "\n";
                gen->freeReg(node->children[0]->reg);
            }
            retInst << "\tj " << gen->lastRetLabel;
            // clean up
            gen->emitInst(retInst.str());
            throw StopTraversalException();
            break;
        }
        case NodeKind::VarDecl: {
            auto ident = node->children[0];
            auto type = node->children[1];
            ident->symbol->label = std::to_string(gen->offsetFromFp) + "($fp)";
            std::stringstream inst;
            if(type->attr == "string") {
                auto reg = gen->allocReg();
                inst << "la " << reg << ", " << gen->emptyStringLabel << "\n";
                inst << "\tsw " << reg << ", " << ident->symbol->label;
                gen->freeReg(reg);
            }
            else {
                inst << "sw $0" << ", " << ident->symbol->label << "\t\t# initializing var " << ident->attr;
            }
            gen->emitInst(inst.str());
            gen->offsetFromFp -= 4;
            break;
        }
        case NodeKind::IfStmt: {
            auto expr = node->children[0];
            auto ifBlock = node->children[1];
            auto elseBlock = (node->children.size() == 3) ? node->children[2] : nullptr;
            auto endLabel = gen->getLabel();
            std::stringstream testInst;

            // generate if-expr code first
            gen->prePostOrderTraversal(expr, pass2PreOrderCallback, pass2PostOrderCallback);

            if(elseBlock == nullptr) {
                // if expr is false, go to end label
                testInst << "beq " << expr->reg << ", $0, " << endLabel;
                gen->emitInst(testInst.str());
                gen->freeReg(expr->reg);
                // generate if-block code
                gen->prePostOrderTraversal(ifBlock, pass2PreOrderCallback, pass2PostOrderCallback);
                gen->emitLabel(endLabel);
            }
            else {
                auto elseLabel = gen->getLabel();
                // if expr is false, go to else label
                testInst << "beq " << expr->reg << ", $0, " << elseLabel;
                gen->emitInst(testInst.str());
                gen->freeReg(expr->reg);
                // generate if-block code
                gen->prePostOrderTraversal(ifBlock, pass2PreOrderCallback, pass2PostOrderCallback);
                // unconditional jump to end label
                std::string jumpInst = "j " + endLabel;
                gen->emitInst(jumpInst);
                // generate else block
                gen->emitLabel(elseLabel);
                gen->prePostOrderTraversal(elseBlock, pass2PreOrderCallback, pass2PostOrderCallback);
                gen->emitLabel(endLabel);
            }
            throw StopTraversalException();
            break;
        }
        case NodeKind::ForStmt: {
            auto expr = node->children[0];
            auto block = node->children[1];
            auto loopLabel = gen->getLabel();
            auto exitLabel = gen->getLabel();
            std::stringstream testInst;
            std::stringstream jumpInst;
            // first emit loop label
            gen->emitLabel(loopLabel);
            // eval expr
            gen->prePostOrderTraversal(expr, pass2PreOrderCallback, pass2PostOrderCallback);
            // check expr; exit loop if false
            testInst << "beq " << expr->reg << ", $0, " << exitLabel;
            gen->emitInst(testInst.str());
            gen->freeReg(expr->reg);

            // update the exit label for any break statements
            gen->forStmtExitLabels.push_back(exitLabel);
            // emit loop body
            gen->prePostOrderTraversal(block, pass2PreOrderCallback, pass2PostOrderCallback);
            // emit loop unconditional jump
            jumpInst << "j " << loopLabel;
            gen->emitInst(jumpInst.str());
            // emit exit label
            gen->emitLabel(gen->forStmtExitLabels.back());
            gen->forStmtExitLabels.pop_back();

            throw StopTraversalException();
            break;
        }
        case NodeKind::BreakStmt: {
            std::string breakInst = "j " + gen->forStmtExitLabels.back();
            gen->emitInst(breakInst);
            break;
        }
        // we just want to populate the reg/label for the lhs identifier
        // so we can easily generate the instruction on the post-order traversal
        // we just fetch the reg/label from the symbol of the identifier
        case NodeKind::AssignStmt: {
            auto ident = node->children[0]->children[0];
            auto rhs = node->children[1];
            
            if (ident->symbol->label != "") {
                ident->label = ident->symbol->label;
            }
            // Houston, we have a problem
            else {
               handleError("bad! assign pre");
            }

            gen->prePostOrderTraversal(rhs, pass2PreOrderCallback, pass2PostOrderCallback);

            std::stringstream inst;
            assert(rhs->reg != ""); // DEBUG
            if(ident->reg != "") {
                inst
                    << "move "
                    << ident->reg << ", "
                    << rhs->reg;
            }
            else if(ident->label != "") {
                inst
                    << "sw "
                    << rhs->reg << ", "
                    << ident->label;
            }
            else { // DEBUG
               handleError("bad! assign post"); 
            }
            gen->emitInst(inst.str());
            gen->freeReg(rhs->reg);

            // stop traversal
            throw StopTraversalException();
            break;
        }
        case NodeKind::ExprStmt:
            gen->prePostOrderTraversal(node->children[0], pass2PreOrderCallback, pass2PostOrderCallback);
            gen->freeReg(node->children[0]->reg);
            throw StopTraversalException();
            break;
        case NodeKind::FuncCall: {
            auto ident = node->children[0];
            auto args = node->children[1];
            // std::cout << "handling funccall " << ident->attr << "\n";
            std::string inst;

            // handle args if necessary            
            if (args->children.size() > 4) {
                handleError("Too many arguments to generate function");
            }

            gen->prePostOrderTraversal(args, pass2PreOrderCallback, pass2PostOrderCallback);

            for (size_t i = 0; i < args->children.size(); i++) {
                inst = "move $a" + std::to_string(i) + ", " +
                        args->children[i]->reg;
                gen->emitInst(inst);
                gen->freeReg(args->children[i]->reg);
            }

            // save regs in use
            if(gen->regsInUse.size() > 0) {
                inst = "addiu $sp, $sp, " + std::to_string(int(gen->regsInUse.size()) * -4);
                gen->emitInst(inst);
                int offset = 0;
                for(auto & reg : gen->regsInUse) {
                    inst = "sw " + reg + ", " + std::to_string(offset) + "($sp)";
                    gen->emitInst(inst);
                    offset += 4;
                }
            }
            
            // now handle function call
            assert(ident->symbol->label != "");
            inst = "jal " + ident->symbol->label;
            gen->emitInst(inst);

            // do cleanup
            if(gen->regsInUse.size() > 0) {
                int offset = 0;
                for(auto & reg : gen->regsInUse) {
                    inst = "lw " + reg + ", " + std::to_string(offset) + "($sp)";
                    gen->emitInst(inst);
                    offset += 4;
                }
                inst = "addiu $sp, $sp, " + std::to_string(int(gen->regsInUse.size()) * 4);
                gen->emitInst(inst);
            }

            node->reg = gen->allocReg();
            if (ident->symbol->rvSig != "void") {
                inst = "move " + node->reg + ", $v0";
                gen->emitInst(inst);
            }

            throw StopTraversalException();
            break;
        }
        case NodeKind::BinaryExpr: {
            if(node->attr == "||" || node->attr == "&&") {
                auto lhs = node->children[0];
                auto rhs = node->children[1];

                // we always have to evaluate the lhs
                gen->prePostOrderTraversal(lhs, pass2PreOrderCallback,
                                           pass2PostOrderCallback);
                // just use the lhs reg to be a bit cleaner
                node->reg = lhs->reg;

                if(node->attr == "&&") {
                    std::string inst;
                    auto skipLabel = gen->getLabel();
                    // if the first lhs is false, dont execute rhs
                    inst = "beq $0, " + node->reg + ", " + skipLabel;
                    gen->emitInst(inst);
                    // std::cout << "enter\n";
                    gen->prePostOrderTraversal(rhs, pass2PreOrderCallback,
                                           pass2PostOrderCallback);
                    // std::cout << "exit\n";
                    // the final result is a simple bitwise AND of the two operands
                    inst = "and " + node->reg + ", " + lhs->reg + ", " + rhs->reg;
                    gen->emitInst(inst);
                    gen->emitLabel(skipLabel);
                    gen->freeReg(rhs->reg);
                }
                else if (node->attr == "||") {
                    std::string inst;
                    // just use the lhs reg to be a bit cleaner
                    node->reg = lhs->reg;
                    auto skipLabel = gen->getLabel();
                    // if the first lhs is true, dont execute rhs
                    inst = "bne $0, " + node->reg + ", " + skipLabel;
                    gen->emitInst(inst);
                    // std::cout << "enter\n";
                    gen->prePostOrderTraversal(rhs, pass2PreOrderCallback,
                                           pass2PostOrderCallback);
                    // std::cout << "exit\n";
                    // the final result is a simple bitwise OR of the two operands
                    inst = "or " + node->reg + ", " + lhs->reg + ", " + rhs->reg;
                    gen->emitInst(inst);
                    gen->emitLabel(skipLabel);
                    gen->freeReg(rhs->reg);
                }
                // std::cout << "here\n";
                throw StopTraversalException();
            }
            break;
        }            
        default:
            break;
    }
}

void pass2PostOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node) {
    switch (node->kind) {
        // load integer value into a register
        case NodeKind::IntLit: {
            node->reg = gen->allocReg();
            std::stringstream res;
            res << "li " << node->reg << ", " << node->attr;
            gen->emitInst(res.str());
            break;
        }
        // we keep track of every str lit in a map and emit them all at the end
        // load the address of the str lit into a register
        case NodeKind::StrLit: { 
            // handle special characters
            std::string cleanString;
            for(size_t i = 0; i < node->attr.size(); i++) {
                int c = node->attr[i];
                if(c == 92 && i < node->attr.length()-1) {
                    int nextC = node->attr[i+1];
                    switch (nextC) {
                        case 98:   // \b
                            cleanString += "\b";
                            break;
                        case 102:   // \f
                            cleanString += "\f";
                            break;
                        case 110:   // \n
                            cleanString += "\n";
                            break;
                        case 114:   // \r
                            cleanString += "\r";
                            break;
                        case 116:   // \t
                            cleanString += "\t";
                            break;
                        case 92:   /* \\ */
                            cleanString += "\\";
                            break;
                        case 34:   // \"
                            cleanString += "\"";
                            break;
                        default: 
                            std::cout << "found char " << nextC << std::endl;
                            break;
                    }
                    i += 1;
                    continue;
                }
                cleanString += char(c);
            }
            if(gen->orderedstringLits.find(cleanString) == gen->orderedstringLits.end()) {
                gen->orderedstringLits[cleanString] = gen->getLabel();
            }
            node->reg = gen->allocReg();
            std::string inst = "la " + node->reg + ", " + gen->orderedstringLits[cleanString];
            gen->emitInst(inst);
            break;
        }
        // we need to either evaluate the result of the expression into a register
        // or copy the register holding the result if there is no operation
        // we only free the register if it is not a local variable
        case NodeKind::UnaryExpr: {
            // std::cout << "3\n";
            auto operand = node->children[0];
            if(operand->kind == NodeKind::Ident) {
                // DEBUG: make sure that both label and reg are not populated for the same variable
                assert(operand->symbol->reg == "" || operand->symbol->label == "");
                if(operand->symbol->reg != "") {
                    operand->reg = operand->symbol->reg;
                }
                else if(operand->symbol->label != "") {
                    operand->reg = gen->allocReg();
                    std::string instr = "lw " + operand->reg + ", " + operand->symbol->label;
                    gen->emitInst(instr);
                }
                // DEBUG: make sure that both label and reg are not both empty
                else {
                    handleError("bad! unary");
                }
            }
 
            assert(operand->reg != "");
            if(node->attr != "") {
                node->reg = operand->reg;
                std::string res;
                if(node->attr == "u-") {
                    res = "subu " + node->reg + ", $0, " + operand->reg;
                }
                else if(node->attr == "!") {
                    res = "xori " + node->reg + ", " + operand->reg + ", 1";
                }
                else {
                    handleError("bad unaryexpr op!");
                }
                gen->emitInst(res);
            }
            else {
                // just pass the register upwards if there is no operation
                node->reg = operand->reg;
            }

            // DEBUG: we've done something wrong if we are leaving this function with no reg assigned
            assert(node->reg != "");
            break;
        }
        // we need to evaluate the result of the expression into a register
        // we only free the registers if they are not local variables
        case NodeKind::BinaryExpr: {
            // std::cout << "1\n";
            if(node->attr != "&&" && node->attr != "||") {
                // std::cout << "2\n";
                auto lhs = node->children[0];
                auto rhs = node->children[1];
                if(node->attr == "/" || node->attr == "%") {
                    std::string checkInst;
                    checkInst = "addiu $sp, $sp, -8";
                    gen->emitInst(checkInst);
                    checkInst = "sw $a0, 4($sp)";
                    gen->emitInst(checkInst);
                    checkInst = "sw $a1, ($sp)";
                    gen->emitInst(checkInst);
                    checkInst = "move $a0, " + lhs->reg;
                    gen->emitInst(checkInst);
                    checkInst = "move $a1, " + rhs->reg;
                    gen->emitInst(checkInst);
                    checkInst = "jal divModChk";
                    gen->emitInst(checkInst);
                    checkInst = "move " + rhs->reg + ", $v0";
                    gen->emitInst(checkInst);
                    checkInst = "lw $a0, 4($sp)";
                    gen->emitInst(checkInst);
                    checkInst = "lw $a1, ($sp)";
                    gen->emitInst(checkInst);
                    checkInst = "addiu $sp, $sp, 8";
                    gen->emitInst(checkInst);
			    }
                assert(lhs->reg != "");
                assert(rhs->reg != "");
                node->reg = lhs->reg;
                char inst[256];	//no buffer overflows pls!!
                sprintf(inst, opToAsm[node->attr].c_str(), node->reg.c_str(), lhs->reg.c_str(), rhs->reg.c_str());
                gen->emitInst(std::string(inst));
                gen->freeReg(rhs->reg);
            }
            break;
        }
        default:
            break;
    }
}
}