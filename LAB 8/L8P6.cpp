// Lab 8, Problem 6: Cybersecurity Threat Scanner
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

class SecurityScanner {
public:
    virtual ~SecurityScanner() = default;
    virtual void scan(int threats) = 0;
};

class BasicScanner : public SecurityScanner {
public:
    void scan(int threats) override {
        cout << "Basic scanner detected: " << threats << '\n';
    }
};

class AdvancedScanner : public SecurityScanner {
public:
    void scan(int threats) override {
        // Whole threats: remove floor(0.90 * threats), keep ceil(threats / 10).
        // Quotient + remainder avoids floating-point error and int overflow.
        const int remaining = threats / 10 + (threats % 10 != 0);
        cout << "Advanced scanner detected: " << threats
             << "\nAdvanced scanner removed: " << threats - remaining
             << "\nAdvanced scanner remaining: " << remaining << '\n';
    }
};

int main() {
    int threats;
    cout << "Enter detected threats: ";
    if (!readInput(threats) || threats < 0) {
        cerr << "Enter a non-negative integer threat count.\n";
        return 1;
    }

    BasicScanner basic;
    AdvancedScanner advanced;
    SecurityScanner* first = &basic;
    SecurityScanner* second = &advanced;
    cout << fixed << setprecision(2);
    first->scan(threats);
    second->scan(threats);
    return 0;
}
