#include<stdio.h>

//Adaptado de https://pt.wikipedia.org/wiki/Pesquisa_bin%C3%A1ria

int binary_search (int *array, int size, int key){
    
     int begin = 0,
         end = size-1,
         middle;
         
    if (size < 1){
        puts("**ERROR - Binary Search: size must be greater than 0");
        return -1;
    }
         
     while (begin <= end){
         
          middle = (begin + end)/2;
          
          if (key == array[middle])
               return middle;
          else if (key < array[middle])
               end = middle-1;
          else
               begin = middle+1;
     }
     
     return middle;   
}