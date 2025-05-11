/*Factory pattern 

A Simple Factory is a design pattern that creates objects without exposing the instantiation logic to the client.
It provides a single point for object creation
============================================*/
#include <iostream>

// Step 1: Define an interface (Base Class)
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual ~Shape() {}       // Virtual destructor
};

// Step 2: Implement concrete classes
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Rectangle\n";
    }
};

// Step 3: Create the Factory
class ShapeFactory {
public:
    static Shape* createShape(const std::string& type) {
        if (type == "Circle") return new Circle();
        if (type == "Rectangle") return new Rectangle();
        return nullptr;  // Handle unknown type
    }
};

// Step 4: Client Code
int main() {
    Shape* shape1 = ShapeFactory::createShape("Circle");
    if (shape1) {
        shape1->draw();
        delete shape1;  // Manually free memory
    }

    Shape* shape2 = ShapeFactory::createShape("Rectangle");
    if (shape2) {
        shape2->draw();
        delete shape2;  // Manually free memory
    }

    return 0;
}
