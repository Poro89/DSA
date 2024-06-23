#include <stdio.h>
#include <stdlib.h>
#include "circq_array.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   circularQ Q;
    initQueue(&Q);

    Enqueue(&Q, 10);
    Enqueue(&Q, 20);
    Enqueue(&Q, 30);

    display(Q);

    printf("Front element: %d\n", Front(Q));
    printf("Rear element: %d\n", Rear(Q)); 

    Dequeue(&Q);
    display(Q);

    return 0;
}
