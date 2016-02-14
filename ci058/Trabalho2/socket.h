#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/ioctl.h>          
#include <sys/types.h>         
#include <sys/socket.h>        
#include <netinet/in.h>
#include <net/if.h> 	
#include <arpa/inet.h>
#include <net/ethernet.h>       
#include <linux/if_packet.h>
#include <stddef.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <sys/un.h>
#include <netdb.h>
#include <sys/uio.h>

#define BUFSIZE 2048
#define TIMEOUT 25.0 //Cada um tem 60 segundos para fazera jogada + 10 segundos pde timeout de transmissão
#define TIMEOUT_CONEXAO 25.0
#define TIMEOUT_BASTAO 350.0
#define TIMEOUT_JOGADA 50.0

//Log
FILE *log;

//Socket
int sock;

//Buffer
unsigned char buf[BUFSIZE];
int recvlen;

//Bastao
int bastao;

//Tempo do bastao
double tBastao;

//Pontuacao
int macPri;
int bowTal;

//Informações da máquina
typedef struct InfoMaquina
{
	char nome [9];
	char maqRecebe[9];
	char maqEnvia[9];
	int  portEntrada;	
	int  portSaida;
} InfoMaquina;

InfoMaquina maquina;

//Mensagem
typedef struct Mensagem
{
	char envia	[9];
	char recebe	[9];
	char tipo	[2];
	char msg	[BUFSIZE-23];
	char rec	[5];
	char seq	[4];
} mensagem;

int jogo; 

//Valores
int truco; //1 para pediu, 2 para aceito
int seis;  //1 para pedido, 2 para aceito

//Funções do socket
void SetConnection (int port);
void SetRing();
void Send(char *message);
double TimeStamp();
void Get();
void EnterRing();
void PassaBastao();
int AguardaMensagem(mensagem * recebido);
mensagem DivideMsg(char * msg);

//Uma carta
typedef char carta[3];

//Manilha
carta manilha;

//O Baralho
carta baralho[40];
 
//As mãos
typedef carta mao[2];
mao minhaMao;
mao maoMacalan;
mao maoBowmore;
mao maoPriorat;
mao maoTalisker;

//O o que já foi tirado do baralho
int sorteadas[40];
int sort;
