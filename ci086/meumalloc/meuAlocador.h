#ifndef _bstree_
#define _bstree_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*----------------------------------------------------------------------------*/
/* Objeto inserido dentro de cada no da arvore                                */ 
/*----------------------------------------------------------------------------*/
typedef int object;

/*----------------------------------------------------------------------------*/
/* Estrutura de arvore binaria sem balanceamento                              */ 
/*----------------------------------------------------------------------------*/
typedef struct node {
    struct node *left;
    struct node *right;
    int tam;
    char disp;
    char balance;
} node;

typedef node *tree;


/*----------------------------------------------------------------------------*/
/* Funcoes para trabalhar com o objeto                                        */
/*----------------------------------------------------------------------------*/
void fprintf_object                 (FILE *stream, object o);
int objectcmp                       (void *o1, void *o2);
int modulo                          (int n);

/*----------------------------------------------------------------------------*/
/* Funcoes para trabalhar com os nos                                          */
/*----------------------------------------------------------------------------*/
node *create_node                   (node **n, int tam);
node* destroy_node                  (node **n);

/*----------------------------------------------------------------------------*/
/* Funcoes de rotacoes                                                        */
/*----------------------------------------------------------------------------*/
void rotation_left                  (node **n);
void rotation_right                 (node **n);

/*----------------------------------------------------------------------------*/
/* Funcoes de incersao remocao e busca                                        */
/*----------------------------------------------------------------------------*/
int insereSemBal                    (node **n, object *o);
int insert_node                     (node **n, object *o);
int removeSemBal                    (node **n, object *o);
int remove_node                     (node **n, void *end);
void procura_e_libera               (node **n, void *end);


/*----------------------------------------------------------------------------*/
/* Funcoes que podem auxiliar o desenvolvimento do trabalho                   */
/*----------------------------------------------------------------------------*/
void lower_of_bigger             (node **n, node **pai_lower);
object* bigger_of_lower             (node **n);
void show_tree                      (FILE *stream, node *n, int b);
int print_tree_border               (node **n);
int print_tree                      (node **n);
int calcula_balanc                  (node **n);
int calcula_contanodos              (node **n);
int particionar                     (node **n, int val, int *num_rots);
int partPontoMed                    (node **n, int *num_rots);

#endif
