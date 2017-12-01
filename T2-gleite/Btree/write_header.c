#include<stdio.h>
#include"btree.h"

int write_header(FILE *fi, tHeader header){
    
    fseek(fi, 0, SEEK_SET);
    return fwrite(&header, sizeof(tHeader),1,fi);
    
}