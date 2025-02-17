/*Concept- skeleton/template of algos
 defines the structure of an algorithm in a base class but allows subclasses to override specific steps.
*/
#include <iostream>

// Abstract Base Class (Template)
class FileProcessor {
public:
    // Template Method - Defines the algorithm structure
    void processFile() {
        openFile();
        readFile();
        closeFile();
    }

    // Common step (Implemented in Base Class)
    void openFile() { std::cout << "Opening file...\n"; }

    // Abstract steps (To be overridden by subclasses)
    virtual void readFile() = 0;

    // Common step (Implemented in Base Class)
    void closeFile() { std::cout << "Closing file...\n"; }

    virtual ~FileProcessor() = default;
};

// Concrete Class 1: Text File Processing
class TextFileProcessor : public FileProcessor {
public:
    void readFile() override {
        std::cout << "Reading text file contents...\n";
    }
};

// Concrete Class 2: CSV File Processing
class CSVFileProcessor : public FileProcessor {
public:
    void readFile() override {
        std::cout << "Reading CSV file contents...\n";
    }
};

// Main Function
int main() {
    std::cout << "Processing Text File:\n";
    TextFileProcessor textProcessor;
    textProcessor.processFile();

    std::cout << "\nProcessing CSV File:\n";
    CSVFileProcessor csvProcessor;
    csvProcessor.processFile();

    return 0;
}
