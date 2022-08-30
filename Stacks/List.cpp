//Joon Park, jp4hj, February 22th, 2021, List.cpp
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include "stack.h"
using namespace std;

List::List(){
	count = 0;
	head = new ListNode(); 
	tail = new ListNode();
	head->next=tail;
    tail->previous=head;

}

List::List(const List& source){ //Ask TA about this
	head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}


List:: ~List(){ 
	makeEmpty();
	delete head; 
	delete tail;
}

List& List::operator=(const List& source) { //Ask TA about this

	if (this == &source) { //why use THIS here?
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;


}

ListItr List::first() {
	ListItr lst; //how can a list itr point to a listnode
	lst = head -> next; 
	return lst; 
}

ListItr List::last() {
	ListItr lst;
	lst = tail -> previous; 
	return lst;
}


bool List::isEmpty() const {
	//is this just when count = 0? 
	if(count == 0){ //hmmm
		return true;
	}
	else{
		return false;
	}
}

void List::makeEmpty() {
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


void List::insertAfter(int x, ListItr position) {
	count += 1;
	ListNode* lst = new ListNode(); // do we even need new here
	lst -> value = x;

	
	lst -> next = position.current -> next; 
	lst -> previous = position.current;
	position.current -> next -> previous = lst;
	position.current -> next = lst;

}


void List::insertBefore(int x, ListItr position) {
	count += 1;
	ListNode* lst = new ListNode();
	lst -> value = x;

	
	lst -> next = position.current; 
	lst -> previous = position.current -> previous;
	position.current -> previous -> next = lst;
	position.current -> previous = lst;
}


void List::insertAtTail(int x) {
	count += 1;
	ListNode* lst = new ListNode();
	lst -> value = x;

	lst -> next = tail; 
	lst -> previous = tail -> previous;
	tail -> previous -> next = lst;
	tail -> previous = lst;


}

ListItr List::find(int x){
	ListItr lst;
	lst = head -> next;

	while (!lst.isPastEnd()) {
		if(lst.retrieve() == x){
			return lst;
		}
		lst.moveForward();

    }
    lst = tail;

	return lst; 
}


void List::remove(int x) { // make sure to change count later
	// im guessing this is just connecting the pointers
	ListItr lst;
	lst = find(x);

	if (!lst.isPastEnd()) {
			count -= 1;
			lst.current -> previous -> next = lst.current -> next;
			lst.current -> next -> previous = lst.current -> previous; 
			delete lst.current;

		}

    }

int List::size() const{
	//count is called everytime an insert method is called; therefore, size only needs to return count.
	return count;

}

void printList(List& source, bool forward) {
	//check if it is forward or backwards. 
	//create a new listitr -> retrieve each value and move forward
	if(forward == true){
		ListItr iter(source.first());
		while (!iter.isPastEnd()) {
        cout << " " << iter.retrieve();
        iter.moveForward();
    }

    
    }
    else{
    	ListItr iter(source.last());
    	while (!iter.isPastBeginning()){
    		cout << " " << iter.retrieve();
    		iter.moveBackward();
    	}

    //make sure to do backward later*************
    //similar logic to forward
	}

}


