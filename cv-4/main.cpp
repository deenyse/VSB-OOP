#include <iostream>
using namespace std;

class Client{
private:
    string name;
    int code;

public:
    Client(string name, int code);
    string getName() { return name; }
    int getCode() { return code; }
};

Client::Client(string name, int code){
    this->name = name;
    this->code = code;
}

class Account{
private:
    int number;
    double balance;
    double interestRate;
    Client* owner;
    Client* partner;

public:
    Account(int n, Client* c);
    Account(int n, Client* c, Client *p);
    Account(int n, Client* c, double ir);
    Account(int n, Client* c, Client *p, double ir);

    int getNumber() { return this->number; };
    double getBalance() { return this->balance;}
    double getInterestRate() { return this->interestRate;}
    Client* getOwner() { return this->owner;}
    Client* getPartner() { return this->partner;}

    bool canWithdraw(double a); // +able to get money

    void Deposit(double a);//+ depose money
    bool Withdraw(double a); // +withdraw money
    void addInterest(); //+ add interest add % to whole accounts
};

Account::Account(int n, Client *c) {
    this->number = n;
    this->owner = c;
    this->partner = nullptr;
    this->interestRate = 0.05;
    this->balance =0;
}

Account::Account(int n, Client *c, Client *p) {
    this->number = n;
    this->owner =c;
    this->partner = p;
    this->interestRate = 0.05;
    this->balance =0;
}

Account::Account(int n, Client *c, double ir) {
    this->number = n;
    this->owner = c;
    this->partner = nullptr;
    this->interestRate = ir;
    this->balance =0;
}

Account::Account(int n, Client *c, Client *p, double ir) {
    this->number = n;
    this->owner = c;
    this->partner = p;
    this->interestRate = ir;
    this->balance =0;
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

class Bank {
private:
    Client** clients;
    int clientsCount;
    int maxClients;
    Account** accounts;
    int accountsCount;
    int maxAccounts;
public:
    Bank(int c, int a);
    ~Bank();

    Client* getClient(int code);
    Account* getAccount(int number);

    Client* createClient(int code, string name);

    Account* createAccount(int n, Client* c);
    Account* createAccount(int n, Client* c, Client *p);
    Account* createAccount(int n, Client* c, double ir);
    Account* createAccount(int n, Client* c, Client *p, double ir);

    void addInterest();
    void print_stats();
};

Bank::Bank(int c, int a) {
    this->clients = new Client * [c]();
    this->clientsCount = 0;
    this->maxClients = c;
    this->accounts = new Account * [a]();
    this->accountsCount = 0;
    this->maxAccounts = a;
}

Bank::~Bank(){
    for (int i=0; i< this->accountsCount; i++){
        delete this->accounts[i];
    }
    delete [] this->accounts;
    for (int i=0; i<clientsCount; i++){
        delete  this->clients[i];
    }
    delete [] this->clients;

}

Client * Bank::getClient(int code){
    for (int i=0; i<clientsCount; i++){
        if(this->clients[i]->getCode() == code)
            return this->clients[i];
    }
    return nullptr;
}

Account* Bank::getAccount(int number) {
    for(int i=0; i<accountsCount; i++){
        if (this->accounts[i]->getNumber() == number)
            return this->accounts[i];

    }
    return nullptr;
}

Client* Bank::createClient(int code, std::string name) {
    if (this->clientsCount >= this->maxClients)
        return nullptr;
    this->clients[clientsCount] = new Client(name, code);

    this->clientsCount++;
    return this->clients[clientsCount-1];
}

Account * Bank::createAccount(int n, Client *c) {
    if(this->accountsCount >= this->maxAccounts)
        return nullptr;

    this->accounts[this->accountsCount] =new Account(n,c);
    this->accountsCount ++;
    return this->accounts[this->accountsCount-1];
}

Account * Bank::createAccount(int n, Client *c, Client *p) {
    if(this->accountsCount >= this->maxAccounts)
        return nullptr;

    this->accounts[this->accountsCount] =new Account(n,c,p);
    this->accountsCount ++;
    return this->accounts[this->accountsCount-1];
}
Account * Bank::createAccount(int n, Client *c, double ir) {
    if(this->accountsCount >= this->maxAccounts)
        return nullptr;

    this->accounts[this->accountsCount] =new Account(n,c,ir);
    this->accountsCount ++;
    return this->accounts[this->accountsCount-1];
}

Account * Bank::createAccount(int n, Client *c, Client* p, double ir) {
    if(this->accountsCount >= this->maxAccounts)
        return nullptr;

    this->accounts[this->accountsCount] =new Account(n,c,p,ir);
    this->accountsCount ++;
    return this->accounts[this->accountsCount-1];
}

void Bank::addInterest() {
    for(int i=0;i < this->accountsCount; i++) {
        this->accounts[i]->addInterest();
    }
}

void Bank::print_stats() {
    cout<< endl<< "Accounts:"  << endl;
    for (int i=0; i< this->accountsCount; i++){
        cout << "Number: " << this->accounts[i]->getNumber() << " Balance: " << this->accounts[i]->getBalance() << " ir: " << this->accounts[i]->getInterestRate() * 100 << "% Owner: " << this->accounts[i]->getOwner()->getName();
        if (this->accounts[i]->getPartner() != nullptr)
            cout << " Partner: " << this->accounts[i]->getPartner()->getName() << " code: " << this->accounts[i]->getPartner()->getCode();
        cout << endl;
    }
    cout << endl<< "Clients:"  << endl;

    for (int i=0; i<clientsCount; i++){
        cout << "Code: " << this->clients[i]->getCode() << " Name: " << this->clients[i]->getName() << endl;
    }
}

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

    delete monoBank;
    return  0;
}
