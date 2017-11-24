#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"funcoes.h"
#include"btree.h"

int criar_indice (FILE *fd, FILE **fi, FILE *fl){

    char buffer[MAX_BUFFER_SIZE],
         buffer_size,
         *token;

    const char delimiter[2] = "|";

    tKey insert_key,
         promo_key;

    int propo_r_child,
        stop_flag,
        error;

/*
    //abertura do arquivo de dados
    fd = fopen(NOME_DADOS, "r");
    if(fd == NULL) {
        error = 1;
        printf("Error during the opening of data file\n");
    }

    //abertura do arquivo de índice
    fi = fopen(NOME_INDICE, "w+");
    if(fi == NULL) {
        error = 1;
        printf("Error during the opening of index file\n");
    }
*/

    //Reabre arquivo de indice, apagando conteúdo anterior
    assert(printf("Reabrindo arquivo\n"));
    fclose((*fi));
    
    (*fi) = fopen(NOME_INDICE, "w+b");
    if((*fi) == NULL) {
        error = 1;
        printf("Error during the opening of index file\n");
    }
    
    assert(printf("Adicionando header\n"));
    //Insere novo header
    tHeader new_header;
    new_header.root_RRN = -1;
    new_header.updated = 1;
    new_header.free_slot = 0;
        
    fwrite(&new_header, sizeof(tHeader), 1, (*fi));

    //movendo o ponteiro para a posição inicio do arquivo
    fseek(fd, 0, SEEK_SET);

    //********************************************* início loop que percorre o arquivo todo
    while(1){

        //pega o offset e coloca na chave
        insert_key.offset = ftell(fd);

        //leitura do tamanho do registro e do registro
        stop_flag = fread(&buffer_size, sizeof(buffer_size), 1, fd); // lê tamanho do registro
        
        //Chegou ao final do arquivo?
        if(stop_flag != 1) break;
        
        fread(buffer, buffer_size, 1, fd);               // lê registro
        

        //pega apenas o ID e joga na chave
        token = strtok(buffer, delimiter);
        insert_key.key = atoi(token);

        assert(printf("Inserindo chave %d\n", insert_key.key));
        //chama a insert para inserir a chave na árvore no arquivo de indice
        error = insert_btree((*fi),fl, get_root_RRN((*fi)), insert_key, &promo_key, &propo_r_child);
        
        if(error == 1) {
            printf("Erro de inserção\n");
            return 1;
        }
    }
    //********************************************* fim loop que percorre o arquivo todo

/*
    //fechamento do arquivo de dados e de índice
    fclose(fd);
    fclose(fi);
*/
    return 0;
}
