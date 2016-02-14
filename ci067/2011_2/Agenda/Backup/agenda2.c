/************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
************************/
/***********************
	Comentários Gerais:
		- Arrumar falha na leitura da última ID inserida (lê a partir da terceira linha)
		- Arruma função de leitura (falha de segmentação)
		- Arrumar a busca
		- Fazer as funções de altera e exclui "r + b" e fseek -> As duas funções fazem a mesma coisa. A função altera substitui a entrada por zero, "apagando logicamente"
		- Alterar o insere para procurar áreas apagadas logicamente e inserir nelas
************************/
/***********************
	Última Alteração: 25/Out/2011 18:00
************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**************
	ESTRUTURAS
**************/
typedef struct registro
{
	char *nome;
	char *email;
	char *telefone;
	int ID;
} Registro;
/**************
	FUNÇÕES
**************/
void TiraEnter (char *string)
{
	int n = strlen(string);
	string[n-1] = '\0';
}
void Le(int tam, char *string) //Lê string da linha de comando para uma variável temporária, aloca espaço exato para a variável
{
	char *aux = (char *) malloc (tam*sizeof(char));
	fgets (aux, (tam-1)*sizeof(char), stdin);
	int n = strlen(aux);
	printf("%d\n", n);
	TiraEnter(aux);
	string = (char *) malloc (n-1*sizeof(char));
	printf("%s\n", aux);
	strcpy(string, aux);
}
char * LeArquivo(int tam, FILE *arquivo) //Faz o mesmo da função anterior, mas lê do arquivo e não da entrada padrão
{
	char *aux = (char *) malloc (tam*sizeof(char));
	fgets(aux, (tam-1)*sizeof(char), arquivo);
	int n = strlen(aux);
	char *string = (char *) malloc (n*sizeof(char));
	string = aux;
	return string;
}
void InsereContato(char *agenda, int *ultimaID) //Insere contato no arquivo
{
	FILE *arquivo;
	int n;
	/***** Coleta as informações *****/
	Registro contato;
	/* Nome */
	printf("\nNome: ");
	Le(100, contato.nome);
	printf("%s\n", contato.nome);
	/* Email */
	printf("E-mail: ");
	Le(200, contato.nome);
	/* Telefone */
	printf("Telefone: ");
	Le(25, contato.nome);
	/* ID */
	*ultimaID = *ultimaID+1;
	contato.ID = *ultimaID;
	/***** Joga no arquivo *****/
	arquivo = fopen(agenda, "a +");
	fprintf(arquivo, "%d\n", contato.ID);
	fprintf(arquivo, "%s\n", contato.nome);
	fprintf(arquivo, "%s\n", contato.email);
	fprintf(arquivo, "%s\n", contato.telefone);
	fclose(arquivo);
	printf("\n------------------------------\n");
	printf("Contato salvo com a ID %d", contato.ID);
	printf("\n------------------------------\n");
	printf("Pressione enter para continuar");
	getchar();
}
int BuscaID(int ID, FILE *arquivo, int ultimaID, Registro *contato) // Faz busca a partir da ID e retorna falha ou sucesso
{
	int i = 0;
	char *auxID;
	do
	{

		auxID = LeArquivo(4, arquivo);
		contato->nome = LeArquivo(100, arquivo);
		contato->email = LeArquivo(500, arquivo);
		contato->telefone = LeArquivo(25, arquivo);
		i++;
	} while ((i <= ID) && (i <= ultimaID));
	if (i-- == ID)
	{
		i--;
		contato->ID = i;
		return 1;
	}
	else
	{
		return 0;
	}
}
void BuscaNome(char *nome, FILE *arquivo, int ultimaID) //Procura contato por nome. Como pode haver mais de um contato com o mesmo nome, percorre todo o arquivo e imprime conforme for encontrando
{
	Registro contato;
	int i;
	char *auxID;
	int encontrou = 0;
	for (i=0; i<=ultimaID; i++)
	{
		auxID = LeArquivo(5, arquivo);
		contato.nome = LeArquivo(100, arquivo);
		contato.email = LeArquivo(500, arquivo);
		contato.telefone = LeArquivo(25, arquivo);
		if (strstr(nome, contato.nome)) //Vê se uma string está contida na outra
		{
			printf("\n------------------------------\n");
			printf("ID: %s", auxID);
			printf("Nome: %s", contato.nome);
			printf("E-mail: %s", contato.email);
			printf("Telefone: %s", contato.telefone);
			encontrou = 1;
		}
	}
	if (encontrou == 0)
	{
		printf("\n------------------------------\n");
		printf("Contato não encontrado");
		printf("\n------------------------------\n");
		printf("Pressione enter para continuar");
		getchar();
	}
}
void RemoveContato(char *agenda)
{
	printf("\n------------------------------\n");
	printf("Digite a ID do contato a ser removido");
	printf("\n------------------------------\n");
}
void ProcuraContato(char *agenda, int ultimaID) //Busca contato por ID e por nome
{
	char opc;
	char *nome;
	char *auxID;
	int ID;
	int encontrou;
	FILE *arquivo = fopen(agenda, "r +");
	Registro *contato;
	printf("\n------------------------------\n");
	printf("Digite 1 para procurar contato por ID e 2 para procurar por nome");
	printf("\n------------------------------\n");
	opc = getchar();
	getchar();
	switch (opc)
	{
		case '1':
			printf("\nDigite a ID desejada\n");
			Le(5, auxID);
			ID = atoi(auxID);
			encontrou = BuscaID(ID, arquivo, ultimaID, contato);
			if (encontrou == 1)
			{
				printf("\n------------------------------\n");
				printf("ID: %d\n", contato->ID);
				printf("Nome: %s\n", contato->nome);
				printf("E-mail: %s\n", contato->email);
				printf("Telefone: %s\n", contato->telefone);
				printf("\n------------------------------\n");
			}
			else
			{
				printf("\n------------------------------\n");
				printf("ID não encontrada");
				printf("\n------------------------------\n");
			}
			break;
		case '2':
			printf("\nDigite o nome ou parte do nome a ser buscado\n");
			Le(100, nome);
			BuscaNome(nome, arquivo, ultimaID);
			break;
	}
	fclose(arquivo);
}
void AlteraContato()
{
	printf("\nAltera");
}
char ImprimeMenu (int ultimaID) // Imprime o Menu e retorna a opção digitada pelo usuário
{
	char opc;
	system("clear"); //Limpa a tela
	if (ultimaID == 0) //Verifica se a agenda está vazia. Se estiver, imprime o menu sem as opções de alterar, procurar e remover
	{
		printf("\nA agenda está vazia");
		printf("\nO que deseja fazer?");
		printf("\n------------------------------\n");
		printf("i - Inserir\n");
		printf("q - Sair");
		printf("\n------------------------------\n");
		opc = getchar();
	}
	else
	{
		printf("\nO que deseja fazer?\n");
		printf("------------------------------\n");
		printf("i - Inserir\n");
		printf("r - Remover\n");
		printf("p - Procurar\n");
		printf("a - Alterar\n");
		printf("q - Sair\n");
		printf("------------------------------\n");
		opc = getchar();
	}
	getchar(); //Pega o enter
	return opc;
}
int UltimaID (FILE *arquivo) // Devolve a última ID registrada
{
	int ID;
	char *auxID;
	char *sAux;
	if (feof(arquivo)) //Verifica se o arquivo está vazio
	{
		return 0;
	}
	else //Vai até o fim do arquivo e busca a última ID cadastrada
	{
		do 
		{
			auxID = LeArquivo(4, arquivo);
			sAux = LeArquivo(100, arquivo);
			sAux = LeArquivo(500, arquivo);
			sAux = LeArquivo(25, arquivo);
			printf("%s\n", sAux);
		}while (!feof(arquivo));
		free(sAux);
		ID = atoi(auxID);
		free(auxID);
		return (ID);
	}
}
/**************
	PROGRAMA PRINCIPAL
**************/
main(int argc, char **argv)
{	
	/***** Declaração de Variáveis *****/
	char opcao;
	FILE *arquivo;
	int i;
	char *agenda;
	int ultimaID;
	/***** Pega o parametro e transforma no arquivo *****/
	i = strlen(argv[1]); // Tamanho do nome do arquivo
	agenda = (char *) malloc (i*sizeof(char)); //Aloca espaço para o nome do arquivo
	agenda = argv[1];
	arquivo = fopen(agenda, "a +"); //Se o arquivo não existir, cria... ponteiro para o final do arquivo
	rewind(arquivo); //Volta ponteiro para o início
	ultimaID = UltimaID(arquivo);
	fclose(arquivo);
	/***** Menu *****/
	do
	{
		opcao = ImprimeMenu(ultimaID); //Imprime o menu
		switch (opcao)
		{
			case 'i':
				InsereContato(agenda, &ultimaID);
				break;
			case 'r':
				RemoveContato(agenda);
				break;
			case 'p':
				ProcuraContato(agenda, ultimaID);
				break;
			case 'a':
				AlteraContato();
				break;
			case 'q':
				printf("\n------------------------------\n");
				printf("Saindo...\n");
				printf("------------------------------\n");
				break;
			default:
				printf("\nOpção inexistente. Para selecionar uma opção digite-a duas vezes. Exemplo: 'ii'");
				break;
		}
	} while (opcao != 'q');
}
