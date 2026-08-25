// Lab 5, Program 6: Display Data
// Demonstrates overloading by scalar type and array element type.

#include <iomanip>
#include <iostream>

using namespace std;

constexpr int MAX_SIZE = 100;

// The compiler selects one display() overload from the argument's type.
void display(int value) {
    cout << value << '\n';
}

void display(double value) {
    cout << fixed << setprecision(2) << value << '\n';
}

void display(char value) {
    cout << '\'' << value << "'\n";
}

// An array is passed with its size because a function cannot determine the
// number of elements from the array parameter alone.
void display(const int values[], int size) {
    cout << "[";
    for (int index = 0; index < size; ++index) {
        if (index > 0) {
            cout << ", ";
        }
        cout << values[index];
    }
    cout << "]\n";
}

void display(const char values[], int size) {
    cout << "[";
    for (int index = 0; index < size; ++index) {
        if (index > 0) {
            cout << ", ";
        }
        cout << '\'' << values[index] << '\'';
    }
    cout << "]\n";
}

int main() {
    int integerValue;
    double floatingValue;
    char characterValue;
    int integerArray[MAX_SIZE];
    char characterArray[MAX_SIZE];
    int integerCount;
    int characterCount;

    cout << "========================================\n";
    cout << "         DISPLAY DATA - OVERLOADS       \n";
    cout << "========================================\n";

    cout << "Enter an integer: ";
    if (!(cin >> integerValue)) {
        cerr << "Invalid integer input.\n";
        return 1;
    }

    cout << "Enter a floating-point number: ";
    if (!(cin >> floatingValue)) {
        cerr << "Invalid floating-point input.\n";
        return 1;
    }

    cout << "Enter a character: ";
    if (!(cin >> characterValue)) {
        cerr << "Invalid character input.\n";
        return 1;
    }

    cout << "Enter the number of integers (1-" << MAX_SIZE << "): ";
    if (!(cin >> integerCount) || integerCount < 1 || integerCount > MAX_SIZE) {
        cerr << "Array size must be between 1 and " << MAX_SIZE << ".\n";
        return 1;
    }

    cout << "Enter " << integerCount << " integer(s): ";
    for (int index = 0; index < integerCount; ++index) {
        if (!(cin >> integerArray[index])) {
            cerr << "Invalid integer array input.\n";
            return 1;
        }
    }

    cout << "Enter the number of characters (1-" << MAX_SIZE << "): ";
    if (!(cin >> characterCount) || characterCount < 1 ||
        characterCount > MAX_SIZE) {
        cerr << "Array size must be between 1 and " << MAX_SIZE << ".\n";
        return 1;
    }

    cout << "Enter " << characterCount << " character(s), separated by spaces: ";
    for (int index = 0; index < characterCount; ++index) {
        if (!(cin >> characterArray[index])) {
            cerr << "Invalid character array input.\n";
            return 1;
        }
    }

    cout << "\n--------------- DISPLAY ----------------\n";
    cout << left;
    cout << setw(22) << "Integer" << ": ";
    display(integerValue);
    cout << setw(22) << "Floating-point" << ": ";
    display(floatingValue);
    cout << setw(22) << "Character" << ": ";
    display(characterValue);
    cout << setw(22) << "Integer array" << ": ";
    display(integerArray, integerCount);
    cout << setw(22) << "Character array" << ": ";
    display(characterArray, characterCount);
    cout << "========================================\n";

    return 0;
}
