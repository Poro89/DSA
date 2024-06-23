#include <stdio.h>
#include <stdlib.h>
#include "circq_array.h"

//typedef struct {
//    int data[MAX];
//    int front;
//    int rear;
//} circularQ;

void initQueue(circularQ *Q) {
    Q->front = 1;
    Q->rear = 0;
}

void Enqueue(circularQ *Q, int data) {
	if (isFull(*Q)) {
    printf("Queue is full. Cannot enqueue %d.\n", data);
    return;
    }
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAX;
}

void Dequeue(circularQ *Q) {
    if (isEmpty(*Q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    Q->front = (Q->front + 1) % MAX;
}

int Front(circularQ Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return -1; 
    }
    return Q.data[Q.front];
}

int Rear(circularQ Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return -1; 
    }
    return Q.data[(Q.rear - 1 + MAX) % MAX];
}

int isEmpty(circularQ Q) {
    return (Q.front == (Q.rear + 1) % MAX);
}

int isFull(circularQ Q) {
    return ((Q.rear + 1) % MAX == Q.front);
}

void display(circularQ Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = Q.front;
    while (i != Q.rear) {
        printf("%d ", Q.data[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", Q.data[i]);
}


