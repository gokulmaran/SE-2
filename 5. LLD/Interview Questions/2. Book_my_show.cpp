/*Class Diagram (Simplified)
+---------------------+
|      Movie          |
+---------------------+
| - name: string      |
| - duration: int     |
| - genre: string     |
+---------------------+
| + getDetails(): void|
+---------------------+

+----------------------+
|      Theater         |
+----------------------+
| - name: string       |
| - location: string   |
| - screenCount: int   |
+----------------------+
| + showMovies(): void |
+----------------------+

+----------------------+
|      Ticket          |
+----------------------+
| - movie: Movie*      |
| - user: User*        |
| - seatNumber: string |
+----------------------+
| + printTicket(): void|
+----------------------+

+----------------------+
|      Booking         |
+----------------------+
| - user: User*        |
| - movie: Movie*      |
| - theater: Theater*  |
| - ticket: Ticket*    |
+----------------------+
| + createBooking(): void |
+----------------------+

+---------------------+
|        User         |
+---------------------+
| - name: string      |
| - email: string     |
+---------------------+
| + bookTicket(): void|
=========================================*/
#include <iostream>
#include <string>
#include <vector>

// Movie Class
class Movie {
private:
    std::string name;
    int duration;  // in minutes
    std::string genre;

public:
    Movie(const std::string& name, int duration, const std::string& genre)
        : name(name), duration(duration), genre(genre) {}

    void getDetails() const {
        std::cout << "Movie Name: " << name << "\n";
        std::cout << "Duration: " << duration << " mins\n";
        std::cout << "Genre: " << genre << "\n";
    }

    std::string getName() const {
        return name;
    }
};

// Theater Class
class Theater {
private:
    std::string name;
    std::string location;
    int screenCount;
    std::vector<Movie> movies;

public:
    Theater(const std::string& name, const std::string& location, int screenCount)
        : name(name), location(location), screenCount(screenCount) {}

    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    void showMovies() const {
        std::cout << "Movies available at " << name << " theater:\n";
        for (const auto& movie : movies) {
            movie.getDetails();
            std::cout << "--------------------\n";
        }
    }

    const std::vector<Movie>& getMovies() const {
        return movies;
    }
};

// User Class
class User {
private:
    std::string name;
    std::string email;

public:
    User(const std::string& name, const std::string& email)
        : name(name), email(email) {}

    std::string getName() const {
        return name;
    }

    void bookTicket(const Movie& movie, Theater& theater);
};

// Ticket Class
class Ticket {
private:
    const Movie* movie;
    const User* user;
    std::string seatNumber;

public:
    Ticket(const Movie* movie, const User* user, const std::string& seatNumber)
        : movie(movie), user(user), seatNumber(seatNumber) {}

    void printTicket() const {
        std::cout << "Ticket Booked!\n";
        std::cout << "Movie: " << movie->getName() << "\n";
        std::cout << "User: " << user->getName() << "\n";
        std::cout << "Seat Number: " << seatNumber << "\n";
    }
};

// Booking Class
class Booking {
private:
    const User* user;
    const Movie* movie;
    const Theater* theater;
    Ticket* ticket;

public:
    Booking(const User* user, const Movie* movie, const Theater* theater, const std::string& seatNumber)
        : user(user), movie(movie), theater(theater), ticket(new Ticket(movie, user, seatNumber)) {}

    void createBooking() {
        std::cout << "Booking ticket...\n";
        ticket->printTicket();
    }

    ~Booking() {
        delete ticket;
    }
};

void User::bookTicket(const Movie& movie, Theater& theater) {
    std::string seatNumber;
    std::cout << "Enter seat number for the movie " << movie.getName() << ": ";
    std::cin >> seatNumber;

    // Check if the seat number is valid (simple validation)
    if (seatNumber.empty()) {
        std::cerr << "Seat number cannot be empty!\n";
        return;
    }

    // Passing the User pointer correctly with this
    Booking booking(this, &movie, &theater, seatNumber);
    booking.createBooking();
}

int main() {
    // Create movies
    Movie movie1("Avengers: Endgame", 180, "Action");
    Movie movie2("The Lion King", 120, "Animation");

    // Create theater
    Theater theater("PVR Cinemas", "Mumbai", 5);
    theater.addMovie(movie1);
    theater.addMovie(movie2);

    // Show available movies
    theater.showMovies();

    // Create user
    User user("John Doe", "john.doe@example.com");

    // User books a ticket
    user.bookTicket(movie1, theater);

    return 0;
}

