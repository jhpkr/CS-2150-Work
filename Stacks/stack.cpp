//Joon Park, jp4hj, March 2nd, 2021, stack.cpp

#include "stack.h"
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include <cstdlib>
using namespace std;

stack::stack(){
	count = 0;
	head = new ListNode(); 
	tail = new ListNode();
	head->next=tail;
    tail->previous=head;
}


stack::~stack(){ 
	makeEmpty();
	delete head;
	delete tail;
}

bool stack::isEmpty() {
	if(count == 0){
		return true;
	}
	else {
		return false;
	}
}

void stack::makeEmpty() {
	count = 0;
	//rearragnge pointers to skip ove the node after head -> delete note
	ListItr lst; 
	lst = head -> next;
	while (!lst.isPastEnd()) {
		ListNode* tmp = lst.current -> next;
		delete lst.current;
		lst.current = tmp;
	}
	head -> next = tail;
	tail -> previous = head;
}

void stack::push(int x){
	count += 1;
	ListNode* stk = new ListNode();
	stk -> value = x;

	stk -> next = tail;
	stk -> previous = tail -> previous;
	tail -> previous -> next = stk;
	tail -> previous = stk;

}

void stack::pop() {
	if(count == 0){
		cout << "The stack is empty!" << endl;
		exit(-1);
	}
	count -= 1;
	ListItr lst;
	lst = tail -> previous;
	tail -> previous = lst.current -> previous;
	lst.current -> previous -> next = tail; 
	delete lst.current;




    }

int stack::top() const {
	if(count == 0){
		cout << "The stack is empty!" << endl;
		exit(-1);
	}
	ListItr lst;
	lst = tail -> previous;
	return lst.current -> value;
}