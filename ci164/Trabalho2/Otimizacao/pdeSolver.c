#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <ctype.h>
#include "pdeSolver.h"
//#include <likwid.h>

double timestamp(void){
	struct timeval tp;
        gettimeofday(&tp, NULL);
	return((double)(tp.tv_sec + tp.tv_usec/1000000.0));
}

void ImprimePontos(double *resul, double *residuo, char arquivo[], unsigned short metodo, unsigned short maxIter, unsigned short nx, unsigned short ny, double hx, double hy, double tMetodo, double tResiduo)
{
	char sMetodo[3];

	int xy, ix, iy, i;
	double x, y;

	if (metodo == 0)
		strcpy(sMetodo, "GS");
	else
		strcpy(sMetodo, "SOR");

	FILE * saida = fopen(arquivo, "w+");

//	fprintf(saida, "###########\n"); fflush(stdout);
	fprintf(saida, "# Tempo Método %s: %f\n", sMetodo, tMetodo); fflush(stdout);
//	fprintf(saida, "# Tempo Resíduo: %f\n", tResiduo); fflush(stdout);
//	fprintf(saida, "#\n"); fflush(stdout);
//	fprintf(saida, "# Norma do Residuo\n"); fflush(stdout);

	//Imprimir normas dos resíduos
//	for (i=0; i<maxIter; ++i)
//	{
//		fprintf(saida, "# i=%d: %.19f\n", i+1, residuo[i]); fflush(stdout);
//	}
//	fprintf(saida, "###########\n");fflush(stdout);
//	
//	//Borda inferior
//	y=0;
//	xy = 0;
//	for (iy=0; iy<=ny; ++iy)
//	{
//		x = 0;
//		for(ix=0; ix<=nx; ++ix)
//		{
//			fprintf(saida, "%f %f %f\n", x, y, resul[xy]); fflush(stdout);
//			xy++;
//			x = x+hx;
//		}
//		y = y+hy;
//	}
//
	//fclose(saida);
}

int CalculaResiduo(double *resul, int tVetor, double *b, double mx, double my, double ptConst)
{
 
	int acumulador, i;
	int aux;
//	int ant, pos;
	
	acumulador = ptConst*resul[0] + my*resul[1];
	
	for(i=1; i<=tVetor-2; i++)
	{
//		ant = i-1;
//		pos = i+1;
		aux = (mx*resul[i-1] + ptConst*resul[i] + my*resul[i+1]);
		acumulador += b[i] - aux;
	}

	acumulador += b[i+1] - (mx*resul[i] + ptConst*resul[i+1]);

	return acumulador;
}

//void CalculaB(double *b, unsigned short nx, unsigned short ny, double hx, double hy)
//{
//	int xy, ix, iy, ib;
//	double x, y, f, f0, f1, f2, f3, f4;
//
//    y = 0;
//      ib = 0;
 //     for (iy=0;iy<=ny;iy++)
//      {
//              x = 0;
//              for (ix=0;ix<=nx;ix++)
//              {
//                      f0 = 4*(M_PI*M_PI);
//                      f1 = 2*M_PI*x;
//                      f2 = sin(f1);
//                      f3 = 2*M_PI*y;
//                      f4 = sinh(f3);
//
//			f = f0*f2*f4;
//                      b[ib] = f;
//                      ++ib;
//
//			x = x+hx;
//                }
//                y = y+hy;
//        }
//
//}

