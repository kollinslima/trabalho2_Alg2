#include<stdio.h>
#include"btree.h"

int update_free_slot(FILE *fi, int new_slot){
    
    tHeader reader;
    
    fseek(fi, 0, SEEK_SET);
    fread(&reader, sizeof(tHeader),1,fi);
    
    reader.free_slot = new_slot;
    
    fseek(fi, 0, SEEK_SET);
    
    return fwrite(&reader, sizeof(tHeader),1,fi);
}