#include<stdio.h>

#define NOME_DADOS "dados.dad"
#define NOME_INDICE "arvore.idx"
#define NOME_LOG "log_X.txt"

#define ORDER 5
#define N_KEYS ORDER-1

typedef struct{
    int root_RRN;
    int updated;
    int free_slot;
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
    int i;
    tHeader reader;
    
    fseek(fi, 0, SEEK_SET);
    fread(&reader, sizeof(tHeader),1,fi);
    
    printf("Root: %d\n", reader.root_RRN);
    printf("updated: %d\n", reader.updated);
    printf("free_slot: %d\n", reader.free_slot);
    
    puts("");
    tPage reader_page;
    
    fseek(fi, sizeof(tHeader), SEEK_SET);       //Pula o Header
    
    
    while(fread(&reader_page, sizeof(tPage),1,fi) == 1){
        
        puts("");
        
        printf("Count: %d\n", reader_page.count);
        
        for(i = 0; i < reader_page.count; i++){
            printf("Key%d: %d\n", i, reader_page.keys[i].key);
            printf("Offset%d: %ld\n",i, reader_page.keys[i].offset);
        }
        for(i = 0; i < reader_page.count; i++){
            printf("L_CHILDREN%d: %d\n", i,reader_page.children[i]);
            printf("R_CHILDREN%d: %d\n", i,reader_page.children[i+1]);
        }
            
        printf("leaf: %d\n", reader_page.isLeaf);
        
    
    
    }
}