#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3
#define NUM_ITERATIONS 5

int shared_variable = 0;
pthread_mutex_t mutex;

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_mutex_lock(&mutex); // Lock the mutex before accessing the shared variable
        shared_variable++; // Increment the shared variable
        printf("Thread %d: Shared variable = %d\n", thread_id, shared_variable);
        pthread_mutex_unlock(&mutex); // Unlock the mutex after accessing the shared variable
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex); // Destroy the mutex
    return 0;
}
