//Joon Park, jp4hj, March 1st, 2021, postfixCalculator.cpp

#include "postfixCalculator.h"
#include <iostream>
#include "stack.h"
using namespace std;
#include <string>


void postfixCalculator::calculate(string s) {
	//check for all of the operators
		//if it is an operator, pop two and apply the operator
		//if it is not an operator, convert the string in to an integer and add the number to the list

	if(s == "+"){
		int x = numbers.top();
		numbers.pop();
		int y = numbers.top();
		numbers.pop();
		output = x + y;
		numbers.push(output);
		// cout << "I am adding " << x << " " << "and" << y << " " << "which is: " << output << endl;
		
	}
	else if (s == "-"){
		int x = numbers.top();
		numbers.pop();
		int y = numbers.top();
		numbers.pop();
		output = y - x;
		numbers.push(output);
		// cout << "I am subtracting" << x << "and" << " " << y << " " << "which is: " << output << endl;
	}
	else if (s == "*"){
		int x = numbers.top();
		numbers.pop();
		int y = numbers.top();
		numbers.pop();
		output = y * x;
		numbers.push(output);
	}
	else if (s == "/"){
		int x = numbers.top();
		numbers.pop();
		int y = numbers.top();
		numbers.pop();
		output = y / x;
		numbers.push(output);
	}
	else if (s == "~"){
		int x = numbers.top();
		numbers.pop();
		output = -x;
		numbers.push(output);
	}
	else{
		int tmp = stoi(s); // stoi(tree -> value)
		numbers.push(tmp);
		// cout << "I pushed the number:" << tmp << endl;
	}

}

int postfixCalculator::getOutput(){
	// cout << "This is working" << endl;
	return output;
}