void CalculaPontos(double *resul, double *b, double *tResiduo, double *tMetodo, int tVetor, unsigned short maxIter, unsigned short nx, unsigned short ny, double hx, double hy, double k, double *residuo, double w)
{
	unsigned short xy;
//	int ant, pos;
	double x, y;
	unsigned short i, ix, iy, ib;
	double ptConst, ptConst1, ptConst2, ptConst3;
	double f, f0, f1, f2, f3, f4;
	double mX, mY;
	double vX, vY;
	double resulAux;
	double iT, fT;

	*tMetodo = 0.0;
	*tResiduo = 0.0;

//	likwid_markerStartRegion("GS");

	//Multiplicadores de x e y
	mX = 1/(hx*hx);
	mY = 1/(hy*hy);

	//Multiplicador da equação
	ptConst1 = 2/(hx*hx);
	ptConst2 = 2/(hy*hy);
	ptConst3 = k*k;
//	if (metodo == 0)
		ptConst = 1/(ptConst1+ptConst2+ptConst3);
//	else
//		ptConst = w/(ptConst1+ptConst2+ptConst3);

	//Resultado f(x,y) para cada valor de x e y, inclusive bordas
	//ALTERAÇÃO: retirada função, diminui pressão sobre os registradores
//	CalculaB(b, nx, ny, hx, hy);
	y = 0;
        ib = 0;
        for (iy=0;iy<=ny;iy++)
        {
                x = 0;
                for (ix=0;ix<=nx;ix++)
                {
                        f0 = 4*(M_PI*M_PI);
                        f1 = 2*M_PI*x;
                        f2 = sin(f1);
                        f3 = 2*M_PI*y;
                        f4 = sinh(f3);
	
 			f = f0*f2*f4;
                        b[ib] = f;
                        ++ib;

			x = x+hx;
               }
               y = y+hy;
       }

	for(i=0; i<maxIter; ++i)
	{
		iT = timestamp();
		xy = nx+3;
		ib = nx+3;//por causa das bordas
		//printf("iteração %d\n", i);
		y = hy;
		for (iy=1; iy < ny; iy++)
		{

			x = hx;
			for(ix=1; ix < nx; ix++)
			{
//				ant = xy-1;
//				pos = xy+1;
				//printf("	%f %f", x, y);
				//Calcula variação em x
				vX = mX*(resul[xy-1]+resul[xy+1]);

				//Calcula variação em y
//				ant = xy-ny;
//				pos = xy+ny;
				vY = mY*(resul[xy-ny]+resul[xy+ny]);

				//Final
				resulAux = ptConst*(b[ib]+vY+vX);

                                //ALTERAÇÃO: retirado um dos desvios de dentro do laço
//				if (metodo == 0)
					resul[xy] = resulAux;
//				else
//					resul[xy] = (1-w)*resul[xy] + resulAux;

				x = x+hx;

				//Pular Bordas
				if(ix == nx-1)
				{
					ib = ib+3;
					xy = xy+3;
				}
				else 
				{
					ib++;
					xy++;
				}
			}

			y=y+hy;
		}

//		likwid_markerStopRegion("GS");
		fT = timestamp();

		*tMetodo += (fT - iT);

		iT = timestamp();
//		likwid_markerStartRegion("Residuo");
		residuo[i] = CalculaResiduo(resul, tVetor, b, mX, mY, ptConst);
//		likwid_markerStopRegion("Residuo");
		fT = timestamp();

		*tResiduo += (fT-iT);
	}
}

//ALTERAÇÃO: a fim de retirar desvio de dentro do loop, retiramos a função SOR de dentro da anterior
void SOR(double *resul, double *b, double *tResiduo, double *tMetodo, int tVetor, int maxIter, unsigned short nx, unsigned short ny, double hx, double hy, double k, double *residuo, double w)
{
	unsigned short xy;
	double x, y;
	unsigned short i, ix, iy, ib;
	double ptConst, ptConst1, ptConst2, ptConst3;
	double f, f0, f1, f2, f3, f4;
	double mX, mY;
	double vX, vY;
	double resulAux;
	double iT, fT;

	*tMetodo = 0.0;
	*tResiduo = 0.0;

	//Multiplicadores de x e y
	mX = 1/(hx*hx);
	mY = 1/(hy*hy);

	//Multiplicador da equação
	ptConst1 = 2/(hx*hx);
	ptConst2 = 2/(hy*hy);
	ptConst3 = k*k;
	//if (metodo == 0)
	//	ptConst = 1/(ptConst1+ptConst2+ptConst3);
	//else
		ptConst = w/(ptConst1+ptConst2+ptConst3);

	//Resultado f(x,y) para cada valor de x e y, inclusive bordas
	//ALTERAÇÃO: retirada função, diminui pressão sobre os registradores
	//CalculaB(b, nx, ny, hx, hy);
	y = 0;
        ib = 0;
        for (iy=0;iy<=ny;iy++)
        {
                x = 0;
                for (ix=0;ix<=nx;ix++)
                {
                        f0 = 4*(M_PI*M_PI);
                        f1 = 2*M_PI*x;
                        f2 = sin(f1);
                        f3 = 2*M_PI*y;
                        f4 = sinh(f3);
 
 			f = f0*f2*f4;
                        b[ib] = f;
                        ++ib;

			x = x+hx;
                }
                y = y+hy;
        }

	for(i=0; i<maxIter; ++i)
	{
		iT = timestamp();
		xy = nx+3;
		ib = nx+3;//por causa das bordas
		//printf("iteração %d\n", i);
		y = hy;
		for (iy=1; iy < ny; iy++)
		{

			x = hx;
			for(ix=1; ix < nx; ix++)
			{
				//printf("	%f %f", x, y);
				//Calcula variação em x
				vX = mX*(resul[xy-1]+resul[xy+1]);

				//Calcula variação em y
				vY = mY*(resul[xy+ny]+resul[xy-ny]);

				//Final
				resulAux = ptConst*(b[ib]+vY+vX);

				//if (metodo == 0)
				//	resul[xy] = resulAux;
				//else
					resul[xy] = (1-w)*resul[xy] + resulAux;

				x = x+hx;

				//Pular Bordas
				if(ix == nx-1)
				{
					ib = ib+3;
					xy = xy+3;
				}
				else 
				{
					ib++;
					xy++;
				}
			}

			y=y+hy;
		}
		fT = timestamp();

		*tMetodo += (fT - iT);

		iT = timestamp();
		residuo[i] = CalculaResiduo(resul, tVetor, b, mX, mY, ptConst);
		fT = timestamp();

		*tResiduo += (fT-iT);
	}
}

