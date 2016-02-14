program inteirosemordem;
type vetor= array [1..5] of integer;
const max=5;
var i, j:integer;
    v, num: vetor;

(* Procedimentos *)
procedure ler (var num: vetor);
var i:integer;

begin
for i:= 1 to max do
read (num[i]);

end;

procedure compara (var v: vetor; var num:vetor);
	var maior, i, j: integer;	
	begin

	for j:= max downto 1 do

		begin
  			i:=1;
		while i<=5 do
		begin
			maior:= 0;
 			if num[i]>maior then
			begin  				
				maior:= num[i];
				num[i]:= 0;
			end;
				i:= i+1;
                     		

		end;
			v[j]:= maior;
		end;
	end;
     
procedure imprime (var v:vetor; var i:integer);
begin
	for i:=1 to max do
		writeln (v[i]);
end;


   
(* Programa principal *)
Begin
	ler (i, v);
	if v[i]>0 then
 	compara (i, num, v);
        imprime (v,i);
        else
	writeln ('Insira um valor positivo não nulo');
End.










