/*Concept --define new operations on object
The Visitor Pattern is a behavioral design pattern that allows you to define new operations on objects without changing their classes.
 It separates the algorithm from the object structure by moving the operation logic to a separate visitor class.*/
 #include <iostream>
#include <vector>

// Forward declarations
class Circle;
class Rectangle;
class ShapeVisitor;

// Element Interface
class Shape {
public:
    virtual void accept(ShapeVisitor& visitor) = 0;
    virtual ~Shape() = default;
};

// Concrete Element: Circle
class Circle : public Shape {
public:
    void accept(ShapeVisitor& visitor) override;
    void draw() const { std::cout << "Drawing Circle\n"; }
};

// Concrete Element: Rectangle
class Rectangle : public Shape {
public:
    void accept(ShapeVisitor& visitor) override;
    void draw() const { std::cout << "Drawing Rectangle\n"; }
};

// Visitor Interface
class ShapeVisitor {
public:
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
    virtual ~ShapeVisitor() = default;
};

// Concrete Visitor: DrawingVisitor (Draws shapes)
class DrawingVisitor : public ShapeVisitor {
public:
    void visit(Circle& circle) override {
        circle.draw();
    }

    void visit(Rectangle& rectangle) override {
        rectangle.draw();
    }
};

// Concrete Visitor: AreaVisitor (Calculates area of shapes)
class AreaVisitor : public ShapeVisitor {
public:
    void visit(Circle& circle) override {
        std::cout << "Calculating area of Circle: Area = π * r^2\n";
    }

    void visit(Rectangle& rectangle) override {
        std::cout << "Calculating area of Rectangle: Area = length * width\n";
    }
};

// Implementing accept methods
void Circle::accept(ShapeVisitor& visitor) {
    visitor.visit(*this);
}

void Rectangle::accept(ShapeVisitor& visitor) {
    visitor.visit(*this);
}

// Main Function
int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());

    // Create visitors
    DrawingVisitor drawVisitor;
    AreaVisitor areaVisitor;

    // Visit each shape
    for (Shape* shape : shapes) {
        shape->accept(drawVisitor); // Draw the shape
        shape->accept(areaVisitor); // Calculate area of the shape
    }

    // Clean up
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
