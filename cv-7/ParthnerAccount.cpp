#pragma  once
#include "ParthnerAccount.h"
using namespace std;

ParthnerAccount::ParthnerAccount(int n, Client* c, double ir, bool isCustomIR, Client * partner) : Account(n,c,ir,isCustomIR){
    cout << "ParthnerAccount constructor" << endl;
    this -> partner = partner;
}