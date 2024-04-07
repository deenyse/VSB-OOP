#include <iostream>
#include "Bank.h"
#include "Account.h"

Bank::Bank(int c, int a) {
    this->clients = new Client * [c]();
    this->maxClients = c;
    this->accounts = new Account * [a]();
    this->maxAccounts = a;
}
Bank::~Bank(){
    for (int i=0; i< Account::getAccountsCount(); i++){
        delete this->accounts[i];
    }
    delete [] this->accounts;
    for (int i=0; i<Client::getClientsCount(); i++){
        delete  this->clients[i];
    }
    delete [] this->clients;

}

Client * Bank::getClient(int code){
    for (int i=0; i<Client::getClientsCount(); i++){
        if(this->clients[i]->getCode() == code)
            return this->clients[i];
    }
    return nullptr;
}

Account* Bank::getAccount(int number) {
    for(int i=0; i<Account::getAccountsCount(); i++){
        if (this->accounts[i]->getNumber() == number)
            return this->accounts[i];

    }
    return nullptr;
}

Client* Bank::createClient(int code, std::string name) {
    if (Client::getClientsCount() >= this->maxClients)
        return nullptr;

    int myclientsCount = Client::getClientsCount();
    this->clients[Client::getClientsCount() -1 ] = new Client(name, code);

    return this->clients[myclientsCount];
}

Account * Bank::createAccount(int n, Client *c) {
    if(Account::getAccountsCount() >= this->maxAccounts)
        return nullptr;

    this->accounts[Account::getAccountsCount() -1] =new Account(n,c);
    return this->accounts[Account::getAccountsCount()-1];
}

Account * Bank::createAccount(int n, Client *c, Client *p) {
    if(Account::getAccountsCount() >= this->maxAccounts)
        return nullptr;

    this->accounts[Account::getAccountsCount() -1] =new Account(n,c,p);
    return this->accounts[Account::getAccountsCount()-1];
}
Account * Bank::createAccount(int n, Client *c, double ir) {
    if(Account::getAccountsCount() >= this->maxAccounts)
        return nullptr;

    this->accounts[Account::getAccountsCount() -1] =new Account(n,c,ir);
    return this->accounts[Account::getAccountsCount()-1];
}

Account * Bank::createAccount(int n, Client *c, Client* p, double ir) {
    if(Account::getAccountsCount() >= this->maxAccounts)
        return nullptr;

    this->accounts[Account::getAccountsCount() - 1] =new Account(n,c,p,ir);
    return this->accounts[Account::getAccountsCount()-1];
}

void Bank::addInterest() {
    for(int i=0;i < Account::getAccountsCount(); i++) {
        this->accounts[i]->addInterest();
    }
}

void Bank::print_stats() {
    cout<< endl<< "Accounts:"  << endl;
    for (int i=0; i< Account::getAccountsCount(); i++){
        cout << "Number: " << this->accounts[i]->getNumber() << " Balance: " << this->accounts[i]->getBalance() << " ir: " << this->accounts[i]->getInterestRate() * 100 << "% Owner: " << this->accounts[i]->getOwner()->getName();
        if (this->accounts[i]->getPartner() != nullptr)
            cout << " Partner: " << this->accounts[i]->getPartner()->getName() << " code: " << this->accounts[i]->getPartner()->getCode();
        cout << endl;
    }
    cout << endl<< "Clients:"  << endl;

    for (int i=0; i<Client::getClientsCount(); i++){
        cout << "Code: " << this->clients[i]->getCode() << " Name: " << this->clients[i]->getName() << endl;
    }
}