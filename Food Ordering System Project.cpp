#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;
    double price;

    MenuItem(string n, double p) : name(n), price(p) {}
};

class Order {
public:
    vector<MenuItem> items;

    void addItem(MenuItem item) {
        items.push_back(item);
    }

    double calculateTotal() {
        double total = 0.0;
        for (const MenuItem &item : items) {
            total += item.price;
        }
        return total;
    }
};

class Restaurant {
private:
    vector<MenuItem> menu;

public:
    Restaurant() {
        // Initialize menu items
        menu.push_back(MenuItem("Burger", 5.99));
        menu.push_back(MenuItem("Pizza", 8.99));
        menu.push_back(MenuItem("Pasta", 7.49));
        // Add more items as needed
    }

    void displayMenu() {
        cout << "Menu:" << endl;
        for (const MenuItem &item : menu) {
            cout << item.name << " - $" << item.price << endl;
        }
    }

    Order takeOrder() {
        Order order;
        displayMenu();
        cout << "Enter the items you want to order (separated by spaces): ";
        string input;
        getline(cin, input);

        size_t pos = 0;
        while ((pos = input.find(" ")) != string::npos) {
            string itemName = input.substr(0, pos);
            input.erase(0, pos + 1);
            for (const MenuItem &item : menu) {
                if (item.name == itemName) {
                    order.addItem(item);
                    break;
                }
            }
        }
        // Add the last item
        for (const MenuItem &item : menu) {
            if (item.name == input) {
                order.addItem(item);
                break;
            }
        }
        return order;
    }
};

int main() {
    Restaurant restaurant;
    cout << "Welcome to the Food Ordering System!" << endl;
    
    while (true) {
        Order order = restaurant.takeOrder();
        double total = order.calculateTotal();
        cout << "Your order total is: $" << total << endl;

        cout << "Do you want to place another order? (y/n): ";
        string response;
        getline(cin, response);
        if (response != "y" && response != "Y") {
            cout << "Thank you for using the Food Ordering System. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}
