// Lab 7, Problem 8: Hospital System - Protected Members
// Patient -> InPatient

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class Patient {
protected:
    // Derived classes may access these; callers in main() cannot access them.
    string patientName;
    string patientID;
    int age;

public:
    Patient(const string& n, const string& id, int years)
        : patientName(n), patientID(id), age(years) {}
};

class InPatient : public Patient {
    double roomCharges;
    int numberOfDays;

public:
    InPatient(const string& n, const string& id, int years, double dailyCharge, int days)
        : Patient(n, id, years), roomCharges(dailyCharge), numberOfDays(days) {}

    double totalBill() const {
        // The worksheet supplies room charges only, interpreted as a daily rate.
        return roomCharges * numberOfDays;
    }

    void display() const {
        // Access patient information directly through inherited protected members.
        cout << fixed << setprecision(2);
        cout << "\nPatient name: " << patientName << "\nPatient ID: " << patientID
             << "\nAge: " << age << "\nRoom charges per day: " << roomCharges
             << "\nNumber of days: " << numberOfDays
             << "\nTotal hospital bill: " << totalBill() << '\n';
    }
};

int main() {
    string name, id;
    int age, days;
    double charge;
    cout << "Enter patient name: ";
    if (!getline(cin >> ws, name)) return 1;
    cout << "Enter patient ID, age, room charge per day, and number of days: ";
    if (!(cin >> id >> age >> charge >> days) || age < 0 || days < 0
        || !isfinite(charge) || charge < 0) {
        cerr << "Enter an ID, non-negative whole age/days, and a non-negative room charge.\n";
        return 1;
    }
    const InPatient patient(name, id, age, charge, days);
    if (!isfinite(patient.totalBill())) {
        cerr << "The calculated hospital bill is too large.\n";
        return 1;
    }
    patient.display();
    return 0;
}
