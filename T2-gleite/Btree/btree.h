#ifndef _btree_h
#define _btree_h

#define ORDER 5
#define N_KEYS ORDER-1

typedef struct{
    int root_RRN;
    int updated;
    int free_slot;
    int pages;
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

int binary_search (tKey *array, int size, int key);

int get_free_RRN(FILE *fi);
int get_root_RRN(FILE *fi);
int insert_btree(FILE *fi, FILE *fl, int RRN, tKey key, tKey *propo_key, int *propo_r_child);
int search_btree(FILE *fi, int RRN, int key, int *found_RRN, int *found_position);
int set_header_update(FILE *fi, int status);
int set_update_pages(FILE *fi, int RRN);
int sort_keys(tKey *key_array, int size_key, int *children);
int split(FILE *fi, tPage *page, int RRN, tKey key, int r_child_connect, tKey *propo_key, int *propo_r_child);
int update_free_slot(FILE *fi, int new_slot);
int update_root(FILE *fi, int new_root);
int write_page(FILE *fi, tPage actual_page, int RRN);

#endif