#include <stdio.h>
struct Student {
    int registrationNumber;
    char name[100];
    int cProgramming;
    int mathematics;
    int physics;
};
int main() {
    struct Student record;
    int sum;
    float mean;
    printf("Enter roll number: ");
    scanf("%d", &record.registrationNumber);
    printf("Enter student name: ");
    scanf("%99s", record.name);
    printf("Enter marks in C: ");
    scanf("%d", &record.cProgramming);
    printf("Enter marks in Mathematics: ");
    scanf("%d", &record.mathematics);
    printf("Enter marks in Physics: ");
    scanf("%d", &record.physics);
    sum = record.cProgramming + record.mathematics + record.physics;
    mean = sum / 3.0f;
    printf("\n========== MARKSHEET ==========\n");
    printf("Roll Number : %d\n", record.registrationNumber);
    printf("Name        : %s\n", record.name);
    printf("C           : %d\n", record.cProgramming);
    printf("Mathematics : %d\n", record.mathematics);
    printf("Physics     : %d\n", record.physics);
    printf("Total       : %d\n", sum);
    printf("Average     : %.2f\n", mean);
    printf("===============================\n");
    return 0;
}