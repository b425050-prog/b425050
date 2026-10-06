// Lab 7, Problem 1: Employee Salary - Multilevel Inheritance
// Employee -> Developer -> SeniorDeveloper

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class Employee {
protected:
    string name;
    double basicSalary;

public:
    Employee(const string& n, double basic) : name(n), basicSalary(basic) {}
};

class Developer : public Employee {
protected:
    int experience;

public:
    // Initialize the immediate base before initializing this class's member.
    Developer(const string& n, double basic, int years)
        : Employee(n, basic), experience(years) {}

    double experienceBonus() const {
        return 0.05 * basicSalary * experience;
    }
};

class SeniorDeveloper : public Developer {
    double projectBonus;

public:
    SeniorDeveloper(const string& n, double basic, int years, double bonus)
        : Developer(n, basic, years), projectBonus(bonus) {}

    double finalSalary() const {
        return basicSalary + experienceBonus() + projectBonus;
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "\nEmployee name: " << name
             << "\nBasic salary: " << basicSalary
             << "\nExperience (years): " << experience
             << "\nExperience bonus: " << experienceBonus()
             << "\nProject bonus: " << projectBonus
             << "\nFinal salary: " << finalSalary() << '\n';
    }
};

int main() {
    string name;
    double basic, bonus;
    int years;

    cout << "Enter employee name: ";
    if (!getline(cin >> ws, name)) {
        cerr << "A name is required.\n";
        return 1;
    }
    cout << "Enter basic salary, experience in whole years, and project bonus: ";
    if (!(cin >> basic >> years >> bonus) || !isfinite(basic) || !isfinite(bonus)
        || basic < 0 || years < 0 || bonus < 0) {
        cerr << "Enter finite, non-negative amounts and non-negative whole years.\n";
        return 1;
    }

    const SeniorDeveloper developer(name, basic, years, bonus);
    if (!isfinite(developer.finalSalary())) {
        cerr << "The calculated salary is too large.\n";
        return 1;
    }
    developer.display();
    return 0;
}
