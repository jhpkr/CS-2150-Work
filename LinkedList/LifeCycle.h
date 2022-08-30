//Joon Park, jp4hj, February 13th, 2021, LifeCycle.h
#include <iostream>
using namespace std;
#ifndef LIFECYCLE_H
#define LIFECYCLE_H



// Declare the MyObject class
class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor -> what is this
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj); //not sure what this does; friend keyword allows access to private fields
    // operator has something to do with overloading
private:
    string name;
    int id;
};

#endif