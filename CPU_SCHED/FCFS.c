#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

void enqueue(Queue* q, Process data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Process dequeue(Queue* q) {
    if (q->front == NULL) {
        fprintf(stderr, "Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = q->front;
    Process data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int is_empty(Queue* q) {
    return (q->front == NULL);
}

float calculate_average_waiting_time(Process* processes, int n) {
    float total_waiting_time = 0;
    int i;
    for (i = 0; i < n; ++i) {
        total_waiting_time += processes[i].waiting_time;
    }
    return total_waiting_time / n;
}

void display_process_table(Process* processes, int n) {
	printf("\nCPU SCHEDULING\n");
    printf("\nProcess Table:\n");
    printf("---------------------------------------------------------------------------------------------\n");
    printf("| Process ID | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time |\n");
    printf("---------------------------------------------------------------------------------------------\n");
    int i;
    for (i = 0; i < n; ++i) {
        printf("| %10c | %12d | %10d | %15d | %12d | %15d |\n",
               processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    int total_waiting = 0;
    int total_turnaround = 0;
    for (i = 0; i < n; ++i) {
        total_waiting += processes[i].waiting_time;
        total_turnaround += processes[i].turnaround_time;
    }
    
    printf("| Total      |..............-............-.................- %12d | %15d |\n", total_waiting, total_turnaround);
    printf("---------------------------------------------------------------------------------------------\n");
}
