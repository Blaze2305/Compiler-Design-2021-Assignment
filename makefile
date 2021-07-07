SOURCE_DIR = src
SOURCES = $(wildcard *.cpp) $(wildcard src/*/*.cpp)
BUILD_DIR = bin
TEST_FILE_NAME = testInput.txt
COMPRESSOR = tar -czvf
ZIP_NAME = 4NI18CS122_4NI18CS121_4NI18CS126.tar.gz

ifeq ($(OS),Windows_NT) 
GXX := cl /EHsc /std:c++17
BUILD_NAME := tutorial.exe
DELETE_OBJS := del *.obj
DELETE_FOLDER := call rmdir /S /Q
DELETE_FILE := call del /Q /F
CLEAR_SCREEN := cls
OUTPUT_FLAG := /Fe:
else
GXX := g++ -std=c++17
BUILD_NAME := tutorial.out
DELETE_FOLDER := rm -rf
DELETE_FILE := rm -f
CLEAR_SCREEN := clear
OUTPUT_FLAG := -o
endif

default: build
.PHONY: default

build: |buildDir
	$(GXX) $(SOURCES) ${OUTPUT_FLAG}$(BUILD_DIR)/$(BUILD_NAME)
	${DELETE_OBJS}
.PHONY: build


buildDir: |clean
	mkdir $(BUILD_DIR)
.PHONY: buildDir


clean:
	 ${DELETE_FOLDER} $(BUILD_DIR) | echo Done
	 ${DELETE_FILE} ${ZIP_NAME}
.PHONY: clean


test: |build
	${CLEAR_SCREEN}
	$(BUILD_DIR)/$(BUILD_NAME) $(TEST_FILE_NAME)
.PHONY: test


submission: |build
	${COMPRESSOR} ${ZIP_NAME} ${SOURCE_DIR} main.cpp ${TEST_FILE_NAME}
.PHONY: submission