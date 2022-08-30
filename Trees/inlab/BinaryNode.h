//Joon Park, jp4hj March 22, 2021, BinaryNode.h
#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
    BinaryNode();
    ~BinaryNode();

    string value;
    BinaryNode* left;
    BinaryNode* right;

    friend class BinarySearchTree;
};

#endif