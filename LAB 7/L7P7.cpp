// Lab 7, Problem 7: University Personnel - Hybrid Inheritance
// Person -> Student and Employee -> TeachingAssistant (one shared Person)

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(const string& n, int years) : name(n), age(years) {}
};

class Student : virtual public Person {
protected:
    string rollNo;
    double cgpa;

public:
    Student(const string& n, int years, const string& roll, double grade)
        : Person(n, years), rollNo(roll), cgpa(grade) {}
};

class Employee : virtual public Person {
protected:
    string employeeID;
    double salary;

public:
    Employee(const string& n, int years, const string& id, double pay)
        : Person(n, years), employeeID(id), salary(pay) {}
};

class TeachingAssistant : public Student, public Employee {
public:
    // The most-derived class constructs the shared virtual base Person.
    // Student/Employee's Person initializers are ignored when constructing a TA.
    TeachingAssistant(const string& n, int years, const string& roll, double grade,
                      const string& id, double pay)
        : Person(n, years), Student(n, years, roll, grade), Employee(n, years, id, pay) {}

    bool hasOnePerson() const {
        // Both inheritance paths must lead to the exact same Person subobject.
        const Person* viaStudent = static_cast<const Student*>(this);
        const Person* viaEmployee = static_cast<const Employee*>(this);
        return viaStudent == viaEmployee;
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "\nTeaching assistant\nName: " << name << "\nAge: " << age
             << "\nRoll number: " << rollNo << "\nCGPA: " << cgpa
             << "\nEmployee ID: " << employeeID << "\nSalary: " << salary
             << "\nShared Person base: " << (hasOnePerson() ? "Yes" : "No") << '\n';
    }
};

int main() {
    string name, roll, id;
    int age;
    double cgpa, salary;
    cout << "Enter name: ";
    if (!getline(cin >> ws, name)) return 1;
    cout << "Enter age, roll number, CGPA, employee ID, and salary: ";
    if (!(cin >> age >> roll >> cgpa >> id >> salary) || age < 0
        || !isfinite(cgpa) || cgpa < 0 || cgpa > 10
        || !isfinite(salary) || salary < 0) {
        cerr << "Enter non-negative whole age, CGPA from 0 to 10, and non-negative salary.\n";
        return 1;
    }
    const TeachingAssistant assistant(name, age, roll, cgpa, id, salary);
    assistant.display();
    return 0;
}
