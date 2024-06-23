#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Sets_Array.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    Set set1, set2;
    Set unionSet;
    Set intersectionSet;

    printf("Input Set 1:\n");
    inputSet(&set1);

    printf("Input Set 2:\n");
    inputSet(&set2);

    printf("Set 1: ");
    printSet(&set1);

    printf("Set 2: ");
    printSet(&set2);

    findUnion(&set1, &set2, &unionSet);
    printf("Union: ");
    printSet(&unionSet);

    findIntersection(&set1, &set2, &intersectionSet);
    printf("Intersection: ");
    printSet(&intersectionSet);

    int value;
    printf("Enter value to add to Set 1: ");
    scanf("%d", &value);
    add(&set1, value);
    printf("Set 1 after adding %d: ", value);
    printSet(&set1);

    printf("Enter value to delete from Set 2: ");
    scanf("%d", &value);
    delete(&set2, value);
    printf("Set 2 after deleting %d: ", value);
    printSet(&set2);

    return 0;
}
