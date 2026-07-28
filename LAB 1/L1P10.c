#include <stdio.h>
struct Date {
    int day;
    int month;
    int year;
};
struct Student {
    int rollNo;
    char studentName[100];
    struct Date birthDate;
};
int main() {
    struct Student details;
    printf("Enter roll number: ");
    scanf("%d", &details.rollNo);
    printf("Enter student name: ");
    scanf("%99s", details.studentName);
    printf("Enter date of birth (DD MM YYYY): ");
    scanf("%d %d %d",
          &details.birthDate.day,
          &details.birthDate.month,
          &details.birthDate.year);
    printf("\n========== STUDENT INFORMATION ==========\n");
    printf("Roll Number   : %d\n", details.rollNo);
    printf("Name          : %s\n", details.studentName);
    printf("Date of Birth : %02d/%02d/%04d\n",
           details.birthDate.day,
           details.birthDate.month,
           details.birthDate.year);
    printf("=========================================\n");
    return 0;
}