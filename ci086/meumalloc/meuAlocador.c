#include "meuAlocador.h"

tree raiz1, raiz2;
int ast1;


/*----------------------------------------------------------------------------*/
/* Imprime um object em stream                                                */
/*----------------------------------------------------------------------------*/
void fprintf_object(FILE *stream, object o) {
    fprintf(stream, "%d", o);
}

/*----------------------------------------------------------------------------*/
/* Faz a compraracao entre dois objects                                       */
/*----------------------------------------------------------------------------*/
int objectcmp(void *o1, void *o2) {
  return o1 < o2 ? -1 : o1 > o2 ? 1 : 0;
}

/*----------------------------------------------------------------------------*/
/* Retorna o módulo de n                                                      */
/*----------------------------------------------------------------------------*/
int modulo(int n)
{
	if (n<0)
		return (-1)*n;
	return n;
}

/*----------------------------------------------------------------------------*/
/* Visualizacao da arvore                                                     */ 
/*----------------------------------------------------------------------------*/
int print_tree_border(node **n)
{
	printf("(");
	print_tree(n);
	printf(")\n");
}

int print_tree(node **n)
{
	if( ! *n )
		return 0;
	printf("(");
	if ((*n)->left)
		print_tree(&(*n)->left);
	printf(") %d[%d] (",(*n)->tam,(*n)->balance);
	if ((*n)->right)
		print_tree(&(*n)->right);
	printf(")");
}

void show_tree (FILE *stream, node *n, int b) {
	int i;
	if (n == NULL) {
		for (i = 0; i < b; i++) 
			fprintf(stream, "      ");
		fprintf(stream, "*\n");
		return;
	}
	show_tree(stream, n->right, b+1);
	void *temp = n;
	for (i = 0; i < b; i++) 
		printf("      ");
	if (n->disp==1)
		fprintf(stream, "ini: %p tam: %d bal: %d (L)\n",n, n->tam, n->balance);
	else
		fprintf(stream, "ini: %p tam: %d bal: %d\n",n, n->tam, n->balance);
	for (i = 0; i < b; i++) 
		printf("      ");
	fprintf(stream, "fim: %p\n",temp+13+n->tam);

	show_tree(stream, n->left, b+1);
}

void show_tree_2 (FILE *stream, node *n, int b) {
	int i;
	void *temp = n;
	for (i = 0; i < b-1; i++) 
		printf("│    ");
	if(n==raiz1) {
		if (n->disp==1)
			printf("ini: %p (L)\n",n);
		else
			printf("ini: %p\n",n);
		printf("fim: %p\n",temp+13+n->tam);
	}
	else {
		if (n == NULL) {
			printf("├──\n");
			return;
		}
		else {
			if (n->disp==1)
				printf("├── ini: %p (L)\n",n);
			else
				printf("├── ini: %p\n",n);
			for (i = 0; i < b-1; i++) 
				printf("│    ");
			printf("│   fim: %p\n",temp+13+n->tam);
		}
	}
	show_tree_2(stream, n->right, b+1);
	show_tree_2(stream, n->left , b+1);
}

void imprMapa()
{	
	printf("\n");
	show_tree(stdout, raiz1, 0);
	printf("\n");
}

void imprMapa2()
{	
	printf("\n");
	show_tree_2(stdout, raiz1, 0);
	printf("\n\n");
}
/*----------------------------------------------------------------------------*/
/* Destroi e libera a memoria alocada para o respectivo node                  */
/*----------------------------------------------------------------------------*/
node* destroy_node(node **n) {
	if (*n) {
		(*n)->balance = 0;
		(*n)->left = NULL;
		(*n)->right = NULL;
		free(*n);
	}
	return NULL;
}

/*----------------------------------------------------------------------------*/
/* Devolve o menor dos maiores objetos inserido na arvore apartir do node n   */
/*----------------------------------------------------------------------------*/
void lower_of_bigger(node **n, node **pai_lower) {
	if ((*n)->left->left == NULL) {
		(*pai_lower) = (*n);

	}
 	else 
		lower_of_bigger(&(*n)->left, pai_lower);
}

