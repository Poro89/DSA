#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "close_hash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	HashTable ht;
    initHashTable(&ht);

    char color[20];
    char choice;

    do {
        printf("Enter a color to insert into hash table: ");
        scanf("%s", color);
        insertClosedLinear(&ht, color);

        printf("Do you want to enter another color? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    displayHashTableClosed(&ht);

    printf("\nEnter a color to search: ");
    scanf("%s", color);

    if (searchClosedLinear(&ht, color)) {
        printf("Color '%s' found in hash table.\n", color);
    } else {
        printf("Color '%s' not found in hash table.\n", color);
    }

	return 0;
}
