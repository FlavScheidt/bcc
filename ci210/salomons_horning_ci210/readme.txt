-----------------------------------------------------------------------
TRABALHO DE PROJETOS DIGITAIS E MICROPROCESSADORES
RELATÓRIO - IMPLEMENTAÇÃO DE 2 FUNÇÕES NO PICOPROCESSOR
-----------------------------------------------------------------------

Nicole Janny Salomons		GRR20114171
Walter José Horning Junior	GRR20105484

------------------------------------------------------------------------
ÍNDICE:
	1.0 - SHIFTER;
		1.1 - DESCRIÇÃO DOS TIPOS DE SHIFT;
		1.2 - LÓGICA UTILIZADA;
		1.3 - ALTERAÇÕES REALIZADAS NOS CÓDIGOS-FONTE;
			1.3.1 - "pP_defs.vhd"	
			1.3.2 - "pP_defs-body.vhd"	
			1.3.3 - "pP-behav.vhd"	
			1.3.4 - "pP-unpipelined_single_cycle_rtl.vhd"

	2.0 - MULTIPLICAÇÃO;
		2.1 - DESCRIÇÃO;
		2.2 - LÓGICA UTILIZADA;
		2.3 - ALTERAÇÕES REALIZADAS NOS CÓDIGOS-FONTE;
			2.3.1 - "pP_defs.vhd"	
			2.3.2 - "pP_defs-body.vhd"	
			2.3.3 - "pP-behav.vhd"	
			2.3.4 - "pP-unpipelined_single_cycle_rtl.vhd"

	3.0 - TESTES;
		3.1 - COMPILAÇÃO, EXECUÇÃO E VISUALIZAÇÃO;
			3.1.1 - ANÁLISE DO SHIFTER			
			3.1.2 - ANÁLISE DO MULTIPLICADOR

	4.0 - CONSIDERAÇÕES FINAIS.

--------------------------------------------------------------------------


FUNÇÕES IMPLEMENTADAS: 

	->1.0 - SHIFTER (sll, srl, sllv, srlv, sra, srav);
	
	->2.0 - MULTIPLICAÇÂO.

--------------------------------------------------------------------------------------------------------------------------------------------------

->1.0 - SHIFTER

	->1.1 - DESCRIÇÃO DOS TIPOS DE SHIFT

		SLL (shift left logical) - Faz um shift para a esquerda. A quantidade que deve ser deslocada é definido em uma contante.
		SRL – (shift right logical) – Faz um shift para a direita. A quantidade que deve ser deslocada é definido em uma constante.
		SLLV – (shift left logical variable) – Faz um shift para a esquerda. A quantidade que dever ser deslocada é o valor de um 			registrador.
		SRLV – (shift right logical variable) – Faz um shift para a direita. A quantidade que deve ser deslocada é o valor de um 			registrador.
		SRA – (shift right arithmetic) – Faz uma shift para a direita. A quantidade que deve ser deslocada é definida em uma constante. 		Mantém o sinal (verifica complemento de dois).
		SRAV – (shift right arithmetic variable) - Faz uma shift para a direita. A quantidade que deve ser deslocada é o valor de um 			registrador. Mantém o sinal (verifica complemento de dois).

	->1.2 - LÓGICA UTILIZADA 

		Segundo a ISA (The picoProcessor ISA), o registrador de instruções do shifter é indexado da seguinte maneira:
		([1 downto 0] reservado como seletor foi alterado, pois na ISA os 5 ultimos bits são "don't care")

quantidade de bits:	      3       |	   2    |      3     |      3    |      3    |      3    |   2    |
			|-------------|---------|------------|-----------|-----------|-----------|--------|
			|	      |	        |	     |	         |    r2     |           |        |	 
			|   1  1  0   |    fn   |      rd    |     r1    |    ou     |  X  X  X  |   sel  |              
			|	      |         |            |           |  cte (sc) |           |        |
			|-------------|---------|------------|-----------|-----------|-----------|--------|
			[18   ..   16] [15 .. 14][13  ..  11] [10  ..   8][7  ..   5] [4   ..  2] [1  .. 0]


[18 .. 16] - Código que define a operação a ser realizada. Nesse caso, operação de shift é 110;
[15 .. 14] - Após selecionada a operação, define de qual tipo ela será (ver tabela_1);
[13 .. 11] - Registrador destino;
[10 ..  8] - Primeiro registrador;
[7  ..  5] - Segundo registrador (para operações do tipo sllv / srlv / srav) ou valor de uma constante (para operações do tipo sll / srl / sra);
[4  ..  2] - Valores desprezados para esta operação;
[1  ..  0] - Após definido o "fn", esses bits definem se a operação do shift utilizará o valor de um registrador (sllv / srlv), ou pegará o valor de uma constante (sll / srl) (ver tabela_1).

------------------------------------------------------
Tabela_1:	FN  |	SEL  |	TIPO DE OPERAÇÃO
	       ----------------------------------
		00	00	    SLL
		00	01	    SLLV
		01	00	    SRL
		01	01	    SRLV
		10	XX	    SRA
		11	XX          SRAV
