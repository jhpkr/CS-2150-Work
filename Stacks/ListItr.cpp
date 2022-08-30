//Joon Park, jp4hj, February 22th, 2021, ListItr.cpp
#include "ListItr.h"
#include "ListNode.h"
#include "List.h"
#include "stack.h"

using namespace std;

ListItr::ListItr(){
	current = NULL;

	//current is the current node that listitr is pointing to

}
ListItr::ListItr(ListNode* theNode){ 
	current = theNode;

}

bool ListItr::isPastEnd() const {
	//if the current is pointing to the tail, return true, else return false
	if( current -> next == NULL){
		return true;
	}
	else{
		return false;
	}
}


bool ListItr::isPastBeginning() const {
	//similar logic to above
	if (current -> previous == NULL) {
		return true;
	}
	else{
		return false;
	}
}


void ListItr::moveForward() {
	//if it is past the end, do nothing, else move forward
	if(isPastEnd() == true){
	} 
	else {

		current = current -> next;

	}

}

void ListItr::moveBackward() {
	//similar logic above
	if(isPastBeginning() == true){
	}
	else {
	current = current -> previous;
}

}

int ListItr::retrieve() const{
	// get the value of the node which the current itr is pointing at
	int number = current -> value;
	return number;
}


