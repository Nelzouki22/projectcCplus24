#include <iostream>
#include <string>
#include <vector>

class Item {
public:
    Item(const std::string &name, double price)
        : name(name), price(price) {}

    const std::string &getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

private:
    std::string name;
    double price;
};

class ShoppingCart {
public:
    void addItem(const Item &item) {
        items.push_back(item);
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const Item &item : items) {
            total += item.getPrice();
        }
        return total;
    }

private:
    std::vector<Item> items;
};

int main() {
    std::vector<Item> supermarketItems = {
        Item("Bread", 1.99),
        Item("Milk", 2.49),
        Item("Eggs", 3.99),
        // Add more items here
    };

    ShoppingCart cart;

    std::cout << "Supermarket Billing System\n";
    std::cout << "Available Items:\n";
    for (size_t i = 0; i < supermarketItems.size(); ++i) {
        std::cout << i + 1 << ". " << supermarketItems[i].getName() << " ($" << supermarketItems[i].getPrice() << ")\n";
    }

    int choice;
    do {
        std::cout << "Enter item number to add to cart (0 to checkout): ";
        std::cin >> choice;
        if (choice >= 1 && choice <= static_cast<int>(supermarketItems.size())) {
            cart.addItem(supermarketItems[choice - 1]);
        } else if (choice != 0) {
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    double total = cart.calculateTotal();
    std::cout << "Total: $" << total << "\n";

    std::cout << "Thank you for shopping with us!\n";

    return 0;
}
