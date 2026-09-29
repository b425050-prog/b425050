// Lab 6, Program 2: Complex Number Subtraction
// OOP Laboratory - Group B2 - 29 September 2026

#include <cmath>
#include <iostream>

class Complex {
    double real;
    double imaginary;
public:
    Complex(double r, double i) : real(r), imaginary(i) {}
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }
    void display() const {
        std::cout << (real == 0 ? 0 : real)
                  << (imaginary < 0 ? " - " : " + ") << std::abs(imaginary) << 'i';
    }
};

int main() {
    double r1, i1, r2, i2;
    std::cout << "Enter C1 and C2 (real imaginary for each): ";
    if (!(std::cin >> r1 >> i1 >> r2 >> i2) ||
        !std::isfinite(r1) || !std::isfinite(i1) ||
        !std::isfinite(r2) || !std::isfinite(i2) ||
        !std::isfinite(r1 - r2) || !std::isfinite(i1 - i2)) {
        std::cerr << "Enter finite numbers with a representable difference.\n"; return 1;
    }
    const Complex first(r1, i1), second(r2, i2);
    const Complex result = first - second;
    std::cout << "C1 = "; first.display();
    std::cout << "\nC2 = "; second.display();
    std::cout << "\nC1 - C2 = "; result.display();
    std::cout << '\n';
}
