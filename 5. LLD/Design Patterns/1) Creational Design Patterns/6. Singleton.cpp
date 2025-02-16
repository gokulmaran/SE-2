/* Concept
The Singleton Pattern is a creational design pattern that ensures:
✅ Only one instance of a class exists.
✅ Global access to that instance.
======================================*/
#include <iostream>
#include <mutex> // Include this for std::mutex

using namespace std;

class PaymentGatewayManager
{
private:
    PaymentGatewayManager()
    {
        cout << "Payment Gateway Manager initialized." << endl;
    }

    static PaymentGatewayManager *instance;
    static std::mutex mtx;

public:
    static PaymentGatewayManager *getInstance()
    {
        if (instance == nullptr)
        {
            // Lock the mutex to ensure thread safety
            std::lock_guard<std::mutex> lock(mtx);
            if (instance == nullptr)
            {
                instance = new PaymentGatewayManager();
            }
        }
        return instance;
    }

    void processPayment(double amount)
    {
        cout << "Processing payment of $" << amount << " through the payment gateway." << endl;
    }
};

// Initialize the static member variables
PaymentGatewayManager *PaymentGatewayManager::instance = nullptr;
std::mutex PaymentGatewayManager::mtx;

int main()
{
    PaymentGatewayManager *paymentGateway = PaymentGatewayManager::getInstance();

    paymentGateway->processPayment(100.0);

    // Attempt to create another instance (should return the existing instance)
    PaymentGatewayManager *anotherPaymentGateway = PaymentGatewayManager::getInstance();

    // Check if both instances are the same
    if (paymentGateway == anotherPaymentGateway)
    {
        cout << "Both instances are the same. Singleton pattern is working" << endl;
    }
    else
    {
        cout << "Singleton pattern is not working correctly" << endl;
    }
    return 0;
}
