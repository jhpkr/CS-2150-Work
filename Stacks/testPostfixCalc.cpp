//Joon Park, jp4hj, March 1st, 2021, testPostfixCalc.cpp

#include <iostream>
#include <string>
#include "stack.h"
#include "postfixCalculator.h"
using namespace std;


int main(){
string token;
postfixCalculator calculator;
while (cin >> token) {
	
   calculator.calculate(token);
}
	cout << calculator.getOutput() << endl;
	return 0; 
}