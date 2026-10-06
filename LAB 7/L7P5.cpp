// Lab 7, Problem 5: Student Performance - Multiple Inheritance
// Academic + Sports -> StudentResult

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Academic {
protected:
    double subjectMarks[3];

public:
    Academic(double a, double b, double c) : subjectMarks{a, b, c} {}

    double academicTotal() const {
        return subjectMarks[0] + subjectMarks[1] + subjectMarks[2];
    }
};

class Sports {
protected:
    double sportsMarks;

public:
    explicit Sports(double marks) : sportsMarks(marks) {}
};

class StudentResult : public Academic, public Sports {
public:
    // Initialize both independent base-class parts of the result.
    StudentResult(double a, double b, double c, double sports)
        : Academic(a, b, c), Sports(sports) {}

    double total() const { return academicTotal() + sportsMarks; }
    double average() const { return total() / 4.0; }

    void display() const {
        cout << fixed << setprecision(2);
        for (int i = 0; i < 3; ++i) {
            cout << "Subject " << i + 1 << ": " << subjectMarks[i] << '\n';
        }
        cout << "Academic total: " << academicTotal()
             << "\nSports marks: " << sportsMarks
             << "\nTotal: " << total()
             << "\nAverage: " << average() << '\n';
    }
};

int main() {
    double marks[4];
    cout << "Enter three academic marks, then sports marks (0 to 100 each): ";
    for (int i = 0; i < 4; ++i) {
        if (!(cin >> marks[i]) || !isfinite(marks[i]) || marks[i] < 0 || marks[i] > 100) {
            cerr << "Each mark must be a number from 0 to 100.\n";
            return 1;
        }
    }
    const StudentResult result(marks[0], marks[1], marks[2], marks[3]);
    cout << "\nStudent performance\n";
    result.display();
    return 0;
}
