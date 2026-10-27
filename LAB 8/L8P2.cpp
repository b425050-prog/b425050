// Lab 8, Problem 2: Smart Parking Fee Calculator
// Function overriding with a virtual base interface and derived implementations.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

// Read one complete line, rejecting missing values and trailing junk.
template <typename... Values>
bool readInput(Values&... values) {
    string line;
    if (!getline(cin, line)) return false;
    istringstream input(line);
    if (!(input >> ... >> values)) return false;
    input >> ws;
    return input.eof();
}

class ParkingSlot {
public:
    virtual ~ParkingSlot() = default;
    virtual double calculateFee(int hours) = 0;
};

class TwoWheelerSlot : public ParkingSlot {
public:
    double calculateFee(int hours) override {
        const double fee = 10.0 * hours;
        return hours > 5 ? fee * 0.90 : fee;
    }
};

class FourWheelerSlot : public ParkingSlot {
public:
    double calculateFee(int hours) override {
        const double fee = 30.0 * hours;
        return hours > 5 ? fee * 0.90 : fee;
    }
};

int main() {
    int hours;
    cout << "Enter parking hours: ";
    if (!readInput(hours) || hours < 0) {
        cerr << "Enter a non-negative integer number of hours.\n";
        return 1;
    }

    TwoWheelerSlot two;
    FourWheelerSlot four;
    ParkingSlot* first = &two;
    ParkingSlot* second = &four;
    cout << fixed << setprecision(2);
    cout << "Two-wheeler fee: Rs. " << first->calculateFee(hours)
         << "\nFour-wheeler fee: Rs. " << second->calculateFee(hours) << '\n';
    return 0;
}