/*----------------------------------------------------------------------------*/
/* Devolve o maior dos menores objetos inserido na arvore apartir do node n   */
/*----------------------------------------------------------------------------*/
/*object* bigger_of_lower(node **n) {
	if ((*n)->right == NULL)
		return (&((*n)->value));
 	else 
		return bigger_of_lower(&(*n)->right);
}*/

/*----------------------------------------------------------------------------*/
/* Rotaciona o node para a esquerda                                           */
/*----------------------------------------------------------------------------*/
void rotation_left(node **n) {
	node *a = *n;
	node *b = (*n)->right;
	a->right = b->left;
	b->left = a;
	(*n) = b;
	(*n)->left->balance = ((*n)->left->balance*2 - (*n)->balance + modulo((*n)->balance) + 2)/2;
	(*n)->balance = ((*n)->balance*2 + (*n)->left->balance + modulo((*n)->left->balance) + 2)/2;
}

/*----------------------------------------------------------------------------*/
/* Rotaciona o node para a direita                                            */
/*----------------------------------------------------------------------------*/
void rotation_right(node **n) {
	node *a = *n;
	node *b = (*n)->left;

	a->left = b->right;
	b->right = a;

	(*n) = b;
	(*n)->right->balance = ((*n)->right->balance*2 - (*n)->balance - modulo((*n)->balance) - 2)/2;
	(*n)->balance = ((*n)->balance*2 + (*n)->right->balance - modulo((*n)->right->balance) - 2)/2;
}

/*----------------------------------------------------------------------------*/
/* Cria e aloca um novo no                                                    */
/*----------------------------------------------------------------------------*/
node *create_node(node **n,int tam) {
	node *new_node;
	new_node = sbrk(14);
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->balance = 0;
        sbrk(tam);
	*n = new_node;
	return *n;
}

node *create_node_free(node **n, void *end, int tam) {
	node *new_node = end;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->balance = 0;
	*n = new_node;
	return *n;
}

/*----------------------------------------------------------------------------*/
/* Insere um node na arvore, balanceando                                      */
/*----------------------------------------------------------------------------*/

int insere_por_end(node **n, void *end, int tam) {
	node *current = *n;
	if( !current ) {
		if( !(current = create_node_free(&current, end, tam))) 
            		return 0;
		current->tam = tam;
		current->disp = 1;
		void *temp = current;
		*n = current;
		return 1;
	}
	else if( objectcmp(end,*n) == -1 ) {
		if( insere_por_end(&(current->left), end, tam) == 1){
			current->balance++;
			if ( current->balance == 2 ) {
				if ( (current->left)->balance == 1) {
					rotation_right(&current);
				}
				else if ( (current->left)->balance == -1) {
                                        rotation_left(&(current->left));
                                        rotation_right(&current);
				}
				*n = current;
			}
			return (current->balance > 0);
		}
	}
	else if( objectcmp(end,*n) == 1 ) {
		if( insere_por_end(&(current->right), end, tam) == 1){
			current->balance--;
			if ( current->balance == -2 ) {
				if ( (current->right)->balance == -1) {
					rotation_left(&current);
				}
				else if ( (current->right)->balance == 1) {
                                        rotation_right(&(current->right));
                                        rotation_left(&current);
				}
				*n = current;
			}
			return (current->balance < 0);
		}
	}
	return 0;
}

/*----------------------------------------------------------------------------*/
/* Insere um node na arvore à direita, balanceando                            */
/*----------------------------------------------------------------------------*/

int insere_a_direita(node **n, int tam, void **retorno) {
	node *current = *n;
	if( !current ) {
		if( !(current = create_node(&current, tam))) 
            		return 0;
		current->tam = tam;
		current->disp=0;
		*n = current;
		void *temp = current;
                *retorno = temp+14;
		return 1;
	} else {
		if( insere_a_direita(&(current->right), tam, retorno) == 1){
			current->balance--;
			if ( current->balance == -2 ) {
				if ( (current->right)->balance == -1) {
					rotation_left(&current);
				}
				else if ( (current->right)->balance == 1) {
                                        rotation_right(&(current->right));
                                        rotation_left(&current);
				}
				*n = current;
			}
			return (current->balance < 0);
		}
	}
	return 0;
}

