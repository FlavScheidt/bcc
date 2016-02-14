-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- UFPR, BCC, ci212 2012-2 trabalho semestral, autor: Roberto Hexsel, 25jan
-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- módulo extensor de sinal
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library ieee; use ieee.std_logic_1164.all;
use work.p_WIRES.all;

entity extensor is
	port(	ent	: in reg12;
		sai	: out reg16);
end extensor;

architecture extensor of extensor is
begin
	sai <= 	"0000" & ent when ent(11) = '0' else
		"1111" & ent;
end extensor;
 
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- implementação do módulo de subtração
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library ieee; use ieee.std_logic_1164.all;
use work.p_WIRES.all;

entity subtracao16 is
	port (	ent1, ent2	: in reg16;
		sai		: out reg12);
end subtracao16;

architecture subtracao16 of subtracao16 is

   component adderAdianta4 is -- somador com adiantamento
  	port(	inpA, inpB : in  std_logic_vector;
   		outC       : out std_logic_vector;
   		vem        : in std_logic;
    		vai        : out std_logic);
   end component adderAdianta4;

   signal invertido, saida	: reg16;
   signal aux2			: std_logic;
	begin
		invertido <= not ent2;
		AD1     : adderAdianta4         port map(ent1, invertido, saida, '0', aux2);
		sai <= saida(11 downto 0);
end subtracao16;

-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- definicao do modulo filtro
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library ieee; use ieee.std_logic_1164.all;
use work.p_WIRES.all;

--Caixa preta
entity filtro is
  generic (CIRC_LATENCY: time := 20 ns);
  port(rel, rst: in std_logic;
       ent: in  reg12;                  -- entrada em 12 bits- registrador
       sai: out reg12;                  -- saida em 12 bits - registrador
       dif: out reg12);                 -- amplitude do ruido eliminado
end filtro;

--Funcionamento
architecture estrutural of filtro is

  component subtracao16 is
	port(	ent1, ent2	: in reg16;
		sai		: out reg12);
  end  component subtracao16;

  component adderAdianta4 is -- somador com adiantamento
    port(inpA, inpB : in  std_logic_vector;
         outC       : out std_logic_vector;
         vem        : in std_logic;
         vai        : out std_logic);
  end component adderAdianta4;

 component registrador12 is -- registrador 12 bits
    generic (REG_LATENCY: time);
    port(rel, rst, ld: in  std_logic;
         D:            in  std_logic_vector;
         Q:            out std_logic_vector);
  end component registrador12;

  component shift is
  	port(   ent     : in reg12;
    		sai     : out reg16;
     		index   : in natural;
     		dir     : in std_logic);
   end component shift;
	
   component extensor is
	port(	ent	: in reg12;
		sai	: out reg16);
   end component extensor;

  signal U_ent, i0, i1, i2, i3, diff, s_soma		: reg12;
  signal s0, s1, s2, s3, a0, a1, a2, saida, reg0	: reg16;
  signal aux0						 	: std_logic;

  begin
  	----------------------------------------------------------
  	-- Trânsito dos dados entre os registradores (pipeline)
	----------------------------------------------------------
	I_0	: registrador12 	generic map (3 ns) port map(rel, '1', '0', ent, i0); -- registrador i0 recebe dados
	I_1	: registrador12 	generic map (3 ns) port map(rel, '1', '0', i0, i1);
	I_2	: registrador12		generic map (3 ns) port map(rel, '1', '0', i1, i2);
	I_3	: registrador12		generic map (3 ns) port map(rel, '1', '0', i2, i3);

	----------------------------------------------------------
	-- Mapeamento dos deslocadores
	----------------------------------------------------------
	s0 <= ("000" & i0 & "0");
	s1 <= ("000" & i1 & "0");
	s2 <= ("00" & i2 & "00");
	s3 <= ("0" & i3 & "000");
	----------------------------------------------------------
	-- Somadores
	----------------------------------------------------------
	A_0	: adderAdianta4		port map(s0, s1, a0, '0', aux0);
	A_1	: adderAdianta4		port map(a0, s2, a1, '0', aux0);
	A_2	: adderAdianta4		port map(a1, s3, a2, '0', aux0);

	----------------------------------------------------------
	-- Desloca para esquerda
	----------------------------------------------------------
	saida <= ("0000" & a2(11 downto 0));

	----------------------------------------------------------
	-- Subtração para encontrar a difereça entre entrada e saída
	----------------------------------------------------------
	EXT	: extensor		port map(i0, reg0);

	SB	: subtracao16		port map(reg0, saida, diff);
	
	sai <= saida(11 downto 0);
	dif <= diff;
	
end estrutural;
-- -------------------------------------------------------------------
