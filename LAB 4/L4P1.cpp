#include <iostream>
#include <string>
using namespace std;

class Diary {
private:
    string ownerName;
    int numberOfEntries;
    string lastEntry;

public:
    // Constructor to initialize diary details
    Diary(string owner, int entries, string last) {
        ownerName = owner;
        numberOfEntries = entries;
        lastEntry = last;
    }

    // Friend function can access private members of Diary
    friend void displayDiary(const Diary &diary);
};

void displayDiary(const Diary &diary) {
    cout << "\n--- Diary Details ---\n";
    cout << "Owner Name        : " << diary.ownerName << '\n';
    cout << "Number of Entries : " << diary.numberOfEntries << '\n';
    cout << "Last Entry        : " << diary.lastEntry << '\n';
}

int main() {
    string ownerName, lastEntry;
    int numberOfEntries;

    cout << "Enter owner name: ";
    getline(cin, ownerName);

    cout << "Enter number of entries: ";
    cin >> numberOfEntries;
    cin.ignore();

    cout << "Enter last entry: ";
    getline(cin, lastEntry);

    Diary myDiary(ownerName, numberOfEntries, lastEntry);
    displayDiary(myDiary);

    return 0;
}
