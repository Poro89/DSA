#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    Queue Q;
    initQueue(&Q);
    Enqueue(&Q, 1);
    Enqueue(&Q, 2);
    Enqueue(&Q, 3);
    Enqueue(&Q, 4);
    Enqueue(&Q, 5);

    printf("Original Queue: ");
    display(Q);

    Queue evenNumbersQueue = getEvenNumbers(&Q);

    printf("Even Numbers Queue: ");
    display(evenNumbersQueue);

    return 0;
}
