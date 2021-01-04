all: txtfind isort


isort: isort.o 
	gcc -Wall -g isort.o -o isort

txtfind: txtfind.o workTxt.o
	gcc -Wall -g workTxt.o txtfind.o -o txtfind
	
workTxt.o: workTxt.h workTxt.c
	gcc -Wall -g -c workTxt.c

txtfind.o:  workTxt.h txtfind.c 
	gcc -Wall -g -c txtfind.c

isort.o: isort.c
	gcc -Wall -g -c isort.c
	
clean:
	rm *.o txtfind isort