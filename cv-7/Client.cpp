#include "Client.h"
using namespace std;
int Client::clientsCount = 0;

Client::Client(string name, int code){
    this->name = name;
    this->code = code;
    Client::clientsCount +=1;
    cout << "Client constructor" << endl;
}

Client::~Client() {
    Client::clientsCount-=1;
    cout << "Client destructor" << endl;
}

int Client::getClientsCount() {
     return Client::clientsCount;
}