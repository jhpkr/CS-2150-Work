//Joon Park, jp4hj, prelab4.cpp, 3/15/2021

#include <climits>
#include <iostream>
#include <string>
using namespace std;

void sizeOfTest();
void overflow();
void outputBinary(unsigned int x);

int main(){
unsigned int x; 
cin >> x;
sizeOfTest();
overflow();
outputBinary(x);
return 0; 
}


void sizeOfTest(){ 
// Returns the size of different sizes
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of bool: " << sizeof(bool) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of char*: " << sizeof(char*) << endl;
	cout << "Size of double*: " << sizeof(double*) << endl;

}

void overflow(){
	int a = UINT_MAX + 1;
	cout << UINT_MAX << " + " << "1 " << "= " << a << endl;

}

void outputBinary(unsigned int x){
//created an int array that is 32 bits long
//iterated it forwards not backwards

int someInts[32];
string a = "";


for(int i = 0; i < 32; i++) {
		if(x % 2 == 1){
		someInts[i] = 1;
	}
	else if(x % 2 == 0){
		someInts[i] = 0;
	}
	x = x / 2;
} 

for(int i = 31; i>=0; i--){

		a += to_string(someInts[i]);
		if(i % 4 == 0){
			a += " ";
		}
	
		
}
	cout << a << endl;

}




