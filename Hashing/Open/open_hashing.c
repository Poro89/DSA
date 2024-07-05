#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "open_hashing.h"

#define TABLE_SIZE 10

int hash(char *color) {
    unsigned long hash = 5381;
    int c;

    while ((c = *color++))
        hash = ((hash << 5) + hash) + c; 

    return hash % TABLE_SIZE;
}

void initHashTable(HashTable *ht) {
	int i;
    for ( i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

void insertOpen(HashTable *ht, char *color) {
    int index = hash(color);
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    strcpy(newNode->color, color);
    newNode->next = NULL;

    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        newNode->next = ht->table[index];
        ht->table[index] = newNode;
    }
}

bool searchOpen(HashTable *ht, char *color) {
    int index = hash(color);
    Node *current = ht->table[index];
    
    while (current != NULL) {
        if (strcmp(current->color, color) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void displayHashTable(HashTable *ht) {
    printf("Hash Table Contents:\n");
    int i;
    for ( i = 0; i < TABLE_SIZE; i++) {
        Node *current = ht->table[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("%s -> ", current->color);
            current = current->next;
        }
        printf("NULL\n");
    }
}
