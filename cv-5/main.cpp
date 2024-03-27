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
    Bus(int id, string name){
        this->id = id;
        this->status = 0;
        this->distanceDrive = 0;
        this -> speed = 0;
        this -> name = name;
        this -> route = nullptr;
    }
    int getId() { return id; }
    int getStatus() { return status; }
    double getDistanceDrive() { return distanceDrive; }
    double getSpeed() { return speed; }
    string getName() { return name; }
    Route * getRoute() { return route; }

    Route * addRoute();
    void addDistance(int time); // time in minutes
    void beginRoute();
};


class CarrierManagement{
private:
    int busAmount;
    int maxBusAmount;
    Bus ** vehicles;
    int routeAmount;
    int maxRouteAmount;
    Route * routes;

public:
};

