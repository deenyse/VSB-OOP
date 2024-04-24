#include "ParthnerAccount.h"
using namespace std;

ParthnerAccount::ParthnerAccount(int n, Client* c, double ir, bool isCustomIR, Client * partner) : Account(n,c,ir,isCustomIR){
    cout << "ParthnerAccount constructor" << endl;
    this -> partner = partner;
}


void ParthnerAccount::printStats() {
    cout << "Number: " << this->getNumber() << " Balance: " << this->getBalance() << " ir: " << this->getInterestRate() * 100 <<"% isCustomIR:"<<this->getIsCustomIR() << " Owner: " << this->getOwner()->getName();
    cout << " Partner: " << this->getPartner()->getName() << " code: " << this->getPartner()->getCode();
}