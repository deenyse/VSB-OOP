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

void CreditAccount::printStats(){
    cout << "Number: " << this->getNumber() << " Balance: " << this->getBalance() << " ir: " << this->getInterestRate() * 100 <<"% isCustomIR:"<<this->getIsCustomIR() << " Owner: " << this->getOwner()->getName();
    cout << " Credit: " << this->getCredit();
}