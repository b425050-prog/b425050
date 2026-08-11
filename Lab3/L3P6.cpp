#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
private:
    int employeeId;
    string employeeName;
    double salary;

public:
    // Accept details of one employee.
    void acceptDetails() {
        cout << "Enter employee ID: ";
        cin >> employeeId;
        cin.ignore();

        cout << "Enter employee name: ";
        getline(cin, employeeName);

        cout << "Enter salary: ";
        cin >> salary;
    }

    // Display details of one employee.
    void displayDetails() const {
        cout << left << setw(12) << employeeId
             << setw(25) << employeeName
             << fixed << setprecision(2) << salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    // Dynamically allocate an array of Employee objects.
    Employee *employees = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of employee " << i + 1 << ":\n";
        employees[i].acceptDetails();
    }

    cout << "\nEmployee Details\n";
    cout << left << setw(12) << "ID"
         << setw(25) << "Name"
         << "Salary" << endl;

    for (int i = 0; i < n; i++) {
        employees[i].displayDetails();
    }

    // Release the dynamically allocated object array.
    delete[] employees;
    employees = nullptr;

    return 0;
}
