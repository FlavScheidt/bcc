/*******************************************************************
Informações para conexão:
	PORTAS
		Servidor: MACALAN
			Entrada: 1915
			Saída:   6131
		Servidor: BOWMORE
			Entrada: 6131
			Saída:	 8499
		Servidor: PRIORAT
			Entrada: 8499
			Saída:	 1919
		Servidor: TALISKER
			Entrada: 1919
			Saída: 	 1915
	CONEXÕES:
		MACALAN 	-> BOWMORE
		BOWMORE 	-> PRIORAT
		PRIORAT 	-> TALISKER
		TALISKER 	-> MACALAN
		

******************************************************************/

#include "socket.h"

void RetiraEspacoFimString(char * st, int tamMax)
{
	int len = strlen(st);

	st[tamMax] = '\0';

	int i = 0;
	while(i<len)
	{
		if (st[i] == ' ')
			st[i] = '\0';
		i++;
	}
}

void SetConnection(int port)
{
        //STEP 1 - Criar o socket
        sock = socket(AF_INET, SOCK_DGRAM, 0);
        
        if (sock < 0)
        {
                perror("ERRO: problemas na criação do socket\n");
                exit(1);
        }
       
	//STEP 3 - Socket deve ser NÃO bloqueante (ou não poderemos fazer timeout)
	fcntl(sock, F_SETFL, O_NONBLOCK);

        //STEP 3 - BIND -> configurações da conexão
        struct sockaddr_in myaddr;

        memset((char *)&myaddr, 0, sizeof(myaddr));
        myaddr.sin_family = AF_INET;
        myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        
        myaddr.sin_port = htons(port);

        if (bind(sock, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) 
        {
	        perror("ERRO: problemas para configurar a conexão\n");
	        exit(1);
	}
}

void SetRing()
{
	gethostname(maquina.nome, 1024);
        if (strcmp(maquina.nome, "macalan") == 0)
	{
		maquina.portEntrada 	= 1915;
		maquina.portSaida 	= 6131;
		strcpy(maquina.maqRecebe, "talisker");
		strcpy(maquina.maqEnvia, "bowmore");
                SetConnection(maquina.portEntrada);
	}
        else if (strcmp(maquina.nome, "bowmore") == 0)
	{
		maquina.portEntrada	= 6131;
		maquina.portSaida	= 8499;
		strcpy(maquina.maqRecebe, "macalan");
		strcpy(maquina.maqEnvia, "priorat");
                SetConnection(maquina.portEntrada);
	}
	else if (strcmp(maquina.nome, "priorat") == 0)
	{
		maquina.portEntrada	= 8499;
		maquina.portSaida	= 1919;
		strcpy(maquina.maqRecebe, "priorat");
		strcpy(maquina.maqEnvia, "talisker");
		SetConnection(maquina.portEntrada);
	}
	else if (strcmp(maquina.nome, "talisker") == 0)
	{
		maquina.portEntrada	= 1919;
		maquina.portSaida	= 1915;
		strcpy(maquina.maqRecebe, "priorat");
		strcpy(maquina.maqEnvia, "macalan");
		SetConnection(maquina.portEntrada);
	}
	else
		fprintf(stderr, "ERRO: Esta máquina não é permitida no anel\n");

}

void Send(char * message)
{
        struct hostent *hp;
        struct sockaddr_in servaddr;
	struct in_addr **addr_list;

	int i;

        //Informações da máquina destino
        memset((char*)&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(maquina.portSaida);

        //Procura o IP da máquina destino a partir do nome
        hp = gethostbyname(maquina.maqEnvia);
        if (!hp) 
        {
	        fprintf(stderr, "ERRO: impossível obter o endereço de %s\n", maquina.maqEnvia);
	        exit(1);
        }

        //Preenche a estrutura com as informações do dentino
        memcpy((void *)&servaddr.sin_addr, hp->h_addr_list[0], hp->h_length);

        //Envia a mensagem
        if (sendto(sock, message, strlen(message), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	        perror("ERRO: Erro ao enviar a mensagem");
}


double TimeStamp()
{
	struct timeval tp;
	gettimeofday(&tp, NULL);
	return((double)(tp.tv_sec + tp.tv_usec/1000000.0));
}

void Get()
{

	struct sockaddr_in myaddr;
        struct sockaddr_in remaddr;
        socklen_t addrlen = sizeof(remaddr);

	double timeIn, timeFi;

	timeIn = TimeStamp();
	timeFi = timeIn;
	
	recvlen = 0;

        while ((timeFi - timeIn) <= TIMEOUT && recvlen <= 0)
        {
                recvlen = recvfrom(sock, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
                timeFi = TimeStamp();

		if (recvlen == 1)
		{
			fprintf(stderr, "ERRO ao receber mensagem\n");
			exit(1);
		}
        }

	if (recvlen == 0)
	{
		fprintf(stderr, "\nTIMEOUT. Encerrando jogo.\n");
		exit(1);
	}
		
	buf[recvlen] = '\0';
}

void EnterRing()
{
	mensagem  recebe;
	struct sockaddr_in muaddr;
	struct sockaddr_in remaddr;
	socklen_t addrlen = sizeof(remaddr);

	double timeIn;
	double timeFi;
	double tempo;

	char aux[BUFSIZE];

	int send = 0;

	int reset	= 0;
	//O macalan aguarda receber o nome dos três outros servidores
	//Quando recebe todos, envia um sinal de reset pelo anel
	if(strcmp(maquina.nome, "macalan") == 0)
	{
		fprintf(log, "<%f> Aguardando jogadores\n", TimeStamp()); fflush(log);
		while (reset == 0)
		{
			
			recvlen = recvfrom(sock, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
			if (recvlen > 0)
			{
				buf[recvlen] = '\0';
				fprintf(log, "<%f> recebido: %s\n", TimeStamp(), buf);fflush(log);
				if (strstr(buf, "bowmore") != NULL && strstr(buf, "talisker") != NULL && strstr(buf, "priorat") != NULL)
				{
					reset = 1;
					fprintf(log, "<%f> Jogadores Conectados\n", TimeStamp());fflush(log);
				}
				else
				{
					fprintf(log, "<%f> recebido: %s aguardando jogadores restantes\n", TimeStamp(), buf);fflush(log);
					Send(buf);
				}
			}
		}
		
		fprintf(log, "<%f> Enviado reset\n", TimeStamp());fflush(log);
		Send("macalan :all     :0:0000:000: ");
		
		reset = 0;
		while(reset == 0)
		{
			fprintf(log, "<%f> Aguardando volta do reset \n", TimeStamp());fflush(log);
			while(AguardaMensagem(&recebe) != 3);
			
			if (recebe.tipo[0] == '0')
				reset = 1;
			else
				Send("macalan :all     :0:0000:000: ");
		}

		bastao = 1;
	}
	else if (strcmp(maquina.nome, "bowmore") == 0)
	{
		//O Bowmore apenas envia a mensagem deque está no servidor. Envia até receber o reset
		fprintf(log, "<%f> Enviando nome para entrada \n", TimeStamp());fflush(log);
		Send("macalan :bowmore ");
		fprintf(log,"<%f> Aguardando reset\n", TimeStamp());fflush(log); 
		while (reset == 0)
		{
			timeIn = TimeStamp();
			timeFi = timeIn;
			tempo = 0;
			while (tempo <= TIMEOUT_CONEXAO && recvlen <= 0)
			{
				recvlen = recvfrom(sock, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
				timeFi = TimeStamp();
				tempo = timeFi - timeIn;
			}
			
			buf[recvlen] = '\0';
			recebe = DivideMsg(buf);
			if (recebe.tipo[0] == (char)'0')
			{
				fprintf(log, "<%f> Reset recebido!\n", TimeStamp());fflush(log);
				reset = 1;
				fprintf(log, "<%f> Retransmitindo reset\n", TimeStamp());fflush(log);
				send = 0;
				while (send <= 10)
				{
					Send(buf);
					send++;
				}
				Send(buf);
			}
			else
			{
				fprintf(log, "<%f> Reenviando nome\n", TimeStamp());fflush(log);
				Send("macalan :bowmore :");
			}
		}
	}
	else
	{
		//Essas máquinas ficam na escuta, até receber a mensagem anterior, então retransmitem
		
		while (recebe.tipo[0] != (char) '0')
		{
			fprintf(log, "<%f> Aguardando mensagem\n", TimeStamp());fflush(log);
			recvlen = 0;
			while (recvlen <= 0)
				recvlen = recvfrom(sock, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &addrlen);

	
			fprintf(log, "<%f> recebido: %s\n", TimeStamp(), buf);
			buf[recvlen] = '\0';
			recebe = DivideMsg(buf);

			if (recebe.tipo[0] != (char) '0')
			{
				strcpy(aux, buf);
				strcat(aux, ":");
				strcat(aux, maquina.nome);
				fprintf(log, "<%f> Enviando %s\n", TimeStamp(), aux);fflush(log);
				Send(aux);
			}
		}

		Send(buf);
		fprintf(log, "<%f> Retransmitindo: %s\n", TimeStamp(), buf);fflush(log);
		fprintf(log, "<%f> Jogadores conectados!\n", TimeStamp());fflush(log);
	}
}

void PassaBastao()
{
	char msg[BUFSIZE];
	fprintf(log, "<%f> Enviando bastão\n", TimeStamp()); fflush(log);

	strcpy(msg, maquina.nome);
	if (strcmp(maquina.nome, "talisker") == 0)
	{
		msg[8] = (char) ':';
		msg[9] = '\0';
	}
	else 
	{
		strcat(msg, " :");
	}

	strcat(msg, maquina.maqEnvia);
	if (strcmp(maquina.maqEnvia, "talisker") == 0)
		msg[17] = (char) ':';
	else
	{
		strcat(msg, " :");
	}

	strcat(msg, "1:0000:000: ");

	fprintf(log, "<%f> %s\n", TimeStamp(), msg);fflush(log);

	bastao = 0;

	Send(msg);
}

mensagem DivideMsg(char * msg)
{
	mensagem retorno;
	int i, k;
	int max = strlen(msg);

	i=0;
	k=0;
	
	//Origem
	while(i<8)
	{
		retorno.envia[i] = msg[k];
		i++;
		k++;
	}
	RetiraEspacoFimString(retorno.envia, 8);
	//fprintf(log, "\n <%f> envia: %s", TimeStamp(), retorno.envia);
	//Destino
	k++;
	i=0;
	while(i<8)
	{
		retorno.recebe[i] = msg[k];
		i++;
		k++;
	}
	RetiraEspacoFimString(retorno.recebe, 8);
	//fprintf(log, " recebe: %s", retorno.recebe);
	//Tipo
	k++;
	retorno.tipo[0] = (char) msg[k];
	k++;
	RetiraEspacoFimString(retorno.tipo, 1);
	//fprintf(log, " tipo: %s", retorno.tipo);
	//Recebimento
	k++;
	i=0;
	while (i<4)
	{
		retorno.rec[i] = msg[k];
		i++;
		k++;
	}
	RetiraEspacoFimString(retorno.rec, 4);
	//fprintf(log, " rec: %s", retorno.rec);
	//Sequencia
	k++;
	i=0;
	while(i<3)
	{
		retorno.seq[i] = msg[k];
		i++;
		k++;
	}
	RetiraEspacoFimString(retorno.seq, 3);
	//fprintf(log, " seq: %s", retorno.seq);
	//Mensagem
	k++;
	i=0;
	while(k<max)
	{
		retorno.msg[i] = msg[k];
		i++;
		k++;
	}
	RetiraEspacoFimString(retorno.msg, max);
	//fprintf(log, " msg: %s\n", retorno.msg); fflush(log);
	return retorno;

}

void LimpaBuf()
{
	int i=0;
	while (i<BUFSIZE)
	{
		buf[i] = '\0';
		i++;
	}
}

void RetiraDoAnel(mensagem * recebe)
{
	int aguarda;
	if (strcmp(recebe->recebe, "all") == 0)
		if (strcmp(recebe->rec, "1111") != 0)
		{
		}
	else if (strcmp(recebe->recebe, "macalan") == 0)
		if (strcmp(recebe->rec, "1000") != 0)
		{
		}
        else if (strcmp(recebe->recebe, "bowmore") == 0)
                if (strcmp(recebe->rec, "0100") != 0)
                {
		}

	else if (strcmp(recebe->recebe, "priorat") == 0)
	        if (strcmp(recebe->rec, "0010") != 0)
	        {
	        }
	else if (strcmp(recebe->recebe, "talisker") == 0)
	        if (strcmp(recebe->rec, "0001") != 0)
		{
                }

}

int AguardaMensagem(mensagem * recebido)
{
	LimpaBuf();
	Get();

	if (recvlen > 0)
	{
		*recebido = DivideMsg(buf);

		fprintf(log,"<%f> Mensagem recebida: %s \n", TimeStamp(), buf);fflush(log);

		if (recebido->tipo[0] == (char) '1') //Bastão
		{
			fprintf(log, "<%f> Bastão recebido\n", TimeStamp());fflush(log);
			bastao = 1;
			tBastao = TimeStamp();
			return 0;
		}
		else if (strcmp(recebido->envia, maquina.nome) == 0) //Retira msg do anel
		{
			fprintf(log, "<%f> Mensagem deve ser retirada do anel\n", TimeStamp()); fflush(log);
			if (strcmp(recebido->recebe, "all") == 0)
				if (strcmp(maquina.nome, "macalan") == 0)
					buf[20] = (char)'1';
				else if (strcmp(maquina.nome, "bowmore") == 0)
				        buf[21] = (char)'1';
				else if (strcmp(maquina.nome, "priorat") == 0)
				        buf[22] = (char)'1';
				else if (strcmp(maquina.nome, "talisker") == 0)
				        buf[23] = (char)'1';

			RetiraDoAnel(recebido);
			return 3;
		}
		else if (strcmp(recebido->recebe, maquina.nome) == 0 || strcmp(recebido->recebe, "all") == 0) //Mensagem precisa ser tratada
		{
			if (strcmp(maquina.nome, "macalan") == 0)
				buf[20] = (char)'1';
			else if (strcmp(maquina.nome, "bowmore") == 0)
				buf[21] = (char)'1';
			else if (strcmp(maquina.nome, "priorat") == 0)
				buf[22] = (char)'1';
			else if (strcmp(maquina.nome, "talisker") == 0)
				buf[23] = (char)'1';
			return 1;
		}
		else
		{
			fprintf(log, "<%f> Retransmitindo %s \n", TimeStamp(), buf); fflush(log);
			Send(buf);
			return 2;
		}
	}
}
