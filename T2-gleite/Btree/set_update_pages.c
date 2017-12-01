#include<stdio.h>
#include"btree.h"

int set_update_pages(FILE *fi, int RRN){
    
    tHeader reader;
    
    fseek(fi, 0, SEEK_SET);
    fread(&reader, sizeof(tHeader),1,fi);
    //Arquivo vazio
    if(reader.root_RRN < 0){
    	reader.pages = 0;
    }
    //Split na raiz
    else if(reader.root_RRN == RRN){
    	reader.pages = reader.pages + 2;
    }
    //Split na folha
    else{
    	reader.pages = reader.pages + 1;
    }
    
    fseek(fi, 0, SEEK_SET);
    
    return fwrite(&reader, sizeof(tHeader),1,fi);
}