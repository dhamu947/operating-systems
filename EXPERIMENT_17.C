#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int finish[MAX_PROCESSES];

int num_processes, num_resources;

void request_resources(int process_id, int request[]) {
    int i;
    for (i = 0; i < num_resources; i++) {
        if (request[i] > need[process_id][i] || request[i] > available[i]) {
            printf("Unsafe request\n");
            return;
        }
    }
    for (i = 0; i < num_resources; i++) {
        available[i] -= request[i];
        allocation[process_id][i] += request[i];
        need[process_id][i] -= request[i];
    }
    if (!isSafe(process_id)) {
        printf("Unsafe allocation\n");
        for (i = 0; i < num_resources; i++) {
            available[i] += request[i];
            allocation[process_id][i] -= request[i];
            need[process_id][i] += request[i];
        }
        return;
    }
    printf("Safe allocation\n");
}

int isSafe(int process_id) {
    int work[MAX_RESOURCES], finish_copy[MAX_PROCESSES];
    int i, j;
    for (i = 0; i < num_resources; i++)
        work[i] = available[i];
    for (i = 0; i < num_processes; i++)
        finish_copy[i] = finish[i];
    for (i = 0; i < num_resources; i++) {
        if (need[process_id][i] > work[i])
            return 0;
    }
    for (i = 0; i < num_resources; i++) {
        work[i] += allocation[process_id][i];
        finish[process_id] = 1;
    }
    for (i = 0; i < num_processes; i++) {
        if (!finish[i]) {
            for (j = 0; j < num_resources; j++) {
                if (need[i][j] > work[j])
                    break;
            }
            if (j == num_resources) {
                for (j = 0; j < num_resources; j++)
                    work[j] += allocation[i][j];
                finish[i] = 1;
                i = -1;
            }
        }
    }
    for (i = 0; i < num_processes; i++) {
        if (!finish[i])
            return 0;
    }
    return 1;
}

int main() {
    int i, j, request[MAX_RESOURCES];
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter number of resources: ");
    scanf("%d", &num_resources);
    printf("Enter available resources: ");
    for (i = 0; i < num_resources; i++)
        scanf("%d", &available[i]);
    printf("Enter maximum resources for each process:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < num_resources; j++) {
            scanf("%d", &maximum[i][j]);
            need[i][j] = maximum[i][j];
        }
    }
    printf("Enter allocated resources for each process:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] -= allocation[i][j];
        }
    }
    printf("Enter process id for resource request: ");
    scanf("%d", &i);
    printf("Enter resource request: ");
    for (j = 0; j < num_resources; j++)
        scanf("%d", &request[j]);
    request_resources(i, request);
    return 0;
}
