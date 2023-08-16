#include <iostream>
#include <string>
#include <vector>

class Passenger {
public:
    Passenger(const std::string &name, int age, const std::string &trainNumber, int seatNumber)
        : name(name), age(age), trainNumber(trainNumber), seatNumber(seatNumber) {}

    void displayInfo() const {
        std::cout << "Passenger Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Train Number: " << trainNumber << "\n";
        std::cout << "Seat Number: " << seatNumber << "\n";
    }

private:
    std::string name;
    int age;
    std::string trainNumber;
    int seatNumber;
};

class Train {
public:
    Train(const std::string &number, int totalSeats)
        : number(number), totalSeats(totalSeats), availableSeats(totalSeats) {}

    bool reserveSeat(int seatNumber, const std::string &passengerName, int passengerAge) {
        if (availableSeats > 0 && seatNumber >= 1 && seatNumber <= totalSeats) {
            passengers.push_back(Passenger(passengerName, passengerAge, number, seatNumber));
            availableSeats--;
            return true;
        }
        return false;
    }

    void displayAvailableSeats() const {
        std::cout << "Available Seats: " << availableSeats << "\n";
    }

    void displayPassengers() const {
        for (const Passenger &passenger : passengers) {
            passenger.displayInfo();
            std::cout << "\n";
        }
    }

private:
    std::string number;
    int totalSeats;
    int availableSeats;
    std::vector<Passenger> passengers;
};

int main() {
    Train train("12345", 50);

    train.reserveSeat(10, "John Doe", 25);
    train.reserveSeat(25, "Jane Smith", 30);

    std::cout << "Passenger Details:\n";
    train.displayPassengers();

    std::cout << "\nAvailable Seats:\n";
    train.displayAvailableSeats();

    return 0;
}
