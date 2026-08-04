#include <iostream>
using namespace std;

class Calculator {
private:
    float number1;
    float number2;

public:
    void input() {
        cout << "Enter first number: ";
        cin >> number1;

        cout << "Enter second number: ";
        cin >> number2;
    }

    float addition() {
        return number1 + number2;
    }

    float subtraction() {
        return number1 - number2;
    }

    float multiplication() {
        return number1 * number2;
    }

    void division() {
        if (number2 != 0) {
            cout << "Division: " << number1 / number2 << endl;
        } else {
            cout << "Division is not possible because the second number is zero."
                 << endl;
        }
    }

    void display() {
        cout << "\nCalculator Results\n";
        cout << "Addition: " << addition() << endl;
        cout << "Subtraction: " << subtraction() << endl;
        cout << "Multiplication: " << multiplication() << endl;
        division();
    }
};

int main() {
    Calculator calculator;

    calculator.input();
    calculator.display();

    return 0;
}