#include<stdio.h>
#include"btree.h"

tHeader read_header(FILE *fi){
    
    tHeader reader;
    
    fseek(fi, 0, SEEK_SET);
    fread(&reader, sizeof(tHeader),1,fi);
    
    return reader;
}