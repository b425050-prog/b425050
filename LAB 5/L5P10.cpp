// Lab 5, Program 10: Overloaded Data Processor
// Every overload applies one consistent operation (sum) to a different input form.

#include <iomanip>
#include <iostream>

using namespace std;

constexpr int MAX_SIZE = 100;

// Every processData() overload performs the same meaningful operation: sum.
long long processData(int first, int second) {
    return static_cast<long long>(first) + second;
}

double processData(int integerValue, double floatingValue) {
    return integerValue + floatingValue;
}

double processData(double first, double second) {
    return first + second;
}

long long processData(const int values[], int size) {
    long long total = 0;
    for (int index = 0; index < size; ++index) {
        total += values[index];
    }
    return total;
}

// Two pointer arguments select this overload instead of the array-and-size one.
long long processData(const int* first, const int* second) {
    return static_cast<long long>(*first) + *second;
}

int main() {
    int firstInteger;
    int secondInteger;
    int mixedInteger;
    double mixedFloatingValue;
    double firstFloatingValue;
    double secondFloatingValue;
    int values[MAX_SIZE];
    int size;
    int firstPointerValue;
    int secondPointerValue;

    cout << "========================================\n";
    cout << "       OVERLOADED DATA PROCESSOR        \n";
    cout << "         Common operation: SUM          \n";
    cout << "========================================\n";

    cout << "Enter two integers: ";
    if (!(cin >> firstInteger >> secondInteger)) {
        cerr << "Invalid integer input.\n";
        return 1;
    }

    cout << "Enter an integer and a floating-point value: ";
    if (!(cin >> mixedInteger >> mixedFloatingValue)) {
        cerr << "Invalid mixed-type input.\n";
        return 1;
    }

    cout << "Enter two floating-point values: ";
    if (!(cin >> firstFloatingValue >> secondFloatingValue)) {
        cerr << "Invalid floating-point input.\n";
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

    cout << "Enter two values to process through pointers: ";
    if (!(cin >> firstPointerValue >> secondPointerValue)) {
        cerr << "Invalid pointer-value input.\n";
        return 1;
    }

    cout << "\n--------------- RESULTS ----------------\n";
    cout << "Sum of two integers              : "
         << processData(firstInteger, secondInteger) << '\n';
    cout << "Sum of integer and floating value: " << fixed << setprecision(2)
         << processData(mixedInteger, mixedFloatingValue) << '\n';
    cout << "Sum of two floating values       : "
         << processData(firstFloatingValue, secondFloatingValue) << '\n';
    cout << "Sum of all array elements        : "
         << processData(values, size) << '\n';
    cout << "Sum of values through pointers   : "
         << processData(&firstPointerValue, &secondPointerValue) << '\n';
    cout << "========================================\n";

    return 0;
}
