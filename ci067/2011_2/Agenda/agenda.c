/************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
************************/
/***********************
	Comentários Gerais:
		- Arrumar a função modificar
************************/
/***********************
	Última Alteração: 20/Out/2011 15:00
************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**************
	ESTRUTURAS
**************/
typedef struct registro
{
	char nome[200];
	char email[350];
	char telefone[15];
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
void InsereContato(char *agenda, int *ultimaID) //Insere contato no arquivo
{
	FILE *arquivo;
	/***** Coleta as informações *****/
	Registro contato;
	/* Nome */
	printf("\nNome: ");
	fgets(contato.nome, (200*sizeof(char)), stdin);
	/* Email */
	printf("E-mail: ");
	fgets(contato.email, (350*sizeof(char)), stdin);
	/* Telefone */
	printf("Telefone: ");
	fgets(contato.telefone, (15*sizeof(char)), stdin);
	/* ID */
	*ultimaID = *ultimaID+1;
	contato.ID = *ultimaID;
	/***** Joga no arquivo *****/
	arquivo = fopen(agenda, "a +");
	fprintf(arquivo, "%d\n", contato.ID);
	fprintf(arquivo, "%s", contato.nome);
	fprintf(arquivo, "%s", contato.email);
	fprintf(arquivo, "%s", contato.telefone);
	fclose(arquivo);
	printf("\n------------------------------\n");
	printf("Contato salvo com a ID %d", contato.ID);
	printf("\n------------------------------\n");
	getchar();
}
int BuscaID(int ID, FILE *arquivo, int ultimaID, Registro *contato) // Faz busca a partir da ID e retorna falha ou sucesso
{
	int i = 0;
	char auxID[5];
	do //Vai lendo as entradas até o fim do arquivo
	{
		i++;
		/* ID */
		fgets(auxID, 5*sizeof(char), arquivo);
		contato->ID = atoi(auxID);
		/* Nome */
		fgets(contato->nome, 200*sizeof(char), arquivo);
		/* Email */
		fgets(contato->email, 350*sizeof(char), arquivo);
		/* Telefone */
		fgets(contato->telefone, 15*sizeof(char), arquivo);
		if (contato->ID != ID) //Se a ID não foi encontrada, pula direto para o do
		{
			continue;
		}
		return 1; //Se a ID foi encontrada, retorna verdadeiro
	} while (i < ultimaID);
	return 0; //Se não achou a ID, retorna falso
}
void BuscaNome(char *nome, FILE *arquivo, int ultimaID) //Procura contato por nome. Como pode haver mais de um contato com o mesmo nome, percorre todo o arquivo e imprime conforme for encontrando
{
	Registro contato;
	char auxID[5];
	int i = 0;
	int encontrou = 0;
	do
	{
		/* ID */
		fgets(auxID, 5*sizeof(char), arquivo);
		contato.ID = atoi(auxID);
		/* Nome */
		fgets(contato.nome, 200*sizeof(char), arquivo);
		/* Email */
		fgets(contato.email, 350*sizeof(char), arquivo);
		/* Telefone */
		fgets(contato.telefone, 15*sizeof(char), arquivo);
		if ((strstr(contato.nome, nome) != NULL) || (strstr(nome, contato.nome)!=NULL)) //Sempre que encontra uma ocorrência, imprime na tela
		{
			encontrou = 1;
			printf("\n------------------------------\n");
			printf("ID: %d\n", contato.ID);
			printf("Nome: %s", contato.nome);
			printf("E-mail: %s", contato.email);
			printf("Telefone: %s", contato.telefone);
			printf("\n------------------------------\n");
			getchar();
		}
		i++;
	} while (i < ultimaID);
	if (encontrou == 0)
	{
		printf("\n------------------------------\n");
		printf("Contato não encontrado");
		printf("\n------------------------------\n");
		getchar();
	}
}
void RemoveContato(char *agenda, int ultimaID)
{
	FILE *arquivo = fopen(agenda, "r + b"); //Abre arquivo binário para leitura e escrita
	int ID = 0;
	char auxID[5];
	int i =0;
	int encontrou = 0;
	long int posicao;
	Registro contato;
	printf("\n------------------------------\n");
	printf("Digite a ID do contato a ser removido");
	printf("\n------------------------------\n");
	fgets(auxID, 5*sizeof(char), stdin);
	ID = atoi(auxID);
	do
	{
		posicao = ftell(arquivo); //posição do ponteiro no arquivo no início la leitura do contato atual
		/* ID */
		fgets(auxID, 5*sizeof(char), arquivo);
		contato.ID = atoi(auxID);
		/* Nome */
		fgets(contato.nome, 200*sizeof(char), arquivo);
		/* E-mail */
		fgets(contato.email, 350*sizeof(char), arquivo);
		/* Telefone */
		fgets(contato.telefone, 15*sizeof(char), arquivo);
		if (ID != contato.ID)
		{
			i++;
			continue;
		}
		i = ultimaID; //Para sair do loop
		encontrou = 1;
		/***** Manipulação de arquivo *****/
		fseek (arquivo, posicao, 0); //Move o ponteiro do arquivo de volta para o início do contato
		/* ID */
		fwrite("-1\n",3*sizeof(char), 1, arquivo);  // Marca o contato como desativado
		fclose(arquivo);
		printf("\n------------------------------\n");
		printf("Contato Apagagado com Sucesso");
		printf("\n------------------------------\n");
		getchar();
	} while (i < ultimaID);
	if (encontrou == 0)
	{
		printf("\n------------------------------\n");
		printf("ID não encontrada");
		printf("\n------------------------------\n");
		getchar();
	}
}
void ProcuraContato(char *agenda, int ultimaID) //Busca contato por ID e por nome
{
	char opc;
	char nome[200];
	char auxID[5];
	int ID;
	int encontrou = 0;
	FILE *arquivo = fopen(agenda, "r +");
	Registro contato;
	printf("\n------------------------------\n");
	printf("Digite 1 para procurar contato por ID e 2 para procurar por nome");
	printf("\n------------------------------\n");
	opc = getchar();
	getchar();
	switch (opc)
	{
		case '1':
			printf("\nDigite a ID desejada\n");
			fgets(auxID, (5*sizeof(char)), stdin);
			ID = atoi(auxID);
			encontrou = BuscaID(ID, arquivo, ultimaID, &contato);
			if (encontrou == 1)
			{
				printf("\n------------------------------\n");
				printf("ID: %d\n", contato.ID);
				printf("Nome: %s", contato.nome);
				printf("E-mail: %s", contato.email);
				printf("Telefone: %s", contato.telefone);
				printf("\n------------------------------\n");
				getchar();
			}
			else
			{
				printf("\n------------------------------\n");
				printf("ID não encontrada");
				printf("\n------------------------------\n");
				getchar();
			}
			break;
		case '2':
			printf("\nDigite o nome ou parte do nome a ser buscado\n");
			fgets(nome, 200*sizeof(char), stdin);
			BuscaNome(nome, arquivo, ultimaID);
			break;
	}
	fclose(arquivo);
}
void AlteraContato(char *agenda, int ultimaID)
{
	FILE *arquivo = fopen(agenda, "r + b"); //Abre arquivo binário para leitura e escrita
	int ID = 0;
	char auxID[5];
	int i =0;
	int n;
	int encontrou = 0;
	long int posicao;
	Registro contato;
	printf("\n------------------------------\n");
	printf("Digite a ID do contato a ser modificado");
	printf("\n------------------------------\n");
	fgets(auxID, 5*sizeof(char), stdin);
	ID = atoi(auxID);
	do
	{
		posicao = ftell(arquivo); //posição do ponteiro no arquivo no início la leitura do contato atual
		/* ID */
		fgets(auxID, 5*sizeof(char), arquivo);
		contato.ID = atoi(auxID);
		/* Nome */
		fgets(contato.nome, 200*sizeof(char), arquivo);
		/* E-mail */
		fgets(contato.email, 350*sizeof(char), arquivo);
		/* Telefone */
		fgets(contato.telefone, 15*sizeof(char), arquivo);
		if (ID != contato.ID)
		{
			i++;
			continue;
		}
		encontrou = 1;
		/****** Imprime Contato *****/
		printf("\n------------------------------\n");
		printf("Nome: %s", contato.nome);
		printf("Email: %s", contato.email);
		printf("Telefone: %s", contato.telefone);
		printf("\n------------------------------\n");
		/* Nome */
		printf("\nNome: ");
		fgets(contato.nome, 200*sizeof(char), stdin);
		/* Email */
		printf("\nE-mail: ");
		fgets(contato.email, 350*sizeof(char), stdin);
		/* Telefone */
		printf("\nTelefone: ");
		fgets(contato.telefone, 15*sizeof(char), stdin);
		/****** Joga no Arquivo ******/
		fseek(arquivo, posicao, 0);
		n = strlen(auxID);
		fwrite(auxID, n*sizeof(char), 1, arquivo);
		n = strlen(contato.nome);
		fwrite(contato.nome, n*sizeof(char), 1, arquivo);
		n = strlen(contato.email);
		fwrite(contato.email, n*sizeof(char), 1, arquivo);
		n = strlen(contato.telefone);
		fwrite(contato.telefone, n*sizeof(char), 1, arquivo);
		fclose(arquivo);
		printf("\n------------------------------\n");
		printf("Contato Modoficado com Sucesso");
		printf("\n------------------------------\n");
		getchar();
		i = ultimaID; //Para sair do loop
	} while (i < ultimaID);
	if (encontrou == 0)
	{
		printf("\n------------------------------\n");
		printf("ID não encontrada");
		printf("\n------------------------------\n");
		getchar();
	}
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
int UltimaID (char *agenda) // Devolve a última ID registrada
{
	FILE *arquivo;
	int ID;
	char auxID[5];
	char nome[200];
	char email[350];
	char telefone[15];
	arquivo = fopen(agenda, "a +"); // Se o arquivo não existir, cria... Ponteiro aponta para o fim do arquivo
	rewind(arquivo); //Retorna ponteiro para o início do arquivo
	if (feof(arquivo)) //Verifica se o arquivo está vazio
	{
		fclose(arquivo);
		return 0;
	}
	else //Vai até o fim do arquivo e busca a última ID cadastrada
	{
		fclose(arquivo);
		arquivo = fopen(agenda, "r+");
		do 
		{
			fgets(auxID, 5*sizeof(char), arquivo);
			fgets(nome, 200*sizeof(char), arquivo);
			fgets(email, 350*sizeof(char), arquivo);
			fgets(telefone, 15*sizeof(char), arquivo);
			printf("%s\n", auxID);
		}while (!feof(arquivo));
		ID = atoi(auxID);
		fclose(arquivo);
		return (ID);
	}
}
/**************
	PROGRAMA PRINCIPAL
**************/
int main(int argc, char **argv)
{	
	/***** Declaração de Variáveis *****/
	char opcao;
	int i;
	char *agenda;
	int ultimaID;
	/***** Pega o parametro e transforma no arquivo *****/
	i = strlen(argv[1]); // Tamanho do nome do arquivo
	agenda = (char *) malloc (i*sizeof(char)); //Aloca espaço para o nome do arquivo
	agenda = argv[1];
	ultimaID = UltimaID(agenda);
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
				RemoveContato(agenda, ultimaID);
				break;
			case 'p':
				ProcuraContato(agenda, ultimaID);
				break;
			case 'a':
				AlteraContato(agenda, ultimaID);
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
	return 1;
}
