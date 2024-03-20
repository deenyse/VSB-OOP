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
}

Account::Account(int n, Client *c, Client *p) {
    this->number = n;
    this->owner =c;
    this->partner = p;
}

Account::Account(int n, Client *c, double ir) {
    this->number = n;
    this->owner = c;
    this->partner = nullptr;
    this->interestRate = ir;
}

Account::Account(int n, Client *c, Client *p, double ir) {
    this->number = n;
    this->owner = c;
    this->partner = p;
    this->interestRate = ir;
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
    int cliensCount;

    Account** accounts;
    int accountsCount;
public:
    Bank(Client** clients, int cliensAmount);
    ~Bank();

    Client* getClient(int code);
    Account* getAccount(int number);

    Client* createClient(int code, string name);

    Account* CreateAccount(int n, Client* c);
    Account* CreateAccount(int n, Client* c, Client *p);
    Account* CreateAccount(int n, Client* c, double ir);
    Account* CreateAccount(int n, Client* c, Client *p, double ir);

    void addInterest();

};
int main(){

    return  0;
}

//
//bank maxclients
// bank maxaccounts