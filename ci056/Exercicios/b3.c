/************************
	Programa B.3 do livro Projetos de Algoritmos com Implementações em PASCAL e C - Nivio Ziviani
************************/
#include <stdio.h>

int FibRec(int n)
{
	if(n<2)
		return n;
	else
		return(FibRec(n-1)+FibRec(n-2));
}
main()
{
	int resultado;
	int n;
	printf("\nDigite o número de elementos a serem somados\n");
	scanf("%d", &n);
	resultado = FibRec(n);
	printf("\n%d\n", n);
}
