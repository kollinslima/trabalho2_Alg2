#include<stdio.h>
#include"funcoes.h"
#include"btree.h"

int pesquisar_elemento (FILE *fd, FILE *fi, FILE *fl){
    
    int elemento_encontrado,
        RRN_inicial,
        chave_busca,
        retorno_RRN,
        retorno_posicao;
        
    //Leitura do Header para encontrar posição inicial
    //Teste new Branch
    
    printf("Digite o ID a ser buscado: ");
    scanf("%d", &chave_busca);
    
    elemento_encontrado = searchBTree(fi, RRN_inicial, chave_busca, retorno_RRN, retorno_posicao);
    
    //Encontrou elemento
    if(elemento_encontrado){
        
    }
    //Elemento não encontrado
    else{
        
    }
    
    return 0;
}