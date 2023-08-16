#include <iostream>
#include <vector>
#include <string>

class Room {
public:
    Room(int number, int capacity) : number(number), capacity(capacity), booked(false) {}
    
    int getNumber() const {
        return number;
    }
    
    int getCapacity() const {
        return capacity;
    }
    
    bool isBooked() const {
        return booked;
    }
    
    void book() {
        booked = true;
    }
    
    void unbook() {
        booked = false;
    }
    
private:
    int number;
    int capacity;
    bool booked;
};

class Reservation {
public:
    Reservation(const std::string& guestName, const Room& room)
        : guestName(guestName), room(room) {}
    
    void display() const {
        std::cout << "Reservation Details:" << std::endl;
        std::cout << "Guest Name: " << guestName << std::endl;
        std::cout << "Room Number: " << room.getNumber() << std::endl;
        std::cout << "Room Capacity: " << room.getCapacity() << std::endl;
    }
    
private:
    std::string guestName;
    const Room& room;
};

class HostelBookingSystem {
public:
    void addRoom(const Room& room) {
        rooms.push_back(room);
    }
    
    void displayAvailableRooms() const {
        std::cout << "Available Rooms:" << std::endl;
        for (const Room& room : rooms) {
            if (!room.isBooked()) {
                std::cout << "Room Number: " << room.getNumber() << " (Capacity: " << room.getCapacity() << ")" << std::endl;
            }
        }
    }
    
    bool bookRoom(int roomNumber, const std::string& guestName) {
        for (Room& room : rooms) {
            if (room.getNumber() == roomNumber && !room.isBooked()) {
                room.book();
                Reservation reservation(guestName, room);
                reservations.push_back(reservation);
                std::cout << "Room successfully booked." << std::endl;
                return true;
            }
        }
        std::cout << "Room not available for booking." << std::endl;
        return false;
    }
    
    void displayReservations() const {
        std::cout << "All Reservations:" << std::endl;
        for (const Reservation& reservation : reservations) {
            reservation.display();
            std::cout << std::endl;
        }
    }
    
private:
    std::vector<Room> rooms;
    std::vector<Reservation> reservations;
};

int main() {
    HostelBookingSystem system;
    
    Room singleRoom1(101, 1);
    Room singleRoom2(102, 1);
    Room doubleRoom1(201, 2);
    Room doubleRoom2(202, 2);
    
    system.addRoom(singleRoom1);
    system.addRoom(singleRoom2);
    system.addRoom(doubleRoom1);
    system.addRoom(doubleRoom2);
    
    int choice;
    do {
        std::cout << "1. Display available rooms" << std::endl;
        std::cout << "2. Book a room" << std::endl;
        std::cout << "3. Display all reservations" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                system.displayAvailableRooms();
                break;
            case 2: {
                std::string guestName;
                int roomNumber;
                system.displayAvailableRooms();
                std::cout << "Enter your name: ";
                std::cin >> guestName;
                std::cout << "Enter the room number: ";
                std::cin >> roomNumber;
                system.bookRoom(roomNumber, guestName);
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
