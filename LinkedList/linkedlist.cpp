#include <iostream>
using namespace std;

class ListNode{
public:
	int value = 5; 
};

class List {
public:
	List(){
		cout << "In List() constructor" << endl;
		ListNode* foo = new ListNode();
		//here...}
	}
	
private:
	ListNode *head;
	
};

int main(){
	List *l = new List(); //dynamic allocation -> compiler is handsoff
	delete l;
	//int x; static allocation. Does not need to worry about allocating/deallocating x
	return 0;
}