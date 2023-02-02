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
./golf <input file>     # should really be ./bin/golf but spec say executable should be in root directory
```

### Cleaning
1. Run clean Makefile recipe ```make clean```