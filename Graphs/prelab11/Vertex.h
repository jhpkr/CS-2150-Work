#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;



class Vertex {
public:
    Vertex();
    int indegree;
    bool visited;
    vector<Vertex*> edges;
    string name;
private:

};

#endif