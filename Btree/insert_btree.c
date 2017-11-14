#include<stdio.h>
#include<assert.h>
#include"btree.h"

int insert_btree(FILE *fi, int RRN, tKey key, tKey *propo_key, int *propo_r_child){
    
    tPage actual_page;
    
    /*************INSERÇÃO EM ARQUIVO VAZIO**************/
    if(RRN < 0){
        assert(printf("Primeira insercao\n"));
        
        actual_page = new_page();
        
        actual_page.count += 1;
        actual_page.keys[actual_page.count-1] = key;
        actual_page.isLeaf = 1;
        
        write_page(fi, actual_page, 0);
        
        update_root(fi, 0);
        update_free_slot(fi, get_free_RRN(fi) + 1);
    }
    /*************INSERÇÃO EM ARQUIVO NÃO-VAZIO**************/
    else{
        actual_page = read_page(fi, RRN);
        
        
        /*************NÓ FOLHA**************/
        if (actual_page.isLeaf){
            assert(printf("Insercao no folha\n"));
            /*************SEM OVERFLOW**************/
            if(actual_page.count < N_KEYS){
                assert(printf("Sem overflow\n"));
                actual_page.count += 1;
                actual_page.keys[actual_page.count-1] = key;
                
                sort_keys(actual_page.keys, actual_page.count);
                
                write_page(fi, actual_page, RRN);
            }
            /*************COM OVERFLOW**************/
            else{
                assert(printf("Com overflow\n"));
                split(fi, &actual_page, RRN, key, propo_key, propo_r_child);
                /***************PRIMEIRO SPLIT***************/
                if(get_root_RRN(fi) == RRN){
                    
                    actual_page = new_page();            //"Sobe na recursão"
                    actual_page.count += 1;
                    actual_page.keys[actual_page.count-1] = (*propo_key);
                    actual_page.children[actual_page.count-1] = RRN;
                    actual_page.children[actual_page.count] = (*propo_r_child);
                    actual_page.isLeaf = 0;
        
                    write_page(fi, actual_page, get_free_RRN(fi));
                    assert(printf("Escrita Pag: %d\n", get_free_RRN(fi)));
        
                    update_root(fi, get_free_RRN(fi));
                    update_free_slot(fi, get_free_RRN(fi) + 1);
                }
            }
        }
        /*************NÓ NÃO-FOLHA**************/
        else{
            assert(printf("No nao folha\n"));
            
            int position;
                
            position = binary_search(actual_page.keys, actual_page.count, key);
    
            //Descida à direita
            if(actual_page.keys[position].key < key.key){
                insert_btree(fi, actual_page.children[position+1], key, propo_key, propo_r_child);
                //Tratar subida na recursão (chave promovida)
            }
            //Descida à esquerda
            else if(actual_page.keys[position].key > key.key){
                insert_btree(fi, actual_page.children[position], key, propo_key, propo_r_child);
                //Tratar subida na recursão (chave promovida)
            }
            //Chave já existe
            else{
                assert(printf("Chave já existente\n"));    
            }
        }
        
    }
    
    return 0;
    
}