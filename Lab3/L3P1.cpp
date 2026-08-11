#include <iostream>
using namespace std;

int main() {
    // Dynamically allocate memory for one integer.
    int *num = new int;

    cout << "Enter an integer: ";
    cin >> *num;

    cout << "Stored value: " << *num << endl;

    // Release the dynamically allocated memory.
    delete num;
    num = nullptr;

    return 0;
}
