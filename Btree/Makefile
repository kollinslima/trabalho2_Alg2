OPTIONS = -DNDEBUG

all:
	cd aux_functions
	gcc $(OPTIONS) *.c -c 
	mv *.o ..
	
	cd ..
	gcc $(OPTIONS) *.c -c
	mv *.o ../
	
Debug:
	cd aux_functions
	gcc *.c -c 
	mv *.o ..
	
	cd ..
	gcc *.c -c 
	mv *.o ..