-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- UFPR, BCC, ci212 2012-2 trabalho semestral, autor: Roberto Hexsel, 24jan
-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- testbench para filtro de ruido
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library ieee; use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.p_wires.all;

entity tb_filtro is
end tb_filtro;

architecture TB of tb_filtro is
  
  component ENTRADA is 
    generic (LOAD_FILE_NAME : string);
    port (rst,sel : in    std_logic;
          address : in    integer;
          data    : inout std_logic_vector);
  end component ENTRADA;

  component filtro
    generic (CIRC_LATENCY: time := 10 ns);
    port(rel, rst: in  std_logic;
         ent:      in  std_logic_vector;
         sai:      out std_logic_vector;
         dif:      out std_logic_vector);
  end component filtro;

  signal rel,rst : std_logic;
  signal a,ent,sai,dif : reg12 := x"000";
  signal num,amostra : integer := 0;

begin  -- TB

  U_clock: process
  begin
    rel <= '0';      -- executa e
    wait for CLOCK_PER / 2;  -- espera meio ciclo
    rel <= '1';      -- volta a executar e
    wait for CLOCK_PER / 2;  -- espera meio ciclo e volta ao topo
  end process;

  U_reset: process
  begin
    rst <= '0';      -- executa e
    wait for CLOCK_PER * 0.25;  -- espera por 1/4 de ciclo
    rst <= '1';      -- volta a executar e
    wait;            -- espera para sempre
  end process;

  U_entrada: entrada
    generic map ("ruidosa.txt")
    port map (rst, rel, num, ent);

  U_filtro:  filtro
    generic map (20 ns)
    port map (rel, rst, ent,sai,dif);
  
  U_teste: process
    variable amostra,filtr,difer : integer;
  begin

    for i in 0 to ENT_MAX_SZ-1 loop
      num <= i;
      wait until rising_edge(rel);

      -- exibe a sequencia de amostras
      --amostra := to_integer(unsigned(ent));
      --assert false
      -- report "amostra["& natural'image(num) &"]="& integer'image(amostra)
      -- severity note;

      -- exibe a sequencia com valores filtrados

      amostra := to_integer(unsigned(ent));
      filtr := to_integer(unsigned(sai));
      difer := to_integer(unsigned(dif));
      assert false
      report "amostra["& natural'image(num) &"]="& integer'image(amostra)
      &" F="& integer'image(filtr) &" D="& integer'image(difer)
      severity note;
      
    end loop;

    wait;
    
  end process;
  
end TB;
-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

----------------------------------------------------------------
configuration CFG_TB of tb_filtro is
	for TB
        end for;
end CFG_TB;
----------------------------------------------------------------
