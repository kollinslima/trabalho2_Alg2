#include<stdio.h>
#include"btree.h"

int insert_btree(FILE *fi, int RRN, tKey key, tKey propo_key, int propo_r_child){
    
    tPage actual_page;
    
    /*************INSERÇÃO EM ARQUIVO VAZIO**************/
    if(RRN < 0){
        actual_page = new_page();
        
        actual_page.count += 1;
        actual_page.keys[actual_page.count-1] = key;
        actual_page.isLeaf = 1;
        
        write_page(fi, actual_page, 0);
        
        update_root(fi, 0);
        
    }
    /*************INSERÇÃO EM ARQUIVO NÃO-VAZIO**************/
    else{
        actual_page = read_page(fi, RRN);
        
        
        /*************NÓ FOLHA**************/
        if (actual_page.isLeaf){
            
            /*************SEM OVERFLOW**************/
            if(actual_page.count < N_KEYS){
                actual_page.count += 1;
                actual_page.keys[actual_page.count-1] = key;
                
                sort_keys(actual_page.keys, actual_page.count);
                
                write_page(fi, actual_page, RRN);
            }
            /*************COM OVERFLOW**************/
            else{
                
            }
        }
        /*************NÓ NÃO-FOLHA**************/
        else{
            
        }
        
    }
    
    return 0;
    
}