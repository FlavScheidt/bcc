program vetoresidenticos;
type vetor= array [1..5] of integer;
var v, w: vetor;
    igual: boolean;

(* Procedimento ler *)
procedure ler (var a:vetor);
var i: integer;
Begin
	for i:=1 to 5 do
		read (a[i]);
end;

(*Função Compara*)
function iguais (var v,w: vetor): boolean;
var i: integer;
    compara: boolean;

Begin
i:= 1;
compara:= false;

	while v[i]=w[i] do
	Begin
		compara:= true;
		i:= i+1;
	End;
iguais:= compara;
End;

(* Programa Principal*)
Begin
	writeln ('Insira o primeiro vetor - cinco elementos');
        ler (v);
	writeln ('Insira o segundo vetor - cinco elementos');
	ler (w);

	igual:= iguais(v,w);
	if igual then
		writeln('Os vetores são iguais')
	else
		writeln('Os vetores não são iguais');
End.
