#include <iostream>
using namespace std;

class KeyValue{
    private:
        int key;
        double value;
    public:
        KeyValue(int key, double value);
        int GetKey();
        double GetValue();
};


class KeyValues{
    private:
        KeyValue** keyValues;
        int count;
    public:
        KeyValues(int n);
        ~KeyValues();
        KeyValue* createObject(int key, double value);
        KeyValue* searchObject(int key);
        KeyValue* deleteObject(int key);
        // debug
        KeyValue ** getKeyValues(){
            return keyValues;
        }
        int Count();
};


KeyValue::KeyValue(int key, double value) {
    this -> key = key;
    this -> value = value;
}

int KeyValue::GetKey(){
    return this -> key;
}

double KeyValue::GetValue() {
    return this -> value;
}

KeyValues::KeyValues(int n){
    this-> keyValues = new KeyValue*[n]();
    this -> count = 0;
}

KeyValues::~KeyValues(){
    for (int i = 0; i < this->count; i++){
        delete this->keyValues[i];
    }

    delete[] this->keyValues;
}


int KeyValues::Count(){
    return this->count;
}

KeyValue* KeyValues::createObject(int key, double value){
    this->keyValues[this->count] = new KeyValue(key, value);
    this ->count++;
    return this->keyValues[this->count-1];
}

KeyValue* KeyValues::searchObject(int key) {
    for(int i = 0; i < this->count; i++) {
        if (this-> keyValues[i]->GetKey() == key){
            return this->keyValues[i];
        }
    }
    return nullptr;
}

KeyValue* KeyValues::deleteObject(int key){
    KeyValue* tmp = nullptr;
    for (int i = 0; i < this->count; i++) {
        if (this-> keyValues[i]->GetKey() == key){
            tmp = keyValues[i];
            this -> count --;
            for (int j = i; j < this->count; j++) {
                this -> keyValues[j] = this -> keyValues[j+1];
            }
            break;
        }
    }
    return  tmp;
}
int main (){
    KeyValues* valuesArray = new KeyValues(10);
    for (int i = 0; i < 5; i++){
        valuesArray->createObject(i, 100+i);
    }

    valuesArray->deleteObject(2);
    valuesArray->deleteObject(1);
    valuesArray->deleteObject(2);

    for (int i = 0; i < valuesArray->Count(); i++){
        cout << valuesArray->getKeyValues()[i]->GetKey() << endl;
    }


    delete valuesArray;
    return 0;
}