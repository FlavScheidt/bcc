tudo: alg3
alg3: aplic1.o meuAlocador.o
	gcc -lm -o aplic1 aplic1.o meuAlocador.o


aplic1.o: aplic1.c
	gcc -c aplic1.c
bs-tree.o: meuAlocador.c meuAlocador.h
	gcc -c meuAlocador.c
limpa:
	rm -f *.o *.~* *.bak core*
