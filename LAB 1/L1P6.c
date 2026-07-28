#include <stdio.h>
struct Distance {
    int feet;
    int inches;
};
int main() {
    struct Distance first, second, total;
    printf("Enter first distance in feet and inches: ");
    scanf("%d %d", &first.feet, &first.inches);
    printf("Enter second distance in feet and inches: ");
    scanf("%d %d", &second.feet, &second.inches);
    total.feet = first.feet + second.feet;
    total.inches = first.inches + second.inches;
    printf("\nTotal Distance\n");
    printf("Feet   : %d\n", total.feet);
    printf("Inches : %d\n", total.inches);
    return 0;
}