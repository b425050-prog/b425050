// Lab 8, Problem 1: Game Character Battle
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

class Character {
public:
    virtual ~Character() = default;
    virtual long long attack() = 0;
};

class Warrior : public Character {
    int strength;
public:
    explicit Warrior(int value) : strength(value) {}
    long long attack() override { return 20LL + 2LL * strength; }
};

class Archer : public Character {
    int agility;
public:
    explicit Archer(int value) : agility(value) {}
    long long attack() override { return 15LL + 3LL * agility; }
};

int main() {
    int strength, agility;
    cout << "Enter strength and agility: ";
    if (!readInput(strength, agility) || strength < 0 || agility < 0) {
        cerr << "Enter two non-negative integers.\n";
        return 1;
    }

    Warrior warrior(strength);
    Archer archer(agility);
    Character* first = &warrior;
    Character* second = &archer;
    cout << fixed << setprecision(2);
    cout << "Warrior damage: " << first->attack() << "\nArcher damage: " << second->attack() << '\n';
    return 0;
}
