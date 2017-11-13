#include<stdio.h>
#include"btree.h"

int get_root_RRN(FILE *fi){
    
    tHeader reader = read_header(fi);
    return reader.root_RRN;
    
}