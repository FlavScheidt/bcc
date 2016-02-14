program resolvedor;
uses crt;
const 	tempo=200;
type 	m1 = array [0..41, 0..41] of char;
	m2 = array [0..41, 0..41] of integer;
var	campo: m1;
	posicoes: m2;
	counter, i, j, tam, bombas: integer;

(* Inicializa Matrizez *)
procedure inicia (var campo:m1; posicoes:m2);
var i, j: integer;
Begin
	for i:=0 to tam+1 do
		for j:=0 to tam+1 do
		Begin
			posicoes[i,j]:= 0;
			campo[i,j]:='#';
		End;
End;


(* Lê matriz posicoes do arquivo gerado pelo gerador de campo *)
procedure learquivo(var posicoes:m2;var tam: integer);
var	F: text;
	i,j: integer;
Begin
	assign (F,ParamStr(1));
	reset(F);
	readln(F, tam);
	readln(F, bombas);
	for i:=1 to tam do
		for j:=1 to tam do
		Begin
			readln(F, posicoes[i,j]);
		End;
	close(F);
End;

(* Gera máscara que será impressa *)
procedure geramascara(var campo:m1; tam: integer);
var i, j:integer;
Begin
	for i:=1 to tam do
		for j:=1 to tam do
			campo[i,j]:='#';
End;

(* Imprimir *)
procedure imprime(var campo: m1);
var 	i,j,k: integer;
Begin

	delay(tempo);
	clrscr;
	write ('    ');
	for k:=1 to tam do
	Begin
		if k<=9 then
			write('0',k,' ')
		else
			write(k,' ');
	End;
	writeln;
	write('   ');
	write('+');
	for k:=1 to tam do
		write('---');
	write('+');
	writeln;
	for i:=1 to tam do
	Begin
		if i<=9 then
			write('0',i,' |')
		else
			write(i,' |');
		for j:=1 to tam do
			write(' ',campo[i,j],' ');
		write('|');
		writeln;
	End;
	write('   +');
	for i:=1 to tam do
		write('---');
	write('+');
	writeln;
End;

(* Marcar Bombas *)
procedure marcabomba(var campo:m1; i,j: integer; var counter: integer);
Begin
	campo[i,j]:= 'B';
	counter:= counter+1;
	imprime(campo);
End;

(* Verifica se há algum campo com bomba aberta *)
function perdeu(var campo:m1):boolean;
var 	i, j: integer;
Begin
		for i:=1 to tam do
			for j:=1 to tam do
			Begin
				if campo[i,j]='9' then
				Begin
					perdeu:= true;
				End
				else
					perdeu:= false;
			End;
End;

(* Abrir posições *)
procedure abreposicao (var campo: m1; var posicoes: m2; l, c: integer);
var x,y, i, j: integer;
	(* Verificar se ainda há zeros para abrir *)
	function verificaposicao (var campo: m1; var posicao:m2): boolean;
	var l, m: integer;
	Begin
		verificaposicao:= false;
		for l:=1 to tam do
			for m:=1 to tam do
				if (posicoes[l,m]=0) and (campo[l,m]='#') then
					verificaposicao:= true;
	End;
	(* Abrir campos *)
	procedure abre(var campo: m1; var posicao: m2; i, j: integer);
	Begin
		if campo[i,j]= '#' then
		case posicoes[i,j] of
			1: campo[i,j]:='1';
			2: campo[i,j]:='2';
			3: campo[i,j]:='3';
			4: campo[i,j]:='4';
			5: campo[i,j]:='5';
			6: campo[i,j]:='6';
			7: campo[i,j]:='7';
			8: campo[i,j]:='8';
			9: campo[i,j]:='9';
			0: campo[i,j]:='0';
		End;
	End;
Begin
	if campo [l,c]='#' then
		abre(campo, posicoes, l, c);
		while verificaposicao(campo, posicoes) do
		Begin
			for i:=1 to tam do
				for j:=1 to tam do
					if (campo[i,j]='0') then
					Begin
						for x:=(i-1) to (i+1) do
							for y:=(j-1) to (j+1) do
								abre(campo, posicoes, x, y);
					End;
		End;
		imprime(campo);
End;

(* Função para verificar se ainda há campos fechados e sem marcar *)
function tr00 (var campo: m1): boolean;
var	i, j: integer;
	confere: boolean;
	Begin
	confere:= true;

	while confere do
	Begin
		for i:=1 to tam do
			for j:=1 to tam do
				if (campo[i,j]='#') then
					confere:= false;
	End;

	if not confere then
		tr00:= false
	else
		tr00:= true;
