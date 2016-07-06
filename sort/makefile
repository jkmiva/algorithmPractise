# flags for the c++ compiler
CXXFLAGS = -Wall -Wextra -std=c++11 -g
LDFALGS =

.PHONY: all  clean

all: quick merge

quick: quick.o
	g++ quick.o -o quick

merge: merge.o
	g++ merge.o -o merge

quick.o: quick.cc
merge.o: merge.cc

clean:
	rm -f *.o
	rm -f *~ quick merge
