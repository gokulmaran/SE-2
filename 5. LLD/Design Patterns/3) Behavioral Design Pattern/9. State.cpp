/*Concept 
Here's a State Pattern example in C++ where an object changes its behavior when its internal state changes. 
We will model a simple turnstile (barrier gate) system with two states: Locked and Unlocked.*/
#include <iostream>

// Forward declaration of Context class
class Turnstile;

// Abstract State
class TurnstileState {
public:
    virtual void insertCoin(Turnstile* turnstile) = 0;
    virtual void pushBar(Turnstile* turnstile) = 0;
    virtual ~TurnstileState() = default;
};

// Context Class (Turnstile)
class Turnstile {
private:
    TurnstileState* currentState;

public:
    Turnstile(TurnstileState* state) : currentState(state) {}

    void setState(TurnstileState* state) {
        currentState = state;
    }

    void insertCoin() {
        currentState->insertCoin(this);
    }

    void pushBar() {
        currentState->pushBar(this);
    }
};

// Locked State
class LockedState : public TurnstileState {
public:
    void insertCoin(Turnstile* turnstile) override {
        std::cout << "Coin inserted, turnstile unlocked.\n";
        turnstile->setState(new UnlockedState()); // Transition to Unlocked
        delete this; // Free memory for old state
    }

    void pushBar(Turnstile* turnstile) override {
        std::cout << "Turnstile is locked, you need to insert a coin first.\n";
    }
};

// Unlocked State
class UnlockedState : public TurnstileState {
public:
    void insertCoin(Turnstile* turnstile) override {
        std::cout << "Turnstile is already unlocked.\n";
    }

    void pushBar(Turnstile* turnstile) override {
        std::cout << "Bar pushed, turnstile locked again.\n";
        turnstile->setState(new LockedState()); // Transition to Locked
        delete this; // Free memory for old state
    }
};

// Main Function
int main() {
    Turnstile* turnstile = new Turnstile(new LockedState()); // Initial state is Locked

    // Test the turnstile behavior
    turnstile->insertCoin();  // Coin inserted, unlocks turnstile
    turnstile->pushBar();     // Pushes the bar, locks turnstile again

    delete turnstile; // Free memory for the context
    return 0;
}
