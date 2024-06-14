#ifndef queue
#define queue

typedef struct node{
	int data;
	struct node* next;
}Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}Queue;

void initQueue(Queue *Q);

bool Enqueue(Queue *Q, int data);
bool Dequeue(Queue *Q);
int Front(Queue *Q); 
int Rear(Queue *Q);
bool isEmpty(Queue *Q);
void display(Queue *Q);

//create a function that would get all even numbers and return asa a new queue removing from the old queue

#endif
