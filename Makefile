.PHONY: all 

all: mytee mync

mytee: mytee.c
	gcc -o mytee mytee.c

mync: mync.c
	gcc -o mync mync.c
	

.PHONY: clean
clean: 
		rm -f *.o *.a *.so mytee mync