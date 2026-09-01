// Lab 6, Program 7: Text Analyzer
// Traverses a character array until its null terminator.

#include <cctype>
#include <iostream>

int main() {
    constexpr int maximumSentenceLength = 500;
    char sentence[maximumSentenceLength]{};

    std::cout << "Enter a sentence: ";
    std::cin.getline(sentence, maximumSentenceLength);

    int digitCount = 0;
    int alphabeticCount = 0;
    int spaceCount = 0;

    for (const char* currentCharacter = sentence;
         *currentCharacter != '\0'; ++currentCharacter) {
        const unsigned char safeCharacter =
            static_cast<unsigned char>(*currentCharacter);

        if (std::isdigit(safeCharacter)) {
            ++digitCount;
        } else if (std::isalpha(safeCharacter)) {
            ++alphabeticCount;
        } else if (*currentCharacter == ' ') {
            ++spaceCount;
        }
    }

    std::cout << "Digits                : " << digitCount << '\n'
              << "Alphabetic characters : " << alphabeticCount << '\n'
              << "Spaces                : " << spaceCount << '\n';
    return 0;
}
