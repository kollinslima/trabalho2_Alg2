#include<stdio.h>
#include"btree.h"

int search_btree(FILE *fi, int RRN, int key, int *found_RRN, int *found_position){
    
    int position;
    tPage search_page;
    
    if(RRN < 0)
        return 0;
        
    search_page = read_page(fi, RRN);
    
    position = binary_search(search_page.keys, search_page.count, key);
    
    //Key found
    if(search_page.keys[position].key == key){
        (*found_RRN) = RRN;
        (*found_position) = position;
        return 1;
    }
    //search left child
    else if(search_page.keys[position].key < key){
        return search_btree(fi, search_page.children[position],key,found_RRN,found_position);
    }
    //search right child
    else{
        return search_btree(fi, search_page.children[position+1],key,found_RRN,found_position);
    }
    
}