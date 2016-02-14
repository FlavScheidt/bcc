-----------------------------------------------------------------------
TRABALHO DE PROJETOS DIGITAIS E MICROPROCESSADORES
RELATÓRIO - IMPLEMENTAÇÃO DE 2 FUNÇÕES NO PICOPROCESSOR
-----------------------------------------------------------------------

Flaviene Scheidt 		 GRR20101915
Veridiana G. von Paraski GRR20096475

------------------------------------------------------------------------
ÍNDICE:
	1.0 - LOAD/STORE HALFWORD;
		1.1 - DESCRIÇÃO DOS TIPOS DE LOAD E STORE;
		1.2 - ALTERAÇÕES REALIZADAS NOS CÓDIGOS-FONTE;
			1.2.1 - "pP_defs.vhd"	
			1.2.2 - "pP_defs-body.vhd"	
			1.2.3 - "pP-behav.vhd"	
			1.2.4 - "pP-unpipelined_single_cycle_rtl.vhd"

	2.0 - MULTIPLICAÇÃO COM PONTO FLUTUANTE;
		2.1 - DESCRIÇÃO;
		2.2 - ALTERAÇÕES REALIZADAS NOS CÓDIGOS-FONTE;
			2.2.1 - "pP_defs.vhd"	
			2.2.2 - "pP_defs-body.vhd"	
			2.2.3 - "pP-behav.vhd"	
			2.2.4 - "pP-unpipelined_single_cycle_rtl.vhd"

	3.0 - TESTES;
		3.1 - COMPILAÇÃO, EXECUÇÃO E VISUALIZAÇÃO;
			3.1.1 - ANÁLISE DO LOAD E STORE HALFWORD			
			3.1.2 - ANÁLISE DA MULTIPLICAÇÃO DE PONTO FLUTUANTE

--------------------------------------------------------------------------


FUNÇÕES IMPLEMENTADAS: 

	->1.0 - LOAD HALFWORD (lhm);
			STORE HALFWORD (shm);
	
	->2.0 - MULTIPLICAÇÂO DE PONTO FLUTUANTE (muls).

--------------------------------------------------------------------------------------------------------------------------------------------------

->1.0 - LOAD e STORE HALFWORD

	->1.1 - DESCRIÇÃO 

		LHM (load halfword from memory)  - Carrega meia palavra (4 bits) da memória com extensao de sinal para o registrador.
		SHM (store halfword to  memory)  - Salva meia palavra (4 bits) do registrador com extensao de sinal para a memória.

		Apenas os 4 bits mais significativos da palavra (8 bits) são carregados para o registrador quando a instrução é lhm é executada.
		Para o shm a definição é a mesma, no entanto o carregamento se dá do registrador para a memória.
		Em ambos os casos existe extensão de sinal.  
		

	-> 1.3 - ALTERAÇÕES REALIZADAS NOS CÓDIGOS-FONTE

		-> 1.3.1 - "pP_defs.vhd" :
			
			*Definição dos códigos "fn" para operações de memória.
			
		-> 1.3.2 - "pP_defs-body.vhd" :
			
			*Alteração dos nomes apresentados em "display" durante criação do programa de saída para execução no GTKWAVE;
				
				LHM -> Load halfword from memory (fn = 010);
				SHM -> Store halfword to memory (fn = 011);
				

		-> 1.3.3 - "pP-behav.vhd" :
		
			*Na procedure perform_memory foi acrescentada a implementação para realizar load halfword e store halfword;

		-> 1.3.4 - "pP-unpipelined_single_cycle_rtl.vhd" : 

			*Na definição do GPR_mem foram implementadas as instruções com extensão de sinal.
			*Na definição do Dmem_out acrescentamos a função shm para que o sinal seja modificado, assim como é feito para a função stm.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
->2.0 - MULTIPLICAÇÃO PONTO FLUTUANTE

	->2.1 - DESCRIÇÃO

		MULS - (Multiplicação Ponto Flutuante): Ambos operandos são vetores comuns de bits tratados como ponto flutuante apenas durante a multiplicação, seguindo o seguinte padrão: 

	[7] - Sinal
	[6..3] - Expoente (maior range de números representados)
	[2..0] - Mantissa (menor precisão).


------------------------------------------------------
	A multiplicação em ponto flutuante funciona do seguinte modo:
		*Soma os expoentes
		*Multiplica a mantissa utilizando um algoritmo de multiplicação unsigned commum (considerando apenas os bits mais dignificativos)
		*Calcula o sinal utilizando um if then else
------------------------------------------------------------------------------------------------------------------

	-> 2.2 - ALTERAÇÕES REALIZADAS NOS CÓDIGOS-FONTE

		-> 2.2.1 - "pP_defs.vhd" :
			
			*Definição da operação alu_fn_muls.
			
		-> 2.2.2 - "pP_defs-body.vhd" :
			
			*Alteração dos nomes apresentados em "display" durante criação do programa de saída para execução no GTKWAVE;
				
				MULs -> Multiplicação de Ponto Flutuante
				
		-> 2.2.3 - "pP-behav.vhd" :
		
			*Definição da operação de multiplicação na ULA;
			
		-> 2.2.4 - "pP-unpipelined_single_cycle_rtl.vhd" : 

			*Definição dos valores recebidos por cada sinal

---------------------------------------------------------------------------------------------------------------------------------------------------

->3.0 - TESTES

	3.1 - COMPILAÇÃO, EXECUÇÃO E VISUALIZAÇÃO
			>Sinais a serem analisados:

			pc[11:0]			
			alu_result[7:0]
			gpr_r1[7:0]
			gpr_r2[7:0]
			dmem_out[7:0]

		3.1.1 - ANÁLISE DAS OPERAÇÕES DE HALF WORD
			>O test bench que compreende lhm é test_load.ppe (onde deve ser analisado o registrador de origem) e para o shm é o test_store.ppe (onde deve ser analisado o sinal dmem_out). Além destes dois, há ainda um terceiro que exemplifica ambas instruções.
			
			
		3.1.2 - ANÁLISE DO MULTIPLICADOR

			>O test bench que compreende a multiplicação em ponto flutuante é test_muls.ppe. Deve ser analisado o sinal alu_result na instrução 23, que recebe os valores colocados nos registradores nas intruções 21 e 22. As demais operações realizadas são apenas ilustrativas.

--------------------------------------------------------------------------------------------------------------------------------------------------



