#ifndef FCFS
#define FCFS

typedef struct {
    char pid;            	
    int arrival_time;       
    int burst_time;         
    int waiting_time;     
    int turnaround_time;    
    int completion_time;   
} Process;

typedef struct Node {
    Process data;           
    struct Node* next;     
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, Process data);
Process dequeue(Queue* q);
int is_empty(Queue* q);
float calculate_average_waiting_time(Process* processes, int n);
void display_process_table(Process* processes, int n);

#endif
