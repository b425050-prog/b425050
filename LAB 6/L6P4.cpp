// Lab 6, Program 4: Negative Value Converter
// OOP Laboratory - Group B2 - 29 September 2026

#include <iostream>

class Number {
    long long value;
public:
    Number(long long v) : value(v) {}
    Number operator-() const { return Number(-value); }
    long long getValue() const { return value; }
};

int main() {
    // Read an int and store it in long long so even INT_MIN can be negated safely.
    int value;
    std::cout << "Enter an integer: ";
    if (!(std::cin >> value)) { std::cerr << "Invalid integer.\n"; return 1; }
    const Number n1 = value;
    const Number n2 = -n1;
    std::cout << "n1 = " << n1.getValue() << "\nn2 = " << n2.getValue() << '\n';
}
