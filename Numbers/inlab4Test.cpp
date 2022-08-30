//Joon Park, jp4hj, inlab4.cpp, 3/15/2021

#include <climits>
#include <iostream>
#include <string>
#include <limits>
using namespace std;


void overflow();

int main(){
unsigned int x; 
cin >> x;
overflow();
return 0; 
}




void overflow(){
int a = 2147483647;
unsigned int b = 0; 
float c = 0;
double d = numeric_limits<double>::max();;
char e = 127;
bool f = 0;
int* MaxInt= &a;
char* MaxChar = &e;
double* MaxDouble = NULL;


cout << "INT" << a << endl;
cout << "UINT" << b << endl;
cout << "FLOAT" << c << endl;
cout << "DOUBLE" << d << endl;
cout << "CHAR" << e << endl;
cout << "BOOL" << f << endl;
cout << "INT*" << MaxInt << endl;
cout << "CHAR*" << MaxChar << endl;
cout << "DOUBE*" << MaxDouble << endl;

}



