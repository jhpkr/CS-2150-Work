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
    void decoder(string filename);
    void create_path(HuffmanNode *node, char leaf, string prefix_code);
    void enabler();
    void traversal(HuffmanNode* node, string decoded);

    int counter; 
    int unique;
    int totalBit;
    float compressionRatio;
    float cost;
    string s;
    string bits;


private:
    int freq[256];
    heap MinHeap;
    map<char, string> codes; 
    map<char, string> decoding;




};

#endif