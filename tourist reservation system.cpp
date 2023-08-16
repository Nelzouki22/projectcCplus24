#include <iostream>
#include <vector>
#include <string>

class Hotel {
public:
    Hotel(const std::string& name, int capacity) : name(name), capacity(capacity) {}
    
    const std::string& getName() const {
        return name;
    }
    
    int getCapacity() const {
        return capacity;
    }
    
private:
    std::string name;
    int capacity;
};

class Reservation {
public:
    Reservation(const std::string& guestName, const Hotel& hotel, int numGuests)
        : guestName(guestName), hotel(hotel), numGuests(numGuests) {}
    
    void display() const {
        std::cout << "Reservation Details:" << std::endl;
        std::cout << "Guest Name: " << guestName << std::endl;
        std::cout << "Hotel: " << hotel.getName() << std::endl;
        std::cout << "Number of Guests: " << numGuests << std::endl;
    }
    
private:
    std::string guestName;
    const Hotel& hotel;
    int numGuests;
};

class ReservationSystem {
public:
    void addHotel(const Hotel& hotel) {
        hotels.push_back(hotel);
    }
    
    void displayHotels() const {
        std::cout << "Available Hotels:" << std::endl;
        for (const Hotel& hotel : hotels) {
            std::cout << hotel.getName() << " (Capacity: " << hotel.getCapacity() << ")" << std::endl;
        }
    }
    
    void makeReservation(const std::string& guestName, const Hotel& selectedHotel, int numGuests) {
        if (numGuests > selectedHotel.getCapacity()) {
            std::cout << "Not enough capacity in the selected hotel." << std::endl;
            return;
        }
        
        Reservation reservation(guestName, selectedHotel, numGuests);
        reservations.push_back(reservation);
        std::cout << "Reservation successfully made." << std::endl;
    }
    
    void displayReservations() const {
        std::cout << "All Reservations:" << std::endl;
        for (const Reservation& reservation : reservations) {
            reservation.display();
            std::cout << std::endl;
        }
    }
    
private:
    std::vector<Hotel> hotels;
    std::vector<Reservation> reservations;
};

int main() {
    ReservationSystem system;
    
    Hotel hilton("Hilton", 100);
    Hotel marriott("Marriott", 150);
    
    system.addHotel(hilton);
    system.addHotel(marriott);
    
    int choice;
    do {
        std::cout << "1. Display available hotels" << std::endl;
        std::cout << "2. Make a reservation" << std::endl;
        std::cout << "3. Display all reservations" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                system.displayHotels();
                break;
            case 2: {
                std::string guestName;
                int hotelChoice, numGuests;
                system.displayHotels();
                std::cout << "Enter your name: ";
                std::cin >> guestName;
                std::cout << "Enter the hotel number: ";
                std::cin >> hotelChoice;
                std::cout << "Enter the number of guests: ";
                std::cin >> numGuests;
                
                if (hotelChoice >= 1 && hotelChoice <= system.getNumHotels()) {
                    const Hotel& selectedHotel = system.getHotel(hotelChoice - 1);
                    system.makeReservation(guestName, selectedHotel, numGuests);
                } else {
                    std::cout << "Invalid hotel choice." << std::endl;
                }
                break;
            }
            case 3:
                system.displayReservations();
                break;
            case 4:
                std::cout << "Exiting." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    } while (choice != 4);
    
    return 0;
}
