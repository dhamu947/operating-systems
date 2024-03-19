#include<stdio.h>
struct Process {
    char name;
    int arrival_time, burst_time;
};
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for(int i = 0; i < n; i++) {
        printf("Enter process name, arrival time, and burst time: ");
        scanf(" %c %d %d", &processes[i].name, &processes[i].arrival_time, &processes[i].burst_time);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(processes[i].arrival_time > processes[j].arrival_time) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    int current_time = 0;
    printf("Gantt Chart:\n");
    for(int i = 0; i < n; i++) {
        printf("%c ", processes[i].name);
        current_time += processes[i].burst_time;
    }
    printf("\n");
    return 0;
}
