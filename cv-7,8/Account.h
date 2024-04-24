#pragma once
#include "Client.h"

class Account {
private:
    int number;
    double interestRate;
    Client* owner;
    bool isCustomIR;
    static int accountCount;
protected:
    double balance;
public:
    Account(int n, Client* c, double ir, bool isCustomIR);
    ~Account();

    static int getAccountsCount();

    int getNumber() { return this->number; };
    double getBalance() { return this->balance;}
    double getInterestRate() { return this->interestRate;}
    Client* getOwner() { return this->owner;}

    virtual bool canWithdraw(double a); // +able to get money
    bool getIsCustomIR() { return this->isCustomIR;}

    void Deposit(double a);//+ depose money
    bool Withdraw(double a); // +withdraw money
    void setNewIR(double a);
    void addInterest(); //+ add interest add % to whole accounts

    virtual void printStats();
};


