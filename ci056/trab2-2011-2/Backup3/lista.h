typedef struct conteiner
{
    int entrada;
    int aduana;
    char ID[4];
    char tipo[4];
    int espera;
    struct conteiner *proximo;
} conteiner;
typedef struct fila
{
    conteiner *primeiro;
    int tam;
} fila;
fila *ConstroiFila(void);
void InsereFila(conteiner *c, fila *f);
void RetiraPrimeiro(fila *f);
int PatioVazio(conteiner **patio);
int BuscaConteiner(conteiner **patio);
