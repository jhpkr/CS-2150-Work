# Joon Park, jp4hj, april 26, 2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g
OBJECTS=Huffman.o HuffmanNode.o heap.o huffmandec.o

huffman: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) 
	@echo "Huffman is ready"

Huffman.o: Huffman.cpp Huffman.h HuffmanNode.h heap.h
HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
heap.o: heap.cpp heap.h HuffmanNode.h
huffmandec.o: huffmandec.cpp Huffman.h HuffmanNode.h heap.h

.PHONY: clean
clean:
	-rm -f *.o a.out