#include<stdio.h>
#include<assert.h>
#include"funcoes.h"
#include"btree.h"

int main(void){

    FILE *fd,
         *fi,
         *fl;
    
    assert(printf("Ordem: %d\n", ORDER));
    assert(printf("Chaves: %d\n", N_KEYS));
    
    init(&fd,&fi,&fl);
    
    int escolha = 0,
        i;
    
    char *menu[] = {"Criar indice", "Inserir musica", "Pesquiar musica por ID", "Remover musica por ID", "Mostrar arvore-B", "Fechar"};
    int (*func[])(FILE *fd, FILE *fi, FILE *fl) = {criar_indice,inserir_elemento,pesquisar_elemento,remover_elemento,mostrar_btree};
    
    while(1){
        printf("Escolha uma opcao:\n");
        
        for(i = 0; i < MENU_SIZE; i++)
            printf("%d - %s\n", i+1, menu[i]);
        
        printf("> ");
        scanf("%d",&escolha);
        
        if(escolha > MENU_SIZE || escolha < 1)
            printf("\nOpcao Invalida\n");
        else if(escolha == MENU_SIZE)           //Última opção é sempre para fechar
            break;
        else
            (*func[escolha-1])(fd,fi,fl);
        
    }
    
    fclose(fd);
    fclose(fi);
    fclose(fl);
}