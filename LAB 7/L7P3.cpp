// Lab 7, Problem 3: Vehicle Rental - Multilevel Inheritance
// Vehicle -> Car -> LuxuryCar

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class Vehicle {
protected:
    string registrationNumber;
    int rentalDays;

public:
    Vehicle(const string& registration, int days)
        : registrationNumber(registration), rentalDays(days) {}
};

class Car : public Vehicle {
protected:
    double dailyRate;

public:
    Car(const string& registration, int days, double rate)
        : Vehicle(registration, days), dailyRate(rate) {}
};

class LuxuryCar : public Car {
    double luxuryCharge;

public:
    LuxuryCar(const string& registration, int days, double rate, double charge)
        : Car(registration, days, rate), luxuryCharge(charge) {}

    double totalCost() const {
        // Both charges apply on each rental day.
        return (dailyRate + luxuryCharge) * rentalDays;
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "\nRegistration number: " << registrationNumber
             << "\nRental days: " << rentalDays
             << "\nDaily rental rate: " << dailyRate
             << "\nLuxury charge per day: " << luxuryCharge
             << "\nTotal rental cost: " << totalCost() << '\n';
    }
};

int main() {
    string registration;
    int days;
    double rate, charge;
    cout << "Enter registration number: ";
    if (!getline(cin >> ws, registration)) {
        cerr << "A registration number is required.\n";
        return 1;
    }
    cout << "Enter rental days, daily rate, and luxury charge per day: ";
    if (!(cin >> days >> rate >> charge) || days < 0
        || !isfinite(rate) || !isfinite(charge) || rate < 0 || charge < 0) {
        cerr << "Enter non-negative whole days and finite, non-negative charges.\n";
        return 1;
    }
    const LuxuryCar car(registration, days, rate, charge);
    if (!isfinite(car.totalCost())) {
        cerr << "The calculated rental cost is too large.\n";
        return 1;
    }
    car.display();
    return 0;
}
