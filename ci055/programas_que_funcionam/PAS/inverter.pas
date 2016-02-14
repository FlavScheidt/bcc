
program inverter;
var
numero, unidade, inverso, resto, i: integer;

begin
read (numero);

i:= 1;

while (i<=3) do

begin

unidade:= numero mod 10;
resto:= numero div 10;
inverso:= inverso*10+unidade;
numero:= resto;

i:= i+1;
end;

writeln (inverso);
end.
