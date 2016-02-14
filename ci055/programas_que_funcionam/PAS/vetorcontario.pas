program vetorcontrario;
type vetor= array [0..5] of integer;

var v: vetor;

procedure ler (var v: vetor);
var	i: integer;
Begin
	for i:=0 to 5 do
		read(v[i]);
end;

procedure imprime (var v: vetor);
var	i:integer;
Begin
	for i:=5 downto 0 do
		writeln(v[i]);
End;

Begin
writeln('Digite cinco numeros');
ler (v);

imprime (v);
End.
