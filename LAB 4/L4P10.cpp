#include <iostream>
#include <string>
using namespace std;

class HomeController;

class SmartDevice {
private:
    string deviceName;
    string deviceType;
    bool isPoweredOn;

public:
    SmartDevice(string name, string type, bool powerStatus) {
        deviceName = name;
        deviceType = type;
        isPoweredOn = powerStatus;
    }

    // HomeController can directly read and change device status
    friend class HomeController;
};

class HomeController {
public:
    void displayDeviceInfo(const SmartDevice &device) {
        cout << "\n--- Smart Device Information ---\n";
        cout << "Device Name : " << device.deviceName << '\n';
        cout << "Device Type : " << device.deviceType << '\n';
    }

    void turnOn(SmartDevice &device) {
        device.isPoweredOn = true;
        cout << device.deviceName << " has been turned ON.\n";
    }

    void turnOff(SmartDevice &device) {
        device.isPoweredOn = false;
        cout << device.deviceName << " has been turned OFF.\n";
    }

    void displayPowerStatus(const SmartDevice &device) {
        cout << "Power Status: "
             << (device.isPoweredOn ? "ON" : "OFF") << '\n';
    }
};

int main() {
    string deviceName, deviceType;
    int powerChoice, menuChoice;

    cout << "Enter device name: ";
    getline(cin, deviceName);

    cout << "Enter device type: ";
    getline(cin, deviceType);

    cout << "Enter initial power status (1 for ON, 0 for OFF): ";
    cin >> powerChoice;

    SmartDevice device(deviceName, deviceType, powerChoice == 1);
    HomeController controller;

    controller.displayDeviceInfo(device);
    controller.displayPowerStatus(device);

    cout << "\n1. Turn ON\n2. Turn OFF\nEnter your choice: ";
    cin >> menuChoice;

    if (menuChoice == 1)
        controller.turnOn(device);
    else if (menuChoice == 2)
        controller.turnOff(device);
    else
        cout << "Invalid choice.\n";

    controller.displayPowerStatus(device);

    return 0;
}
