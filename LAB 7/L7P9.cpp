// Lab 7, Problem 9: Constructor Execution in Inheritance
// Person -> Employee -> Manager

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
    Person(const string& n, int years) : name(n), age(years) {
        cout << "Person constructor\n";
    }
};

class Employee : public Person {
protected:
    string employeeID;
    double salary;

public:
    Employee(const string& n, int years, const string& id, double pay)
        : Person(n, years), employeeID(id), salary(pay) {
        cout << "Employee constructor\n";
    }
};

class Manager : public Employee {
    string department;

public:
    Manager(const string& n, int years, const string& id, double pay, const string& dept)
        : Employee(n, years, id, pay), department(dept) {
        // This body runs only after the Person and Employee constructors finish.
        cout << "Manager constructor\n";
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "\nManager information\nName: " << name << "\nAge: " << age
             << "\nEmployee ID: " << employeeID << "\nSalary: " << salary
             << "\nDepartment: " << department << '\n';
    }
};

int main() {
    string name, id, department;
    int age;
    double salary;
    cout << "Enter manager name: ";
    if (!getline(cin >> ws, name)) return 1;
    cout << "Enter age, employee ID, and salary: ";
    if (!(cin >> age >> id >> salary) || age < 0 || !isfinite(salary) || salary < 0) {
        cerr << "Enter non-negative whole age, an ID, and a finite, non-negative salary.\n";
        return 1;
    }
    cout << "Enter department: ";
    if (!getline(cin >> ws, department)) return 1;

    cout << "\nConstructing a Manager object:\n";
    const Manager manager(name, age, id, salary, department);
    manager.display();
    return 0;
}
