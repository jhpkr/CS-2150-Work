#include <iostream>
using namespace std; 

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main(){
	int *a = new int(100);
	int *b = new int(98);
	swap(a,b);
	cout << *a << endl;
	return 0;
}