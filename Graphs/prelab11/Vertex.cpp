#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "Vertex.h"

Vertex::Vertex(){
	indegree = 0;
	visited = false;
	name = "";
}