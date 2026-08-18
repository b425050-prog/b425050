#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class FoodOrder {
private:
    int orderId;
    string foodItem;
    int quantity;
    double price;

public:
    FoodOrder(int id, string item, int qty, double itemPrice) {
        orderId = id;
        foodItem = item;
        quantity = qty;
        price = itemPrice;
    }

    // Friend function calculates the bill using private members
    friend void calculateBill(const FoodOrder &order);
};

void calculateBill(const FoodOrder &order) {
    double totalBill = order.quantity * order.price;

    cout << fixed << setprecision(2);
    cout << "\n--- Food Order Details ---\n";
    cout << "Order ID   : " << order.orderId << '\n';
    cout << "Food Item  : " << order.foodItem << '\n';
    cout << "Quantity   : " << order.quantity << '\n';
    cout << "Price      : Rs. " << order.price << '\n';
    cout << "Total Bill : Rs. " << totalBill << '\n';
}

int main() {
    int orderId, quantity;
    string foodItem;
    double price;

    cout << "Enter order ID: ";
    cin >> orderId;
    cin.ignore();

    cout << "Enter food item: ";
    getline(cin, foodItem);

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter price per item: ";
    cin >> price;

    FoodOrder order(orderId, foodItem, quantity, price);
    calculateBill(order);

    return 0;
}
