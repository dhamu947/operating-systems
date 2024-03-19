#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *dp;

    // Open the current directory if no directory is specified
    if (argc == 1) {
        dir = opendir(".");
        if (dir == NULL) {
            perror("opendir");
            exit(EXIT_FAILURE);
        }
    } else {
        // Open the specified directory
        dir = opendir(argv[1]);
        if (dir == NULL) {
            perror("opendir");
            exit(EXIT_FAILURE);
        }
    }

    // Read and print directory contents
    while ((dp = readdir(dir)) != NULL) {
        printf("%s\n", dp->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