void InicializaVetor(double *resul, int tVetor, unsigned short nx, double hx)
{
	int xy;
	double x = 0;
	double aux, aux2;
	//Valores iniciam com zero, segundo especificação
	//Exceto pelas bordas superiores. Comecamos por elas

	for (xy=(tVetor-nx); xy<=tVetor; ++xy)
	{
		aux = 2*M_PI*x;
		aux2 = sin(aux);
		resul[xy] = aux2*sinh(2*M_PI);
		x = x+hx;
	}

	for (xy=0; xy<tVetor-(nx+1); ++xy)
	{
		resul[xy] = 0.0;
	}
}

void CalculosIniciais(unsigned short nx, unsigned short ny, double *hx, double *hy, int *tVetor, double *w)
{
	// Calculas os hs
	*hx = 2/ (float) nx;
	*hy = 1/ (float) ny;

	// Tamanho do vetor de pontos a ser alocado
	*tVetor = (nx+1)*(ny+1);

	//Calcula w para o SOR
	*w = 2-(*hx+*hy)/2;
}

void ErrorExit(int error)
{
	// 0 -> número incorreto de parâmetros
	if (error == 0)
	{
		fprintf(stderr, "ERRO: Número incorreto de parâmetros\n");
		exit(1);
	}
	// 1 -> parâmetros incorretos
	if (error == 1)
	{
		fprintf(stderr, "ERRO: Parâmetros incorretos\n");
		exit(1);
	}
	
	// 2 -> possível divisão por 0 (quando nx ou ny são 0)
	if (error == 2)
	{
		fprintf
		(stderr, "ERRO: Possível divisão por zero\n");
		exit(1);
	}

}

void LeParametros(int argc, char * argv[], unsigned short *nx, unsigned short *ny, unsigned short *maxIter, unsigned short *metodo)
{
	char aux[3];
	unsigned short i;

	if (argc != 11)
		ErrorExit(0);
	
	//Trata o número de pontos de x
	if (strcmp(argv[1], "-nx") == 0)
	{
		*nx = (unsigned short) atoi(argv[2]);
		fprintf(stdout, "nx %d\n", *nx);fflush(stdout);
		if (*nx < 1)
			ErrorExit(2);
	}
	else
		ErrorExit(1);

	//Trata o número de pontos de y
	if (strcmp(argv[3], "-ny") == 0)
	{
		*ny = (unsigned short) atoi(argv[4]);
		fprintf(stdout, "ny %d\n", *ny);fflush(stdout);
		if (*ny < 1)
			ErrorExit(2);
	}
	else
		ErrorExit(1);

	//Trata o número máximo de iterações
	if (strcmp(argv[5], "-i") == 0)
	{
		*maxIter = (unsigned short) atoi(argv[6]);
		fprintf(stdout, "iter %d\n", *maxIter);fflush(stdout);
		if (*maxIter < 1)
			ErrorExit(1);
	}
	else
		ErrorExit(1);

	//Trata o método de resolução
	if (strcmp(argv[7], "-m") == 0)
	{
		for (i=0; i<strlen(argv[8]); ++i)
			aux[i] = (char) tolower(argv[8][i]);
			
		aux[i] = '\0';

		fprintf(stdout, "metodo %s\n", aux);fflush(stdout);

		if (strcmp(aux, "gs") == 0)
			*metodo = 0;
		else if (strcmp(aux, "sor") == 0)
			*metodo = 1;
		else
			ErrorExit(1);
	}
	else
		ErrorExit(1);

	//Nome do arquivo
	if (strcmp(argv[9], "-o") != 0)
		ErrorExit(1);
}

int main(int argc, char *argv[])
{
	unsigned short nx, ny, maxIter, metodo;
	int tVetor;
	FILE * saida;

	double hx, hy;

	double k = 2*M_PI;

	double w;

	double tMetodo, tResiduo;

	// Leitura de parâmtros da linha de comando
	LeParametros(argc, argv, &nx, &ny, &maxIter, &metodo);
	
	//Calcula os hs e o tamanho do vetor a ser alocado
	CalculosIniciais(nx, ny, &hx, &hy, &tVetor, &w);

	//fprintf(stdout, "\nnx %d ny %d i %d m %d hx %f hy %f t %d\n", nx, ny, maxIter, metodo, hx, hy, tVetor);

	double * resul 		= (double *) malloc(tVetor*sizeof(double));
	double * b		= (double *) malloc(tVetor*sizeof(double));
	double * residuo 	= (double *) malloc(maxIter*sizeof(double));

	//Inicialização do vetor
	InicializaVetor(resul, tVetor, nx, hx);

	//Calcula Pontos

//	likwid_markerInit();

	if (metodo == 0)
		CalculaPontos(resul, b, &tResiduo, &tMetodo, tVetor, maxIter, nx, ny, hx, hy, k, residuo, w);
	else
		SOR(resul, b, &tResiduo,  &tMetodo, tVetor, maxIter, nx, ny, hx, hy, k, residuo, w);

//	likwid_markerClose();

	tMetodo = tMetodo/(double)maxIter;
	tResiduo = tResiduo/(double)maxIter;

	//Imprime os resultados
	ImprimePontos(resul, residuo, argv[10], metodo, maxIter, nx, ny, hx, hy, tMetodo, tResiduo);
	
	return 0;
}
