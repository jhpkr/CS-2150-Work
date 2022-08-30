# Joon Park, jp4hj, March 27, 2021

CXX=clang $(CXXFLAGS)
CXXFLAGS=-Walls -g
DEBUG=-g
OBJECTS=linkedlist.o

linkedlist: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) 
	@echo "linkedlist is ready"

.PHONY: clean
clean:
	-rm -f *.o a.out