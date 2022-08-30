// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "HuffmanNode.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<HuffmanNode*> vec);
    ~heap();

    void insert(HuffmanNode* x);
    HuffmanNode* findMin();
    HuffmanNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

    unsigned int heap_size;

private:
    vector<HuffmanNode*> binary_heap;
    

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif