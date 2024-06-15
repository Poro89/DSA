#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList stack = createStack();
    stack_push(&stack, 1);
    stack_push(&stack, 2);
    stack_push(&stack, 3);
    stack_push(&stack, 4);
    stack_push(&stack, 5);

    printf("Original stack: ");
    display(stack);

    StackArrayList evenStack = extractEvenNumbers(&stack);

    printf("Stack after extracting evens: ");
    display(stack);

    printf("Extracted even stack: ");
    display(evenStack);
	return 0;
}
