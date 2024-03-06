#include <iostream>
using namespace std;

class KeyValue
{
private:
    int key;
    double value;
    KeyValue *next;

public:
    KeyValue(int k, double v);
    ~KeyValue();
    int getKey();
    double getValue();
    KeyValue *getNext();
    KeyValue *CreateNext(int k, double v);
    void Print();
    KeyValue *GetLastElement();
    // void ExtendByOne(int k, double v);
    void GrowWithLoop(int n);
    void GrowWithRecursion(int n);
    KeyValue *DeleteAtPosition(int index);
};

KeyValue::KeyValue(int k, double v)
{
    this->key = k;
    this->value = v;
    this->next = nullptr;
}

KeyValue::~KeyValue()
{
    if (this->next = nullptr)
    {
        delete this->next;
        this->next = nullptr;
    }
}

int KeyValue::getKey()
{
    return this->key;
}

double KeyValue::getValue()
{
    return this->value;
}

KeyValue *KeyValue::getNext()
{
    return this->next;
}

KeyValue *KeyValue::CreateNext(int k, double v)
{
    this->next = new KeyValue(k, v);
    return this->next;
}

void KeyValue::Print()
{
    cout << this->key << " " << this->value << endl;

    if (this->next != nullptr)
    {
        this->next->Print();
    }
}

KeyValue *KeyValue::GetLastElement()
{
    if (this->next == nullptr)
        return this;
    else
        return this->next->GetLastElement();
}

// replace at get last element, to separate functionality
// void KeyValue::ExtendByOne(int k, double v)
// {
//     if (this->next == nullptr)
//         this->next = new KeyValue(k, v);
//     else
//         this->next->ExtendByOne(k, v);
// }

// void KeyValue::GrowWithLoop(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         this->ExtendByOne(this->getKey() + 1 + i, this->getValue() + 1 + i);
//     }
// }

void KeyValue::GrowWithLoop(int n)
{
    for (int i = 0; i < n; i++)
    {
        this->GetLastElement()->CreateNext(this->getKey() + 1 + i, this->getValue() + 1 + i);
    }
}

void KeyValue::GrowWithRecursion(int n)
{
    if (n)
    {
        if (this->next == nullptr)
        {
            this->CreateNext(this->getKey() + 1, this->getValue() + 1)->GrowWithRecursion(n - 1);
        }
        else
        {
            this->next->GrowWithRecursion(n);
        }
    }
}

KeyValue *KeyValue::DeleteAtPosition(int index)
{
    KeyValue *temp = this->getNext();
    if (index == 1 && this->next != nullptr)
    {
        if (this->next != nullptr)
            this->next = temp->getNext();
        return temp;
    }
    else
    {
        if (this->next != nullptr)
        {
            return this->next->DeleteAtPosition(index - 1);
        }
        else
        {
            cout << "sequence hasn't enough elements" << endl;
            return nullptr;
        }
    }
}
int main()
{
    KeyValue *kv1 = new KeyValue(1, 1.5);

    kv1->GrowWithLoop(2);
    kv1->GrowWithRecursion(2);
    kv1->Print();
    cout << "Break one" << endl;
    KeyValue *kv2 = kv1->DeleteAtPosition(2);
    cout << kv2->getKey() << " " << kv2->getValue() << endl;
    cout << "Break two" << endl;
    kv1->Print();
    return 0;
}