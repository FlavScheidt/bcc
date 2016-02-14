-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- UFPR, BCC, ci212 2012-2 trabalho semestral, autor: Roberto Hexsel, 25jan
-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- Flaviene Scheidt de Cristo		20101915	fsc10
-- Vinicius Moises Botto		20096649	vmb09
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
		sai		: out reg16);
end subtracao16;

architecture subtracao16 of subtracao16 is

   component adderAdianta4 is -- somador com adiantamento
  	port(	inpA, inpB : in  std_logic_vector;
   		outC       : out std_logic_vector;
   		vem        : in std_logic;
    		vai        : out std_logic);
   end component adderAdianta4;

   signal invertido, aux		: reg16;
   signal aux2, aux1			: std_logic;
	begin
		invertido <= not ent2;
		AD0	: adderAdianta4		port map(invertido, "0000000000000001", aux, '0', aux1);
		AD1     : adderAdianta4         port map(ent1, aux, sai, '0', aux2);
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
		sai		: out reg16);
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
	
   component extensor is
	port(	ent	: in reg12;
		sai	: out reg16);
   end component extensor;

  signal U_ent, i0, i1, i2, i3, i4, i5, i6, i7, s_soma, diff2					: reg12;
  signal s0, s1, s2, s3, s4, s5, s6, s7, a0, a1, a2, a3, a4, a5, a6, saida, reg0, diff1, diff0	: reg16;
  signal aux0						 					: std_logic;

  begin
  	----------------------------------------------------------
  	-- Trânsito dos dados entre os registradores (pipeline)
	----------------------------------------------------------
	I_0	: registrador12 	generic map (3 ns) port map(rel, '1', '0', ent, i0); -- registrador i0 recebe dados
	I_1	: registrador12 	generic map (3 ns) port map(rel, '1', '0', i0, i1);
	I_2	: registrador12		generic map (3 ns) port map(rel, '1', '0', i1, i2);
	I_3	: registrador12		generic map (3 ns) port map(rel, '1', '0', i2, i3);
	I_4	: registrador12		generic map (3 ns) port map(rel, '1', '0', i3, i4);
	I_5	: registrador12		generic map (3 ns) port map(rel, '1', '0', i4, i5);
	I_6	: registrador12		generic map (3 ns) port map(rel, '1', '0', i5, i6);
	I_7	: registrador12		generic map (3 ns) port map(rel, '1', '0', i6, i7);

	----------------------------------------------------------
	-- Mapeamento dos deslocadores
	----------------------------------------------------------
	s0 <= ("000" & i0 & "0"); -- mult por 2
	s1 <= ("000" & i1 & "0"); -- mult por 2
	s2 <= ("00" & i2 & "00"); -- mult por 4
	s3 <= ("0" & i3 & "000"); -- mult por 8
	s4 <= ("0" & i4 & "000"); -- mult por 8
	s5 <= ("00" & i5 & "00"); -- mult por 4
	s6 <= ("000" & i6 & "0"); -- mult por 2
	s7 <= ("000" & i7 & "0"); -- mult por 2

	----------------------------------------------------------
	-- Somadores
	----------------------------------------------------------
	A_0	: adderAdianta4		port map(s0, s1, a0, '0', aux0);
	A_1	: adderAdianta4		port map(a0, s2, a1, '0', aux0);
	A_2	: adderAdianta4		port map(a1, s3, a2, '0', aux0);
	A_3	: adderAdianta4		port map(a2, s4, a3, '0', aux0);
	A_4	: adderAdianta4		port map(a3, s5, a4, '0', aux0);
	A_5	: adderAdianta4		port map(a4, s6, a5, '0', aux0);
	A_6	: adderAdianta4		port map(a5, s7, a6, '0', aux0);

	----------------------------------------------------------
	-- Desloca para esquerda
	----------------------------------------------------------
	saida <= ("00000" & a6(15 downto 5)); -- divide por 32

	----------------------------------------------------------
	-- Subtração para encontrar a difereça entre entrada e saída
	----------------------------------------------------------
	EXT	: extensor		port map(i7, reg0);

	SB0	: subtracao16		port map(reg0, saida, diff0);
	SB1	: subtracao16		port map(saida, reg0, diff1); -- Soma dos dois modos, pois é módulo
	
	diff2 <=  diff0(11 downto 0) when diff0(15) = '0'
	 	  else diff1(11 downto 0);
	
	E0	: registrador12		generic map(3 ns)	port map(rel, '1', '0', diff2, dif);
	E1	: registrador12 	generic map(3 ns)	port map(rel, '1', '0', saida(11 downto 0), sai);
	
end estrutural;
-- -------------------------------------------------------------------
