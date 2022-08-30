// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Huffman.h"
using namespace std;

Huffman huffman;
// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    char* file = argv[1];
    huffman.decoder(file);
    huffman.enabler();
    huffman.traversal(huffman.find_root(), huffman.bits);
    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    
    

    return 0;
}