#include<stdio.h>
#include<string.h>
#include<assert.h>
#include"funcoes.h"
#include"btree.h"

int inserir_elemento (FILE *fd, FILE *fi, FILE *fl){
    
    //tHeader header;
    tKey insert_key, promo_key;
    int propo_r_child;
    
    int error;
    
    char buffer[MAX_BUFFER_SIZE],
         buffer_size,
         aux_clear;
         
    tRegistro novo_registro;
    
    /*************LEITURA DOS DADOS******************/
    printf("ID: ");
    scanf("%d", &novo_registro.id);
    
    printf("Titulo: ");
    scanf("%s",novo_registro.titulo);
    //fgets(novo_registro.titulo,30,stdin);
    
    //Limpar buffer de entrada
    //while ((aux_clear = getchar()) != '\n' && aux_clear != EOF);
    
    printf("Genero: ");
    scanf("%s",novo_registro.genero);
    //fgets(novo_registro.genero,20,stdin);
    
    /*************COMPOSICAO DO REGISTRO******************/
    sprintf(buffer, "%d|%s|%s|", novo_registro.id, novo_registro.titulo, novo_registro.genero);
    buffer_size = strlen(buffer);
    assert(buffer != NULL);
    
    /*************ESCRITA NO ARQUIVO DE DADOS******************/
    insert_key.key = novo_registro.id;
    insert_key.offset = ftell(fd);
    
    assert(fd != NULL);
    fwrite(&buffer_size,sizeof(buffer_size),1,fd);
    fwrite(buffer,buffer_size,1,fd);
    
    //header = read_header(fi);
    
    assert(printf("rootRRN: %d\n", get_root_RRN(fi)));
    
    error = insert_btree(fi, get_root_RRN(fi), insert_key, &promo_key, &propo_r_child);
    
    //TRATAR ERROS
    
    return 0;
}