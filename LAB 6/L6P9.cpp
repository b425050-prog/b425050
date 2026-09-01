// Lab 6, Program 9: Restaurant Table Manager
// Uses a dynamically allocated array and pointer traversal.

#include <iostream>

int main() {
    int tableCount = 0;
    std::cout << "Enter the number of tables: ";
    if (!(std::cin >> tableCount) || tableCount <= 0) {
        std::cerr << "Table count must be positive.\n";
        return 1;
    }

    int* tableNumbers = new int[tableCount];
    std::cout << "Enter " << tableCount << " table numbers:\n";

    for (int* currentTable = tableNumbers;
         currentTable < tableNumbers + tableCount; ++currentTable) {
        if (!(std::cin >> *currentTable)) {
            std::cerr << "Please enter integer table numbers only.\n";
            delete[] tableNumbers;
            return 1;
        }
    }

    int smallestTableNumber = *tableNumbers;
    for (const int* currentTable = tableNumbers + 1;
         currentTable < tableNumbers + tableCount; ++currentTable) {
        if (*currentTable < smallestTableNumber) {
            smallestTableNumber = *currentTable;
        }
    }

    std::cout << "Smallest table number: " << smallestTableNumber << '\n';

    // Memory created with new[] must be released with delete[].
    delete[] tableNumbers;
    tableNumbers = nullptr;
    return 0;
}
