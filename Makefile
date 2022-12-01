.PHONY: all 

all: mytee nc

mytee: mytee.c
	gcc -o mytee mytee.c

nc: nc.c
	gcc -o nc nc.c
	

.PHONY: clean
clean: 
		rm -f *.o *.a *.so mytee nc