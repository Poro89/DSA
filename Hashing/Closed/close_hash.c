#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "close_hash.h"

#define INITIAL_TABLE_SIZE 20
#define MAX_PROBES 20
#define LOAD_THRESHOLD 0.65

int hash(char *color, int table_size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *color++))
        hash = ((hash << 5) + hash) + c; 

    return hash % table_size;
}

void initHashTable(HashTable *ht) {
    int i;
    ht->size = INITIAL_TABLE_SIZE;
    ht->count = 0;
    for (i = 0; i < ht->size; i++) {
        ht->occupied[i] = false;
    }
}

void resizeHashTable(HashTable *ht) {
    int new_size = ht->size * 2;
    char temp[new_size][20];
    bool temp_occupied[new_size];

    int i;
    for (i = 0; i < new_size; i++) {
        temp_occupied[i] = false;
    }

    for (i = 0; i < ht->size; i++) {
        if (ht->occupied[i]) {
            int index = hash(ht->color[i], new_size);
            int probes = 0;
            while (temp_occupied[index]) {
                index = (index + 1) % new_size;
                probes++;
                if (probes >= new_size) {
                    fprintf(stderr, "Error: Hash table is full after resizing.\n");
                    exit(EXIT_FAILURE);
                }
            }
            strcpy(temp[index], ht->color[i]);
            temp_occupied[index] = true;
        }
    }

    ht->size = new_size;
    for (i = 0; i < ht->size; i++) {
        ht->occupied[i] = temp_occupied[i];
        if (ht->occupied[i]) {
            strcpy(ht->color[i], temp[i]);
        }
    }

    printf("Hash table resized. New size: %d\n", ht->size);
}

void insertClosedLinear(HashTable *ht, char *color) {
    if ((double)ht->count / ht->size >= LOAD_THRESHOLD) {
        resizeHashTable(ht);
    }

    int index = hash(color, ht->size);
    int probes = 0;

    while (ht->occupied[index] && probes < MAX_PROBES) {
        index = (index + 1) % ht->size;
        probes++;
    }

    if (probes < MAX_PROBES) {
        strcpy(ht->color[index], color);
        ht->occupied[index] = true;
        ht->count++;
        printf("Inserted '%s' at index %d.\n", color, index);
    } else {
        printf("Could not insert '%s'. Hash table is full.\n", color);
    }
}

bool searchClosedLinear(HashTable *ht, char *color) {
    int index = hash(color, ht->size);
    int probes = 0;

    while (ht->occupied[index] && probes < MAX_PROBES) {
        if (strcmp(ht->color[index], color) == 0) {
            return true;
        }
        index = (index + 1) % ht->size;
        probes++;
    }
    return false;
}

void displayHashTableClosed(HashTable *ht) {
    printf("Hash Table Contents:\n");
    int i;
    for (i = 0; i < ht->size; i++) {
        if (ht->occupied[i]) {
            printf("%d: %s\n", i, ht->color[i]);
        } else {
            printf("%d: NULL\n", i);
        }
    }
}
