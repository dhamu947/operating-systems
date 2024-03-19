#include<stdio.h>
struct Process {
    char name;
    int arrival_time, burst_time, priority;
};
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for(int i = 0; i < n; i++) {
        printf("Enter process name, arrival time, burst time, and priority: ");
        scanf(" %c %d %d %d", &processes[i].name, &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    }
    int current_time = 0;
    int total_burst = 0;
    for(int i = 0; i < n; i++) {
        total_burst += processes[i].burst_time;
    }
    printf("Gantt Chart:\n");
    while(total_burst > 0) {
        int highest_priority = -1;
        int selected_process = -1;
        for(int i = 0; i < n; i++) {
            if(processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
                if(highest_priority == -1 || processes[i].priority < highest_priority) {
                    highest_priority = processes[i].priority;
                    selected_process = i;
                }
            }
        }
        if(selected_process == -1) {
            printf("IDLE ");
            current_time++;
        } else {
            printf("%c ", processes[selected_process].name);
            processes[selected_process].burst_time--;
            current_time++;
            total_burst--;
        }
    }
    printf("\n");
    return 0;
}
