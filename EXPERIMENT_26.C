#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    char buffer[100];

    // Creating a new file
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    printf("File '%s' created successfully.\n", filename);

    // Writing data to the file
    fprintf(file, "Hello, this is some data written to the file.\n");
    printf("Data written to file.\n");

    // Closing the file
    fclose(file);
    printf("File closed.\n");

    // Opening the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Reading data from the file
    printf("\nData read from file:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Closing the file
    fclose(file);

    // Appending data to the file
    file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "This data is appended to the file.\n");
    printf("\nData appended to file.\n");

    fclose(file);

    return 0;
}
