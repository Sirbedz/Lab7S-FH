#include <stdio.h>
#include <string.h>

typedef struct student {
    int id;
    char name[50];
    float gpa;
} student;

int main() {
    int Nos, i;
    
    printf("Enter the number of students: ");
    scanf("%d", &Nos);

    student student1[Nos]; //

    for (i = 0; i < Nos; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Enter your ID: ");
        scanf("%d", &student1[i].id);

        printf("Enter your Name: ");
        scanf("%s", student1[i].name);

        printf("Enter your GPA: ");
        scanf("%f", &student1[i].gpa);
    }

    printf("\nStudent Records:\n");
    for (i = 0; i < Nos; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("ID: %d\n", student1[i].id);
        printf("Name: %s\n", student1[i].name);
        printf("GPA: %.2f\n", student1[i].gpa);
    }

    return 0;
}
