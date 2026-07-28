#include <stdio.h>
#include <string.h>
struct Student {
    int rollNumber;
    char name[100];
    int age;
    float cgpa;
};
int main(void) {
    struct Student student;
    printf("Enter roll number: ");
    scanf("%d", &student.rollNumber);
    getchar();
    printf("Enter name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0';
    printf("Enter age: ");
    scanf("%d", &student.age);
    printf("Enter CGPA: ");
    scanf("%f", &student.cgpa);
    printf("\nStudent Information:-\n");
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("CGPA: %.2f\n", student.cgpa);
    return 0;
}