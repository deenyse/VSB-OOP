#include <iostream>
using namespace std;

class Osoba{
private:
    string name;
    string surname;
    string address;

public:
    Osoba(string name, string surname, string address);
    string getName() { return name; }
    string getSurname() { return surname; }
    string getAddress() { return address; }
};

Osoba::Osoba(string name, string surname, string address){
    this->name = name;
    this->surname = surname;
    this->address = address;
}

class Poloha{
private:
    string name;
    double cost;
public:
    Poloha(string name, double cost);
    string getName() { return name; }
    double getCost() { return cost; }

};

Poloha::Poloha(string name, double cost){
    this->name = name;
    this->cost = cost;
}

class Factura{
private:
    int cislo;
    Osoba* prijemec;
    int pocetPolozek;
    int maxPocetPolozek;
    Poloha ** polozky;

public:
    Factura(int cislo, string prijemec_name, string  prijemec_adress, string prijemec_surname, int maxPocetPolozek);
    ~Factura();

    bool pridatPolozku(string name, double cost);
    Poloha* odebratPolozku(string name);
    double spocitatCenu();
    void vytisknout();
    int getMaxPocetPolozek() { return this->maxPocetPolozek; }
};

Factura::Factura(int cislo, std::string prijemec_name,std::string prijemec_surname, std::string prijemec_adress,  int maxPocetPolozek) {
    this -> cislo = cislo;
    this -> prijemec = new Osoba(prijemec_name, prijemec_surname, prijemec_adress);
    this-> pocetPolozek =0;
    this -> maxPocetPolozek = maxPocetPolozek;
    this -> polozky = new Poloha * [maxPocetPolozek]();
}

Factura::~Factura(){
    for (int i =0; i< this-> pocetPolozek; i++){
        delete this->polozky[i];
    }

    delete[] this->polozky;
}

bool Factura::pridatPolozku(std::string name, double cost) {
    if (this -> pocetPolozek < this -> maxPocetPolozek){
        this->polozky[this->pocetPolozek] = new Poloha(name, cost);
        this->pocetPolozek++;
        return true;
    }
    else
        return false;
}

Poloha * Factura::odebratPolozku(std::string name) {
    Poloha * tmp = nullptr;

    for (int i = 0; i < this -> pocetPolozek; i++){
        if (this->polozky[i]->getName() == name){
            tmp = polozky[i];
            for (int j = i;  j < this->pocetPolozek -1; j++){
                this->polozky[j] = this->polozky[j+1];
            }
            this->pocetPolozek --;
            break;
        }
    }
    return tmp;
}

double Factura::spocitatCenu() {
    double totalCost = 0;
    for (int i = 0; i < this -> pocetPolozek; i ++){
        totalCost += polozky[i]->getCost();
    }

    return totalCost;
}

void Factura::vytisknout() {
    cout << "Factura: " << endl;
    cout << "Cislo:" << this->cislo << endl;
    cout << "Prijemec" << endl;
    cout << "\tname: " << this->prijemec->getName() << endl;
    cout << "\tsurname: " << this->prijemec->getSurname() << endl;
    cout << "\tadress: " << this->prijemec->getAddress() << endl;
    cout << "Polozky:" << endl;
    for (int i = 0; i < this-> pocetPolozek; i++){
        cout << "\t" << this->polozky[i]->getName() << " " << this->polozky[i]->getCost() << endl;
    }

    cout << "Tolal: " << this->spocitatCenu() << endl;
}
int main (){
    auto *myFactura = new Factura(123456, "Vasya", "Peckin", "simpleadress", 12 );

    for (int i = 0; i < myFactura->getMaxPocetPolozek(); i++){
        myFactura->pridatPolozku("Item", i);
    }

    myFactura->odebratPolozku("Item");
    myFactura->pridatPolozku("NewItem", 10);
    myFactura->odebratPolozku("NewItem");
    myFactura->odebratPolozku("Item");
    myFactura->pridatPolozku("NewItem", 20);
    myFactura->vytisknout();
    return 0;
}