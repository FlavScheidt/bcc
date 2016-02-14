#include "socket.h"

void CarregaBaralho()
{
	strcpy(baralho[0],"AP\0");
	strcpy(baralho[1],"2P\0");
	strcpy(baralho[2],"3P\0");
	strcpy(baralho[3],"4P\0");
	strcpy(baralho[4],"5P\0");
	strcpy(baralho[5],"6P\0");
	strcpy(baralho[6],"7P\0");
	strcpy(baralho[7],"QP\0");
	strcpy(baralho[8],"JP\0");
	strcpy(baralho[9],"KP\0");
	strcpy(baralho[10],"AC\0");
	strcpy(baralho[11],"2C\0");
	strcpy(baralho[12],"3C\0");
	strcpy(baralho[13],"4C\0");
	strcpy(baralho[14],"5C\0");
	strcpy(baralho[15],"6C\0");
	strcpy(baralho[16],"7C\0");
	strcpy(baralho[17],"QC\0");
	strcpy(baralho[18],"JC\0");
	strcpy(baralho[19],"KC\0");
	strcpy(baralho[20],"AE\0");
	strcpy(baralho[21],"2E\0");
	strcpy(baralho[22],"3E\0");
	strcpy(baralho[23],"4E\0");
	strcpy(baralho[24],"5E\0");
	strcpy(baralho[25],"6E\0");
	strcpy(baralho[26],"7E\0");
	strcpy(baralho[27],"QE\0");
	strcpy(baralho[28],"JE\0");
	strcpy(baralho[29],"KE\0");
	strcpy(baralho[30],"AO\0");
	strcpy(baralho[31],"2O\0");
	strcpy(baralho[32],"3O\0");
	strcpy(baralho[33],"4O\0");
	strcpy(baralho[34],"5O\0");
	strcpy(baralho[35],"6O\0");
	strcpy(baralho[36],"7O\0");
	strcpy(baralho[37],"QO\0");
	strcpy(baralho[38],"JO\0");
	strcpy(baralho[39],"KO\0");
}

int ConfereCartaSorteada(int nCarta)
{
	int j = 0;
	while (j < 40)
	{
		if (nCarta == sorteadas[j])
			return 1;
		j++;
	}

	return 0;
}

int SorteiaCarta()
{
	int nCarta;
	int validaCarta;
	
	nCarta = (rand() % 40);
	validaCarta = ConfereCartaSorteada(nCarta);
	while (validaCarta == 1)
	{
		nCarta = (rand() % 40);
		validaCarta = ConfereCartaSorteada(nCarta);
	}
	return nCarta;
}

void Dealer()
{
	int nCarta;
	char msg[BUFSIZE];
	int i, j;
	int validaCarta = 0;

	srand((unsigned)time(NULL));

	i = 0;
	while (i<40)
	{
		sorteadas[i] = 40;
		i++;
	}

	j=0;
	i = 0;
	while (i<3)
	{
		nCarta = SorteiaCarta();
		sorteadas[j] = nCarta;
		strcpy(minhaMao[i],baralho[nCarta]);
		j++;
		i++;
	}

	i = 0;
	while (i<3)
	{
		nCarta = SorteiaCarta();
		sorteadas[j] = nCarta;
		strcpy(maoBowmore[i], baralho[nCarta]);
		i++;
		j++;
	}

	i=0;
	while (i<3)
	{
	        nCarta = SorteiaCarta();
		sorteadas[j] = nCarta;
		strcpy(maoPriorat[i], baralho[nCarta]);
		i++;
		j++;
	}

	i=0;
        while (i<3)
        {
                nCarta = SorteiaCarta();
		sorteadas[j] = nCarta;
		strcpy(maoTalisker[i], baralho[nCarta]);
		i++;
		j++;
	}

	//Cartas do Bowmore
	strcpy(msg, "macalan :bowmore :2:0000:000:");
	i=0;
	while(i<3)
	{
		strcat(msg, maoBowmore[i]);
		i++;
	}
	fprintf(log, "<%f> Enviando cartas bowmore %s\n", TimeStamp(), msg);
	Send(msg);
	
	//Cartas do Priorat
	strcpy(msg, "macalan :priorat :2:0000:000:");
	i=0;
	while (i<3)
	{
		strcat(msg, maoPriorat[i]);
		i++;
	}
	fprintf(log, "<%f> Enviando cartas priorat %s\n", TimeStamp(), msg);
	Send(msg);

	//Cartas do Talisker
	strcpy(msg, "macalan :talisker:2:0000:000:");
	i=0;
	while (i<3)
	{
		strcat(msg, maoTalisker[i]);
		i++;
	}
	fprintf(log, "<%f> Enviando cartas talisker%s\n", TimeStamp(), msg);fflush(log);
	Send(msg);

	//Manilha
	nCarta = SorteiaCarta();
	sorteadas[j] = nCarta;
	j++;

	strcpy(manilha, baralho[nCarta]);
	strcpy(msg, "macalan :all     :3:0000:000:");
	strcat(msg, manilha);

	fprintf(log, "<%f> Manilha: %s \n", TimeStamp(), manilha);
	Send(msg);
	fprintf(log, "<%f> Enviando manilha\n", TimeStamp()); fflush(log);
	Send(msg);
}

