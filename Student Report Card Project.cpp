#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks[5];
    float totalMarks;
    float average;
    char grade;
};

void calculateTotalAndAverage(Student &student) {
    student.totalMarks = 0;
    for (int i = 0; i < 5; ++i) {
        student.totalMarks += student.marks[i];
    }
    student.average = student.totalMarks / 5;
}

void assignGrade(Student &student) {
    if (student.average >= 90) {
        student.grade = 'A';
    } else if (student.average >= 80) {
        student.grade = 'B';
    } else if (student.average >= 70) {
        student.grade = 'C';
    } else if (student.average >= 60) {
        student.grade = 'D';
    } else {
        student.grade = 'F';
    }
}

void displayReportCard(const Student &student) {
    cout << "-----------------------------------" << endl;
    cout << "Student Report Card" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.rollNumber << endl;
    cout << "-----------------------------------" << endl;
    cout << "Subject-wise Marks:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Subject " << i + 1 << ": " << student.marks[i] << endl;
    }
    cout << "-----------------------------------" << endl;
    cout << "Total Marks: " << student.totalMarks << endl;
    cout << "Average Marks: " << fixed << setprecision(2) << student.average << endl;
    cout << "Grade: " << student.grade << endl;
    cout << "-----------------------------------" << endl;
}

int main() {
    Student student;

    cout << "Enter Student Name: ";
    getline(cin, student.name);

    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;

    cout << "Enter Marks for 5 Subjects:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Subject " << i + 1 << ": ";
        cin >> student.marks[i];
    }

    calculateTotalAndAverage(student);
    assignGrade(student);
    displayReportCard(student);

    return 0;
}
