# GoLF

## Introduction     
This repository contains the CPSC 411 course project, a compiler that translates "GoLF", a subset of the Go Language, into MIPS assembly for emulation.

## Instructions

### Dependencies:
1. Flex - ```apt install flex```

### Building and running program
1. Run default Makefile recipe
2. Run executable

```bash
make
./golf <input file>     # should really be ./bin/golf but spec says executable should be in root directory
```

### Cleaning
1. Run clean Makefile recipe ```make clean```

## Milestones

### Milestone 3
- [DONE] An identifier is redefined within the same scope.   
- [DONE] An undeclared identifier is used.
- [?] A type was needed but something other than a type was used.
- [?] A type was used in a context where a type didn't belong.
- [DONE] An if-, if-else, or for-condition must be of Boolean type.
- [DONE] Type mismatch for an operator (||, &&, ==, !=, =, <, >, <=, >=, +, - (unary and binary), *, /, %, !).
- [DONE] Calling something that isn't a function.
- [TODO] The number/type of arguments in a function call doesn't match the function's declaration.
- [DONE] No main declaration found.
- [DONE] Multiple main declarations found.
- [Pass 4] The main function can't have a return value.
- [DONE] The left-hand side of an assignment may only be a variable.
- [?] A constant may not be assigned to.
- [Pass 4] break statements must be inside a for statement.
- [Pass 4] A return statement in a void function (i.e., one without a declared result type) can't return a value.
- [Pass 4] A return statement in a non-void function must return a value.
- [Pass 4] A value returned from a non-void function has the wrong type.
- [Pass 4] An integer literal is out of range.
- [Pass 4] No return statements at all are present in a non-void function. Note that you're only checking for the existence of an appropriate return statement at the semantic checking stage, not whether it's actually executed.