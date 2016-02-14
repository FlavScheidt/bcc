--
-- Copyright Roberto Andre Hexsel, 2011-2012
--

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- testbench para somador
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use work.p_wires.all;

entity tb_adder is
end tb_adder;

architecture TB of tb_adder is

  component adderFuncional is port(inpA, inpB : in reg16;
                          outC : out reg16;
                          vem  : in std_logic;
                          vai  : out std_logic);
  end component adderFuncional;

  component adderCadeia is port(inpA, inpB : in reg16;
                          outC : out reg16;
                          vem  : in std_logic;
                          vai  : out std_logic);
  end component adderCadeia;

  component adderAdianta4 is port(inpA, inpB : in reg16;
                          outC : out reg16;
                          vem  : in std_logic;
                          vai  : out std_logic);
  end component adderAdianta4;

  component adderAdianta16 is port(inpA, inpB : in reg16;
                          outC : out reg16;
                          vem  : in std_logic;
                          vai  : out std_logic);
  end component adderAdianta16;

  signal inpA,inpB : reg16;             -- test inputs
  signal resFun,resCad,resAd4,resAd16 : reg16; -- result
  signal vaiFun,vaiCad,vaiAd4,vaiAd16 : std_logic;
  signal addsub : std_logic;
  signal tb_res : reg16;
  signal tb_vai : std_logic;
  
  type test_record is record
                        a : reg16;      -- entrada
                        b : reg16;      -- entrada
                        f : std_logic;  -- funcao: 0=ADD, 1=SUB
                        c : reg16;      -- saida
                        v : std_logic;  -- vai-um
                      end record;
  type test_array is array(positive range <>) of test_record;
    
  constant test_vectors : test_array := (
    -- a,     b,      f, c,       vai-um
    --ADD
    (x"0000",x"0000",'0',x"0000",'0'),
    -- acrescente novos valores aqui
    (x"0fff",x"0001",'0',x"0000",'0'),  -- corrija valores de c e v
    (x"0eee",x"0111",'0',x"0000",'0'),
    (x"5555",x"5555",'0',x"0000",'0'),
    (x"7777",x"8888",'0',x"0000",'0'),
    (x"ffff",x"0000",'0',x"0000",'0'),
    (x"0000",x"0000",'0',x"0000",'0'),
    -- SUB
    (x"0000",x"0000",'1',x"0000",'1'),  -- inverte vai-um (empresta)
    -- acrescente novos valores aqui
    (x"0000",x"0000",'1',x"0000",'1'),
    (x"0000",x"0000",'1',x"0000",'1'),
    (x"0000",x"0000",'1',x"0000",'1'),
    (x"0000",x"0000",'1',x"0000",'1'),
    (x"0000",x"0000",'1',x"0000",'1'),
    (x"0000",x"0000",'1',x"0000",'1')
    );

begin  -- TB

  U_addFun: adderFuncional  port map ( inpA, inpB, resFun, addsub, vaiFun );
  U_addCad: adderCadeia     port map ( inpA, inpB, resCad, addsub, vaiCad );
  U_addAd4: adderAdianta4   port map ( inpA, inpB, resAd4, addsub, vaiAd4 );
  U_addAd16: adderAdianta16 port map ( inpA, inpB, resAd16, addsub, vaiAd16 );

  U_testValues: process                -- test the circuit
    variable v : test_record;
  begin
    
    for i in test_vectors'range loop
      v := test_vectors(i);
      inpA <= v.a;
      if v.f = '0' then                 -- soma
        inpB <= v.b;
      else
        inpB <= not(v.b);               -- subtracao= A + not(B)+1
      end if;
      addsub <= v.f;                    -- vem-um(0)=1 na subtracao
      tb_res <= v.c;
      tb_vai <= v.v;
         assert resFun = tb_res report "func: valor errado" severity error;
         assert vaiFun = tb_vai report "func: vai-um errado" severity error;
         assert resCad = tb_res report "cade: valor errado" severity error;
         assert vaiCad = tb_vai report "cade: vai-um errado" severity error;
         assert resAd4 = tb_res report "adi4: valor errado" severity error;
         assert vaiAd4 = tb_vai report "adi4: vai-um errado" severity error;
         assert resAd16 = tb_res report "ad16: valor errado" severity error;
         assert vaiAd16 = tb_vai report "ad16: vai-um errado" severity error;
      wait for 1000 ns;
    end loop;

    wait;
    end process;
   
end TB;

----------------------------------------------------------------
configuration CFG_TB of TB_ADDER is
	for TB
        end for;
end CFG_TB;
----------------------------------------------------------------
