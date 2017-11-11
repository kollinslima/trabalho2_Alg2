#include<stdio.h>
#include"btree.h"

int insert_btree(FILE *fi, int RRN, tKey key, tKey propo_key, int propo_r_child){
    
    tPage actual_page;
    
    //Arquivo vazio
    if(RRN < 0){
        actual_page = new_page();
        
        actual_page.count += 1;
        actual_page.keys[0] = key;
        actual_page.isLeaf = 1;
        
        write_page(fi, actual_page, 0);
    }
    else{
        
    }
    
    return 0;
    
}