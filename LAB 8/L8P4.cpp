// Lab 8, Problem 4: Food Delivery Time Estimator
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

class Delivery {
public:
    virtual ~Delivery() = default;
    virtual double estimateTime(double distance) = 0;
};

class BikeDelivery : public Delivery {
public:
    double estimateTime(double distance) override {
        return (distance / 20.0) * 60.0 + 5.0;
    }
};

class DroneDelivery : public Delivery {
public:
    double estimateTime(double distance) override {
        return (distance / 40.0) * 60.0 + 2.0;
    }
};

int main() {
    double distance;
    cout << "Enter delivery distance in km: ";
    if (!readInput(distance) || !isfinite(distance) || distance < 0) {
        cerr << "Enter a finite, non-negative distance.\n";
        return 1;
    }

    BikeDelivery bike;
    DroneDelivery drone;
    Delivery* first = &bike;
    Delivery* second = &drone;
    const double bikeTime = first->estimateTime(distance);
    const double droneTime = second->estimateTime(distance);
    if (!isfinite(bikeTime) || !isfinite(droneTime)) {
        cerr << "Calculation overflow.\n";
        return 1;
    }
    cout << fixed << setprecision(2);
    cout << "Bike delivery time: " << bikeTime << " minutes\nDrone delivery time: " << droneTime << " minutes\n";
    return 0;
}
