#define M_PI 3.14159265358979323846

double timestamp(void);
void ImprimePontos(double *resul, double *residuo, char arquivo[], int metodo, int maxIter, int nx, int ny, double hx, double hy, double tMetodo, double tResiduo);
int CalculaResiduo(double *resul, int tVetor, double *b, int nx, double mx, double my, double ptConst);
void CalculaB(double *b, int nx, int ny, double hx, double hy);
void CalculaPontos(double *resul, double *b, double *tMetodo, double *tResiduo, int tVetor, int maxIter, int nx, int ny, double hx, double hy, double k, double *residuo, int metodo, double w);
void InicializaVetor(double *resul, int tVetor, int nx, double hx);
void CalculosIniciais(int nx, int ny, double *hx, double *hy, int *tVetor, double *w);
void ErrorExit(int error);
void LeParametros(int argc, char * argv[], int *nx, int *ny, int *maxIter, int *metodo);

