#include<stdio.h>
#include"btree.h"

tPage read_page(FILE *fi, int RRN){
    
    tPage reader;
    
    fseek(fi, sizeof(tHeader), SEEK_SET);       //Pula o Header
    fseek(fi, RRN*sizeof(tPage), ftell(fi));
    fread(&reader, sizeof(tPage),1,fi);
    
    return reader;
}