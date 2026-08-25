// Lab 5, Program 4: Element Search
// The array type and optional range parameters select the required overload.

#include <array>
#include <cstddef>
#include <iostream>

constexpr std::size_t MAX_ELEMENTS = 50;

int search(const int values[], std::size_t size, int target) {
    for (std::size_t index = 0; index < size; ++index) {
        if (values[index] == target) {
            return static_cast<int>(index);
        }
    }
    return -1;
}

int search(const char values[], std::size_t size, char target) {
    for (std::size_t index = 0; index < size; ++index) {
        if (values[index] == target) {
            return static_cast<int>(index);
        }
    }
    return -1;
}

// This overload searches an inclusive, zero-based index range.
int search(const int values[], std::size_t size, int target,
           std::size_t startIndex, std::size_t endIndex) {
    if (size == 0 || startIndex >= size || startIndex > endIndex) {
        return -1;
    }

    // Clamp the last index so the function remains safe for any caller.
    if (endIndex >= size) {
        endIndex = size - 1;
    }

    for (std::size_t index = startIndex; index <= endIndex; ++index) {
        if (values[index] == target) {
            return static_cast<int>(index);
        }
    }
    return -1;
}

void displayResult(const char label[], int index) {
    std::cout << label;
    if (index == -1) {
        std::cout << "not found\n";
    } else {
        // Add one because positions shown to the user begin at 1.
        std::cout << "found at position " << index + 1 << '\n';
    }
}

int main() {
    std::array<int, MAX_ELEMENTS> integerValues{};
    std::array<char, MAX_ELEMENTS> characterValues{};
    std::size_t integerCount = 0;
    std::size_t characterCount = 0;
    int integerTarget = 0;
    int rangeTarget = 0;
    char characterTarget = '\0';
    std::size_t startPosition = 0;
    std::size_t endPosition = 0;

    std::cout << "========================================\n"
              << "          ELEMENT SEARCH - LAB 5        \n"
              << "========================================\n";

    std::cout << "Number of integers (1-" << MAX_ELEMENTS << "): ";
    if (!(std::cin >> integerCount) || integerCount == 0 ||
        integerCount > MAX_ELEMENTS) {
        std::cerr << "Invalid size. Enter a value from 1 to "
                  << MAX_ELEMENTS << ".\n";
        return 1;
    }

    std::cout << "Enter " << integerCount << " integer value(s): ";
    for (std::size_t index = 0; index < integerCount; ++index) {
        if (!(std::cin >> integerValues[index])) {
            std::cerr << "Invalid input. Please enter integer values only.\n";
            return 1;
        }
    }

    std::cout << "Integer to search in the whole array: ";
    if (!(std::cin >> integerTarget)) {
        std::cerr << "Invalid input. Please enter an integer.\n";
        return 1;
    }

    std::cout << "Number of characters (1-" << MAX_ELEMENTS << "): ";
    if (!(std::cin >> characterCount) || characterCount == 0 ||
        characterCount > MAX_ELEMENTS) {
        std::cerr << "Invalid size. Enter a value from 1 to "
                  << MAX_ELEMENTS << ".\n";
        return 1;
    }

    std::cout << "Enter " << characterCount
              << " character(s), separated by spaces: ";
    for (std::size_t index = 0; index < characterCount; ++index) {
        if (!(std::cin >> characterValues[index])) {
            std::cerr << "Invalid character input.\n";
            return 1;
        }
    }

    std::cout << "Character to search: ";
    if (!(std::cin >> characterTarget)) {
        std::cerr << "Invalid character input.\n";
        return 1;
    }

    std::cout << "Integer to search within a range: ";
    if (!(std::cin >> rangeTarget)) {
        std::cerr << "Invalid input. Please enter an integer.\n";
        return 1;
    }

    std::cout << "Enter the start and end positions (1-" << integerCount
              << "): ";
    if (!(std::cin >> startPosition >> endPosition) || startPosition == 0 ||
        endPosition == 0 || startPosition > endPosition ||
        endPosition > integerCount) {
        std::cerr << "Invalid range. Positions must lie within the array.\n";
        return 1;
    }

    const int integerIndex =
        search(integerValues.data(), integerCount, integerTarget);
    const int characterIndex =
        search(characterValues.data(), characterCount, characterTarget);
    const int rangeIndex =
        search(integerValues.data(), integerCount, rangeTarget,
               startPosition - 1, endPosition - 1);

    std::cout << "\n--------------- RESULTS ----------------\n";
    displayResult("Integer search   : ", integerIndex);
    displayResult("Character search : ", characterIndex);
    displayResult("Range search     : ", rangeIndex);
    std::cout << "========================================\n";

    return 0;
}
