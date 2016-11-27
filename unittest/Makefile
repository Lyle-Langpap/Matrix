CC := gcc

FLAGS := -std=c99
FLAGS += -Wall

INC := -I ../
INC += -I ../Test

LIB := -lm

FILES := ../Test/Test.c
FILES += ../Matrix_3x3.c


.PHONY: default
default: buildDirectory
	$(CC) $(FLAGS) main-Matrix_3x3_Test.c $(FILES) -o ./build/Matrix_3x3_Test $(INC) $(LIB)

.PHONY: run
run: default
	./build/Matrix_3x3_Test

buildDirectory:
	if [ ! -d "./build" ]; then mkdir build; fi
