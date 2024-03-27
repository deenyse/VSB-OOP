#include <iostream>
using namespace std;

class Route{
private:
    int id;
    int length;
public:
    Route(int id, int length){
        this->id = id;
        this->length = length;
    }
    int getId() const { return id; }
    int getLength() const { return length; }
};

class Bus{
private:
    int id;
    int status; // 0 - hasn't started; 1 - on route; 2 - finished;
    double distanceDrive;
    double speed;
    string name;
    Route* route;
public:
    Bus(int id, string name, Route * route = nullptr){
        this->id = id;
        this->status = 0;
        this->distanceDrive = 0;
        this -> speed = 0;
        this -> name = name;
        this -> route = route;
    }
    int getId() { return id; }
    int getStatus() { return status; }
    double getDistanceDrive() { return distanceDrive; }
    double getSpeed() { return speed; }
    string getName() { return name; }
    Route * getRoute() { return route; }
    Route * addRoute(Route * newRoute) { this->route = newRoute; return this->route;}

    // complicated
    void addDistance(int time); // time in hours // add check if route is finished;
    void beginRoute(); // add check if route not started and set speed;
    void endRoute(); // add check if route is finished and set status;
};

void Bus::beginRoute(){
    if (this->route == nullptr){
        cout << "Can't start route, rote not exist" << endl;
        return;
    }
    if (this->status !=1){
        this->status = 1;
        this->speed = 100;
    }
}

void Bus::endRoute(){
    if (this->route!= nullptr)
    {
        cout << "Can't end route, rote not exist" << endl;
        return;
    }
    this->status = 2; 
}


void Bus::addDistance(int time){
    this->distanceDrive += time * this->speed;
    if(distanceDrive > this->route->getLength())
        this->endRoute();
}


class CarrierManager{
private:
    int busAmount;
    int maxBusAmount;
    Bus ** vehicles;
    int routeAmount;
    int maxRouteAmount;
    Route ** routes;

public:
    
    CarrierManager(int maxBusAmount, int maxRoteAmount){
        this->busAmount = 0;
        this->maxBusAmount = maxBusAmount;
        this->vehicles = new Bus*[maxBusAmount]();
        this->routeAmount = 0;
        this->maxRouteAmount = maxRouteAmount;
        this->routes = new Route*[maxRouteAmount]();
    }
    ~CarrierManager();

    Bus * getVehicle(int id);
    Route * getRoute(int id);

    Bus * addBus(string name, Route * route);
    Route * addRoute(int length);

    void addDistance(int timeInHours);

    void printAgency();

    //later
    Bus * deleteBus(int id); // не обязательно
    Route * deleteRote(int id);// не обязатеьно

};
CarrierManager::~CarrierManager(){
    for(int i =0; i < maxBusAmount; i++){
        delete this->vehicles[i];
    }
    delete [] vehicles;

    for (int i =0; i < maxRouteAmount; i++){
        delete this->routes[i];
    }
    delete [] routes;
}

Bus * CarrierManager::getVehicle(int id){
    for (int i = 0; i < busAmount; i++){
        if (this->vehicles[i]->getId() == id){
            return this->vehicles[i];
        }
    }
    return nullptr;
}

Route * CarrierManager::getRoute(int id){
    for (int i = 0; i < routeAmount; i++){
        if (this->routes[i]->getId() == id){
            return this->routes[i];
        }
    }
    return nullptr;
}

Bus * CarrierManager::addBus(string name, Route * route = nullptr){
    if (this->busAmount >= maxBusAmount){
        cout << "Can't add bus, max amount reached" << endl;
        return nullptr;
    }
    this->vehicles[this->busAmount] = new Bus(this->busAmount, name, route);
    this->busAmount++;
    return this->vehicles[this->busAmount-1];
}

Route * CarrierManager::addRoute(int length){
    if (this->routeAmount >= maxRouteAmount){
        cout << "Can't add route, max amount reached" << endl;
        return nullptr;
    }
    this->routes[this->routeAmount] = new Route(this->routeAmount, length);
    this->routeAmount++;
    return this->routes[this->routeAmount-1];
}

void CarrierManager::addDistance(int timeInHours){
    for (int i = 0; i < this->busAmount; i++){
        this->vehicles[i]->addDistance(timeInHours);
    }
}

void CarrierManager::printAgency(){
    for (int i =0; i<this->busAmount; i++){
        cout<< "id: " <<this->vehicles[i]->getId()<< " Name: " << this->vehicles[i]->getName() << endl;
        cout<< "\tStatus: " << this->vehicles[i]->getStatus()<< endl;
        cout<< "\tSpeed: " << this->vehicles[i]->getSpeed() << endl;
        cout<< "\tDistance completed: " << this->vehicles[i]->getDistanceDrive()<< endl; 
        if (this->vehicles[i]->getRoute() != nullptr){
            cout<< "\tRoute:"<< endl;
            cout<< "\t\tId: " << this->vehicles[i]->getRoute()->getId()<< endl;
            cout<< "\t\tLenght: "<< this->vehicles[i]->getRoute()->getLength() << endl;
        }
    }
}

int main(){
    auto myBusAgency = new CarrierManager(10,10);
    myBusAgency->addBus("BokhdanZluty", myBusAgency->addRoute(255));

    myBusAgency->printAgency();
    delete myBusAgency;
    return 0;
}