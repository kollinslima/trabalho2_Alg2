#include<stdio.h>
#include<assert.h>
#include"funcoes.h"
#include"btree.h"

int pesquisar_elemento (FILE *fd, FILE *fi, FILE *fl){
    
    tHeader header;
    
    char buffer[MAX_BUFFER_SIZE],
         buffer_size;
    
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
        assert(printf("Elemento encontrado\n"));
        
        tPage found_page = read_page(fi, retorno_RRN);
        tKey found_key = found_page.keys[retorno_posicao];
        
        
        fseek(fd, found_key.offset, SEEK_SET);  
        fread(&buffer_size, sizeof(buffer_size), 1, fd);    //Leitura do tamanho do registro
        fread(&buffer, buffer_size, 1, fd);    //Leitura do registro
        
        
        printf("ID: %d\n", found_register.id);
        printf("Titulo: %s\n", found_register.titulo);
        printf("Genero: %s\n", found_register.genero);
    }
    //Elemento não encontrado
    else{
        assert(printf("Elemento nao encontrado\n"));
        
    }
    
    return 0;
}