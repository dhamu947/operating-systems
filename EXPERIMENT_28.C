#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    // Check if filename and search string are provided
    if (argc < 3) {
        printf("Usage: %s <search_string> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *searchString = argv[1];
    char *filename = argv[2];
    char line[MAX_LINE_LENGTH];
    FILE *file;

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read each line from the file and search for the search string
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, searchString) != NULL) {
            printf("%s", line); // Print the line if search string is found
        }
    }

    // Close the file
    fclose(file);

    return 0;
}
