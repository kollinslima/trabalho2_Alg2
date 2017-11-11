#include<stdio.h>
#include"btree.h"

tPage new_page(){
    
    tPage page;
    int i;
    
    page.count = 0;
    
    for(i = 0; i < N_KEYS; i++){
        page.keys[i].key = -1;
        page.keys[i].offset = -1;
    }
    
    for(i = 0; i < ORDER; i++){
        page.children[i] = -1;
    }
    
    page.isLeaf = -1;
    
    return page;
}