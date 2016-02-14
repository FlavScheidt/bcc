library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.p_wires.all; 

entity tb_deslocador is

end tb_deslocador;

architecture tb_deslocador of tb_deslocador is
	
	component normalizacao is 
		port (	e       :       in      reg16;
			s       :       out     reg16;
			done    :       out     std_logic;
			rst     :       in      std_logic
		);
	end component;
	
	signal eNorm	: 	reg16;
	signal sNorm	:	reg16;
	signal rNorm	:	std_logic;
	signal reset	:	std_logic;

Begin
	TESTE : process
	begin
		eNorm <= "0000001111010100";
		reset <= '0';
		reset <= '1' after 5 ns;
		eNorm <= "1111111111111111" after 5 ns;
	end process;

	norm	:	normalizacao port map(eNorm, sNorm, rNorm, reset);

end tb_deslocador;

