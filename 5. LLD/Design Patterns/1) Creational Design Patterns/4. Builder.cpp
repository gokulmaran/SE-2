// Concept:
// The Builder Pattern is a creational design pattern used for creating complex objects step by step.

// It separates the object construction logic from the object representation.
// =============================================================
#include <iostream>
#include <string>

// Step 1: Define the Product (Car)
class Car {
public:
    std::string engine;
    std::string color;
    int seats;

    void showCar() {
        std::cout << "Car Details:\n";
        std::cout << "Engine: " << engine << "\n";
        std::cout << "Color: " << color << "\n";
        std::cout << "Seats: " << seats << "\n";
    }
};

// Step 2: Define the Abstract Builder
class CarBuilder {
public:
    virtual void setEngine(const std::string& type) = 0;
    virtual void setColor(const std::string& color) = 0;
    virtual void setSeats(int num) = 0;
    virtual Car* getCar() = 0;
    virtual ~CarBuilder() {}
};

// Step 3: Implement the Concrete Builder
class SportsCarBuilder : public CarBuilder {
private:
    Car* car;
public:
    SportsCarBuilder() { car = new Car(); }  // Initialize new Car
    void setEngine(const std::string& type) override { car->engine = type; }
    void setColor(const std::string& color) override { car->color = color; }
    void setSeats(int num) override { car->seats = num; }
    
    Car* getCar() override { return car; }  // Return the built car

    ~SportsCarBuilder() { delete car; }  // Destructor
};

// Step 4: Define the Director
class Director {
public:
    Car* createSportsCar(CarBuilder& builder) {
        builder.setEngine("V8 Turbo");
        builder.setColor("Red");
        builder.setSeats(2);
        return builder.getCar();
    }
};

// Step 5: Client Code
int main() {
    SportsCarBuilder builder;
    Director director;

    Car* myCar = director.createSportsCar(builder);
    myCar->showCar();

    delete myCar;  // Clean up memory
    return 0;
}