/*----------------------------------------------------------------------------*/
/* Remocao, balanceando                                                       */
/*----------------------------------------------------------------------------*/
int remove_node(node **n, void *end) {
	node *pai_lower;
	node *lower;
	node *temp;
	if( ! *n )
		return 0;
	if( objectcmp(end,*n) == -1 ) {
		if( remove_node(&((*n)->left), end) == 1){
			(*n)->balance -= 1;
			if ( (*n)->balance == -2 ) {
				if ( (*n)->right ){
					if ( ((*n)->right)->balance == 1) {
						rotation_right(&(*n)->right);
						rotation_left(n);
					}
					else if ( ((*n)->right)->balance == 0) {
						rotation_left(n);
					}
					else if ( ((*n)->right)->balance == -1) {
						rotation_left(n);
					}
				}
			}
			return ((*n)->balance == 0);
		}
	}
 	else if( objectcmp(end,*n) == 1 ) {
		if( remove_node(&((*n)->right), end) == 1){
			(*n)->balance += 1;
			if ( (*n)->balance == 2 ) {
				if ( (*n)->left ) {
					if ( ((*n)->left)->balance == 1 ) {
						rotation_right(n);
					}
					else if ( ((*n)->left)->balance == 0) {
						rotation_right(n);
					}
					else if ( ((*n)->left)->balance == -1) {
						rotation_left(&(*n)->left);
						rotation_right(n);
					}
				}
			}
			return ((*n)->balance == 0);
		}
	}
	else if ( objectcmp(end,*n) == 0) {
		if ((*n)->left && (*n)->right) {
			
			node *right = (*n)->right;
			if (right->left == NULL) {
				lower = right;
				node *temp1 = lower->right;
				lower->left = (*n)->left;
				int temp_balance = lower->balance;
				lower->balance= (*n)->balance;
				(*n)->balance = temp_balance;
				lower->right = (*n);
				(*n)->left = NULL;
				(*n)->right = temp1; 
				temp = (*n);
				(*n) = lower;
				
			}
			else {
				lower_of_bigger(&((*n)->right), &pai_lower);
				lower = pai_lower->left;
				node *temp1 = lower->right;
				lower->left = (*n)->left;
				int temp_balance = lower->balance;
				lower->balance= (*n)->balance;
				(*n)->balance = temp_balance;
				lower->right = (*n)->right;
				(*n)->left = NULL;
				(*n)->right = temp1; 
				temp = (*n);
				pai_lower->left=temp;
				(*n) = lower;
			}
			if (remove_node(&((*n)->right), temp) == 1) { //IDEM RIGHT ¬¬
			(*n)->balance += 1;
			if ( (*n)->balance == 2 ) {
				if ( (*n)->left ) {
					if ( ((*n)->left)->balance == 1 ) {
						rotation_right(n);
					}
					else if ( ((*n)->left)->balance == 0) {
						rotation_right(n);
					}
					else if ( ((*n)->left)->balance == -1) {
						rotation_left(&(*n)->left);
						rotation_right(n);
					}
				}
			}
			return ((*n)->balance == 0);

			}
		}
		else {	
			node *m = *n;
			if ((*n)->left)
				*n = (*n)->left;
			else 
				*n = (*n)->right;
		
		return 1;	
		}
}

	return 0;
}

void *procura_pai(node **n, void *end) {
		if (objectcmp(end, (*n)) == 0 )
			return NULL;
		else if (objectcmp(end, (*n)) == -1 )
			if (objectcmp(end, (*n)->left) == 0 )
				return (*n);
			else
				procura_pai(&(*n)->left, end);
		else if (objectcmp(end, (*n)) == 1 ) 
			if (objectcmp(end, (*n)->right) == 0 )
				return NULL;
			else
				procura_pai(&(*n)->right, end);
}

node *prox_nodo_rec(node *n) {
	if (n->left == NULL)
		return (n);
 	else 
		return prox_nodo_rec(n->left);
}

node *prox_nodo(node *n) {
	if (n->right == NULL) {
		node *pai = procura_pai(&raiz1, n);
		return pai;
	}
 	else 
		return prox_nodo_rec(n->right);
}

