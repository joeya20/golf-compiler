.PHONY: clean

CC := gcc
CXX := g++
CFLAGS := -Wall
CXXFLAGS := -Wall
LDFLAGS := 
SRC_PATH := src
BIN_PATH := bin
BUILD_PATH := build

golf: $(BUILD_PATH)/util.o $(BUILD_PATH)/lex.yy.o $(BUILD_PATH)/lexer.o $(BUILD_PATH)/parse.tab.o $(BUILD_PATH)/AstNode.o $(BUILD_PATH)/SemanticAnalyzer.o $(BUILD_PATH)/SymbolTable.o $(BUILD_PATH)/Symbol.o $(BUILD_PATH)/main.o
	$(CXX) $(CFLAGS) -o $@ $^

$(BUILD_PATH)/main.o: $(SRC_PATH)/main.cpp $(SRC_PATH)/main.hpp $(SRC_PATH)/parse.tab.cc $(SRC_PATH)/lexer.cpp $(SRC_PATH)/lexer.hpp $(SRC_PATH)/util.cpp $(SRC_PATH)/util.hpp
	$(CXX) -c $(CFLAGS) -o $@ $<

$(BUILD_PATH)/util.o: $(SRC_PATH)/util.cpp $(SRC_PATH)/util.hpp $(SRC_PATH)/main.cpp $(SRC_PATH)/main.hpp
	$(CXX) -c $(CFLAGS) -o $@ $<

$(BUILD_PATH)/lexer.o: $(SRC_PATH)/lexer.cpp $(SRC_PATH)/lexer.hpp $(SRC_PATH)/util.cpp $(SRC_PATH)/util.hpp $(SRC_PATH)/parse.tab.cc
	$(CXX) -c $(CFLAGS) -o $@ $<

$(BUILD_PATH)/AstNode.o: $(SRC_PATH)/AstNode.cpp $(SRC_PATH)/AstNode.hpp
	$(CXX) -c $(CFLAGS) -o $@ $<

$(BUILD_PATH)/lex.yy.o: $(SRC_PATH)/lex.yy.cc $(SRC_PATH)/parse.tab.cc
	$(CXX) -c $(CFLAGS) -o $@ $<

$(SRC_PATH)/lex.yy.cc: $(SRC_PATH)/lex.l $(SRC_PATH)/parse.tab.cc $(SRC_PATH)/lexer.cpp $(SRC_PATH)/lexer.hpp $(SRC_PATH)/util.cpp $(SRC_PATH)/util.hpp
	flex -o $@ $<
	
$(BUILD_PATH)/parse.tab.o: $(SRC_PATH)/parse.tab.cc
	$(CXX) -c $(CFLAGS) $^ -o $@

$(SRC_PATH)/parse.tab.cc: $(SRC_PATH)/parse.y $(SRC_PATH)/AstNode.hpp
	bison -o $@ $<

$(BUILD_PATH)/SemanticAnalyzer.o: $(SRC_PATH)/SemanticAnalyzer.cpp $(SRC_PATH)/SemanticAnalyzer.hpp
	$(CXX) -c $(CFLAGS) $< -o $@

$(BUILD_PATH)/SymbolTable.o: $(SRC_PATH)/SymbolTable.cpp $(SRC_PATH)/SymbolTable.hpp
	$(CXX) -c $(CFLAGS) $< -o $@

$(BUILD_PATH)/Symbol.o:  $(SRC_PATH)/Symbol.cpp $(SRC_PATH)/Symbol.hpp
	$(CXX) -c $(CFLAGS) $< -o $@

clean:
	-rm $(BUILD_PATH)/*.o $(SRC_PATH)/lex.yy.cc $(SRC_PATH)/parse.tab.* $(SRC_PATH)/location.hh golf