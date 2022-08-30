//Joon Park, jp4hj, February 13th, 2021, bankAccount.cpp

#include "bankAccount.h"
using namespace std;

bankAccount::bankAccount() {
	balance = 0.00;
}

bankAccount::bankAccount(double amount){
	balance = amount;
}

bankAccount::~bankAccount(){

}

double bankAccount::withdraw(double amount) {

	if(amount > balance){
		return balance;
	}
	else{
		balance = balance - amount;
		return balance;
	}
}
double bankAccount::deposit(double amount) {
	balance = balance + amount;
	return balance;
}

double bankAccount::getBalance() {
	return balance;
}