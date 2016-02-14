program binario_para_decimal;
const max=4;
var binario, decimal: integer;

(* Funções e Procedimentos *)

procedure transforma (var binario, decimal: integer);
	var i, termo, j, exponencial: integer;
	begin
		i:=0;
		j:=0;
		decimal:= 0;
		while i<=max do
		begin
			termo:=binario mod 10;
			binario:=binario div 10;
				if i=0 then
				begin
					decimal:= 1;
					j:= j+1;
				end
				else
				begin
					exponencial:= 1;
					while j<=i do
					begin
						exponencial:=exponencial*2;
						j:= j+1;
					end;
					termo:= termo*exponencial;
					decimal:= decimal+termo;
				end;
		i:=i+1;
		end;



	end;



(* Programa Principal *)
Begin
	writeln ('Insira um inteiro positivo na forma binária com cinco dígitos');
	read (binario);
	transforma (binario, decimal);
	writeln (decimal);


End.
