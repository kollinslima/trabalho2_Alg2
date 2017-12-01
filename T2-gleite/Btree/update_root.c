#include<stdio.h>
#include"btree.h"

int update_root(FILE *fi, int new_root){
    
    tHeader reader;
    
    fseek(fi, 0, SEEK_SET);
    fread(&reader, sizeof(tHeader),1,fi);
    
    reader.root_RRN = new_root;
    
    fseek(fi, 0, SEEK_SET);
    
    return fwrite(&reader, sizeof(tHeader),1,fi);
}