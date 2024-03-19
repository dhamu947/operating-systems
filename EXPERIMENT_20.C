#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

sem_t mutex, wrt;
int readers_count = 0;

void *reader(void *arg) {
    int reader_id = *((int *)arg);
    while (1) {
        usleep(rand() % 1000000); // Sleep for a random time
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mutex);
        printf("Reader %d: Reading data\n", reader_id);
        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&wrt);
        }
        sem_post(&mutex);
    }
}

void *writer(void *arg) {
    int writer_id = *((int *)arg);
    while (1) {
        usleep(rand() % 1000000); // Sleep for a random time
        sem_wait(&wrt);
        printf("Writer %d: Writing data\n", writer_id);
        sem_post(&wrt);
    }
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int i;

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (i = 0; i < NUM_READERS; i++)
        pthread_create(&readers[i], NULL, reader, (void *)&i);

    for (i = 0; i < NUM_WRITERS; i++)
        pthread_create(&writers[i], NULL, writer, (void *)&i);

    for (i = 0; i < NUM_READERS; i++)
        pthread_join(readers[i], NULL);

    for (i = 0; i < NUM_WRITERS; i++)
        pthread_join(writers[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
