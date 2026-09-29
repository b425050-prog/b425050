// Lab 6, Program 10: Shopping Cart Calculator
// OOP Laboratory - Group B2 - 29 September 2026

#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

class Product {
    std::string name;
    double price;
    long long quantity;
public:
    Product(const std::string& n, double p, long long q) : name(n), price(p), quantity(q) {}
    Product operator+(const Product& other) const {
        if (name != other.name || price != other.price) {
            throw std::invalid_argument("Cannot combine: name and price must both match.");
        }
        return Product(name, price, quantity + other.quantity);
    }
    bool operator>(const Product& other) const {
        return price * quantity > other.price * other.quantity;
    }
    void display() const {
        std::cout << name << " | price: " << std::fixed << std::setprecision(2) << price
                  << " | quantity: " << quantity << " | total: " << price * quantity << '\n';
    }
};

int main() {
    std::string name1, name2;
    double price1, price2;
    int quantity1, quantity2;
    std::cout << "Enter first product name: ";
    if (!std::getline(std::cin >> std::ws, name1)) return 1;
    std::cout << "Enter price and quantity: ";
    if (!(std::cin >> price1 >> quantity1) || !std::isfinite(price1) ||
        price1 < 0 || price1 > 1e9 || quantity1 < 0 || quantity1 > 1000000000) {
        std::cerr << "Price and integer quantity must be between 0 and 1000000000.\n"; return 1;
    }
    std::cout << "Enter second product name: ";
    if (!std::getline(std::cin >> std::ws, name2)) return 1;
    std::cout << "Enter price and quantity: ";
    if (!(std::cin >> price2 >> quantity2) || !std::isfinite(price2) ||
        price2 < 0 || price2 > 1e9 || quantity2 < 0 || quantity2 > 1000000000) {
        std::cerr << "Price and integer quantity must be between 0 and 1000000000.\n"; return 1;
    }
    const Product first(name1, price1, quantity1), second(name2, price2, quantity2);
    if (first > second) std::cout << "First product has a higher total value.\n";
    else if (second > first) std::cout << "Second product has a higher total value.\n";
    else std::cout << "Both products have equal total value.\n";
    try {
        const Product combined = first + second;
        std::cout << "Combined: "; combined.display();
    } catch (const std::invalid_argument& error) {
        std::cout << error.what() << '\n';
    }
    std::cout << "Original 1 (unchanged): "; first.display();
    std::cout << "Original 2 (unchanged): "; second.display();
}
