# Joon Park, jp4hj, March 24, 2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g
OBJECTS=AVLPathTest.o AVLNode.o AVLTree.o

AVLTree: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) 
	@echo "AVLree is Ready!"

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h

.PHONY: clean
clean:
	-rm -f *.o a.out