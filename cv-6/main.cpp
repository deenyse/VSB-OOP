#include <iostream>
using namespace std;
#include "Bank.h"


int main(){

    Bank* monoBank = new Bank(10,10);

    monoBank->createAccount(1, monoBank->createClient(1, "Vasya"))->Deposit(100);
    
    monoBank->createAccount(2, monoBank->createClient(2, "Petya"), monoBank->createClient(3, "Petya2"))->Deposit(120);
    monoBank->createAccount(3, monoBank->getClient(3))->Deposit(200);
    monoBank->createAccount(4, monoBank->createClient(5, "Kolya"), monoBank->getClient(1), 0.1)->Deposit(300);
    monoBank->createAccount(5, monoBank->createClient(4,"koala"), 0.035)->Deposit(10);
    for (int i = 6; i<=10; i++)
        monoBank->createAccount(i, monoBank->createClient(i, "Name"))->Deposit(1000);

    monoBank->createAccount(11, monoBank->createClient(11, "Name1")); // acccount is not added

    monoBank->getAccount(5)->Deposit(1000); // added to koala 1000
    monoBank->getAccount(5)->Withdraw(2000); // cannot withdraw
    monoBank->getAccount(10)->Withdraw(1000); // account n10 can't withdraw


    monoBank->addInterest();
    monoBank->addInterest();
    monoBank->print_stats();

    monoBank->modifiIneterestRate(-1);
    monoBank->addInterest();
    monoBank->print_stats();

    delete monoBank;
    return  0;
}
