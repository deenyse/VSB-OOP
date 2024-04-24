#include "CreditAccount.h"
#include "iostream"
using namespace std;


CreditAccount::CreditAccount(int n, Client *o, double c, double ir, bool isCustomIr) :  Account(n, o, ir, isCustomIr) {
    this->credit = c;
    cout << "CreditAccount constructor" << endl;
}


bool CreditAccount::canWithdraw(double a) {
    return (this->getBalance() + this->credit) >= a;
}

bool CreditAccount::Withdraw(double a) {
    if(this->canWithdraw(a)){
        this->balance -= a;
        return true;
    }
    return false;
}

