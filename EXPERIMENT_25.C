#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("File 'example.txt' opened successfully with file descriptor: %d\n", fd);

    off_t offset = lseek(fd, 0, SEEK_END);
    if (offset == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }
    printf("Current offset (end of file): %ld\n", (long)offset);

    struct stat fileStat;
    if (stat("example.txt", &fileStat) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    printf("File size: %ld bytes\n", (long)fileStat.st_size);

    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    printf("\nContents of current directory:\n");

    struct dirent *dirEntry;
    while ((dirEntry = readdir(dir)) != NULL) {
        printf("%s\n", dirEntry->d_name);
    }

    closedir(dir);
    close(fd);

    return 0;
}
