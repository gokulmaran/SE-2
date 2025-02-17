/*Core Operations:
Flight Scheduling: Flights are scheduled with specific timings, routes, and seat availability.
Booking: Passengers book a seat on a flight by selecting a flight and providing personal details.
Cancellations: Passengers can cancel bookings, which will release seats back to the flight.
Seat Assignment: Seats are assigned to passengers when booking is confirmed.
=======================================================================*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

// Seat Class: Represents a seat on the flight
class Seat {
private:
    int seatNumber;
    bool isBooked;

public:
    Seat(int number) : seatNumber(number), isBooked(false) {}

    int getSeatNumber() const {
        return seatNumber;
    }

    bool isAvailable() const {
        return !isBooked;
    }

    void bookSeat() {
        isBooked = true;
    }

    void releaseSeat() {
        isBooked = false;
    }
};

// Flight Class: Represents a flight with scheduling and seat assignments
class Flight {
private:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::vector<Seat*> seats;

public:
    Flight(std::string flightNumber, std::string origin, std::string destination, int totalSeats)
        : flightNumber(flightNumber), origin(origin), destination(destination) {
        for (int i = 1; i <= totalSeats; ++i) {
            seats.push_back(new Seat(i));
        }
    }

    ~Flight() {
        for (auto seat : seats) {
            delete seat;
        }
    }

    std::string getFlightNumber() const {
        return flightNumber;
    }

    std::string getOrigin() const {
        return origin;
    }

    std::string getDestination() const {
        return destination;
    }

    bool bookSeat(int seatNumber) {
        for (auto seat : seats) {
            if (seat->getSeatNumber() == seatNumber && seat->isAvailable()) {
                seat->bookSeat();
                return true;
            }
        }
        return false;
    }

    bool releaseSeat(int seatNumber) {
        for (auto seat : seats) {
            if (seat->getSeatNumber() == seatNumber && !seat->isAvailable()) {
                seat->releaseSeat();
                return true;
            }
        }
        return false;
    }

    void displaySeats() const {
        std::cout << "Seats on Flight " << flightNumber << ":\n";
        for (const auto seat : seats) {
            std::cout << "Seat " << seat->getSeatNumber() << ": " << (seat->isAvailable() ? "Available" : "Booked") << "\n";
        }
    }
};

// Passenger Class: Represents a passenger who books a seat
class Passenger {
private:
    std::string name;
    int age;

public:
    Passenger(std::string name, int age) : name(name), age(age) {}

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

// Booking Class: Represents a booking made by a passenger
class Booking {
private:
    Flight* flight;
    Passenger* passenger;
    int seatNumber;

public:
    Booking(Flight* flight, Passenger* passenger, int seatNumber)
        : flight(flight), passenger(passenger), seatNumber(seatNumber) {}

    void printBookingDetails() const {
        std::cout << "Booking Details:\n";
        std::cout << "Passenger: " << passenger->getName() << ", Age: " << passenger->getAge() << "\n";
        std::cout << "Flight: " << flight->getFlightNumber() << ", Origin: " << flight->getOrigin()
                  << ", Destination: " << flight->getDestination() << "\n";
        std::cout << "Seat Number: " << seatNumber << "\n";
    }

    void cancelBooking() {
        flight->releaseSeat(seatNumber);
        std::cout << "Booking cancelled for " << passenger->getName() << " on Flight " << flight->getFlightNumber() << "\n";
    }
};

// Reservation System Class: Manages flight schedules and bookings
class ReservationSystem {
private:
    std::unordered_map<std::string, Flight*> flights;
    std::vector<Booking*> bookings;

public:
    ~ReservationSystem() {
        for (auto flight : flights) {
            delete flight.second;
        }
        for (auto booking : bookings) {
            delete booking;
        }
    }

    void addFlight(Flight* flight) {
        flights[flight->getFlightNumber()] = flight;
    }

    Booking* bookSeat(Passenger* passenger, const std::string& flightNumber, int seatNumber) {
        auto it = flights.find(flightNumber);
        if (it == flights.end()) {
            std::cout << "Flight " << flightNumber << " does not exist.\n";
            return nullptr;
        }

        Flight* flight = it->second;
        if (flight->bookSeat(seatNumber)) {
            Booking* booking = new Booking(flight, passenger, seatNumber);
            bookings.push_back(booking);
            booking->printBookingDetails();
            return booking;
        } else {
            std::cout << "Seat " << seatNumber << " on flight " << flightNumber << " is already booked.\n";
            return nullptr;
        }
    }

    void cancelBooking(Booking* booking) {
        if (booking == nullptr) return;
        booking->cancelBooking();
        auto it = std::find(bookings.begin(), bookings.end(), booking);
        if (it != bookings.end()) {
            delete *it;
            bookings.erase(it);
        }
    }

    void showFlightDetails(const std::string& flightNumber) {
        auto it = flights.find(flightNumber);
        if (it == flights.end()) {
            std::cout << "Flight " << flightNumber << " does not exist.\n";
            return;
        }

        Flight* flight = it->second;
        flight->displaySeats();
    }
};

// Main Program
int main() {
    // Create some flights
    Flight* flight1 = new Flight("FL123", "New York", "London", 5);
    Flight* flight2 = new Flight("FL456", "Paris", "Rome", 5);

    // Create reservation system and add flights
    ReservationSystem reservationSystem;
    reservationSystem.addFlight(flight1);
    reservationSystem.addFlight(flight2);

    // Create passengers
    Passenger* passenger1 = new Passenger("John Doe", 30);
    Passenger* passenger2 = new Passenger("Jane Smith", 28);

    // Passengers book seats and collect booking pointers
    Booking* booking1 = reservationSystem.bookSeat(passenger1, "FL123", 1);
    Booking* booking2 = reservationSystem.bookSeat(passenger2, "FL123", 2);

    // Show flight details (seats availability)
    reservationSystem.showFlightDetails("FL123");

    // Cancel booking for passenger1 if booking exists
    if (booking1 != nullptr) {
        reservationSystem.cancelBooking(booking1);
    }

    // Show flight details again after cancellation
    reservationSystem.showFlightDetails("FL123");

    // Clean up dynamically allocated passengers
    delete passenger1;
    delete passenger2;

    return 0;
}
