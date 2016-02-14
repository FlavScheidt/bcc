matricula: main.c aluno.o display.o matricula.o
	cc -o matricula main.c aluno.o display.o matricula.o
display.o: display.c
	cc -c display.c
aluno.o: aluno.c
	cc -c aluno.c
matricula.o: matricula.c
	cc -c matricula.c
clean:
	rm -f *.o
