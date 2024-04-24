#pragma once
#include "Account.h"
#include "ParthnerAccount.h"

class Bank {
private:
    Client** clients;
    int maxClients;
    Account** accounts;
    int maxAccounts;
    static double defaultIR;
public:
    Bank(int c, int a);
    ~Bank();

    Client* getClient(int code);
    Account* getAccount(int number);
    double getDefaultIR();
    void modifiIneterestRate(double rate);
    Client* createClient(int code, string name);

    Account* createAccount(int n, Client* c);
    ParthnerAccount* createAccount(int n, Client* c, Client *p);
    Account* createAccount(int n, Client* c, double ir);
    ParthnerAccount* createAccount(int n, Client* c, Client *p, double ir);

    void addInterest();
    void print_stats();
};

