#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Result;

class Exam {
private:
    string studentName;
    string subject;
    double marks;
    double maximumMarks;

public:
    Exam(string name, string examSubject, double obtainedMarks, double maxMarks) {
        studentName = name;
        subject = examSubject;
        marks = obtainedMarks;
        maximumMarks = maxMarks;
    }

    friend class Result;
};

class Result {
public:
    void displayResult(const Exam &exam) {
        double percentage = (exam.marks / exam.maximumMarks) * 100.0;

        cout << fixed << setprecision(2);
        cout << "\n--- Exam Result ---\n";
        cout << "Student Name  : " << exam.studentName << '\n';
        cout << "Subject       : " << exam.subject << '\n';
        cout << "Marks         : " << exam.marks << '\n';
        cout << "Maximum Marks : " << exam.maximumMarks << '\n';
        cout << "Percentage    : " << percentage << "%\n";

        if (percentage >= 40.0)
            cout << "Result        : Pass\n";
        else
            cout << "Result        : Fail\n";
    }
};

int main() {
    string studentName, subject;
    double marks, maximumMarks;

    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter subject: ";
    getline(cin, subject);

    cout << "Enter marks obtained: ";
    cin >> marks;

    cout << "Enter maximum marks: ";
    cin >> maximumMarks;

    Exam exam(studentName, subject, marks, maximumMarks);
    Result result;
    result.displayResult(exam);

    return 0;
}
