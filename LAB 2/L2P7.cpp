#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    int quantity;
    float pricePerUnit;

public:
    void input() {
        cout << "Enter product ID: ";
        cin >> productId;

        cin.ignore();
        cout << "Enter product name: ";
        getline(cin, productName);

        cout << "Enter quantity available: ";
        cin >> quantity;

        cout << "Enter price per unit: ";
        cin >> pricePerUnit;
    }

    void sellProduct(int unitsSold) {
        if (unitsSold <= 0) {
            cout << "Invalid number of units.\n";
        } else if (unitsSold > quantity) {
            cout << "Not enough stock available.\n";
        } else {
            quantity = quantity - unitsSold;
            cout << "Product sold successfully.\n";
        }
    }

    float calculateInventoryValue() {
        return quantity * pricePerUnit;
    }

    void display() {
        cout << "\nProduct Details\n";
        cout << "Product ID: " << productId << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Quantity Available: " << quantity << endl;
        cout << "Price Per Unit: Rs. " << pricePerUnit << endl;
        cout << "Total Inventory Value: Rs. "
             << calculateInventoryValue() << endl;
    }
};

int main() {
    Product product;
    int unitsSold;

    product.input();

    cout << "Enter number of units sold: ";
    cin >> unitsSold;

    product.sellProduct(unitsSold);
    product.display();

    return 0;
}