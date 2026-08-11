#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    double price;
    int quantity;

public:
    // Accept details of one product.
    void acceptDetails() {
        cout << "Enter product ID: ";
        cin >> productId;
        cin.ignore();

        cout << "Enter product name: ";
        getline(cin, productName);

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter quantity: ";
        cin >> quantity;
    }

    // Cost contributed by this product to the cart.
    double getCost() const {
        return price * quantity;
    }

    // Display one product in table form.
    void displayDetails() const {
        cout << left << setw(10) << productId
             << setw(22) << productName
             << setw(12) << fixed << setprecision(2) << price
             << setw(10) << quantity
             << getCost() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of products in the cart: ";
    cin >> n;

    // Dynamically allocate an array of Product objects.
    Product *cart = new Product[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of product " << i + 1 << ":\n";
        cart[i].acceptDetails();
    }

    double totalAmount = 0.0;

    cout << "\nShopping Cart\n";
    cout << left << setw(10) << "ID"
         << setw(22) << "Product"
         << setw(12) << "Price"
         << setw(10) << "Quantity"
         << "Cost" << endl;

    for (int i = 0; i < n; i++) {
        cart[i].displayDetails();
        totalAmount += cart[i].getCost();
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Amount = " << totalAmount << endl;

    // Release the dynamically allocated product array.
    delete[] cart;
    cart = nullptr;

    return 0;
}
