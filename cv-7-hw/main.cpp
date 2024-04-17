#include <iostream>
using namespace std;

class Mamals{
public:
    void feedChildByMilck(){
        cout << "futtern mit Milch" << endl;
    }
};

class Hunting : public Mamals{
public:
    void hunt(){
        cout << "let's go hunt do do dodo do do" << endl;
    }

};

class Dogs : public Hunting{
public:

    void woof(){
        cout << "Talk so pretty, but your heart got teeth" << endl;
    }
};

class Wolf : public Dogs{
public:

    void run(){
        cout << "wolf run only when hunts" << endl;
    }
};

int main(){
    auto TheWolf = new Wolf();

    TheWolf->feedChildByMilck();
    TheWolf->hunt();
    TheWolf->woof();
    TheWolf->run();
    return 0;
}