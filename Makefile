# Makefile

CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field


prog1A: prog1A.o storeIP.o
	${CXX} $^ -o $@

prog1B: prog1B.o storeBin.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f *.o prog1A prog1B