---------------------------------------------------------------------
OBS.: Sel está implementado no processador com o nome de IR_shift_v 
(alias IR_shift_v : shift_fn_code is IR(1 downto 0))
----------------------------------------------------------------------

	-> 1.3 - ALTERAÇÕES REALIZADAS NOS CÓDIGOS-FONTE

		-> 1.3.1 - "pP_defs.vhd" :
			
			*Definição dos códigos "fn" para cada operação de shift.
			
		-> 1.3.2 - "pP_defs-body.vhd" :
			
			*Alteração dos nomes apresentados em "display" durante criação do programa de saída para execução no GTKWAVE;
				
				SLL -> Shift Left Logical;
				SRL -> Shift Right Logical;
				SRA -> Shift Right Arithmetic;
				SRV -> Shift Right Arithmetic Variable.
				
			*Linha 53 comentada seguindo especificação para compilação do processador (enviado pelo monitor na lista da disciplina).

		-> 1.3.3 - "pP-behav.vhd" :
		
			*Criação do seletor IR_shift_v (linha 25);
			*Definição dos protótipos da operação de shifter.

		-> 1.3.4 - "pP-unpipelined_single_cycle_rtl.vhd" : 

			*Definições necessárias do seletor IR_shift_v;
			*Seletor IR_shift_v adicionado como "parâmetro" no processo da ULA;
			*Dentro do case do IR_shift_fn:
				-Quando for operação de sll:
					>verifica o valor do seletor (IR_shift_v);
					>se for igual a "00" faz sll;
					>se for igual a "01" faz sllv;
					>para outros ("10" ou "11") retorna o primeiro registrador sem alterar seu valor.

				-Quando for operação de srl:
					>verifica o valor do seletor (IR_shift_v);
					>se for igual a "00" faz srl;
					>se for igual a "01" faz srlv;
					>para outros ("10" ou "11") retorna o primeiro registrador sem alterar seu valor.

				-Quando for operação de sra e srav, o resultado é independente do seletor.

			*O resultado da operação realizada é guardado em shift_result, sendo, depois do case, guardado definitivamente em 				ALU_result, para ser possível a visualização no GTKWAVE (ver seção 3.0);

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
->2.0 - MULTIPLICAÇÃO (unsigned)

	->2.1 - DESCRIÇÃO

		MULTU - (Multiplicação Unsigned) - Realiza a multiplicação entre dois registradores, cujos valores no teste estão em GPR_r1 e 			GPR_r2.  

	->2.2 - LÓGICA UTILIZADA 

		Segundo a ISA (The picoProcessor ISA), o registrador de instruções da ULA é indexado da seguinte maneira:

quantidade de bits:	      2    |	 3      |      3     |      3    |      3    |      3    |   
			|----------|------------|------------|-----------|-----------|-----------|
			|	   |	        |	     |	         |           |           |  	 
			|   0  0   |     fn     |      rd    |     r1    |    r2     | X X X X X |                
			|	   |            |            |           |           |           |  
			|----------|------------|------------|-----------|-----------|-----------|
			[18 ..  17] [16  ..  14] [13  ..  11] [10  ..  8] [7  ..   5] [4   ..  0] 


[18 .. 17] - Código que define a operação a ser realizada. Nesse caso, operação de "ULA Reg-Reg" é 00;
[16 .. 14] - Define o tipo de operação na ULA. Para mult esta operação é "111";
[13 .. 11] - Registrador destino;
[10 ..  8] - Primeiro registrador;
[7  ..  5] - Segundo registrador;
[4  ..  0] - Valores desprezados para esta operação;

------------------------------------------------------

	O resultado da multiplicação resultará em um número de 16 bits. Os registradores do picoProcessor contém 8 bits. Criamos uma variável chamada "tmp_result_mult", a qual contém 16 bits e é tipada com unsigned (pois tratamos da multiplicação unsigned). Nesta variável, guardamos temporariamente o resultado da multiplicação entre o primeiro e o segundo registrador (no teste, GRP_r1 e GPR_r2). Criamos também dois "sinais": HI e LO. Em HI, colocamos os 8 bits mais significativos de tmp_result_mult, já em LO, adicionamos os 8 bits menos significativos deste mesmo registrador (tmp_result_mult).
------------------------------------------------------------------------------------------------------------------

	-> 2.3 - ALTERAÇÕES REALIZADAS NOS CÓDIGOS-FONTE

		-> 2.3.1 - "pP_defs.vhd" :
			
			*Definição da operação alu_fn_mult.
			
		-> 2.3.2 - "pP_defs-body.vhd" :
			
			*Alteração dos nomes apresentados em "display" durante criação do programa de saída para execução no GTKWAVE;
				
				MUL -> Multiplicação Unsigned.
				
		-> 2.3.3 - "pP-behav.vhd" :
		
			*Definição da operação de multiplicação na ULA;
			
		-> 2.3.4 - "pP-unpipelined_single_cycle_rtl.vhd" : 

			*Criação dos sinais HI e LO com tamanho de um byte cada;
			*Sinais HI e LO adicionados como "parâmetros" no processo da ULA;
			*Criação da variável tmp_result_mult com tamanho de 2 bytes e tipo unsigned;
			*Caso fn da ULA seja igual a "111", realiza a operação de multiplicação;
				-Multiplica o primeiro registrador com o operando da direita;
				-Salva o valor dessa multiplicação em tmp_result_mult;
				-Coloca os 8 bits mais significativos de tmp_result_mult em HI e os 8 bits menos significativos em LO. 

