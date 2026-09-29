// Lab 6, Program 5: Time Addition
// OOP Laboratory - Group B2 - 29 September 2026

#include <iostream>

class Time {
    long long hours;
    long long minutes;
public:
    Time(long long h, long long m) : hours(h + m / 60), minutes(m % 60) {}
    Time operator+(const Time& other) const {
        return Time(hours + other.hours, minutes + other.minutes);
    }
    void display() const { std::cout << hours << " hours " << minutes << " minutes"; }
};

int main() {
    int h1, m1, h2, m2;
    std::cout << "Enter time 1 (hours minutes): ";
    if (!(std::cin >> h1 >> m1) || h1 < 0 || m1 < 0) {
        std::cerr << "Enter non-negative integer durations.\n"; return 1;
    }
    std::cout << "Enter time 2 (hours minutes): ";
    if (!(std::cin >> h2 >> m2) || h2 < 0 || m2 < 0) {
        std::cerr << "Enter non-negative integer durations.\n"; return 1;
    }
    const Time first(h1, m1), second(h2, m2);
    const Time result = first + second;
    std::cout << "Time 1: "; first.display();
    std::cout << "\nTime 2: "; second.display();
    std::cout << "\nResult: "; result.display();
    std::cout << '\n';
}
