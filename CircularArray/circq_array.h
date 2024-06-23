#ifndef circq_array
#define circq_array

#define MAX 10

typedef struct{
	int data[MAX];
	int front;
	int rear;
}circularQ;

void initQueue(circularQ *Q);
void Enqueue(circularQ *Q, int data);
void Dequeue (circularQ *Q);
int Front(circularQ Q);
int Rear (circularQ Q);
int isEmpty (circularQ Q);
int isFull (circularQ Q);
void display (circularQ Q);


#endif
	
