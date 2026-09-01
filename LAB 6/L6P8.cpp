// Lab 6, Program 8: Classroom Marks Update
// Adds five marks to every element in the caller's original array.

#include <iostream>

void addFiveMarks(int* firstMark, int studentCount) {
    for (int* currentMark = firstMark;
         currentMark < firstMark + studentCount; ++currentMark) {
        *currentMark += 5;
    }
}

void displayMarks(const int* firstMark, int studentCount) {
    for (const int* currentMark = firstMark;
         currentMark < firstMark + studentCount; ++currentMark) {
        std::cout << *currentMark << ' ';
    }
    std::cout << '\n';
}

int main() {
    int studentCount = 0;
    std::cout << "Enter the number of students: ";
    if (!(std::cin >> studentCount) || studentCount <= 0) {
        std::cerr << "Student count must be positive.\n";
        return 1;
    }

    int* marks = new int[studentCount];
    std::cout << "Enter marks for " << studentCount << " students:\n";

    for (int* currentMark = marks; currentMark < marks + studentCount;
         ++currentMark) {
        if (!(std::cin >> *currentMark)) {
            std::cerr << "Please enter integer marks only.\n";
            delete[] marks;
            return 1;
        }
    }

    std::cout << "Marks before update : ";
    displayMarks(marks, studentCount);
    addFiveMarks(marks, studentCount);
    std::cout << "Marks after update  : ";
    displayMarks(marks, studentCount);

    delete[] marks;
    marks = nullptr;
    return 0;
}
