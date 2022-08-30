//Joon Park, jp4hj March 22, 2021, BinaryNode.h
#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    insertHelper(root, x);
}

void BinarySearchTree::insertHelper(BinaryNode*& n, const string& x){

// checks for null and sets the value
    if (n == NULL){
        n = new BinaryNode();
        n -> value = x;
    }

    if (x < n -> value){
        insertHelper(n -> left, x);
    }
    else if(x > n-> value){
        insertHelper(n-> right, x);
    }
    else{
        ;
    }

}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
    root = remove(root, x);
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    if(find(x) == true){ 
        return pathToHelper(x, root);
    }
    else {
        return "";
    }
    
}

string BinarySearchTree::pathToHelper(const string& x, BinaryNode* curNode) const{
    string path = "";
    if(x == curNode -> value){
        return curNode -> value;
    }
    if(x < curNode -> value){
        path = curNode -> value + " " + pathToHelper(x, curNode -> left) ;
        }
        else{
            path = curNode -> value + " " + pathToHelper(x, curNode -> right);
        }
        return path;
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE

    if(findHelper(x, root) == x){
        return true;
    }
    else if(findHelper(x, root) != x){
        return false;
    }
    return false;

}
string BinarySearchTree::findHelper(const string& x, BinaryNode* curNode) const{


    if (curNode == NULL){
        return "";
    }
    else if (x < curNode -> value){
        return findHelper(x, curNode -> left);
    }
    else if ( x > curNode -> value){
        return findHelper(x, curNode -> right);
    }
    else{
        return curNode -> value;
    }
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    return numNodesHelper(root);
}

int BinarySearchTree::numNodesHelper(BinaryNode* node) const{
    //traverse through the tree and increase the count


    if(node == NULL){
        return 0;
    }

    return 1 + numNodesHelper(node -> left) + numNodesHelper(node -> right); //help from TA

}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}
