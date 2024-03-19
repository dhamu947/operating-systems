#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>  
#include <string.h>
#define SHM_SIZE 1024
int main() {
    key_t key = ftok("/tmp", 'A');
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    char *shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {  
        strcpy(shm, "Hello, shared memory!");
        exit(0);
    } else { 
        wait(NULL);
        printf("Message read from shared memory: %s\n", shm);
    }
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
