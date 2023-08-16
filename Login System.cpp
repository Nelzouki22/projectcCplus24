#include <iostream>
#include <string>
#include <map>

class UserDatabase {
public:
    UserDatabase() {
        users["user1"] = "password1";
        users["user2"] = "password2";
        // Add more users here
    }

    bool authenticate(const std::string &username, const std::string &password) const {
        auto it = users.find(username);
        if (it != users.end() && it->second == password) {
            return true;
        }
        return false;
    }

private:
    std::map<std::string, std::string> users;
};

int main() {
    UserDatabase userDatabase;

    std::string username, password;
    std::cout << "Login System\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (userDatabase.authenticate(username, password)) {
        std::cout << "Login successful. Welcome, " << username << "!\n";
    } else {
        std::cout << "Login failed. Invalid username or password.\n";
    }

    return 0;
}
