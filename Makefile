.PHONY: all 

all: mytee mync myshell

mytee: mytee.c
	gcc -o mytee mytee.c

mync: mync.c
	gcc -o mync mync.c

myshell: myshell.c
	gcc -o myshell myshell.c	

.PHONY: clean
clean: 
		rm -f *.o *.a *.so mytee mync myshell