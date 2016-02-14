--
-- Copyright Roberto Andre Hexsel, 2011-2012
--

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- somador de 16 bits
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

library IEEE; use IEEE.Std_Logic_1164.all;

package p_WIRES is

  -- tipos para os barramentos e sinais
  subtype reg2  is std_logic_vector(1 downto 0);
  subtype reg3  is std_logic_vector(2 downto 0);
  subtype reg4  is std_logic_vector(3 downto 0);
  subtype reg5  is std_logic_vector(4 downto 0);
  subtype reg8  is std_logic_vector(7 downto 0);
  subtype reg16 is std_logic_vector(15 downto 0);
  subtype reg17 is std_logic_vector(16 downto 0);

end p_WIRES;

--package body p_ADDER is
--end p_ADDER;

-- gate delays
-- 2 entradas 20ns
-- 3 entradas 30ns
-- 4 entradas 40ns
-- 5 entradas 50ns


-- MODELOS FUNCIONAIS -----------------------------------------------------


-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- somador completo de um bit, modelo funcional
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;

entity addBit is
  port(bitA, bitB, vem : in std_logic;    -- entradas A,B,vem-um
       soma, vai       : out std_logic);  -- saida C,vai-um
end addBit;

architecture funcional of addBit is 
  signal notB : std_logic;
begin
    soma <= bitA xor bitB xor vem after 30 ns;
    vai <= (bitA and bitB)or(bitA and vem)or(vem and bitB) after 40 ns;
end funcional;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- somador de 16 bits, modelo funcional
-- cfe. Secao ?.?
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use work.p_wires.all;

entity adderFuncional is
  port(inpA, inpB : in reg16;
       outC : out reg16;
       vem  : in std_logic;
       vai  : out std_logic
       );
end adderFuncional;

-- usa sinais de 17 bits para emular a soma de dois números de 16 bits
-- resultado é em 17=1+16 bits: vai-um e soma

architecture adderFuncional of adderFuncional is 
  signal ext_A, ext_B, ext_vem, soma : reg17;  -- artefato da modelagem
begin

  ext_A <= '0'&inpA;
  ext_B <= '0'&inpB;
  ext_vem <= "0000000000000000"&vem;

  soma <= ext_A + ext_B + ext_vem;
  
  outC <= soma(15 downto 0);
  vai <= soma(16);
  
end adderFuncional;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





-- MODELOS ESTRUTURAIS E COM TEMPORIZACAO------------------------------



-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- porta AND de 2 entradas
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;

entity and2 is
  generic (prop : time := 20 ns);
  port(A, B : in std_logic;  -- entradas A,B
       S    : out std_logic);  -- saida C
end and2;

architecture and2 of and2 is 
begin
    S <= A and B after prop;
end and2;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- porta OR de 3 entradas
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;

entity or3 is
  generic (prop : time := 30 ns);
  port(A, B, C : in std_logic;  -- entradas A,B,C
       S       : out std_logic); -- saida S 
end or3;

architecture or3 of or3 is 
begin
    S <= A or B or C after prop;
end or3;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- porta XOR de 3 entradas
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;

entity xor3 is
  generic (prop : time := 30 ns);
  port(A, B, C : in std_logic;  -- entradas A,B,C
       S       : out std_logic);  -- saida S 
end xor3;

architecture xor3 of xor3 is 
begin
    S <= A xor B xor C after prop;
end xor3;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- somador completo de um bit, modelo estrutural
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;
use work.p_wires.all;

entity addBit is
  port(bitA, bitB, vem : in std_logic;    -- entradas A,B,vem-um
       soma, vai       : out std_logic);  -- saida C,vai-um
end addBit;

architecture estrutural of addBit is 

  component and2 is generic (prop:time);
                      port (A,B: in std_logic; S: out std_logic);
  end component and2;

  component or3 is generic (prop:time);
                      port (A,B,C: in std_logic; S: out std_logic);
  end component or3;

  component xor3 is generic (prop:time);
                      port (A,B,C: in std_logic; S: out std_logic);
  end component xor3;

  signal a1,a2,a3: std_logic;
begin
  U_xor:  xor3 generic map ( 30 ns ) port map ( bitA, bitB, vem, soma );

  U_and1: and2 generic map ( 20 ns ) port map ( bitA, bitB, a1 );
  U_and2: and2 generic map ( 20 ns ) port map ( bitA, vem,  a2 );
  U_and3: and2 generic map ( 20 ns ) port map ( vem,  bitB, a3 );
  U_or:   or3  generic map ( 30 ns ) port map ( a1, a2, a3, vai );

