//Joon Park, jp4hj, February 13th, 2021, bankAccount.h
#include <iostream>
using namespace std;
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount {
public:
    bankAccount(); 
    bankAccount(double amount);
    ~bankAccount();
    double withdraw(double amount);
    double deposit(double amount);
    double getBalance();
private:
    double balance;

};




#endif