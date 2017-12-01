OPTIONS = -DNDEBUG

all:
	cd Btree; make;
	cd Funcoes; make;
	gcc $(OPTIONS) main.c -c -I "Funcoes" -I "Btree"
	gcc $(OPTIONS) *.o -o bin/Debug/T2-gleite
	rm *.o

Debug: all

clean:
	rm arvore.idx;
	rm dados.dad;
	rm log_gleite.txt;
	rm bin/Debug/T2-gleite;

run:
	./bin/Debug/T2-gleite
