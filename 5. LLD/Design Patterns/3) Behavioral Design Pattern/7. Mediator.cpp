/*Mediator-- 
The Mediator Pattern is a behavioral design pattern that promotes loose coupling by centralizing communication between objects. 
Instead of objects communicating directly, they interact through a mediator.
*/
#include <iostream>
#include <vector>
#include <string>

// Forward declaration
class User;

// Mediator Interface
class ChatMediator {
public:
    virtual void sendMessage(const std::string& message, User* sender) = 0;
    virtual void addUser(User* user) = 0;
    virtual ~ChatMediator() = default;
};

// Colleague Class (User)
class User {
protected:
    std::string name;
    ChatMediator* mediator;
public:
    User(const std::string& name, ChatMediator* mediator) : name(name), mediator(mediator) {}

    virtual void send(const std::string& message) {
        std::cout << name << " sends: " << message << "\n";
        mediator->sendMessage(message, this);
    }

    virtual void receive(const std::string& message, const std::string& sender) {
        std::cout << name << " received from " << sender << ": " << message << "\n";
    }

    std::string getName() const { return name; }
};

// Concrete Mediator (ChatRoom)
class ChatRoom : public ChatMediator {
private:
    std::vector<User*> users;
public:
    void addUser(User* user) override {
        users.push_back(user);
    }

    void sendMessage(const std::string& message, User* sender) override {
        for (User* user : users) {
            if (user != sender) { // Avoid sending message to sender
                user->receive(message, sender->getName());
            }
        }
    }
};

// Main Function
int main() {
    ChatRoom chatRoom;

    User user1("Alice", &chatRoom);
    User user2("Bob", &chatRoom);
    User user3("Charlie", &chatRoom);

    chatRoom.addUser(&user1);
    chatRoom.addUser(&user2);
    chatRoom.addUser(&user3);

    user1.send("Hello, everyone!");
    user2.send("Hi, Alice!");
    user3.send("Hey folks!");

    return 0;
}
