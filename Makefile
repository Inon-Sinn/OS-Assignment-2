.PHONY: all 

all: mytee

mytee: mytee.c
	gcc -o mytee mytee.c
	

.PHONY: clean
clean: 
		rm -f *.o *.a *.so mytee