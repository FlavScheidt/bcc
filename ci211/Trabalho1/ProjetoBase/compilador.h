/* -------------------------------------------------------------------
 *            Arquivo: compilaodr.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, protótipos e vaiáveis globais do compilador
 *
 * ------------------------------------------------------------------- */

#define TAM_TOKEN 16

typedef enum simbolos { 
  simb_program, simb_var, simb_begin, simb_end, 
  simb_identificador, simb_numero,
  simb_ponto, simb_virgula, simb_ponto_e_virgula, simb_dois_pontos,
  simb_atribuicao, simb_abre_parenteses, simb_fecha_parenteses,
  simb_label, simb_integer, simb_boolean,
  simb_mais, simb_menos, simb_maior, simb_menor, simb_maior_igual,
  simb_menor_igual, simb_mult, simb_diff, simb_div, simb_igual,
  simb_and, simb_or, simb_while, simb_do, simb_if, simb_then, simb_else,
  simb_proc, simb_func,
} simbolos;



/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;


simbolos simbolo, relacao;
char token[TAM_TOKEN];


/**********************************************************************
	Definições da Tabela de Símbolos
**********************************************************************/
typedef struct InfoVar
{
	int tipoVar;
} InfoVar;

typedef struct InfoLabel
{
	int nRotulo;
} InfoLabel;

typedef struct InfoProcedure
{
	int nRotulo;
	int nParams;
	int * params;
} InfoProcedure;

typedef struct InfoParamFormal
{
	int tipoVar;
	int valor;
} InfoParamFormal;

typedef union Info
{
	InfoVar		infoVar;
	InfoProcedure	infoProcedure;
	InfoLabel	infoLabel;
	InfoParaFormal	infoParamFormal;
	//Se precisar, criar mais sctructs e colocar os elementos aqui
}Info;

typedef struct TabelaSimbolos
{
	int	tipo; // 0 é variável simples
	char 	simbolo[32];
	
	int 	nLexico;
	int 	nDesloc;
	Info 	info;
} TabelaSimbolos;

TabelaSimbolos *TS;
int topoTS;

/******************************************************************
	Defeinições da Tabela de Rótulos
******************************************************************/
int * TR; //Tabela de rótulos é apenas um vetor de inteiros
int topoTR;
int ultimoRotulo; //Ultimo rótulo gerado, para não haver duplicidade de rótulos
