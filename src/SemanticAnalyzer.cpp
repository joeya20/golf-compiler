#include "SemanticAnalyzer.hpp"

namespace GoLF {
    SemanticAnalyzer::SemanticAnalyzer(std::shared_ptr<AstNode> root) : root(root) {}

    void SemanticAnalyzer::doAnalysis() {
        // first pass -- build up symbol table
        buildSymbolTable();

        // second pass -- ?
    }

    // The semantic checker should keep track of symbols in the program and their attributes using a symbol table
    void SemanticAnalyzer::buildSymbolTable() {
        
    }

    // An identifier is redefined within the same scope.
    // An undeclared identifier is used.
    // A type was needed but something other than a type was used.
    // A type was used in a context where a type didn't belong.
    // An if-, if-else, or for-condition must be of Boolean type.
    // Type mismatch for an operator (||, &&, ==, !=, =, <, >, <=, >=, +, - (unary and binary), *, /, %, !).
    // Calling something that isn't a function.
    // The number/type of arguments in a function call doesn't match the function's declaration.
    // No main declaration found.
    // Multiple main declarations found.
    // The main function can't have a return value.
    // The left-hand side of an assignment may only be a variable.
    // A constant may not be assigned to.
    // break statements must be inside a for statement.
    // A return statement in a void function (i.e., one without a declared result type) can't return a value.
    // A return statement in a non-void function must return a value.
    // A value returned from a non-void function has the wrong type.
    // An integer literal is out of range.
    // No return statements at all are present in a non-void function. Note that you're only checking for the existence of an appropriate return statement at the semantic checking stage, not whether it's actually executed.
}