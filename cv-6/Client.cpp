#include "Client.h"
int Client::clientsCount = 0;

Client::Client(string name, int code){
    this->name = name;
    this->code = code;
    Client::clientsCount +=1;
}

Client::~Client() {
    Client::clientsCount-=1;
}

int Client::getClientsCount() {
     return Client::clientsCount;
}