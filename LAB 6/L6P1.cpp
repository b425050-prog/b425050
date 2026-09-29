// Lab 6, Program 1: Distance Addition
// OOP Laboratory - Group B2 - 29 September 2026

#include <iostream>

class Distance {
    long long feet;
    long long inches;
public:
    Distance(long long f, long long i) : feet(f + i / 12), inches(i % 12) {}
    Distance operator+(const Distance& other) const {
        return Distance(feet + other.feet, inches + other.inches);
    }
    void display() const { std::cout << feet << " feet " << inches << " inches"; }
};

int main() {
    int f1, i1, f2, i2;
    std::cout << "Enter distance 1 (feet inches): ";
    if (!(std::cin >> f1 >> i1) || f1 < 0 || i1 < 0) {
        std::cerr << "Enter non-negative integer distances.\n"; return 1;
    }
    std::cout << "Enter distance 2 (feet inches): ";
    if (!(std::cin >> f2 >> i2) || f2 < 0 || i2 < 0) {
        std::cerr << "Enter non-negative integer distances.\n"; return 1;
    }
    const Distance first(f1, i1), second(f2, i2);
    const Distance result = first + second;
    std::cout << "Distance 1: "; first.display();
    std::cout << "\nDistance 2: "; second.display();
    std::cout << "\nResult: "; result.display();
    std::cout << '\n';
}
