#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
private:
    int employeeId;
    string employeeName;
    double basicSalary;
    int numberOfMonths;
    double *monthlyEarnings;

public:
    Employee() {
        monthlyEarnings = nullptr;
    }

    // Accept employee details and monthly earnings.
    void acceptDetails() {
        cout << "Enter employee ID: ";
        cin >> employeeId;
        cin.ignore();

        cout << "Enter employee name: ";
        getline(cin, employeeName);

        cout << "Enter basic salary: ";
        cin >> basicSalary;

        cout << "Enter number of months: ";
        cin >> numberOfMonths;

        // Allocate memory according to the number of months entered at runtime.
        monthlyEarnings = new double[numberOfMonths];

        cout << "Enter monthly earnings:\n";
        for (int i = 0; i < numberOfMonths; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> monthlyEarnings[i];
        }
    }

    // Calculate total of all monthly earnings.
    double calculateTotalEarnings() const {
        double total = 0.0;
        for (int i = 0; i < numberOfMonths; i++) {
            total += monthlyEarnings[i];
        }
        return total;
    }

    // Calculate average monthly earning.
    double calculateAverageEarning() const {
        return calculateTotalEarnings() / numberOfMonths;
    }

    // Return the index of the month having the highest earning.
    int findHighestEarningMonth() const {
        int highestMonth = 0;
        for (int i = 1; i < numberOfMonths; i++) {
            if (monthlyEarnings[i] > monthlyEarnings[highestMonth]) {
                highestMonth = i;
            }
        }
        return highestMonth;
    }

    // Display the complete employee salary analysis.
    void displayAnalysis() const {
        int highestMonth = findHighestEarningMonth();

        cout << fixed << setprecision(2);
        cout << "\nEmployee Salary Analysis\n";
        cout << "Employee ID             : " << employeeId << endl;
        cout << "Employee Name           : " << employeeName << endl;
        cout << "Basic Salary            : " << basicSalary << endl;
        cout << "Number of Months        : " << numberOfMonths << endl;

        cout << "Monthly Earnings        : ";
        for (int i = 0; i < numberOfMonths; i++) {
            cout << monthlyEarnings[i] << " ";
        }
        cout << endl;

        cout << "Total Earnings          : " << calculateTotalEarnings() << endl;
        cout << "Average Monthly Earning : " << calculateAverageEarning() << endl;
        cout << "Highest Earning Month   : Month " << highestMonth + 1 << endl;
        cout << "Highest Earning         : " << monthlyEarnings[highestMonth] << endl;
    }

    // Destructor releases dynamically allocated monthly earnings.
    ~Employee() {
        delete[] monthlyEarnings;
    }
};

int main() {
    Employee employee;
    employee.acceptDetails();
    employee.displayAnalysis();

    return 0;
}
