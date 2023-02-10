.PHONY: clean

CC := gcc
CXX := g++
CFLAGS := -Wall
CXXFLAGS := -Wall
LDFLAGS := 
SRC_PATH := src
BIN_PATH := bin
BUILD_PATH := build

golf: $(BUILD_PATH)/main.o $(BUILD_PATH)/lexer.o $(BUILD_PATH)/lex.yy.o $(BUILD_PATH)/parse.tab.o $(BUILD_PATH)/util.o
	$(CXX) $(CFLAGS) $^ -o $@

$(BUILD_PATH)/main.o: $(SRC_PATH)/main.cpp $(SRC_PATH)/main.hpp
	$(CXX) -c $(CFLAGS) $(SRC_PATH)/main.cpp -o $@

$(BUILD_PATH)/lexer.o: $(SRC_PATH)/lexer.cpp $(SRC_PATH)/lexer.hpp
	$(CXX) -c $(CFLAGS) $(SRC_PATH)/lexer.cpp -o $@

$(BUILD_PATH)/util.o: $(SRC_PATH)/util.cpp $(SRC_PATH)/util.hpp
	$(CXX) -c $(CFLAGS) $(SRC_PATH)/util.cpp -o $@

$(BUILD_PATH)/lex.yy.o: $(SRC_PATH)/lex.yy.cc
	$(CXX) -c $(CFLAGS) $^ -o $@

$(BUILD_PATH)/parse.tab.o: $(SRC_PATH)/parse.tab.cc
	$(CXX) -c $(CFLAGS) $^ -o $@

$(SRC_PATH)/lex.yy.cc:  $(SRC_PATH)/lex.l
	flex -o $@ $^

$(SRC_PATH)/parse.tab.cc:  $(SRC_PATH)/parse.y
	bison -o $@ $^

clean:
	-rm $(BUILD_PATH)/*.o $(SRC_PATH)/lex.yy.cc $(SRC_PATH)/parse.tab.cc golf