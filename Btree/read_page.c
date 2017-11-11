#include<stdio.h>
#include"btree.h"

tPage read_page(FILE *fi, int RRN){
    
    tPage reader;
    
    fseek(fi, RRN, SEEK_SET);
    fread(&reader, sizeof(tPage),1,fi);
    
    return reader;
}