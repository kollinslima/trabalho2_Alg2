#include<stdio.h>
#include<assert.h>
#include"btree.h"

/*
Faz a divisão das chaves em 2 novas páginas e as escreve em disco, retornando: 
-propo_key: a chave promovida (se houver);
-propo_r_child: o ponteiro para a página à direita para ser utilizada pela nova raíz
-RRN: ponteiro para a página à esquerda (não muda) para ser utilizada pela nova raíz
*/
int split(FILE *fi, tPage *page, int RRN, tKey key, tKey *propo_key, int *propo_r_child){
    
    int total_keys = N_KEYS;
    int total_ordem = ORDER;
    
    //Auxiliares para fazer o split
    tKey key_divider[(total_keys/2) + 1];
    
    int pointer_divider[(total_keys/2) + 2],
        i,j,
        new_count;
    
    /*****************ORDENAÇÃO ANTES DO SPLIT**********************/
    //Primeira verificação feita manualmente
    if(key.key < (*page).keys[total_keys-1].key){
        
        int aux = key.key;
        key.key = (*page).keys[total_keys-1].key;
        (*page).keys[total_keys-1].key = aux;
    }
    
    //Ordenação das demais chaves
    sort_keys((*page).keys, total_keys);
    
    
    assert(printf("Tamanho antigo: %d\n", (*page).count));
    
    (*page).count = total_keys/2;           //Atualização do novo tamanho do vetor;
    
    assert(printf("Novo tamanho: %d\n", (*page).count));
    
    /*
    Da maneira como está sendo calculado, a chave promovida será a primeira do
    novo nó, ou seja, a mais a esquerda (a ordenação é crescente).
    /*
    
    /***************IDENTIFICA CHAVE A SER PROMOVIDA***************/
    (*propo_key) = (*page).keys[(*page).count];
    assert(printf("Chave promovida: %d\n", (*propo_key).key));
    
    
    /***************SALVA CHAVES A SEREM ALOCADAS NO NOVO NÓ***************/
    for(i = (*page).count + 1, j = 0; i < total_keys; i++, j++)
        key_divider[j] = (*page).keys[i];
    
    key_divider[j] = key;            //Salva última chave
    new_count = j+1;
    
    /*
    A chave está sempre na mesma posição do ponteiro à esquerda (left_child),
    por isso, começamos a copiar partindo do próximo.
    */
    /***************SALVA PONTEIROS A SEREM ALOCADAS NO NOVO NÓ***************/
    for(i = (*page).count + 1, j = 0; i < total_ordem; i++, j++)
        pointer_divider[j] = (*page).children[i];
    
    
    /**********SALVA FILHO DA ESQUERDA**********/
    write_page(fi, (*page), RRN);
    assert(printf("Escrita Pag: %d\n", RRN));
    
    /*
    Para não ficar com 2 páginas em disco, uma vez salvo o filho da esquerda,
    podemos utilizar a estrutura "page" para manipular o filho da direita.
    */
    
    (*page).count = new_count;          //Tem um elemento a menos pois teve uma chave promovida
    
    for(i = 0; i < (*page).count; i++){
        (*page).keys[i] = key_divider[i];
    }
    
    for(i = 0; i < (*page).count + 1 ; i++){
        (*page).children[i] = pointer_divider[i];
    }
    
    (*propo_r_child) = get_free_RRN(fi);
    write_page(fi, (*page), (*propo_r_child));
    assert(printf("Escrita Pag: %d\n", (*propo_r_child)));
    
    update_free_slot(fi, get_free_RRN(fi) + 1);
    
    return 0;
    
}