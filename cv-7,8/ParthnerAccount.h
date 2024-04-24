#pragma once
#include "Account.h"

class ParthnerAccount : public Account{
private:
    Client* partner;

public:
    ParthnerAccount(int n, Client* c, double ir, bool isCustomIR, Client * partner);
    Client* getPartner() const { return partner; }

    void printStats() override;
};


