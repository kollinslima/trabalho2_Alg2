#include<stdio.h>
#include"btree.h"

int write_page(FILE *fi, tPage actual_page, int RRN){
    
    fseek(fi, sizeof(tHeader), SEEK_SET);   //Pula o header;
    fseek(fi, RRN*sizeof(tPage), ftell(fi));
    
    return fwrite(&actual_page, sizeof(tPage), 1, fi);
}