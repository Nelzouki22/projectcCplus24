#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CovidData {
public:
    string country;
    int totalCases;
    int totalDeaths;
    int totalRecovered;

    CovidData(string c, int cases, int deaths, int recovered)
        : country(c), totalCases(cases), totalDeaths(deaths), totalRecovered(recovered) {}
};

class CovidDatabase {
private:
    vector<CovidData> data;

public:
    void addData(CovidData newData) {
        data.push_back(newData);
    }

    void displayData() {
        cout << "Covid-19 Data:" << endl;
        for (const CovidData &entry : data) {
            cout << "Country: " << entry.country << endl;
            cout << "Total Cases: " << entry.totalCases << endl;
            cout << "Total Deaths: " << entry.totalDeaths << endl;
            cout << "Total Recovered: " << entry.totalRecovered << endl;
            cout << "-------------------------------" << endl;
        }
    }
};

int main() {
    CovidDatabase covidDB;

    covidDB.addData(CovidData("USA", 5000000, 100000, 4500000));
    covidDB.addData(CovidData("India", 3000000, 60000, 2800000));
    covidDB.addData(CovidData("Brazil", 2000000, 80000, 1800000));

    cout << "Welcome to the Covid-19 Management System!" << endl;

    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. Display Covid-19 Data" << endl;
        cout << "2. Exit" << endl;
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                covidDB.displayData();
                break;
            case 2:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select again." << endl;
        }
    }

    return 0;
}
