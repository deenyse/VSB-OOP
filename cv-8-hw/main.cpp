#include <iostream>
#include <cmath>
using namespace std;

class Figure {
public:
    virtual double Content()  {
        return 0.0;
    }

    virtual double Perimeter()  {
        return 0.0;
    }
};

class Rectangle : public Figure {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Content() {
        return length * width;
    }

    double Perimeter()  {
        return 2 * (length + width);
    }
};

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double Content()  {
        return M_PI * radius * radius;
    }

    double Perimeter()  {
        return 2 * M_PI * radius;
    }
};

int main() {
    Figure ** figuresArray = new Figure*[8]();

    for (int i = 0; i < 4; i++) {
    figuresArray[i] = new Rectangle(10*i, 10*i*2);
    }
    for (int i = 4; i < 8; i++) {
        figuresArray[i] = new Circle(5*i);
    }

    cout << "Figure content:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << figuresArray[i]->Content() << endl;
    }
    cout << "Figure perimetr:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << figuresArray[i]->Perimeter() << endl;
    }


    return 0;
}
