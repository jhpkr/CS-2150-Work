/*
CS 2150 prelab 9 Joon Park, jp4hj, 4/17/2021
*/

#include <iostream>
#include "timer.h"
using namespace std;

extern "C" long threexplusone(long x);

int main() {
    

    long x; //number for the collatz conjecture
    long n; //number of iterations

    cout << "Enter a number: ";
    cin >> x;

    cout << "Enter iterations of subroutine: ";
    cin >> n;

    // timer t; 
    // t.start();

    long steps = threexplusone(x);

    for(int i = 0; i < n; i++){
        threexplusone(x);
    }

    // t.stop();
    cout << "Steps: " << steps << endl;
    // int timer = t.getTime();
    // cout << timer << endl;

    return 0;

}