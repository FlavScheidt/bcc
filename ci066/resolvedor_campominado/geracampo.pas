program geracampo;
uses sysutils;
type	m2=array[1..40, 1..40] of integer;
var	posicoes: m2;
	tam, bombas, maxb: integer;

(* Ler Parâmetros  *)
procedure ler (var tam, bombas: integer);
Begin
	tam:= strtoint(ParamStr(1));
	bombas:= strtoint(ParamStr(2));
End;

(* Inicializa Campo *)
procedure inicializacampo (var posicoes: m2; tam: integer);
var	i,j:integer;
Begin
	for i:=1 to tam do
		for j:=1 to tam do
			posicoes[i,j]:=0;
End;

(* Coloca Bombas e calcula casas *)
procedure campo (var posicoes: m2; tam, bombas: integer);
var i, j, x, y, n:integer;
Begin
	n:=0;
	while (n<=bombas) do
	Begin
		i:= random (tam-1);
		j:= random (tam-1);
		if (posicoes[i,j]<>9) and (i<>(tam div 2)) and (j<>(tam div 2))then
		Begin
			posicoes[i,j]:= 9;
			n:=n+1;
			for x:=i-1 to i+1 do
				for y:=j-1 to j+1 do
					if (posicoes[x,y]<>9) and (x<>0) and (y<>0) then
						posicoes[x,y]:= posicoes[x,y]+1;


		End;
	End;
End;

(* Joga informações em um arquivo *)
procedure gera_arquivo(var posicoes: m2; tam: integer);
var	i, j: integer;
	F: text;
Begin
	assign (F,'campo.txt');
	rewrite(F);
	writeln(F, tam);
	writeln(F, bombas);
	for i:=1 to tam do
		for j:=1 to tam do
			writeln(F,posicoes[i,j]);
	close(F);
End;

(* Programa Principal *)
Begin
	ler(tam,bombas);
	maxb:= (tam*tam)-1;
	if (tam<=40) and (bombas>=1) and (bombas<maxb) then
	Begin
		inicializacampo(posicoes,tam);
		campo(posicoes,tam,bombas);
		gera_arquivo(posicoes, tam);
		writeln('Campo gerado com sucesso');
	End
	else
	Begin
		writeln('./geracampo <tamanho> <numerodebombas>');
		writeln('O tamanho deve estar entre 8 e 40. E o número de bombas entre 1 e tamanho*tamanho');
	End;
End.
