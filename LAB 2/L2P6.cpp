#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    void input() {
        cout << "Enter feet: ";
        cin >> feet;

        cout << "Enter inches: ";
        cin >> inches;
    }

    Distance add(Distance secondDistance) {
        Distance result;

        result.feet = feet + secondDistance.feet;
        result.inches = inches + secondDistance.inches;

        if (result.inches >= 12) {
            result.feet = result.feet + result.inches / 12;
            result.inches = result.inches % 12;
        }

        return result;
    }

    void display() {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main() {
    Distance distance1;
    Distance distance2;
    Distance totalDistance;

    cout << "Enter first distance\n";
    distance1.input();

    cout << "\nEnter second distance\n";
    distance2.input();

    totalDistance = distance1.add(distance2);

    cout << "\nTotal Distance: ";
    totalDistance.display();

    return 0;
}