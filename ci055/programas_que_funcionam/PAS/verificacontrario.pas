program verifica_contrario;
var
	n0, n1, inverso: integer;

(* Funções e Procedimentos *)

(* Inverte primeiro número *)             
procedure inverte (var inverso, n0: integer);
	var termo, i: integer;
	begin
		inverso:=0;
		i:= 1;
		while (i<= 3) do
			begin
			termo:= n0 mod 10;
			n0:= n0 div 10;
			inverso:= inverso*10 + termo;
			i:= i+1;
			end;
	end;




(* Programa Principal *)
Begin;
	writeln ('Insira o primeiro numero (três digitos)');
	read (n0);
	writeln ('Insira outro numero com a mesma quantidade de digitos');
	read (n1);
   
    
        inverte (inverso, n0);

		if (inverso = n1) then
			writeln('O segundo numero eh o inverso do primeiro')
		else
			writeln('O segundo numero nao eh o inverso do primeiro');

End.
