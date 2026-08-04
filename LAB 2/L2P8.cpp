#include <iostream>
#include <string>
using namespace std;

class LibraryBook {
private:
    int bookId;
    string bookTitle;
    string studentName;
    int numberOfDays;
    int fine;

public:
    void input() {
        cout << "Enter book ID: ";
        cin >> bookId;

        cin.ignore();
        cout << "Enter book title: ";
        getline(cin, bookTitle);

        cout << "Enter student name: ";
        getline(cin, studentName);

        cout << "Enter number of days the book was issued: ";
        cin >> numberOfDays;
    }

    void calculateFine() {
        if (numberOfDays > 15) {
            fine = (numberOfDays - 15) * 2;
        } else {
            fine = 0;
        }
    }

    void display() {
        cout << "\nBook Transaction Details\n";
        cout << "Book ID: " << bookId << endl;
        cout << "Book Title: " << bookTitle << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Number of Days Issued: " << numberOfDays << endl;
        cout << "Fine: Rs. " << fine << endl;
    }
};

int main() {
    LibraryBook book;

    book.input();
    book.calculateFine();
    book.display();

    return 0;
}