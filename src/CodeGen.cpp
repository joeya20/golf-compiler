#include "CodeGen.hpp"
#include "AstNode.hpp"
#include "util.hpp"
#include <memory>
#include <sstream>
#include <unordered_map>
#include <assert.h>

// use table-driven generation
// generate string on entry and exit of a node
namespace GoLF {

static std::unordered_map<std::string, std::string> opToAsm = {
    // binary ops
    {   "+"     ,    "add"  },
    {   "-"     ,    "sub"  }, 
    {   "*"     ,    "mult" }, 
    {   "/"     ,    "div"  },  // read quotient from mfho
    {   "%"     ,    "div"  },  // read remainder from mfhi
    {   "<"     ,    "slt"  },
    {   "<="    ,    "sle"  },
    {   ">"     ,    "sgt"  },
    {   ">="    ,    "sge"  },
    {   "=="    ,    "seq"  },
    {   "!="    ,    "sne"  }
};

CodeGen::CodeGen(std::shared_ptr<AstNode> root) {
    this->regPool = {
        {CodeGen::RegType::Temp, 
            {"$t0", "$t1", "$t2", "$t3",  "$t4",
            "$t5", "$t6", "$t7", "$t8", "$t9"}},
        {CodeGen::RegType::Saved, 
            {"$s0", "$s1", "$s2", "$s3",  "$s4",
            "$s5", "$s6", "$s7"}},
        {CodeGen::RegType::Arg, 
            {"$a0", "$a1", "$a2", "$a3"}},
        {CodeGen::RegType::Ret,
            {"$v0", "$v1"}},
    };
    this->root = root;
}

void CodeGen::preOrderTraversal(
    std::shared_ptr<AstNode> node,
    std::function<void(CodeGen *, std::shared_ptr<AstNode>)>
        callback) {
  callback(this, node);
  for (size_t i = 0; i < node->children.size(); i++) {
    try {
        preOrderTraversal(node->children[i], callback);
    }
    catch (StopTraversalException& stop) {
        break;
    }
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
  preCallback(this, node);
  for (size_t i = 0; i < node->children.size(); i++) {
    try {
        prePostOrderTraversal(node->children[i], preCallback, postCallback);
    }
    catch (StopTraversalException& stop) {
        break;
    }
  }
  postCallback(this, node);
}

// main function that gets called to generate MIPS assembly
void CodeGen::generate() {
    emitPreamble();
}

// emit things that are always output, such as the built-in functions
void CodeGen::emitPreamble() {
    prog += 
R"(
    .data
LtrueString:
    .asciiz "true"
LfalseString:
    .asciiz "false"

    .text
Lhalt:
    li $v0 10
    syscall
    jr $ra

# will populate $v0
LgetChar:
    li $v0 12
    syscall
    jr $ra

# assumes $a0 is loaded with address of string
Llen:
    # initialize length variable to 0
    addi $t0 $0 0
Lcount:
    # load in character at address in $a0
    lb $t1 $a0
    # we've reached EOS if the byte == 0
    beq $t1 $0 LretLen
    # else we increment length and the address
    addi $t0 $t0 1
    addi $a0 $a0 1
    j Lcount
LretLen:
    # move length to return register and return
    addi $v0 $t0 0
    jr $ra

# assumes $a0 is loaded with boolean to print
Lprintb:
    # if the boolean value is 0 then print false
    beq $0 $a0 LprintFalse
    # else print true
    la $a0 LtrueString
    jal Lprints
    jr $ra
LprintFalse:
    la $a0 LfalseString
    jal Lprints
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
)";
}

// returns label for jump and branch instructions
std::string CodeGen::getLabel() {
    static int count = 1;
    return "L" + std::to_string(count);
}

const std::string CodeGen::allocReg(CodeGen::RegType type) {
    if(this->regPool[type].size() == 0) {
        // output error for now
        handleError("No register available!");
    }
    auto res = regPool[type].back();
    regPool[type].pop_back();
    return res;
}

// std::string CodeGen::allocStaticMem();
// std::string CodeGen::allocStackMem();
// void CodeGen::emit();

/**************** callback functions ******************/ 
using NodeKind = AstNode::Kind;
void pass1PreOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node) {
    switch (node->kind) {
        // here we just emit to the .data segment
        // and update the symbol with the appropriate label
        case NodeKind::GlobVarDecl:
            emitData(label, value, allocType);
            break;
        case NodeKind::FuncDecl:
            //do prologue
            //do function body
            //do epilogue
            break;
        case NodeKind::VarDecl:
            break;
        // here we just want to populate the reg/label for the lhs identifier
        // so we can easily generate the instruction on the post-order traversal
        // we just fetch the reg/label from the symbol of the identifier
        case NodeKind::AssignStmt: {
            auto ident = node->children[0];
            // check if the variable is local
            if(ident->symbol->reg != "") {
                ident->reg = ident->symbol->reg;
            }
            // check if the variable is global
            else if(ident->symbol->label != "") {
                ident->label = ident->symbol->label;
            }
            // Houston, we have a problem
            else {
               handleError("bad! assign pre");
            }
            break;
        }
        // unary expressions with identifiers are handled here
        // two possiblities: local and global variable
        // for local, we just get its register from the symbol
        // for global, we load its value from the label
        case NodeKind::UnaryExpr: {
            auto operand = node->children[0];
            if(operand->kind == NodeKind::Ident) {
                if(operand->symbol->reg != "") {
                    operand->reg = operand->symbol->reg;
                }
                else if(operand->symbol->label != "") {
                    operand->reg = gen->allocReg(CodeGen::RegType::Temp);
                    std::stringstream instr;
                    instr
                        << "lw "
                        << operand->reg << ", "
                        << operand->symbol->label;
                    emitInst(instr);
                }
                // Houston, we have a problem
                else {
                    handleError("bad! unaryExpr pre");
                }
            }
            break;
        }
        case NodeKind::IfStmt:
            break;
        case NodeKind::ForStmt:
            break;
        default:
            break;
    }
}

