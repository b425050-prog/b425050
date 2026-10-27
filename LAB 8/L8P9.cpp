// Lab 8, Problem 9: Robot Navigation System
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

class Robot {
public:
    virtual ~Robot() = default;
    virtual double move(double distance) = 0;
};

class WheeledRobot : public Robot {
public:
    double move(double distance) override { return distance / 2.0; }
};

class TrackedRobot : public Robot {
public:
    double move(double distance) override { return distance / 1.2; }
};

int main() {
    double distance;
    cout << "Enter travel distance in metres: ";
    if (!readInput(distance) || !isfinite(distance) || distance < 0) {
        cerr << "Enter a finite, non-negative distance.\n";
        return 1;
    }

    WheeledRobot wheeled;
    TrackedRobot tracked;
    // Required base-class pointers: both calls dispatch at runtime.
    Robot* first = &wheeled;
    Robot* second = &tracked;
    cout << fixed << setprecision(2);
    cout << "Wheeled robot time: " << first->move(distance)
         << " seconds\nTracked robot time: " << second->move(distance) << " seconds\n";
    return 0;
}
