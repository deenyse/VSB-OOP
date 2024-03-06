#include <iostream>
using namespace std;

void helloWorld()
{
    cout << "Hello\nWorld!" << endl;
}

void intChanger(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void getTwoNums(int *x, int *y)
{
    cin >> *x >> *y;
}

void divider()
{
    int a, b = 0;
    getTwoNums(&a, &b);
    cout << (a > b ? a / b : b / a) << endl;
}

void numberCompare()
{
    int a, b = 0;
    getTwoNums(&a, &b);
    if (a == b)
    {
        cout << "equal" << endl;
    }
    else
    {
        if (a > b)
        {
            cout << "first is bigger" << endl;
        }
        else
        {
            cout << "second is bigger" << endl;
        }
    }
}

void numMultipliers()
{
    int a = 0;
    cin >> a;
    if (a <= 100)
        for (int i = a; i <= 100; i++)
            if (i % a == 0)
                cout << i << endl;
}

void findDivider()
{
    int a = 0;
    int b = 0;
    getTwoNums(&a, &b);
    if (a == b || a == 0 || b == 0)
    {
        cout << a << endl;
    }
    else
    {
        while (b % a != 0)
        {
            if (a > b)
                a = a % b;
            else
                b = b % a;
        }
        cout << a << endl;
    }
}

void printSquare()
{
    int a = 0;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (j == 0 || i == 0 || i == a - 1 || j == a - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

struct
{
    string jmeno;
    string prijmeni;
    int vek;
} StructuraOsoba;

class Osoba
{
    string jmeno = StructuraOsoba.jmeno;
    string prijmeni = StructuraOsoba.prijmeni;
    int vek = StructuraOsoba.vek;

public:
    void gratulation()
    {
        cout << "Ahoj, ja jsem" << jmeno << " " << prijmeni << "a mam" << vek << "let" << endl;
    }
};
int main()
{
    // 1
    //  helloWorld();
    // 2
    //  intChanger(&a, &b);
    // 3
    //  divider();
    // 4
    //  numberCompare();
    // 5
    //  numMultipliers();
    // 6
    // findDivider();
    // 7
    // printSquare();
    // 8
    StructuraOsoba.jmeno = "Ken";
    StructuraOsoba.prijmeni = "qwerty";
    StructuraOsoba.vek = 34;
    // 9
    Osoba myKen;
    myKen.gratulation();

    return 0;
}