void WaitCards()
{
	mensagem divide;
	int i, j;

	fprintf(log, "<%f> Aguardando Cartas\n", TimeStamp());fflush(log);
	
	do
	{
		while (AguardaMensagem(&divide) != 1);
		Send(buf);
	} while (divide.tipo[0] != (char) '2');

	fprintf(log, "<%f> Minha mao: ", TimeStamp());fflush(log);

	minhaMao[0][0] = divide.msg[0];
	minhaMao[0][1] = divide.msg[1];
	
	minhaMao[1][0] = divide.msg[2];
	minhaMao[1][1] = divide.msg[3];

	minhaMao[2][0] = divide.msg[4];
	minhaMao[2][1] = divide.msg[5];
	
	fprintf(log, "%s %s %s\n", minhaMao[0], minhaMao[1], minhaMao[2]);fflush(log);

	Send(buf);

	do
	{
		while (AguardaMensagem(&divide) != 1);
		Send(buf);
		
	} while (divide.tipo[0] != (char)'3');

	strcpy(manilha, divide.msg);

	fprintf(log, "<%f> Manilha recebida: %s\n", TimeStamp(), manilha); fflush(log);

	Send(buf);

}

void ComputaPontos()
{
}

int TrataRecepcao(mensagem recebe)
{
	char tpJogada[2];
	char jogada;
	int confere = 0;
	char msg[BUFSIZE];
	int ctRecebida;
	int i;
	int encontrou = 0;
	char recebida[2];
	int aguarda;
	int resposta;

	if (recebe.tipo[0] == (char) '4')
	{		
		tpJogada[0] = recebe.msg[0];
		tpJogada[1] = recebe.msg[1];
		tpJogada[2] = '\0';

		fprintf(log, "<%f> Tipo de Jogada: %s\n", TimeStamp(), tpJogada);fflush(log);

		if (strcmp(tpJogada, "TR") == 0)
		{
			fprintf(log, "<%f> %s pediu truco\n", TimeStamp(), recebe.envia);
			fprintf(stdout, "%s pediu truco. Para aceitar digite 1, para não aceitar, digite 0\n", recebe.envia);
			Send(buf);

			while(confere == 0)
			{
				jogada = (char) getc(stdin);

				if (jogada == (char) '1')
				{
					resposta = 0;
					while (resposta < 3)
					{
						do 
						{
							aguarda = AguardaMensagem(&recebe);
						} while (aguarda != 0 && aguarda != 1);

						if (aguarda == 0)
						{
							strcpy(msg, maquina.nome);
							if (strcmp(maquina.nome, "talisker") == 0)
								msg[8] = (char) ':';
							else
								strcat(msg, " :");
					
							strcat(msg, "all     :4:0000:000:OK");
							Send(msg);
							PassaBastao();
						}
						else
						{
							if (recebe.tipo[0] == (char) '4')
								if (strcmp(recebe.msg, "OK") == 0)
									resposta++;
								else if (strcmp(recebe.msg, "FU") == 0)
									return 1;
						}

						truco = 1;
						confere = 1;
						return 0;
					}
				}
				else if (jogada == (char) '0')
				{
					do
					{
						aguarda = AguardaMensagem(&recebe);
					} while (aguarda != 0);

					strcpy(msg, maquina.nome);
					if (strcmp(maquina.nome, "talisker") == 0)
						msg[8] = (char) ':';
					else
						strcat(msg, " :");

					strcat(msg, "all     :4:0000:000:FU");
					
					Send(msg);
					PassaBastao();

					confere = 1;

					return 1;
				}
				else
					fprintf(stdout, "Incorreto. Digite novamente\n");
			}

		}
		else if (strcmp(tpJogada, "SE") == 0)
		{			
		        fprintf(log, "<%f> %s pediu seis\n", TimeStamp(), recebe.envia);
			fprintf(stdout, "%s pediu seis. Para aceitar digite 1, para não aceitar, digite 0\n", recebe.envia);
			Send(buf);

			while(confere == 0)
			{
				jogada = (char) getc(stdin);

				if (jogada == (char) '1')
				{
					 resposta = 0;
					 while (resposta < 3)
					 {
					 	do
						{
							aguarda = AguardaMensagem(&recebe);
						} while (aguarda != 0 && aguarda != 1);
						
						if (aguarda == 0)
						{
						        strcpy(msg, maquina.nome);
						        if (strcmp(maquina.nome, "talisker") == 0)
							        msg[8] = (char) ':';
						        else
						                strcat(msg, " :");
						
							strcat(msg, "all     :4:0000:000:OK");
							Send(msg);
							PassaBastao();
						}
						else
						{
						        if (recebe.tipo[0] == (char) '4')
						                if (strcmp(recebe.msg, "OK") == 0)
							                resposta++;
						                else if (strcmp(recebe.msg, "FU") == 0)
						                        return 1;
							seis = 1;
						}
						
						confere = 1;
						return 0;
					}

				}
				else if (jogada == (char) 0)
				{
					do
					{
						aguarda = AguardaMensagem(&recebe);
					} while (aguarda != 0);
					
					strcpy(msg, maquina.nome);
					if (strcmp(maquina.nome, "talisker") == 0)
					        msg[8] = (char) ':';
					else
						strcat(msg, " :");
					
					strcat(msg, "all     :4:0000:000:FU");
					
					Send(msg);
					PassaBastao();

					confere = 1;
					 
					return 1;
				}
				else
					fprintf(stdout, "Incorreto. Digite novamente\n");
			}
		}
		else if (strcmp(tpJogada, "CT") == 0)
		{
			recebida[0] = recebe.msg[2];
			recebida[1] = recebe.msg[3];
			recebida[2] = '\0';
			
			fprintf(log, "<%f> Carta recebida de %s\n", TimeStamp(), recebe.envia);fflush(log);
			fprintf(stdout, "Carta recebida de %s: %s\n", recebe.envia, recebida);fflush(stdout);
			Send(buf);

			ComputaPontos();

			return 2;
		}
	}
	else if (recebe.tipo[0] == (char) '5')
		return 3;
}

