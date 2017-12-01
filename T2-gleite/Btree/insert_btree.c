#include<stdio.h>
#include<assert.h>
#include"btree.h"

int insert_btree(FILE *fi, FILE *fl, int RRN, tKey key, tKey *propo_key, int *propo_r_child){
    
    tPage actual_page;
    
    /*************INSERÇÃO EM ARQUIVO VAZIO**************/
    if(RRN < 0){
        assert(printf("Primeira insercao\n"));
        
        actual_page = new_page();
        
        actual_page.count += 1;
        actual_page.keys[actual_page.count-1] = key;
        actual_page.isLeaf = 1;
        
        write_page(fi, actual_page, 0);
        set_update_pages(fi,RRN);
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
                
                sort_keys(actual_page.keys, actual_page.count, actual_page.children);
                
                write_page(fi, actual_page, RRN);
            }
            /*************COM OVERFLOW**************/
            else{
                assert(printf("Com overflow\n"));
                split(fi, &actual_page, RRN, key, -1, propo_key, propo_r_child);
                set_update_pages(fi,RRN);
                fprintf (fl, "  Divisao de no -  pagina %d.\n",RRN);             //Registro no arquivo de Log
                fprintf (fl, "  Chave %d promovida.\n",(*propo_key).key);             
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
                
            position = binary_search(actual_page.keys, actual_page.count, key.key);
    
            assert(printf("Busca binaria: %d\n", position));
            assert(printf("Elemento aqui: %d\n", actual_page.keys[position].key));
            
            //Será analisado o valor deste ponteiro para saber se houve chave promovida
            (*propo_r_child) = 0;        
    
            //Descida à direita
            if(actual_page.keys[position].key < key.key){
                assert(printf("Descida a direita\n"));
                insert_btree(fi, fl, actual_page.children[position+1], key, propo_key, propo_r_child);
            }
            //Descida à esquerda
            else if(actual_page.keys[position].key > key.key){
                assert(printf("Descida a esquerda\n"));
                insert_btree(fi, fl, actual_page.children[position], key, propo_key, propo_r_child);
            }
            //Chave já existe
            else{
                assert(printf("Chave já existente\n"));    
                //Tratar log
                return -1; //Criar mensagem de erro
            }
            
            //Houve chave promovida
            if((*propo_r_child) != 0){
                
                assert(printf("Chave promovida - nao folha\n"));
                
                //Sem overflow
                if(actual_page.count < N_KEYS){
                    assert(printf("Sem overflow\n"));
                    actual_page.count += 1;
                    actual_page.keys[actual_page.count-1] = (*propo_key);
                    actual_page.children[actual_page.count] = (*propo_r_child);
                
                    sort_keys(actual_page.keys, actual_page.count, actual_page.children);
                    
                    write_page(fi, actual_page, RRN);
                    assert(printf("Escrita Pag: %d\n", RRN));
                    
                    /*
                    Garante que a chave não será propagada para o nível acima
                    já que tem espaço no nível atual.
                    */
                    (*propo_r_child) = 0;   
                }
                //Overvlow em nó não folha
                else{
                    assert(printf("Overflow no nao folha\n"));
                    
                    /*
                    Salva chave que promoveu overflow
                    Isso é necessário para que propo_key receba a chave de overflow
                    como retorno da função "split".
                    */
                    tKey aux_key = (*propo_key);
                    int aux_r_child = (*propo_r_child);
                    
                    split(fi, &actual_page, RRN, aux_key, aux_r_child, propo_key, propo_r_child);
                    set_update_pages(fi,RRN);
                    fprintf (fl, "  Divisao de no -  pagina %d.\n",RRN);             //Registro no arquivo de Log
                    fprintf (fl, "  Chave %d promovida.\n",(*propo_key).key); 

                    //Não existe nó acima
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
        }
    }
    
    return 0;
    
}