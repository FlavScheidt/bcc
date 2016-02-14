program formigas;
uses crt;
const 	max=50;
	tempo=100;
type vetor= array [0..100] of integer;
var	n, interacoes: integer;
	formiga: vetor;

(* Randomizar *)
procedure randomizar (var formiga: vetor; var n: integer);
var	i: integer;
Begin
	for i:=1 to max do
	Begin
		formiga[i]:= random(3);
		case formiga[i] of
			1: n:=n+1;
			2: Begin
				n:= (n+1);
				formiga[i]:= -1;
			   End;
		End;
	End;
End;

(* Imprime *)
procedure imprime (var formiga: vetor; var interacoes: integer);
var	i:integer;

	(* Troca *)
	function troca (i:integer): char;
		Begin
			case i of
				1: troca:= '>';
				0: troca:= '_';
				-1: troca:= '<';
			end;
		End;
Begin
	for i:=1 to max do	
		write(troca(formiga[i]));
	write(':', interacoes);
	writeln;
End;


(* Movimento *)
procedure movimento (var formiga: vetor; var interacoes: integer; n: integer);
var	i, j, k, d: integer;
Begin
	interacoes:= 1;
	i:= 1;
	while (n>0) and (i<=max)  do
	Begin
		for i:=1 to max do
		Begin
			case formiga [i] of
				1: j:=1;
				-1: j:=-1;
			End;
			k:= i+j;
			d:= k;
			(* Movimento *)
			if formiga[k]=0 then
			Begin
				 while (formiga[d]=0) and (d<=max) and (d>=1) do
					Begin
						d:= d+j;
						formiga[k]:= formiga[i];
						formiga[i]:= 0;
					End;
			
			End;
			if (formiga[k]=formiga[i]*-1) then
				formiga[i]:= formiga[k];
			(* Deleção *)
			if formiga[1]=-1 then
			Begin
				formiga[1]:=0;
				n:=n-1;
			End;
			if formiga[12]= 1 then
			Begin
				formiga[12]:=0;
				n:=n-1;
			End;
			interacoes:= interacoes+1;
			delay(tempo);
			clrscr;
			imprime(formiga, interacoes);
		End;
	End;
End;

(* Programa Principal *)
Begin
	randomize;
	randomizar(formiga, n);
	clrscr;
	imprime(formiga, interacoes);
	movimento(formiga, interacoes, n);

End.
