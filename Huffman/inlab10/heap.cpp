// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    binary_heap.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<HuffmanNode*> vec) : heap_size(vec.size()) {
    binary_heap = vec;
    binary_heap.push_back(binary_heap[0]);
    binary_heap[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(HuffmanNode* x) {
    // a vector push_back will resize as necessary
    binary_heap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    HuffmanNode* x = binary_heap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x -> frequency < binary_heap[hole/2] -> frequency); hole /= 2) {
        binary_heap[hole] = binary_heap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    binary_heap[hole] = x;
}

HuffmanNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    HuffmanNode* ret = binary_heap[1];
    // move the last inserted position into the root
    binary_heap[1] = binary_heap[heap_size--];
    // make sure the vector knows that there is one less element
    binary_heap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    HuffmanNode* x = binary_heap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (binary_heap[child+1] -> frequency < binary_heap[child] -> frequency)) {
            child++;
        }
        // if the child is greater than the node...
        if (x -> frequency > binary_heap[child] -> frequency) {
            binary_heap[hole] = binary_heap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    binary_heap[hole] = x;
}

HuffmanNode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return binary_heap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    binary_heap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << binary_heap[0] << ") ";
    // cout << "Character: " << binary_heap[0] -> c << endl;
    for (int i = 1; i <= heap_size; i++) {
        cout << binary_heap[i] -> c << " ";
        // cout << "Frequency: "<< binary_heap[i] -> frequency << " " << "Index: " <<  i << endl;
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}