int chec_dist_consec(node *n) { //Checa distância entre dois nodos consecutivos
	void *end = n;
	void *prox = prox_nodo(n);
	if ((end+14+(n->tam))==(prox))
		return 0;
	else
		return 1;
}

int procura_disp_insere(node **n, int tam, void **retorno) {
	int inseriu;
	node *temp;
	if (!(*n))
		return 0;
	inseriu = procura_disp_insere(&(*n)->left, tam, retorno);
	if (inseriu==0) {
		if ((*n)->disp==1) {
			node *consecutivo = prox_nodo(*n);
			while (consecutivo!=NULL) {
				if (consecutivo->disp==1) {
					(*n)->tam+= 14 + consecutivo->tam;
					temp = *n;
					remove_node(&raiz1, consecutivo);
					*n = temp;
				}
				consecutivo = prox_nodo(consecutivo);
				
			}	
			int dif = (*n)->tam-tam;
			void *end_prox = (*n);
			end_prox=end_prox+14+tam;
			if (dif>=0) {// espaco suficiente para alocar
				(*n)->disp=0; inseriu=1;
				(*n)->tam=tam;
				*retorno = end_prox-tam;
				if (dif>=15) { //tamanho restante suficiente para criar outro nodo
					insere_por_end(&raiz1, end_prox, dif-14);
				}
				return 1;
			}
		}
	}
	if (inseriu==0)
		inseriu = procura_disp_insere(&(*n)->right, tam, retorno);
	return inseriu;
}

void imprMemoria() {
	printf("|");
	imprMemRec(&raiz1);
	printf("\n");
}

int imprMemRec(node **n) {
	int i;
	if (!(*n))
		return 0;
	imprMemRec(&(*n)->left);
	printf("%d",(*n)->disp);
	if ((*n)->disp==1)
		for (i=0; i<(*n)->tam; i++)
			printf("-");
	else
		for (i=0; i<(*n)->tam; i++)
			printf("*");
	printf("|");
	imprMemRec(&(*n)->right);
}

void procura_e_libera(node **n, void *end) {
		if (objectcmp(end, (*n)) == -1 ) {
			procura_e_libera(&(*n)->left, end);
		}
		else if (objectcmp(end, (*n)) == 1 ) {
			procura_e_libera(&(*n)->right, end);
		}
		else {
			(*n)->disp=1;
			node *consecutivo = prox_nodo(*n);
			if (consecutivo) {
				void *calc = (*n);
				void *cons_end = consecutivo;
				calc = calc+14+(*n)->tam;
				calc = cons_end - calc;
				(*n)->tam+= (int) calc;
				if (consecutivo->disp==1) {
					(*n)->tam+= 14 + consecutivo->tam;
					remove_node(&raiz1, consecutivo);
				}
			}
		}
}
/***** Malloc *****/
void *meuAlocaMem ( int num_bytes ) { //Procura posição livre, se não achar, insere a direita, ou seja, no topo da pilha
        void *retorno;
	int sucesso = procura_disp_insere(&raiz1, num_bytes, &retorno); 
        if (!sucesso) {
		insere_a_direita(&raiz1, num_bytes, &retorno);
	}
	return retorno;
}

/***** Calloc *****/
void *meuCalocaMem ( int quant, int num_bytes ) {
	int tam = quant * num_bytes;
        void *retorno;
	int sucesso = procura_disp_insere(&raiz1, tam, &retorno);
        if (!sucesso) {
		insere_a_direita(&raiz1, tam, &retorno);
	}
	return retorno;
}

/***** Realloc *****/
void *meuRealocaMem ( void *end, int num_bytes ) { //Libera memória já alocada para aquele nodo e aloca novamente em outro lugar
        void *retorno;
	meuLiberaMem(end);
	retorno = meuAlocaMem(num_bytes);
	return retorno;
}

/***** Free ******/
void  meuLiberaMem (void *end ) { //Endereço menos o tamanho do nodo (14) para chegar ao início da área alocado, então desaloca
	void *end_real = end-14;
	procura_e_libera(&raiz1,end_real);
}
