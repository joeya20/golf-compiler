#include "CodeGen.hpp"
#include "util.hpp"
#include <memory>
#include <sstream>
#include <unordered_map>
#include <assert.h>
#include <algorithm>

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
    emitPreamble();
    // do traversal(s)
    preOrderTraversal(this->root, pass1PreOrderCallback);
    prePostOrderTraversal(this->root, pass2PreOrderCallback, pass2PostOrderCallback);
    // emit code
    emitDataSeg();
    prog += "\n";
    emitTextSeg();
}

// emit things that are always output, such as the built-in functions
void CodeGen::emitPreamble() {
    prog += 
R"(

# start of RTS
    .data
LtrueString:
    .asciiz "true"
LfalseString:
    .asciiz "false"
    .align 4
Ltrue:
    .word 1
Lfalse:
    .word 0

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

void CodeGen::emitDataWord(const std::string& label) {
    dataSeg += label + ":\n";
    dataSeg += "\t .word 0\n";
}

// emit all strings after traversal, before emitDataSeg
void CodeGen::emitStrLits() {
    for(auto & str : orderedstringLits) {
        dataSeg += str.second + ":\n";
        dataSeg += "\t .asciiz ";
        dataSeg += str.first + "\n";
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

const std::string CodeGen::allocReg(CodeGen::RegType type) {
    if(this->regPool[type].size() == 0) {
        // output error for now
        handleError("No register available!");
    }
    auto res = regPool[type].back();
    regPool[type].pop_back();
    return res;
}

void CodeGen::freeReg(CodeGen::RegType type, const std::string& regId) {
    // DEBUG: make sure we allocated the register properly
    assert(std::find(regPool[type].begin(), regPool[type].end(), regId) == regPool[type].end());
    regPool[type].push_back(regId);
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

        // // if its a string, we just assign it the empty string label
        // // FIX this: we should allocate a word to store the address
        // if(type->attr == "string") {
        //     ident->symbol->label = gen->emptyStringLabel;
        // }
        // // else (for ints and bools) we allocate a word in the data segment
        // else {
        ident->symbol->label = gen->idToAsm(ident->attr);
        gen->emitDataWord(ident->symbol->label);
        // }
        if(type->attr == "string") {
            auto reg = gen->allocReg(CodeGen::RegType::Temp);
            std::stringstream inst;
            // first load in the address of the empty string
            inst << "la " << reg << ", " << gen->emptyStringLabel << "\n";
            // then save it to the data word allocated for the string
            inst << "\tsw " << reg << ", " << ident->symbol->label;
            gen->emitInst(inst.str());
            gen->freeReg(CodeGen::RegType::Temp, reg);
        }
    }
}

void pass2PreOrderCallback(CodeGen* gen, std::shared_ptr<AstNode> node) {
    switch (node->kind) {
        // here we just emit to the .data segment
        // and update the symbol with the appropriate label
        // we should have a special case for strings
        // case NodeKind::GlobVarDecl: {
        //     auto ident = node->children[0];
        //     auto type = node->children[1];

        //     // if its a string, we just assign it the empty string label
        //     if(type->attr == "string") {
        //         ident->symbol->label = gen->emptyStringLabel;
        //     }
        //     // else (for ints and bools) we allocate a word in the data segment
        //     else {
        //         ident->symbol->label = gen->idToAsm(ident->attr);
        //         gen->emitDataWord(ident->label);
        //     }
        // }
            // break;
        case NodeKind::FuncDecl: {
            std::cout << "here\n";
            auto ident = node->children[0];
            auto sign = node->children[1];
            auto params = sign->children[0];
            auto body = node->children[2];

            //do prologue
            //do function body
            auto label = gen->idToAsm(ident->attr);
            gen->emitLabel(label);

            // allocate a register for each param
            for(auto & paramDecl : params->children) {
                paramDecl->symbol->reg = gen->allocReg(CodeGen::RegType::Saved);
            }

            // traverse function body to generate instructions
            gen->prePostOrderTraversal(body, pass2PreOrderCallback, pass2PostOrderCallback);
            
            // free param registers
            for(auto & paramDecl : params->children) {
                gen->freeReg(CodeGen::RegType::Saved, paramDecl->symbol->reg);
            }

            // update text segment and reset currFuncBody
            gen->textSeg += "\n" + gen->currFuncBody;
            gen->currFuncBody = "";
            throw StopTraversalException();
            break;
        }
        // allocate a register for variable
        // keep track of how many/which register is used
        // so we can the populate the function prologue
        case NodeKind::VarDecl: {
            auto ident = node->children[0];
            auto type = node->children[1];
            ident->symbol->reg = gen->allocReg(CodeGen::RegType::Saved);
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
                // generate if-block code
                gen->prePostOrderTraversal(ifBlock, pass2PreOrderCallback, pass2PostOrderCallback);
                gen->emitLabel(endLabel);
            }
            else {
                auto elseLabel = gen->getLabel();
                // if expr is false, go to else label
                testInst << "beq " << expr->reg << ", $0, " << elseLabel;
                gen->freeReg(CodeGen::RegType::Temp, expr->reg);
                gen->emitInst(testInst.str());
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
        case NodeKind::ForStmt:
            break;
        // we just want to populate the reg/label for the lhs identifier
        // so we can easily generate the instruction on the post-order traversal
        // we just fetch the reg/label from the symbol of the identifier
        case NodeKind::AssignStmt: {
            auto ident = node->children[0]->children[0];
            auto rhs = node->children[1];
            std::cout << "reg: " << ident->symbol->reg << std::endl;
            std::cout << "lbl: " << ident->symbol->label << std::endl;
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

            // visit RHS only so we don't load in the value of the LHS unnecesarily
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
            gen->freeReg(CodeGen::RegType::Temp, rhs->reg);

            // stop traversal
            throw StopTraversalException();
            break;
        }
        // unary expressions with identifiers are handled here
        // two possiblities: local and global variable
        // for local, we just get its register from the symbol
        // for global, we load its value from the label
        // TODO: boolean smashing
        case NodeKind::UnaryExpr: {
            auto operand = node->children[0];
            if(operand->kind == NodeKind::Ident) {
                // DEBUG: make sure that both label and reg are not populated for the same variable
                assert(operand->symbol->reg == "" || operand->symbol->label == "");

                if(operand->symbol->reg != "") {
                    operand->reg = operand->symbol->reg;
                }
                else if(operand->symbol->label != "") {
                    operand->reg = gen->allocReg(CodeGen::RegType::Temp);
                    std::stringstream instr;
                    if(operand->sig == "string") {
                        instr
                            << "la "
                            << operand->reg << ", "
                            << operand->symbol->label;
                    }
                    else {
                        instr
                            << "lw "
                            << operand->reg << ", "
                            << operand->symbol->label;
                    }
                    gen->emitInst(instr.str());
                }
                // DEBUG: make sure that both label and reg are not both empty
                else {
                    handleError("bad! unaryExpr pre");
                }
            }
            break;
        }
        case NodeKind::FuncCall: {
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
            node->reg = gen->allocReg(CodeGen::RegType::Temp);
            std::stringstream res;
            res << "li " << node->reg << ", " << node->attr;
            gen->emitInst(res.str());
            break;
        }
        // we keep track of every str lit in a map and emit them all at the end
        // load the address of the str lit into a register
        case NodeKind::StrLit: { 
            auto label = gen->getLabel();
            gen->orderedstringLits[node->attr] = label;
            node->reg = gen->allocReg(CodeGen::RegType::Temp);
            std::stringstream res;
            res << "la " << node->reg << ", " << label;
            gen->emitInst(res.str());
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
                gen->emitInst(res.str());
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
            gen->emitInst(res.str());
            if(lhs->kind != NodeKind::Ident || lhs->label != "") {
                gen->freeReg(CodeGen::RegType::Temp, lhs->reg);
            }
            if(rhs->kind != NodeKind::Ident || rhs->label != "") {
                gen->freeReg(CodeGen::RegType::Temp, rhs->reg);
            }
            break;
        }
        default:
            break;
    }
}
}