/*Concept
The Flyweight Pattern is used to reduce memory usage when dealing with a large number of objects by sharing common state.
===========================*/
#include <iostream>
#include <unordered_map>

using namespace std;

// **Flyweight Class** (Shared Object)
class Character {
private:
    char symbol;  // Intrinsic state (shared among objects)

public:
    Character(char sym) : symbol(sym) {}

    void display(int fontSize) {  // Extrinsic state (varies per object)
        cout << "Character: " << symbol << " | Font Size: " << fontSize << endl;
    }
};

// **Flyweight Factory** (Manages Shared Objects)
class CharacterFactory {
private:
    unordered_map<char, Character*> characters; // Cache for Flyweight objects

public:
    Character* getCharacter(char symbol) {
        if (characters.find(symbol) == characters.end()) {
            characters[symbol] = new Character(symbol);  // Create new character if not exists
        }
        return characters[symbol]; // Return existing instance
    }

    ~CharacterFactory() {  // Cleanup all allocated objects
        for (auto& pair : characters) {
            delete pair.second;
        }
    }
};

// **Client Code**
int main() {
    CharacterFactory factory;

    // Multiple requests for same characters (Shared)
    Character* c1 = factory.getCharacter('A');
    Character* c2 = factory.getCharacter('B');
    Character* c3 = factory.getCharacter('A');  // Reused object

    // Display characters with different font sizes (Extrinsic state)
    c1->display(12);
    c2->display(14);
    c3->display(18);  // Reuses 'A' from cache

    return 0;
}
