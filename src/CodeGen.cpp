
#include "CodeGen.hpp"
#include "AstNode.hpp"
#include "util.hpp"
#include <memory>
#include <unordered_map>

// use table-driven generation
// generate string on entry and exit of a node
namespace GoLF {

static const std::unordered_map<std::string, std::string> opToAsm = {
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
    {   "!="    ,    "sne"  },
    // unary ops
    {   "u-"    ,    "neg"  },
    // {   "!"    ,     "neg"  },   // TODO: TBD

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

std::string CodeGen::allocReg(CodeGen::RegType type) {
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
        case NodeKind::FuncDecl:
            //do prologue
            //do function body
            //do epilogue

            break;
        case NodeKind::GlobVarDecl:
            // emit to data segment
            break;

        case NodeKind::IfStmt:
            break;

        case NodeKind::ForStmt:
            break;
            
        default:
            break;
    }
}

//handles leaf nodes
void pass1PostOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node) {
    switch (node->kind) {
        case NodeKind::IntLit:
            break;
        case NodeKind::StrLit:
            break;
        case NodeKind::ForStmt:
            break;
        default:
            break;
    }
}
}