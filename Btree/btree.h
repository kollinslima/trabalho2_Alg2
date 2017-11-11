#ifndef _btree_h
#define _btree_h

#define ORDER 5
#define N_KEYS ORDER-1

typedef struct{
    int root_RRN;
    int updated;
}tHeader;

typedef struct{
    int key;
    long int offset;
}tKey;

typedef struct {
    int count;
    tKey keys[N_KEYS];
    int children[ORDER]; 
    int isLeaf;
} tPage; 

tPage new_page();
tPage read_page(FILE *fi, int RRN);

tHeader read_header(FILE *fi);

int insert_btree(FILE *fi, int RRN, tKey key, tKey propo_key, int propo_r_child);
int search_btree(FILE *fi, int RRN, int key, int found_RRN, int found_position);
int write_page(FILE *fi, tPage actual_page, int RRN);

#endif