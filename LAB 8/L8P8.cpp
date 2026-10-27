// Lab 8, Problem 8: Cloud Resource Cost Calculator
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

class CloudResource {
public:
    virtual ~CloudResource() = default;
    virtual double calculateCost(double cpuHours) = 0;
};

class StandardInstance : public CloudResource {
public:
    double calculateCost(double cpuHours) override {
        // Apply discount to the rate first to avoid an unnecessary intermediate overflow.
        return cpuHours * (cpuHours > 100.0 ? 5.0 * 0.85 : 5.0);
    }
};

class PremiumInstance : public CloudResource {
public:
    double calculateCost(double cpuHours) override {
        return cpuHours * (cpuHours > 100.0 ? 12.0 * 0.85 : 12.0);
    }
};

int main() {
    double cpuHours;
    cout << "Enter CPU-hours: ";
    if (!readInput(cpuHours) || !isfinite(cpuHours) || cpuHours < 0) {
        cerr << "Enter finite, non-negative CPU-hours.\n";
        return 1;
    }

    StandardInstance standard;
    PremiumInstance premium;
    CloudResource* first = &standard;
    CloudResource* second = &premium;
    const double standardCost = first->calculateCost(cpuHours);
    const double premiumCost = second->calculateCost(cpuHours);
    if (!isfinite(standardCost) || !isfinite(premiumCost)) {
        cerr << "Calculation overflow.\n";
        return 1;
    }
    cout << fixed << setprecision(2);
    cout << "Standard cost: Rs. " << standardCost
         << "\nPremium cost: Rs. " << premiumCost << '\n';
    return 0;
}
