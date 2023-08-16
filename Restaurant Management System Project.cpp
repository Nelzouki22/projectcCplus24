#include <iostream>
#include <string>
#include <vector>

class MenuItem {
public:
    MenuItem(const std::string &name, double price)
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

class Order {
public:
    void addItem(const MenuItem &item) {
        items.push_back(item);
    }

    double getTotal() const {
        double total = 0.0;
        for (const MenuItem &item : items) {
            total += item.getPrice();
        }
        return total;
    }

    void displayOrder() const {
        std::cout << "Order Details:\n";
        for (const MenuItem &item : items) {
            std::cout << "Item: " << item.getName() << "\tPrice: $" << item.getPrice() << "\n";
        }
        std::cout << "Total: $" << getTotal() << "\n";
    }

private:
    std::vector<MenuItem> items;
};

class Restaurant {
public:
    Restaurant(const std::string &name) : name(name) {}

    void displayMenu() const {
        std::cout << "Menu:\n";
        for (const MenuItem &item : menu) {
            std::cout << "Item: " << item.getName() << "\tPrice: $" << item.getPrice() << "\n";
        }
    }

    void placeOrder(Order &order) {
        orders.push_back(order);
    }

    void displayOrders() const {
        std::cout << "Orders:\n";
        for (const Order &order : orders) {
            order.displayOrder();
            std::cout << "\n";
        }
    }

private:
    std::string name;
    std::vector<MenuItem> menu;
    std::vector<Order> orders;
};

int main() {
    Restaurant restaurant("Sample Restaurant");

    restaurant.displayMenu();

    Order order1;
    order1.addItem(MenuItem("Burger", 8.99));
    order1.addItem(MenuItem("Fries", 2.49));
    restaurant.placeOrder(order1);

    Order order2;
    order2.addItem(MenuItem("Pizza", 12.99));
    order2.addItem(MenuItem("Salad", 6.49));
    restaurant.placeOrder(order2);

    restaurant.displayOrders();

    return 0;
}
