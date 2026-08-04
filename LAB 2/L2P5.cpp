#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int employeeId;
    string employeeName;
    float basicSalary;
    float hra;
    float da;
    float grossSalary;

public:
    void input() {
        cout << "Enter employee ID: ";
        cin >> employeeId;

        cin.ignore();
        cout << "Enter employee name: ";
        getline(cin, employeeName);

        cout << "Enter basic salary: ";
        cin >> basicSalary;
    }

    void calculateSalary() {
        hra = 0.20 * basicSalary;
        da = 0.10 * basicSalary;
        grossSalary = basicSalary + hra + da;
    }

    void display() {
        cout << "\nEmployee Salary Details\n";
        cout << "Employee ID: " << employeeId << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Basic Salary: Rs. " << basicSalary << endl;
        cout << "HRA: Rs. " << hra << endl;
        cout << "DA: Rs. " << da << endl;
        cout << "Gross Salary: Rs. " << grossSalary << endl;
    }
};

int main() {
    Employee employee;

    employee.input();
    employee.calculateSalary();
    employee.display();

    return 0;
}