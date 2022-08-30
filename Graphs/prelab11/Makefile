# Joon Park, jp4hj, april 26, 2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -std=c++11
DEBUG=-g
OFILES=topological.cpp Vertex.cpp

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	doxygen

.PHONY: clean
clean:
	-rm -f *.o a.out