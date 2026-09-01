// Lab 6, Program 3: Sports Equipment Rack
// Traverses an array using pointer arithmetic and prints each address.

#include <iostream>

int main() {
    constexpr int equipmentCount = 6;
    int equipmentIds[equipmentCount]{};
    int* firstEquipment = equipmentIds;

    std::cout << "Enter " << equipmentCount << " equipment IDs:\n";
    for (int offset = 0; offset < equipmentCount; ++offset) {
        if (!(std::cin >> *(firstEquipment + offset))) {
            std::cerr << "Please enter integer equipment IDs only.\n";
            return 1;
        }
    }

    std::cout << "\nEquipment rack\n"
              << "----------------------------------------\n";
    for (int offset = 0; offset < equipmentCount; ++offset) {
        int* currentEquipment = firstEquipment + offset;
        std::cout << "Equipment " << offset + 1 << " | ID: "
                  << *currentEquipment << " | Address: " << currentEquipment
                  << '\n';
    }

    return 0;
}
