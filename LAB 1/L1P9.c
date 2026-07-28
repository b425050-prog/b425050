#include <stdio.h>
struct Student {
    int rollNumber;
    char studentName[100];
    float cgpa;
};
int main() {
    struct Student list[5];
    printf("Enter details of 5 students:\n");
    for (int index = 0; index < 5; index++) {
        printf("\nStudent %d\n", index + 1);
        printf("Enter roll number: ");
        scanf("%d", &list[index].rollNumber);
        printf("Enter name: ");
        scanf("%99s", list[index].studentName);
        printf("Enter CGPA: ");
        scanf("%f", &list[index].cgpa);
    }
    printf("\nStudents with CGPA greater than or equal to 8.0:\n");
    printf("------------------------------------------------\n");
    for (int index = 0; index < 5; index++) {
        if (list[index].cgpa >= 8.0f) {
            printf("Roll Number : %d\n", list[index].rollNumber);
            printf("Name        : %s\n", list[index].studentName);
            printf("CGPA        : %.2f\n\n", list[index].cgpa);
        }
    }
    return 0;
}