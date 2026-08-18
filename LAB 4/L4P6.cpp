#include <iostream>
using namespace std;

class SecuritySystem;

class Door {
private:
    int doorNumber;
    bool isLocked;

public:
    Door(int number, bool lockStatus) {
        doorNumber = number;
        isLocked = lockStatus;
    }

    // Entire SecuritySystem class can access private members of Door
    friend class SecuritySystem;
};

class SecuritySystem {
public:
    void checkLockStatus(const Door &door) {
        cout << "\n--- Door Status ---\n";
        cout << "Door Number : " << door.doorNumber << '\n';

        if (door.isLocked)
            cout << "Lock Status : Locked\n";
        else
            cout << "Lock Status : Unlocked\n";
    }
};

int main() {
    int doorNumber, lockChoice;

    cout << "Enter door number: ";
    cin >> doorNumber;

    cout << "Enter lock status (1 for Locked, 0 for Unlocked): ";
    cin >> lockChoice;

    Door door(doorNumber, lockChoice == 1);
    SecuritySystem security;
    security.checkLockStatus(door);

    return 0;
}
