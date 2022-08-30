// This program shows how C++-based file I/O works.
// It will print a file to the screen two times.

// included so we can use cout
#include <iostream>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>
#include "heap.h"
#include "Huffman.h"
using namespace std;

Huffman huffman;
// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    char* file = argv[1];
    huffman.count_freqs(file);
    huffman.insert_to_heap();
    huffman.buildTree();
    huffman.determine_prefix_codes(huffman.find_root(), "");
    cout << "----------------------------------------" << endl;
    huffman.reader(file);
    cout << huffman.s << endl;
    cout << "----------------------------------------" << endl;
    cout<< "There are a total of " << huffman.counter << " symbols that are encoded." << endl;
    cout << "There are "<< huffman.unique << " distinct symbols used." << endl;
    cout << "There were " << huffman.totalBit << " bits in the original file." << endl;
    cout << "There were " << huffman.calculate() << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << huffman.compressionRatio << "." << endl;
    cout << "The cost of the Huffman tree is " << huffman.cost << " bits per character." << endl;


    return 0;
}



