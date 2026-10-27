// Lab 8, Problem 5: Smart Irrigation Controller
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

class IrrigationSystem {
public:
    virtual ~IrrigationSystem() = default;
    virtual double calculateWater(double moisture) = 0;
};

class DripIrrigation : public IrrigationSystem {
public:
    double calculateWater(double moisture) override { return 2.0 * (100.0 - moisture); }
};

class SprinklerIrrigation : public IrrigationSystem {
public:
    double calculateWater(double moisture) override { return 3.0 * (100.0 - moisture); }
};

int main() {
    double moisture;
    cout << "Enter soil moisture (0 to 100 percent): ";
    if (!readInput(moisture) || !isfinite(moisture) || moisture < 0 || moisture > 100) {
        cerr << "Enter a finite moisture percentage from 0 to 100.\n";
        return 1;
    }

    DripIrrigation drip;
    SprinklerIrrigation sprinkler;
    IrrigationSystem* first = &drip;
    IrrigationSystem* second = &sprinkler;
    cout << fixed << setprecision(2);
    cout << "Drip water: " << first->calculateWater(moisture)
         << " litres\nSprinkler water: " << second->calculateWater(moisture) << " litres\n";
    return 0;
}
