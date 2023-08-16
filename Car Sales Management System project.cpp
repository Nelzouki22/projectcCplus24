#include <iostream>
#include <string>
#include <vector>

class Car {
public:
    Car(const std::string &make, const std::string &model, int year, double price)
        : make(make), model(model), year(year), price(price) {}

    void displayInfo() const {
        std::cout << "Make: " << make << "\n";
        std::cout << "Model: " << model << "\n";
        std::cout << "Year: " << year << "\n";
        std::cout << "Price: $" << price << "\n";
    }

private:
    std::string make;
    std::string model;
    int year;
    double price;
};

class Inventory {
public:
    void addCar(const Car &car) {
        cars.push_back(car);
    }

    void displayCars() const {
        std::cout << "Car Inventory:\n";
        for (const Car &car : cars) {
            car.displayInfo();
            std::cout << "\n";
        }
    }

private:
    std::vector<Car> cars;
};

int main() {
    Inventory inventory;

    Car car1("Toyota", "Corolla", 2022, 25000.0);
    Car car2("Honda", "Civic", 2021, 23000.0);

    inventory.addCar(car1);
    inventory.addCar(car2);

    inventory.displayCars();

    return 0;
}
