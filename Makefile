OPTIONS = -DNDEBUG

all:
	cd Btree; make;
	cd Funcoes; make;
	gcc $(OPTIONS) main.c -c -I "Funcoes" -I "Btree"
	gcc $(OPTIONS) *.o -o trab_run
	rm *.o
	
Debug:
	cd Btree; make Debug;
	cd Funcoes; make Debug;
	gcc main.c -c -I "Funcoes" -I "Btree"
	gcc *.o -o trab_run
	rm *.o

clean:
	rm arvore.idx;
	rm dados.dad;
	rm log_X.txt;
	rm trab_run;
	
run:
	./trab_run