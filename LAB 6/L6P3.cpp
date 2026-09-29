// Lab 6, Program 3: Student Marks Comparison
// OOP Laboratory - Group B2 - 29 September 2026

#include <iostream>
#include <string>

class Student {
    std::string name;
    int totalMarks;
public:
    Student(const std::string& n, int marks) : name(n), totalMarks(marks) {}
    bool operator>(const Student& other) const { return totalMarks > other.totalMarks; }
    const std::string& getName() const { return name; }
};

int main() {
    std::string name1, name2;
    int marks1, marks2;
    std::cout << "Enter first student's name: ";
    if (!std::getline(std::cin >> std::ws, name1)) return 1;
    std::cout << "Enter total marks: ";
    if (!(std::cin >> marks1) || marks1 < 0) {
        std::cerr << "Marks must be a non-negative integer.\n"; return 1;
    }
    std::cout << "Enter second student's name: ";
    if (!std::getline(std::cin >> std::ws, name2)) return 1;
    std::cout << "Enter total marks: ";
    if (!(std::cin >> marks2) || marks2 < 0) {
        std::cerr << "Marks must be a non-negative integer.\n"; return 1;
    }
    const Student first(name1, marks1), second(name2, marks2);
    if (first > second) std::cout << first.getName() << " has higher marks.\n";
    else if (second > first) std::cout << second.getName() << " has higher marks.\n";
    else std::cout << "Both students have equal marks.\n";
}
