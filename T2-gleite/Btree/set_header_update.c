#include<stdio.h>
#include"btree.h"

int set_header_update(FILE *fi, int status){
    
    tHeader reader;
    
    fseek(fi, 0, SEEK_SET);
    fread(&reader, sizeof(tHeader),1,fi);
    
    reader.updated = status;
    
    fseek(fi, 0, SEEK_SET);
    
    return fwrite(&reader, sizeof(tHeader),1,fi);
}