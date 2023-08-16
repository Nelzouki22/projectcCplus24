#include <iostream>
#include <string>
#include <vector>

class Medicine {
public:
    Medicine(const std::string &name, int stock, double price)
        : name(name), stock(stock), price(price) {}

    void displayInfo() const {
        std::cout << "Medicine Name: " << name << "\n";
        std::cout << "Stock: " << stock << "\n";
        std::cout << "Price: $" << price << "\n";
    }

    void sell(int quantity) {
        if (quantity <= stock) {
            stock -= quantity;
            std::cout << "Sold " << quantity << " units of " << name << "\n";
        } else {
            std::cout << "Not enough stock for " << name << "\n";
        }
    }

private:
    std::string name;
    int stock;
    double price;
};

class Pharmacy {
public:
    void addMedicine(const Medicine &medicine) {
        medicines.push_back(medicine);
    }

    void displayMedicines() const {
        std::cout << "Medicine Inventory:\n";
        for (const Medicine &medicine : medicines) {
            medicine.displayInfo();
            std::cout << "\n";
        }
    }

    void sellMedicine(int index, int quantity) {
        if (index >= 0 && index < medicines.size()) {
            medicines[index].sell(quantity);
        } else {
            std::cout << "Invalid medicine index.\n";
        }
    }

private:
    std::vector<Medicine> medicines;
};

int main() {
    Pharmacy pharmacy;

    Medicine medicine1("Aspirin", 100, 5.99);
    Medicine medicine2("Antibiotic", 50, 10.99);

    pharmacy.addMedicine(medicine1);
    pharmacy.addMedicine(medicine2);

    pharmacy.displayMedicines();

    pharmacy.sellMedicine(0, 20);
    pharmacy.sellMedicine(1, 10);
    pharmacy.sellMedicine(0, 100);

    pharmacy.displayMedicines();

    return 0;
}
