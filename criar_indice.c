#include<stdio.h>
#include"funcoes.h"
#include"btree.h"

int criar_indice (FILE *fd, FILE *fi, FILE *fl){

    char buffer[MAX_BUFFER_SIZE],
         buffer_size,
         *token;

    const char delimiter[2] = "|";

    tKey insert_key,
         promo_key;

    int propo_r_child,
        error;

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

    //********************************************* início loop que percorre o arquivo todo
    //PRECISA COLOCAR O LOOP

        //movendo o ponteiro para a posição do byte-offset corrente
        fseek(fd, insert_key.offset, SEEK_SET);

        //pega o offset e coloca na chave
        insert_key.offset = ftell(fd);

        //leitura do tamanho do registro e do registro
        fread(&buffer_size, sizeof(buffer_size), 1, fd); // lê tamanho do registro
        fread(buffer, buffer_size, 1, fd);               // lê registro
        puts("");

        //pega apenas o ID e joga na chave
        token = strtok(buffer, delimiter);
        insert_key.key = token;

        //chama a insert para inserir a chave na árvore no arquivo de indice
        error = insert_btree(fi,fl, get_root_RRN(fi), insert_key, &promo_key, &propo_r_child);
    //}
    //********************************************* fim loop que percorre o arquivo todo

    if(error == 1) {
        printf("Error during the insertion\n");
        return 1;
    }

    //fechamento do arquivo de dados e de índice
    fclose(fd);
    fclose(fi);

    return 0;
}
