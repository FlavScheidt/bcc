C = gcc
CFLAGS = -std=c99 -o

all: pdeSolver.c
	$(CC) $(CFLAGS) pdeSolver pdeSolver.c -lm

lik:
	$(CC) $(CFLAGS) pdeSolver pdeSolver.c -I/home/soft/likwid/include/ -L/home/soft/likwid/lib/ -llikwid -lm

clean : 
	rm -f *.o *.dat *.png *.jpg *.txt pdeSolver
