#include <stdio.h>
struct Product {
    int productCode;
    char productName[100];
    float unitPrice;
    int stock;
};
int main() {
    struct Product item;
    float totalAmount;
    printf("Enter Product ID: ");
    scanf("%d", &item.productCode);
    printf("Enter Product Name: ");
    scanf("%99s", item.productName);
    printf("Enter Price: ");
    scanf("%f", &item.unitPrice);
    printf("Enter Quantity: ");
    scanf("%d", &item.stock);
    totalAmount = item.unitPrice * item.stock;
    printf("\n========== PRODUCT DETAILS ==========\n");
    printf("Product ID   : %d\n", item.productCode);
    printf("Product Name : %s\n", item.productName);
    printf("Price        : %.2f\n", item.unitPrice);
    printf("Quantity     : %d\n", item.stock);
    printf("Total Cost   : %.2f\n", totalAmount);
    printf("=====================================\n");
    return 0;
}