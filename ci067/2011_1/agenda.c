#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct No_St{
   char *nome;
   char *email;
   char *telefone;
   struct No_St *prox;
}No;


No *criaraiz(No *raiz){     /*Função do tipo apontador para lista, i.e., o tipo de função tem de ser igual ao tipo que retorna*/
 
    raiz = (No*)malloc(sizeof(No));
    raiz->prox=NULL;
 
    return (raiz);
}


void insere_no_fim(No *raiz,char *arq)
{
    No *novo,*aux;                                               // Cria novo no //
    char buffer[40];
    int tam,numero;
    FILE *fp;
    
    fp=fopen(arq,"a+");                    //ABRE O ARQUIVO INSERINDO NO FINAL

    novo = (No*) malloc(sizeof(No));
    novo->prox = NULL;
    
    printf("Digite o nome : \n");                  
    gets(buffer);                                            // BUFFER PARA INSERIR O NOME
    tam = strlen(buffer);                                     
    novo->nome = (char*) malloc (sizeof(char)*tam)+1;        // ALOCA ESPACO PARA O NOME
    strcpy(novo->nome , buffer);                             // COPIA PARA O *nome
	   
    printf("Digite o email : \n");
    gets(buffer);                                            //BUFFER PARA INSERIR O EMAIL
    tam = strlen(buffer);                                    
    novo->email = (char*) malloc (sizeof(char)*tam +1) ;     // ALOCA O ESPACO PARA O EMAIL
    strcpy(novo->email , buffer);                            // COPIA PARA O *email
    
    printf("Digite o telefone : \n");
    gets(buffer);
    tam = strlen(buffer);                                   
    novo->telefone = (char*) malloc (sizeof(char)*tam +1) ;
    strcpy(novo->telefone , buffer);  

    fputs(novo->nome,fp);
    fputs("\n",fp);
    fputs(novo->email,fp);
    fputs("\n",fp);
    fputs(novo->telefone,fp);
    fputs("\n",fp);

    if(raiz == NULL)
        raiz = novo;
    else
    { 
        aux = raiz;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }

   fclose(fp);
}

void escreve_no_arquivo(No *p , char *arq)
{
   No *aux;
   FILE *fp;

   fp=fopen(arq,"w+");
   aux = p->prox;

   while (aux != NULL)
   {
      
      fputs(aux->nome,fp);
      fputs("\n",fp);
      fputs(aux->email,fp);
      fputs("\n",fp);
      fputs(aux->telefone,fp);
      fputs("\n",fp);
      
      aux=aux->prox;
   }

  fclose(fp);
}
void remove_por_nome(No *raiz , char *arq){

No *aux1,*aux2;
char buffer[40];
      
   printf("Digite o nome a ser deletado\n");
   gets(buffer);
   aux1=raiz;
   
   do{
      aux2=aux1;
      aux1=aux1->prox;
   }while ((strcmp(aux1->nome,buffer) !=0 )&& (aux1->prox != NULL ));   // PROCURA NA LISTA
   
   if ((strcmp(aux1->nome,buffer)!= 0) && (aux1->prox == NULL )){      // SE O VALOR A SER DELETADO NAO FOR ENCONTRADO
      printf("Nome não encontrado\n");
   }
   else if ((strcmp(aux1->nome,buffer) == 0) && (aux1->prox == NULL )){  // SE O VALOR A SER DELETADO FOR O ULTIMO
      aux2->prox=NULL;
      free(aux1);
   }
   else if ((strcmp(aux1->nome,buffer) == 0) && (aux1->prox != NULL )){   // SE O VALOR A SER DELETADO FOR O DO MEIO
      aux2->prox=aux1->prox;
      free(aux1);
   }

   escreve_no_arquivo(raiz ,arq);

}

void imprime(No *p)
{
   No *aux;
   aux = p->prox;
     
   while (aux != NULL)
   {
      printf("O nome é : %s , Email é %s , O telefone é : %s \n",aux->nome , aux->email,aux->telefone);
      aux=aux->prox;
   }
}



//PROGRAMA PRINCIPAL
int main (int argc, char *argv[])
{

   int menu, tamagenda, i;
   No *raiz;
   
   if (argc == 1 )
   {
      printf("Reinicie o programa passando o nome do arquivo\n");
   }
   else
   {
      raiz = criaraiz(raiz);
      
      do
      {
         printf("Digite o numero da opcão desejada :\n 1-)Inserir \n 2-)Remover\n 3-)Imprimir \n 4-)Sair\n");
         scanf("%d",&menu);
         getchar();
         switch(menu)
         {
            case 1:
               insere_no_fim(raiz,argv[1]);
            break;
            case 2:
               remove_por_nome(raiz,argv[1]); 
            break;
            case 3:
               imprime(raiz);
            break;
         }
      }   
      while ( menu != 4 ); 
   }
}
