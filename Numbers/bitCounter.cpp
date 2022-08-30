//Joon Park, jp4hj, bitCounter.cpp, 3/17/2021
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <math.h>
using namespace std;


int counter(int number);
string converter(string number, int sBase, int eBase);

int main (int argc, char* argv[]) { //make sure to end if there is no argv 

	if(argc == 1){
		cout << "There is not enough command line parameters!" << endl;
		exit(-1);
	}
    char* x = argv[1]; //ask if there is better way to do this
    char* y = argv[2];
    char* z = argv[3];
    char* w = argv[4];
    int a = atoi(x);
    string s(y);
    int c = atoi(z);
    int d = atoi(w);

    cout << a << " has " << counter(a) << " bit(s)" << endl;
    cout << y << " (base " << z << ")" << " = " << converter(s,c,d) << " (base " << w << ")" << endl;
    // cout << s << "(base " << c << ") = " << converter(s,c,d) << "base " << d << ")" << endl;



    return 0;
}

int counter (int number){ //counts the number of bits given an integer
	if(number == 0){ //base case when number == 0
		return 0;

	}
	if(number == 1){ // base case when number == 1
		return 1;
	}

	if(number % 2 == 0){ //if the number is even 
		return (counter(number/2));
	}
	else{ //if the number is odd
		return (1 + counter((number/2)));
	}
	
}
//covert the number given a base using the start and end bases.
string converter(string number, int sBase, int eBase){ 
	vector<char> CharVector;
	vector<int> IntVector;
	vector<int> ReciprocalVector;
	int sum = 0;
	int remainder = 0;
	int clone = 0;
	string a = "";

	//this for-loop adds the letters to the vector
	for(int i = number.length(); i >= 0 ;i--){
		char letter = number[i];
		CharVector.push_back(letter);
	}


	//convert the letters in to integer values
	for(int i = 0; i <= CharVector.size()-1; i++){
		if(CharVector.at(i) >= '0'){
			if(CharVector.at(i) <= '9'){
				int converted = CharVector.at(i) - '0';
				IntVector.push_back(converted);

			}
			else{
				int converted = CharVector.at(i) - '7';
				IntVector.push_back(converted);
			}
		}
		
	}

	//converts base in to base10
	for(int i = 0; i <= IntVector.size()-1; i++){
		sum += IntVector.at(i) * pow(sBase,i);
		clone += IntVector.at(i) * pow(sBase,i);
	}
	

	//if the end base is equal to 10, then stop here
	if(eBase == 10) {
		string SConverter = to_string(sum);
		return SConverter;
	}

	//converting base10 to end base
	while( clone != 0){
		sum =  clone % eBase;
		clone = clone / eBase;
		ReciprocalVector.push_back(sum);

	}

	//puts the values together.
	for(int i = ReciprocalVector.size()-1; i >= 0 ;i--){

		//Checks if the reciprocal is greater than 10
		if(ReciprocalVector.at(i) >= 10){
			char character = ReciprocalVector.at(i) + '7';
			a += character;
		}

		else{
		a += to_string(ReciprocalVector.at(i));
	}
	}




	return a; 
}
