#include<stdio.h>
#include<assert.h>
#include<string.h>
#include"funcoes.h"
#include"btree.h"

int pesquisar_elemento (FILE *fd, FILE *fi, FILE *fl){
    
    tHeader header;
    
    const char delimiter[2] = "|";
    char *token;
    
    char buffer[MAX_BUFFER_SIZE],
         buffer_size;
    
    int elemento_encontrado,
        chave_busca,
        retorno_RRN,
        retorno_posicao;
        
    header = read_header(fi);
    
    printf("Digite o ID a ser buscado: ");
    scanf("%d", &chave_busca);
    
    elemento_encontrado = search_btree(fi, header.root_RRN, chave_busca, &retorno_RRN, &retorno_posicao);
    
    //Encontrou elemento
    if(elemento_encontrado){
        assert(printf("Elemento encontrado\n"));
        
        tPage found_page = read_page(fi, retorno_RRN);
        
        assert(printf("Qtd chaves: %d\n", found_page.count));
        assert(printf("Posicao chave: %d\n", retorno_posicao));
        tKey found_key = found_page.keys[retorno_posicao];
        
        assert(printf("Offset: %ld\n", found_key.offset));
        fseek(fd, found_key.offset, SEEK_SET);  
        fread(&buffer_size, sizeof(buffer_size), 1, fd);    //Leitura do tamanho do registro
        fread(buffer, buffer_size, 1, fd);                 //Leitura do registro
        
        puts("");
        token = strtok(buffer, delimiter);
        printf("ID: %s\n", token);
    
        token = strtok(NULL, delimiter);
        printf("Titulo: %s", token);
        
        token = strtok(NULL, delimiter);
        printf("Genero: %s", token);
        puts("");
    }
    //Elemento não encontrado
    else{
        assert(printf("Elemento nao encontrado\n"));
        
    }
    
    return 0;
}