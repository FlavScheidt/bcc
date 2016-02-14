program permutacao;
type vetor= array [0..100] of integer;
const max=5;
var	v1, v2: vetor;

(* Prodecimento para ler *)
procedure ler (var v: vetor);
var 	i: integer;
Begin
	for i:=0 to max do
		read(v[i]);
End;

(* Função Busca *)
function busca (var v1, v2: vetor): boolean;
var 	encontrou: boolean;
	i, j: integer;
Begin
encontrou:= false;
i:= 0;
j:=0;
		while not encontrou and (j<=max) and (i<=max) do
		Begin
			if v1[i]=v2[j] then
				encontrou:= true
			else
				j:=j+1;
		i:=i+1;		
		End;
	if encontrou then
		busca:= true
	else
		busca:= false;

End;

(* Programa Principal *)
Begin
	writeln('Entre com o primeiro vetor. Seis digitos');
        ler (v1);
	writeln('Entre com o segundo vetor. Seis digitos');
	ler (v2);

	if busca (v1, v2)  then
		writeln('O vetor dois é permutação do vetor um')
	else	
		writeln('O vetor dois não é permutação do vetor um');
End.
