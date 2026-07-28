#include <stdio.h>
struct Employee {
    int emp_id;
    char emp_name[100];
    float salary;
};
int main() {
    struct Employee staff[3];
    int i;
    printf("Enter details of 3 employees:\n");
    for (i = 0; i < 3; i++) {
        printf("\nEnter details of Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &staff[i].emp_id);
        printf("Name: ");
        scanf("%99s", staff[i].emp_name);
        printf("Salary: ");
        scanf("%f", &staff[i].salary);
    }
    printf("\nEmployee Details:\n");
    for (i = 0; i < 3; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("ID: %d\n", staff[i].emp_id);
        printf("Name: %s\n", staff[i].emp_name);
        printf("Salary: %.2f\n", staff[i].salary);
    }
    return 0;
}