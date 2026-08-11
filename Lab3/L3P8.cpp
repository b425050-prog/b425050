#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    int numberOfSubjects;
    float *marks;

public:
    Student() {
        marks = nullptr;
    }

    // Accept basic details and dynamically allocate the marks array.
    void acceptDetails() {
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cin.ignore();

        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter number of subjects: ";
        cin >> numberOfSubjects;

        marks = new float[numberOfSubjects];

        cout << "Enter marks in " << numberOfSubjects << " subjects:\n";
        for (int i = 0; i < numberOfSubjects; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    // Calculate total marks.
    float calculateTotal() const {
        float total = 0.0f;
        for (int i = 0; i < numberOfSubjects; i++) {
            total += marks[i];
        }
        return total;
    }

    // Calculate average marks.
    float calculateAverage() const {
        return calculateTotal() / numberOfSubjects;
    }

    // Display complete student result.
    void displayResult() const {
        cout << "\nStudent Result\n";
        cout << "Roll Number       : " << rollNumber << endl;
        cout << "Name              : " << name << endl;
        cout << "Number of Subjects: " << numberOfSubjects << endl;

        cout << "Marks             : ";
        for (int i = 0; i < numberOfSubjects; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;

        cout << fixed << setprecision(2);
        cout << "Total Marks       : " << calculateTotal() << endl;
        cout << "Average Marks     : " << calculateAverage() << endl;
    }

    // Destructor releases the dynamically allocated marks array.
    ~Student() {
        delete[] marks;
    }
};

int main() {
    Student student;
    student.acceptDetails();
    student.displayResult();

    return 0;
}
