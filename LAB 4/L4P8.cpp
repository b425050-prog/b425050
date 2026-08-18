#include <iostream>
#include <string>
using namespace std;

class TicketChecker;

class TrainSeat {
private:
    int seatNumber;
    string passengerName;
    bool isBooked;

public:
    TrainSeat(int seat, string passenger, bool bookingStatus) {
        seatNumber = seat;
        passengerName = passenger;
        isBooked = bookingStatus;
    }

    friend class TicketChecker;
};

class TicketChecker {
public:
    void displaySeatDetails(const TrainSeat &seat) {
        cout << "\n--- Train Seat Details ---\n";
        cout << "Seat Number : " << seat.seatNumber << '\n';
    }

    void checkBooking(const TrainSeat &seat) {
        if (seat.isBooked) {
            cout << "Seat Status : Booked\n";
            cout << "Passenger   : " << seat.passengerName << '\n';
        } else {
            cout << "Seat Status : Available\n";
        }
    }
};

int main() {
    int seatNumber, bookingChoice;
    string passengerName = "";

    cout << "Enter seat number: ";
    cin >> seatNumber;

    cout << "Is the seat booked? (1 for Yes, 0 for No): ";
    cin >> bookingChoice;
    cin.ignore();

    bool isBooked = (bookingChoice == 1);

    if (isBooked) {
        cout << "Enter passenger name: ";
        getline(cin, passengerName);
    }

    TrainSeat seat(seatNumber, passengerName, isBooked);
    TicketChecker checker;

    checker.displaySeatDetails(seat);
    checker.checkBooking(seat);

    return 0;
}
