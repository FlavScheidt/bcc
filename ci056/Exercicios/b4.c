/************************
	Programa retirado do livro Projetos de Algoritmos com Implemantações em PASCAL e C
************************/
#include <stdio.h>
int FibIter(int n)
{
	int i=1, k, F=0;
	for (k=1; k<=n; k++)
	{
		F += i; 
		i = F-i;
	}
	return F;
}
main()
{
	int n;
	int resultado;
	printf("Digite o número de elementos a serem somados");
	scanf("%d", &n);
	resultado = FibIter(n);
	printf("%d", n);
}
