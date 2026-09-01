// Lab 6, Program 1: Mobile Battery Update
// Modifies the battery percentage only through a pointer.

#include <algorithm>
#include <iostream>

int main() {
    int batteryPercentage = 0;
    int chargingIncrease = 0;

    std::cout << "Enter the current battery percentage: ";
    if (!(std::cin >> batteryPercentage) || batteryPercentage < 0 ||
        batteryPercentage > 100) {
        std::cerr << "Battery percentage must be between 0 and 100.\n";
        return 1;
    }

    int* batteryPointer = &batteryPercentage;
    std::cout << "Current battery level : " << *batteryPointer << "%\n";

    std::cout << "Enter the percentage gained after charging: ";
    if (!(std::cin >> chargingIncrease) || chargingIncrease < 0) {
        std::cerr << "Charging increase cannot be negative.\n";
        return 1;
    }

    // The original battery variable is changed only through this pointer.
    *batteryPointer = std::min(100, *batteryPointer + chargingIncrease);

    std::cout << "Updated battery level : " << *batteryPointer << "%\n";
    return 0;
}
