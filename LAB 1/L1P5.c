#include <stdio.h>
struct Rectangle {
    int width;
    int height;
};
int main() {
    struct Rectangle box;
    int surfaceArea;
    int boundaryLength;
    printf("Enter length: ");
    scanf("%d", &box.height);
    printf("Enter breadth: ");
    scanf("%d", &box.width);
    surfaceArea = box.height * box.width;
    boundaryLength = 2 * (box.height + box.width);
    printf("\n----- RECTANGLE RESULT -----\n");
    printf("Length    : %d\n", box.height);
    printf("Breadth   : %d\n", box.width);
    printf("Area      : %d\n", surfaceArea);
    printf("Perimeter : %d\n", boundaryLength);
    return 0;
}
