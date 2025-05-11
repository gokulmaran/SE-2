/*Concept --Same task but different algorithm
The Strategy Pattern is a behavioral design pattern that enables selecting an 
algorithm at runtime. Instead of hardcoding behavior inside a class, we define multiple strategies (algorithms) and allow the user to switch between them dynamically.
*/
#include <iostream>

// Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() = default;
};

// Concrete Strategy 1: Credit Card Payment
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid $" << amount << " using Credit Card.\n";
    }
};

// Concrete Strategy 2: PayPal Payment
class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid $" << amount << " using PayPal.\n";
    }
};

// Context Class
class PaymentContext {
private:
    PaymentStrategy* strategy;  // Raw pointer to strategy
public:
    PaymentContext() : strategy(nullptr) {}  // Initialize with no strategy

    void setStrategy(PaymentStrategy* newStrategy) {
        strategy = newStrategy;  // Assign the new strategy
    }

    void processPayment(int amount) {
        if (strategy) {
            strategy->pay(amount);
        } else {
            std::cout << "No payment method selected.\n";
        }
    }
};

// Main Function
int main() {
    PaymentContext context;
    
    CreditCardPayment creditCard;
    PayPalPayment paypal;

    // Paying using Credit Card
    context.setStrategy(&creditCard);
    context.processPayment(100);

    // Paying using PayPal
    context.setStrategy(&paypal);
    context.processPayment(200);

    return 0;
}
