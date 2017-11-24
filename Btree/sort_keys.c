#include<stdio.h>
#include"btree.h"

int sort_keys(tKey *key_array, int size_key, int *children_array){
    
    int index = size_key-1;
    int aux_pointer;
    tKey aux;
    
    //Insertion Sort
    while(index > 0 && key_array[index].key < key_array[index-1].key){
        
        //Move chave para nova posição
        aux = key_array[index];
        key_array[index] = key_array[index-1];
        key_array[index-1] = aux;
        
        //Move ponteiro da direita para nova posição
        aux_pointer = children_array[index];
        children_array[index] = children_array[index+1];
        children_array[index+1] = aux_pointer;
        
        index -= 1;
    }
    
    return 0;
    
}