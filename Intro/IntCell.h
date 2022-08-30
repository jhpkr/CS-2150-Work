#ifndef INTCELL_H
#define INTCELL_H

class IntCell {
public:
	IntCell(int initialValue = 0); //if you call this parameter with 0 value -> default to 0. If there is 1 parameter, it will be that value


	int getValue () const; //that method will not modify the state of the object
	void setValue (int val);

private:
	int storedValue;
	int max(int m) const;


};

#endif