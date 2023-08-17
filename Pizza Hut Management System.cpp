#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pizza {
public:
    string name;
    double price;

    Pizza(string n, double p) : name(n), price(p) {}
};

class Order {
public:
    int orderId;
    vector<Pizza> pizzas;
    double totalAmount;

    Order(int id) : orderId(id), totalAmount(0) {}

    void addPizza(Pizza pizza) {
        pizzas.push_back(pizza);
        totalAmount += pizza.price;
    }

    void displayOrder() {
        cout << "Order ID: " << orderId << endl;
        cout << "Pizzas:" << endl;
        for (const Pizza &pizza : pizzas) {
            cout << pizza.name << " - $" << pizza.price << endl;
        }
        cout << "Total Amount: $" << totalAmount << endl;
    }
};

class PizzaHut {
private:
    vector<Pizza> menu;
    vector<Order> orders;
    int orderCounter;

public:
    PizzaHut() : orderCounter(1) {
        // Initialize the menu with some pizzas
        menu.push_back(Pizza("Margherita", 10.99));
        menu.push_back(Pizza("Pepperoni", 12.99));
        menu.push_back(Pizza("Vegetarian", 11.99));
    }

    void displayMenu() {
        cout << "Menu:" << endl;
        for (const Pizza &pizza : menu) {
            cout << pizza.name << " - $" << pizza.price << endl;
        }
    }

    void placeOrder() {
        Order order(orderCounter++);
        int pizzaChoice;

        do {
            displayMenu();
            cout << "Enter the number of the pizza you want to add (0 to finish): ";
            cin >> pizzaChoice;

            if (pizzaChoice > 0 && pizzaChoice <= menu.size()) {
                order.addPizza(menu[pizzaChoice - 1]);
            } else if (pizzaChoice != 0) {
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (pizzaChoice != 0);

        orders.push_back(order);
        cout << "Order placed successfully!" << endl;
    }

    void displayOrders() {
        cout << "Orders:" << endl;
        for (const Order &order : orders) {
            order.displayOrder();
            cout << "------------------------" << endl;
        }
    }
};

int main() {
    PizzaHut pizzaHut;

    int choice;
    do {
        cout << "Pizza Hut Management System" << endl;
        cout << "1. Place an Order" << endl;
        cout << "2. Display Orders" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pizzaHut.placeOrder();
                break;
            case 2:
                pizzaHut.displayOrders();
                break;
            case 0:
                cout << "Exiting. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
