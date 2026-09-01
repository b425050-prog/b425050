// Lab 6, Program 4: Train Seat Correction
// Corrects a seat number without using seatNumbers[position].

#include <iostream>

void displaySeats(const int* firstSeat, int seatCount) {
    for (int offset = 0; offset < seatCount; ++offset) {
        std::cout << *(firstSeat + offset) << ' ';
    }
    std::cout << '\n';
}

int main() {
    constexpr int seatCount = 8;
    int seatNumbers[seatCount]{};

    std::cout << "Enter " << seatCount << " recorded seat numbers:\n";
    for (int offset = 0; offset < seatCount; ++offset) {
        if (!(std::cin >> *(seatNumbers + offset))) {
            std::cerr << "Please enter integer seat numbers only.\n";
            return 1;
        }
    }

    std::cout << "Before correction : ";
    displaySeats(seatNumbers, seatCount);

    int seatPosition = 0;
    int correctedSeatNumber = 0;
    std::cout << "Enter the position to correct (1-" << seatCount << "): ";
    if (!(std::cin >> seatPosition) || seatPosition < 1 ||
        seatPosition > seatCount) {
        std::cerr << "Position must be between 1 and " << seatCount << ".\n";
        return 1;
    }

    std::cout << "Enter the corrected seat number: ";
    if (!(std::cin >> correctedSeatNumber)) {
        std::cerr << "Please enter a valid integer seat number.\n";
        return 1;
    }

    // Convert the user's 1-based position into a pointer offset.
    *(seatNumbers + seatPosition - 1) = correctedSeatNumber;

    std::cout << "After correction  : ";
    displaySeats(seatNumbers, seatCount);
    return 0;
}