int AguardaJogador()
{
        int confere;
        char msg[BUFSIZE];
        char ctJogada;
	int nJogada;
	int resposta;
	int aguarda;
	mensagem recebe;
        
	fprintf(stdout, "Sua vez! Digite o número da carta que quer jogar\n");
	fprintf(stdout, "Sua mao: 0: %s 1: %s 2: %s\n", minhaMao[0], minhaMao[1], minhaMao[2]);
	fprintf(stdout, "Ou digite 3 para pedir truco, 4 para pedir seis e 5 para sair\n");
	
	confere = 0;
	while (confere == 0)
	{
		ctJogada = (char) getc(stdin);
		nJogada = ctJogada - 48;
		fprintf(log, "<%f> Entrada do jogador: %c\n", TimeStamp(), ctJogada);fflush(log);
        	if (ctJogada == (char) '0' ||  ctJogada == (char) '1' || ctJogada == (char) '2')
		{
			fprintf(log, "<%f> Jogador escolheu uma carta\n", TimeStamp());fflush(log);
			if (strcmp(minhaMao[nJogada], "00") == 0)
			{
        			fprintf(stdout, "Carta já utilizada! Tente novamente\n");fflush(stdout);
			}
			else
			{
				fprintf(log, "<%f> Carta Aceita\n", TimeStamp());fflush(log);
				strcpy(msg, maquina.nome);
				if (strcmp(maquina.nome, "talisker") == 0)
		         		msg[8] = (char) ':';
				else
		         		strcat(msg, " :");
					
				strcat(msg, "all     :4:0000:000:CT");
        			strcat(msg, minhaMao[nJogada]);

				strcpy(minhaMao[nJogada], "00");
	
				Send(msg);

				fprintf(log, "<%f> %s\n", TimeStamp(), msg);fflush(log);
				PassaBastao();
				return 0;
			}
		}
		else if (ctJogada == (char) '3')
		{
			strcpy(msg, maquina.nome);
			if (strcmp(maquina.nome, "talisker") == 0)
				msg[8] = (char) ':';
			else
			        strcat(msg, " :");
					           
			strcat(msg, "all     :4:0000:000:TR");
						                       				
			Send(msg);
			PassaBastao();

			resposta = 0;
			while (resposta < 3)
			{
				do
			        {
				        aguarda = AguardaMensagem(&recebe);
			        } while (aguarda != 1);

				if (strcmp(recebe.msg, "OK") == 0)
					resposta++;
			        else if (strcmp(recebe.msg, "FU") == 0)
			                return 1;
			        truco = 1;
			}	
			return 0;

		}
        	else if (ctJogada == (char) '4')
		{
			strcpy(msg, maquina.nome);
			if (strcmp(maquina.nome, "talisker") == 0)
				msg[8] = (char) ':';
			else
			        strcat(msg, " :");
							                                    
			strcat(msg, "all     :4:0000:000:SE");
			Send(msg);
			PassaBastao();

			resposta = 0;
			while (resposta < 3)
			{
				do
				{
				        
					aguarda = AguardaMensagem(&recebe);
				} while (aguarda != 1);
				                                           
				if (strcmp(recebe.msg, "OK") == 0)
				        resposta++;
				else if (strcmp(recebe.msg, "FU") == 0)
				        return 1;
				seis = 1;
			}
			return 0;
		}
		else if (ctJogada == (char) '5')
		{
		        strcpy(msg, maquina.nome);
		        if (strcmp(maquina.nome, "talisker") == 0)
		                 msg[8] = (char) ':';
		        else
		                 strcat(msg, " :");
				 
		        strcat(msg, "all     :5:0000:000: ");
						
			Send(msg);
			PassaBastao();

			return 3;
		}
	}
}

