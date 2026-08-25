// Lab 5, Program 9: Maximum Value Finder
// Contrasts ordinary integers, pointer pairs, and a pointer-based array.

#include <iostream>

using namespace std;

constexpr int MAX_SIZE = 100;

int maximum(int first, int second) {
    return (first > second) ? first : second;
}

// This overload compares the values stored at two pointer addresses.
int maximum(const int* first, const int* second) {
    return (*first > *second) ? *first : *second;
}

// A pointer plus a size selects the overload that scans the whole array.
int maximum(const int* values, int size) {
    int largest = values[0];
    for (int index = 1; index < size; ++index) {
        if (values[index] > largest) {
            largest = values[index];
        }
    }
    return largest;
}

int main() {
    int firstInteger;
    int secondInteger;
    int firstPointerValue;
    int secondPointerValue;
    int values[MAX_SIZE];
    int size;

    cout << "========================================\n";
    cout << "         MAXIMUM VALUE - OVERLOADS      \n";
    cout << "========================================\n";

    cout << "Enter two integers: ";
    if (!(cin >> firstInteger >> secondInteger)) {
        cerr << "Invalid integer input.\n";
        return 1;
    }

    cout << "Enter two values to compare through pointers: ";
    if (!(cin >> firstPointerValue >> secondPointerValue)) {
        cerr << "Invalid pointer-value input.\n";
        return 1;
    }

    cout << "Enter the array size (1-" << MAX_SIZE << "): ";
    if (!(cin >> size) || size < 1 || size > MAX_SIZE) {
        cerr << "Array size must be between 1 and " << MAX_SIZE << ".\n";
        return 1;
    }

    cout << "Enter " << size << " integer(s): ";
    for (int index = 0; index < size; ++index) {
        if (!(cin >> values[index])) {
            cerr << "Invalid array input.\n";
            return 1;
        }
    }

    cout << "\n--------------- RESULTS ----------------\n";
    cout << "Maximum of the two integers : "
         << maximum(firstInteger, secondInteger) << '\n';
    cout << "Maximum through pointers     : "
         << maximum(&firstPointerValue, &secondPointerValue) << '\n';
    cout << "Maximum in the array         : " << maximum(values, size) << '\n';
    cout << "========================================\n";

    return 0;
}
