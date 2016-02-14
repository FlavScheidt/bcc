//Numero de linhas d matriz
#define L 5

//Numero de diagonais
#define K 3

//Matriz. Seu tamanho é dado por número de linha * (número de diagonais+1). 
//Lembrando que o termo independente é guardado neste mesmo vetor (por isso o +1)
//Retiramos dois elementos pois a primeira e a ultima linha possuem k-1 elementos
float A[(L*(K+1)-2)];

float R[L*2];	 //Vetor dos resultados. Como precisamos fazer o resultado da rodada atual - o resultado da rodada anterior, ele guarda ambos
float Rfinal[L]; //Vetor dos resultado finais	

