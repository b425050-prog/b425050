// Lab 5, Program 1: Number Calculator
// Demonstrates overloading by changing the number and type of parameters.

#include <iomanip>
#include <iostream>

int calculate(int first, int second) {
    return first + second;
}

// Three parameters select this overload instead of the two-integer version.
int calculate(int first, int second, int third) {
    return first + second + third;
}

// Two floating-point arguments select this overload.
double calculate(double first, double second) {
    return first + second;
}

int main() {
    int firstInteger = 0;
    int secondInteger = 0;
    int thirdInteger = 0;
    double firstDecimal = 0.0;
    double secondDecimal = 0.0;

    std::cout << "========================================\n"
              << "       NUMBER CALCULATOR - LAB 5        \n"
              << "========================================\n";

    std::cout << "Enter two integers: ";
    if (!(std::cin >> firstInteger >> secondInteger)) {
        std::cerr << "Invalid input. Please enter integer values only.\n";
        return 1;
    }
    const int twoIntegerResult = calculate(firstInteger, secondInteger);

    std::cout << "Enter three integers: ";
    if (!(std::cin >> firstInteger >> secondInteger >> thirdInteger)) {
        std::cerr << "Invalid input. Please enter integer values only.\n";
        return 1;
    }

    const int threeIntegerResult =
        calculate(firstInteger, secondInteger, thirdInteger);

    std::cout << "Enter two floating-point values: ";
    if (!(std::cin >> firstDecimal >> secondDecimal)) {
        std::cerr << "Invalid input. Please enter numeric values only.\n";
        return 1;
    }

    std::cout << "\n--------------- RESULTS ----------------\n"
              << "Sum of the two integers       : "
              << twoIntegerResult << '\n'
              << "Sum of the three integers     : " << threeIntegerResult << '\n'
              << std::fixed << std::setprecision(2)
              << "Sum of the two decimal values : "
              << calculate(firstDecimal, secondDecimal) << '\n'
              << "========================================\n";

    return 0;
}
