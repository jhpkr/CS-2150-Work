/*
 * Filename: huffmannode.h
 * Description: huffman class definition
 */

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
using namespace std;

class HuffmanNode {
public:
    HuffmanNode(); // Constructor
    HuffmanNode(int freq, unsigned char character);
    unsigned char c; //temporarily here
    int frequency;          // The frequency of the node!
    HuffmanNode* left;     // The left HuffmanNode in the tree
    HuffmanNode* right; // The right HuffmanNode in the tree



private:
    




    // List needs access to value, next, and previous
    friend class huffman;
    friend class heap;

};

#endif