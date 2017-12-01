#include<stdio.h>
#include<assert.h>
#include"btree.h"

int write_page(FILE *fi, tPage actual_page, int RRN){
    
    int error_test;
    
    fseek(fi, sizeof(tHeader), SEEK_SET);   //Pula o header;
    
    error_test = fseek(fi, RRN*sizeof(tPage), SEEK_CUR);
    
    assert(error_test == 0);
    
    return fwrite(&actual_page, sizeof(tPage), 1, fi);
}