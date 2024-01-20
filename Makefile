CC = gcc
CXX = g++

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TEST_SRC_DIR = ./testsrc

CXXFLAGS = -std = c++17 -I $(INC_DIR)
LDFLAGS = -lgtest -lpthread

all: directories runtest

runtests: $(BIN_DIR)/teststrutils
	$(BIN_DIR)/teststrutils

$(BIN_DIR)/teststrutils: $(OBJ_DIR)/StringUtils.o $(OBJ_DIR)/StringUtilsTest.o 
	$(CXX) -o $(BIN_DIR)/teststrutils $(CXXFLAGS) $(OBJ_DIR)/StringUtils.o $(OBJ_DIR)/StringUtilsTest.o

$(OBJ_DIR)/StringUtils.o: $(SRC_DIR)/StringUtils.cpp $(INC_DIR)/StringUtils.h
	$(CXX) -o $(OBJ_DIR)/StringUtils.o -c $(CXXFLAGS) $(SRC_DIR)/StringUtils.cpp

$(OBJ_DIR)/StringUtilsTest.o: $(TEST_SRC_DIR)/StringUtilsTest.cpp $(INC_DIR)/StringUtils.h
	$(CXX) -o $(OBJ_DIR)/StringUtilsTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/StringUtilsTest.cpp


directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)
