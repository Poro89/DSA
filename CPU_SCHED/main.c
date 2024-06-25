#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
 	int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n]; 

    for (i = 0; i < n; ++i) {
        processes[i].pid = 'A' + i;
        printf("Enter arrival time for process %c: ", processes[i].pid);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %c: ", processes[i].pid);
        scanf("%d", &processes[i].burst_time);
        processes[i].waiting_time = 0;  
        processes[i].turnaround_time = 0;
        processes[i].completion_time = 0;  
    }

    Queue q = {.front = NULL, .rear = NULL};
    int current_time = 0;

    for (i = 0; i < n; ++i) {
        while (current_time < processes[i].arrival_time) {
            current_time++;
        }
        enqueue(&q, processes[i]);
        current_time += processes[i].burst_time;
        Process completed_process = dequeue(&q);
        completed_process.completion_time = current_time;
        completed_process.waiting_time = completed_process.completion_time - completed_process.arrival_time - completed_process.burst_time;
        completed_process.turnaround_time = completed_process.completion_time - completed_process.arrival_time;
        processes[i] = completed_process; 
    }

    display_process_table(processes, n);

    float avg_waiting_time = calculate_average_waiting_time(processes, n);
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);

    return 0;
}
