#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Patient {
public:
    string name;
    int age;
    string gender;
    string contact;

    Patient(string _name, int _age, string _gender, string _contact) {
        name = _name;
        age = _age;
        gender = _gender;
        contact = _contact;
    }
};

class Appointment {
public:
    time_t time;
    Patient* patient;

    Appointment(time_t _time, Patient* _patient) {
        time = _time;
        patient = _patient;
    }
};

class Clinic {
private:
    vector<Patient*> patients;
    vector<Appointment*> appointments;

public:
    void addPatient(string name, int age, string gender, string contact) {
        Patient* patient = new Patient(name, age, gender, contact);
        patients.push_back(patient);
        cout << "Patient added successfully.\n";
    }

    void scheduleAppointment(Patient* patient, time_t time) {
        Appointment* appointment = new Appointment(time, patient);
        appointments.push_back(appointment);
        cout << "Appointment scheduled successfully.\n";
    }

    void listAppointments() {
        cout << "Scheduled Appointments:\n";
        for (Appointment* appointment : appointments) {
            cout << "Time: " << ctime(&appointment->time);
            cout << "Patient: " << appointment->patient->name << endl;
        }
    }
};

int main() {
    Clinic clinic;

    while (true) {
        cout << "Clinic Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Schedule Appointment\n";
        cout << "3. List Appointments\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, gender, contact;
                int age;
                cout << "Enter patient name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter patient age: ";
                cin >> age;
                cout << "Enter patient gender: ";
                cin.ignore();
                getline(cin, gender);
                cout << "Enter patient contact: ";
                getline(cin, contact);
                clinic.addPatient(name, age, gender, contact);
                break;
            }
            case 2: {
                int patientIndex, year, month, day, hour, minute;
                cout << "Enter patient index: ";
                cin >> patientIndex;
                if (patientIndex < 0 || patientIndex >= clinic.patients.size()) {
                    cout << "Invalid patient index.\n";
                    break;
                }
                cout << "Enter year (YYYY): ";
                cin >> year;
                cout << "Enter month (1-12): ";
                cin >> month;
                cout << "Enter day (1-31): ";
                cin >> day;
                cout << "Enter hour (0-23): ";
                cin >> hour;
                cout << "Enter minute (0-59): ";
                cin >> minute;

                tm appointmentTime = {};
                appointmentTime.tm_year = year - 1900;
                appointmentTime.tm_mon = month - 1;
                appointmentTime.tm_mday = day;
                appointmentTime.tm_hour = hour;
                appointmentTime.tm_min = minute;

                time_t time = mktime(&appointmentTime);
                clinic.scheduleAppointment(clinic.patients[patientIndex], time);
                break;
            }
            case 3:
                clinic.listAppointments();
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    }

    return 0;
}
