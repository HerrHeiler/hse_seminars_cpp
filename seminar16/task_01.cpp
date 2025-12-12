#include <iostream>
#include <string>

// TODO 1: Create a base class Shape
class Shape {
protected:
    // TODO 2: Add protected field name
    std::string name;
public:
    // TODO 3: Constructor that sets name
    Shape(const std::string& _name) : name(_name) {}
    // TODO 4: area() that returns 0.0 in base class
    double area() const {
        return 0.0;
    }

    // TODO 5: printInfo() that prints the name
    void printInfo() {
        std::cout << name << std::endl;
    }
};

// TODO 6: Create Rectangle inheriting from Shape
class Rectangle : public Shape {
private:
    // TODO 7: width and height fields
    double width;
    double height; 

public:
    // TODO 8: Rectangle constructor that sets name, width, height
    Rectangle(std::string _name, double _width, double _height) : Shape(_name), width(_width), height(_height) {}
    // TODO 9: Redefine area() (not virtual override)
    double area() const {
        return width * height;
    }

    // TODO 10: Redefine printInfo() to show rectangle data
    void printInfo() {
        std::cout << name << width << ' ' << height << std::endl;
    }
};

// TODO 11: Create Circle inheriting from Shape
class Circle : public Shape {
private:
    // TODO 12: radius field
    double radius;
public:
    // TODO 13: Constructor that sets name and radius
    Circle();
    // TODO 14: Redefine area() (not virtual override)

    // TODO 15: Redefine printInfo() to show circle data
};


int main() {
    // TODO 16: Create Rectangle and Circle objects normally (not pointers)
    //Rectangle rect("MyRectangle", 3.0, 4.0);
    //Circle circ("MyCircle", 5.0);

    // TODO 17: Call printInfo() and area() directly
    //rect.printInfo();
    //std::cout << "Area: " << rect.area() << "\n\n";

    //circ.printInfo();
    //std::cout << "Area: " << circ.area() << "\n";

    return 0;
}
