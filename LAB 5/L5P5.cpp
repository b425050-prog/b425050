// Lab 5, Program 5: Modify a Value
// Reference and pointer parameter types distinguish the modify() overloads.

#include <iomanip>
#include <iostream>

void modify(int& value, int amount) {
    value += amount;
}

void modify(double& value, double amount) {
    value += amount;
}

// Passing an address selects the pointer overload and changes that stored integer.
void modify(int* value, int amount) {
    if (value != nullptr) {
        *value += amount;
    }
}

int main() {
    int integerValue = 0;
    int integerAmount = 0;
    double decimalValue = 0.0;
    double decimalAmount = 0.0;
    int pointerValue = 0;
    int pointerAmount = 0;

    std::cout << "========================================\n"
              << "          MODIFY A VALUE - LAB 5        \n"
              << "========================================\n";

    std::cout << "Enter an integer and the value to add: ";
    if (!(std::cin >> integerValue >> integerAmount)) {
        std::cerr << "Invalid input. Please enter integer values only.\n";
        return 1;
    }

    std::cout << "Enter a floating-point number and the value to add: ";
    if (!(std::cin >> decimalValue >> decimalAmount)) {
        std::cerr << "Invalid input. Please enter numeric values only.\n";
        return 1;
    }

    std::cout << "Enter an integer to modify through a pointer and the value to add: ";
    if (!(std::cin >> pointerValue >> pointerAmount)) {
        std::cerr << "Invalid input. Please enter integer values only.\n";
        return 1;
    }

    const int integerBefore = integerValue;
    const double decimalBefore = decimalValue;
    const int pointerBefore = pointerValue;

    modify(integerValue, integerAmount);
    modify(decimalValue, decimalAmount);
    modify(&pointerValue, pointerAmount);

    std::cout << "\n--------------- RESULTS ----------------\n"
              << "Integer value       : " << integerBefore << " -> "
              << integerValue << '\n'
              << std::fixed << std::setprecision(2)
              << "Floating-point value: " << decimalBefore << " -> "
              << decimalValue << '\n'
              << "Pointer-modified int: " << pointerBefore << " -> "
              << pointerValue << '\n'
              << "========================================\n";

    return 0;
}
