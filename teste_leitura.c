#include<stdio.h>

#define NOME_DADOS "dados.dad"
#define NOME_INDICE "arvore.idx"
#define NOME_LOG "log_X.txt"

#define ORDER 5
#define N_KEYS ORDER-1

typedef struct{
    int root_RRN;
    int updated;
}tHeader;

typedef struct{
    int key;
    long int offset;
}tKey;

typedef struct {
    int count;
    tKey keys[N_KEYS];
    int children[ORDER]; 
    int isLeaf;
} tPage; 

void main(void){
    
    FILE *fi = fopen(NOME_INDICE,"r+b");
    
     tHeader reader;
    
    fseek(fi, 0, SEEK_SET);
    fread(&reader, sizeof(tHeader),1,fi);
    
    printf("Root: %d\n", reader.root_RRN);
    printf("updated: %d\n", reader.updated);
    
    puts("");
    tPage reader_page;
    
    fseek(fi, sizeof(tHeader), SEEK_SET);       //Pula o Header
    fseek(fi, sizeof(tPage), ftell(fi));
    fread(&reader_page, sizeof(tPage),1,fi);
    
    printf("Count: %d\n", reader_page.count);
    printf("Key: %d\n", reader_page.keys[0].key);
    printf("Offset: %ld\n", reader_page.keys[0].offset);
    printf("L_CHILDREN: %d\n", reader_page.children[0]);
    printf("leaf: %d\n", reader_page.isLeaf);
}