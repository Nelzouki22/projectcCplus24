#include <iostream>
#include <string>
#include <vector>

class Car {
public:
    Car(const std::string &licensePlate, const std::string &ownerName)
        : licensePlate(licensePlate), ownerName(ownerName) {}

    const std::string &getLicensePlate() const {
        return licensePlate;
    }

    const std::string &getOwnerName() const {
        return ownerName;
    }

private:
    std::string licensePlate;
    std::string ownerName;
};

class ParkingSpace {
public:
    ParkingSpace(int spaceNumber) : spaceNumber(spaceNumber), occupied(false) {}

    void occupy(const Car &car) {
        if (!occupied) {
            parkedCar = car;
            occupied = true;
            std::cout << "Car with license plate " << car.getLicensePlate() << " parked in space " << spaceNumber << "\n";
        } else {
            std::cout << "Parking space " << spaceNumber << " is already occupied.\n";
        }
    }

    void vacate() {
        if (occupied) {
            std::cout << "Car with license plate " << parkedCar.getLicensePlate() << " has left space " << spaceNumber << "\n";
            occupied = false;
        } else {
            std::cout << "Parking space " << spaceNumber << " is already vacant.\n";
        }
    }

    bool isOccupied() const {
        return occupied;
    }

private:
    int spaceNumber;
    bool occupied;
    Car parkedCar;
};

class ParkingLot {
public:
    ParkingLot(int capacity) : capacity(capacity) {
        for (int i = 0; i < capacity; ++i) {
            parkingSpaces.push_back(ParkingSpace(i + 1));
        }
    }

    void parkCar(const Car &car) {
        for (ParkingSpace &space : parkingSpaces) {
            if (!space.isOccupied()) {
                space.occupy(car);
                return;
            }
        }
        std::cout << "No available parking space.\n";
    }

    void removeCar(const std::string &licensePlate) {
        for (ParkingSpace &space : parkingSpaces) {
            if (space.isOccupied() && space.parkedCar.getLicensePlate() == licensePlate) {
                space.vacate();
                return;
            }
        }
        std::cout << "Car with license plate " << licensePlate << " not found in the parking lot.\n";
    }

    void displayParkingStatus() const {
        std::cout << "Parking Lot Status:\n";
        for (const ParkingSpace &space : parkingSpaces) {
            std::cout << "Space " << spaceNumber << ": " << (space.isOccupied() ? "Occupied" : "Vacant") << "\n";
        }
    }

private:
    int capacity;
    std::vector<ParkingSpace> parkingSpaces;
};

int main() {
    ParkingLot parkingLot(10);

    Car car1("ABC123", "John Doe");
    Car car2("XYZ789", "Jane Smith");

    parkingLot.parkCar(car1);
    parkingLot.parkCar(car2);

    parkingLot.displayParkingStatus();

    parkingLot.removeCar("ABC123");

    parkingLot.displayParkingStatus();

    return 0;
}
