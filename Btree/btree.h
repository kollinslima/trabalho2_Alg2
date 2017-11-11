#ifndef _btree_h
#define _btree_h

#define ORDER 5
#define N_KEYS ORDER-1

typedef struct {
    int count;
    int keys[ORDER-1];
    int children[ORDER]; 
    int isLeaf;
} tPage; 

int searchBTree(FILE *fi, int RRN, int key, int found_RRN, int found_position);

#endif