//Hello World

#include <iostream> //make sure you include this!
using namespace std; //removes the need of std::

int max(int a, int b); // this must be done to let the compiler know that it exists

int main(){
	int x = 7;
	cout<< "Hello World" << endl;

	cout<< max(1,2) << endl;

	if (x) //if the value is !- 0, it is true and == 0, it is false
	// if (x =0 ) <- will overwrite the value of x 
		cout << "true" << endl;
	else
		cout << "false" << endl;

	// cout<<x << endl; will print out 0

	return 0;
}

int max(int a,int b){
	if (a>b)
		return a;
	else
		return b;

}