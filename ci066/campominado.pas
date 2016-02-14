program campominado;
uses crt;
const	maxm = 40;
	minm = 8;

type matriz  = array [1..40, 1..40] of integer;
     matriz2 = array [1..40, 1..40] of char;
var 	tamanho, bombas: integer;
	tr00: boolean;
	campo, marca: matriz2;
	revela: matriz;

(* Verifica se a entrada do usuário está entre 8 e 40*)
procedure verifica (var tamanho, bombas: integer);
var	valido: boolean;
	maxb: integer;
Begin
valido:= false;
	while not valido do
	Begin
		writeln ('Entre com o tamanho do campo.Maximo: 40 e Minino:8');
			read(tamanho);
		if (tamanho>maxm) and (tamanho<minm) then 
		Begin
			writeln('Tamanho especificado incorreto.Entre com um número entre 8 e 40');
			valido:= false;
		end
		else
			valido:= true;
	End;
valido:= false;
	while not valido do
	Begin
		maxb:= tamanho*tamanho;
		writeln('Entre com o número de bombas. Maximo:', maxb, 'Minimo: 1');
			read(bombas);
		if (bombas>maxm) and (bombas<1) then
		Begin
			writeln('Numero de bombas especificado incorreto. Entre com um número entre 1 e', maxb);
			valido:=false;
		end
		else
			valido:= true;
	End;
End;
	
(* Gera campo *)
procedure geracampo (var  marca, revela:matriz; campo: matriz2; var tamanho: integer);
var	k, x,y: integer;
	procedure inicializa (var m: matriz;var tamanho:integer);
	var	x,y: integer;
	Begin
		for x:=1 to tamanho do
		Begin
			for y:=1 to tamanho do
				m[x,y]:=0;
		End;
	End;

Begin
	(* Inicializa Matrizes  *)
	(* Troca 0 por # em campo  *)
	for x:=1 to tamanho do
	Begin
		for y:=1 to tamanho do
			campo[x,y]:= '#';
	End;
	inicializa(revela,tamanho);
	inicializa(marca, tamanho);

	(* Sorteia Posição das Bombas *)
	for k:=1 to bombas do
	Begin
		x:= random (tamanho);
		y:= random (tamanho);
	(* Verifica se há bomba na posição, se não, coloca *)
		if revela[x,y]=0 then
			revela[x,y]:= 9;
	End;

	(* Calcula numeros*)
	for x:=1 to tamanho do
	Begin
		for y:=1 to tamanho do
		Begin
			if (revela[x,y]= 9) then
			Begin
				revela[x-1, y-1]:= revela [x-1, y-1]+1;
				revela[x-1, y]:= revela [x-1, y]+1;
				revela[x-1, y+1]:= revela [x-1,y+1]+1;
				revela[x, y-1]:= revela [x, y-1]+1;
				revela[x, y+1]:= revela[x, y+1]+1;
				revela[x+1, y-1]:= revela [x+1, y-1]+1;
				revela[x+1, y]:= revela[x+1,y]+1;
				revela[x+1, y+1]:= revela[x+1, y+1]+1;
			End;
		End;
	End;
End;

(* Procedimento para imprimir matrizes *)
procedure imprimecampo (var campo: matriz2; var tamanho: integer);
var	i, x, y:integer;

Begin

	(* Campo *)
	write('  ');
	for i:=1 to tamanho do
		write(i);
	writeln;
	write('+');
	for i:=1 to tamanho do
		write('-');
	write('+');
	writeln;
	for x:=1 to tamanho do
	Begin
		write(x,' |');
		for y:=1 to tamanho do
			write(campo[x,y]);
		write('|');
		writeln;
	End;
	(* menu *)
	writeln('Menu');
	writeln('[N] Novo Jogo');
	writeln('[P] Revelar Posicao');
	writeln('[M] Marcar/Desmarcar Bomba');
	writeln('[R] Revelar Campo');
	writeln('[S] Sair');

End;

(* Marcar Bomba *)
procedure marcabomba (var marca, campo: matriz2; bombas: integer);
var	i, a, b: integer;
	x: char;
	bomba: boolean;
Begin
	clrscr;
	imprimecampo(campo, tamanho);
i:= 1;
bomba:= false;
	while (i<=bombas) and not bomba do
	Begin
		writeln('Insira as coordenadas');
		read (a, b);
		if revela[a,b]= 9 then
		Begin
			bomba:= true;
			fimdejogo(a);
		End
		else
			Begin
				marca[a, b]:= 'P';
				campo[a, b]:= 'P';
	i:=i+1;		End;
	End;
	
End;

(* Revelar Campo *)
procedure revelaposicao(var campo, marca: matriz2; revela: matriz);
var	i,a,b: integer;
	teste: boolean;
Begin
	clrscr;
	imprimecampo(campo, tamanho);
teste:= false;
	while not teste do
	Begin
		writeln('Digite as coordenadas');
		read(a,b);
		if campo[a,b]<>'#' then
		Begin
			writeln('Coordenadas já utilizadas.');
			teste:= false;
		End
		else
			teste:= true;

	End;

	campo[a,b]:= revela[a,b];
	if (revela[a,b]=9) and (marca[a,b]='P') then
		writeln('Bomba encontrada!');
	if (revela[a,b]=9) and (marca[a,b]=0) then
		fimdejogo(a);
	
	clrscr;
	imprimecampo(campo, tamanho);
End;

(* Novo Jogo *)
procedure novojogo (var campo: matriz2);
Begin
	clrscr;
	verifica(tamanho, bombas);
	geracampo(revela, campo, marca, tamanho);
	clrscr;
	imprimecampo(matriz, tamanho);
End;

(* Fim de Jogo *)
procedure fimdejogo (a:char);
Begin
	writeln('Game Over. Digite n para novo jogo ou s, para sair');
	read(a);
	case a of
		'n': novojogo(campo);
		's': break;
	End;
End;

(* Menu *)
procedure menu(var campo, marca: matriz2; revela:matriz);
var	x: char;
Begin
	read(x);
	case x OF	
        	'n': novojogo(campo);
		'p': revelaposicao(campo, marca, revela);
		'm': marcabomba(marca, campo, bombas);
		'r': imprimecampo(revela, tamanho);
		's': break;
	End;
End;

(* Programa principal *)
Begin
randomize;
tr00:= true;
	while tr00 do
	Begin
		verifica(tamanho, bombas);
		geracampo(revela, campo, marca, tamanho);
		clrscr;
		imprimecampo(matriz, tamanho);
	End;
End.