end estrutural;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- somador de 16 bits, sem adiantamento de vai-um
-- cfe. Secao ?.?
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;
use work.p_wires.all;

entity adderCadeia is
  port(inpA, inpB : in reg16;
       outC : out reg16;
       vem  : in std_logic;
       vai  : out std_logic
       );
end adderCadeia;

architecture adderCadeia of adderCadeia is 

  component addBit port(bitA, bitB, vem : in std_logic;
                        soma, vai       : out std_logic);       
  end component addBit;

  signal v : reg16;                     -- cadeia de vai-um
  signal r : reg16;                     -- resultado parcial
  
begin

  -- entrada vem deve estar ligada em '0' para somar, em '1' para subtrair
  U_b0: addBit port map ( inpA(0),inpB(0),vem, r(0),v(0) );
  U_b1: addBit port map ( inpA(1),inpB(1),v(0),r(1),v(1) );
  U_b2: addBit port map ( inpA(2),inpB(2),v(1),r(2),v(2) );
  U_b3: addBit port map ( inpA(3),inpB(3),v(2),r(3),v(3) );
  U_b4: addBit port map ( inpA(4),inpB(4),v(3),r(4),v(4) );
  U_b5: addBit port map ( inpA(5),inpB(5),v(4),r(5),v(5) );
  U_b6: addBit port map ( inpA(6),inpB(6),v(5),r(6),v(6) );
  U_b7: addBit port map ( inpA(7),inpB(7),v(6),r(7),v(7) );
  U_b8: addBit port map ( inpA(8),inpB(8),v(7),r(8),v(8) );
  U_b9: addBit port map ( inpA(9),inpB(9),v(8),r(9),v(9) );
  U_ba: addBit port map ( inpA(10),inpB(10), v(9),r(10),v(10) );
  U_bb: addBit port map ( inpA(11),inpB(11),v(10),r(11),v(11) );
  U_bc: addBit port map ( inpA(12),inpB(12),v(11),r(12),v(12) );
  U_bd: addBit port map ( inpA(13),inpB(13),v(12),r(13),v(13) );
  U_be: addBit port map ( inpA(14),inpB(14),v(13),r(14),v(14) );
  U_bf: addBit port map ( inpA(15),inpB(15),v(14),r(15),v(15) );
  
  vai <= v(15);
  outC <= r;
  
end adderCadeia;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- adiantamento de vai-um de 4 bits, P&H,2ndEd,sec4.5
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;
use work.p_wires.all;

entity adianta4 is
  port(a,b : in reg4;           -- entradas A(i),B(i)
       vem : in std_logic;      -- vem-um
       c: out reg4              -- vai(i)
       );
end adianta4;

architecture adianta4 of adianta4 is 
  signal p,g : reg4;
begin

  g(0) <= a(0) and b(0) after 20 ns;
  g(1) <= a(1) and b(1) after 20 ns;
  g(2) <= a(2) and b(2) after 20 ns;
  g(3) <= a(3) and b(3) after 20 ns;

  p(0) <= a(0) or b(0) after 20 ns;
  p(1) <= a(1) or b(1) after 20 ns;
  p(2) <= a(2) or b(2) after 20 ns;
  p(3) <= a(3) or b(3) after 20 ns;

  c(0) <= g(0) or (p(0) and vem) after 40 ns;
  c(1) <= g(1) or (p(1) and g(0)) or (p(1) and p(0) and vem) after 60 ns;
  c(2) <= g(2) or (p(2) and g(1)) or (p(2) and p(1) and g(0)) or
          (p(2) and p(1) and p(0) and vem) after 80 ns;
  c(3) <= g(3) or (p(3) and g(2)) or (p(3) and p(2) and g(1)) or
          (p(3) and p(2) and p(1) and g(0)) or
          (p(3) and p(2) and p(1) and p(0) and vem) after 100 ns;

end adianta4;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- somador de 16 bits, com adiantamento de vai-um, 4 a 4 bits
-- cfe. Secao ?.?
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;
use work.p_wires.all;

entity adderAdianta4 is
  port(inpA, inpB : in reg16;
       outC : out reg16;
       vem  : in std_logic;
       vai  : out std_logic
       );
end adderAdianta4;

