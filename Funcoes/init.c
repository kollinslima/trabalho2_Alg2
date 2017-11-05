#include<stdio.h>
#include<assert.h>
#include"funcoes.h"

/*
Função de inicialização:
-Procura por arquivo de dados e indice
-Confere se indice está atualizado
*/
int init (FILE **fd, FILE **fi, FILE **fl){
    (*fd) = fopen(NOME_DADOS,"r+b");
    
    if((*fd) == NULL){                      //Verifica existência do arquivo
        (*fd) = fopen(NOME_DADOS,"w+b");
        
        if((*fd) == NULL){
            printf("ERRO AO CRIAR ARQUIVO DE DADOS");
            return -1;
        }
    }
    
    assert((*fd)!=NULL);
    
    (*fi) = fopen(NOME_INDICE,"r+b");
    
    if((*fi) == NULL){                      //Verifica existência do arquivo
        (*fi) = fopen(NOME_INDICE,"w+b");
        
        if((*fi) == NULL){
            printf("ERRO AO CRIAR ARQUIVO DE INDICE");
            return -1;
        }
    }
    
    (*fl) = fopen(NOME_LOG,"r+");
    
    if((*fl) == NULL){                      //Verifica existência do arquivo
        (*fl) = fopen(NOME_LOG,"w+");
        
        if((*fl) == NULL){
            printf("ERRO AO CRIAR ARQUIVO DE LOG");
            return -1;
        }
    }
    
    //VERIFICAR SE INDICE ESTÁ ATUALIZADO
    
    return 0;
}