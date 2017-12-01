#include<stdio.h>
#include<assert.h>
#include"btree.h"

//Adaptado de https://pt.wikipedia.org/wiki/Pesquisa_bin%C3%A1ria
/*
Retorna a posição onde a chave buscada está (ou deveria estar).
*/

int binary_search (tKey *array, int size, int key){
    
    assert(printf("Busca por: %d\n", key));
    
     int begin = 0,
         end = size-1,
         middle;
         
    if (size < 1){
        puts("**ERROR - Binary Search: size must be greater than 0");
        return -1;
    }
         
     while (begin <= end){
         
          middle = (begin + end)/2;
    
          assert(printf("Compara %d com %d\n", key, array[middle].key));      
          
          if (key == array[middle].key)
               return middle;
          else if (key < array[middle].key)
               end = middle-1;
          else
               begin = middle+1;
     }
     
     return middle;   
}