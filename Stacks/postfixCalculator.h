//Joon Park, jp4hj, March 1st, 2021, postfixCalculator.h
#include <iostream>
using namespace std;
#include <string>
#include "stack.h"
#ifndef POSTFIXCALCULATOR_H 
#define POSTFIXCALCULATOR_H 


class postfixCalculator{
public:
	void calculate(string s); 
	int getOutput();

private:
	stack numbers; 
	int output; 
};



#endif