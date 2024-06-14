#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

//typedef struct node{
//	int data;
//	struct node* next;
//}Node, NodePtr*;

//typedef struct{
//	NodePtr front;
//	NodePtr rear;
//}Queue;


void initQueue(Queue *Q){
	Q->front = NULL;
	Q->rear = NULL;
}

bool Enqueue(Queue *Q, int data){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	if (newNode == NULL){
		return false;
	}
	newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(*Q)) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    return true;
}
bool Dequeue(Queue *Q){
	NodePtr temp = Q->front;
    Q->front = Q->front->next;
    free(temp);
    if (Q->front == NULL) {
        Q->rear = NULL; 
    }	
}
int Front(Queue Q){
	return Q.front->data;
}
int Rear(Queue Q){
	return Q.rear->data;
}

bool isEmpty(Queue Q){
	return Q->front == NULL;
}

void display(Queue Q){
    printf("Queue elements: ");
    NodePtr current = Q.front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Queue getEvenNumbers(Queue *Q){
	Queue evenQueue;
    initQueue(&evenQueue); 
    
    NodePtr current = Q->front;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            Enqueue(&evenQueue, current->data);
        }
        current = current->next;
    }

    return evenQueue;
}
}
