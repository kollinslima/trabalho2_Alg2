#include<stdio.h>
#include"funcoes.h"
#include"btree.h"

int pesquisar_elemento (FILE *fd, FILE *fi, FILE *fl){
    
    tHeader header;
    
    int elemento_encontrado,
        chave_busca,
        retorno_RRN,
        retorno_posicao;
        
    header = read_header(fi);
    
    printf("Digite o ID a ser buscado: ");
    scanf("%d", &chave_busca);
    
    elemento_encontrado = search_btree(fi, header.root_RRN, chave_busca, retorno_RRN, retorno_posicao);
    
    //Encontrou elemento
    if(elemento_encontrado){
        
    }
    //Elemento não encontrado
    else{
        
    }
    
    return 0;
}