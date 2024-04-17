#include <iostream>
#include "Account.h"
using namespace std;
int Account::accountCount = 0;

Account::Account(int n, Client *c, double ir, bool isDefaultIR)
        : number(n), owner(c), interestRate(ir), balance(0), isCustomIR(isDefaultIR) {
    Account::accountCount++;
    cout << "Account constructor" << endl;
}

Account::~Account() {
    Account::accountCount --;
    cout << "Account destructor" << endl;
}

bool Account::canWithdraw(double a) {
    return this->balance >= a;
}

void Account::Deposit(double a) {
    this->balance += a;
}

bool Account::Withdraw(double a) {
    if (!this->canWithdraw(a))
        return false;

    this->balance -= a;
    return true;
}

void Account::addInterest(){
    this->balance += this-> balance * this->interestRate;
}

int Account::getAccountsCount() {
    return Account::accountCount;
}

void Account::setNewIR(double newIR) {
        this->interestRate = newIR;
}