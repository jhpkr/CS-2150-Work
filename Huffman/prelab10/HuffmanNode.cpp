#include "HuffmanNode.h"
using namespace std;

HuffmanNode::HuffmanNode(){
	frequency = 0;
	c = '?'; 
	left = NULL;
	right = NULL;
}

HuffmanNode::HuffmanNode(int freq, unsigned char character){
	frequency = freq;
	c = character;
	left = NULL;
	right = NULL;

}