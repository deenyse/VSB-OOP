#pragma once
#include <iostream>
using namespace std;

class Client {
private:
    string name;
    int code;
    static int clientsCount;
public:
    static int getClientsCount();
    Client(string name, int code);
    ~Client();
    string getName() { return name; }
    int getCode() { return code; }
};


