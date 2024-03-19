#include <stdio.h>
struct Process {
    char name;
    int arrival_time;
    int burst_time;
    int remaining_time;
};
int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter process name, arrival time, and burst time: ");
        scanf(" %c %d %d", &processes[i].name, &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    int current_time = 0;
    printf("Gantt Chart:\n");
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = 0;
                int execute_time = quantum < processes[i].remaining_time ? quantum : processes[i].remaining_time;
                printf("%c ", processes[i].name);
                current_time += execute_time;
                processes[i].remaining_time -= execute_time;
            }
        }
        if (done) {
            break;
        }
    }
    printf("\n");
    return 0;
}
