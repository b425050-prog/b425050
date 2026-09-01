// Lab 6, Program 2: Water Tank Level
// Reads and updates a water level through a pointer.

#include <iostream>

int main() {
    double waterLevelLitres = 0.0;
    double waterAddedLitres = 0.0;
    double waterRemovedLitres = 0.0;

    std::cout << "Enter the current water level in litres: ";
    if (!(std::cin >> waterLevelLitres) || waterLevelLitres < 0.0) {
        std::cerr << "Water level cannot be negative.\n";
        return 1;
    }

    double* waterLevelPointer = &waterLevelLitres;
    std::cout << "Current water level : " << *waterLevelPointer << " litres\n";

    std::cout << "Enter the amount of water added: ";
    if (!(std::cin >> waterAddedLitres) || waterAddedLitres < 0.0) {
        std::cerr << "Added amount cannot be negative.\n";
        return 1;
    }
    *waterLevelPointer += waterAddedLitres;

    std::cout << "Enter the amount of water removed: ";
    if (!(std::cin >> waterRemovedLitres) || waterRemovedLitres < 0.0 ||
        waterRemovedLitres > *waterLevelPointer) {
        std::cerr << "Removed amount must be valid for the current level.\n";
        return 1;
    }
    *waterLevelPointer -= waterRemovedLitres;

    std::cout << "Final water level   : " << *waterLevelPointer << " litres\n";
    return 0;
}
