#include <stdio.h>
struct Employee {
    char employeeName[100];
    float monthlySalary;
};
int main() {
    struct Employee staff[5];
    int highestIndex = 0;
    printf("Enter details of 5 employees:\n");
    for (int index = 0; index < 5; index++) {
        printf("\nEmployee %d\n", index + 1);
        printf("Enter name: ");
        scanf("%99s", staff[index].employeeName);
        printf("Enter salary: ");
        scanf("%f", &staff[index].monthlySalary);
    }
    for (int index = 1; index < 5; index++) {
        if (staff[index].monthlySalary >
            staff[highestIndex].monthlySalary) {
            highestIndex = index;
        }
    }
    printf("\n===== HIGHEST PAID EMPLOYEE =====\n");
    printf("Name   : %s\n", staff[highestIndex].employeeName);
    printf("Salary : %.2f\n", staff[highestIndex].monthlySalary);
    printf("=================================\n");
    return 0;
}