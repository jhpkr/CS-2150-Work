# Joon Park, jp4hj, March 21, 2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g
OBJECTS=BSTPathTest.o BinaryNode.o BinarySearchTree.o

BSTree: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) 
	@echo "BSTree is Ready!"

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

.PHONY: clean
clean:
	-rm -f *.o a.out