architecture adderAdianta4 of adderAdianta4 is 

  component addBit port(bitA, bitB, vem : in std_logic;
                        soma, vai       : out std_logic);       
  end component addBit;

  component adianta4 port(a,b : in reg4;
                          vem : in std_logic;
                          c: out reg4);
  end component adianta4;
  
  signal v : reg16;                     -- cadeia de vai-um
  signal r : reg16;                     -- resultado parcial
  signal c : reg16;                     -- cadeia de adiantamento de vai-um

begin

  -- entrada vem deve estar ligada em '0' para somar, em '1' para subtrair

  U_a0_3:
    adianta4 port map (inpA(3 downto 0),inpB(3 downto 0),vem,c(3 downto 0)); 

  U_b0: addBit port map ( inpA(0),inpB(0),vem,r(0),v(0) );
  U_b1: addBit port map ( inpA(1),inpB(1),c(0),r(1),v(1) );
  U_b2: addBit port map ( inpA(2),inpB(2),c(1),r(2),v(2) );
  U_b3: addBit port map ( inpA(3),inpB(3),c(2),r(3),v(3) );

  U_a4_7:
    adianta4 port map (inpA(7 downto 4),inpB(7 downto 4),c(3),c(7 downto 4));

  U_b4: addBit port map ( inpA(4),inpB(4),c(3),r(4),v(4) );
  U_b5: addBit port map ( inpA(5),inpB(5),c(4),r(5),v(5) );
  U_b6: addBit port map ( inpA(6),inpB(6),c(5),r(6),v(6) );
  U_b7: addBit port map ( inpA(7),inpB(7),c(6),r(7),v(7) );

  U_a8_b:
    adianta4 port map
      (inpA(11 downto 8),inpB(11 downto 8),c(7),c(11 downto 8)); 

  U_b8: addBit port map ( inpA(8), inpB(8), c(7), r(8), v(8) );
  U_b9: addBit port map ( inpA(9), inpB(9), c(8), r(9), v(9) );
  U_ba: addBit port map ( inpA(10),inpB(10),c(9), r(10),v(10) );
  U_bb: addBit port map ( inpA(11),inpB(11),c(10),r(11),v(11) );

  U_a12_15:
    adianta4 port map
      (inpA(15 downto 12),inpB(15 downto 12),c(11),c(15 downto 12)); 

  U_bc: addBit port map ( inpA(12),inpB(12),c(11),r(12),v(12) );
  U_bd: addBit port map ( inpA(13),inpB(13),c(12),r(13),v(13) );
  U_be: addBit port map ( inpA(14),inpB(14),c(13),r(14),v(14) );
  U_bf: addBit port map ( inpA(15),inpB(15),c(14),r(15),v(15) );
  
  vai <= c(15);
  outC <= r;
  
end adderAdianta4;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- -- adiantamento de vai-um de 16 bits, P&H,2ndEd,sec4.5
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;
use work.p_wires.all;

entity adianta16 is
  port(a,b : in reg16;           -- entradas A(i),B(i)
       vem : in std_logic;       -- vem-um
       c: out reg4               -- vai(i), de 4 em 4 bits
       );
end adianta16;

architecture adianta16 of adianta16 is 
  signal p,g : reg16;
  signal pp,gg,cc : reg4;
begin

  gen: for i in 15 downto 0 generate
    g(i) <= a(i) and b(i) after 20 ns;    
    p(i) <= a(i) or b(i) after 20 ns;
  end generate gen;

  pp(0) <= p(3) and p(2) and p(1) and p(0) after 40 ns;
  pp(1) <= p(7) and p(6) and p(5) and p(4) after 40 ns;
  pp(2) <= p(11) and p(10) and p(9) and p(8) after 40 ns;
  pp(3) <= p(15) and p(14) and p(13) and p(12) after 40 ns;

  gg(0) <= g(3) or (p(3) and g(2)) or (p(3) and p(2) and g(1)) or
           (p(3) and p(2) and p(1) and g(0)) after 80 ns;

  gg(1) <= g(7) or (p(7) and g(6)) or (p(7) and p(6) and g(5)) or
           (p(7) and p(6) and p(5) and g(4)) after 80 ns;

  gg(2) <= g(11) or (p(11) and g(10)) or (p(11) and p(10) and g(9)) or
           (p(11) and p(10) and p(9) and g(8)) after 80 ns;

  gg(3) <= g(15) or (p(15) and g(14)) or (p(15) and p(14) and g(13)) or
           (p(15) and p(14) and p(13) and g(12)) after 80 ns;

  cc(0) <= gg(0) or (pp(0) and vem) after 40 ns;
  cc(1) <= gg(1) or (pp(1) and gg(0)) or (pp(1) and pp(0) and vem) after 60 ns;
  cc(2) <= gg(2) or (pp(2) and gg(1)) or (pp(2) and pp(1) and gg(0)) or
           (pp(2) and pp(1) and pp(0) and vem) after 80 ns;
  cc(3) <= gg(3) or (pp(3) and gg(2)) or (pp(3) and pp(2) and gg(1)) or
           (pp(3) and pp(2) and pp(1) and gg(0)) or
           (pp(3) and pp(2) and pp(1) and pp(0) and vem) after 100 ns;

  c <= cc;

