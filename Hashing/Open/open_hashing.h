#ifndef open_hashing
#define open_hashing

#define TABLE_SIZE 10

typedef struct Node {
    char color[20];
    struct Node *next;
} Node;

typedef struct HashTable {
    Node *table[TABLE_SIZE];
} HashTable;

int hash(char *color);
void initHashTable(HashTable *ht);
void insertOpen(HashTable *ht, char *color);
bool searchOpen(HashTable *ht, char *color);
void displayHashTable(HashTable *ht);

#endif
