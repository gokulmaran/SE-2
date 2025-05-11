// Concept:

// The Abstract Factory Pattern is an extension of the Factory Method Pattern. It is used when:

// There are multiple families of related products.
// We want to ensure that related objects are created together
// ============================================
#include <iostream>

// Step 1: Define Abstract Product Interfaces
class Button {
public:
    virtual void render() = 0;
    virtual ~Button() {}
};

class Checkbox {
public:
    virtual void check() = 0;
    virtual ~Checkbox() {}
};

// Step 2: Implement Concrete Products for Windows
class WindowsButton : public Button {
public:
    void render() override {
        std::cout << "Rendering Windows Button\n";
    }
};

class WindowsCheckbox : public Checkbox {
public:
    void check() override {
        std::cout << "Checking Windows Checkbox\n";
    }
};

// Step 3: Implement Concrete Products for Mac
class MacButton : public Button {
public:
    void render() override {
        std::cout << "Rendering Mac Button\n";
    }
};

class MacCheckbox : public Checkbox {
public:
    void check() override {
        std::cout << "Checking Mac Checkbox\n";
    }
};

// Step 4: Define Abstract Factory Interface
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual ~GUIFactory() {}
};

// Step 5: Implement Concrete Factories for Windows & Mac
class WindowsFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }
    
    Checkbox* createCheckbox() override {
        return new WindowsCheckbox();
    }
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }
    
    Checkbox* createCheckbox() override {
        return new MacCheckbox();
    }
};

// Step 6: Client Code
int main() {
    GUIFactory* factory = nullptr;
    
    // Example: Create Windows GUI
    factory = new WindowsFactory();
    Button* button = factory->createButton();
    Checkbox* checkbox = factory->createCheckbox();
    
    button->render();
    checkbox->check();

    // Clean up memory
    delete button;
    delete checkbox;
    delete factory;

    return 0;
}
