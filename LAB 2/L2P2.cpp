#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float breadth;

public:
    void input() {
        cout << "Enter length: ";
        cin >> length;

        cout << "Enter breadth: ";
        cin >> breadth;
    }

    float calculateArea() {
        return length * breadth;
    }

    float calculatePerimeter() {
        return 2 * (length + breadth);
    }

    void display() {
        cout << "\nRectangle Details\n";
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    Rectangle rectangle;

    rectangle.input();
    rectangle.display();

    return 0;
}