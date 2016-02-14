program concatena;
type vetor= array [0..100] of integer;
var 	v1, v2, vf: vetor;
	t1, t2, tf: integer;


(* Procedimento ler vetores *)
procedure levetor (var v: vetor);
var	i: integer;
Begin
	for i:= 1 to 6 do
	Begin
		read(v[i]);
	end;
t1:= 6;
t2:= 6;
End;

(* Procedimento concatena *)
procedure concatenar (var v1, v2, vf: vetor; var t1, t2, tf: integer);
var j ,i:integer;
Begin
j:=1;
tf:= t1+t2;
	for i:=1 to t1 do
		v1[i]:= vf[i];
	while (i<=t1+1) and (j<=t2)  do
	Begin
		v2[j]:= vf[i];
		i:= i+1;
		j:= j+1;
	End;
End;

(*Procedimento Imprime Vetor *)
procedure imprime (var vf:vetor);
var i:integer;
Begin
	for i:=0 to tf do
		write (vf[i]);
End;

(* Programa Principal *)
Begin
	(* Vetor 1 *)
	writeln ('Insira o vetor. Seis números');
	levetor (v1);


	(* Vetor 2 *)
	writeln('Insira o vetor. Dois números');
	levetor(v2);

	concatenar(v1, v2, vf, t1, t2, tf);
	imprime(vf);	
End.
