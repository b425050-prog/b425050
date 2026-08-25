// Lab 5, Program 7: Compare Data Sets
// Uses the same function name for scalar comparisons and array equality.

#include <iomanip>
#include <iostream>

using namespace std;

constexpr int MAX_SIZE = 100;

int compareData(int first, int second) {
    return (first > second) ? first : second;
}

// Changing the parameter type makes this a different compareData() overload.
double compareData(double first, double second) {
    return (first > second) ? first : second;
}

// The three-parameter overload compares corresponding array elements.
bool compareData(const int first[], const int second[], int size) {
    for (int index = 0; index < size; ++index) {
        if (first[index] != second[index]) {
            return false;
        }
    }
    return true;
}

int main() {
    int firstInteger;
    int secondInteger;
    double firstFloatingValue;
    double secondFloatingValue;
    int firstArray[MAX_SIZE];
    int secondArray[MAX_SIZE];
    int size;

    cout << "========================================\n";
    cout << "       COMPARE DATA SETS - OVERLOADS    \n";
    cout << "========================================\n";

    cout << "Enter two integers: ";
    if (!(cin >> firstInteger >> secondInteger)) {
        cerr << "Invalid integer input.\n";
        return 1;
    }

    cout << "Enter two floating-point numbers: ";
    if (!(cin >> firstFloatingValue >> secondFloatingValue)) {
        cerr << "Invalid floating-point input.\n";
        return 1;
    }

    cout << "Enter the common array size (1-" << MAX_SIZE << "): ";
    if (!(cin >> size) || size < 1 || size > MAX_SIZE) {
        cerr << "Array size must be between 1 and " << MAX_SIZE << ".\n";
        return 1;
    }

    cout << "Enter " << size << " element(s) for the first array: ";
    for (int index = 0; index < size; ++index) {
        if (!(cin >> firstArray[index])) {
            cerr << "Invalid first-array input.\n";
            return 1;
        }
    }

    cout << "Enter " << size << " element(s) for the second array: ";
    for (int index = 0; index < size; ++index) {
        if (!(cin >> secondArray[index])) {
            cerr << "Invalid second-array input.\n";
            return 1;
        }
    }

    cout << "\n--------------- RESULTS ----------------\n";
    cout << "Larger integer              : "
         << compareData(firstInteger, secondInteger) << '\n';
    cout << "Larger floating-point value : " << fixed << setprecision(2)
         << compareData(firstFloatingValue, secondFloatingValue) << '\n';
    cout << "Arrays are                  : "
         << (compareData(firstArray, secondArray, size)
                 ? "identical"
                 : "not identical")
         << '\n';
    cout << "========================================\n";

    return 0;
}
