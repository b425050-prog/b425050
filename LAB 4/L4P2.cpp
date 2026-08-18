#include <iostream>
#include <string>
using namespace std;

class Mobile {
private:
    string brand;
    string model;
    int batteryPercentage;

public:
    Mobile(string mobileBrand, string mobileModel, int battery) {
        brand = mobileBrand;
        model = mobileModel;
        batteryPercentage = battery;
    }

    // Friend function is allowed to read private mobile details
    friend void checkBattery(const Mobile &mobile);
};

void checkBattery(const Mobile &mobile) {
    cout << "\n--- Mobile Details ---\n";
    cout << "Brand              : " << mobile.brand << '\n';
    cout << "Model              : " << mobile.model << '\n';
    cout << "Battery Percentage : " << mobile.batteryPercentage << "%\n";

    if (mobile.batteryPercentage < 20)
        cout << "Battery Status     : Battery Low\n";
    else
        cout << "Battery Status     : Battery Normal\n";
}

int main() {
    string brand, model;
    int batteryPercentage;

    cout << "Enter mobile brand: ";
    getline(cin, brand);

    cout << "Enter mobile model: ";
    getline(cin, model);

    cout << "Enter battery percentage: ";
    cin >> batteryPercentage;

    Mobile phone(brand, model, batteryPercentage);
    checkBattery(phone);

    return 0;
}