end adianta16;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- somador de 16 bits, com adiantamento de vai-um de 16 bits
-- cfe. Secao ?.?
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE; use IEEE.std_logic_1164.all;
use work.p_wires.all;

-- entrada vem deve estar ligada em '0' para somar, em '1' para subtrair
entity adderAdianta16 is
  port(inpA, inpB : in reg16;
       outC : out reg16;
       vem  : in std_logic;             -- '0' soma, '1' subtrai    
       vai  : out std_logic
       );
end adderAdianta16;

architecture adderAdianta16 of adderAdianta16 is 

  component addBit port(bitA, bitB, vem : in std_logic;
                        soma, vai       : out std_logic);       
  end component addBit;

  component adianta4 port(a,b : in reg4;
                          vem : in std_logic;
                          c: out reg4);
  end component adianta4;
  
  component adianta16 port(a,b : in reg16;
                          vem : in std_logic;
                          c: out reg4);
  end component adianta16;
  
  signal v : reg16;                     -- cadeia de vai-um
  signal r : reg16;                     -- resultado parcial
  signal c : reg16;
  signal cc : reg4;                     -- cadeia de adiantamento de vai-um

begin

  U_a15_0:
    adianta16 port map (inpA,inpB,vem,cc); 
  
  U_a3_0:
    adianta4 port map (inpA(3 downto 0),inpB(3 downto 0),vem,c(3 downto 0)); 

  U_b0: addBit port map ( inpA(0),inpB(0),vem, r(0),v(0) );
  U_b1: addBit port map ( inpA(1),inpB(1),c(0),r(1),v(1) );
  U_b2: addBit port map ( inpA(2),inpB(2),c(1),r(2),v(2) );
  U_b3: addBit port map ( inpA(3),inpB(3),c(2),r(3),v(3) );

  U_a4_7:
    adianta4 port map (inpA(7 downto 4),inpB(7 downto 4),cc(0),c(7 downto 4));

  U_b4: addBit port map ( inpA(4),inpB(4),cc(0),r(4),v(4) );
  U_b5: addBit port map ( inpA(5),inpB(5), c(4),r(5),v(5) );
  U_b6: addBit port map ( inpA(6),inpB(6), c(5),r(6),v(6) );
  U_b7: addBit port map ( inpA(7),inpB(7), c(6),r(7),v(7) );

  U_a8_11:
    adianta4 port map
      (inpA(11 downto 8),inpB(11 downto 8),cc(1),c(11 downto 8)); 

  U_b8: addBit port map ( inpA(8), inpB(8), cc(1), r(8), v(8) );
  U_b9: addBit port map ( inpA(9), inpB(9),  c(8), r(9), v(9) );
  U_ba: addBit port map ( inpA(10),inpB(10), c(9),r(10),v(10) );
  U_bb: addBit port map ( inpA(11),inpB(11),c(10),r(11),v(11) );

  U_a12_15:
    adianta4 port map
      (inpA(15 downto 12),inpB(15 downto 12),cc(2),c(15 downto 12)); 

  U_bc: addBit port map ( inpA(12),inpB(12),cc(2),r(12),v(12) );
  U_bd: addBit port map ( inpA(13),inpB(13),c(12),r(13),v(13) );
  U_be: addBit port map ( inpA(14),inpB(14),c(13),r(14),v(14) );
  U_bf: addBit port map ( inpA(15),inpB(15),c(14),r(15),v(15) );
  
  vai <= cc(3);
  outC <= r;
  
end adderAdianta16;
-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
