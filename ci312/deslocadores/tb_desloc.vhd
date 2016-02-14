library ieee; use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.p_wires.all;

entity tb_deslocador is

end tb_deslocador;

architecture tb of tb_deslocador is

	-- Componentes a serem testados
	component shifterBooth is
		port(   ent :   in      reg26;
                	sai :   out     reg26
        	);
	end component;
	
	component shifter13 is
        	port(   e :     in      reg13;
                	d :     in      reg4;
                	s :     out     reg13
        	);
	end component;

	component normalizacao is
		port(   e       :       in      reg16;
	                s       :       out     reg16;
        	        done    :       out     std_logic;
			rst	: 	in 	std_logic
        	);
	end component;

	-- Sinais de entrada e saída dos componentes
	-- Gerais
	signal reset	: std_logic;
	signal clock	: std_logic;

	-- shiftBooth
	signal eBooth	: reg26;
	signal sBooth	: reg26;

	-- shifter13
	signal e13	: reg13;
	signal s13	: reg13;
	signal d13	: reg4;

	-- normalizacao
	signal eNorm	: reg16;
	signal sNorm	: reg16;
	signal rNorm	: std_logic;

	-- Arrays com as massas de teste para cada componente
	-- shiftBooth
	type test_booth is record
                        a : reg26;      -- entrada
                        b : reg26;      -- saída (esperada)
        end record;

	type test_array_booth is array(positive range <>) of test_booth;

  	constant test_vectors_booth : test_array_booth := (
	--a				b
	("00000000001000111111111111", "00000000001100011111111111"),
	("00000000001110001111111111", "00000000001111000111111111"),
	("00000000001111100011111111", "00000000001111110001111111"),
	("00000000001111111000111111", "00000000001111111100011111"),
	("00000000001111111110001111", "00000000001111111111000111"),
	("00000000001111111111100011", "00000000001111111111110001"),
	("00000000000000111111111100", "00000000000000011111111110"),
	("00000000000000001111111111", "01111111111000000111111111"),
	("10111111101000000011111111", "11011111111000000001111111"),
	("11101111111110000000111111", "11110111111111000000011111"),
	("11111011111111100000001111", "11111101111111110000000111"),
	("11111110111111111000000011", "11111111011111111100000001")
	);

	-- shifter13
        type test_13 is record
                        c : reg13;      -- entrada
                        d : reg13;      -- saída (esperada)
			e : reg4;	-- número de casas a deslocar
        end record;

        type test_array_13 is array(positive range <>) of test_13;

        constant test_vectors_13 : test_array_13 := (
	--c		 d		e
	("0010011100010","0000100111000", "0010"),
	("1110111110010","0111011111001", "0001"),
	("0000000000100","0000000000000", "0011"),
	("0101010101010","0000010101010", "0100"),
	("0101000000111","0000001010000", "0101"),
	("0000111111111","0000001111111", "0110"),
	("1111111111000","0000000111111", "0111"),
	("0101010000000","0000000001010", "1000"),
	("0101010101010","0101010101010", "1111")
	); 

	-- normalização
        type test_norm is record
                        f : reg16;      -- entrada
                        g : reg16;      -- saída (esperada)
        end record;

        type test_array_norm is array(positive range <>) of test_norm;

        constant test_vectors_norm : test_array_norm := (
	--f			g
	("1111111100001000","1111111100001000"),
	("0001111010101100","0001111010101100"),
	("0000001111010100","0000111101010000")
	);

Begin

	--Ligar os fio
--	b	:	shifterBooth	port map(eBooth, sBooth);
--	t	:	shifter13	port map(e13, d13, s13);
	norm	:	normalizacao	port map(eNorm, sNorm, rNorm, reset);

	-- Processo para jogar vetores de teste nas entradas

	U_teste: process
    		variable b : test_booth;
		variable t : test_13;
		variable n : test_norm;
  	begin
		-- booth
-- 		for i in test_vectors_booth'range loop
--    			b := test_vectors_booth(i);
--    			eBooth <= b.a;
--			wait for 34 * CLOCK_PER;
--     	 	end loop;

--		for j in test_vectors_13'range loop
--                        t := test_vectors_13(j);
--                        e13	<= t.c;
--			d13	<= t.e;
--			wait for 34 * CLOCK_PER;
--                end loop;

                for k in test_vectors_norm'range loop
                        n := test_vectors_norm(k);
                        eNorm <= n.f;
			wait for 34 * CLOCK_PER;
                end loop;

    		assert FALSE report " -###-fim da simulacao-###- " severity failure;
   	end process;


	-- Processo para o clock
	 U_clock: process
 	 begin
    		clock <= '0';      -- executa e
   		wait for CLOCK_PER / 2;  -- espera meio ciclo
    		clock <= '1';      -- volta a executar e
    		wait for CLOCK_PER / 2;  -- espera meio ciclo e volta ao topo
  	end process;

	-- Processo para o Reset
  	U_reset: process
  	begin
    		reset <= '0';      -- executa e
    		wait for CLOCK_PER * 0.75;  -- espera por 1/4 de ciclo
    		reset <= '1';      -- volta a executar e
    		wait;            -- espera para sempre
  	end process;

end tb;

configuration CFG_TB of tb_deslocador is
        for TB
        end for;
end CFG_TB;

