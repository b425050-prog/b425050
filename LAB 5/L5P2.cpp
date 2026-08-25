// Lab 5, Program 2: Value Comparison
// The compiler selects a larger() overload from the argument list.

#include <iomanip>
#include <iostream>

int larger(int first, int second) {
    return (first >= second) ? first : second;
}

double larger(double first, double second) {
    return (first >= second) ? first : second;
}

// The third argument distinguishes this overload from larger(int, int).
int larger(int first, int second, int third) {
    return larger(larger(first, second), third);
}

int main() {
    int firstInteger = 0;
    int secondInteger = 0;
    int thirdInteger = 0;
    double firstDecimal = 0.0;
    double secondDecimal = 0.0;

    std::cout << "========================================\n"
              << "        VALUE COMPARISON - LAB 5        \n"
              << "========================================\n";

    std::cout << "Enter two integers: ";
    if (!(std::cin >> firstInteger >> secondInteger)) {
        std::cerr << "Invalid input. Please enter integer values only.\n";
        return 1;
    }
    const int largerOfTwo = larger(firstInteger, secondInteger);

    std::cout << "Enter two floating-point values: ";
    if (!(std::cin >> firstDecimal >> secondDecimal)) {
        std::cerr << "Invalid input. Please enter numeric values only.\n";
        return 1;
    }
    const double largerDecimal = larger(firstDecimal, secondDecimal);

    std::cout << "Enter three integers: ";
    if (!(std::cin >> firstInteger >> secondInteger >> thirdInteger)) {
        std::cerr << "Invalid input. Please enter integer values only.\n";
        return 1;
    }
    const int largerOfThree =
        larger(firstInteger, secondInteger, thirdInteger);

    std::cout << "\n--------------- RESULTS ----------------\n"
              << "Larger of the two integers       : " << largerOfTwo << '\n'
              << std::fixed << std::setprecision(2)
              << "Larger floating-point value      : " << largerDecimal << '\n'
              << "Largest of the three integers    : " << largerOfThree << '\n'
              << "========================================\n";

    return 0;
}
