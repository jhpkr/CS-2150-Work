#include <iostream>
using namespace std;

class Item{
private:
	int* id;
	double price = 0.0;

public:
	Item(){
		cout << "Constructor called" << endl;
		id = new int;
		*id = 7;

		id = new int(7);
	}
};

int main(){
	Item i; //statically allocated -> comes from the heap
	Item *j = new Item(); //anything with a "new" keyword 
	// comes from the heap 


	return 0;
}