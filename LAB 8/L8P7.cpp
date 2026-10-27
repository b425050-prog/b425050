// Lab 8, Problem 7: Cricket Target Calculator
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

class MatchFormat {
public:
    virtual ~MatchFormat() = default;
    virtual long long calculateTarget(int firstInningsScore) = 0;
};

class T20Match : public MatchFormat {
public:
    long long calculateTarget(int firstInningsScore) override {
        // ceil(score / 100) for non-negative integers, without floating point.
        const long long margin = (1LL * firstInningsScore + 99) / 100;
        return firstInningsScore + margin;
    }
};

class ODIMatch : public MatchFormat {
public:
    long long calculateTarget(int firstInningsScore) override {
        const long long margin = (2LL * firstInningsScore + 99) / 100;
        return firstInningsScore + margin;
    }
};

int main() {
    int score;
    cout << "Enter first-innings score: ";
    if (!readInput(score) || score < 0) {
        cerr << "Enter a non-negative integer score.\n";
        return 1;
    }

    T20Match t20;
    ODIMatch odi;
    MatchFormat* first = &t20;
    MatchFormat* second = &odi;
    cout << fixed << setprecision(2);
    cout << "T20 target: " << first->calculateTarget(score)
         << "\nODI target: " << second->calculateTarget(score) << '\n';
    return 0;
}
