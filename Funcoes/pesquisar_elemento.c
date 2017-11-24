#include<stdio.h>
#include<assert.h>
#include<string.h>
#include"funcoes.h"
#include"btree.h"

int pesquisar_elemento (FILE *fd, FILE *fi, FILE *fl){
    
    tHeader header;
    
    const char delimiter[2] = "|";
    char *token_id, *token_titulo, *token_genero;
    
    char buffer[MAX_BUFFER_SIZE],
         buffer_size;
    
    int elemento_encontrado,
        chave_busca,
        retorno_RRN,
        retorno_posicao,
        i;
        
    header = read_header(fi);
    
    printf("Digite o ID a ser buscado: ");
    scanf("%d", &chave_busca);

    //Registro no arquivo de log da operacao de busca
    fprintf (fl, "Execucao de operacao de PESQUISA de %d.\n",chave_busca); 
    
    header = read_header(fi);
    //Primeira inserção
    if(header.root_RRN == -1){
        elemento_encontrado = 0;
    }
    else{
        //Verifica se não há duplicação da chave
        for (i = 0; i <= header.pages; ++i)
        {
            elemento_encontrado = search_btree(fi, i, chave_busca, &retorno_RRN, &retorno_posicao);
            if (elemento_encontrado)
                break;
        }
    }
    //Encontrou elemento
    if(elemento_encontrado > 0){
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
        token_id = strtok(buffer, delimiter);
        printf("ID: %s\n", token_id);
    
        token_titulo = strtok(NULL, delimiter);
        printf("Titulo: %s", token_titulo);
        
        token_genero = strtok(NULL, delimiter);
        printf("Genero: %s", token_genero);

        strtok(token_titulo,"\n");
        strtok(token_genero,"\n");
        fprintf (fl, "Chave %s encontrada, offset %ld, Titulo: %s, Genero: %s.\n", token_id, found_key.offset, token_titulo, token_genero);

        puts("");
    }
    //Elemento não encontrado
    else{
        assert(printf("Elemento nao encontrado\n"));
        fprintf (fl, "Chave %d não encontrada.\n",chave_busca);
        printf("Elemento nao encontrado\n\n");
    }
    
    return 0;
}