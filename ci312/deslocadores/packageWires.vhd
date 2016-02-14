-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- UFPR, BCC, ci212 2012-2 trabalho semestral, autor: Roberto Hexsel, 24jan
-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

-- ESTE ARQUIVO NAO PODE SER ALTERADO

-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- baseado em MRstd_tb.vhd [Calazans,Moraes06], [TortatoJr09]
-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

library ieee; use ieee.std_logic_1164.all;
library std;  use std.textio.all;
package p_WIRES is -- tipos para os barramentos e sinais

  constant CLOCK_PER : time := 50 ns;

  subtype reg2  is std_logic_vector(1 downto 0);
  subtype reg3  is std_logic_vector(2 downto 0);
  subtype reg4  is std_logic_vector(3 downto 0);
  subtype reg5  is std_logic_vector(4 downto 0);
  subtype reg8  is std_logic_vector(7 downto 0);
  subtype reg9  is std_logic_vector(8 downto 0);
  subtype reg10 is std_logic_vector(9 downto 0);
  subtype reg11 is std_logic_vector(10 downto 0);
  subtype reg12 is std_logic_vector(11 downto 0);
  subtype reg13 is std_logic_vector(12 downto 0);
  subtype reg14 is std_logic_vector(13 downto 0);
  subtype reg15 is std_logic_vector(14 downto 0);
  subtype reg16 is std_logic_vector(15 downto 0);
  subtype reg17 is std_logic_vector(16 downto 0);
  subtype reg26 is std_logic_vector(25 downto 0);
  subtype reg32 is std_logic_vector(31 downto 0);
  subtype reg33 is std_logic_vector(32 downto 0);

  constant ENT_LINHA_SZ : integer := 4;
  constant ENT_MAX_SZ   : integer := 64;  -- entrada com 64 amostras
  
  function log2_ceil(n: natural) return natural;
  function CONVERT_STRING(s: in string) return std_logic_vector;
  function CONVERT_VECTOR(letra: string(1 to ENT_LINHA_SZ);  pos: integer)
    return std_logic_vector;
  function SLV12HEX(w: in std_logic_vector(11 downto 0)) return string;
  
end p_WIRES;

package body p_WIRES is

   -- find minimum number of bits required to
   -- represent N as an unsigned binary number
  function log2_ceil(n: natural) return natural is
   begin
     if n < 2 then
       return 0;
     else
       return 1 + log2_ceil(n/2);
     end if;
   end;

  
  --converte string em std_logic_vector 
  function CONVERT_STRING(s: in string) return std_logic_vector is
    variable result : std_logic_vector(s'range);
  begin
    for i in s'range loop
      if s(i) = '0' then
        result(i) := '0'; 
      elsif s(i) = '1' then 
        result(i) := '1';
      elsif s(i) = 'x' then
        result(i) := 'X';
      else
        result(i) := 'Z';
      end if;
    end loop;
    return result;
  end CONVERT_STRING;

  
  -- converte caractere de uma linha para um std_logic_vector
  function CONVERT_VECTOR(letra: string(1 to ENT_LINHA_SZ); pos: integer)
    return std_logic_vector
  is
    variable bin: reg4;
  begin
    case (letra(pos)) is
      when '0' => bin := "0000";
      when '1' => bin := "0001";
      when '2' => bin := "0010";
      when '3' => bin := "0011";
      when '4' => bin := "0100";
      when '5' => bin := "0101";
      when '6' => bin := "0110";
      when '7' => bin := "0111";
      when '8' => bin := "1000";
      when '9' => bin := "1001";
      when 'A' | 'a' => bin := "1010";
      when 'B' | 'b' => bin := "1011";
      when 'C' | 'c' => bin := "1100";
      when 'D' | 'd' => bin := "1101";
      when 'E' | 'e' => bin := "1110";
      when 'F' | 'f' => bin := "1111";
      when others =>  bin := "UUUU";  
    end case;
    return bin;
  end CONVERT_VECTOR;


  -- convert std_logic_vector(12) to an hexadecimal string
  function SLV12HEX(w: in std_logic_vector(11 downto 0)) return string is
    variable nibble: reg4;
    variable stmp : string(4 downto 1);
  begin
    for i in 3 downto 1 loop
      nibble := w(((i-1)*4+3) downto ((i-1)*4));
      case nibble is
        when b"0000" => stmp(i) := '0';
        when b"0001" => stmp(i) := '1';                        
        when b"0010" => stmp(i) := '2';
        when b"0011" => stmp(i) := '3';                        
        when b"0100" => stmp(i) := '4';
        when b"0101" => stmp(i) := '5';                        
        when b"0110" => stmp(i) := '6';
        when b"0111" => stmp(i) := '7';                        
        when b"1000" => stmp(i) := '8';
        when b"1001" => stmp(i) := '9';                        
        when b"1010" => stmp(i) := 'a';
        when b"1011" => stmp(i) := 'b';                        
        when b"1100" => stmp(i) := 'c';
        when b"1101" => stmp(i) := 'd';                        
        when b"1110" => stmp(i) := 'e';
        when b"1111" => stmp(i) := 'f';                        
        when others  => stmp(i) := 'x';
      end case;
    end loop;
    return stmp;
  end SLV12HEX;
  -- ---------------------------------------------------------

end p_WIRES;
-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
