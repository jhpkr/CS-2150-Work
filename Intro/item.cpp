#include <iostream>
using namespace std;
#include "item.h"

int Item::getID() const { //const does a check to see if it is read-only
	return id;
}

void Item::setID(int i){ 
	id = i;
}

