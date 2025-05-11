/* Concept-Neeed to iterate and sort in alphabatical order
The Iterator pattern provides a way to access elements of a collection sequentially without exposing the underlying representation.
*/
#include <iostream>
#include <vector>

// Forward declaration
class Iterator;

// Collection Class
class Collection {
    std::vector<int> items;

public:
    void addItem(int item) { items.push_back(item); }

    int getItem(int index) const { return items[index]; }

    int size() const { return items.size(); }

    Iterator begin();  // Returns an iterator to the first element
};

// Iterator Class
class Iterator {
    const Collection& collection;
    int index;

public:
    Iterator(const Collection& col, int start = 0) : collection(col), index(start) {}

    bool hasNext() const { return index < collection.size(); }

    int next() { return collection.getItem(index++); }
};

// Implementation of `begin` function in Collection
Iterator Collection::begin() { return Iterator(*this); }

int main() {
    Collection collection;
    collection.addItem(10);
    collection.addItem(20);
    collection.addItem(30);

    Iterator it = collection.begin();
    
    while (it.hasNext()) {
        std::cout << it.next() << " ";
    }

    return 0;
}
