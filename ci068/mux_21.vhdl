-- Inversor 
entity inv is
	port ( i1: in bit;
			i0: out bit;
		);
end inv;
architecture fsc10 of inv is
	Begin
		i0 <= not (i1) after 6ns; -- descreve funcionamento da porta
end fsc10;
----------------------------------------------------
-- Porta e
entity gate_and is
	port ( i1, i2: in bit_vector (7 downto 0);
			i0: out bit_vector (7 downto 0);
		);
end and2;
architecture fsc10 of gate_and is
	Begin
		i0 <= (i1 and i2) delay 8ns; -- descreve funcionamento da porta
end fsc10;
-----------------------------------------------------
-- Porta ou
entity gate_or is
	port ( i1,i2: in bit_vector (7 downto 0);
			i0: out bit_vector (7 downto 0);
		);
end or2;
architecture fsc10 of gate_or is
	Begin
		i0 <= (i1 or i2) delay 8ns; -- descreve funcionamento da porta
end fsc10;
-----------------------------------------------------
-- Multiplexador 2:1
entity mux21 is
	port( a,b: in bit_vector (7 downto 0);
		 s: in bit;
		 dout: out bit_vector (7 downto 0);
		);
end mux21;
architecture fsc10 of mux21 is
-- Descreve os componentes a serem utilizados, ou seja, constroi caixas pretas
	component c1 port( i1: in bit_vector (7 downto 0);
						i0: out bit_vector (7 downto 0);
					);
	end component;
	component c2 port( i1, i2: in bit_vector (7 downto 0);
						i0: out_bit (7 downto 0);
					);
	end component;
	component c3 port( i1,i2: in bit_vector(7 downto 0);
						i0: out bit_vector (7 downto 0);
					);
	end component;
-- Diz quais entidades devem ser utilizadas. Ou seja, o que há dentro das caixas pretas
	for all: c1 use entity work.inv(fsc10);
	for all: c2 use entity work.gate_and(fsc10);
	for all: c3 use entity work.gate_or(fsc10);
		signal s1,s2,s3: bit_vector(7 downto 0);
	Begin
-- Mapeia entradas para as portas das caixas pretas
		g0: c1 port map (s, s1);
		g1: c2 port map (a, s1, s2);
		g2: c2 port map (b, s, s3);
		g3: c3 port map (s2, s3, dout);
end fsc10;
	
