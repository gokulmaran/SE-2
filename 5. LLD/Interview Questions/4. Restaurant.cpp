/*Core Classes:
Restaurant: Represents a restaurant and manages food items.
Order: Represents an order that the user places.
User: Represents a user who can order food and rate orders.
RatingSystem: The subject class that updates restaurants whenever a new rating is added.
RestaurantObserver: Observer classes that update the list of restaurants.
RestaurantRatingDisplay: Displays the list of restaurants based on ratings.
============================================================================*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Forward declaration for Restaurant and RatingSystem
class Restaurant;
class RatingSystem;

// Observer class that listens for changes in ratings
class RestaurantObserver {
public:
    virtual void update() = 0;
};

// Restaurant class that holds information about a restaurant
class Restaurant {
private:
    std::string name;
    std::vector<std::pair<std::string, float>> menu;  // Menu with food items and their prices
    float averageRating;
    int totalRatings;
    int ratingCount;

public:
    Restaurant(std::string name) : name(name), averageRating(0), totalRatings(0), ratingCount(0) {}

    void addFoodItem(const std::string& foodName, float price) {
        menu.push_back({foodName, price});
    }

    void rate(float rating) {
        totalRatings += rating;
        ratingCount++;
        averageRating = totalRatings / ratingCount;
    }

    float getAverageRating() const {
        return averageRating;
    }

    const std::string& getName() const {
        return name;
    }

    void showMenu() const {
        std::cout << "Menu for " << name << ":\n";
        for (const auto& item : menu) {
            std::cout << item.first << " - $" << item.second << "\n";
        }
    }
};

// RatingSystem class that handles rating and notifies observers
class RatingSystem {
private:
    std::vector<Restaurant*> restaurants;
    std::vector<RestaurantObserver*> observers;

public:
    void addRestaurant(Restaurant* restaurant) {
        restaurants.push_back(restaurant);
    }

    void addObserver(RestaurantObserver* observer) {
        observers.push_back(observer);
    }

    void rateRestaurant(Restaurant* restaurant, float rating) {
        restaurant->rate(rating);
        notifyObservers();
    }

    void displayTopRestaurants() {
        std::sort(restaurants.begin(), restaurants.end(), [](Restaurant* a, Restaurant* b) {
            return a->getAverageRating() > b->getAverageRating();
        });

        std::cout << "Top Restaurants by Average Rating:\n";
        for (auto& restaurant : restaurants) {
            std::cout << restaurant->getName() << " - Rating: " << restaurant->getAverageRating() << "\n";
        }
    }

    void notifyObservers() {
        for (auto& observer : observers) {
            observer->update();
        }
    }
};

// RestaurantRatingDisplay class that observes RatingSystem and displays restaurant lists
class RestaurantRatingDisplay : public RestaurantObserver {
private:
    RatingSystem* ratingSystem;

public:
    RestaurantRatingDisplay(RatingSystem* ratingSystem) : ratingSystem(ratingSystem) {
        ratingSystem->addObserver(this);
    }

    void update() override {
        ratingSystem->displayTopRestaurants();
    }
};

// User class that can place orders and rate restaurants
class User {
private:
    std::string name;

public:
    User(const std::string& name) : name(name) {}

    void placeOrder(Restaurant& restaurant, const std::string& foodItem) {
        std::cout << name << " ordered " << foodItem << " from " << restaurant.getName() << "\n";
        restaurant.showMenu();
    }

    void rateOrder(RatingSystem& ratingSystem, Restaurant& restaurant, float rating) {
        ratingSystem.rateRestaurant(&restaurant, rating);
        std::cout << name << " rated " << restaurant.getName() << " with " << rating << " stars.\n";
    }
};

// Main function to simulate the system
int main() {
    // Create rating system
    RatingSystem ratingSystem;

    // Create restaurants
    Restaurant restaurant1("Pasta Place");
    restaurant1.addFoodItem("Pasta", 10.99);
    restaurant1.addFoodItem("Pizza", 12.99);

    Restaurant restaurant2("Burger King");
    restaurant2.addFoodItem("Cheese Burger", 8.99);
    restaurant2.addFoodItem("Veg Burger", 6.99);

    // Add restaurants to the rating system
    ratingSystem.addRestaurant(&restaurant1);
    ratingSystem.addRestaurant(&restaurant2);

    // Create a restaurant rating display (observer)
    RestaurantRatingDisplay ratingDisplay(&ratingSystem);

    // Create users
    User user1("Alice");
    User user2("Bob");

    // Users place orders and rate restaurants
    user1.placeOrder(restaurant1, "Pasta");
    user1.rateOrder(ratingSystem, restaurant1, 4.5);  // Alice rates Pasta Place

    user2.placeOrder(restaurant2, "Cheese Burger");
    user2.rateOrder(ratingSystem, restaurant2, 3.0);  // Bob rates Burger King

    // Display top restaurants after rating
    ratingSystem.displayTopRestaurants();

    return 0;
}
