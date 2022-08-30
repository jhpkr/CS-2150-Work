# Joon Park, jp4hj, april 26, 2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 -std=c++11
DEBUG=-g
OFILES=traveling.cpp middleearth.cpp

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	doxygen

.PHONY: clean
clean:
	-rm -f *.o a.out