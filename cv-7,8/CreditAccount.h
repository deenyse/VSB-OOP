#pragma once
#include "Account.h"
class CreditAccount : public Account {
private:
    double credit;
public:
    CreditAccount(int n, Client * o, double c,double ir, bool isCustomIr);
    bool canWithdraw(double a);
    bool Withdraw(double a);

    double getCredit(){
        return this->credit;
    }

    void printStats() override;

};


