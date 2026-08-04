#include <iostream>
#include <string>
using namespace std;

class ElectricityBill {
private:
    long long consumerNumber;
    string consumerName;
    int unitsConsumed;
    float billAmount;

public:
    void input() {
        cout << "Enter consumer number: ";
        cin >> consumerNumber;

        cin.ignore();
        cout << "Enter consumer name: ";
        getline(cin, consumerName);

        cout << "Enter units consumed: ";
        cin >> unitsConsumed;
    }

    void calculateBill() {
        if (unitsConsumed <= 100) {
            billAmount = unitsConsumed * 5;
        } else if (unitsConsumed <= 200) {
            billAmount = (100 * 5) + ((unitsConsumed - 100) * 7);
        } else {
            billAmount = (100 * 5) + (100 * 7)
                         + ((unitsConsumed - 200) * 10);
        }
    }

    void display() {
        cout << "\nElectricity Bill\n";
        cout << "Consumer Number: " << consumerNumber << endl;
        cout << "Consumer Name: " << consumerName << endl;
        cout << "Units Consumed: " << unitsConsumed << endl;
        cout << "Total Bill Amount: Rs. " << billAmount << endl;
    }
};

int main() {
    ElectricityBill bill;

    bill.input();
    bill.calculateBill();
    bill.display();

    return 0;
}