void Jogo()
{
	int aguarda, recepciona, confere;
	mensagem recebe;

	char *msg;

	char ctJogada;

	recepciona = 0;
	confere = 0;
	aguarda = 0;
	while (recepciona != 3)
	{
		fprintf(log, "<%f> Aguarda Mensagem...\n", TimeStamp()); fflush(log);
		
		do
		{
			aguarda = AguardaMensagem(&recebe);
		} while (aguarda != 1 && aguarda != 0);

		if (aguarda == 1)
			recepciona = TrataRecepcao(recebe);
		else if (aguarda == 0)
		{
			recepciona = AguardaJogador();
		}

		if (recepciona == 1)
			if (strcmp(maquina.nome, "macalan") == 0)
				Dealer();
			else
			        WaitCards();
		else if (recepciona == 3)
		{
			Send(buf);
		        fprintf(stdout, "Jogo encerrado\n");fflush(stdout);
		        fprintf(log, "<%f> Jogo encerrado\n", TimeStamp());fflush(log);
		}
	}
}
	
int main (int argc, char *argv[])
{
	log = fopen("log", "w+");
	double t;
	mensagem recebe;

       	seis = 0;
       	truco = 0;

        SetRing();

	//Inicia o Anel
	if (strcmp(maquina.nome, "macalan") == 0)
		log = fopen("log_mac", "w+");
	else if (strcmp(maquina.nome, "bowmore") == 0)
		log = fopen("log_bow", "w+");
	else if (strcmp(maquina.nome, "priorat") == 0)
		log = fopen("log_prio", "w+");
	else
		log = fopen("log_tal", "w+");

	CarregaBaralho();
	t = TimeStamp();
	EnterRing();

	//Distribui Cartas
	if (strcmp(maquina.nome, "macalan") == 0)
	{
		fprintf(log, "<%f> Distribuindo cartas\n", TimeStamp());fflush(log);
		Dealer();
		PassaBastao();
		fprintf(log, "<%f> Tempo total: %f\n", TimeStamp(), TimeStamp()-t);	
	}
	else
	{
		WaitCards();
	}

	//Inicia o Jogo!!!
	fprintf(log, "<%f> Cartas na tela \n", TimeStamp());
	fprintf(stdout, "Jogadores Conectados. Cartas recebidas. Esperando sua vez Sua mao:\n");
	fprintf(stdout, "0: %s 1: %s 2: %s\n", minhaMao[0], minhaMao[1], minhaMao[2]);
	fprintf(stdout, "Manilha: %s\n", manilha);

	if (strcmp(maquina.nome, "bowmore") == 0)
	{
		while (AguardaMensagem(&recebe) != 0);
		AguardaJogador();
	}
	Jogo();

}
