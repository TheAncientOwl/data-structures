CXX 		 := g++
CXXFLAGS := -g -Wall -std=c++17 -ggdb

PROJ_PATH = /home/theancientowl/data-structures

BIN			:= $(PROJ_PATH)/bin
SRC 		:= $(PROJ_PATH)/src
INCLUDE := $(PROJ_PATH)/include

LIBRARIES  :=
EXECUTABLE := main

SOURCE_FILES = $(shell find $(SRC) -type f -name *.src.cpp)

all: build run

build: clean $(BIN)/$(EXECUTABLE)

run:
	@$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SOURCE_FILES)
	@echo '[INFO] Build started.'
	@$(CXX) $(CXXFLAGS) -I $(INCLUDE) $^ -o $@ $(LIBRARIES)
	@echo '[INFO] Build finished.'

clean:
	@rm -rf $(BIN)/*
