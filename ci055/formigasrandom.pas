program formigas;
type vetor= array [1..12] of integer;
var	formiga: vetor;
	n, i: integer;

(* Randomiza, número de formigas, posição e direao *)
procedure randomiza(var formiga: vetor; var n: integer);
var	i: integer;
Begin
	for i:=1 to 12 do
	Begin
		formiga[i]:= random (3);
		if (formiga[i]=0) then
			n:=n+1;
		if (formiga[i]=2) then
			formiga[i]:=-1;

	End;
	n:=n-12;
End;

(* Virar Formigas *)
procedure virar (var formigas: vetor;);
var 	i:integer;
Begin
	



End;

(*Programa Principal *)
Begin
	randomize;
	randomiza(formiga, n);



End.
