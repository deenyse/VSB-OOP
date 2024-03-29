#include <iostream>
using namespace std;

class Route{
private:
    int id;
    double avarageSpeed;
    double length;
public:
    Route(int id, double length, double avarageSpeed){
        this->id = id;
        this->length = length;
        this->avarageSpeed = avarageSpeed;
    }
    int getId() const { return id; }
    double getLength() const { return length; }
    double getAvarageSpeed() const { return avarageSpeed; }
};

class Bus{
private:
    int id;
    int status; // 0 - hasn't started; 1 - on route; 2 - finished;
    double distanceDrive;
    string name;
    Route* route;

public:
    Bus(int id, string name, Route * route = nullptr){
        this->id = id;
        this->status = 0;
        this->distanceDrive = 0;
        this -> name = name;
        this -> route = route;
    }
    int getId() { return id; }
    int getStatus() { return status; }
    double getDistanceDrive() { return distanceDrive; }
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

    this->status = 1;

}

void Bus::endRoute(){
    if (this->route == nullptr)
    {
        cout << "Can't end route, rote not exist" << endl;
        return;
    }
    this->status = 2;
    this->distanceDrive =this->getRoute()->getLength();
}

void Bus::addDistance(int time){
    if (this->route == nullptr)
    {
        cout << "Can't add distance, route not exist" << endl;
        return;
    }

    if (this->status != 1) {
        cout << "Please start the route first" << endl;
        return;
    }

    this->distanceDrive += time * this->getRoute()->getAvarageSpeed();

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
    
    CarrierManager(int maxBusAmountInput, int maxRouteAmountInput){
        this->busAmount = 0;
        this->maxBusAmount = maxBusAmountInput;
        this->vehicles = new Bus*[maxBusAmount]();
        this->routeAmount = 0;
        this->maxRouteAmount = maxRouteAmountInput;
        this->routes = new Route*[maxRouteAmount]();
    }
    ~CarrierManager();

    Bus * getVehicle(int id);
    Route * getRoute(int id);

    Bus * addBus(string name, Route * route);
    Route * addRoute(double length, double avgSpped);

    void addRouteToBus(int routeId, int busId);
    void addDistance(int timeInHours);

    void printAgency();

    void startRoute(int id);
    //later
    Bus * deleteBus(int id); // не обязательно
    Route * deleteRote(int id);// не обязатеьно

};
CarrierManager::~CarrierManager(){
    for(int i =0; i < this->busAmount; i++){
        delete this->vehicles[i];
    }
    delete [] vehicles;

    for (int i =0; i < this->routeAmount; i++){
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
    cout << "No vehicle found for id " << id << endl;
    return nullptr;
}

Bus * CarrierManager::deleteBus(int id){
    Bus * tmp = nullptr;
    for (int i = 0; i < this->busAmount; i ++){
        if (this->vehicles[i]->getId() == id){
            tmp = this->vehicles[i];
            --this->busAmount;
            for (int j = i; j < this->busAmount; j++){
                this->vehicles[j] = this->vehicles[j+1];
            }
            break;
        }
    }
    return tmp;
}

Route * CarrierManager::deleteRote(int id){
    Route * tmp = nullptr;
    for (int i = 0; i < this->routeAmount; i ++){
        if (this->routes[i]->getId() == id){
            tmp = this->routes[i];
            --this->routeAmount;
            for (int j = i; j < this->routeAmount; j++){
                this->routes[j] = this->routes[j+1];
            }
            break;
        }
    }
    for (int i = 0; i < this->busAmount; i++ ){
        if (this->vehicles[i]->getRoute() == tmp)
            this->vehicles[i]->addRoute(nullptr);
    }
    return tmp;
}

Route * CarrierManager::getRoute(int id){
    for (int i = 0; i < routeAmount; i++){
        if (this->routes[i]->getId() == id){
            return this->routes[i];
        }
    }
    cout << "No route found for id " << id << endl;
    return nullptr;
}

Bus * CarrierManager::addBus(string name, Route * route = nullptr){
    if (this->busAmount >= maxBusAmount){
        cout << "Can't add bus, max amount reached" << endl;
        return nullptr;
    }
    int tmpId = this->busAmount;
    while (1){
        if (this->getVehicle(tmpId) != nullptr)
            tmpId ++;
        else break;
    }
    this->vehicles[this->busAmount] = new Bus(tmpId, name, route);
    this->busAmount++;
    return this->vehicles[this->busAmount-1];
}

Route * CarrierManager::addRoute(double length, double avgSpeed){
    if (this->routeAmount >= maxRouteAmount){
        cout << "Can't add route, max amount reached" << endl;
        return nullptr;
    }
    int tmpId = this->routeAmount;
    while (1){
        if (this->getRoute(tmpId) != nullptr)
            tmpId ++;
        else break;
    }
    this->routes[this->routeAmount] = new Route(tmpId, length, avgSpeed);
    this->routeAmount++;
    return this->routes[this->routeAmount-1];
}

void CarrierManager::addDistance(int timeInHours){
    for (int i = 0; i < this->busAmount; i++){
            this->vehicles[i]->addDistance(timeInHours);
    }
}

void CarrierManager:: startRoute(int id){
    auto tmpBus =this->getVehicle(id);
    if (tmpBus != nullptr)
        tmpBus->beginRoute();
}

void CarrierManager::addRouteToBus(int routeId, int busId){
    auto tmpBus = this->getVehicle(busId);
    auto tmpRoute = this->getRoute(routeId);
    if (tmpBus  != nullptr && tmpRoute != nullptr){
        tmpBus->addRoute(tmpRoute);
    }

}

void CarrierManager::printAgency(){
    for (int i =0; i<this->busAmount; i++){
        cout<< "id: " <<this->vehicles[i]->getId()<< "; Name: " << this->vehicles[i]->getName() << endl;

        if (this->vehicles[i]->getRoute() != nullptr){
            cout<< "\tStatus: ";
            this->vehicles[i]->getStatus() == 0 ? cout << "On start" : this->vehicles[i]->getStatus() == 1 ? cout <<  "On route" : cout <<  "On finish";
            cout << endl;
            cout<< "\tDistance completed: " << this->vehicles[i]->getDistanceDrive() / (this->vehicles[i]->getRoute()->getLength() / 100) << "%" << endl;
            cout<< "\tRoute:"<< endl;
            cout<< "\t\tId: " << this->vehicles[i]->getRoute()->getId()<< endl;
            cout<< "\t\tAvg speed: " << this->vehicles[i]->getRoute()->getAvarageSpeed() << endl;
            cout<< "\t\tLenght: "<< this->vehicles[i]->getRoute()->getLength() << endl;
        } else {
            cout << "\t No route added" << endl;
        }
    }
}

int main(){
    auto myBusAgency = new CarrierManager(10,10);

    myBusAgency->addBus("Yellow Bokhdan", myBusAgency->addRoute(255, 25.5));
    myBusAgency->startRoute(0);
    myBusAgency->addBus("Green mercedez");
    myBusAgency->addRouteToBus(myBusAgency->addRoute(100, 10)->getId(), 1);
    myBusAgency->startRoute(1);
    myBusAgency->deleteBus(0);
    myBusAgency->deleteRote(1);
    myBusAgency->addBus("Gray Bokhdan", myBusAgency->getRoute(1));
    myBusAgency->addRouteToBus(myBusAgency->addRoute(250, 25)->getId(), 2);
    myBusAgency->addBus("Blue Zaz", myBusAgency->getRoute(0))->beginRoute();

    for (int i = 0; i < 7; i++) {
        myBusAgency->addBus("ArrayBus", myBusAgency->addRoute(300, 60))->beginRoute();
    }
    myBusAgency->addBus("ArrayBus", myBusAgency->addRoute(300, 60));
    myBusAgency->addDistance(4);

    myBusAgency->printAgency();
    delete myBusAgency;
    return 0;
}