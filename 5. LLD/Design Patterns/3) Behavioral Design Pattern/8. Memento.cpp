/*Concept
The Memento Pattern is a behavioral design pattern that allows an object to save and restore its state without exposing its internal details.
 It is useful for implementing undo/redo functionality.
*/
#include <iostream>
#include <vector>
#include <string>

// Memento Class (Stores the state)
class Memento {
private:
    std::string state;
public:
    Memento(const std::string& s) : state(s) {}
    std::string getState() const { return state; }
};

// Originator Class (Creates and restores Memento)
class TextEditor {
private:
    std::string content;
public:
    void write(const std::string& text) {
        content = text;
    }

    Memento save() { 
        return Memento(content); 
    }

    void restore(const Memento& memento) {
        content = memento.getState();
    }

    void showContent() const {
        std::cout << "Current Content: " << content << "\n";
    }
};

// Caretaker Class (Manages Memento history)
class History {
private:
    std::vector<Memento> snapshots;
public:
    void saveState(const Memento& memento) {
        snapshots.push_back(memento);
    }

    Memento undo() {
        if (snapshots.empty()) {
            return Memento(""); // Default empty state
        }
        Memento memento = snapshots.back();
        snapshots.pop_back();
        return memento;
    }
};

// Main Function
int main() {
    TextEditor editor;
    History history;

    editor.write("Hello, World!");
    history.saveState(editor.save());

    editor.showContent();

    editor.write("Hello, C++!");
    history.saveState(editor.save());

    editor.showContent();

    // Undo last change
    editor.restore(history.undo());
    editor.showContent();

    // Undo again
    editor.restore(history.undo());
    editor.showContent();

    return 0;
}
