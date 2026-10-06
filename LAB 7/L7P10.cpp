// Lab 7, Problem 10: Diamond Problem - Virtual Inheritance
// Employee -> Developer and Tester -> TechLead (one shared Employee)

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string employeeID;
    string name;

public:
    Employee(const string& id, const string& n) : employeeID(id), name(n) {}
};

class Developer : virtual public Employee {
protected:
    string programmingLanguage;

public:
    Developer(const string& id, const string& n, const string& language)
        : Employee(id, n), programmingLanguage(language) {}
};

class Tester : virtual public Employee {
protected:
    string testingTool;

public:
    Tester(const string& id, const string& n, const string& tool)
        : Employee(id, n), testingTool(tool) {}
};

class TechLead : public Developer, public Tester {
public:
    // The most-derived class initializes Employee exactly once.
    TechLead(const string& id, const string& n, const string& language, const string& tool)
        : Employee(id, n), Developer(id, n, language), Tester(id, n, tool) {}

    bool hasOneEmployee() const {
        const Employee* viaDeveloper = static_cast<const Developer*>(this);
        const Employee* viaTester = static_cast<const Tester*>(this);
        return viaDeveloper == viaTester;
    }

    void display() const {
        // name and employeeID are unambiguous because Employee is a virtual base.
        cout << "\nTech lead\nEmployee ID: " << employeeID << "\nName: " << name
             << "\nProgramming language: " << programmingLanguage
             << "\nTesting tool: " << testingTool
             << "\nShared Employee base: " << (hasOneEmployee() ? "Yes" : "No") << '\n';
    }
};

int main() {
    string id, name, language, tool;
    cout << "Enter employee ID: ";
    if (!getline(cin >> ws, id)) return 1;
    cout << "Enter name: ";
    if (!getline(cin >> ws, name)) return 1;
    cout << "Enter programming language: ";
    if (!getline(cin >> ws, language)) return 1;
    cout << "Enter testing tool: ";
    if (!getline(cin >> ws, tool)) return 1;

    const TechLead lead(id, name, language, tool);
    lead.display();
    return 0;
}