void pass1PostOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node) {
    switch (node->kind) {
        case NodeKind::IntLit: {
            node->reg = gen->allocReg(CodeGen::RegType::Temp);
            std::stringstream res;
            res << "li " << node->reg << ", " << node->attr;
            emitInst(res.str());
            break;
        }
        case NodeKind::StrLit: { //TODO
            // node->reg = gen->allocReg(CodeGen::RegType::Temp);
            // std::stringstream res;
            // res << "li " << node->reg << ", " << node->attr;
            // emitInst(res.str());
            break;
        }
        // we need to either evaluate the result of the expression into a register
        // or copy the register holding the result if there is no operation
        // we only free the register if it is not a local variable
        case NodeKind::UnaryExpr: {
            if(node->attr != "") {
                node->reg = gen->allocReg(CodeGen::RegType::Temp);
                auto operand = node->children[0];
                std::stringstream res;
                if(node->attr == "u-") {
                    res << "sub " << node->reg << ", $0, " << operand->reg;
                }
                else if(node->attr == "!") {
                    res << "xori " << node->reg << ", " << operand->reg << ", 1";
                }
                else {
                    handleError("bad!");
                }
                emitInst(res.str());
                // register freeing for local identifiers is handled seperately
                if(operand->kind != NodeKind::Ident || operand->label != "") {
                    gen->freeReg(CodeGen::RegType::Temp, node->children[0]->reg);
                }
            }
            else {
                // if there is no operation just copy the reg from the child
                node->reg = node->children[0]->reg;
            }
            break;
        }
        // we need to evaluate the result of the expression into a register
        // we only free the registers if they are not local variables
        case NodeKind::BinaryExpr: {
            auto lhs = node->children[0];
            auto rhs = node->children[1];
            node->reg = gen->allocReg(CodeGen::RegType::Temp);
            std::stringstream res;
            res
                << opToAsm[node->attr] << " "
                << node->reg << ", "
                << node->children[0]->reg << ", "
                << node->children[1]->reg;
            emitInst(res.str());
            if(lhs->kind != NodeKind::Ident || lhs->label != "") {
                gen->freeReg(CodeGen::RegType::Temp, lhs->reg);
            }
            if(rhs->kind != NodeKind::Ident || rhs->label != "") {
                gen->freeReg(CodeGen::RegType::Temp, rhs->reg);
            }
            break;
        }
        // the lhs of an assignment can be either a reg or a label for a globVar
        // at this point, the reg/label for the lhs MUST have been allocated
        case NodeKind::AssignStmt: {  
            std::stringstream res;
            auto lhs = node->children[0];
            auto rhs = node->children[1];
            assert(rhs->reg != ""); // DEBUG
            if(lhs->reg != "") {
                res
                    << "move "
                    << lhs->reg << ", "
                    << rhs->reg;
            }
            else if(node->label != "") {
                res
                    << "sw "
                    << rhs->reg << ", "
                    << rhs->label;
            }
            else { // DEBUG
               handleError("bad! assign post"); 
            }
            emitInst(res.str());
            break;
        }
        default:
            break;
    }
}

void CodeGen::emitData(const std::string& label, const std::string& allocType) {
    
}

void CodeGen::emitInst() {

}

}