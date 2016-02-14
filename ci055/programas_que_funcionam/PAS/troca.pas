program troca;
var 	x, y: integer;

procedure troca (var x, y: integer);
var 	aux: integer;
Begin
	aux:= x;
	x:= y;
	y:= aux;
End;

Begin

	writeln('Entre com o primeiro numero');
	read (x);
	writeln('Entre com o segundo numero');
	read (y);

	troca (x,y);
	
	writeln (x);
	writeln (y);
End.
