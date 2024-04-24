#include <iostream>
using namespace std;
#include "Bank.h"
#include "CreditAccount.h"

int main(){

    Bank* monoBank = new Bank(10,10);

    monoBank->createAccount(1, 1000,monoBank->createClient(1, "Vasya"))->Deposit(1000); // credit account
    monoBank->createAccount(2, 1000,monoBank->createClient(2, "Vasya"),0.3)->Deposit(1000); // credit account // custom ir

    monoBank->createAccount(3, monoBank->createClient(3, "Petya"))->Deposit(1000); // casual account
    monoBank->createAccount(4, monoBank->createClient(4, "name3"),monoBank->createClient(5, "name3"),0.3)->Deposit(1000); // parthner accoubt custom ir
//    monoBank->createAccount(4, monoBank->createClient(5, "Kolya"), 0.1)->Deposit(300);
//    monoBank->createAccount(5, monoBank->createClient(4,"koala"), 0.035)->Deposit(10);




    monoBank->addInterest();
    monoBank->modifiIneterestRate(0.5);
    monoBank->addInterest();
    monoBank->print_stats();


//testing
//    Client* myClient = new Client("Bobby",0);
//    Account* myCreditAcc = new CreditAccount(1, myClient, 1000, 0.2,false);
//
//    myCreditAcc->Deposit(1000);
//    cout << myCreditAcc->canWithdraw(2000) << endl;
//    myCreditAcc->Withdraw(2000);
//    cout << myCreditAcc->canWithdraw(1000) << endl;
    delete monoBank;
    return  0;
}
