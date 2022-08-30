

#include <iostream>
#include "Huffman.h"
#include "HuffmanNode.h"
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>
#include <map>
using namespace std;

Huffman::Huffman(){

}

Huffman::~Huffman() {
}

void Huffman::count_freqs (string filename) {

    for (int i = 0; i <= 255;i++ ){
        freq[i] = 0;
    }

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Unable to open '" << filename << "' for reading" << endl;
        exit(2);
    }

    char c;
    while (file.get(c)) {

        // cout << (int) c << endl;
        if ( (c < 0x20) || (c > 0x7e) )
            continue;
        if ( (c < 32) || (c > 126) )
            continue;
        if ( (c < ' ') || (c > '~') )
            continue;
        freq[c]++;
        counter++;
    }



    // // a nice pretty separator
    // cout << "----------------------------------------" << endl;

    // // once we hit the end of the file we are marked as "failed", so clear that
    // // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    // // Read the file again, and print to the screen
    // while (file.get(c)) {
    //     cout << c;
    // }

    // close the file
    file.close();
     totalBit = 8 * counter;

}

void Huffman::insert_to_heap(){
    for(int i = 0; i <= 255; i++){
        if(freq[i] > 0){
            unique++; 

            char tmp = i;
            // cout << "Frequency: " << freq[i] << " " << "Character: " << tmp << endl;
            HuffmanNode* node = new HuffmanNode(freq[i],tmp);
            MinHeap.insert(node);
        }
    }
    // MinHeap.print();
    
}

void Huffman::buildTree(){
    while(MinHeap.heap_size > 1){
        HuffmanNode* x = MinHeap.deleteMin();
        // cout << "Removing: " << x -> frequency << ","<< x -> c << endl;
        HuffmanNode* y = MinHeap.deleteMin();
        // cout << "Removing: " << y -> frequency << ","<< y -> c << endl;

        HuffmanNode* t1 = new HuffmanNode();
        t1 -> left = x; 
        t1 -> right = y;
        t1 -> frequency = x -> frequency + y -> frequency;
        // cout << "T1 Frequency: " << t1 -> frequency << endl;

        MinHeap.insert(t1);
    }
}


void Huffman::determine_prefix_codes (HuffmanNode* node, string path_taken) {

    if ( node->left == NULL && node -> right == NULL) {
        // recursion ends
        if(node -> c == ' '){
            cout << "space" << " " << path_taken << endl;
        }
        else{
            cout << node->c << " " << path_taken << endl;
        }

        codes[node->c] = path_taken;



    } else { // node must have 2 children
        // recursion continues
        determine_prefix_codes (node->left,  path_taken + "0");
        determine_prefix_codes (node->right, path_taken + "1");

    }


}

HuffmanNode* Huffman::find_root(){
    HuffmanNode* root = MinHeap.findMin();
    return root;
}
void Huffman::reader(string filename){
     ifstream file(filename);

    if (!file.is_open()) {
        cout << "Unable to open '" << filename << "' for reading" << endl;
        exit(2);
    }

    char c;
    while (file.get(c)) {
        if(codes.find(c) != codes.end()){
            s = s + codes[c] + " ";

        }
    }
    file.close();

}
int Huffman::calculate(){ 
    //Get the huffman node and its frequency
    double x = 0;
    for (int i = 0; i <= 255;i++ ){
        if(freq[i] > 0){
            if(codes.find(i) != codes.end()){
                 x += codes[i].length() * freq[i];
            }
        }
    }
    compressionRatio = totalBit/x;
    cost = x/counter;
    return x;
}

