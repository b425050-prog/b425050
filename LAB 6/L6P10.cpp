// Lab 6, Program 10: Contact Number Search
// Searches dynamic memory with a pointer and no array indexing.

#include <iostream>

int main() {
    int contactCount = 0;
    std::cout << "Enter the number of contacts: ";
    if (!(std::cin >> contactCount) || contactCount <= 0) {
        std::cerr << "Contact count must be positive.\n";
        return 1;
    }

    // long long accommodates common 10-digit telephone numbers.
    long long* contactNumbers = new long long[contactCount];
    std::cout << "Enter " << contactCount << " contact numbers:\n";

    for (long long* currentContact = contactNumbers;
         currentContact < contactNumbers + contactCount; ++currentContact) {
        if (!(std::cin >> *currentContact)) {
            std::cerr << "Please enter numeric contact numbers only.\n";
            delete[] contactNumbers;
            return 1;
        }
    }

    long long numberToFind = 0;
    std::cout << "Enter the contact number to search for: ";
    if (!(std::cin >> numberToFind)) {
        std::cerr << "Please enter a numeric contact number.\n";
        delete[] contactNumbers;
        return 1;
    }

    int foundPosition = -1;
    for (const long long* currentContact = contactNumbers;
         currentContact < contactNumbers + contactCount; ++currentContact) {
        if (*currentContact == numberToFind) {
            // Pointer subtraction gives the offset from the first element.
            foundPosition =
                static_cast<int>(currentContact - contactNumbers) + 1;
            break;
        }
    }

    if (foundPosition == -1) {
        std::cout << "Contact number not found.\n";
    } else {
        std::cout << "Contact number found at position " << foundPosition
                  << ".\n";
    }

    delete[] contactNumbers;
    contactNumbers = nullptr;
    return 0;
}
