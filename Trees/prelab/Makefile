# Joon Park, jp4hj, March 20, 2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g
OBJECTS = TreeCalc.o TreeCalcTest.o TreeNode.o

Tree: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Tree is Ready!"

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h

.PHONY: clean
clean:
	-rm -f *.o a.out
