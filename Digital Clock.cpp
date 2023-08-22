#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    while (true) {
        // Get the current time
        time_t now = time(0);
        tm *localTime = localtime(&now);

        // Extract hours, minutes, and seconds
        int hours = localTime->tm_hour;
        int minutes = localTime->tm_min;
        int seconds = localTime->tm_sec;

        // Clear the console (for better display)
        system("clear"); // Use "cls" on Windows

        // Display the digital clock
        cout << "Digital Clock" << endl;
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;

        // Sleep for one second (1000 milliseconds)
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
