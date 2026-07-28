#include <stdio.h>
#include <string.h>
struct Book {
    int bookCode;
    char bookName[100];
    char writerName[100];
    float cost;
};
int main() {
    struct Book record;
    printf("Enter book ID: ");
    scanf("%d", &record.bookCode);
    getchar();
    printf("Enter title: ");
    fgets(record.bookName, sizeof(record.bookName), stdin);
    record.bookName[strcspn(record.bookName, "\n")] = '\0';
    printf("Enter author name: ");
    fgets(record.writerName, sizeof(record.writerName), stdin);
    record.writerName[strcspn(record.writerName, "\n")] = '\0';
    printf("Enter price: ");
    scanf("%f", &record.cost);
    printf("\n========== BOOK RECORD ==========\n");
    printf("ID          : %d\n", record.bookCode);
    printf("Title       : %s\n", record.bookName);
    printf("Written By  : %s\n", record.writerName);
    printf("Price       : %.2f\n", record.cost);
    return 0;
}