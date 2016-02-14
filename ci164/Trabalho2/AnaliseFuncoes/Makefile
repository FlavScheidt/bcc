C = gcc
CFLAGS = -std=c99 -pthread -o

O: pdeSolver.c
	$(CC) $(CFLAGS) pdeSolver pdeSolver.c -I/home/soft/likwid/include/ -L/home/soft/likwid/lib/ -llikwid -lm
	
O3: pdeSolver.c
	$(CC) -O3 $(CFLAGS) pdeSolver pdeSolver.c -L/home/soft/likwid/lib/ -I/home/soft/likwid/include -llikwid -lm
	
flops_dp: 
	likwid-perfctr -C 0 -g FLOPS_DP -m ./pdeSolver -nx 256 -ny 256 -i 10 -m gs -o _512.dat
	
mem: 
	likwid-perfctr -C 0 -g MEM -m ./pdeSolver -nx 256 -ny 256 -i 10 -m gs -o _512.dat

cache: 
	likwid-perfctr -C 0 -g CACHE -m ./pdeSolver -nx 256 -ny 256 -i 10 -m gs -o _512.dat
	
clean : 
	rm -f *.o *.dat *.png *.jpg *.txt pdeSolver
