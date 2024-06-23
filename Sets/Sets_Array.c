#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Sets_Array.h"

//Create a program to find the union and intersection
//- 2 functions that accepts 2 sets and find union & intersection
//functions to add or delete values in the set
//keep the integrity of the 2 initals sets when finding union & intersection
//display resulting unions & intersections
//Array implementation
// "need delete or add"

void add(Set *set, int value) {
	int i;
    for ( i = 0; i < set->size; i++) {
        if (set->elements[i] == value) {
            return; 
        }
    }
    if (set->size < MAX_SIZE) {
        set->elements[set->size++] = value;
    } else {
        printf("Set is full, cannot add more elements.\n");
    }
}

void delete(Set *set, int value) {
    int index = -1;
    int i;
    for ( i = 0; i < set->size; i++) {
        if (set->elements[i] == value) {
            index = i;
            break;
        }
    }
    if (index != -1) {
    	int i;
        for ( i = index; i < set->size - 1; i++) {
            set->elements[i] = set->elements[i + 1];
        }
        set->size--;
    } else {
        printf("Value not found in the set.\n");
    }
}

void findUnion(Set *set1, Set *set2, Set *result) {
    result->size = 0;
    int i;
    for ( i = 0; i < set1->size; i++) {
        result->elements[result->size++] = set1->elements[i];
    }
    for ( i = 0; i < set2->size; i++) {
        bool found = false;
        int j;
        for ( j = 0; j < set1->size; j++) {
            if (set2->elements[i] == set1->elements[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result->elements[result->size++] = set2->elements[i];
        }
    }
}

void findIntersection(Set *set1, Set *set2, Set *result) {
    result->size = 0;
    int i,j;
    for ( i = 0; i < set1->size; i++) {
        for ( j = 0; j < set2->size; j++) {
            if (set1->elements[i] == set2->elements[j]) {
                result->elements[result->size++] = set1->elements[i];
                break;
            }
        }
    }
}

void printSet(Set *set) {
    printf("{ ");
    int i;
    for ( i = 0; i < set->size; i++) {
        printf("%d ", set->elements[i]);
    }
    printf("}\n");
}

void inputSet(Set *set) {
    int num;
    printf("Enter number of elements in the set: ");
    scanf("%d", &num);
    set->size = 0;
    printf("Enter elements of the set: ");
    int i;
    for ( i = 0; i < num; i++) {
        int element;
        scanf("%d", &element);
        add(set, element);
    }
}
