//Joon Park, jp4hj, March 2nd, 2021, StackNode.h
#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class StackNode {
public:
    StackNode(); // Constructor

private:
    int number;          // The value of the node!
    StackNode* next;     // The next ListNode in the List

    // List needs access to value, next, and previous
    friend class stack;
    friend class ListItr;

};

#endif