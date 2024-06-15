#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

//typedef struct{
//	int data[MAX];
//	int top;
//}StackArrayList;

void initStack(StackArrayList *s){
	s->top = -1;
}

StackArrayList createStack(){
	StackArrayList s;
    initStack(&s);
    return s;
}

bool stack_push(StackArrayList *s, int elem){
	if (s->top == MAX - 1){
	return false;
	}
    s->data[++s->top] = elem;
    return true;
}

bool stack_pop(StackArrayList *s){
	if (isEmpty(*s)){
    return false;
	}
    s->top--; 
    return true;
}

int stack_peek(StackArrayList s){
    if (isEmpty(s)){
    return -1;
	}
    return s.data[s.top];	
}

bool isEmpty(StackArrayList s){
	return s.top == -1;
}

bool isFull(StackArrayList s){
	return s.top == MAX - 1;
}

void display(StackArrayList s){
	int i;
    for ( i = 0; i <= s.top; i++){
        printf("%d ", s.data[i]);
    }
    printf("\n");	
}

void visualize(StackArrayList s){
	int i;
    printf("Stack (top to bottom): ");
    for ( i = s.top; i >= 0; i--){
        printf("%d ", s.data[i]);
    }
    printf("\n");    
}	
StackArrayList extractEvenNumbers(StackArrayList *s) {
    StackArrayList evenStack = createStack();
    StackArrayList tempStack = createStack();
    
    while (!isEmpty(*s)) {
        int elem = stack_peek(*s);
        stack_pop(s);
        if (elem % 2 == 0) {
            stack_push(&evenStack, elem);
        } else {
            stack_push(&tempStack, elem);
        }
    }

    while (!isEmpty(tempStack)) {
        int elem = stack_peek(tempStack);
        stack_pop(&tempStack);
        stack_push(s, elem);
    }

    return evenStack;
}