End;

(* Marcar "Cantos" *)
procedure cantos (var campo:m1; var counter: integer);
var	x,y:integer;
Begin

	counter:= 0;
	for x:=1 to tam do
		for y:=1 to tam do
		Begin
			if campo[x,y]='#' then
			Begin
				if ((campo[x+1,y]<>'#') and (campo[x+1,y-1]<>'#') and (campo[x,y+1]<>'#')) or ((campo[x,y-1]<>'#') and (campo[x-1,y-1]<>'#') and (campo[x-1,y]<>'#')) or ((campo[x,y+1]<>'#') and (campo[x+1,y+1]<>'#') and (campo[x+1,y]<>'#')) or ((campo[x,y+1]<>'#') and (campo[x-1,y+1]<>'#') and (campo[x-1,y]<>'#')) then
				Begin
					marcabomba(campo, x, y, counter);
					imprime(campo);
				End;
			End;
		End;
End;

(* primeira jogada *)
procedure inicializa (var campo: m1; var counter: integer;var  i,j:integer);
Begin
	abreposicao(campo, posicoes, i, j);
	cantos(campo, counter);
	while counter=0 do
	Begin
		i:= random(tam-1);
		j:= random(tam-1);
		abreposicao (campo, posicoes, i, j);
		cantos(campo, counter);
	End;
End;


(* Bombas ao redor *)
procedure emvolta (var campo:m1; x,y: integer);
var marca, i, j: integer; marcac: char;
Begin
	marca:= 0;

	for i:=x-1 to x+1 do
		for j:=y-1 to y+1 do
		Begin
			if (campo[i,j]= 'B') then
				marca:= marca+1;
		End;
		case marca of
			1: marcac:='1';
			2: marcac:='2';
			3: marcac:='3';
			4: marcac:='4';
			5: marcac:='5';
			6: marcac:='6';
			7: marcac:='7';
			8: marcac:='8';
		End;
	if (marcac = campo[x,y]) then
	Begin
		for i:= x-1 to x+1 do
			for y:= y-1 to x+1 do
			Begin
				if (campo[i,j]='#') then
					abreposicao(campo, posicoes, i,j);
			End;
	End;
	imprime(campo);
End;

(* Confere se ainda há campos para abrir sem duvidas *)
function confereredor (var campo:m1): boolean;
var i, j, x, y,marca: integer; marcac: char;
Begin
	marca:= 0;
	confereredor:= false;
		for i:=1 to tam do
			for j:=1 to tam do
			Begin
				for x:= i-1 to i+1 do
					for y:=j-1 to j+1 do
						if campo[i,j]='B' then
							marca:= marca+1;
			case marca of
				1: marcac:= '1';
				2: marcac:= '2';
				3: marcac:= '3';
				4: marcac:= '4';
				5: marcac:= '5';
				6: marcac:= '6';
				7: marcac:= '7';
				8: marcac:= '8';
			End;
			if marcac= campo[i,j] then
				confereredor:= true;
			End;
End;

(* Fim de Jogo *)
procedure fimdejogo;
Begin
	imprime(campo);
	writeln('Perdeu');
End;

(* Verificar número de bombas *)
function nbombas (campo:m1): boolean;
var	i, j, nb:integer;
Begin
	nb:=0;
	for i:=1 to tam do
		for j:=1 to tam do
			if campo[i,j]='B' then
				nb:=nb+1;
	if nb<=bombas then
		nbombas:= true
	else
		nbombas:= false;
End;

(* Programa Principal *)
Begin
	randomize;
	inicia(campo, posicoes);
	learquivo(posicoes,tam);
	geramascara(campo, tam);
	imprime(campo);
	(* Inicaliza Variáveis *)
		counter:=0;
	(* Começa o jogo *)
	if ((tam mod 2)=0) then
	Begin
		i:= tam div 2;
		j:= tam div 2;
	End
	else
	Begin
		i:= (tam-1) div 2;
		j:= (tam-1) div 2;
	End;
	inicializa(campo, counter, i, j);
	while tr00(campo) and not perdeu(campo) and nbombas(campo) do
	Begin
			while confereredor(campo) do
				emvolta(campo, i, j);
			cantos(campo, counter);
	End;
	if perdeu(campo) then
		fimdejogo();

End.
