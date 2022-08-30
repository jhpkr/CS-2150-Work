#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "HuffmanNode.h"
#include "heap.h"
#include <map>
#include <string>
using namespace std;

class Huffman {
public:
    Huffman();                     // Constructor
    ~Huffman();                    // Destructor

    void count_freqs(string filename);
    void insert_to_heap();
    void buildTree();
    void determine_prefix_codes(HuffmanNode* node, string path_taken);
    int calculate();
    HuffmanNode* find_root();
    void reader(string filename);

    int counter; 
    int unique;
    int totalBit;
    float compressionRatio;
    float cost;
    string s;


private:
    int freq[256];
    heap MinHeap;
    map<char, string> codes; 




};

#endif