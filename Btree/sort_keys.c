#include<stdio.h>
#include"btree.h"

int sort_keys(tKey *key_array, int size_key, int *children_array){
    
    int index = size_key-1;
    int aux;
    
    //Insertion Sort
    while(index > 0 && key_array[index].key < key_array[index-1].key){
        
        //Move chave para nova posição
        aux = key_array[index].key;
        key_array[index].key = key_array[index-1].key;
        key_array[index-1].key = aux;
        
        //Move ponteiro da direita para nova posição
        aux = children_array[index];
        children_array[index] = children_array[index+1];
        children_array[index+1] = aux;
        
        index -= 1;
    }
    
    return 0;
    
}