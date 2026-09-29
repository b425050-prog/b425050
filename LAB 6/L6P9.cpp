// Lab 6, Program 9: Temperature Comparison
// OOP Laboratory - Group B2 - 29 September 2026

#include <cmath>
#include <iostream>

class Temperature {
    double celsius;
public:
    Temperature(double c) : celsius(c) {}
    bool operator<(const Temperature& other) const { return celsius < other.celsius; }
    bool operator>(const Temperature& other) const { return celsius > other.celsius; }
};

int main() {
    double c1, c2;
    std::cout << "Enter two temperatures in Celsius: ";
    if (!(std::cin >> c1 >> c2) || !std::isfinite(c1) || !std::isfinite(c2)) {
        std::cerr << "Enter finite temperatures.\n"; return 1;
    }
    const Temperature first(c1), second(c2);
    if (first < second) std::cout << "First temperature is lower than the second.\n";
    else if (first > second) std::cout << "First temperature is higher than the second.\n";
    else std::cout << "Both temperatures are equal.\n";
}
