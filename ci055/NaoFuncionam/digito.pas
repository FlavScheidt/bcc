program digito;
var
     n, controle, c,d,u: integer;

begin
read (n); 
c:= n div 10;
 d:= (n mod 100) div 10;
 u:= n mod 10;
 controle:= (c+d*3+u*5) mod 7;
 n:= n*10+controle;

writeln(n);

end.
