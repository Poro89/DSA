#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"


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
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s.top; i++){
        printf("%d ", s.data[i]);
    }
    printf("\n");	
}

void visualize(StackArrayList s){
	
}

