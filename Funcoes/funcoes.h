#ifndef _funcoes_h
#define _funcoes_h

#define MENU_SIZE 6
#define MAX_BUFFER_SIZE 100


#define NOME_DADOS "dados.dad"
#define NOME_INDICE "arvore.idx"
#define NOME_LOG "log_X.txt"


typedef struct{
    int id;
    char titulo[30];
    char genero[20];
}tRegistro;

int init (FILE **fd, FILE **fi, FILE **fl);

int criar_indice (FILE *fd, FILE *fi, FILE *fl);
int inserir_elemento (FILE *fd, FILE *fi, FILE *fl);
int pesquisar_elemento (FILE *fd, FILE *fi, FILE *fl);
int remover_elemento (FILE *fd, FILE *fi, FILE *fl);
int mostrar_btree (FILE *fd, FILE *fi, FILE *fl);

#endif