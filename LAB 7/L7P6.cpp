// Lab 7, Problem 6: Resolving Ambiguity in Multiple Inheritance
// InternalExam + ExternalExam -> FinalResult

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class InternalExam {
    double internalMarks;

public:
    explicit InternalExam(double marks) : internalMarks(marks) {}
    void display() const {
        cout << "Internal exam marks: " << internalMarks << '\n';
    }
};

class ExternalExam {
    double externalMarks;

public:
    explicit ExternalExam(double marks) : externalMarks(marks) {}
    void display() const {
        cout << "External exam marks: " << externalMarks << '\n';
    }
};

class FinalResult : public InternalExam, public ExternalExam {
public:
    FinalResult(double internal, double external)
        : InternalExam(internal), ExternalExam(external) {}

    void showResult() const {
        // An unqualified display() here would be ambiguous.
        // Scope resolution explicitly selects each base class's function.
        InternalExam::display();
        ExternalExam::display();
    }
};

int main() {
    double internal, external;
    cout << "Enter internal and external exam marks (0 to 100 each): ";
    if (!(cin >> internal >> external) || !isfinite(internal) || !isfinite(external)
        || internal < 0 || internal > 100 || external < 0 || external > 100) {
        cerr << "Enter two marks from 0 to 100.\n";
        return 1;
    }
    const FinalResult result(internal, external);
    cout << fixed << setprecision(2) << "\nFinal result\n";
    result.showResult();
    return 0;
}
