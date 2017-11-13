#include<stdio.h>
#include"btree.h"

int get_free_RRN(FILE *fi){
    
    tHeader reader = read_header(fi);
    return reader.free_slot;
    
}