#include<stdio.h>
#include"btree.h"

int sort_keys(tKey *key_array, int size){
    
    int index = size-1;
    int aux;
    
    //Insertion Sort
    while(index > 0 && key_array[index].key < key_array[index-1].key){
        
        aux = key_array[index].key;
        key_array[index].key = key_array[index-1].key;
        key_array[index-1].key = aux;
        
        index -= 1;
    }
    
    return 0;
    
}