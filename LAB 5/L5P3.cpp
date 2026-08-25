// Lab 5, Program 3: Array Total
// Array element type and parameter count distinguish the total() overloads.

#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>

constexpr std::size_t MAX_ELEMENTS = 50;

long long total(const int values[], std::size_t size) {
    long long sum = 0;
    for (std::size_t index = 0; index < size; ++index) {
        sum += values[index];
    }
    return sum;
}

// A double array selects this overload even though the parameter count is the same.
double total(const double values[], std::size_t size) {
    double sum = 0.0;
    for (std::size_t index = 0; index < size; ++index) {
        sum += values[index];
    }
    return sum;
}

// The extra count parameter requests the total of only the first count elements.
long long total(const int values[], std::size_t size, std::size_t count) {
    const std::size_t safeCount = (count < size) ? count : size;
    long long sum = 0;
    for (std::size_t index = 0; index < safeCount; ++index) {
        sum += values[index];
    }
    return sum;
}

int main() {
    std::array<int, MAX_ELEMENTS> integerValues{};
    std::array<double, MAX_ELEMENTS> decimalValues{};
    std::size_t integerCount = 0;
    std::size_t decimalCount = 0;
    std::size_t portionCount = 0;

    std::cout << "========================================\n"
              << "           ARRAY TOTAL - LAB 5          \n"
              << "========================================\n";

    std::cout << "Number of integers (1-" << MAX_ELEMENTS << "): ";
    if (!(std::cin >> integerCount) || integerCount == 0 ||
        integerCount > MAX_ELEMENTS) {
        std::cerr << "Invalid size. Enter a value from 1 to "
                  << MAX_ELEMENTS << ".\n";
        return 1;
    }

    std::cout << "Enter " << integerCount << " integer value(s): ";
    for (std::size_t index = 0; index < integerCount; ++index) {
        if (!(std::cin >> integerValues[index])) {
            std::cerr << "Invalid input. Please enter integer values only.\n";
            return 1;
        }
    }

    std::cout << "Number of floating-point values (1-" << MAX_ELEMENTS
              << "): ";
    if (!(std::cin >> decimalCount) || decimalCount == 0 ||
        decimalCount > MAX_ELEMENTS) {
        std::cerr << "Invalid size. Enter a value from 1 to "
                  << MAX_ELEMENTS << ".\n";
        return 1;
    }

    std::cout << "Enter " << decimalCount << " floating-point value(s): ";
    for (std::size_t index = 0; index < decimalCount; ++index) {
        if (!(std::cin >> decimalValues[index])) {
            std::cerr << "Invalid input. Please enter numeric values only.\n";
            return 1;
        }
    }

    std::cout << "How many leading integers should be totalled (1-"
              << integerCount << ")? ";
    if (!(std::cin >> portionCount) || portionCount == 0 ||
        portionCount > integerCount) {
        std::cerr << "Invalid portion size. It must be within the integer array.\n";
        return 1;
    }

    std::cout << "\n--------------- RESULTS ----------------\n"
              << "Total of the integer array      : "
              << total(integerValues.data(), integerCount) << '\n'
              << std::fixed << std::setprecision(2)
              << "Total of the decimal array      : "
              << total(decimalValues.data(), decimalCount) << '\n'
              << "Total of the first " << portionCount << " integer(s) : "
              << total(integerValues.data(), integerCount, portionCount) << '\n'
              << "========================================\n";

    return 0;
}
