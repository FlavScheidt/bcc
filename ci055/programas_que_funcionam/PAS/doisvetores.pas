program doivestores;
type vetor= array [1..5] of integer;

var 	v1, v2: vetor;

(* Ler *)
procedure ler (var v: vetor);
var	i: integer;
Begin
	for i:=1 to 5 do
	read (v[i]);
End;

(* Comparar *)
procedure  compara (var v1, v2: vetor);
var	i, j, aux: integer;

Begin
aux:= 0;
		for i:=1 to 5 do
		Begin
			aux:= v1[i];
			for j:=1 to 5 do
			Begin
				if aux=v2[j] then
				begin
					writeln (v1[i]);
					writeln ('Elemento encontrado');
				end;
			end;
		end;
end;


(*Programa Principal *)
Begin
	writeln ('Insira cinco inteiros - primeiro vetor');
	ler (v1);
	writeln ('Insira mais cinco inteiros - segundo vetor');
	ler (v2);
	compara (v1, v2);
End.
	
