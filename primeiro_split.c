/***************PRIMEIRO SPLIT***************/
                if(get_root_RRN(fi) == RRN){
                    
                    actual_page = new_page();            //"Sobe na recursão"
                    actual_page.count += 1;
                    actual_page.keys[actual_page.count-1] = (*propo_key);
                    actual_page.children[actual_page.count-1] = RRN;
                    actual_page.children[actual_page.count] = (*propo_r_child);
                    actual_page.isLeaf = 0;
        
                    write_page(fi, actual_page, get_free_RRN(fi));
        
                    update_root(fi, get_free_RRN(fi));
                    update_free_slot(fi, get_free_RRN(fi) + 1);
                }