#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    const char *data = "Hello, this is some data written to the file.\n";
    write(fd, data, strlen(data));

    char buffer[1024];
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, sizeof(buffer));

    printf("Data read from file: %s\n", buffer);

    close(fd);
    return 0;
}
