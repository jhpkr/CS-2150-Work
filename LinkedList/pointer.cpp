#include <iostream>
using namespace std;

int main(){
	cout << "Hello World" << endl;

	int i = 1;
	float f = 2.0;
	double d = 3.0;

	int* ip = nullptr; 
	float* fp = &f; // fp is a memory address
	//&f is getting the address of where f is stored
	double* dp; //if you declare a variable inside of a method, 
	//it declares 8bits and stores the value of whatevever was inside

	cout << "variable values: " << endl;
	cout << i << endl; //prints 1
	cout << f << endl; //prints 2
	cout << d << endl; //prints 3

	cout << "variable addresses:" << endl;
	cout << &i << endl; //prints 0xblhablahba
	cout << &f << endl; // same
	cout << &d << endl; // same

	cout << "pointer values:" << endl;
	cout << ip << endl; //expects to print 0
	cout << fp << endl; //prints address of f
	cout << dp << endl; //?????

	cout << "pointer dereferences: " << endl;
	cout << *fp << endl; //follows the pointer and prints the value of f
	cout << *ip << endl; //prints out an error -> nullpointer exception
	cout << *dp << endl; //prints out whatever was in that segment of memory
	
	cout << "sizeof() the pointers: " << endl;
	cout << sizeof(ip) << endl;
	cout << sizeof(fp) << endl;
	cout << sizeof(double*) << endl;

	cout << "comparisons: " << endl;
	int j = 1;
	int* jp = &j;
	if (i==j)
		cout << "equal" << endl;
	else 
		cout << "not equal" << endl;






	return 0;
}