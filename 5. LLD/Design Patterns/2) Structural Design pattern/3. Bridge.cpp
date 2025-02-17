/*Concept:
The Bridge Pattern is a structural design pattern that decouples an abstraction from its implementation, allowing them to evolve independently.

Useful when multiple abstractions and implementations need to be managed.
Encourages composition over inheritance, reducing code complexity.
==============================================*/
#include <iostream>
#include <memory>

// Step 1: Implementation Interface (Bridge)
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setVolume(int level) = 0;
    virtual ~Device() {}
};

// Step 2: Concrete Implementations (TV & Radio)
class TV : public Device {
public:
    void turnOn() override {
        std::cout << "TV is turned ON.\n";
    }

    void turnOff() override {
        std::cout << "TV is turned OFF.\n";
    }

    void setVolume(int level) override {
        std::cout << "TV volume set to " << level << ".\n";
    }
};

class Radio : public Device {
public:
    void turnOn() override {
        std::cout << "Radio is turned ON.\n";
    }

    void turnOff() override {
        std::cout << "Radio is turned OFF.\n";
    }

    void setVolume(int level) override {
        std::cout << "Radio volume set to " << level << ".\n";
    }
};

// Step 3: Abstraction (Remote Control)
class RemoteControl {
protected:
    std::shared_ptr<Device> device;

public:
    RemoteControl(std::shared_ptr<Device> dev) : device(dev) {}

    virtual void powerOn() {
        device->turnOn();
    }

    virtual void powerOff() {
        device->turnOff();
    }

    virtual void volumeUp() {
        device->setVolume(10); // Default volume
    }
};

// Step 4: Extended Abstraction (Advanced Remote)
class AdvancedRemoteControl : public RemoteControl {
public:
    AdvancedRemoteControl(std::shared_ptr<Device> dev) : RemoteControl(dev) {}

    void mute() {
        std::cout << "Muting device.\n";
        device->setVolume(0);
    }
};

// Step 5: Client Code
int main() {
    std::shared_ptr<Device> tv = std::make_shared<TV>();
    std::shared_ptr<Device> radio = std::make_shared<Radio>();

    RemoteControl remote(tv);
    remote.powerOn();
    remote.volumeUp();
    remote.powerOff();

    std::cout << "--------------------\n";

    AdvancedRemoteControl advRemote(radio);
    advRemote.powerOn();
    advRemote.mute();
    advRemote.powerOff();

    return 0;
}
