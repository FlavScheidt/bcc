all: truco

truco: socket.o truco.o
	gcc truco.o socket.o -o rede

truco.o : socket.h truco.c
	gcc -c truco.c

socket.o: socket.c socket.h
	gcc -c socket.c

clean:
	rm -f *.o log_*
