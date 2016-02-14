#define MAXB 1024
#define MAXNOM 100 + 2
#define MAXCOD  5 + 2
#define INDISP -1
/**************
	Estruturas
**************/
struct ALUN {
	char *nome; //Nome do aluno
	int id; //ID do aluno
	struct ALUN *next; //Ponteiro para o próximo
};
struct MATRIC {
	char *codigo; //Código da disciplina
	int id; //ID do aluno matriculado
	float nota1; //Primeira nota
	float nota2; //Segunda nota
	struct MATRIC *next; //Ponteiro para o próximo da lista
};
/**************
	Typedefs
**************/
typedef struct ALUN aluno;
typedef struct MATRIC matricula;
/**************
	Funções
**************/
void TiraEnter(char *);
