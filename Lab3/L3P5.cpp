#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks;

public:
    // Accept student details from the user.
    void acceptDetails() {
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cin.ignore();

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter marks: ";
        cin >> marks;
    }

    // Display the stored student details.
    void displayDetails() const {
        cout << "\nStudent Details\n";
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name       : " << name << endl;
        cout << "Marks      : " << marks << endl;
    }
};

int main() {
    // Create a Student object dynamically.
    Student *student = new Student;

    student->acceptDetails();
    student->displayDetails();

    // Release the dynamically allocated object.
    delete student;
    student = nullptr;

    return 0;
}
