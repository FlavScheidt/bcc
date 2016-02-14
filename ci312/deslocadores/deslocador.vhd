---------------------------------------------------------------------------------
--	Deslocadores
---------------------------------------------------------------------------------

--------------------------------------------------------------
--	Deslocador de 16 bits para multiplicação
--------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use work.p_wires.all;
use work.all;

entity shifterBooth is
	port(	
        	ent :	in	reg26;
		sai :	out	reg26
	);
end shifterBooth;

architecture shifterBooth of shifterBooth is
begin 
      sai <= '0' & ent(25 downto 1);
end architecture shifterBooth;

--------------------------------------------------------------
--	Deslocador 13 bits para soma PF (unidirecional)
--------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use work.p_wires.all;
use work.all;

entity shifter13 is
	port(	
        e :	in  reg13;
		d :	in  reg4;
		s :	out reg13
	);
end shifter13;

architecture shifter13 of shifter13 is
begin
	process(d,e)
	begin
	case d is
		when "0001"	=>	s <= '0' & e(12 downto 1);
		when "0010"	=>	s <= "00" & e(12 downto 2);
		when "0011"	=>	s <= "000" & e(12 downto 3);
		when "0100"	=>	s <= "0000" & e(12 downto 4);
		when "0101"	=>	s <= "00000" & e(12 downto 5);
		when "0110"	=>	s <= "000000" & e(12 downto 6);
		when "0111"	=>	s <= "0000000" & e(12 downto 7);
		when "1000"	=>	s <= "00000000" & e(12 downto 8);
		when "1001"	=>	s <= "000000000" & e(12 downto 9);
		when "1010"	=>	s <= "0000000000" & e(12 downto 10);
		when "1011"	=>	s <= "00000000000" & e(12 downto 11);
		when "1101"	=>	s <= "000000000000" & e(12);
		when others	=>	s <= e;
	end case;
	end process;
end architecture shifter13;

--------------------------------------------------------------
--	Deslocador bidirecional para normalização (16 bits)
--------------------------------------------------------------
----------------------------------------
--	Direita
----------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use work.p_wires.all;
use work.all;

entity shifterDIR is
        port(   e 	:     	in      reg16;
                s 	:     	out     reg16;
		rst0 	:	in	std_logic;
		rstDir 	:	in 	std_logic
        );
end shifterDIR;

architecture shifterDIR of shifterDIR is
begin
        process(rst0, rstDir)
	begin
		if (rst0 = '1' and rstDir = '1') then
			s <= '0' & e(14 downto 0);
		else 
			s <= "XXXXXXXXXXXXXXXX";
		end if;
	end process;
end architecture shifterDIR;

--------------------------------------
--	Esquerda
--------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use work.p_wires.all;
use work.all;

entity shifterESQ is
        port(   e 	:     	in      reg16;
                s 	:     	out     reg16;
		rst0	:	in	std_logic;
		rstEsq	:	in	std_logic
        );      
end shifterESQ;
                
architecture shifterESQ of shifterESQ is
begin
        process(rst0, rstEsq)
	begin
                if rst0 = '1' and rstEsq = '0' then
                        s <= e(15 downto 1) & '0';
                else
                        s <= "XXXXXXXXXXXXXXXX";
                end if;
        end process;

end architecture shifterESQ;

-----------------------------------
--	Bidirecional
-----------------------------------
library ieee;
use ieee.std_logic_1164.all;
use work.p_wires.all;
use work.all;

entity normalizacao is
	port(	e 	:	in 	reg16;
		s 	:	out	reg16;
		done 	:	out	std_logic;
		rst	: 	in 	std_logic
	);
end normalizacao;

architecture normalizacao of normalizacao is

	component shifterDIR is
		        port(   e       :       in      reg16;
                		s       :       out     reg16;
                		rst0    :       in      std_logic;
                		rstDir  :       in      std_logic
        		);
	end component;
	
	component shifterESQ is
		        port(   e       :       in      reg16;
                		s       :       out     reg16;
               	 		rst0    :       in      std_logic;
                		rstEsq  :       in      std_logic
        		);
	end component;

	signal desloca			: std_logic;
	signal next_st, current_st	: integer := 0;

	constant	st_verification		: integer := 0;
	constant	st_exit			: integer := 1;
	constant	st_right		: integer := 2;
	constant	st_left			: integer := 3;

begin
	U_MULT_st_reg: process(rst)
  	begin
    		if rst = '1' then
      			current_st <= next_st;
		else
			current_st <= st_verification;	
		end if;
 	end process U_MULT_st_reg;

	process(current_st, e, rst)
	begin
		case current_st is
			when st_verification =>
				done <= '0';
				if rst = '1' then
					if e(11) = '1' then
						next_st <= st_exit;
					elsif ((e(13) or e(12)) = '1') then
						next_st <= st_right;
					elsif ((e(13) or e(12)) = '0') then
						next_st <= st_left;
					end if;
				else 
					next_st <= st_verification;
				end if;
				desloca <= '0';
				
			when st_exit =>
				done <= '1';
				desloca <= '0';
				next_st <= st_verification;
			
			when st_right =>
				desloca <= '1';
				if e(11) = '1' then
					next_st <= st_exit;
				else
					next_st <= st_right;
				end if;

			when st_left =>
				desloca <= '1';
				if e(11) = '1' then
					next_st <= st_exit;
				else
					next_st <= st_left;
				end if;
			when others => 
			next_st <= st_verification;
		end case;
	end process;

	LEFT	: shifterESQ	port map (e, s, desloca, e(11));
	RIGHT	: shifterDIR	port map (e, s, desloca, e(11));

end architecture normalizacao;
