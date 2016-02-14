
program formigas;
uses crt;
const 	tampal=100;
	tempo=200;

type tpalito=array[1..tampal] of integer;

var palito:tpalito;

	procedure show(var palito:tpalito);
	var i:integer;
		function substitui(i:integer):char;
		begin
			case i of
				1:substitui:='>';
				0:substitui:='_';
				-1:substitui:='<';
			end;
		end;
	begin
		write(substitui(palito[1]));
		for i:=2 to tampal do
			write(substitui(palito[i]));
		writeln;
	end;




	procedure roda(var palito:tpalito);
	var i,j,sent:integer;

		function temformiga:boolean;
		var i:integer;
		begin
			i:=1;
			while (i<=tampal)and(palito[i]=0) do
				i:=i+1;
			temformiga:=(i<=tampal);
		end;

		procedure inverte(i,j:integer);
		begin
			while i<=j do begin
				palito[i]:=palito[i]*-1;
				i:=i+1;
			end;
		end;

		procedure mv(i,j:integer);
		begin
			if sent=-1 then begin
				if i>1 then
					palito[i-1]:=-1;
				palito[j]:=0;
			end else begin
				if j<tampal then
					palito[j+1]:=1;
				palito[i]:=0;
			end;
		end;	

	begin
		while temformiga do begin
			i:=1;
			while i<=tampal do begin
				if palito[i]<>0 then begin
					sent:=palito[i];
					j:=i+1;
					while (j<=tampal)and(palito[j]=sent) do
						j:=j+1;
					if sent=1 then begin
						if j<=tampal then begin
							if palito[j]=sent*-1 then begin
								inverte(i,j);
								i:=j+1;
							end else if (j<tampal)and(palito[j]=0)and(palito[j+1]=-1) then begin
								inverte(i,j+1);
								i:=j+2;
							end else begin
								mv(i,j-1);
								i:=j+1;
							end;
						end else begin
							mv(i,j-1);
							i:=j+1;
						end;
					end else begin
						if (i>1)and(palito[i-1]=1) then
							inverte(i,j-1)
						else
							mv(i,j-1);
						i:=j;
					end;
				end else
					i:=i+1;
			end;
			delay(tempo);
			clrscr;
			show(palito);
		end;
	end;



	procedure criapalito(var palito:tpalito);
	var i:integer;
	begin
		for i:=1 to tampal do
			palito[i]:=(random(2000)mod 3)-1;
	end;


begin
	randomize;
	criapalito(palito);
	clrscr;
	show(palito);
	roda(palito);
end.

