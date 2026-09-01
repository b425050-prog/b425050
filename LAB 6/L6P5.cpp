// Lab 6, Program 5: Online Order Status
// Passes the status address to a function that updates the original value.

#include <iostream>
#include <string>

void updateStatus(int* status) {
    if (*status == 1) {
        *status = 2;  // Processing becomes Shipped.
    } else if (*status == 2) {
        *status = 3;  // Shipped becomes Delivered.
    }
}

std::string statusLabel(int status) {
    switch (status) {
        case 1:
            return "Processing";
        case 2:
            return "Shipped";
        case 3:
            return "Delivered";
        default:
            return "Invalid";
    }
}

int main() {
    int orderStatus = 0;
    std::cout << "Status codes: 1=Processing, 2=Shipped, 3=Delivered\n"
              << "Enter the current status code: ";

    if (!(std::cin >> orderStatus) || orderStatus < 1 || orderStatus > 3) {
        std::cerr << "Status code must be 1, 2, or 3.\n";
        return 1;
    }

    std::cout << "Before update : " << statusLabel(orderStatus) << '\n';
    updateStatus(&orderStatus);
    std::cout << "After update  : " << statusLabel(orderStatus) << '\n';
    return 0;
}
