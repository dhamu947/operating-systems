#include <stdio.h>
#include <stdlib.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    FILE *filePtr;
    struct Employee emp;
    filePtr = fopen("employees.dat", "rb+");

    if (filePtr == NULL) {
        filePtr = fopen("employees.dat", "wb+");
        if (filePtr == NULL) {
            printf("Error in file creation!");
            exit(1);
        }
    }

    rewind(filePtr);

    printf("Enter employee ID, name, and salary: ");
    scanf("%d %s %f", &emp.id, emp.name, &emp.salary);

    fseek(filePtr, (emp.id - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, filePtr);

    printf("\nEnter employee ID to retrieve details: ");
    int searchId;
    scanf("%d", &searchId);

    fseek(filePtr, (searchId - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, filePtr);

    printf("\nEmployee details:\n");
    printf("ID: %d\nName: %s\nSalary: %.2f\n", emp.id, emp.name, emp.salary);

    // Close file
    fclose(filePtr);

    return 0;
}
