#include <iostream>
#include <string>
using namespace std;

class ParkingSlot {
private:
    int slotNumber;
    string vehicleNumber;
    bool isOccupied;

public:
    ParkingSlot(int slot, string vehicle, bool occupied) {
        slotNumber = slot;
        vehicleNumber = vehicle;
        isOccupied = occupied;
    }

    // Friend function checks private occupancy details
    friend void checkSlot(const ParkingSlot &slot);
};

void checkSlot(const ParkingSlot &slot) {
    cout << "\n--- Parking Slot Details ---\n";
    cout << "Slot Number : " << slot.slotNumber << '\n';

    if (slot.isOccupied) {
        cout << "Status      : Occupied\n";
        cout << "Vehicle No. : " << slot.vehicleNumber << '\n';
    } else {
        cout << "Status      : Available\n";
    }
}

int main() {
    int slotNumber, occupancyChoice;
    string vehicleNumber = "";

    cout << "Enter slot number: ";
    cin >> slotNumber;

    cout << "Is the slot occupied? (1 for Yes, 0 for No): ";
    cin >> occupancyChoice;
    cin.ignore();

    bool isOccupied = (occupancyChoice == 1);

    if (isOccupied) {
        cout << "Enter vehicle number: ";
        getline(cin, vehicleNumber);
    }

    ParkingSlot slot(slotNumber, vehicleNumber, isOccupied);
    checkSlot(slot);

    return 0;
}
