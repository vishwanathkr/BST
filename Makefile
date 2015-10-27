# A simple makefile for CSE 100 P1

#use g++ for everything
CC= g++  	

# include debugging symbols in object files,
# and enable all warnings
CXXFLAGS= -std=c++11 -g -c

#include debugging symbols in executable
LDFLAGS= -g	

bst: test_BST.o 
	$(CC) -o bst test_BST.o

test_BST.o: test_BST.cpp BST.hpp BSTNode.hpp BSTIterator.hpp
	$(CC) $(CXXFLAGS) test_BST.cpp -o test_BST.o

clean:
	rm -f *.o core

