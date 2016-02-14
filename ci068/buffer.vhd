-- Declaracao da biblioteca a ser utilizada
library IEEE;
	use IEEE.std_logic_1164.all;
-------------------------------
entity t_buffer is -- declaracao das portas a serem utilizadas (estrutura da caixa preta)
	port( 	i, s: in std_logic;
		y: out std_logic
	);
end t_buffer;
architecture tristate of t_buffer is
Begin
-- a saida recebe o valor da entrada quando o sinal for igual a zero, se nao, a entrada fica na memoria 
	y <= i when ('s=0');
	y <= 'Z' when ('s=1');
end tristate;
