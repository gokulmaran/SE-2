// Factory method design pattern 
// ----------------------------------
// The Factory Method Pattern is a creational design pattern that provides an interface for creating objects 
// but allows subclasses to decide which class to instantiate.
// ========================================
#include <iostream>

// Step 1: Define an abstract base class (Product)
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual ~Shape() {}       // Virtual destructor
};

// Step 2: Implement concrete classes (Concrete Products)
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

// Step 3: Define an abstract Factory class (Creator)
class ShapeFactory {
public:
    virtual Shape* createShape() = 0;  // Factory Method
    virtual ~ShapeFactory() {}         // Virtual destructor
};

// Step 4: Implement concrete factories (Concrete Creators)
class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Circle();
    }
};

class RectangleFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Rectangle();
    }
};

// Step 5: Client Code
int main() {
    ShapeFactory* factory1 = new CircleFactory();
    Shape* shape1 = factory1->createShape();
    shape1->draw();
    
    ShapeFactory* factory2 = new RectangleFactory();
    Shape* shape2 = factory2->createShape();
    shape2->draw();

    // Clean up
    delete shape1;
    delete factory1;
    delete shape2;
    delete factory2;

    return 0;
}
