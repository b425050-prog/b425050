// Lab 5, Program 8: Counting Operation
// Parameter type and count select which kind of item is counted.

#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

constexpr int MAX_ARRAY_SIZE = 100;
constexpr int MAX_CHARACTER_COUNT = 100;

int count(int number) {
    // Zero has one digit. Dividing a negative value directly also avoids the
    // overflow that abs(INT_MIN) could cause.
    if (number == 0) {
        return 1;
    }

    int digits = 0;
    while (number != 0) {
        ++digits;
        number /= 10;
    }
    return digits;
}

// Arrays lose their length when passed to a function, so the size is supplied.
int count(const int[], int size) {
    return size;
}

// Adding the target character creates the third count() overload.
int count(const char values[], int size, char target) {
    int occurrences = 0;
    for (int index = 0; index < size; ++index) {
        if (values[index] == target) {
            ++occurrences;
        }
    }
    return occurrences;
}

int main() {
    int number;
    int integerArray[MAX_ARRAY_SIZE];
    int arraySize;
    char characterArray[MAX_CHARACTER_COUNT + 1] = {};
    char target;

    cout << "========================================\n";
    cout << "        COUNTING OPERATION - OVERLOADS  \n";
    cout << "========================================\n";

    cout << "Enter an integer: ";
    if (!(cin >> number)) {
        cerr << "Invalid integer input.\n";
        return 1;
    }

    cout << "Enter the integer-array size (0-" << MAX_ARRAY_SIZE << "): ";
    if (!(cin >> arraySize) || arraySize < 0 || arraySize > MAX_ARRAY_SIZE) {
        cerr << "Array size must be between 0 and " << MAX_ARRAY_SIZE << ".\n";
        return 1;
    }

    if (arraySize > 0) {
        cout << "Enter " << arraySize << " integer(s): ";
        for (int index = 0; index < arraySize; ++index) {
            if (!(cin >> integerArray[index])) {
                cerr << "Invalid integer array input.\n";
                return 1;
            }
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter a character array (up to " << MAX_CHARACTER_COUNT
         << " characters): ";
    cin.getline(characterArray, MAX_CHARACTER_COUNT + 1);
    if (cin.fail()) {
        cerr << "Character array exceeds " << MAX_CHARACTER_COUNT
             << " characters.\n";
        return 1;
    }

    int characterCount = 0;
    while (characterArray[characterCount] != '\0') {
        ++characterCount;
    }

    cout << "Enter the character to count: ";
    if (!cin.get(target) || target == '\n') {
        cerr << "A character is required.\n";
        return 1;
    }

    cout << "\n--------------- RESULTS ----------------\n";
    cout << left;
    cout << setw(34) << "Digits in entered integer" << ": " << count(number)
         << '\n';
    cout << setw(34) << "Elements in the integer array" << ": "
         << count(integerArray, arraySize) << '\n';
    cout << setw(34) << "Occurrences of selected character" << ": "
         << count(characterArray, characterCount, target) << " ('" << target
         << "')\n";
    cout << "========================================\n";

    return 0;
}
