/*Facade
The Facade Pattern provides a simplified interface to a complex subsystem.
It hides the details of multiple components and exposes only a single entry point for clients.
==============================================*/
#include <iostream>

using namespace std;

// Subsystem 1
class CPU {
public:
    void start() { cout << "CPU started." << endl; }
    void execute() { cout << "CPU executing instructions." << endl; }
    void shutdown() { cout << "CPU shut down." << endl; }
};

// Subsystem 2
class Memory {
public:
    void load() { cout << "Memory loaded." << endl; }
    void clear() { cout << "Memory cleared." << endl; }
};

// Subsystem 3
class HardDrive {
public:
    void read() { cout << "Hard Drive reading data." << endl; }
    void write() { cout << "Hard Drive writing data." << endl; }
};

// **Facade Class** (Simplifies interaction with the subsystems)
class ComputerFacade {
private:
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;

public:
    void startComputer() {
        cout << "Starting Computer..." << endl;
        cpu.start();
        memory.load();
        hardDrive.read();
        cout << "Computer is ready to use." << endl;
    }

    void shutdownComputer() {
        cout << "Shutting Down Computer..." << endl;
        hardDrive.write();
        memory.clear();
        cpu.shutdown();
        cout << "Computer has been shut down." << endl;
    }
};

// **Client Code**
int main() {
    ComputerFacade myComputer;
    myComputer.startComputer();  // Facade simplifies starting the computer
    cout << "----------------------" << endl;
    myComputer.shutdownComputer(); // Facade simplifies shutting down
    return 0;
}
