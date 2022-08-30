

#include <iostream>
#include "Huffman.h"
#include "HuffmanNode.h"
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>
#include <map>


#include <sstream>

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

void Huffman::decoder(string filename){
    ifstream file(filename, ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << filename << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        // cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;

        char car = character[0];
        decoding[car] = prefix;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    bits = allbits;
    // close the file before exiting
    file.close();

}


void Huffman::create_path(HuffmanNode *node, char leaf, string prefix_code){
    if(prefix_code == ""){
        node -> c = leaf;
        return;
    }


    if(prefix_code[0] == '0'){
        if(node -> left == NULL){
            HuffmanNode *leftNode = new HuffmanNode();
            node -> left = leftNode;
        }
        create_path(node -> left, leaf, prefix_code.erase(0,1));
    }
    else{ 
        if(node -> right == NULL){
            HuffmanNode *rightNode = new HuffmanNode();
            node -> right = rightNode;
        }
        create_path(node -> right, leaf, prefix_code.erase(0,1));
    }
}

void Huffman::enabler(){
    HuffmanNode*root = new HuffmanNode();
    map<char, string> :: iterator it; 

    for (it = decoding.begin(); it != decoding.end(); it++){
        create_path(root, it -> first, it -> second);
    }
    MinHeap.insert(root);
}

void Huffman::traversal(HuffmanNode* node, string prefix_code){
    string s = "";

    while(prefix_code != ""){
        if (node -> left == NULL && node -> right == NULL){
            s += node -> c;
            node = MinHeap.findMin();
        }
        if(prefix_code[0] == '1'){
            node = node -> right;
        }
        else{
            node = node -> left;
        }
        prefix_code.erase(0,1);
    }
    s += node -> c;
    cout << s << endl;
}




