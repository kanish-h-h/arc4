all: arcfour example

example: example.o
	gcc arcfour.o example.o -o example -Wall -O2

example.o: example.c
	gcc -c -O2 -Wall example.c

arcfour: arcfour.o
	gcc arcfour.o -o arcfour.so -O2 -Wall -fPIC -shared -ldl -D_GNU_SOURCE

arcfour.o: arcfour.c
	gcc -c -O2 -Wall arcfour.c

clean:
	rm -f *.o *.so example
