OPTIONS = -DNDEBUG

all:
	cd aux_functions; make;
	gcc $(OPTIONS) *.c -c 
	mv *.o ../

Debug:
	cd aux_functions; make;
	gcc *.c -c 
	mv *.o ../