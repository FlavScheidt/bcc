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
  simb_atribuicao, simb_abre_parenteses, simb_fecha_parenteses, simb_mais,
  simb_menos, simb_or, simb_mult, simb_div, simb_and, simb_igual, simb_diff,
  simb_maior, simb_menor, simb_maior_igual, simb_menor_igual, simb_do, simb_while,
  simb_if, simb_then, simb_else, simb_procedure,simb_function, simb_label, simb_goto, simb_read, simb_write, simb_true, simb_false, simb_boolean, simb_integer
} simbolos;

typedef struct {
  char nome[10];
  int tipo; // 0: var simples; 1: procedimento; 2: parametro; 3: funcao; 4: label; 5: chamada_fc_pc;
  int niv_lex;
  int desloc;
  char rot[10];
  int num_param;
  int *indices;
} elem_tabela;



/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;
extern elem_tabela* tab_simb;
extern int* tab_rot;
extern int topo_tabela;
extern int topo_rot;
extern int num_rot;




simbolos simbolo, relacao;
char token[TAM_TOKEN];
elem_tabela* tab_simb;
int* tab_rot;
int topo_tabela;
int topo_rot;
int desloc;
int nl;
int num_rot;


