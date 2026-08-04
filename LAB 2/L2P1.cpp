#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks;

public:
    void input() {
        cout << "Enter roll number: ";
        cin >> rollNumber;

        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nStudent Details\n";
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student student;

    student.input();
    student.display();

    return 0;
}