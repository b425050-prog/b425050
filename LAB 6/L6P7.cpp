// Lab 6, Program 7: Date Equality Checker
// OOP Laboratory - Group B2 - 29 September 2026

#include <iomanip>
#include <iostream>

class Date {
    int day, month, year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
    bool isValid() const {
        if (year < 1 || month < 1 || month > 12 || day < 1) return false;
        const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        const bool leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
        return day <= days[month - 1] + (month == 2 && leap ? 1 : 0);
    }
    void display() const {
        std::cout << std::setfill('0') << std::setw(2) << day << ' '
                  << std::setw(2) << month << ' ' << std::setw(4) << year
                  << std::setfill(' ');
    }
};

int main() {
    int d1, m1, y1, d2, m2, y2;
    std::cout << "Enter two dates (day month year for each): ";
    if (!(std::cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2)) {
        std::cerr << "Invalid date input.\n"; return 1;
    }
    const Date first(d1, m1, y1), second(d2, m2, y2);
    if (!first.isValid() || !second.isValid()) {
        std::cerr << "Enter valid calendar dates with positive years.\n"; return 1;
    }
    std::cout << "Date 1: "; first.display();
    std::cout << "\nDate 2: "; second.display();
    std::cout << '\n' << (first == second ? "Both dates are equal." : "Dates are different.") << '\n';
}
