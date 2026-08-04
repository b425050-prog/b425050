#include <iostream>
#include <string>
using namespace std;

class StudentResult {
private:
    string studentName;
    int rollNumber;
    float marks[5];
    float totalMarks;
    float percentage;
    char grade;

public:
    void input() {
        cout << "Enter roll number: ";
        cin >> rollNumber;

        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, studentName);

        cout << "Enter marks in five subjects:\n";

        for (int i = 0; i < 5; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void calculateResult() {
        totalMarks = 0;

        for (int i = 0; i < 5; i++) {
            totalMarks = totalMarks + marks[i];
        }

        percentage = (totalMarks / 500.0) * 100;

        if (percentage >= 90) {
            grade = 'A';
        } else if (percentage >= 80) {
            grade = 'B';
        } else if (percentage >= 70) {
            grade = 'C';
        } else if (percentage >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }

    void display() {
        cout << "\nStudent Result\n";
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Student Name: " << studentName << endl;

        for (int i = 0; i < 5; i++) {
            cout << "Marks in Subject " << i + 1 << ": "
                 << marks[i] << endl;
        }

        cout << "Total Marks: " << totalMarks << " / 500" << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    StudentResult student;

    student.input();
    student.calculateResult();
    student.display();

    return 0;
}