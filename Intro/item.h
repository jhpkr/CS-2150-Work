#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item{ //name of the file and the class does not need to be the same
	
public:
	int getID() const;
	void setID(int i);

private:
	int id;
	double price;
	const float f = 9.9;
	static double pi =3.14159265358979;
};

#endif