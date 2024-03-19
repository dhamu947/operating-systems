#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2

void *thread_function(void *arg) {
    int thread_number = *((int *)arg);
    printf("Thread %d is executing...\n", thread_number);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    // Creating threads
    for (i = 0; i < NUM_THREADS; ++i) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void *)&thread_args[i]);
    }

    // Joining threads
    for (i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
        printf("Thread %d has joined.\n", i);
    }

    // Checking if threads are equal
    if (pthread_equal(threads[0], threads[1])) {
        printf("Threads are equal.\n");
    } else {
        printf("Threads are not equal.\n");
    }

    printf("Main thread exiting...\n");
    pthread_exit(NULL);
}
