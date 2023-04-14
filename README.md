# GoLF Compiler

## Introduction     
This repository contains a compiler that translates "GoLF", a subset of the Go Language, into MIPS assembly.

## Instructions

### Install dependencies:
1. Flex
2. Bison

```bash
<sudo> apt install flex
<sudo> apt install Bison
```

### Build and run compiler:
1. Run default Makefile recipe
2. Run executable. This will write the generated assembly to stdout; redirect using bash to save to a file.

```bash
make
./bin/golf <input file> > <output file>
```
### simulate using Mars:
1. see instructions here: 

### Cleaning
1. Run clean Makefile recipe - ```make clean```

## Language Specification

The language specification for GoLF can be found [here](./GoLF%20Specification.html).