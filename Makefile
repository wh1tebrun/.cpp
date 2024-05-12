.SUFFIXES:
.PHONY: all compile checkstyle test clean format

all: clean compile test checkstyle

compile: SnakeMain SnakeTest

Snake.o: Snake.cpp Snake.h
	clang++ -c Snake.cpp

SnakeMain.o: SnakeMain.cpp Snake.h
	clang++ -c SnakeMain.cpp

SnakeTest.o: SnakeTest.cpp Snake.h
	clang++ -c SnakeTest.cpp

SnakeMain: Snake.o SnakeMain.o
	clang++ -o SnakeMain SnakeMain.o Snake.o -lncurses

SnakeTest: Snake.o SnakeTest.o
	clang++ -o SnakeTest SnakeTest.o Snake.o -lncurses -lgtest -lgtest_main

test: SnakeTest
	./SnakeTest

checkstyle:
	clang-format-14 *.cpp --dry-run -Werror

clean:
	rm -f ./SnakeMain ./SnakeTest *.o

format:
	clang-format-14 -i *.cpp