.PHONY: clean

CCX := g++
CCXFLAGS := -Wall
LDFLAGS := 
SRC_PATH := src
BIN_PATH := bin
BUILD_PATH := build

$(BIN_PATH)/golf: $(BUILD_PATH)/entry.o $(BUILD_PATH)/lexer.o
	$(CCX) $(CCXFLAGS) $^ -o $@

$(BUILD_PATH)/entry.o: $(SRC_PATH)/entry.cpp $(SRC_PATH)/entry.h
	$(CCX) -c $(CCXFLAGS) $(SRC_PATH)/entry.cpp -o $@

$(BUILD_PATH)/lexer.o: $(SRC_PATH)/lexer.cpp $(SRC_PATH)/lexer.h
	$(CCX) -c $(CCXFLAGS) $(SRC_PATH)/lexer.cpp -o $@

clean:
	-rm $(BUILD_PATH)/*.o $(BIN_PATH)/golf