// Lab 7, Problem 2: Student Result - Function Overriding
// Student -> RegularStudent and ScholarshipStudent

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class Student {
protected:
    string name;
    string rollNo;

public:
    Student(const string& n, const string& roll) : name(n), rollNo(roll) {}
    virtual ~Student() = default;

    // The worksheet does not specify subject count; this program uses three.
    // A pure virtual function requires both student types to supply a result.
    virtual double calculateResult() const = 0;

    void display() const {
        cout << "Name: " << name << "\nRoll number: " << rollNo
             << "\nFinal total: " << fixed << setprecision(2)
             << calculateResult() << '\n';
    }
};

class RegularStudent : public Student {
    double marks[3];

public:
    RegularStudent(const string& n, const string& roll, double a, double b, double c)
        : Student(n, roll), marks{a, b, c} {}

    double calculateResult() const override {
        return marks[0] + marks[1] + marks[2];
    }
};

class ScholarshipStudent : public Student {
    double marks[3];

public:
    ScholarshipStudent(const string& n, const string& roll, double a, double b, double c)
        : Student(n, roll), marks{a, b, c} {}

    double calculateResult() const override {
        // Add five to the total, not five to each subject; do not cap the bonus.
        return marks[0] + marks[1] + marks[2] + 5;
    }
};

bool readStudent(const string& type, string& name, string& roll, double marks[3]) {
    cout << "\nEnter " << type << " student's name: ";
    if (!getline(cin >> ws, name)) return false;
    cout << "Enter roll number: ";
    if (!getline(cin >> ws, roll)) return false;
    cout << "Enter three subject marks (0 to 100 each): ";
    for (int i = 0; i < 3; ++i) {
        if (!(cin >> marks[i]) || !isfinite(marks[i])
            || marks[i] < 0 || marks[i] > 100) return false;
    }
    return true;
}

int main() {
    string regularName, regularRoll, scholarshipName, scholarshipRoll;
    double regularMarks[3], scholarshipMarks[3];
    if (!readStudent("regular", regularName, regularRoll, regularMarks)
        || !readStudent("scholarship", scholarshipName, scholarshipRoll, scholarshipMarks)) {
        cerr << "Enter names, roll numbers, and three marks from 0 to 100.\n";
        return 1;
    }

    const RegularStudent regular(regularName, regularRoll,
                                regularMarks[0], regularMarks[1], regularMarks[2]);
    const ScholarshipStudent scholarship(scholarshipName, scholarshipRoll,
                                        scholarshipMarks[0], scholarshipMarks[1], scholarshipMarks[2]);

    // Base references keep dynamic dispatch: each call uses the derived override.
    const Student& regularView = regular;
    const Student& scholarshipView = scholarship;
    cout << "\nRegular student (no bonus)\n";
    regularView.display();
    cout << "\nScholarship student (5 bonus marks)\n";
    scholarshipView.display();
    return 0;
}