---------------------------------------------------------------------------------------------------------------------------------------------------

->3.0 - TESTES

	*Para realização dos testes e comprovação da efetividade de nosso código, utilizamos do GTKWAVE.
	*Nosso teste se encontra em "test3.ppe" e é chamado em "test_bench_unpipelined_single_cycle_rtl.vhd"

	3.1 - COMPILAÇÃO, EXECUÇÃO E VISUALIZAÇÃO

		>No terminal, execute o camando: sh build.sh (build contém todos os comandos para a realização da compilação de todos os códigos 			necessários e para a geração dos arquivos executáveis);
		>Depois gere o arquivo para visualização no GTKWAVE com o seguinte comando: ./test_bench_unpipelined_single_cycle_rtl --stop-time=1000ns --vcd=teste.vcd
		>Este comando irá gerar um arquivo chamado teste.vcd, para visualizá-lo use o comando: gtkwave teste.vcd
		>Este comando irá direcioná-lo para a visualização no GTKWAVE;
		>No GTKWAVE, no canto superior esquerdo clique em "dut";
		>Isto fará com que todos os sinais utilizados no processador apareçam em uma tabela. Nesta, arraste os seguintes sinais para a 			coluna de exibição:
			
			pc[11:0]			
			alu_result[7:0]
			gpr_r1[7:0]
			gpr_r2[7:0]
			hi[7:0]
			lo[7:0]
		
		>Com o botão direito do mouse, clique sobre os sinais e atribua a eles os formatos de acordo com as especificações a seguir:

		3.1.1 - ANÁLISE DO SHIFTER

			Para uma melhor visualização, deve-se atribuir os formatos da seguinte maneira:

			pc[11:0]           -      decimal;		
			alu_result[7:0]    -      binary;
			gpr_r1[7:0]        -      binary;
			gpr_r2[7:0]        -      decimal;
			hi[7:0]            -      (indiferente);
			lo[7:0]            -      (indiferente).

			>A primeira instrução de shift executada pelo nosso teste (teste3.ppe) é feita quando PC = 26;
			>Analisando PC a partir de 26 e seguindo a o arquivo de teste, percebe-se que o resultado obtido condiz com o resultado 			esperado;
			>EXEMPLO1:
				
				Para PC=026, a operação a ser executada é (sll r1, r1, 2);
				Nesse instante (PC=26), o valor de GPR_r1 (durante a execução para este relatório) foi "00000001";
				Após o incremento do PC (PC=27), seu valor foi alterado para "00000100", ou seja, o sll foi executado com sucesso.

			>EXEMPLO2:
		
				Para PC=31, a operação a ser executada é (sra r1, r1, 2);
				Nesse instante (PC=31), o valor de GPR_r1 (durante a execução para este relatório) foi "10000000";
				Após o incremento do PC (PC=32), seu valor foi alterado para "11100000", ou seja, o sra foi executado com sucesso, 					pois além de deslocar para a direita dois bits, foi capaz de perceber que GPR_r1 estava em complemento de dois e 					adicionou 1's em vez de 0's.

		3.1.2 - ANÁLISE DO MULTIPLICADOR

			Para uma melhor visualização, deve-se atribuir os formatos da seguinte maneira:

			pc[11:0]           -      decimal;		
			alu_result[7:0]    -      (indiferente);
			gpr_r1[7:0]        -      decimal;
			gpr_r2[7:0]        -      decimal;
			hi[7:0]            -      binary;
			lo[7:0]            -      binary.

			>A primeira instrução de multiplicação executada pelo nosso teste (teste3.ppe) é feita quando PC = 33, todavia o resultado 				foi zero pois o segundo registrador continha o valor zero nesse instante;
			>Na segunda operação de multiplicação (PC=41), o primeiro registrador (durante os testes) continha 85 e o segundo 				registrador continha 191;
			>A multiplicação resultante desses dois registradores deve ser 16.235 (em binário = "11111101101011");
			>Nesse caso o registrador LO deve receber ("01101011")	e HI ("00111111"), os mesmos resultados mostrados pelo GTKWAVE;

--------------------------------------------------------------------------------------------------------------------------------------------------

->4.0 - CONSIDERAÇÕES FINAIS
		
	Apenas alguns exemplos foram apresentados neste relatório, todavia nosso arquivo de testes (test3.ppe) contém um exemplo para cada operação de shift implementada, e dois exemplos para a operação de multiplicação (um tratando multiplicação por zero). Todas as operações foram testadas diversas vezes para excluir a possibilidade de coincidências entre resultados.	

