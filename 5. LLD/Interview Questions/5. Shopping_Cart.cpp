/*+------------------+
|     Product      |
+------------------+
| - id: int       |
| - name: string  |
| - price: double |
| - stock: int    |
+------------------+
| + Product(id, name, price, stock) |
+------------------+

           ▲
           │
           │
+------------------+   +----------------+
|    CartItem      |   |      User       |
+------------------+   +----------------+
| - product: Product* | - id: int       |
| - quantity: int  |   | - name: string |
+------------------+   | - cart: Cart   |
                       +----------------+
                               │
                               ▼
+------------------+
|      Cart        |
+------------------+
| - cartItems: unordered_map<int, CartItem> |
+------------------+
| + addItem(Product*, int) |
| + removeItem(int)        |
| + updateQuantity(int, int) |
| + viewCart()             |
| + calculateTotal()       |
| + clearCart()            |
+------------------+

                               ▲
                               │
                               │
+------------------+           │
|      Order       | <---------┘
+------------------+
| - orderId: int  |
| - totalAmount: double |
+------------------+
| + Order(double) |
| + displayOrder() |
+------------------+
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Product class
class Product {
public:
    int id;
    string name;
    double price;
    int stock;

    Product(int id, string name, double price, int stock)
        : id(id), name(name), price(price), stock(stock) {}
};

// Cart Item class
class CartItem {
public:
    Product* product;
    int quantity;

    CartItem(Product* product, int quantity) : product(product), quantity(quantity) {}
};

// Shopping Cart class
class Cart {
private:
    unordered_map<int, CartItem> cartItems; // Key: Product ID, Value: CartItem

public:
    void addItem(Product* product, int quantity) {
        if (product->stock < quantity) {
            cout << "Insufficient stock for " << product->name << endl;
            return;
        }
        if (cartItems.find(product->id) != cartItems.end()) {
            cartItems[product->id].quantity += quantity;
        } else {
            cartItems[product->id] = CartItem(product, quantity);
        }
        product->stock -= quantity; // Reduce stock
        cout << quantity << " " << product->name << "(s) added to cart.\n";
    }

    void removeItem(int productId) {
        if (cartItems.find(productId) != cartItems.end()) {
            cartItems.erase(productId);
            cout << "Item removed from cart.\n";
        } else {
            cout << "Item not found in cart.\n";
        }
    }

    void updateQuantity(int productId, int quantity) {
        if (cartItems.find(productId) != cartItems.end()) {
            cartItems[productId].quantity = quantity;
            cout << "Quantity updated.\n";
        } else {
            cout << "Item not found in cart.\n";
        }
    }

    void viewCart() {
        if (cartItems.empty()) {
            cout << "Cart is empty.\n";
            return;
        }
        cout << "Cart Items:\n";
        for (auto& item : cartItems) {
            cout << item.second.product->name << " - Quantity: " << item.second.quantity 
                 << " - Price: $" << item.second.product->price * item.second.quantity << "\n";
        }
    }

    double calculateTotal() {
        double total = 0;
        for (auto& item : cartItems) {
            total += item.second.product->price * item.second.quantity;
        }
        return total;
    }

    void clearCart() {
        cartItems.clear();
    }
};

// Order class
class Order {
public:
    static int orderCount;
    int orderId;
    double totalAmount;

    Order(double totalAmount) : totalAmount(totalAmount) {
        orderId = ++orderCount;
    }

    void displayOrder() {
        cout << "Order ID: " << orderId << " | Total Amount: $" << totalAmount << endl;
    }
};
int Order::orderCount = 0;

// User class
class User {
public:
    int id;
    string name;
    Cart cart;

    User(int id, string name) : id(id), name(name) {}

    void checkout() {
        if (cart.calculateTotal() == 0) {
            cout << "Cart is empty. Cannot proceed to checkout.\n";
            return;
        }

        cout << "Processing payment...\n";
        double total = cart.calculateTotal();
        cout << "Payment successful! Order confirmed.\n";
        Order order(total);
        order.displayOrder();

        cart.clearCart(); // Empty cart after checkout
    }
};

int main() {
    // Create products
    Product p1(1, "Laptop", 1000, 10);
    Product p2(2, "Phone", 500, 20);
    Product p3(3, "Headphones", 100, 15);

    // Create user
    User user(101, "John Doe");

    // User actions
    user.cart.addItem(&p1, 1);
    user.cart.addItem(&p2, 2);
    user.cart.viewCart();

    user.cart.updateQuantity(1, 2);
    user.cart.viewCart();

    user.checkout(); // Checkout process

    return 0;
}
