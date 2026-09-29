// Lab 6, Program 6: Counter Increment
// OOP Laboratory - Group B2 - 29 September 2026

#include <iostream>

class Counter {
    long long value;
public:
    Counter(long long v) : value(v) {}
    Counter& operator++() { ++value; return *this; }
    Counter operator++(int) {
        Counter previous = *this;
        ++(*this);
        return previous;
    }
    long long getValue() const { return value; }
};

int main() {
    int value;
    std::cout << "Enter initial counter value: ";
    if (!(std::cin >> value)) { std::cerr << "Invalid integer.\n"; return 1; }
    Counter counter(value);
    std::cout << "Before prefix: " << counter.getValue() << '\n';
    const Counter prefixResult = ++counter;
    std::cout << "Prefix returned: " << prefixResult.getValue()
              << "\nAfter prefix: " << counter.getValue() << '\n';
    std::cout << "Before postfix: " << counter.getValue() << '\n';
    const Counter postfixResult = counter++;
    std::cout << "Postfix returned: " << postfixResult.getValue()
              << "\nAfter postfix: " << counter.getValue() << '\n';
}
