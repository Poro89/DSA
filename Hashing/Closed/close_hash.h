#ifndef close_hash
#define close_hash

#define INITIAL_TABLE_SIZE 20
#define MAX_PROBES 20
#define LOAD_THRESHOLD 0.65

typedef struct HashTable {
    char color[INITIAL_TABLE_SIZE][20];
    bool occupied[INITIAL_TABLE_SIZE];
    int size;
    int count;
} HashTable;

int hash(char *color, int table_size);
void initHashTable(HashTable *ht);
void resizeHashTable(HashTable *ht);
void insertClosedLinear(HashTable *ht, char *color);
bool searchClosedLinear(HashTable *ht, char *color);
void displayHashTableClosed(HashTable *ht);

#endif
