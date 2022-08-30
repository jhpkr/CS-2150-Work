//Joon Park, jp4hj, March 2nd, 2021, stack.h


#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#include "ListNode.h"
#include "ListItr.h"

class stack {
public:
	stack();
	~stack();
	bool isEmpty();
	void push(int x);
	void pop();
	int top() const;
	void makeEmpty();

private:
	ListNode* head; 
	ListNode* tail;
	int count;
};  

#endif