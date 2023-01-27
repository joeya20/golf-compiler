.PHONY: clean

CC := gcc
CFLAGS := -Wall
LDFLAGS := 
SRC_PATH := src
BIN_PATH := bin
BUILD_PATH := build

$(BIN_PATH)/golf: $(BUILD_PATH)/main.o $(BUILD_PATH)/lexer.o $(BUILD_PATH)/lex.yy.o $(BUILD_PATH)/util.o
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_PATH)/main.o: $(SRC_PATH)/main.c $(SRC_PATH)/main.h
	$(CC) -c $(CFLAGS) $(SRC_PATH)/main.c -o $@

$(BUILD_PATH)/lexer.o: $(SRC_PATH)/lexer.c $(SRC_PATH)/lexer.h
	$(CC) -c $(CFLAGS) $(SRC_PATH)/lexer.c -o $@

$(BUILD_PATH)/util.o: $(SRC_PATH)/util.c $(SRC_PATH)/util.h
	$(CC) -c $(CFLAGS) $(SRC_PATH)/util.c -o $@

$(BUILD_PATH)/lex.yy.o: $(SRC_PATH)/lex.yy.c
	$(CC) -c $(CFLAGS) $^ -o $@

$(SRC_PATH)/lex.yy.c:  $(SRC_PATH)/lex.l
	flex -o $@ $(SRC_PATH)/lex.l

clean:
	-rm $(BUILD_PATH)/*.o $(BIN_PATH)/golf $(SRC_PATH)/lex.yy.c