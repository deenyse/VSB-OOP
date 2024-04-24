#include <iostream>
#include <cmath>

class Shape {
public:
    double Content() const {
        return 0.0; // Default implementation for content
    }

    double Perimeter() const {
        return 0.0; // Default implementation for perimeter
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Content() const {
        return length * width;
    }

    double Perimeter() const {
        return 2 * (length + width);
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double Content() const {
        return M_PI * radius * radius;
    }

    double Perimeter() const {
        return 2 * M_PI * radius;
    }
};

int main() {
    Rectangle rect(5, 4);
    Circle circle(3);

    std::cout << "Rectangle: " << std::endl;
    std::cout << "Area: " << rect.Content() << std::endl;
    std::cout << "Perimeter: " << rect.Perimeter() << std::endl;

    std::cout << "Circle: " << std::endl;
    std::cout << "Area: " << circle.Content() << std::endl;
    std::cout << "Perimeter: " << circle.Perimeter() << std::endl;

    return 0;
}
